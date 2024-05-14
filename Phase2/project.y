%token COMMA RET BREAK DEFAULT SWITCH DO CASE OBRACE EBRACE ORBRACKET ERBRACKET SEMICOLON COLON INCREMENT DECREMENT PEQUAL MEQUAL MULEQUAL DIVEQUAL GREATER LESS GE LE EQ NE PLUS MINUS MUL DIV REM AND OR NOT WHILE FOR IF ELSE PRINT INT FLOAT DOUBLE LONG CHAR STRING CONST INTEGERNUMBER FLOATNUMBER TEXT CHARACTER IDENTIFIER ASSIGN POWER FALSE TRUE BOOL

%left ASSIGN
%left GREATER LESS GE LE EQ NE AND OR NOT
%left PLUS MINUS 
%left DIV MUL REM
%left POWER
%nonassoc IFX
%nonassoc ELSE
%nonassoc UMINUS

%{
#include <stdio.h>   
#include "SymbolTable.h"


int yyerror(char *);
int yylex(void);

extern FILE *yyin;
extern int yylineno;

int lineIndex = 0;
int blockLevel = 0;

SymbolTable* symbolTable;

%}

%%

program : 
    function_declaration
    ;

function_declaration : 
    function_declaration statement  
    |
    ;
        
statement : 
    datatype IDENTIFIER SEMICOLON                {printf("Declare variable\n");}
    | IDENTIFIER ASSIGN expression SEMICOLON	          {printf("Assign value\n");}
    | datatype IDENTIFIER ASSIGN expression SEMICOLON	      {printf("Declare and initialize variable\n");}
    | CONST datatype IDENTIFIER ASSIGN expression SEMICOLON   {printf("Assign constant value\n");}
    | increment_statement SEMICOLON                             {printf("Increment\n");}
    | WHILE ORBRACKET expression ERBRACKET statement	  {printf("While loop\n");}
    | DO brace_scope WHILE ORBRACKET expression ERBRACKET SEMICOLON	{printf("Do-while loop\n");}
    | FOR ORBRACKET INT IDENTIFIER ASSIGN INTEGERNUMBER SEMICOLON 
      boolean_expression SEMICOLON 
      for_expression ERBRACKET
      brace_scope											  {printf("For loop\n");}
    | IF ORBRACKET expression ERBRACKET brace_scope %prec IFX {printf("If statement\n");}
    | IF ORBRACKET expression ERBRACKET brace_scope ELSE brace_scope	{printf("If-else statement\n");}
    | SWITCH ORBRACKET IDENTIFIER ERBRACKET switch_scope      {printf("Switch case\n");}
    | PRINT expression 	SEMICOLON	                        {printf("Print\n");}
    | function_call	     SEMICOLON                                      
    | RET expression SEMICOLON		{printf("Return value\n");}
    | RET SEMICOLON		{printf("Return\n");}
    | function 
    | brace_scope											{printf("New scope\n");}
    ;

function : 
    datatype IDENTIFIER ORBRACKET argument_list ERBRACKET OpeningBRACE statement_list ClosingBRACE      {printf("Define function\n");}
    ;

function_call : 
    IDENTIFIER ORBRACKET argument_list ERBRACKET  {printf("function call\n");}
    ;
       
argument_list :  
    datatype IDENTIFIER continuation
    |
    ;

continuation :  
    COMMA datatype IDENTIFIER continuation 
    |
    ;  
           
            
brace_scope: 
    OpeningBRACE statement_list ClosingBRACE								{printf("Block of statements\n");}
    | OpeningBRACE ClosingBRACE	
    ;

OpeningBRACE: OBRACE {blockLevel++; printf("Block %d\n", blockLevel);};
ClosingBRACE: EBRACE {printf("End of block %d\n", blockLevel); blockLevel--;};

switch_scope:  
    OpeningBRACE case_expression ClosingBRACE					    {printf("Switch case block\n");}		
    ;
        
statement_list:  
    statement 
    | statement_list statement ;

datatype :   
    INT
    | FLOAT
    | DOUBLE
    | LONG
    | CHAR
    | STRING
    | BOOL
    ;

arithmetic_expression :   
    expression PLUS    expression { $$ = $1 + $3;}
    | expression MINUS expression  { $$ = $1 - $3; }
    | expression MUL expression    { $$ = $1 * $3; }
    | expression  DIV    expression { $$ = $1 / $3; }
    | expression  REM    expression { $$ = $1 % $3; }
    | expression  POWER  expression { $$ = $1 % $3; }
    | MINUS expression %prec UMINUS    { $$ = -$1; }
    | IDENTIFIER INCREMENT                 { $$ = $1+1; }
    | IDENTIFIER DECREMENT                 { $$ = $1+1; }

increment_statement: 
    IDENTIFIER  INCREMENT              { $$ = $1+1; }
    | IDENTIFIER DECREMENT                { $$ = $1+1; }
    | IDENTIFIER PEQUAL expression    { $1 = $1+$3; }
    | IDENTIFIER MEQUAL expression    { $1 = $1-$3; }
    | IDENTIFIER MULEQUAL expression  { $1 = $1*$3; }
    | IDENTIFIER DIVEQUAL expression  { $1 = $1/$3; }
    ;


for_expression : 
    increment_statement                 {$$=$1;}
    | IDENTIFIER ASSIGN arithmetic_expression ;
     
boolean_expression: 
     expression AND expression          { $$ = $1 && $3; }
    | expression OR expression                { $$ = $1 || $3; }
    | NOT expression                          { $$ = ! $2; }
    | expression GREATER expression         { $$ = $1 > $3; }
    | expression LESS expression                { $$ = $1 < $3; }
    | expression GE expression                  { $$ = $1 >= $3; }
    | expression LE expression                  { $$ = $1 <= $3; }
    | expression NE expression                  { $$ = $1 != $3; }
    | expression EQ expression                  { $$ = $1 == $3; }
    ;
            
value:
    FLOATNUMBER               
    | INTEGERNUMBER                 
    | CHARACTER
    | FALSE 
    | TRUE
    | TEXT
    | IDENTIFIER;

expression: 
    value
    | arithmetic_expression
    | boolean_expression 
    | function_call
    | ORBRACKET expression ERBRACKET;

case_expression: 
    DEFAULT COLON statement_list BREAK SEMICOLON                              
    | CASE INTEGERNUMBER COLON statement_list BREAK SEMICOLON   case_expression  		
    ;

%% 

int yyerror(char *s) {  
    int lineno = ++yylineno;   
    fprintf(stderr, "Line number : %d %s\n", lineno, s);     
    return 0; 
}

int main(void) {    
    yyin = fopen("input.txt", "r");


    symbolTable = createSymbolTable();
    
    if (!yyparse()) {
        printf("\nParsing complete\n");
    } else {
        printf("\nParsing failed\n");
        return 0;
    }
    
    fclose(yyin);
    
    return 0;
}
