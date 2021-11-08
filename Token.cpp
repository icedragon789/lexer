
// CSCI 4536 - Dr Alice Fischer
// Class to define a token in FORTH code
// Created by Ben Placzek on 10/14/2021.

#include "Token.hpp"

const string myTokens[3] = {"word   ","number  ","strings"};

Token::Token(string tName, TokenType mType) {
    tokenName = tName;
    myType = mType;
    refCount = 1;
}

// print all members
ostream &Token::print(ostream &os) const {
    os << tokenName << setw(20) << myTokens[myType] << setw(20) << refCount << "\n";
    return os;
}



