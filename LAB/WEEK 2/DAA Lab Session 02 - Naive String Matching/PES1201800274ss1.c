
#include<string.h>
int searchFirstOccurrence(char *pattern, char *text){
    int i=0;
    int j=1;
    int flag=0;
    while(text[i]!='\0'){
        flag=0;
        j=1;
        if(text[i]==pattern[0]){ 
            int k=i;
            while(pattern[j]!='\0'){
                if(pattern[j++]!=text[++k] || text[k]=='\0'){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return i;
            }
        }
        i++;
   }
   return -1;
}
int searchLastOccurrence(char *pattern, char *text){
    int p=strlen(pattern)-1;
    int t=strlen(text)-1;
    int flag=0;
    while(t>=p){
        flag=0;
        if(text[t]==pattern[p]){
            int pt=p-1;
            int tt=t-1;
            while(pt>=0){
                if(pattern[pt--]!=text[tt--]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return tt+1;
            }
        }
        t--;
    }
    return -1;
}   
     
int numOccurrences(char *pattern, char *text){
    int count=0;
    int l1=strlen(pattern);
    int l2=strlen(text);
    int j=0;
    for(int i=0;i<l2;i++){
        if(pattern[j]==text[i]){
            j++;
        }
        else{
            j=0;
        }
        if(j==l1){
            count++;
            j=0;
        }
    }
    return count;
}

int longestPrefix(char *pattern, char *text){
    int max=0;
    int l1=strlen(pattern);
    int l2=strlen(text);
    int j=0;
    for(int i=0;i<l2;i++){
        if(pattern[j]==text[i]){
            j++;
            if(j>max){
                max=j;
            }
        }
        else{
            j=0;
        }
        if(j==l1){
            return j;
        }
    }
    return max;
}

// Count the number of characters compared while finding all occurences of the pattern in the given text
// Characters must be matched from left to right
int charactersCompared(char *pattern, char *text){
    int t = strlen(text);
	int p = strlen(pattern);
	int i,j;
	int count = 0;
	
	for(i = 0; i <= t-p; i++)
	{
		for(j = 0; j < p; j++, count++)
		{
			if(text[i+j] != pattern[j])
			{
				count++;
				break;
			}
		}
	}
	return count;
}

