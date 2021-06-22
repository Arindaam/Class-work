/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 254 "Parser.y"
  
	struct data
	{
		char *text;
		char* type;
	}value;  
	int depth;
 

#line 135 "y.tab.h"

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
