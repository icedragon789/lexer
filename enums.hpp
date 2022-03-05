
// CSCI 4536 - Dr Alice Fischer
// Created by Ben Placzek on 10/14/2021.

#ifndef LEXER_ENUMS_HPP
#define LEXER_ENUMS_HPP

enum TokenType{word,number,strings};
enum StateType{start, slashPending, acquiringSlash,
        parenPending, acquiringParen, acquiringToken,
        acquiringString};


#endif //LEXER_ENUMS_HPP
