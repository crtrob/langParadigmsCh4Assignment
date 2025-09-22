// Author: Carter Roberts
// Institution: Loyola University New Orleans
// Instructor: Dr. Omar EL Khatib
// Filename: q2Globals.cpp
// Description: global variables for 2nd tokenizer function for language implementation
// Date Created (MM/DD/YYYY): 9/22/2025
// Date Modified (MM/DD/YYYY): 9/22/2025

#include <iostream>
using namespace std;

enum Tokens {A, B, C, a, b, c, UNKNOWN, ENDFILE};
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