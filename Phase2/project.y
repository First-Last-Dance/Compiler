%{
#include <stdio.h>   
#include "SymbolTable.h"
#include "types.h"


nodeType * opr(int oper, int nops, ...);
nodeType * id(int type, char * name);
nodeType * getId(char * name, SymbolTable * table);
nodeType * con(char* value, int type);
void freeNode(nodeType *p);
void ftoa(float n,char res[], int afterpoint);
int ex(nodeType *p) ;//phase 2 semantic analyser;
extern int yyerror(char *);
extern int yyerrorvar(char *s, char *var);
extern int yylex(void);


extern FILE *yyin;
FILE *f1;
FILE *f2;
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
%type <nPtr> function_declaration statement OpeningBRACE expression statement_list boolean_expression ClosingBRACE arithmetic_expression value increment_statement brace_scope for_expression case_expression switch_scope function
%type <iValue> datatype
%type <iValue> Constant

%%

program : 
    function_declaration
    ;

function_declaration : 
    function_declaration statement  {ex($2); freeNode($2);}
    | statement {ex($1); freeNode($1);}
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
    datatype IDENTIFIER SEMICOLON                {$$=id($1,$2);printf("Declare variable\n"); lineIndex++;}
    | IDENTIFIER ASSIGN expression SEMICOLON	          {$$ = opr(ASSIGN,2, getId($1, symbolTable), $3);printf("Assign value\n"); lineIndex++;}
    | datatype IDENTIFIER ASSIGN expression SEMICOLON	      {$$ = opr(ASSIGN,2, id($1,$2), $4);lineIndex++;printf("Declare and initialize variable\n");}
    | Constant IDENTIFIER ASSIGN expression SEMICOLON   {$$ = opr(ASSIGN,2, id($1,$2), $4);printf("Assign constant value\n");}
    | increment_statement SEMICOLON                             {$$=$1; printf("Increment\n"); lineIndex++;}
    | WHILE ORBRACKET expression ERBRACKET brace_scope	  {$$ = opr(WHILE,2, $3, $5);printf("While loop\n");}
    | DO brace_scope WHILE ORBRACKET expression ERBRACKET SEMICOLON	{$$ = opr(DO,2, $2, $5);printf("Do-while loop\n");}
    | FOR ORBRACKET IDENTIFIER ASSIGN INTEGERNUMBER SEMICOLON 
      boolean_expression SEMICOLON 
      for_expression ERBRACKET brace_scope			{char c[] = {}; sprintf(c,"%d",$5);$$ = opr(FOR, 4, opr(ASSIGN, 2, getId($3,symbolTable), con(c, 0)), $7, $9, $11);printf("For loop\n");}
    /* | FOR ORBRACKET INT IDENTIFIER ASSIGN INTEGERNUMBER SEMICOLON 
      boolean_expression SEMICOLON 
      for_expression ERBRACKET brace_scope			{printf("why ?");char c[] = {}; sprintf(c,"%d",$6);$$ = opr(FOR, 4, opr(ASSIGN, 2, id(0, $4), con(c, 0)), $8, $10, $12);printf("For loop\n");} */
    | IF ORBRACKET expression ERBRACKET brace_scope %prec IFX {$$ = opr(IF, 2, $3, $5);printf("If statement\n");}
    | IF ORBRACKET expression ERBRACKET brace_scope ELSE brace_scope	{$$ = opr(IF, 3, $3, $5, $7);printf("If-else statement\n");}
    | SWITCH ORBRACKET IDENTIFIER ERBRACKET switch_scope      {$$ = opr(SWITCH, 2, getId($3,symbolTable), $5);printf("Switch case\n");}
    /* | PRINT expression 	SEMICOLON	                        {printf("Print\n");} */
    /* | function_call	     SEMICOLON                                       */
    /* | RET expression SEMICOLON		{printf("Return value\n");} */
    /* | RET SEMICOLON		{printf("Return\n");} */
    | function 
    | brace_scope											{printf("New scope\n");} 
    ;

 function : 
    datatype IDENTIFIER ORBRACKET argument_list ERBRACKET OpeningBRACE statement_list RET expression SEMICOLON ClosingBRACE      { char c[] = {}; sprintf(c,"%d",$1);  $$=opr( RET,3,con(c ,0),$7,$9 ); printf("function\n");printf("Define function\n");}
    | datatype IDENTIFIER ORBRACKET ERBRACKET OpeningBRACE statement_list RET expression SEMICOLON ClosingBRACE      { char c[] = {}; sprintf(c,"%d",$1);  $$=opr( RET,3,con(c ,0),$6,$8 );printf("Define function\n");}
    ;

/* function_call : 
    IDENTIFIER ORBRACKET argument_list ERBRACKET  {printf("function call\n");}
    ; */
       
argument_list :  
    datatype IDENTIFIER continuation
    | datatype IDENTIFIER
    ;

continuation :  
    COMMA datatype IDENTIFIER continuation 
    | COMMA datatype IDENTIFIER
    ;  
           
            
brace_scope: 
    OpeningBRACE statement_list ClosingBRACE	{$$ = $2; printf("Block of statements\n");}
    | OpeningBRACE ClosingBRACE	
    ;

OpeningBRACE: OBRACE {blockLevel++ ;symbolTable = createChild(symbolTable); printf("Block %d\n", blockLevel);};
ClosingBRACE: EBRACE {printf("End of block %d\n", blockLevel); symbolTable = deleteChild(symbolTable);  blockLevel--;};

switch_scope:  
    OpeningBRACE case_expression ClosingBRACE	    {$$ = $2;printf("Switch case block\n");}		
    ;
        
statement_list:  
    statement 
    | statement_list statement  { $$ = opr(SEMICOLON, 2, $1, $2); };


arithmetic_expression :   
    expression PLUS	expression {$$ = opr(PLUS, 2, $1, $3); }
    | expression MINUS expression  {$$= opr(MINUS,2,$1,$3);}
    | expression MUL expression    {$$= opr(MUL, 2 ,$1,$3);}
    | expression  DIV	expression {$$= opr(DIV, 2 ,$1,$3);}
    | expression  REM	expression {$$= opr(REM, 2 ,$1,$3);}
    | expression  POWER	expression  {$$= opr(POWER, 2 ,$1,$3);}
    | MINUS expression %prec UMINUS   { $$ = opr(UMINUS, 1, $2); } 
    | IDENTIFIER INCREMENT                 {$$=opr(INCREMENT,1,getId($1, symbolTable));}
    | IDENTIFIER DECREMENT                 {$$=opr(DECREMENT,1,getId($1, symbolTable));}
    ;

increment_statement: 
    IDENTIFIER INCREMENT                 {$$=opr(INCREMENT,1,getId($1, symbolTable));}
    | IDENTIFIER DECREMENT                 {$$=opr(DECREMENT,1,getId($1, symbolTable));}
    | IDENTIFIER PEQUAL expression    { $$ = opr(ASSIGN, 2,getId($1, symbolTable), opr(PLUS, 2, getId($1, symbolTable), $3)); }
    | IDENTIFIER MEQUAL expression    { $$ = opr(ASSIGN, 2,getId($1, symbolTable), opr(MINUS, 2, getId($1, symbolTable), $3)); }
    | IDENTIFIER MULEQUAL expression  { $$ = opr(ASSIGN, 2,getId($1, symbolTable), opr(MUL, 2, getId($1, symbolTable), $3)); }
    | IDENTIFIER DIVEQUAL expression  { $$ = opr(ASSIGN, 2,getId($1, symbolTable), opr(DIV, 2, getId($1, symbolTable), $3)); }
    ;


for_expression : 
    increment_statement                 {$$=$1;}
    | IDENTIFIER ASSIGN arithmetic_expression  {$$ = opr(ASSIGN, 2, getId($1,symbolTable), $3);};;
     
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
    | INTEGERNUMBER  { char c[] = {};sprintf(c,"%d",$1); $$ = con(c, 0); printf("Integer\n");}                 
    | CHARACTER { $$ = con($1, 2); }
    | FALSE { $$ = con("false", 4); }
    | TRUE { $$ = con("true", 4); }
    | TEXT { $$ = con($1, 3); };
    | IDENTIFIER { $$ = getId($1, symbolTable); } ;

expression: 
    value { $$ = $1;}
    | arithmetic_expression { $$ = $1; }
    | boolean_expression    { $$ = $1; }
    /* | function_call */
    | ORBRACKET expression ERBRACKET { $$ = $2; }

case_expression: 
    DEFAULT COLON statement_list BREAK SEMICOLON   { $$ = opr(DEFAULT, 2, $3, opr(BREAK, 0)); }                             
    | CASE INTEGERNUMBER COLON statement_list BREAK SEMICOLON   case_expression  { char c[] = {}; sprintf(c,"%d",$2); $$ = opr(CASE, 4, con(c, 0), $4, opr(BREAK, 0), $7); }
    | CASE INTEGERNUMBER COLON statement_list  case_expression  { char c[] = {}; sprintf(c,"%d",$2); $$ = opr(CASE, 3, con(c, 0), $4, $5); }
    ;

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
        data->table = symbolTable;
    }

    SymbolTableNode *node = malloc(sizeof(SymbolTableNode));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
	
    insertFirst(symbolTable, node);

    /* copy information */
    p->type = typeId;
    p->id.table = symbolTable;
    p->id.node = node;
    p->id.name 	= strdup(name);
    p->id.type 	= type;

    /* p->id.index = index; */

    // dont need these - get them directly from sym table -- leave them for Rana
    /* p->id.type 	= type;
    p->id.per 	= perm;
  
    // insert into symbol table
    /* int init = 0;
    int used = 0;
    struct SymTableData * data1 = getSymTableData(type,init,used,brace,name,perm);
    insertFirst(index,data1); */

    return p;
}

