/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IFX = 258,
     ELSE = 259,
     OP_EQ = 260,
     OP_NE = 261,
     IDENTIFIER = 262,
     STRING_LITERAL = 263,
     SIZEOF = 264,
     HEX = 265,
     STRING = 266,
     UNS32 = 267,
     UNS64 = 268,
     FLOAT32 = 269,
     FLOAT64 = 270,
     PTR_OP = 271,
     INC_OP = 272,
     DEC_OP = 273,
     LEFT_OP = 274,
     RIGHT_OP = 275,
     MUL_ASSIGN = 276,
     DIV_ASSIGN = 277,
     MOD_ASSIGN = 278,
     ADD_ASSIGN = 279,
     SUB_ASSIGN = 280,
     LEFT_ASSIGN = 281,
     RIGHT_ASSIGN = 282,
     AND_ASSIGN = 283,
     XOR_ASSIGN = 284,
     OR_ASSIGN = 285,
     CAT_ASSIGN = 286,
     TYPE_NAME = 287,
     OP_OR = 288,
     OP_AND = 289,
     OP_LT = 290,
     OP_ST = 291,
     OP_LE = 292,
     OP_SE = 293,
     SEMICOLON = 294,
     LCURLY = 295,
     RCURLY = 296,
     COMMA = 297,
     COLON = 298,
     ASSIGN = 299,
     LPAREN = 300,
     RPAREN = 301,
     LBRACKET = 302,
     RBRACKET = 303,
     DOT = 304,
     AND = 305,
     NOT = 306,
     CAT = 307,
     MINUS = 308,
     PLUS = 309,
     MUL = 310,
     DIV = 311,
     MOD = 312,
     XOR = 313,
     OR = 314,
     QUESTION = 315,
     TYPEDEF = 316,
     EXTERN = 317,
     STATIC = 318,
     AUTO = 319,
     CHAR = 320,
     SHORT = 321,
     INT = 322,
     LONG = 323,
     SIGNED = 324,
     UNSIGNED = 325,
     FLOAT = 326,
     DOUBLE = 327,
     CONST = 328,
     VOLATILE = 329,
     VOID = 330,
     CASE = 331,
     DEFAULT = 332,
     IF = 333,
     SWITCH = 334,
     WHILE = 335,
     DO = 336,
     FOR = 337,
     GOTO = 338,
     CONTINUE = 339,
     BREAK = 340,
     RETURN = 341,
     END = 342,
     NEW = 343,
     PROC = 344,
     CLASS = 345,
     STRUCT = 346,
     UNION = 347,
     ENUM = 348,
     ELLIPSIS = 349
   };
#endif
/* Tokens.  */
#define IFX 258
#define ELSE 259
#define OP_EQ 260
#define OP_NE 261
#define IDENTIFIER 262
#define STRING_LITERAL 263
#define SIZEOF 264
#define HEX 265
#define STRING 266
#define UNS32 267
#define UNS64 268
#define FLOAT32 269
#define FLOAT64 270
#define PTR_OP 271
#define INC_OP 272
#define DEC_OP 273
#define LEFT_OP 274
#define RIGHT_OP 275
#define MUL_ASSIGN 276
#define DIV_ASSIGN 277
#define MOD_ASSIGN 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define LEFT_ASSIGN 281
#define RIGHT_ASSIGN 282
#define AND_ASSIGN 283
#define XOR_ASSIGN 284
#define OR_ASSIGN 285
#define CAT_ASSIGN 286
#define TYPE_NAME 287
#define OP_OR 288
#define OP_AND 289
#define OP_LT 290
#define OP_ST 291
#define OP_LE 292
#define OP_SE 293
#define SEMICOLON 294
#define LCURLY 295
#define RCURLY 296
#define COMMA 297
#define COLON 298
#define ASSIGN 299
#define LPAREN 300
#define RPAREN 301
#define LBRACKET 302
#define RBRACKET 303
#define DOT 304
#define AND 305
#define NOT 306
#define CAT 307
#define MINUS 308
#define PLUS 309
#define MUL 310
#define DIV 311
#define MOD 312
#define XOR 313
#define OR 314
#define QUESTION 315
#define TYPEDEF 316
#define EXTERN 317
#define STATIC 318
#define AUTO 319
#define CHAR 320
#define SHORT 321
#define INT 322
#define LONG 323
#define SIGNED 324
#define UNSIGNED 325
#define FLOAT 326
#define DOUBLE 327
#define CONST 328
#define VOLATILE 329
#define VOID 330
#define CASE 331
#define DEFAULT 332
#define IF 333
#define SWITCH 334
#define WHILE 335
#define DO 336
#define FOR 337
#define GOTO 338
#define CONTINUE 339
#define BREAK 340
#define RETURN 341
#define END 342
#define NEW 343
#define PROC 344
#define CLASS 345
#define STRUCT 346
#define UNION 347
#define ENUM 348
#define ELLIPSIS 349




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "ISO.y"
{
    isoToken token;
    class NodeAST* node;
    class BlockAST* block;
    class InitDeclListAST* initDecl;
    class InitListAST* init;
    class FunctionAST* func;
    class StringList* arglist;
    class SegmentAST* segment;
    class DeclarationAST* decl;
    class ParaDeclListAST* paraDecl;
    class ParaDeclAST* para;
}
/* Line 1529 of yacc.c.  */
#line 251 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

