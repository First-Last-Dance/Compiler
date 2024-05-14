@echo off
flex project.l
bison -dy project.y
gcc SymbolTable.c lex.yy.c y.tab.c -o project.exe