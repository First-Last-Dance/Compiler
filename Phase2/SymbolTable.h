#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SymbolTable SymbolTable;

typedef struct SymbolTableData {
  int symbolType;
  int symbolInitLine;
  bool symbolInitialized;
  int *symbolUsedLines;
  int symbolBlock;
  char *symbolValue;
  char *symbolName;
  int symbolUsedLinesCount;
  SymbolTable *table;
  //   permission symPerm;

} SymbolTableData;

typedef struct SymbolTableNode {
  struct SymbolTableData *data;
  struct SymbolTableNode *next;
} SymbolTableNode;

typedef struct SymbolTable {
  SymbolTableNode *head;
  int blockLevel;
  SymbolTable **children;
  SymbolTable *parent;
} SymbolTable;

SymbolTable *createSymbolTable();
void insertFirst(SymbolTable *table, SymbolTableNode *data); //check if name is unique in scope (this symbol table)
void deleteFirst(SymbolTable *table);
SymbolTable *createChild(SymbolTable *table); // returns the child
SymbolTable * deleteChild(SymbolTable *table); // returns the parent
SymbolTable *getParent(SymbolTable *table);
void printList(SymbolTable *table);
void setValue(SymbolTable *table, char *name, char *value, int lineIndex); //also set initialized and init line
void addUsedLine(SymbolTable *table, char *name, int line);
void freeSymbolTable(SymbolTable *table) ;
SymbolTableData *getSymbolData(SymbolTable *table, char *name);
SymbolTableNode *getSymbolTableNode(SymbolTable *table, char *name);

// void setValueByNode(char *value, int lineIndex); //also set initialized and init line


  // struct SymbolTableData *getSymTableData(int type, int init, int used, int
  // brace,
  //                                         char *name);
  // void insert(int index, struct SymbolTableData *data);
  // struct SymbolTableNode *deleteFirst();
  // int length();
  // bool isEmpty();
  // struct SymbolTableData *find(int index);
  // void printList();
  // void setValue(int index, char *value);
  // void setBrace(int findBrace);
  // void setUsed(int findIndex);
  // void setInit(int findIndex);
  // void printUsed(FILE *f);
  // void printNotUsed(FILE *f);
  // void printInit(FILE *f);
  // void printNotInit(FILE *f);
  // bool nameUniqueInScope(char *name, int brace);
  // int getIndex(char *name, int brace);

#endif // SYMBOL_TABLE_H

