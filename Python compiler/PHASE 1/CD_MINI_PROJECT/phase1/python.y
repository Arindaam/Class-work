%{ 
#include<stdio.h> 
#include<stdlib.h> 
#include "y.tab.h"
#include<string.h>

extern int lineno;



void first_val(char *first,char *temp)
{
    int i=0;int n=strlen(first);
    while(i<n && first[i]!=',')
    {
        temp[i]=first[i];i++;
    }
}

void expand(char *str,char *temp)
{
  char *pt;int a=0,b=0,c=0,i=0; char buffer[1024]="";
  pt = strtok(str,",");
  if(pt==NULL)
  {
    if(strlen(str)==0)
    {
    strcat(temp,"");
    return;
    }
  }
  a=atoi(pt);
  pt = strtok(NULL,",");
  if(pt==NULL)
  {
    i=0;
    while(i<a-1)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i++;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return;
  }
  b=atoi(pt);
  pt = strtok (NULL,",");
  if(pt==NULL)
  {
    i=a;
    while(i<b-1)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i++;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return;
  }  
  c=atoi(pt);
  i=a;
  if(c>0)
  {
  while(i<b-c)
  {
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);strcat(temp,",");
    i+=c;
  }
  sprintf(buffer,"%d",i);
  strcat(temp,buffer);
  return;
  }
  else 
  {

    while(i>b-c)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i+=c;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return; 
  }

}

void len(char *val,char *temp)
{
  int t=strlen(val);
  t=t-t/2;
  sprintf(temp,"%d",t);
}

%} 

%union{ struct{char value[1024]; int type;}ctype; char val[1024];};

%token T_DOT T_DEDENT T_LINE T_INDENT T_FALSE T_NONE T_TRUE T_LAND T_BREAK T_CONTINUE T_ELIF T_DEL T_ELSE T_FOR T_IF T_IN T_NOT T_LOR T_WHILE T_INPUT T_PRINT T_INT T_FLOAT T_STR T_LIST T_SPLIT T_MAP T_APPEND T_POP T_INSERT T_LEN T_ID T_CINT T_CFLOAT T_SEMI T_COMMA T_CSTR T_EPOP T_MUL T_DIV T_FDIV T_MOD T_ADD T_SUB T_ASOP T_G T_L T_GE T_LE T_EOP T_NEOP T_XOR T_BAND T_BOR T_LBRACE T_RBRACE T_LPAREN T_RPAREN T_LBRACKET T_RBRACKET T_RANGE T_COLON 

%type <ctype> For_body Exp Const Or_Exp And_Exp In_Exp Eq_Exp Rel_Exp Bit_Exp Add_Exp Mul_Exp Pow_Exp Unary_Exp Primary_Exp T_ID Iterable Param_list

%type<val> T_DOT T_DEDENT T_LINE T_INDENT T_FALSE T_NONE T_TRUE T_LAND T_BREAK T_CONTINUE T_ELIF T_DEL T_ELSE T_FOR T_IF T_IN T_NOT T_LOR T_WHILE T_INPUT T_PRINT T_INT T_FLOAT T_STR T_LIST T_SPLIT T_MAP T_APPEND T_POP T_INSERT T_LEN T_CINT T_CFLOAT T_SEMI T_COMMA T_CSTR T_EPOP T_MUL T_DIV T_FDIV T_MOD T_ADD T_SUB T_ASOP T_G T_L T_GE T_LE T_EOP T_NEOP T_XOR T_BAND T_BOR T_LBRACE T_RBRACE T_LPAREN T_RPAREN T_LBRACKET T_RBRACKET T_RANGE T_COLON T_DOUBLE

%% 
Translation_unit	: Stmt Translation_unit
					|  
					;


Stmt				: Simple_stmt 
					| Compound_stmt 
					| Assignment_stmt 
					;

Assignment_stmt     : T_ID T_ASOP Exp { char buff[3]="";  sprintf(buff,"%d",$3.type);  /*printf("%d %s %d\n",$3.type,buff,$3.value);*/  insert("T_ID",$1.value,buff,$3.value,lineno); }
                    | error { yyerrok; yyclearin; printf("Invalid literal"); }


Simple_stmt			: Exp
					| Print_stmt 
					| Jump_stmt 
					;


Compound_stmt		: If_stmt 
					| For_stmt 
					;

Jump_stmt			: T_BREAK 
					| T_CONTINUE 
					;

Print_stmt			: T_PRINT T_LPAREN Param_list T_RPAREN 
					;

Param_list			: Param_list T_COMMA Exp  { $$.type=50+$1.type; strcat($$.value,","); strcat($$.value,$3.value); }
					| Exp 					{}
					;

