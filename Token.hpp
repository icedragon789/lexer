
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
    ostream& print(ostream& os) const; // neatly print all members
    void incrCount() { refCount++; };
    string getTName() { return tokenName; } // return string class member
    void setTName(string tName) { tokenName  = tName; }
};

// Operator overload to call print statement for column object
inline ostream& operator <<( ostream& os, Token& myTk) {
    return myTk.print(os);
}


#endif //LEXER_TOKEN_HPP
