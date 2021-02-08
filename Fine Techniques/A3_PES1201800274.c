#include <stdio.h>
#include <string.h>
#define MAX 4100
#define PMAX 1100
int initial=0;
int final=0;
int t_count=0;
int len;
int match_here(char *pat, char *text);
int match_non_greedy(char ch, char* pat, char* text);
int match_plus(char ch, char s, char* pat, char* text);
int match_brack(int hash[256], char s, char* pat, char* text);
int ngbrackets(int hash[256],char* pat,char* text);
int match(char *pat, char *text){ 
	initial=0;
	if(*pat == '^'){
		return match_here(pat + 1, text);
	}
	do
	{	
		if(match_here(pat, text)){
			return 1;
		}
		else{
			initial=len-strlen(text)+1;
		}

	} while(*text++ != '\0');
	return 0;
}
int match_here(char *pat, char *text){
	if(*pat == '\0'){ 
		t_count=strlen(text);
		return 1;
	}
	if(pat[1] == '*'){ // Checks for non greedy and greedy pattern matching with *
		if(pat[2]!='?'){	
			return match_plus(pat[0],pat[1], pat+2, text);
		}
		else{
			return match_non_greedy(pat[0],pat+3, text);
		}
	}
	if(pat[1]=='?'){ 
		if((text[0]==pat[0] || pat[0]=='.')&&match_here(pat+2,text+1)){
			return match_here(pat+2,text+1);
		}
		else
			return match_here(pat+2,text);
	}
	if(pat[1] == '+'){
		return match_plus(pat[0],pat[1],pat+2, text);
	}
	if(pat[0] == '$' && pat[1] == '\0'){
		t_count=strlen(text);
		return *text == '\0';	
	}
	if(*text != '\0' && (*pat == '.' || *pat == *text)){
		return match_here(pat + 1, text + 1);
	}
	if(pat[0]=='[' || pat[0]=='\\'){ // Hash Table with the help of ASCII values of character is made in order to keep track of characters inside the class.
		int hash[256]={0};
		if(pat[0]=='['){ // Character classes are handled in this segment
			while(*(++pat)!=']'){
				if(pat[1]=='-'){
					int start=pat[0];
					int end = pat[2];
					for(int i=start;i<=end;i++){
						hash[i]=1;
					}
					pat+=2;
				}
				else{
					hash[pat[0]]=1;
				}
			}
		}
		else{
			if(pat[1]=='w' || pat[1]=='d'){ // Macros and Escape sequences are handled here. Escape sequences are trated like single character class.
				pat++;
				char* temp;
				if(pat[0]=='w'){
					temp="A-Za-z0-9_]";
				}
				else if(pat[0]=='d'){
					temp="0-9]";
				}
				while(*(temp)!=']'){
					if(temp[1]=='-'){
						int start=temp[0];
						int end = temp[2];
						for(int i=start;i<=end;i++){
							hash[i]=1;
						}
						temp+=2;
					}
					else{
						hash[pat[0]]=1;
					}
					temp++;
				}
			}
			else{
				pat++;
				hash[pat[0]]=1;
			}
		}
		pat++; 
		if(pat[0]!='*' && pat[0]!='?' && pat[0]!='+'){ //Once the hash table is computed, greedy and non greedy functions are called based on the appropriate combiations.
			if(hash[text[0]]==1){
				return match_here(pat, text + 1);
			}
		}
		else if(pat[0]=='?'){
			if(hash[text[0]]==1 && match_here(pat+1,text+1)){
				return match_here(pat+1,text+1);	
			}
			else{
				return match_here(pat+1,text);	
			}	
		}
		else if(pat[0]=='+' || pat[0]=='*'){
			if(pat[1]!='?'){
				return match_brack(hash,pat[0],pat+1,text);
			}
			else{
				return ngbrackets(hash,pat+2,text);
			}
		} 
	}
	return 0;	
}
int match_plus(char ch, char s, char* pat, char* text){ //Matches when it comes across * and + 
	int count=0;
	char* last=NULL;
	do{
		if(text[0]==ch && s=='+'){ // count is kept in order to ensure constraints are met for +/
			text++;
			count++;
		}
		if(ch=='.'){    // Due to properties of ., the entire string has to traversed till no match is found. Hence last match is to be kept.
			char* new=text;
			if(s=='+'){
				new=text+1;
			}
			if(match_here(pat,new)){
				last=new;
				count++;
			}
		}
		else if(match_here(pat, text)){
			if(s=='+'){
				if(count>0){
					return 1;
				}
			}
			else{
				return 1;
			}
		}
		} while(*text != '\0' && (*text++ == ch || ch == '.'));
	if(ch=='.'){
		if(last!=NULL && match_here(pat,last)){ //The last match is always kept track of in order to ensure greedy ie longest pattern match,
			if(s=='+'){
				if(count>0){
					return 1;
				}
			}
			else{
				return 1;
			}
		}
	}
	return 0; 
}
int match_brack(int hash[256], char s, char* pat, char* text){ //greedy pattern matching
	int count=0;
	char* last=NULL;
	do{
		if(hash[text[0]]==1 && s=='+'){
			count++;
			text=text+1;
		}
		if(match_here(pat, text)){
			last=text;
		}
	} while(*text != '\0' && hash[*text++]==1);
	if(last!=NULL && match_here(pat,last)){ // The last match is always kept track of in order to ensure greedy ie longet pattern match,
		if(s=='+'){
			if(count>0){
				return 1;
			}
		}
		else{
			return 1;
		}
	}	
	return 0;
}
int ngbrackets(int hash[256], char* pat, char* text){ //non greedy pattern matching for character classes. Same logic as the other non greedy function. This however uses the hash table. 
	do
	{
		if(match_here(pat, text)){
			return 1;
		}
	} while(*text != '\0' && hash[*text++] == 1);
	return 0;
}
int match_non_greedy(char ch, char* pat, char* text){// non greedy pattern matching for *.
	do
	{
		if(match_here(pat, text)){
			return 1;
		}
	} while(*text != '\0' && (*text++ == ch || ch == '.'));
	return 0;
}
int main(){	
	int m;
	char str[MAX];
	char pattern[PMAX];
	char text[MAX];
	fgets(str,MAX,stdin);
	memset(text,'\0',sizeof text);
   	strncpy(text,str,strlen(str)-1);
	scanf("%d\n",&m);
	for (int i=0;i<m;i++){
		fgets(str,PMAX,stdin);
		memset(pattern,'\0',sizeof pattern);
   		strncpy(pattern,str,strlen(str)-1);
		len=strlen(text);
		int val=match(pattern,text);
		final=len-t_count-1;
		if(val==1 && final==-1){
			final=0;
		}
		if(val==1){
			printf("%d %d %d\n",val,initial,final);
		}
		else{
			printf("%d\n",val);
		}
	}
	return 0;
}
