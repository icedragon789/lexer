
// CSCI 4536 - Dr Alice Fischer
// Class to define a token in FORTH code
// Created by Ben Placzek on 10/14/2021.

#include "Token.hpp"

Token::Token(string tName, TokenType mType) {
    tokenName = tName;
    myType = mType;
    refCount = 1;
}

// print all members
ofstream &Token::print(ofstream &os) const {
    os << tokenName << " " << myType << " " << refCount << "\n";
}



