/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_DOT = 258,
    T_DEDENT = 259,
    T_LINE = 260,
    T_INDENT = 261,
    T_FALSE = 262,
    T_NONE = 263,
    T_TRUE = 264,
    T_LAND = 265,
    T_BREAK = 266,
    T_CONTINUE = 267,
    T_ELIF = 268,
    T_DEL = 269,
    T_ELSE = 270,
    T_FOR = 271,
    T_IF = 272,
    T_IN = 273,
    T_NOT = 274,
    T_LOR = 275,
    T_WHILE = 276,
    T_INPUT = 277,
    T_PRINT = 278,
    T_INT = 279,
    T_FLOAT = 280,
    T_STR = 281,
    T_LIST = 282,
    T_SPLIT = 283,
    T_MAP = 284,
    T_APPEND = 285,
    T_POP = 286,
    T_INSERT = 287,
    T_LEN = 288,
    T_ID = 289,
    T_CINT = 290,
    T_CFLOAT = 291,
    T_SEMI = 292,
    T_COMMA = 293,
    T_CSTR = 294,
    T_EPOP = 295,
    T_MUL = 296,
    T_DIV = 297,
    T_FDIV = 298,
    T_MOD = 299,
    T_ADD = 300,
    T_SUB = 301,
    T_ASOP = 302,
    T_G = 303,
    T_L = 304,
    T_GE = 305,
    T_LE = 306,
    T_EOP = 307,
    T_NEOP = 308,
    T_XOR = 309,
    T_BAND = 310,
    T_BOR = 311,
    T_LBRACE = 312,
    T_RBRACE = 313,
    T_LPAREN = 314,
    T_RPAREN = 315,
    T_LBRACKET = 316,
    T_RBRACKET = 317,
    T_RANGE = 318,
    T_COLON = 319
  };
#endif
/* Tokens.  */
#define T_DOT 258
#define T_DEDENT 259
#define T_LINE 260
#define T_INDENT 261
#define T_FALSE 262
#define T_NONE 263
#define T_TRUE 264
#define T_LAND 265
#define T_BREAK 266
#define T_CONTINUE 267
#define T_ELIF 268
#define T_DEL 269
#define T_ELSE 270
#define T_FOR 271
#define T_IF 272
#define T_IN 273
#define T_NOT 274
#define T_LOR 275
#define T_WHILE 276
#define T_INPUT 277
#define T_PRINT 278
#define T_INT 279
#define T_FLOAT 280
#define T_STR 281
#define T_LIST 282
#define T_SPLIT 283
#define T_MAP 284
#define T_APPEND 285
#define T_POP 286
#define T_INSERT 287
#define T_LEN 288
#define T_ID 289
#define T_CINT 290
#define T_CFLOAT 291
#define T_SEMI 292
#define T_COMMA 293
#define T_CSTR 294
#define T_EPOP 295
#define T_MUL 296
#define T_DIV 297
#define T_FDIV 298
#define T_MOD 299
#define T_ADD 300
#define T_SUB 301
#define T_ASOP 302
#define T_G 303
#define T_L 304
#define T_GE 305
#define T_LE 306
#define T_EOP 307
#define T_NEOP 308
#define T_XOR 309
#define T_BAND 310
#define T_BOR 311
#define T_LBRACE 312
#define T_RBRACE 313
#define T_LPAREN 314
#define T_RPAREN 315
#define T_LBRACKET 316
#define T_RBRACKET 317
#define T_RANGE 318
#define T_COLON 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 101 "python.y"
 struct{char value[1024]; int type;}ctype; char val[1024];

#line 188 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
