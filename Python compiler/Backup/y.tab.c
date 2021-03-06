/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Parser.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define stack_size 100  
	
	extern char* yytext;
	extern int yylineno;
	int stack_t=-1;
	int scope=0;
	int count;
	int cnt;
	int id;
	int f_cnt;
	int check;
	int check_count=0;
	char* s;
	int search;
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
	
	 typedef struct quadruples{
    		char *op;
    		char *arg1;
   	 	char *arg2;
    		char *res;
  	}quad;
  	int quadlen = 0;
	
	char st[100][100];
	quad q[100];
	
	void init(){
		symbolTable = (record*)calloc(500, sizeof(record));
		printf("Symbol Table Initialized\n");
		printf("\n---------------------3 Address Code-------------------------\n");
	}
	
	int sIndex = -1;
	
	int searchs(const char* type, const char *name,char* scop)
	{
		int i = 0;
		for(i=0; i<=sIndex; i++)
		{
				if((strcmp(symbolTable[i].type, type)==0) && (strcmp(symbolTable[i].name, name)==0) && (strcmp(symbolTable[i].scope, scop)==0 ) || (strcmp(symbolTable[i].scope, "Global")==0 ) )
				{
					return i;
				}
			}
	
		return -1;
	}
	
	int searchRecord(const char* type, const char *name,char* scop)
	{
		int i = 0;
		for(i=0; i<=sIndex; i++)
		{
				if((strcmp(symbolTable[i].type, type)==0) && (strcmp(symbolTable[i].name, name)==0) && (strcmp(symbolTable[i].scope, scop)==0 ))
				{
					return i;
				}
			}
	
		return -1;
	}
	
	void class(int index, char* class){
		symbolTable[index].classtype=class;
	}	
	
	void insertRecord(const char* type, const char *name, int scope,char* class){ 
		char* scop;
		if (scope==0){
			scop="Global";
		}
		else if(scope==1){
			scop="Local";
		}
		else if(scope==2){
			scop="Func";
		}
		else{
			scop="Temporary";
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
		printf("\n---------------------Symbol Table-------------------------\n");
		printf("\n\nSl No.\t\t\tSymbol\t\t\tType\t\t\tDec_Line\t\t\tScope\t\t\t Fun_args\t\t\tClass\n\n");
		int i = 0;
		for(i=0; i<=sIndex; i++)
		{
			printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%s\t\t\t%d\t\t\t%s\n", i+1, symbolTable[i].name, symbolTable[i].type, symbolTable[i].decLineNo, symbolTable[i].scope,symbolTable[i].fun,symbolTable[i].classtype);
		}
	}
	
	void push(char* string){
		strcpy(st[++stack_t],string);
	}
	
	int temp_i=0;
	char tmp_i[3];
	char temp[2]="t";
	
	void codegen(){
		strcpy(temp,"T");
		sprintf(tmp_i,"%d", temp_i);
		strcat(temp,tmp_i);
		printf("%s = %s %s %s\n",temp,st[stack_t-2],st[stack_t-1],st[stack_t]);
		insertRecord("Temp_var", temp,3,"None");
		q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[stack_t-1]));
		q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[stack_t-2]));
		q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[stack_t]));
		q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
		strcpy(q[quadlen].op,st[stack_t-1]);
		strcpy(q[quadlen].arg1,st[stack_t-2]);
		strcpy(q[quadlen].arg2,st[stack_t]);
		strcpy(q[quadlen].res,temp);
		quadlen++;
		stack_t-=2;
		strcpy(st[stack_t],temp);
		temp_i++;
	}
	
	void codegen_assign(){

    		printf("%s = %s\n",st[stack_t-2],st[stack_t]);
    		q[quadlen].op = (char*)malloc(sizeof(char));
    		q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[stack_t]));
    		q[quadlen].arg2 = NULL;
    		q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[stack_t-2]));
    		strcpy(q[quadlen].op,"=");
    		strcpy(q[quadlen].arg1,st[stack_t]);
    		strcpy(q[quadlen].res,st[stack_t-2]);
    		quadlen++;
    		stack_t-=3;

  	}
  	int pops;
  	int label_n=0;
  	char* label;
  	int labels[20];
  	int ltop=-1;
  	void loop_init(){
  		printf("L%d: \n",pops);
  		q[quadlen].op = (char*)malloc(sizeof(char)*8);
    		q[quadlen].arg1 = NULL;
    		q[quadlen].arg2 = NULL;
    		q[quadlen].res = (char*)malloc(sizeof(char)*(label_n+2));
    		char l[]="L";
  		char x[10];
  		strcpy(q[quadlen].op,"Label");
  		sprintf(x,"%d",pops);
  		strcpy(q[quadlen].res,strcat(l,x));
  		quadlen++;
  	}
  	void loop_condition(){
  		strcpy(temp,"T");
		sprintf(tmp_i, "%d", temp_i);
		strcat(temp,tmp_i);
		insertRecord("Temp_var", temp,3,"None");
		printf("%s = not %s \n",temp,st[stack_t]);
		q[quadlen].op = (char*)malloc(sizeof(char)*4);
    		q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[stack_t]));
    		q[quadlen].arg2 = NULL;
    		q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
		strcpy(q[quadlen].op,"not");
    		strcpy(q[quadlen].arg1,st[stack_t]);
    		strcpy(q[quadlen].res,temp);
    		quadlen++;
    		printf("if %s goto L%d\n",temp,label_n);
    		q[quadlen].op = (char*)malloc(sizeof(char)*3);
    		q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    		q[quadlen].arg2 = NULL;
    		q[quadlen].res = (char*)malloc(sizeof(char)*(label_n+2));
    		strcpy(q[quadlen].op,"if");
    		strcpy(q[quadlen].arg1,temp);
		char x[10];
    		sprintf(x,"%d",label_n);
    		char l[]="L";
    		strcpy(q[quadlen].res,strcat(l,x));
    		quadlen++;
    		temp_i++;
    		labels[++ltop]=label_n++;
  	}
  	void endblock(){
  		pops=labels[ltop--];
  		q[quadlen].op = (char*)malloc(sizeof(char)*5);
    		q[quadlen].arg1 = NULL;
    		q[quadlen].arg2 = NULL;
    		q[quadlen].res = (char*)malloc(sizeof(char)*(label_n+2));
  		char l[]="L";
  		char x[10];
  		int gotos;
  		if(ltop==-1){
  			printf("goto L%d \n",label_n);
  			gotos=label_n++;
  		}
  		else{
  			gotos=labels[ltop--];
  			printf("goto L%d \n",gotos);
  		}
  		strcpy(q[quadlen].op,"goto");
  		sprintf(x,"%d",gotos);
  		strcpy(q[quadlen].res,strcat(l,x));
  		quadlen++;
  		labels[++ltop]=gotos;	
  	}
  	
  	void prinq()
  	{
  		printf("---------------------Quadruples-------------------------\n\n");
    		printf("Operator Arg1 Arg2 Result\n");
    		int i;
    		for(i=0;i<quadlen;i++)
    		{
        		printf("%s %s %s %s\n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    		}
    	}

#line 319 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_Import = 258,                /* T_Import  */
    T_Print = 259,                 /* T_Print  */
    T_If = 260,                    /* T_If  */
    T_While = 261,                 /* T_While  */
    T_Break = 262,                 /* T_Break  */
    T_Else = 263,                  /* T_Else  */
    T_Cln = 264,                   /* T_Cln  */
    T_Relop = 265,                 /* T_Relop  */
    T_Arop = 266,                  /* T_Arop  */
    T_OP = 267,                    /* T_OP  */
    T_CP = 268,                    /* T_CP  */
    T_Comma = 269,                 /* T_Comma  */
    T_EQL = 270,                   /* T_EQL  */
    T_Number = 271,                /* T_Number  */
    T_ID = 272,                    /* T_ID  */
    T_String = 273,                /* T_String  */
    T_andor = 274,                 /* T_andor  */
    T_Binary = 275,                /* T_Binary  */
    T_Def = 276,                   /* T_Def  */
    T_Elif = 277,                  /* T_Elif  */
    T_eq = 278,                    /* T_eq  */
    T_NL = 279,                    /* T_NL  */
    T_Not = 280,                   /* T_Not  */
    T_ND = 281,                    /* T_ND  */
    T_DD = 282,                    /* T_DD  */
    T_id = 283,                    /* T_id  */
    T_EndOfFile = 284              /* T_EndOfFile  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_Import 258
#define T_Print 259
#define T_If 260
#define T_While 261
#define T_Break 262
#define T_Else 263
#define T_Cln 264
#define T_Relop 265
#define T_Arop 266
#define T_OP 267
#define T_CP 268
#define T_Comma 269
#define T_EQL 270
#define T_Number 271
#define T_ID 272
#define T_String 273
#define T_andor 274
#define T_Binary 275
#define T_Def 276
#define T_Elif 277
#define T_eq 278
#define T_NL 279
#define T_Not 280
#define T_ND 281
#define T_DD 282
#define T_id 283
#define T_EndOfFile 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 249 "Parser.y"
  
	struct data
	{
		char *text;
		char* type;
	}value;  
	int depth;
 

#line 440 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_Import = 3,                   /* T_Import  */
  YYSYMBOL_T_Print = 4,                    /* T_Print  */
  YYSYMBOL_T_If = 5,                       /* T_If  */
  YYSYMBOL_T_While = 6,                    /* T_While  */
  YYSYMBOL_T_Break = 7,                    /* T_Break  */
  YYSYMBOL_T_Else = 8,                     /* T_Else  */
  YYSYMBOL_T_Cln = 9,                      /* T_Cln  */
  YYSYMBOL_T_Relop = 10,                   /* T_Relop  */
  YYSYMBOL_T_Arop = 11,                    /* T_Arop  */
  YYSYMBOL_T_OP = 12,                      /* T_OP  */
  YYSYMBOL_T_CP = 13,                      /* T_CP  */
  YYSYMBOL_T_Comma = 14,                   /* T_Comma  */
  YYSYMBOL_T_EQL = 15,                     /* T_EQL  */
  YYSYMBOL_T_Number = 16,                  /* T_Number  */
  YYSYMBOL_T_ID = 17,                      /* T_ID  */
  YYSYMBOL_T_String = 18,                  /* T_String  */
  YYSYMBOL_T_andor = 19,                   /* T_andor  */
  YYSYMBOL_T_Binary = 20,                  /* T_Binary  */
  YYSYMBOL_T_Def = 21,                     /* T_Def  */
  YYSYMBOL_T_Elif = 22,                    /* T_Elif  */
  YYSYMBOL_T_eq = 23,                      /* T_eq  */
  YYSYMBOL_T_NL = 24,                      /* T_NL  */
  YYSYMBOL_T_Not = 25,                     /* T_Not  */
  YYSYMBOL_T_ND = 26,                      /* T_ND  */
  YYSYMBOL_T_DD = 27,                      /* T_DD  */
  YYSYMBOL_T_id = 28,                      /* T_id  */
  YYSYMBOL_T_EndOfFile = 29,               /* T_EndOfFile  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_StartDebugger = 31,             /* StartDebugger  */
  YYSYMBOL_32_1 = 32,                      /* $@1  */
  YYSYMBOL_constant = 33,                  /* constant  */
  YYSYMBOL_term = 34,                      /* term  */
  YYSYMBOL_StartParse = 35,                /* StartParse  */
  YYSYMBOL_36_2 = 36,                      /* $@2  */
  YYSYMBOL_Expressions = 37,               /* Expressions  */
  YYSYMBOL_basic_stmt = 38,                /* basic_stmt  */
  YYSYMBOL_arith_exp = 39,                 /* arith_exp  */
  YYSYMBOL_40_3 = 40,                      /* $@3  */
  YYSYMBOL_arith_OP = 41,                  /* arith_OP  */
  YYSYMBOL_42_4 = 42,                      /* $@4  */
  YYSYMBOL_bool_exp = 43,                  /* bool_exp  */
  YYSYMBOL_44_5 = 44,                      /* $@5  */
  YYSYMBOL_45_6 = 45,                      /* $@6  */
  YYSYMBOL_bool_OP = 46,                   /* bool_OP  */
  YYSYMBOL_47_7 = 47,                      /* $@7  */
  YYSYMBOL_48_8 = 48,                      /* $@8  */
  YYSYMBOL_49_9 = 49,                      /* $@9  */
  YYSYMBOL_import_stmt = 50,               /* import_stmt  */
  YYSYMBOL_break_stmt = 51,                /* break_stmt  */
  YYSYMBOL_assign_stmt = 52,               /* assign_stmt  */
  YYSYMBOL_53_10 = 53,                     /* $@10  */
  YYSYMBOL_54_11 = 54,                     /* $@11  */
  YYSYMBOL_RHS = 55,                       /* RHS  */
  YYSYMBOL_print_stmt = 56,                /* print_stmt  */
  YYSYMBOL_finalStatements = 57,           /* finalStatements  */
  YYSYMBOL_58_12 = 58,                     /* $@12  */
  YYSYMBOL_Recur = 59,                     /* Recur  */
  YYSYMBOL_cmpd_stmt = 60,                 /* cmpd_stmt  */
  YYSYMBOL_if_stmt = 61,                   /* if_stmt  */
  YYSYMBOL_62_13 = 62,                     /* $@13  */
  YYSYMBOL_63_14 = 63,                     /* $@14  */
  YYSYMBOL_64_15 = 64,                     /* $@15  */
  YYSYMBOL_elif_stmts = 65,                /* elif_stmts  */
  YYSYMBOL_66_16 = 66,                     /* $@16  */
  YYSYMBOL_67_17 = 67,                     /* $@17  */
  YYSYMBOL_68_18 = 68,                     /* $@18  */
  YYSYMBOL_69_19 = 69,                     /* $@19  */
  YYSYMBOL_70_20 = 70,                     /* $@20  */
  YYSYMBOL_try = 71,                       /* try  */
  YYSYMBOL_final = 72,                     /* final  */
  YYSYMBOL_suite = 73,                     /* suite  */
  YYSYMBOL_while_stmt = 74,                /* while_stmt  */
  YYSYMBOL_75_21 = 75,                     /* $@21  */
  YYSYMBOL_76_22 = 76,                     /* $@22  */
  YYSYMBOL_new = 77,                       /* new  */
  YYSYMBOL_nsuite = 78,                    /* nsuite  */
  YYSYMBOL_args_list = 79,                 /* args_list  */
  YYSYMBOL_80_23 = 80,                     /* $@23  */
  YYSYMBOL_func_def = 81,                  /* func_def  */
  YYSYMBOL_82_24 = 82,                     /* $@24  */
  YYSYMBOL_83_25 = 83,                     /* $@25  */
  YYSYMBOL_84_26 = 84,                     /* $@26  */
  YYSYMBOL_func_call = 85,                 /* func_call  */
  YYSYMBOL_86_27 = 86,                     /* $@27  */
  YYSYMBOL_87_28 = 87                      /* $@28  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   262,   262,   262,   264,   274,   277,   310,   312,   312,
     312,   319,   319,   321,   321,   321,   321,   321,   323,   323,
     346,   348,   348,   348,   352,   352,   352,   352,   352,   352,
     354,   354,   354,   354,   354,   354,   354,   356,   358,   364,
     378,   364,   380,   380,   382,   384,   384,   384,   388,   388,
     390,   390,   390,   392,   392,   394,   394,   394,   394,   396,
     396,   396,   396,   396,   396,   396,   406,   408,   408,   410,
     410,   410,   412,   412,   412,   420,   420,   420,   442,   442,
     444,   444,   444,   452,   452,   452,   455,   457,   457,   461,
     457,   463,   472,   463
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_Import", "T_Print",
  "T_If", "T_While", "T_Break", "T_Else", "T_Cln", "T_Relop", "T_Arop",
  "T_OP", "T_CP", "T_Comma", "T_EQL", "T_Number", "T_ID", "T_String",
  "T_andor", "T_Binary", "T_Def", "T_Elif", "T_eq", "T_NL", "T_Not",
  "T_ND", "T_DD", "T_id", "T_EndOfFile", "$accept", "StartDebugger", "$@1",
  "constant", "term", "StartParse", "$@2", "Expressions", "basic_stmt",
  "arith_exp", "$@3", "arith_OP", "$@4", "bool_exp", "$@5", "$@6",
  "bool_OP", "$@7", "$@8", "$@9", "import_stmt", "break_stmt",
  "assign_stmt", "$@10", "$@11", "RHS", "print_stmt", "finalStatements",
  "$@12", "Recur", "cmpd_stmt", "if_stmt", "$@13", "$@14", "$@15",
  "elif_stmts", "$@16", "$@17", "$@18", "$@19", "$@20", "try", "final",
  "suite", "while_stmt", "$@21", "$@22", "new", "nsuite", "args_list",
  "$@23", "func_def", "$@24", "$@25", "$@26", "func_call", "$@27", "$@28", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
#endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -122,    10,   -12,  -122,  -122,  -122,    91,     2,    30,  -122,
     140,  -122,     0,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
      14,    26,  -122,  -122,  -122,  -122,  -122,   -12,    28,  -122,
    -122,  -122,     4,  -122,    18,    27,    33,    38,    26,    52,
     140,    63,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,   140,     4,    66,  -122,  -122,  -122,    64,
    -122,  -122,    26,  -122,  -122,  -122,   140,   140,   140,   140,
     140,     4,  -122,  -122,   150,    70,  -122,    75,    35,  -122,
    -122,  -122,  -122,  -122,  -122,    77,  -122,  -122,  -122,    78,
      83,    64,    35,  -122,    82,    88,    64,    76,  -122,    86,
      80,    94,  -122,  -122,    89,    73,    97,   101,   110,   130,
      95,   105,  -122,    40,  -122,   108,    51,  -122,   111,  -122,
     110,  -122,  -122,  -122,   130,  -122,  -122,   130,    40,    68,
      51,    51,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
     129,   140,   116,  -122,   113,   134,   110,   120,    40,   117,
    -122,   110,   110,    40,  -122,  -122,    68,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     8,     1,    10,     3,    46,     0,     0,    38,
       0,     4,     6,     5,    24,    87,    26,     7,    18,    16,
       0,    11,    12,    14,    13,    15,    17,     8,     0,    48,
      49,    37,    52,     6,     0,     0,     0,     0,    36,     0,
       0,    23,    45,    34,    30,    32,    29,     9,    55,    75,
      47,    53,    54,     0,    52,     0,    20,    28,    40,    86,
      25,    88,    36,    27,    21,    19,     0,     0,     0,     0,
       0,    52,    50,    44,     0,    83,    92,     0,     0,    35,
      31,    33,    56,    76,    51,     6,    42,    41,    43,     0,
       0,    86,     0,    22,     0,     0,    86,     0,    89,     0,
       0,     0,    84,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    74,    71,     0,    82,    79,     0,    69,
       0,    73,    57,    78,     0,    81,    77,     0,    74,    68,
      82,    82,    72,    63,    59,    58,    66,    67,    80,    90,
       0,     0,     0,    60,     0,     0,     0,     0,    74,     0,
      64,     0,    68,    74,    65,    61,    68,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -122,  -122,  -122,  -122,  -122,   122,  -122,   -28,    -3,   -10,
    -122,  -122,  -122,    -5,  -122,  -122,   115,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   -48,
    -122,   123,  -122,  -122,  -122,    -2,  -122,  -122,  -122,  -122,
    -122,     7,  -107,  -121,  -122,  -122,  -122,  -116,   -76,   -82,
    -122,  -122,  -122,  -122,  -122,    -4,  -122,  -122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    17,    18,     5,     6,    19,   111,    21,
      41,    65,    78,    22,    38,    40,    46,    67,    68,    66,
      23,    24,    25,    36,    74,    87,    26,    27,    28,    55,
      50,   112,    69,    94,   129,   135,   141,   145,   156,   140,
     152,   136,   137,   122,    52,    70,    95,   116,   126,    76,
      89,    29,    39,    77,   104,   114,    37,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   113,    30,    20,    54,    35,    72,   132,   130,    98,
       3,   131,   -91,   128,   102,   -39,    10,     4,    53,    31,
      11,    33,    13,    84,    14,    71,    54,   150,    43,    16,
      62,    56,   155,    48,    49,    63,    43,    44,    42,   148,
      57,    45,    32,    54,   153,    44,    86,    92,    58,    45,
      59,    11,    33,    13,   138,   139,    62,    62,    62,    62,
      62,    79,    80,    81,    82,    83,   120,   121,    93,    61,
      88,     7,     8,    48,    64,     9,   133,   124,   125,    73,
      10,    75,    99,   -85,    11,    12,    13,    91,    14,   -91,
     134,   100,    96,    16,     7,     8,    97,   101,     9,    56,
     103,   108,   107,    10,   105,   117,   115,    11,    12,    13,
     110,    14,    15,     7,     8,    48,    16,     9,   106,   118,
     117,   115,    10,   117,   115,   109,    11,    12,    13,   119,
      14,    62,   123,     7,     8,    16,   143,     9,   142,   127,
     144,   146,    10,   147,   149,   151,    11,    12,    13,    47,
      14,    51,    10,    60,   157,    16,    11,    33,    13,   154,
      14,     0,    10,     0,     0,    16,    11,    85,    13,     0,
      14,     0,     0,     0,     0,    16
};

static const yytype_int16 yycheck[] =
{
      10,   108,     6,     6,    32,    10,    54,   128,   124,    91,
       0,   127,    12,   120,    96,    15,    12,    29,    14,    17,
      16,    17,    18,    71,    20,    53,    54,   148,    10,    25,
      40,    13,   153,     5,     6,    40,    10,    19,    24,   146,
      13,    23,    12,    71,   151,    19,    74,    12,    15,    23,
      12,    16,    17,    18,   130,   131,    66,    67,    68,    69,
      70,    66,    67,    68,    69,    70,    26,    27,    78,    17,
      74,     3,     4,     5,    11,     7,     8,    26,    27,    13,
      12,    17,    92,    13,    16,    17,    18,    12,    20,    12,
      22,     9,    14,    25,     3,     4,    13,     9,     7,    13,
      24,    28,    13,    12,    24,   109,   109,    16,    17,    18,
       9,    20,    21,     3,     4,     5,    25,     7,    24,    24,
     124,   124,    12,   127,   127,    28,    16,    17,    18,    24,
      20,   141,    24,     3,     4,    25,   141,     7,     9,    28,
      24,    28,    12,     9,    24,    28,    16,    17,    18,    27,
      20,    28,    12,    38,   156,    25,    16,    17,    18,   152,
      20,    -1,    12,    -1,    -1,    25,    16,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    32,     0,    29,    35,    36,     3,     4,     7,
      12,    16,    17,    18,    20,    21,    25,    33,    34,    37,
      38,    39,    43,    50,    51,    52,    56,    57,    58,    81,
      85,    17,    12,    17,    39,    43,    53,    86,    44,    82,
      45,    40,    24,    10,    19,    23,    46,    35,     5,     6,
      60,    61,    74,    14,    37,    59,    13,    13,    15,    12,
      46,    17,    39,    43,    11,    41,    49,    47,    48,    62,
      75,    37,    59,    13,    54,    17,    79,    83,    42,    43,
      43,    43,    43,    43,    59,    17,    37,    55,    85,    80,
      87,    12,    12,    39,    63,    76,    14,    13,    79,    39,
       9,     9,    79,    24,    84,    24,    24,    13,    28,    28,
       9,    38,    61,    72,    85,    38,    77,    85,    24,    24,
      26,    27,    73,    24,    26,    27,    78,    28,    72,    64,
      77,    77,    73,     8,    22,    65,    71,    72,    78,    78,
      69,    66,     9,    43,    24,    67,    28,     9,    72,    24,
      73,    28,    70,    72,    71,    73,    68,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    32,    31,    33,    33,    34,    34,    36,    35,
      35,    37,    37,    38,    38,    38,    38,    38,    40,    39,
      39,    42,    41,    41,    44,    43,    45,    43,    43,    43,
      47,    46,    48,    46,    49,    46,    46,    50,    51,    53,
      54,    52,    55,    55,    56,    57,    58,    57,    57,    57,
      59,    59,    59,    60,    60,    62,    63,    64,    61,    66,
      67,    68,    65,    69,    70,    65,    65,    71,    71,    72,
      72,    72,    73,    73,    73,    75,    76,    74,    77,    77,
      78,    78,    78,    80,    79,    79,    79,    82,    83,    84,
      81,    86,    87,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       3,     0,     3,     0,     0,     3,     0,     3,     3,     2,
       0,     3,     0,     3,     0,     3,     0,     2,     1,     0,
       0,     5,     1,     1,     4,     2,     0,     2,     1,     1,
       2,     3,     0,     1,     1,     0,     0,     0,    11,     0,
       0,     0,    11,     0,     0,     9,     1,     1,     0,     2,
       1,     1,     3,     1,     0,     0,     0,     9,     2,     1,
       3,     1,     0,     0,     4,     1,     0,     0,     0,     0,
      13,     0,     0,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 262 "Parser.y"
                {init();}
#line 1741 "y.tab.c"
    break;

  case 4: /* constant: T_Number  */
#line 264 "Parser.y"
                    {
	insertRecord("Constant", yylval.value.text,0,yylval.value.type);
	push(yytext);
	if(strcmp(s,yylval.value.type)!=0){
		if(strcmp(yylval.value.type,"Float")==0){
			s="Float";
		}
		else if(strcmp(yylval.value.type,"Integer")==0 && (strcmp(s,"")==0||strcmp(s,"bool")==0)){
			s="Integer";	
		}
}}
#line 1757 "y.tab.c"
    break;

  case 5: /* constant: T_String  */
#line 274 "Parser.y"
             {s=yylval.value.type;
		push(yytext);
}
#line 1765 "y.tab.c"
    break;

  case 6: /* term: T_ID  */
#line 277 "Parser.y"
            {
		char* scop;
		if (scope==0){
			scop="Global";
		}
		else if(scope==1){
			scop="Local";
		}
		else if(scope==2){
			scop="Func";
		}
		f_cnt=searchs("Identifier", yylval.value.text,scop);
		if(f_cnt==-1){
			yyerror("Variable out of scope");
		}
		else{
			push(yylval.value.text);
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
		}
#line 1804 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 312 "Parser.y"
            {scope=0;}
#line 1810 "y.tab.c"
    break;

  case 10: /* StartParse: T_EndOfFile  */
#line 312 "Parser.y"
                                                               {	
									printf("\n Valid Python Syntax\n"); 
									prinq();
									printSTable(); 
									exit(0);
								}
#line 1821 "y.tab.c"
    break;

  case 12: /* Expressions: bool_exp  */
#line 319 "Parser.y"
                                    {s="bool";}
#line 1827 "y.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 323 "Parser.y"
                 {
	char* scop;
	if (scope==0){
		scop="Global";
	}
	else if(scope==1){
		scop="Local";
	}
	else if(scope==2){
		scop="Func";
	}
	int n_cnt=searchs("Identifier", yylval.value.text,scop);
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
	check_count++;	
}
#line 1856 "y.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 348 "Parser.y"
                  {push(yytext);}
#line 1862 "y.tab.c"
    break;

  case 22: /* arith_OP: T_Arop $@4 arith_exp  */
#line 348 "Parser.y"
                                          {codegen();}
#line 1868 "y.tab.c"
    break;

  case 23: /* arith_OP: %empty  */
#line 348 "Parser.y"
                                                        {
				check_count=0;
				check=0;
				}
#line 1877 "y.tab.c"
    break;

  case 24: /* $@5: %empty  */
#line 352 "Parser.y"
                   {push(yytext);}
#line 1883 "y.tab.c"
    break;

  case 26: /* $@6: %empty  */
#line 352 "Parser.y"
                                                 {push(yytext);}
#line 1889 "y.tab.c"
    break;

  case 30: /* $@7: %empty  */
#line 354 "Parser.y"
                {push(yytext);}
#line 1895 "y.tab.c"
    break;

  case 31: /* bool_OP: T_andor $@7 bool_exp  */
#line 354 "Parser.y"
                                         {codegen();}
#line 1901 "y.tab.c"
    break;

  case 32: /* $@8: %empty  */
#line 354 "Parser.y"
                                                          {push(yytext);}
#line 1907 "y.tab.c"
    break;

  case 33: /* bool_OP: T_eq $@8 bool_exp  */
#line 354 "Parser.y"
                                                                                  {codegen();}
#line 1913 "y.tab.c"
    break;

  case 34: /* $@9: %empty  */
#line 354 "Parser.y"
                                                                                                      {push(yytext);}
#line 1919 "y.tab.c"
    break;

  case 35: /* bool_OP: T_Relop $@9 bool_exp  */
#line 354 "Parser.y"
                                                                                                                              {codegen();}
#line 1925 "y.tab.c"
    break;

  case 38: /* break_stmt: T_Break  */
#line 358 "Parser.y"
                     {
			if(scope==0){	
				yyerror("Break Invalid");
			}
		}
#line 1935 "y.tab.c"
    break;

  case 39: /* $@10: %empty  */
#line 364 "Parser.y"
                   {
		push(yylval.value.text);
		insertRecord("Identifier", yylval.value.text,scope,"None");
		s="";
		char* scop;
		if (scope==0){
			scop="Global";
		}
		else if(scope==1){
			scop="Local";
		}	
		else if(scope==2){
			scop="Func";
		}		
		search=searchRecord("Identifier",yylval.value.text,scop);}
#line 1955 "y.tab.c"
    break;

  case 40: /* $@11: %empty  */
#line 378 "Parser.y"
                                                                                {push(yytext);}
#line 1961 "y.tab.c"
    break;

  case 41: /* assign_stmt: T_ID $@10 T_EQL $@11 RHS  */
#line 378 "Parser.y"
                                                                                                    {class(search,s);codegen_assign();}
#line 1967 "y.tab.c"
    break;

  case 46: /* $@12: %empty  */
#line 384 "Parser.y"
                                    {
					if(scope==0){	
						scope=1;
					}
				}
#line 1977 "y.tab.c"
    break;

  case 47: /* finalStatements: $@12 cmpd_stmt  */
#line 388 "Parser.y"
                                          {scope=0;}
#line 1983 "y.tab.c"
    break;

  case 55: /* $@13: %empty  */
#line 394 "Parser.y"
               {pops=label_n++;loop_init();}
#line 1989 "y.tab.c"
    break;

  case 56: /* $@14: %empty  */
#line 394 "Parser.y"
                                                     {loop_condition();}
#line 1995 "y.tab.c"
    break;

  case 57: /* $@15: %empty  */
#line 394 "Parser.y"
                                                                                                    {endblock();}
#line 2001 "y.tab.c"
    break;

  case 59: /* $@16: %empty  */
#line 396 "Parser.y"
                  {scope=1;loop_init();}
#line 2007 "y.tab.c"
    break;

  case 60: /* $@17: %empty  */
#line 396 "Parser.y"
                                                 {loop_condition();}
#line 2013 "y.tab.c"
    break;

  case 61: /* $@18: %empty  */
#line 396 "Parser.y"
                                                                                                {endblock();}
#line 2019 "y.tab.c"
    break;

  case 63: /* $@19: %empty  */
#line 396 "Parser.y"
                                                                                                                                {scope=1;loop_init();}
#line 2025 "y.tab.c"
    break;

  case 64: /* $@20: %empty  */
#line 396 "Parser.y"
                                                                                                                                                                                  {printf("L%d: \n",labels[ltop]);
		q[quadlen].op = (char*)malloc(sizeof(char)*8);
    		q[quadlen].arg1 = NULL;
    		q[quadlen].arg2 = NULL;
    		q[quadlen].res = (char*)malloc(sizeof(char)*(label_n+2));
    		char l[]="L";
  		char x[10];
  		strcpy(q[quadlen].op,"Label");
  		sprintf(x,"%d",labels[ltop--]);
  		strcpy(q[quadlen].res,strcat(l,x));
  		quadlen++;}
#line 2041 "y.tab.c"
    break;

  case 74: /* suite: %empty  */
#line 412 "Parser.y"
                              { 	
					if(yylval.depth>1){ /*check*/
					}
					else{
						empty();
						scope=0;	
					}
					}
#line 2054 "y.tab.c"
    break;

  case 75: /* $@21: %empty  */
#line 420 "Parser.y"
                     {pops=label_n++;loop_init();}
#line 2060 "y.tab.c"
    break;

  case 76: /* $@22: %empty  */
#line 420 "Parser.y"
                                                          {loop_condition();}
#line 2066 "y.tab.c"
    break;

  case 77: /* while_stmt: T_While $@21 bool_exp $@22 T_Cln T_NL T_id new nsuite  */
#line 420 "Parser.y"
                                                                                                        {printf("Goto L%d \n",pops);q[quadlen].op = (char*)malloc(sizeof(char)*5);
    		q[quadlen].arg1 = NULL;
    		q[quadlen].arg2 = NULL;
    		q[quadlen].res = (char*)malloc(sizeof(char)*(label_n+2));
  		char l[]="L";
  		char x[10];
  		strcpy(q[quadlen].op,"goto");
  		sprintf(x,"%d",pops);
  		strcpy(q[quadlen].res,strcat(l,x));
  		quadlen++;
  		printf("L%d: \n",label_n-1);
  		q[quadlen].op = (char*)malloc(sizeof(char)*8);
    		q[quadlen].arg1 = NULL;
    		q[quadlen].arg2 = NULL;
    		q[quadlen].res = (char*)malloc(sizeof(char)*(label_n+2));
  		char g[]="L";
  		strcpy(q[quadlen].op,"Label");
  		sprintf(x,"%d",label_n-1);
  		strcpy(q[quadlen].res,strcat(g,x));
  		quadlen++;
  		}
#line 2092 "y.tab.c"
    break;

  case 82: /* nsuite: %empty  */
#line 444 "Parser.y"
                             { 	
					if(yylval.depth>1){ /*check*/
					}
					else{
						empty();
					}
					}
#line 2104 "y.tab.c"
    break;

  case 83: /* $@23: %empty  */
#line 452 "Parser.y"
                {count++;cnt++;}
#line 2110 "y.tab.c"
    break;

  case 85: /* args_list: T_ID  */
#line 452 "Parser.y"
                                                         {
								count++;
								cnt++;
							}
#line 2119 "y.tab.c"
    break;

  case 87: /* $@24: %empty  */
#line 457 "Parser.y"
                {scope=2;}
#line 2125 "y.tab.c"
    break;

  case 88: /* $@25: %empty  */
#line 457 "Parser.y"
                                {
					insertRecord("Func_Name", yylval.value.text,0,"None"); 
					count=0;
					id=sIndex;
				}
#line 2135 "y.tab.c"
    break;

  case 89: /* $@26: %empty  */
#line 461 "Parser.y"
                                                {modify(count,id);}
#line 2141 "y.tab.c"
    break;

  case 90: /* func_def: T_Def $@24 T_ID $@25 T_OP args_list $@26 T_CP T_Cln T_NL T_id new nsuite  */
#line 461 "Parser.y"
                                                                                                   {scope=0;}
#line 2147 "y.tab.c"
    break;

  case 91: /* $@27: %empty  */
#line 463 "Parser.y"
                {
		cnt=0;
		f_cnt=searchRecord("Func_Name",yylval.value.text,"Global");
		if (f_cnt==-1){	
			yyerror("Function not declared");
		}
		else{	
			f_cnt=symbolTable[f_cnt].fun;
		}
	}
#line 2162 "y.tab.c"
    break;

  case 92: /* $@28: %empty  */
#line 472 "Parser.y"
                        {
		if(f_cnt!=cnt){	
			yyerror("Mismatched arguements");
		}
	}
#line 2172 "y.tab.c"
    break;


#line 2176 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 477 "Parser.y"

void yyerror(const char *msg){
	printf("Syntax Error at Line %d Column %d  %s",  yylineno,yylloc.last_column,msg);
	exit(0);
}

int main(){
	printf("Enter the Expression\n");
	yyparse();
	return 0;
}
