%{
	#include <string.h>
	#include "y.tab.h"
	#define stack_size 100
	#define DEBUG 1
	int yycolumn = 1;
	int startFlag = 1;
	#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; 		\
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; 	\
    yycolumn += yyleng;			
	int start = 1;
	extern FILE *yyin;
	static int sp=0, stack [stack_size];
 	
 	static void display(const char *X)
 	{
 		#ifdef DEBUG
 		if(start)
 		{
 			printf("---------------------------------The Token Stream--------------------------\n1 ");
 			start=0;
 		}
 		
 		if(strcmp(X, "NL")==0)
 		{
 			printf("%s\n%d ", X, yylineno);
 		}
		else
		{
			printf("%s ", X);	
		}
 		#endif
 	}
 	static void push (int i) 
 	{
   		if (++sp<stack_size) stack[sp]= i;
   		else {printf ("error: stack overflow\n"); exit(1);}
 	}
 	
 	int pop () 
 	{
   		if (sp>-1) return stack[sp--];
   		else {printf ("error: stack underflow\n"); exit(1);}
 	}
 	
 	int top()
 	{
 		if(sp>-1) return stack[sp];
 		else return 0;
 	}
 	
 	void empty()
 	{
 		sp=-1;
 	}
 	
 	static int indentation(const char *K)
	{
		int len = strlen(K), i, tab_count=0;
		for(i=0; i< len ; i++)
		{
			if(K[i]=='\t')
			{
				tab_count++;
			}
			else
			{
				printf("Nope");
				break;
			}	
		}
		return tab_count;
	}	
 	
 	int depth = 0;
 		
%}
%option yylineno
whitespace [ ]
Multiline_comment \'\'\'([\n\t]|[A-Za-z0-9])*\'\'\'
%%
[\t]*		{
			depth = indentation(yytext);
			if(depth < top())
			{
				while (depth < top()) pop();
				yylval.depth = depth;
				return T_DD;
			}
			
			if(depth == top())
			{
				yylval.depth = depth;
				return T_ND;				
			}
			if(depth > top())
			{
				push(depth);
				yylval.depth = depth;
				return T_id;
			}	
		}
#.*\n {}
{Multiline_comment}\n {}
import {return T_Import;}
print  {return T_Print;}
if {return T_If;}
while { return T_While;}
break { return T_Break;}
else {return T_Else;}
elif { return T_Elif;}
and { return T_andor;}
def {return T_Def;}
or { return T_andor;}
not { return T_Not;}
: { return T_Cln;}
">" { return T_Relop;}
"<" {return T_Relop;}
">=" {return T_Relop;}
"<=" {return T_Relop;}
"==" {return T_eq;}
"!=" {return T_eq;}
True {return T_Binary;}
False { return T_Binary;}
"+" {return T_Arop;}
"-" { return T_Arop;}
"*" { return T_Arop;}
"/" {return T_Arop;}
"(" { return T_OP;}
")" {return T_CP;}
, {return T_Comma;}
= {return T_EQL;}
[0-9]+ {yylval.value.text = strdup(yytext);
	yylval.value.type="Integer";
	return T_Number;
	}
[0-9]+\.[0-9]+ {yylval.value.text = strdup(yytext);
		yylval.value.type="Float";
		return T_Number;
		}
[_a-zA-Z][_a-zA-Z0-9]* {  
				char str[35];
				memset(str,'\0',sizeof(char)*35);
				if(strlen(yytext)>=31){
					strncpy(str,yytext,31);
				}
				else{
					strcpy(str,yytext);
				}
				yylval.value.text = strdup(str); 
				return T_ID;
				}
\"([^\"\n])*\"|\'([^\'\n])*\' {yylval.value.text = strdup(yytext);yylval.value.type="String";  return T_String;}
{whitespace} {} 
\n { 
      return T_NL;}
<<EOF>> {return T_EndOfFile;}
. {printf("Unknown Symbol %s at line no %d",yytext,yylineno); }
%%
