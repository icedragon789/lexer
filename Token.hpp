
// CSCI 4536 - Dr Alice Fischer
// Class to define a token in FORTH code
// Created by Ben Placzek on 10/14/2021.

#ifndef LEXER_TOKEN_HPP
#define LEXER_TOKEN_HPP

#include "tools.hpp"
#include "enums.hpp"

class Token {
private:
    string tokenName;
    TokenType myType;
    int refCount;

public:
    Token(string tName, TokenType mType); // initialize all three members
    ofstream& print(ofstream& os) const; // neatly print all members
    void incrCount() { refCount++; };
};

// Operator overload to call print statement for column object
inline ofstream& operator <<( ofstream& os, Token& myTk) {
    return myTk.print(os);
}


#endif //LEXER_TOKEN_HPP
