// Author: Carter Roberts
// Institution: Loyola University New Orleans
// Instructor: Dr. Omar EL Khatib
// Filename: globals.cpp
// Description: global variables for tokenizer function for language implementation
// Date Created (MM/DD/YYYY): 9/8/2025
// Date Modified (MM/DD/YYYY): 9/10/2025

#include <iostream>
using namespace std;

enum Tokens {INT_LIT, INT_KEYWORD, DECL, VAR, ASSIGN_OP, ADD_OP, SUB_OP, MUL_OP, DIV_OP,
LEFT_PAREN, RIGHT_PAREN, LETTER, DIGIT, COMMA, UNKNOWN, ENDFILE};
const int MAX_SIZE = 100; // maximum size per line
string lexeme = ""; // current lexeme
Tokens nextToken;
int errors = 0; // keep track of number of errors
int line = 1; // keep track of current line reached

// errMsg - function to display the error message with line number of error detected.
void errMsg (string msg) {
    cout << "Error at line: " << line << ": " << msg << endl;
    errors++;
    lex();
}