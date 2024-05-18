#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Symboltable.h"
#include "types.h"
#include "y.tab.h"

/* Function declarations */
void generateMove(char* source, int destination);
void generateArithmetic(char* operation, int resultReg, int leftReg, int rightReg);
int isTypeCompatible(int leftType, int rightType);
int isBooleanTypeValid(char* value);
int isTypeCompatibleForEqualityOps(int type1, int type2);


static int lbl; // used for labeling instructions
int leftType;   // representing left types of operands.
int rightType;  // representing right types of operands.
int last = 0;  //  Index of the last register used
int l=0;       // A counter used in switch case SWITCH
int counter = -1; //  A counter used to keep track of operations
int br = 0;  // Counter for brace operations
int permit;  // Used in permission checking
char* oprType;  // String representing operation type
int base;  // register used in SWITCH
int value;  // Value of operands


int ex(nodeType *p) {
	
    int lbl1, lbl2; // Labels used for branching or jumping
    int type1;   // Store the types of operands 
	int type2;   // Store the types of operands 
	int i,j;     // Used as temporary variables 
	
    if (!p) return 0; // if p = NUll return 0
	
    switch(p->type) 
	{
	case typeCon: 
		//{ Integer, Float, Char, String, Bool, ConstIntger, ConstFloat, ConstChar, ConstString, ConstBool} 
		rightType = p->con.type;
		// if
		// (
		// 	( leftType == 5 && ( rightType != 5 && rightType != 0 )) || 											//integer
		// 	( leftType == 6 && ( rightType != 6 && rightType != 1 && rightType != 5 && rightType != 0 )) || 		//float
		// 	( leftType == 7 && ( rightType != 7 && rightType != 2 )) || 											//char
		// 	( leftType == 8 && ( rightType != 8 && rightType != 3 && rightType != 7 && rightType != 2 )) || 		//string
		// 	( leftType == 9 && ( rightType != 9 && rightType != 4 && rightType != 5 && rightType != 0 ))    		//Bool
		// )
		// {			
		// 	yyerror("Error: incompatible types for assignment ");
			//fprintf( f1," Error in type %d \n", p->con.type);
		// 	break;
		// }
		
		// if (leftType == 9 || leftType == 4 ) // bool 
		// {
			
		// 	if (atoi(p->con.value) != 0 && atoi(p->con.value) != 1 && p->con.value != "true" && p->con.value != "false")
		// 	{
		// 		yyerror("Error: incompatible types for Boolean assignment ");
		// 		//fprintf( f1," Error in type %d \n", p->con.type);
		// 		break;
		// 	}
		// }

        // Call isTypeCompatible to check compatibility
        if (!isTypeCompatible(leftType, rightType)) {
            yyerror("Error: incompatible types for assignment ");
            break;
        }

        // Check for Boolean type and call isBooleanTypeValid
        if (leftType == 9 || leftType == 4) { // bool
            if (!isBooleanTypeValid(p->con.value)) {
                yyerror("Error: incompatible types for Boolean assignment ");
                break;
            }
		}
		
		if ( (leftType == 6 || leftType == 1 ) && ( rightType == 5 || rightType == 0 ))
		{
			fprintf( f1, "Warning : Assigning integer to float\n");
			strcat(p->con.value, ".0");
		}
		
		if ( (leftType == 8 || leftType == 3 ) && ( rightType == 7 || rightType == 2 ))
		{
			fprintf( f1, "Warning : Assigning character to string\n");
		}
		
		fprintf( f1, "\t mov R%01d, %s \n", last,p->con.value);
		last ++;
		counter ++;
				
	break;
    case typeId: 
	   
		   
		rightType = p->id.type; // store the type of identifier
    	if (oprType!=NULL && strcmp(oprType,strdup("a")) == 0 )
    	{	
			// int index=(int)p->id.index;
			struct SymbolTableData * data= getSymbolData(p->id.table, p->id.name);
			int init=(int)data->symbolInitialized;
    		if (init == 0)
    		{
    			fprintf(f1,"\t WARNING: Variable %s is not initialized\n",p->id.name);	
    		}
            // move the value of the identifier to a register 
    		fprintf(f1,"\t mov R%01d,%s \n",last,p->id.name);
    		rightType = p->id.type;
    		last ++;
			counter ++;
		}
		//If the identifier is not being assigned a value 
		//for example if identifier is being used in an expression context rather than being assigned
		else 
    	{
       		fprintf( f1, "\t mov R%01d, null \n", last);
			fprintf( f1, "\t mov %s, R%01d \n", p->id.name, last);
			// counter++;
			// last++;
		}
        break;
	// handle arithmetic operations and function calls. 
    case typeOpr:
        switch(p->opr.oper) 
		{
			
		//*********************OBRACE***********************************************************************
		// for the opening brace of a block ( { )
		case OBRACE:
				br = atoi(p->opr.op[0]->con.value); // Retrieves the number of braces of the node and convert it to int 
				// that recursive part for the statements inside the block to check if it have {
				ex(p->opr.op[1]); 
				ex(p->opr.op[2]);		
		break;	
		//*********************EBRACE************************************************************************
		// for the closing brace of a block ( } )
		case EBRACE:
		// setBrace(br);
		br--;
		break;
		
		//*******************SWITCH**************************************************************************
		case SWITCH:
                    oprType = strdup("a");
					ex(p->opr.op[0]);
					base = last - 1;
					ex(p->opr.op[1]);
					l++;
                    oprType = NULL;
		break;
		//*********************************Case*******************************************	
		case CASE:
					ex(p->opr.op[0]);
					fprintf( f1, "\t compEQ R%01d, R%01d, R%01d \n", last, base, counter);
					fprintf( f1, "\t jnz\tL%03d \n", lbl1 = lbl++); 
					ex(p->opr.op[1]);
					last++;
                    counter++;
					if(p->opr.nops > 3){
						ex(p->opr.op[2]);
						fprintf( f1, "L%03d:\n", lbl1);
						ex(p->opr.op[3]);
					}
					else{
						ex(p->opr.op[2]);
					}
					

        break;
		//********************************Break********************************************			
	    case BREAK:
				  fprintf( f1, "\t jmp Label%01d \n", l);
		break;
	    //********************************Default*******************************************				
		case DEFAULT:
				ex(p->opr.op[0]);
				fprintf( f1, "Label%01d: \n", l);
		break;
		//*********************WHILE*************************************************************************	
        case WHILE:
		    // Generates a label at the beginning of the loop.
            fprintf(f1,"L%03d:\n", lbl1 = lbl++);
			oprType = strdup("a");
            ex(p->opr.op[0]);
			oprType = NULL;
			// Jumps to the end of the loop if the condition is false
            fprintf(f1,"\tjz\tL%03d\n", lbl2 = lbl++);
            ex(p->opr.op[1]);
			// Jumps back to the beginning of the loop lbl1
            fprintf(f1,"\tjmp\tL%03d\n", lbl1);
            fprintf(f1,"L%03d:\n", lbl2);
            break;
			
		//********************DO WHILE*****************************************************************************	
			
		case DO:    
		            // Generates a label at the beginning of the loop.
					fprintf( f1, "L%03d:\n", lbl1 = lbl++);
					ex(p->opr.op[0]);
					oprType = strdup("a");
                    ex(p->opr.op[1]);
					oprType = NULL;
					// Jumps back to the beginning of the loop if the condition is true
					fprintf( f1, "\t jnz\tL%03d\n", lbl1);
		break;	
			
		//********************IF*****************************************************************************	
        case IF:
		   oprType = strdup("a");
           ex(p->opr.op[0]);
		   oprType=NULL;
		    // If the if statement has an else block
            if (p->opr.nops > 2) {
                /* if else */
				// Jumps to the else block if the condition is false
                fprintf(f1,"\tjz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
				// Jumps to the end of the if-else statement
                fprintf(f1,"\tjmp\tL%03d\n", lbl2 = lbl++);
                fprintf(f1,"L%03d:\n", lbl1);
                ex(p->opr.op[2]);
                fprintf(f1,"L%03d:\n", lbl2);
			// If the if statement does not have an else block
            } else {
                /* if */
				// Jumps to the end of the if statement if the condition is false
                fprintf(f1,"\tjz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                fprintf(f1,"L%03d:\n", lbl1);
            }
            break;
			
	//********************************PRINT*******************************************************	
		case PRINT:  
			oprType="a";
            ex(p->opr.op[0]);
			fprintf( f1, "\t print R%01d\n",last-1);
			oprType = NULL;
            break;
			
	//*********************************FOR**********************************************************
		case FOR:
	    	printf("i am here inside for");
			ex(p->opr.op[0]);
		
			fprintf( f1, "L%03d:\n", lbl1 = lbl++);
			ex(p->opr.op[1]);
		    // Jumps to the end of the loop if the condition is false
			fprintf( f1, "\t jnz\tL%03d\n", lbl2 = lbl++);
			ex(p->opr.op[3]);
		
			ex(p->opr.op[2]);
		    // Jumps back to the beginning of the loop
			fprintf( f1, "\t jmp\tL%03d\n", lbl1);
			fprintf( f1, "L%03d:\n", lbl2); 
			oprType = NULL;
	 
			
		break;
	 //***********************************ASSIGN*******************************************************		
		case ASSIGN:
			printf("lol");
			leftType = p->opr.op[0]->id.type;
			oprType = strdup("a");
			if(p->opr.op[0]->id.node->data->symbolInitialized == true){
				if(p->opr.op[0]->id.node->data->symbolType == ConstIntger || p->opr.op[0]->id.node->data->symbolType == ConstFloat || p->opr.op[0]->id.node->data->symbolType == ConstChar || p->opr.op[0]->id.node->data->symbolType == ConstString || p->opr.op[0]->id.node->data->symbolType == ConstBool)
				{
					printf("Error: left operands must be a modifiable expression");
					yyerror("Error: left operands must be a modifiable expression");
					oprType = NULL;
					break;
				}
			}
			ex(p->opr.op[1]);
			// Check compatibility of types between left and right operands
			if((leftType == Integer || leftType == ConstIntger) && (rightType == Integer || rightType == ConstIntger  )) {;}
			else if((leftType == Float || leftType == ConstFloat) && (rightType == Float || rightType == ConstFloat || rightType == Integer || rightType == ConstIntger)) {;}
			else if((leftType == Char || leftType == ConstChar) && (rightType == Char || rightType == ConstChar || rightType == Integer || rightType == ConstIntger)) {;}
			else if((leftType == String || leftType == ConstString) && (rightType == String || rightType == ConstString || rightType==Char || rightType==ConstChar)) {;}
			else if((leftType == Bool || leftType == ConstBool) && (rightType == Bool || rightType == ConstBool || rightType == Integer || rightType == ConstIntger)) {;}
			else if(leftType != rightType) 
			{				
				yyerror("Error: incompatible types for assignment ");
				oprType = NULL;
				break;
			}

			if(p->opr.op[1]->type == typeId) 
			{

				if(p->opr.op[1]->id.node->data->symbolInitialized)
				{
					p->opr.op[0]->id.node->data->symbolValue = strdup(p->opr.op[1]->id.node->data->symbolValue);
				}
				else{
					yyerror("Error: Right hand side of assignment is not initialized");

				}
                   
			}
			else if(p->opr.op[1]->type == typeCon){
				p->opr.op[0]->id.node->data->symbolValue = strdup(p->opr.op[1]->con.value);
			}
            
				p->opr.op[0]->id.node->data->symbolInitialized = true;
					
			fprintf( f1, "\t mov %s, R%01d \n", p->opr.op[0]->id.name, last - 1);
			p->opr.op[0]->id.node->data->symbolInitialized = true;
			last =0;
			counter =-1;
            oprType = NULL;
            leftType = -9;
            rightType = -9;
			break;
			
		//****************************************func********************************
		  
		 case  RET:
		 
		  fprintf( f1, "\t func begin \n");
		  ex(p->opr.op[1]);
		  oprType="a";
		  ex(p->opr.op[2]);
		  
		  leftType=atoi(p->opr.op[0]->con.value);
		  // Checks if the return type matches the function's declared return type
		  if(leftType != rightType)
			  yyerror("Error: incompatible return types for function ");
		  
		  fprintf( f1, "\t func end \n");
		  oprType=NULL;
			  
		break;	
		//****************************************UMINUS******************************			
        case UMINUS:    
            ex(p->opr.op[0]);
			// Generates code to minus the value in the last register
            
            fprintf(f1, "\t neg R%01d, R%01d \n", last, counter);
			last++;
			counter++;
            break;
			
	   //******************************************DEFAULT******************************		
        default:
			oprType = strdup("a");
            if(p->opr.op[0]->type == typeId && p->opr.op[0]->id.per != undeclared){;}
			// setUsed(p->opr.op[0]->id.index);
			ex(p->opr.op[0]);
			
			i = counter;
			type1 = rightType;
			
			
			if(p->opr.oper != NOT && p->opr.oper != INCREMENT && p->opr.oper != DECREMENT) 
			{
                if(p->opr.op[1]->type == typeId && p->opr.op[1]->id.per != undeclared)
				{
					oprType = strdup("a");
					// setUsed(p->opr.op[1]->id.index);
				}	
				ex(p->opr.op[1]);
				type2 = rightType;
					
			}
			j = counter;
            switch(p->opr.oper) 
			{
			    case PLUS:
					if((type1 == Integer || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)) 
					{
                        generateArithmetic("add", last, i, j);
					}
					else 
					{
						yyerror("Error: incompatible types for addition ");
					}
						oprType = NULL;
				break;
							
				case MINUS:
					if((type1 == Integer || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)) 
					{
                        generateArithmetic("sub", last, i, j);
					}
					else 
					{
						yyerror("Error: incompatible types for subtraction ");
					}
                    oprType = NULL;
				break;
							
				case MUL:
					if((type1 == Integer || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 ==  Float || type2 == ConstIntger || type2 == ConstFloat)) 
					{
                        generateArithmetic("mul", last, i, j);
					}
					else 
					{
						yyerror("Error: incompatible types for multiplication ");
					}
                    oprType = NULL;
				break;	
				case DIV:
				if(p->opr.op[1]->type == typeCon){
				value = atoi(p->opr.op[1]->con.value);			
				}
				else if(p->opr.op[1]->type == typeId){
					struct SymbolTableData * data= getSymbolData(p->opr.op[1]->id.table, p->opr.op[1]->id.name);
					if(data->symbolType == Integer || data->symbolType == ConstIntger){
						value = atoi(data->symbolValue);
					}
					else if(data->symbolType == Float || data->symbolType == ConstFloat){
						value = atof(data->symbolValue);
					}
					else{
						yyerror("Error: incompatible types for division ");
					}


				}
				if(value == 0){
					yyerror("Error: Division by zero ");
				}
				if( value!=0  &&(type1 == Integer || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 == Float  || type2 == ConstIntger || type2 == ConstFloat)) {
                    generateArithmetic("div", last, i, j);
				}
				else 
				{
					yyerror("Error: incompatible types for division ");
				}
				oprType = NULL;
				break;
			case REM:
				if((type1 == Integer || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 == Float  || type2 == ConstIntger || type2 == ConstFloat)) {
                    generateArithmetic("rem", last, i, j);
				}
				else 
				{
					yyerror("Error: incompatible types for remainder ");
				}
				oprType = NULL;
				break;
			case POWER:
				if((type1 == Integer || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 == Float  || type2 == ConstIntger || type2 == ConstFloat)) {
                    generateArithmetic("power", last, i, j);
				}
				else 
				{
					yyerror("Error: incompatible types for power ");
				}
				oprType = NULL;
				break;
			case NOT:				
				rightType = Bool;
				if(type1 == Bool || type1 == ConstBool) 
				{
					fprintf( f1, "\t not R%01d \n", last-1);
				}
				else 
				{
					yyerror("Error: incompatible types for not ");
				}
				oprType = NULL;				
				break;				
			case AND:	
				rightType = Bool;
				if((type1 == Bool || type1 == ConstBool) && (type2 == Bool || type2 == ConstBool)) {
                    generateArithmetic("and", last, i, j);
				}
				else 
				{
					yyerror("Error: incompatible types for && ");
				}
				oprType = NULL;
				break;				
			case OR:
				rightType = Bool;
				if((type1 == Bool || type1 == ConstBool) && (type2 == Bool || type2 == ConstBool)) 
				 {
                    generateArithmetic("or", last, i, j);
				}
				else 
				{
					yyerror("Error: incompatible operands types for ||");
				}
				oprType = NULL;
				break;
			
			case GREATER:
				rightType = Bool;
				if((type1 == Integer || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)){
                    generateArithmetic("compGREATER", last, i, j);
				}
				else {
					yyerror("Error: incompatible operands types for >");
				}
				oprType = NULL;
				break;
			case LESS:
				rightType = Bool;
				if((type1 == Integer || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)){
                    generateArithmetic("compLESS", last, i, j);
				}
				else {
					yyerror("Error: incompatible operands types for <");
				}
				oprType = NULL;
				break;
			case GE:
				rightType = Bool;
				if((type1 ==Integer  || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)){
                    generateArithmetic("compGE", last, i, j);
				}
				else {
					yyerror("Error: incompatible operands types for >=");
				}
				oprType = NULL;
				break;
			case LE:
				rightType = Bool;
				if((type1 ==Integer  || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)){
                    generateArithmetic("compLE", last, i, j);
                    
				}
				else {
					yyerror("Error: incompatible operands types for <=");
				}
				oprType = NULL;
				break;
			case NE:
				rightType = Bool;
                
                if (isTypeCompatibleForEqualityOps(type1, type2)) {
                    generateArithmetic("compNE", last, i, j);
                } else {
                    yyerror("Error: incompatible operands types for !=");
                    oprType = NULL;
                    break;
                }
                oprType = NULL;
                break;


			case EQ:
				rightType = Bool;

                if (isTypeCompatibleForEqualityOps(type1, type2)) {
                    generateArithmetic("compEQ", last, i, j);
                } else {
                    yyerror("Error: incompatible operands types for ==");
                    oprType = NULL;
                    break;
                }
                oprType = NULL;
                break;

			case INCREMENT:
				if(type1 == Integer || type1 == Float) 
				{
					fprintf( f1, "\t inc R%01d \n", last-1);
					fprintf( f1, "\t mov %s, R%01d \n", p->opr.op[0]->id.name, last - 1);

				}
				else 
				{
					yyerror("Error: incompatible operands for increment");
				}
				oprType = NULL;
				if(!p->opr.op[0]->id.node->data->symbolInitialized){
					yyerror("Error: Left hand side of assignment is not initialized");
					break;
				}
				if(p->opr.op[0]->id.node->data->symbolType == Integer){
					char buffer[50]; // Buffer to hold the string representation of the number
					int tempValue = atoi(p->opr.op[0]->id.node->data->symbolValue) + 1; // Convert the string to an integer and increment it
					sprintf(buffer, "%d", tempValue); // Convert the incremented integer back to a string
					p->opr.op[0]->id.node->data->symbolValue = strdup(buffer);
					} // Duplicate the string and store it				}
				else if(p->opr.op[0]->id.node->data->symbolType == Float){
					char buffer[50]; // Buffer to hold the string representation of the number
					float tempValue = atof(p->opr.op[0]->id.node->data->symbolValue) + 1; // Convert the string to a double and increment it
					sprintf(buffer, "%f", tempValue); // Convert the incremented double back to a string
					p->opr.op[0]->id.node->data->symbolValue = strdup(buffer); // Duplicate the string and store it
				}
				break;
			case DECREMENT:
				if(type1 == Integer || type1 == Float) 
				{
					fprintf( f1, "\t dec R%01d \n", last-1);
					fprintf( f1, "\t mov %s, R%01d \n", p->opr.op[0]->id.name, last - 1);
				}
				else 
				{
					yyerror("Error: incompatible operands for decrement");
				}
				oprType = NULL;
				break;							
			case PEQUAL:				
				if((type1 == Integer || type1 == Float ) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)) 
				{
                    generateArithmetic("add", last, i, j);
                    
				}
				else 
				{
					yyerror("Error: incompatible operands for +=");
				}
				oprType = NULL;
				break;
			case MEQUAL:
				if((type1 == Integer || type1 == Float ) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)) 
				{
                    generateArithmetic("sub", last, i, j);
				}
				else 
				{	
					yyerror("Error: incompatible operands for -=");
				}
				break;
			case MULEQUAL:
				if((type1 == Integer || type1 == Float ) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)) 
				{
                    generateArithmetic("mul", last, i, j);
				}
				else 
				{
					yyerror("Error: incompatible operands for *=");
				}
				break;
			case DIVEQUAL:
				if((type1 == Integer || type1 == Float ) && (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)) 
				{
                    generateArithmetic("div", last, i, j);
				}
				else 
				{
					yyerror("Error: incompatible operands for /=");
				}
				break;    
			}
		}
	}
    return 0;
}



