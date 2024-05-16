%{
#include <stdio.h>   
#include "SymbolTable.h"
#include "types.h"


nodeType * opr(int oper, int nops, ...);
nodeType * id(int type, char * name);
nodeType * getId(char * name);
nodeType * con(char* value, int type);
void freeNode(nodeType *p);
void ftoa(float n,char res[], int afterpoint);
int ex(nodeType *p) ;//phase 2 semantic analyser;
extern int yyerror(char *);
extern int yyerrorvar(char *s, char *var);
extern int yylex(void);
// int yylineno;


extern FILE *yyin;
extern int yylineno;

int lineIndex = 0;
int blockLevel = 0;



SymbolTable* symbolTable;

%}



%union {
    int iValue;                 /* integer value */
	float fValue;               /* float Value */
    char * sValue;              /* string value */
	char * cValue;               /* character value */
	char * id ;                 /* id value */
    nodeType *nPtr;             /* node pointer */
};


%token COMMA RET BREAK DEFAULT SWITCH DO CASE OBRACE EBRACE ORBRACKET ERBRACKET SEMICOLON COLON INCREMENT DECREMENT PEQUAL MEQUAL MULEQUAL DIVEQUAL GREATER LESS GE LE EQ NE PLUS MINUS MUL DIV REM AND OR NOT WHILE FOR IF ELSE PRINT INT FLOAT DOUBLE LONG CHAR STRING CONST  ASSIGN POWER FALSE TRUE BOOL 
%token <iValue> INTEGERNUMBER 
%token <fValue> FLOATNUMBER 
%token <sValue> TEXT 
%token <cValue> CHARACTER 
%token <id>     IDENTIFIER
%left ASSIGN
%left GREATER LESS GE LE EQ NE AND OR NOT
%left PLUS MINUS 
%left DIV MUL REM
%left POWER
%nonassoc IFX
%nonassoc ELSE
%nonassoc UMINUS


/* %type <nPtr> function_declaration function function_call argument_list statement continuation OpeningBRACE expression statement_list brace_scope for_expression boolean_expression case_expression  ClosingBRACE arithmetic_expression increment_statement value */
%type <nPtr> function_declaration statement OpeningBRACE expression statement_list boolean_expression ClosingBRACE arithmetic_expression value
%type <iValue> datatype
%type <iValue> Constant

%%

program : 
    function_declaration
    ;

function_declaration : 
    function_declaration statement  
    | statement
    ;
        
datatype :   
    INT  {$$=0;}
    | FLOAT{$$=1;}
    | CHAR {$$=2;}
    | STRING {$$=3;}
    | BOOL {$$=4;}
    ;

Constant : CONST INT {$$=5;}
        |	CONST FLOAT {$$=6;}
        | CONST CHAR {$$=7;}
        | CONST STRING {$$=8;}
        | CONST BOOL {$$=9;}
        ;

statement : 
    datatype IDENTIFIER SEMICOLON                {$$=id($1,$2);printf("Declare variable\n");}
    | IDENTIFIER ASSIGN expression SEMICOLON	          {printf("Assign value\n");}
    /*| datatype IDENTIFIER ASSIGN expression SEMICOLON	      {printf("Declare and initialize variable\n");}
    | Constant datatype IDENTIFIER ASSIGN expression SEMICOLON   {printf("Assign constant value\n");}
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
    | brace_scope											{printf("New scope\n");} */
    ;

 /* function : 
    datatype IDENTIFIER ORBRACKET argument_list ERBRACKET OpeningBRACE statement_list ClosingBRACE      {printf("Define function\n");}
    ; */

/* function_call : 
    IDENTIFIER ORBRACKET argument_list ERBRACKET  {printf("function call\n");}
    ; */
       
/* argument_list :  
    datatype IDENTIFIER continuation
    ; */

/* continuation :  
    COMMA datatype IDENTIFIER continuation 
    ;   */
           
            
/* brace_scope: 
    OpeningBRACE statement_list ClosingBRACE								{printf("Block of statements\n");}
    | OpeningBRACE ClosingBRACE	
    ; */

OpeningBRACE: OBRACE {blockLevel++; printf("Block %d\n", blockLevel);};
ClosingBRACE: EBRACE {printf("End of block %d\n", blockLevel); blockLevel--;};

/* switch_scope:  
    OpeningBRACE case_expression ClosingBRACE					    {printf("Switch case block\n");}		
    ; */
        
statement_list:  
    statement 
    | statement_list statement ;


arithmetic_expression :   
    expression PLUS	expression {$$ = opr(PLUS, 2, $1, $3); }
    | expression MINUS expression  {$$= opr(MINUS,2,$1,$3);}
    | expression MUL expression    {$$= opr(MUL, 2 ,$1,$3);}
    | expression  DIV	expression {$$= opr(DIV, 2 ,$1,$3);}
    | expression  REM	expression {$$= opr(REM, 2 ,$1,$3);}
    | expression  POWER	expression  {$$= opr(POWER, 2 ,$1,$3);}
    | MINUS expression %prec UMINUS   { $$ = opr(UMINUS, 1, $2); } 
    | IDENTIFIER INCREMENT                 {$$=opr(INCREMENT,1,getId($1));}
    | IDENTIFIER DECREMENT                 {$$=opr(DECREMENT,1,getId($1));}
    ;

