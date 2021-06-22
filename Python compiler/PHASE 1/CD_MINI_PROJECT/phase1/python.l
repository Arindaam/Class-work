%{
#include <stdio.h> 
#include<stdlib.h>
#include<ctype.h>
#include "y.tab.h"
#include "SymbolTable.h" 

extern FILE *yyin;
extern FILE *yyout;
int lineno = 1; // initialize to 1
void ret_print(char* token_type);

%} 
%% 

\n\t { lineno+=1; return T_INDENT; }
\. { ret_print("T_DOT");  strcpy(yylval.val,yytext); return T_DOT; }
\n { lineno+=1; }
\n\t.\n { lineno+=1; return T_DEDENT;}
#.* {}
""".*"""
[ ] {}
\t {}
False { ret_print("T_FALSE"); strcpy(yylval.val,"T_FALSE");return T_FALSE; }
None { ret_print("T_NONE");  strcpy(yylval.val,"T_NONE");return T_NONE; }
True { ret_print("T_TRUE");  strcpy(yylval.val,"T_TRUE");return T_TRUE; }
and { ret_print("T_LAND");  strcpy(yylval.val,yytext);return T_LAND; }
break { ret_print("T_BREAK");  strcpy(yylval.val,yytext);return T_BREAK; }
continue { ret_print("T_CONTINUE");  strcpy(yylval.val,yytext);return T_CONTINUE; }
elif { ret_print("T_ELIF");  strcpy(yylval.val,yytext);return T_ELIF;}
del { ret_print("T_DEL");   strcpy(yylval.val,yytext);return T_DEL;}
else { ret_print("T_ELSE");   strcpy(yylval.val,yytext);return T_ELSE;}
for { ret_print("T_FOR");   strcpy(yylval.val,yytext);return T_FOR;}
if { ret_print("T_IF");   strcpy(yylval.val,yytext);return T_IF;}
in { ret_print("T_IN");  strcpy(yylval.val,yytext);return T_IN;}
not { ret_print("T_NOT");   strcpy(yylval.val,yytext);return T_NOT;}
or { ret_print("T_LOR");  strcpy(yylval.val,yytext);return T_LOR; }
while { ret_print("T_WHILE");  strcpy(yylval.val,yytext);return T_WHILE; }
input { ret_print("T_INPUT");  strcpy(yylval.val,yytext);return T_INPUT;}
print { ret_print("T_PRINT");  strcpy(yylval.val,yytext);return T_PRINT; }
int { ret_print("T_INT");   strcpy(yylval.val,yytext);return T_INT;}
float { ret_print("T_FLOAT");   strcpy(yylval.val,yytext);return T_FLOAT;}
str { ret_print("T_STR");  strcpy(yylval.val,yytext);return T_STR; }
list { ret_print("T_LIST");   strcpy(yylval.val,yytext);return T_LIST;}
split { ret_print("T_SPLIT");  strcpy(yylval.val,yytext);return T_SPLIT; }
map { ret_print("T_MAP");  strcpy(yylval.val,yytext);return T_MAP;}
append { ret_print("T_APPEND");   strcpy(yylval.val,yytext);return T_APPEND;}
pop { ret_print("T_POP");   strcpy(yylval.val,yytext);return T_POP;}
insert { ret_print("T_INSERT");   strcpy(yylval.val,yytext);return T_INSERT;}
len { ret_print("T_LEN");   strcpy(yylval.val,yytext);return T_LEN;}
range { ret_print("T_RANGE");  strcpy(yylval.val,yytext);return T_RANGE;}
>= { ret_print("T_GE");  strcpy(yylval.val,yytext);return T_GE;}
\<= { ret_print("T_LE");  strcpy(yylval.val,yytext);return T_LE;}
== { ret_print("T_EOP");  strcpy(yylval.val,yytext);return T_EOP;}
\!= { ret_print("T_NEOP");  strcpy(yylval.val,yytext);return T_NEOP;}
; { ret_print("T_SEMI");  strcpy(yylval.val,yytext);return T_SEMI; }
: { ret_print("T_COLON");  strcpy(yylval.val,yytext);return T_COLON; }
, { ret_print("T_COMMA");  strcpy(yylval.val,yytext);return T_COMMA; }
(\".*\")|(\'.*\') { ret_print("T_CSTR"); strcpy(yylval.val,yytext);return T_CSTR;}
\*\* { ret_print("T_EPOP");  strcpy(yylval.val,yytext);return T_EPOP; }
\* { ret_print("T_MUL");  strcpy(yylval.val,yytext);return T_MUL;}
\/ { ret_print("T_DIV");  strcpy(yylval.val,yytext);return T_DIV;}
\/\/ { ret_print("T_FDIV");  strcpy(yylval.val,yytext);return T_FDIV;}
\% { ret_print("T_MOD");  strcpy(yylval.val,yytext);return T_MOD;}
\+ { ret_print("T_ADD");  strcpy(yylval.val,yytext);return T_ADD;}
\- { ret_print("T_SUB");   strcpy(yylval.val,yytext);return T_SUB;}
= { ret_print("T_ASOP");   strcpy(yylval.val,yytext);return T_ASOP;}
\<  { ret_print("T_L");   strcpy(yylval.val,yytext);return T_L;}
> { ret_print("T_G");  strcpy(yylval.val,yytext);return T_G;}
\^ { ret_print("T_XOR");   strcpy(yylval.val,yytext);return T_XOR;}
\& { ret_print("T_BAND");   strcpy(yylval.val,yytext);return T_BAND;}
\| { ret_print("T_BOR");  strcpy(yylval.val,yytext);return T_BOR;}
\{ { ret_print("T_LBRACE");  strcpy(yylval.val,yytext);return T_LBRACE; }
\} { ret_print("T_RBRACE");  strcpy(yylval.val,yytext);return T_RBRACE; }
\( { ret_print("T_LPAREN");  strcpy(yylval.val,yytext);return T_LPAREN;}
\) { ret_print("T_RPAREN");  strcpy(yylval.val,yytext);return T_RPAREN;}
\[ { ret_print("T_LBRACKET");  strcpy(yylval.val,yytext);return T_LBRACKET;}
\] { ret_print("T_RBRACKET");  strcpy(yylval.val,yytext);return T_RBRACKET;}

[0-9]+[a-zA-z_]+ {printf("Unknown Symbol %s at line no %d",yytext,lineno); }

[a-zA-Z_][a-zA-Z0-9_]* { ret_print("T_ID"); yylval.ctype.type=-1;strcpy(yylval.ctype.value,yytext);return T_ID;}


[0-9]* { ret_print("T_CINT");strcpy(yylval.val,yytext); return T_CINT;}
[0-9]*\.[0-9]* { ret_print("T_CFLOAT");  strcpy(yylval.val,yytext);return T_CFLOAT; }
. {printf("Unknown Symbol %s at line no %d",yytext,lineno); }

%% 

int yywrap()  
{  
    strcpy(yylval.val,yytext);return 1;
} 

void ret_print(char *token_type)
{
	printf("\nyytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}

/*int main()
{
	yylex();
  printf("Symbol Table : \n");
  display();
}
*/
