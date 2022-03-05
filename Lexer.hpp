
// CSCI 4536 - Dr Alice Fischer
// Class to create a lexer in FORTH code
// Created by Ben Placzek on 10/14/2021.

#ifndef LEXER_LEXER_HPP
#define LEXER_LEXER_HPP

#include "tools.hpp"
#include "enums.hpp"
#include "Token.hpp"

class Lexer {
private:
    StateType state; // initialized to start
    ifstream inputFile;
    ofstream outputFile;
    map<string, Token> lexMap;
    char currentInput;
    string tokenCharacters; // initialized to empty
    TokenType currentToken;

public:
    Lexer(string iFile); // takes name of input file and open I/O streams
    ~Lexer(); // closes files
    void doLex(); // do a lex
    void print(); // print contents of the map to an output file in a readable format
    void doToken(string name, TokenType tt); // helper function when a token is identified
    void doStart(); // helper function
};


#endif //LEXER_LEXER_HPP
