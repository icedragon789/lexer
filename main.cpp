
// CSCI 4536 - Dr Alice Fischer
// The purpose of this program is to read FORTH code and
// output to a file containing a symbol table
// Created by Ben Placzek on 10/14/2021.

#include "Token.hpp"
#include "Lexer.hpp"

#define INF "../ForthInput.txt"

int main() {

//    TokenType2 mytype;

//    string myInput;
//
//    cin >> myInput;
//
//    if(myInput == "stop") mytype = STOP;
//    if(myInput == "start") mytype = START;
//    if(myInput == "continue") mytype = CONTINUE;
//
//     mytype = STOP;
//
//     cout << mytype << endl;

    vector<int> myVec;
    myVec.push_back(2);
    myVec.push_back(6);
    myVec.push_back(7);
    myVec.push_back(9);
    myVec.push_back(9);
    myVec.push_back(9);
    myVec.push_back(9);
    myVec.push_back(9);

    for(int j =0; j<myVec.size(); j++) cout << myVec[j] << endl;

    // ----------------------

    cout << "------------------" << endl;

    int myArray[100];
    int count = 0;

    myArray[count] = 2;
    count++;
    myArray[count] = 6;
    count++;
    myArray[count] = 7;

    for(int j =0; j<count+1; j++) cout << myArray[j] << endl;



    return 0;

}
