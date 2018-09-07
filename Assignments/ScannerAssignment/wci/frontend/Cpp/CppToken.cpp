/**
 * <h1>CppToken</h1>
 *
 * <p>Base class for Cpp token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "CppToken.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;

map<string, CppTokenType> CppToken::RESERVED_WORDS;
map<string, CppTokenType> CppToken::SPECIAL_SYMBOLS;
map<CppTokenType, string> CppToken::SPECIAL_SYMBOL_NAMES;

bool CppToken::INITIALIZED = false;

void CppToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
        "AND", "ARRAY", "BEGIN", "CASE", "CONST", "DIV", "DO", "DOWNTO",
        "ELSE", "END", "FILE", "FOR", "FUNCTION", "GOTO", "IF", "IN",
        "LABEL", "MOD", "NIL", "NOT", "OF", "OR", "PACKED", "PROCEDURE",
        "PROGRAM", "RECORD", "REPEAT", "SET", "THEN", "TO", "TYPE",
        "UNTIL", "VAR", "WHILE", "WITH"
    };

    vector<CppTokenType> rw_keys =
    {
        CppTokenType::AND,
        CppTokenType::ARRAY,
        CppTokenType::BEGIN,
        CppTokenType::CASE,
        CppTokenType::CONST,
        CppTokenType::DIV,
        CppTokenType::DO,
        CppTokenType::DOWNTO,

        CppTokenType::ELSE,
        CppTokenType::END,
        CppTokenType::FILE,
        CppTokenType::FOR,
        CppTokenType::FUNCTION,
        CppTokenType::GOTO,
        CppTokenType::IF,
        CppTokenType::IN,

        CppTokenType::LABEL,
        CppTokenType::MOD,
        CppTokenType::NIL,
        CppTokenType::NOT,
        CppTokenType::OF,
        CppTokenType::OR,
        CppTokenType::PACKED,
        CppTokenType::PROCEDURE,

        CppTokenType::PROGRAM,
        CppTokenType::RECORD,
        CppTokenType::REPEAT,
        CppTokenType::SET,
        CppTokenType::THEN,
        CppTokenType::TO,
        CppTokenType::TYPE,

        CppTokenType::UNTIL,
        CppTokenType::VAR,
        CppTokenType::WHILE,
        CppTokenType::WITH
    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
        "+", "-", "*", "/", ":=", ".", ",", ";", ":", "'", "=", "<>",
        "<", "<=", ">=", ">", "(", ")", "[", "]", "{", "}",  "^", ".."
    };

    vector<CppTokenType> ss_keys =
    {
        CppTokenType::PLUS,
        CppTokenType::MINUS,
        CppTokenType::STAR,
        CppTokenType::SLASH,
        CppTokenType::COLON_EQUALS,
        CppTokenType::DOT,
        CppTokenType::COMMA,
        CppTokenType::SEMICOLON,
        CppTokenType::COLON,
        CppTokenType::QUOTE,
        CppTokenType::EQUALS,
        CppTokenType::NOT_EQUALS,

        CppTokenType::LESS_THAN,
        CppTokenType::LESS_EQUALS,
        CppTokenType::GREATER_EQUALS,
        CppTokenType::GREATER_THAN,
        CppTokenType::LEFT_PAREN,
        CppTokenType::RIGHT_PAREN,
        CppTokenType::LEFT_BRACKET,
        CppTokenType::RIGHT_BRACKET,
        CppTokenType::LEFT_BRACE,
        CppTokenType::RIGHT_BRACE,
        CppTokenType::UP_ARROW,
        CppTokenType::DOT_DOT
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
        "PLUS", "MINUS", "STAR", "SLASH", "COLON_EQUALS", "DOT", "COMMA",
        "SEMICOLON", "COLON", "QUOTE", "EQUALS", "NOT_EQUALS",

        "LESS_THAN", "LESS_EQUALS", "GREATER_EQUALS", "GREATER_THAN",
        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
        "LEFT_BRACE", "RIGHT_BRACE", "UP_ARROW", "DOT_DOT"
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

CppToken::CppToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::Cpp