/* increment_statement: 
    IDENTIFIER INCREMENT                 {$$=opr(INCREMENT,1,$1);}
    | IDENTIFIER DECREMENT                 {$$=opr(DECREMENT,1,$1);}
    | IDENTIFIER PEQUAL expression    { $$ = opr(PLUS, 2, $1, $1); }
    | IDENTIFIER MEQUAL expression    { $$ = opr(MINUS, 2, $1, $1); }
    | IDENTIFIER MULEQUAL expression  { $$ = opr(MUL, 2, $1, $1); }
    | IDENTIFIER DIVEQUAL expression  {$$= opr(DIV, 2 ,$1,$1);}
    ; */


/* for_expression : 
    increment_statement                 {$$=$1;}
    | IDENTIFIER ASSIGN arithmetic_expression ; */
     
boolean_expression: 
        expression AND expression   { $$ = opr(AND, 2, $1, $3); }       
        | expression OR expression         { $$ = opr(OR , 2, $1, $3); }     
        | NOT expression 				   { $$ = opr(NOT, 1, $2); }                         
        | expression GREATER expression  	   { $$ = opr(GREATER, 2, $1, $3); }		 
        | expression LESS expression         { $$ = opr(LESS, 2, $1, $3); }      
        | expression GE expression           { $$ = opr(GE, 2, $1, $3); }      
        | expression LE expression           { $$ = opr(LE, 2, $1, $3); }      
        | expression NE expression           { $$ = opr(NE, 2, $1, $3); }       
        | expression EQ expression           { $$ = opr(EQ, 2, $1, $3); }  
    ;
            
value:
    FLOATNUMBER      { char c[] = {}; ftoa($1, c, 6); $$ = con(c, 1); }        
    | INTEGERNUMBER  { char c[] = {};sprintf(c,"%d",$1); $$ = con(c, 0); }                 
    | CHARACTER { $$ = con($1, 2); }
    | FALSE { $$ = con("false", 4); }
    | TRUE { $$ = con("true", 4); }
    | TEXT { $$ = con($1, 3); };
    | IDENTIFIER { $$ = getId($1); } ;

expression: 
    value
    | arithmetic_expression
    | boolean_expression 
    /* | function_call */
    | ORBRACKET expression ERBRACKET;

/* case_expression: 
    DEFAULT COLON statement_list BREAK SEMICOLON                              
    | CASE INTEGERNUMBER COLON statement_list BREAK SEMICOLON   case_expression  		
    ; */

%% 

nodeType *con(char* value, int type) 
{
    nodeType *p;

    // allocate node
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    // copy information
    p->type = typeCon;
    p->con.value = strdup(value);
    p->con.type=type;
    return p;
}

nodeType * id(int type, char * name)
{

	nodeType *p;
   
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)         
		yyerror("out of memory");

    SymbolTableData *data = malloc(sizeof(SymbolTableData));
    if (data != NULL) {
        data->symbolType = type;
        data->symbolInitLine = -1;
        data->symbolInitialized = false;
        data->symbolUsedLines = NULL;
        data->symbolBlock = blockLevel;
        data->symbolValue = NULL;
        data->symbolName = strdup(name);
        data->symbolUsedLinesCount = 0;
    }

    SymbolTableNode *node = malloc(sizeof(SymbolTableNode));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
	
    insertFirst(symbolTable, node);

    /* copy information */
    p->type = typeId;
    /* p->id.index = index; */

    // dont need these - get them directly from sym table -- leave them for Rana
    /* p->id.type 	= type;
    p->id.per 	= perm;
    p->id.name 	= strdup(name); */
  
    // insert into symbol table
    /* int init = 0;
    int used = 0;
    struct SymTableData * data1 = getSymTableData(type,init,used,brace,name,perm);
    insertFirst(index,data1); */

    return p;
}

nodeType * getId(char * name)
{

    nodeType *p;
    struct SymbolTableData * data = getSymbolData(symbolTable, name);
    
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)         
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    
    p->id.type 	= data->symbolType;
    p->id.name 	= strdup(data->symbolName);

    return p;
	
}

nodeType *opr(int oper, int nops, ...) 
{
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p)
{
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void reverse(char *str, int len) 
{
	int i=0, j=len-1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

int toStr(int x, char str[], int d) 
{
	int i = 0;
	while (x)
	{
		str[i++] = (x%10) + '0';
		x = x/10;
	}
 
	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';
 
	reverse(str, i);
	str[i] = '\0';
	return i;
}

void ftoa(float n, char res[], int afterpoint) 
{
	
	// Extract integer part
	int ipart = (int)n;
 
	// Extract floating part
	float fpart = n - (float)ipart;
	
 
	// convert integer part to string
	int i = toStr(ipart, res, 0);
 
	// check for display option after point
	if (afterpoint != 0)
	{
		res[i] = '.';  // add dot
 
		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter is needed
		// to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		toStr((int)fpart, res + i + 1, afterpoint);
	}
}

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
        printList(symbolTable);
        
    } else {
        printf("\nParsing failed\n");
        return 0;
    }
    
    fclose(yyin);
    
    return 0;
}
