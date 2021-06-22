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
				display("DD");
				return T_DD;
			}
			
			if(depth == top())
			{
				display("ND");
				yylval.depth = depth;
				return T_ND;				
			}
			if(depth > top())
			{
				push(depth);
				display("id");
				yylval.depth = depth;
				return T_id;
			}	
		}
#.*\n {}
{Multiline_comment}\n {}
import {display("import");return T_Import;}
print  {display("print");return T_Print;}
if {display("If"); return T_If;}
while {display("While"); return T_While;}
break {display("Break"); return T_Break;}
else {display("Else"); return T_Else;}
elif {display("Elif"); return T_Elif;}
and {display("And"); return T_andor;}
def {display("Def"); return T_Def;}
or {display("Or"); return T_andor;}
not {display("Not"); return T_Not;}
: {display("Cln"); return T_Cln;}
">" {display("GT"); return T_Relop;}
"<" {display("LT"); return T_Relop;}
">=" {display("EGT"); return T_Relop;}
"<=" {display("ELT"); return T_Relop;}
"==" {display("EQ"); return T_eq;}
"!=" {display("NEQ"); return T_eq;}
True {display("True"); return T_Binary;}
False {display("False"); return T_Binary;}
"+" {display("PL"); return T_Arop;}
"-" {display("MN"); return T_Arop;}
"*" {display("ML"); return T_Arop;}
"/" {display("DV"); return T_Arop;}
"(" { display("OP"); return T_OP;}
")" {display("CP"); return T_CP;}
, {display("Comma"); return T_Comma;}
= {display("EQL"); return T_EQL;}
[0-9]+ {yylval.value.text = strdup(yytext);
	yylval.value.type="Integer";
	display("Int"); 
	return T_Number;
	}
[0-9]+\.[0-9]+ {yylval.value.text = strdup(yytext);
		yylval.value.type="Float";
		display("Float"); 
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
				display(yylval.value.text); 
				return T_ID;
				}
\"([^\"\n])*\"|\'([^\'\n])*\' {yylval.value.text = strdup(yytext);yylval.value.type="String"; display(yylval.value.text); return T_String;}
{whitespace} {} 
\n {  display("NL");printf("\n");
      return T_NL;}
<<EOF>> {display("EOF"); return T_EndOfFile;}
. {printf("Unknown Symbol %s at line no %d",yytext,yylineno); }
%%
