%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define stack_size 100
	extern int yylineno;
	extern char* yytext;
	int scope=0;
	int count;
	int cnt;
	int id;
	int f_cnt;
	int check;
	int check_count=0;
	char* s;
	int search;
	int flag=0;
	typedef struct record
	{
		char *type;
		char *name;
		int decLineNo;
		char* scope;
		int fun;
		char* classtype;
	} record;
	
	record *symbolTable = NULL;
	
	void init(){
		symbolTable = (record*)calloc(500, sizeof(record));
		printf("Symbol Table Initialized\n");
	}
	
	int sIndex = -1;
	
	int searchRecord(const char* type, const char *name,char* scop)
	{
		int i = 0;
		for(i=0; i<=sIndex; i++)
		{
			if((strcmp(symbolTable[i].type, type)==0) && (strcmp(symbolTable[i].name, name)==0) && (strcmp(symbolTable[i].scope, scop)==0))
			{
				return i;
			}
		}
		return -1;
	}
	
	int searchs( const char *name,char* scop)
	{
		int i = 0;
		for(i=0; i<=sIndex; i++)
		{
				if(strcmp(symbolTable[i].name, name)==0 )
				{
					if((strcmp(symbolTable[i].scope, scop)==0 ) || (strcmp(symbolTable[i].scope, "Global")==0 )){	
						return i;
					}	
				}
		}	
		return -1;
	}
	
	void class(int index, char* class){
		symbolTable[index].classtype=class;
	}	
	
	void insertRecord(const char* type, const char *name, int scope,char* class)
	{ 
		char* scop;
		if (scope==0){
			scop="Global";
		}
		else if(scope==1){
			scop="Loop";
		}
		else if(scope==2){
			scop="Function";
		}
		int recordIndex = searchRecord(type, name,scop);
		const int line=yylineno;
		if(recordIndex==-1)	
		{
			sIndex++;
			symbolTable[sIndex].type = (char*)calloc(30, sizeof(char));
			symbolTable[sIndex].name = (char*)calloc(20, sizeof(char));
			strcpy(symbolTable[sIndex].type, type);	
			strcpy(symbolTable[sIndex].name, name);
			symbolTable[sIndex].decLineNo = line;
			symbolTable[sIndex].scope=scop;
			symbolTable[sIndex].classtype=class;
		}
	}	
	void modify(int count,int id){
		symbolTable[id].fun=count;
	}	
	void printSTable()
	{
		printf("\n\nSl No.\t\t\tSymbol\t\t\tType\t\t\tDeclaration Line\t\t\tScope\t\t\t Fun_args\t\t\tClass\n\n");
		int i = 0;
		for(i=0; i<=sIndex; i++)
		{
			printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%s\t\t\t%d\t\t\t%s\n", i+1, symbolTable[i].name, symbolTable[i].type, symbolTable[i].decLineNo, symbolTable[i].scope,symbolTable[i].fun,symbolTable[i].classtype);
		}
	}
%}

%union {  
	struct data
	{
		char *text;
		char* type;
	}value;  
	int depth;
 };
   	  
%token T_Import T_Print T_If T_While T_Break T_Else T_Cln T_Relop T_Arop T_OP T_CP T_Comma T_EQL T_Number T_ID T_String T_andor T_Binary T_Def T_Elif T_eq T_NL T_Not T_ND T_DD T_id T_EndOfFile
%locations
%start StartDebugger
%%
StartDebugger : {init();} StartParse;

constant : T_Number {
	insertRecord("Const", yylval.value.text,0,yylval.value.type);
	if(strcmp(s,yylval.value.type)!=0){
		if(strcmp(yylval.value.type,"Float")==0){
			s="Float";
		}
		else if(strcmp(yylval.value.type,"Integer")==0 && (strcmp(s,"")==0||strcmp(s,"bool")==0)){
			s="Integer";	
		}
}}| T_String {s=yylval.value.type;};
term : T_ID {char* scop;
		if (scope==0){
			scop="Global";
		}
		else if(scope==1){
			scop="Loop";
		}
		else if(scope==2){
			scop="Function";
		}
		f_cnt=searchs(yylval.value.text,scop);
		if(f_cnt==-1){
			yyerror("Variable out of scope");
		}
		else{
			char* cm=symbolTable[f_cnt].classtype;
			if(strcmp(cm,s)!=0){
				if(strcmp(cm,"String")==0){
					s="String";
				}
				else if(strcmp(cm,"Float")==0){
					s="Float";
				}
				else if(strcmp(cm,"Integer")==0 && (strcmp(s,"")==0||strcmp(s,"bool")==0)){
					s="Integer";	
				}
				else if(strcmp(s,"") && strcmp(cm,"bool")==0){
					s="bool";	
				}
			}
		}
		}| constant {flag=1;};