If_stmt				: T_IF Exp T_COLON T_INDENT Stmt Else_stmt 
					;

Else_stmt			: T_ELSE T_COLON T_INDENT Stmt
					| 
					;

For_stmt			: T_FOR T_ID T_IN Iterable T_COLON T_INDENT Translation_unit
{
  char temp[1024]="";first_val($4.value,temp);
  char buff[3]="";
  sprintf(buff,"%d",$4.type%10);
  insert("T_ID",$2.value,buff,temp, lineno);
}

Iterable			: T_LBRACKET Param_list T_RBRACKET  {$$=$2;}
					| T_RANGE T_LPAREN Param_list T_RPAREN {$$.type=51;char temp[1024]=""; expand($3.value,temp); strcpy($$.value,temp);} 


					;

Exp					: Or_Exp 
					| Primary_Exp
					| Pow_Exp
					| Mul_Exp
					| Add_Exp
					| Bit_Exp
					| Rel_Exp
					| Eq_Exp
					| In_Exp
					| And_Exp
					;

/* const types 1-int 2-float 3-str 4-bool 5-NONE 6-input */

Const: 				T_CINT {$$.type=1; strcpy($$.value,$1);}
					| T_CFLOAT {$$.type=2; strcpy($$.value,$1);}
					| T_CSTR {$$.type=3; strcpy($$.value,$1);}
					| T_TRUE {$$.type=4; strcpy($$.value,$1);}
					| T_FALSE {$$.type=4; strcpy($$.value,$1);}
					| T_NONE {$$.type=5; strcpy($$.value,$1);}
					| T_INPUT T_LPAREN T_RPAREN {$$.type=3; strcpy($$.value,"");}
					;

Primary_Exp			: T_ID {$$=$1;}
					| Const {$$=$1;}
					| T_RPAREN Exp T_LPAREN {$$=$2;}
					| Iterable {$$=$1;}
					| T_LEN T_LPAREN Iterable T_RPAREN {$$.type=1;char buffer[10]="";len($3.value,buffer) ;strcpy($$.value,buffer); }
					| T_INT T_LPAREN Exp T_RPAREN {$$.type=1; strcpy($$.value,$3.value); }
					| T_FLOAT T_LPAREN Exp T_RPAREN {$$.type=2; strcpy($$.value,$3.value); }
					| T_STR  T_LPAREN Exp T_RPAREN {$$.type=3; strcpy($$.value,$3.value); }
					;

Unary_Exp			: T_SUB Primary_Exp {$$.type=$2.type;char buffer[1024]="-";strcat(buffer,$2.value);strcpy($$.value,buffer);}
					| T_ADD Primary_Exp {$$=$2;}
					| T_NOT Primary_Exp {$$.type=$2.type;char buffer[1024]="-";strcat(buffer,$2.value);strcpy($$.value,buffer);}
					| Primary_Exp 
					;

Pow_Exp				: Unary_Exp 
					| Pow_Exp T_EPOP Unary_Exp 
					;

Mul_Exp				: Pow_Exp 
					| Mul_Exp T_MUL Pow_Exp 
					| Mul_Exp T_DIV Pow_Exp 
					| Mul_Exp T_FDIV Pow_Exp 
					| Mul_Exp T_MOD Pow_Exp
					;

Add_Exp				: Mul_Exp 
					| Add_Exp T_ADD Mul_Exp 
					| Add_Exp T_SUB Mul_Exp 
					;

Bit_Exp				: Add_Exp 
					| Bit_Exp T_XOR Add_Exp 
					| Bit_Exp T_BAND Add_Exp 
					| Bit_Exp T_BOR Add_Exp
					;

Rel_Exp				: Bit_Exp 
					| Rel_Exp T_G Bit_Exp 
					| Rel_Exp T_GE Bit_Exp 
					| Rel_Exp T_L Bit_Exp 
					| Rel_Exp T_LE Bit_Exp
					;

Eq_Exp				: Rel_Exp 
					| Eq_Exp T_EOP Rel_Exp 
					| Eq_Exp T_NEOP Rel_Exp 
					;

In_Exp				: Eq_Exp 
					| In_Exp T_IN Eq_Exp 
					;

And_Exp				: In_Exp 
					| And_Exp T_LAND In_Exp 
					;

Or_Exp				: And_Exp 
					| Or_Exp T_LOR And_Exp 
					;

%% 

// int yyerror(char *msg) 
// { 
//   printf("Syntax Error\n"); 
//   return 1;
// } 
void yyerror (char *s) 
{
  fprintf (stderr, "Error: %s\n", s);
} 

  
 
int main() 
{ 
  yyparse(); 
  display();
  return 1;
}

