// Author: Carter Roberts
// Institution: Loyola University New Orleans
// Instructor: Dr. Omar EL Khatib
// Filename: q2Tokenizer.cpp
// Description: most actual parts of 2nd tokenizer function for language implementation
// Date Created (MM/DD/YYYY): 9/17/2025
// Date Modified (MM/DD/YYYY): 9/22/2025

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void lex();
#include "q2Globals.cpp"
#include "q2Parser.cpp"

ifstream infp;
char nextChar = ' '; // next character to read

// return a single character from a file
char getChar() {
    char c = infp.get();
    if (c == '\n') line++;
    return c;
}

// skip spaces and return first non-space character from the file
char getNonSpaceChar() {
    char c = ' ';
    while (isspace(c)) {
        c = getChar();
    }
    return c;
}

// add character to the lexeme string
void addChar(char c) {
    lexeme = lexeme + c;
    if (lexeme.length() > MAX_SIZE - 1) {
        cout << "ERROR: lexeme too long... \n";
        errors++;
    }
}

// lookup determine if lexeme is a keyword or Var
Tokens lookupLetter(string lexeme) {
    Tokens t;
    if (lexeme == "A") t = A;
    else if (lexeme == "B") t = B;
    else if (lexeme == "C") t = C;
    else if (lexeme == "a") t = a;
    else if (lexeme == "b") t = b;
    else if (lexeme == "c") t = c;
    else t = UNKNOWN;
    return t;
}

void prt(Tokens nt) {
    switch (nt) {
        case A: cout << "<A>"; break;
        case B: cout << "<B>"; break;
        case C: cout << "<C>"; break;
        // terminals
        case a: cout << "(terminal) a"; break;
        case b: cout << "(terminal) b"; break;
        case c: cout << "(terminal) c"; break;
        case ENDFILE: cout << "<ENDFILE>"; break;
        case UNKNOWN: cout << "Unknow "; break;
    }
}

void lex() {
    lexeme = "";
    if (isspace(nextChar)) nextChar = getNonSpaceChar();
    if (isalpha(nextChar)) {
        addChar(nextChar);
        nextChar = getChar();
        nextToken = lookupLetter(lexeme);
    }
    else if (nextChar == EOF) nextToken = ENDFILE;
    else nextToken = UNKNOWN;

    cout << "Next token is: "; prt (nextToken); cout << " Next lexeme is " << lexeme << endl;
}

int main() {
    string filename;
    filename = "prg3.in";
    infp.open(filename);

    if (!infp) {
        cout << "ERROR - cannot open " << filename << endl;
        errors++;
        return 0;
    }

    string str;
    if (nextToken != ENDFILE) bigA();
    cout << "Total number of errors: " << errors << endl;
    
    return 0;
}