nodeType * getId(char * name, SymbolTable * table)
{

    nodeType *p;
    struct SymbolTableNode * node = getSymbolTableNode(symbolTable, name);
    
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)         
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    
    p->id.type 	= node->data->symbolType;
    p->id.name 	= strdup(node->data->symbolName);
    p->id.table = table;
    p->id.node = node;


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

int yyerror(char *s) 
{ 
	fclose(f1);
	remove("output.txt"); 
	f1=fopen("output.txt","w");
	fprintf(f1, "Syntax Error Could not parse quadruples\n"); 
	fprintf(f1, "line number : %d %s\n", yylineno,s);    
 
 	fclose(f2);
	remove("symbol.txt");
	f2 = fopen("symbol.txt","w");
	fprintf(f2, "Syntax Error was Found\n");
 	fprintf(stderr, "line number : %d %s\n", yylineno,s);    
 
	exit(0);
}
 
int yyerrorvar(char *s, char *var) 
{
	fclose(f1);
	remove("output.txt");
	f1 = fopen("output.txt","w");
	fprintf(f1, "Syntax Error Could not parse quadruples\n");
 	fprintf(f1, "line number: %d %s : %s\n", yylineno,s,var);
	
	fclose(f2);
	remove("symbol.txt");
	f2 = fopen("symbol.txt","w");
	fprintf(f2, "Syntax Error was Found\n");
 	fprintf(f2, "line number: %d %s : %s\n", yylineno,s,var);
	
 	exit(0);
}

int main(int argc, char *argv[]) 
{   
    if(argc < 4) {
        printf("Please provide an input file, output file, and symbol file.\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    f1 = fopen(argv[2],"w");
    f2 = fopen(argv[3],"w");
    symbolTable = createSymbolTable();
    if(!yyparse())
    {
        printf("\nParsing complete\n");
        
        printList(symbolTable);
        
        /* Print(f2); */
        /* printNotInit(f2); */
        
        fprintf(f2,"-----------------------------------------------\n\n");
    
        /* printUsed(f2); */
        /* printNotUsed(f2); */
        
    }
    else
    {
        printf("\nParsing failed\n");
        return 0;
    }
    fclose(f1);
    fclose(f2);
    fclose(yyin);
    return 0;
}