StartParse :{scope=0;}finalStatements StartParse| T_EndOfFile {printf("\n Valid Python Syntax\n"); printSTable(); exit(0);};

Expressions :  arith_exp | bool_exp{s="bool";} ;
	
basic_stmt : break_stmt | import_stmt | assign_stmt | Expressions | print_stmt;

arith_exp :  term{
	int n_cnt;
	char* scop;
	if (scope==0){
		scop="Global";
	}
	else if(scope==1){
		scop="Loop";
	}
	else if(scope==2){
		scop="Function";
	}
	n_cnt=searchs(yylval.value.text,scop);
	if(flag==0){	
		if(check_count==0){
			if( strcmp(symbolTable[n_cnt].classtype,"String")==0){
				check=1;
			}
		}	
		else{
			if((check==1 && strcmp(symbolTable[n_cnt].classtype,"String")!=0) || (check==0 && strcmp(symbolTable[n_cnt].classtype,"String")==0)){
				yyerror("String Datatype Error");
			}
		}
	}
	else{
		if(check_count==0){
			if( strcmp(yylval.value.type,"String")==0){
				check=1;
			}
		}	
		else{
			if((check==1 && strcmp(yylval.value.type,"String")!=0) || (check==0 && strcmp(yylval.value.type,"String")==0)){
				yyerror("String Datatype Error");
			}
		}
	}

	check_count++;
	flag=0;
} arith_OP |T_OP arith_exp T_CP;
	
arith_OP : T_Arop arith_exp |{check_count=0;check=0;} ;

bool_exp : T_Binary bool_OP| T_Not bool_exp|T_OP bool_exp T_CP | arith_exp bool_OP;
			
bool_OP: T_andor bool_exp |T_eq bool_exp|T_Relop bool_exp|;			

import_stmt : T_Import T_ID;

break_stmt : T_Break {if(scope==0){	yyerror("Break Invalid");}};

assign_stmt : T_ID {insertRecord("Identifier", yylval.value.text,scope,"None");s="";char* scop;
		if (scope==0){
			scop="Global";
		}
		else if(scope==1){
			scop="Loop";
		}
		else if(scope==2){
			scop="Function";
		}		search=searchRecord("Identifier",yylval.value.text,scop);} T_EQL RHS{class(search,s);};

RHS: Expressions|func_call;

print_stmt : T_Print T_OP Recur T_CP;

finalStatements : basic_stmt T_NL | {if(scope==0){	scope=1;}}cmpd_stmt{scope=0;}| func_def| func_call;

Recur: Expressions Recur| T_Comma Expressions Recur|;

cmpd_stmt : if_stmt |while_stmt;

if_stmt : T_If bool_exp T_Cln T_NL T_id final suite elif_stmts;

elif_stmts :T_Elif{scope=1;} bool_exp T_Cln T_NL T_id final suite elif_stmts |T_Else{scope=1;} T_Cln T_NL T_id final suite try|final;

try: final |; /*check*/

final: basic_stmt T_NL | if_stmt|func_call;

suite : T_ND final suite|T_DD|{ 	
					if(yylval.depth>1){ /*check*/
					}
					else{
						empty();
						scope=0;	
					}
					};
while_stmt : T_While bool_exp T_Cln T_NL T_id new nsuite; 

new: basic_stmt T_NL| func_call;

nsuite: T_ND new nsuite|T_DD|{ 	
					if(yylval.depth>1){ /*check*/
					}
					else{
						empty();
					}
					};

args_list : T_ID{count++;cnt++;} T_Comma args_list | T_ID{count++;cnt++;} |;

func_def : T_Def{scope=2;} T_ID {insertRecord("Func_Name", yylval.value.text,0,"None"); count=0;id=sIndex;} T_OP args_list{modify(count,id);} T_CP T_Cln T_NL T_id new nsuite{scope=0;};

func_call : T_ID{cnt=0;f_cnt=searchRecord("Func_Name",yylval.value.text,"Global");if (f_cnt==-1){	yyerror("Function not declared");}else{	f_cnt=symbolTable[f_cnt].fun;}} T_OP args_list{if(f_cnt!=cnt){	yyerror("Mismatched arguements");}} T_CP T_NL;
%%
void yyerror(const char *msg){
	printf("Syntax Error at Line %d Column %d %s",  yylineno,yylloc.last_column,msg);
	exit(0);
}

int main(){
	printf("Enter the Expression\n");
	yyparse();
	return 0;
}
