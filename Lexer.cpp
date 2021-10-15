
// CSCI 4536 - Dr Alice Fischer
// Class to create a lexer in FORTH code
// Created by Ben Placzek on 10/14/2021.

#include <sys/fcntl.h>
#include "Lexer.hpp"

Lexer::Lexer(string iFile) {

//    cout << "Constructor" << endl;
    inputFile.open(iFile); // open the file inputted as parameter

    outputFile.open("../ForthOutput.txt");
    if (outputFile)
    {
        outputFile << NAME << " " << "Lab 3: Lexer for FORTH Written in C++ " << CLASS <<
                   " Lexing file: " << iFile << "\n" << "Comments:";
    }
    else cout << "Unable to open file";

    state = start; // initialize starting state
    tokenCharacters = ""; // initialized to empty
}

Lexer::~Lexer() {
//    cout << "Destructor" << endl;
    inputFile.close();
    outputFile.close();
}

void Lexer::doLex() {

    while(inputFile >> noskipws >> currentInput) {
        putchar(currentInput);

        switch(state) {
            case start:
                doStart(); // break out if whitespace character is first character
                break;
            case slashPending:
                if(currentInput==' ') state = acquiringSlash;
                else {
                    state = acquiringToken;
                    break;
                }
            case acquiringSlash:

            case parenPending:

            case acquiringParen:

            case acquiringToken:

            case acquiringString:

            default:
                break;

        }

    }
}

void Lexer::print() {
    // print map to output file
    outputFile << "Map lol" << endl;
}

// false: first character is not whitespace
// true: first character is whitespace
int Lexer::doStart() {
    if(currentInput == ' ' ) return 0;  // if current char is whitespace, break from the switch
    else if (currentInput == '\\') {    // else if currentChar is a backslash, set state to slashPending and break
        state = slashPending;
    }
    else if(currentInput=='(') {        // else if currentChar is (, set state to parenPending and break
        state = parenPending;
    }
    else { // else you have a token that belongs in the symbol table, change state variable
        state = acquiringToken;
        tokenCharacters += currentInput;  // add current character to token string
    }


    return 0;
}

void Lexer::doToken(string name, TokenType tt) {
    // search tokenmap for tokens name



}
