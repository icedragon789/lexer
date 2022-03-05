
// CSCI 4536 - Dr Alice Fischer
// Class to create a lexer in FORTH code
// Created by Ben Placzek on 10/14/2021.

#include "Lexer.hpp"

#define OUTF "../ForthOutput.txt"

Lexer::Lexer(string iFile) {

//    cout << "Constructor" << endl;
    inputFile.open(iFile); // open the file inputted as parameter

    outputFile.open(OUTF, ios::out | ios::trunc);
    if (outputFile)
    {
        outputFile << NAME << " | " << "Lab 3: Lexer for FORTH Written in C++ " << CLASS <<
                   " | Lexing file: " << iFile << "\nComments:\n";
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

    while(!inputFile.eof()) {
        inputFile >> noskipws >> currentInput;
        switch(state) {
            case start: {
                doStart(); // break out if whitespace character is first character
                break;
            }
            case slashPending: { // a slash was detected
                if (currentInput == ' ') {
                    state = acquiringSlash;
                }
                else {
                    state = acquiringToken;
                    break;
                }
            }
            case acquiringSlash: {//whole line comment found
                while (currentInput != '\n') { // loop until )
                    inputFile >> noskipws >> currentInput;
                    if (currentInput != '\n') outputFile << currentInput;
                }
                state = start;
                break;
            }
            case parenPending: {
                if (currentInput == ' ') state = acquiringParen;
                else state = acquiringToken;
            }
            case acquiringParen: {// partial line comment found
                while (currentInput != ')' ) { // loop until )
                    inputFile >> noskipws >> currentInput;
                    if (currentInput != ')' ) {
                        outputFile << currentInput;
                    }
                }
                outputFile << "\n";
                state = start;
                break;
                }
            case acquiringToken: {// read until reach whitespace
                while (currentInput != ' ' && currentInput != '\n') { // loop until whitespace or newline
                    if(currentInput != ' ' && currentInput != '\n') tokenCharacters += currentInput;
                    inputFile >> noskipws >> currentInput;
                }

                // if characters in the token are all digits
                bool allDigits = true;
                for (int j = 0; j < tokenCharacters.length(); j++) {
                    if (!isdigit(tokenCharacters[j])) allDigits = false;
                }
                if(allDigits) {
                    // at this point, the FORTH lexer actually converts string -> binary
                    doToken(tokenCharacters, number);
                    state = start;
                }
                // if the token is ."
                else if(tokenCharacters == ".\"") {
                    doToken(tokenCharacters, word);
                    state = acquiringString;
                }
                // otherwise situation
                else {
                    doToken(tokenCharacters, word);
                    state = start;
                }

                break;
            }
            case acquiringString: {
                while (currentInput != '\"') { // loop until "
                    inputFile >> noskipws >> currentInput;
                    tokenCharacters += currentInput;
                    if (currentInput != '\"') outputFile << currentInput;
                }
                doToken(tokenCharacters, strings);
                state = start;
                break;
            }

        }
    }
    print();

}

void Lexer::print() {
    map<string, Token>::iterator itr;
    // print map to output file
    outputFile << "-----------------------------------------------------" << endl;
    outputFile << "Name" << setw(20) << "Type" << setw(20) << "Count\n";

    cout << "-----------------------------------------------------" << endl;
    cout << "Name" << setw(20) << "Type" << setw(20) << "Count\n";

    for (itr = lexMap.begin(); itr != lexMap.end(); ++itr) {
        outputFile << itr->second;
        cout << itr->second;
    }
}

// false: first character is not whitespace
// true: first character is whitespace
void Lexer::doStart() {
    if(currentInput == ' ' ) { }   // if current char is whitespace, break from the switch
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

}

void Lexer::doToken(string name, TokenType tt) {
    // search tokenmap for tokens name
    bool exists = false;
    map<string, Token>::iterator itr;
    for (itr = lexMap.begin(); itr != lexMap.end(); ++itr) {
        if(itr->first == name) {
            // increment the token at name's counter
            itr->second.incrCount();
            exists = true;
        }
    }
    if(!exists) {
        // if it doesnt exist yet, insert name and tokentype
        Token temporary(name, tt);

        lexMap.insert(pair<string, Token>(name, temporary));
    }
    tokenCharacters = ""; // set token string to empty
}
