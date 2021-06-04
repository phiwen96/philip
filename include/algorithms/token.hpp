#pragma once
#include "common.hpp"
#include "lexeme.hpp"
#include <unordered_map>

#define IDENTIFIER \
    X (TOKEN_AND, "and") \
    X (TOKEN_CLASS, "class") \
    X (TOKEN_ELSE, "else") \
    X (TOKEN_FALSE, "false") \
    X (TOKEN_FOR, "for") \
    X (TOKEN_FUN, "fun") \
    X (TOKEN_IF, "if") \
    X (TOKEN_NIL, "nil") \
    X (TOKEN_OR, "or") \
    X (TOKEN_PRINT, "print") \
    X (TOKEN_RETURN, "return") \
    X (TOKEN_SUPER, "super") \
    X (TOKEN_THIS, "this") \
    X (TOKEN_TRUE, "true") \
    X (TOKEN_VAR, "var") \
    X (TOKEN_WHILE, "while")


/// lkml
#define TOKEN \
    X (TOKEN_COLON) \
    X (TOKEN_WHITESPACE) \
    X (TOKEN_LEFT_PAREN, '(') \
    X (TOKEN_RIGHT_PAREN, ')') \
    X (TOKEN_LEFT_BRACE, '{') \
    X (TOKEN_RIGHT_BRACE, '}') \
    X (TOKEN_LEFT_BRACKET, '[') \
    X (TOKEN_RIGHT_BRACKET, ']') \
    X (TOKEN_COMMA, ',') \
    X (TOKEN_DOT, ',') \
    X (TOKEN_MINUS, '-') \
    X (TOKEN_PLUS, '+') \
    X (TOKEN_SEMICOLON, ';') \
    X (TOKEN_SLASH, '/') \
    X (TOKEN_STAR, '*') \
    X (TOKEN_BANG, '!') \
    X (TOKEN_BANG_EQUAL, '!', '=') \
    X (TOKEN_EQUAL, '=') \
    X (TOKEN_EQUAL_EQUAL, '=', '=') \
    X (TOKEN_GREATER) \
    X (TOKEN_GREATER_EQUAL) \
    X (TOKEN_LESS) \
    X (TOKEN_LESS_EQUAL) \
    X (TOKEN_IDENTIFIER) \
    X (TOKEN_STRING) \
    X (TOKEN_NUMBER, double value = strtod (parser.previous.start, NULL); emitConstant(value);) \
    X (TOKEN_ERROR) \
    X (TOKEN_EOF) \
    IDENTIFIER


    




enum
{
#define X(x, ...) \
x,
    TOKEN
#undef X
};

template <typename Lexeme>
struct toki
{
    using lexeme_type = Lexeme;
    

    int type;
    lexeme_type lexeme;
    int line {0};
    
    static inline std::unordered_map <std::string, decltype (type)> const identifiers =
    {
#define X(name, str) \
    {str, name},
    IDENTIFIER
#undef X
    };
};

