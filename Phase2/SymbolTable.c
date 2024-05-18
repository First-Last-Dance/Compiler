#include "SymbolTable.h" // Include the symbol table header

// Function to create a new symbol table
SymbolTable *createSymbolTable() {
    SymbolTable *table = (SymbolTable *)malloc(sizeof(SymbolTable));
    if (table == NULL) {
        fprintf(stderr, "Error allocating memory for symbol table\n");
        return NULL;
    }
    table->head = NULL;
    table->blockLevel = 0;
    table->children = NULL;
    table->parent = NULL;
    return table;
}

// Function to insert a symbol data node at the beginning of the symbol table (check for name uniqueness)
void insertFirst(SymbolTable *table, SymbolTableNode *data) {
    SymbolTableNode *current = table->head;
    while (current != NULL) {
        if (strcmp(current->data->symbolName, data->data->symbolName) == 0) {
            fprintf(stderr, "Error: Symbol '%s' already exists in this scope\n", data->data->symbolName);
            free(data); // Free allocated memory for the duplicate node
            return;
        }
        current = current->next;
    }
    data->next = table->head;
    table->head = data;
}

// Function to delete the first node from the symbol table
void deleteFirst(SymbolTable *table) {
    if (table->head == NULL) {
        return;
    }
    SymbolTableNode *temp = table->head;
    table->head = temp->next;
    free(temp->data->symbolName);
    free(temp->data->symbolValue);
    free(temp->data->symbolUsedLines);
    free(temp->data);
    free(temp);
}

// Function to create a child symbol table (for a new block)
SymbolTable *createChild(SymbolTable *table) {
    SymbolTable *child = createSymbolTable();
    child->parent = table;
    int numChildren = table->children ? table->blockLevel + 1 : 1;
    table->children = (SymbolTable **)realloc(table->children, sizeof(SymbolTable *) * numChildren);
    if (table->children == NULL) {
        fprintf(stderr, "Error allocating memory for child symbol tables\n");
        free(child);
        return NULL;
    }
    table->children[table->blockLevel] = child;
    child->blockLevel++;
    return child;
}

// Function to delete a child symbol table and return its parent
SymbolTable *deleteChild(SymbolTable *table) {
    if (table->blockLevel == 0) {
        fprintf(stderr, "Error: Cannot delete root symbol table\n");
        return table;
    }
    // table->blockLevel--;
    SymbolTable *parent = table->parent;
    // int numChildren = table->parent->blockLevel + 1;
    // SymbolTableNode *current = table->head;
    // while (current != NULL) {
    //     // Free memory associated with symbols in the child table
    //     free(current->data->symbolName);
    //     free(current->data->symbolValue);
    //     free(current->data->symbolUsedLines);
    //     free(current->data);
    //     SymbolTableNode *temp = current;
    //     current = current->next;
    //     free(temp);
    // }
    // free(table->children);
    // free(table);
    return parent;
}

// Function to get the parent symbol table
SymbolTable *getParent(SymbolTable *table) {
    return table->parent;
}

// Function to print the contents of the symbol table (for debugging purposes)
void printList(SymbolTable *table) {
    SymbolTableNode *current = table->head;
    printf("Symbol Table (Block Level: %d)\n", table->blockLevel);
    while (current != NULL) {
        printf("  Name: %s, Type: %d, Initialized: %s, Value: %s\n",
               current->data->symbolName, current->data->symbolType,
               current->data->symbolInitialized ? "Yes" : "No",
               current->data->symbolValue ? current->data->symbolValue : "(none)");
        printf("  Used Lines: ");
        for (int i = 0; i < current->data->symbolUsedLinesCount; i++) {
            printf("%d ", current->data->symbolUsedLines[i]);
        }
        printf("\n");
        current = current->next;
    }
}

// Function to set the value of a symbol (also sets initialization flag and line)
void setValue(SymbolTable *table, char *name, char *value, int lineIndex) {
    SymbolTableNode *current = table->head;
    while (current != NULL) {
        if (strcmp(current->data->symbolName, name) == 0) {
            current->data->symbolValue = value;
            current->data->symbolInitialized = true;
            current->data->symbolInitLine = lineIndex;
            return;
        }
        current = current->next;
    }
    fprintf(stderr, "Error: Symbol '%s' not found\n", name);
}

// Function to add a line number where the symbol is used
void addUsedLine(SymbolTable *table, char *name, int line) {
    SymbolTableNode *current = table->head;
    while (current != NULL) {
        if (strcmp(current->data->symbolName, name) == 0) {
            current->data->symbolUsedLinesCount++;
            current->data->symbolUsedLines = (int *)realloc(current->data->symbolUsedLines,
                                                             current->data->symbolUsedLinesCount * sizeof(int));
            current->data->symbolUsedLines[current->data->symbolUsedLinesCount - 1] = line;
            return;
        }
        current = current->next;
    }
    fprintf(stderr, "Error: Symbol '%s' not found\n", name);
}


// Function to free all memory allocated for the symbol table
void freeSymbolTable(SymbolTable *table) {
    if (table == NULL) {
        return;
    }

    // Free child tables recursively
    for (int i = 0; i < table->blockLevel; i++) {
        freeSymbolTable(table->children[i]);
    }
    free(table->children);

    // Free symbol data for each node
    SymbolTableNode *current = table->head;
    while (current != NULL) {
        SymbolTableNode *temp = current;
        current = current->next;
        free(temp->data->symbolName);
        free(temp->data->symbolValue);
        free(temp->data->symbolUsedLines);
        free(temp->data);
        free(temp);
    }

    // Free the table itself
    free(table);
}

// Function to get the data of a symbol
SymbolTableData *getSymbolData(SymbolTable *table, char *name) {
    if (table == NULL || name == NULL) {
        fprintf(stderr, "Error: Invalid parameters\n");
        return NULL;
    }

    SymbolTableNode *current = table->head;
    while (current != NULL) {
        if (strcmp(current->data->symbolName, name) == 0) {
            return current->data;
        }
        current = current->next;
    }

    // If the symbol is not found in the current table, check in the parent
    if (table->parent != NULL) {
        return getSymbolData(table->parent, name);
    }

    fprintf(stderr, "Error: Symbol '%s' not found\n", name);
    return NULL;
}

// Function to get the node of a symbol table
SymbolTableNode *getSymbolTableNode(SymbolTable *table, char *name){
    if (table == NULL || name == NULL) {
        fprintf(stderr, "Error: Invalid parameters\n");
        return NULL;
    }

    SymbolTableNode *current = table->head;
    while (current != NULL) {
        if (strcmp(current->data->symbolName, name) == 0) {
            return current;
        }
        current = current->next;
    }

    // If the symbol is not found in the current table, check in the parent
    if (table->parent != NULL) {
        return getSymbolTableNode(table->parent, name);
    }

    fprintf(stderr, "Error: Symbol '%s' not found\n", name);
    return NULL;
}