/* Generate move instruction */
void generateMove(char* source, int destination) {
    fprintf(f1, "\t mov R%01d, %s \n", destination, source);
    last++;
    counter++;
}

/* Generate arithmetic instruction */
void generateArithmetic(char* operation, int resultReg, int leftReg, int rightReg) {
    fprintf(f1, "\t %s R%01d, R%01d, R%01d \n", operation, resultReg, leftReg, rightReg);
    last++;
    counter++;
}

/* Helper function to check if two types are compatible */
int isTypeCompatible(int leftType, int rightType) {
    if (
        (leftType == 5 && (rightType != 5 && rightType != 0)) ||                                     // integer
        (leftType == 6 && (rightType != 6 && rightType != 1 && rightType != 5 && rightType != 0)) || // float
        (leftType == 7 && (rightType != 7 && rightType != 2)) ||                                     // char
        (leftType == 8 && (rightType != 8 && rightType != 3 && rightType != 7 && rightType != 2)) || // string
        (leftType == 9 && (rightType != 9 && rightType != 4 && rightType != 5 && rightType != 0))    // Bool
    ) {
        return 0; // Incompatible types
    }
    return 1; // Compatible types
}

/* Helper function to check if a Boolean value is valid */
int isBooleanTypeValid(char* value) {
    if (atoi(value) != 0 && atoi(value) != 1 && strcmp(value, "true") != 0 && strcmp(value, "false") != 0) {
        return 0; // Invalid Boolean value
    }
    return 1; // Valid Boolean value
}


/* Helper function to check if types are compatible for equality/inequality operations */
int isTypeCompatibleForEqualityOps(int type1, int type2) {
    if ((type1 == Integer || type1 == Float || type1 == ConstIntger || type1 == ConstFloat) &&
        (type2 == Integer || type2 == Float || type2 == ConstIntger || type2 == ConstFloat)) {
        return 1;
    } else if ((type1 == Char || type1 == ConstChar) && (type2 == Char || type2 == ConstChar)) {
        return 1;
    } else if ((type1 == String || type1 == ConstString) && (type2 == String || type2 == ConstString)) {
        return 1;
    } else if ((type1 == Bool || type1 == ConstBool) && (type2 == Bool || type2 == ConstBool)) {
        return 1;
    }
    return 0;
}