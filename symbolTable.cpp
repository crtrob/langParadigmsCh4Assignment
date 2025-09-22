// Author: Carter Roberts
// Institution: Loyola University New Orleans
// Instructor: Dr. Omar EL Khatib
// Filename: symbolTable.cpp
// Description: symbol table for parser function for language implementation
// Date Created (MM/DD/YYYY): 9/10/2025
// Date Modified (MM/DD/YYYY): 9/22/2025

#include <iostream>
using namespace std;

struct item {
    string name; // to store variable name
    int intValue; // to store value
} symbolTable[100];
int dindex = 0; // index to top of symbol table

void add_symbol(string name, int value) {
    symbolTable[dindex].name = name;
    symbolTable[dindex].intValue = value;
    dindex++;
}

void prt_symbol() {
    cout << "Symbol table:";
    cout << "Name\tValue\n";
    for (int i=0; i<dindex; i++) {
        cout << symbolTable[i].name << "\t" << symbolTable[i].intValue << endl;
    }
}

bool search_symbol (string lexeme) {
    for (int i=0; i<dindex; i++)
        if (symbolTable[i].name == lexeme) return true;
    return false;
}