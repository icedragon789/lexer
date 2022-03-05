
// CSCI 4536 - Dr Alice Fischer
// The purpose of this program is to read FORTH code and
// output to a file containing a symbol table
// Created by Ben Placzek on 10/14/2021.

#include "Token.hpp"
#include "Lexer.hpp"

#define INF "../ForthInput.txt"

int main() {

    Lexer mylex(INF);
    mylex.doLex();

    return 0;

}
