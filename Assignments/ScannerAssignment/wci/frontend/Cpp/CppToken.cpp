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
        "auto", "double", "int", "struct", "break", "else", "long", "switch",
        "case", "enum", "namespace", "template", "char", "extern", "operator", "this",
        "class", "float", "package", "throw", "const", "for", "public", "union",
        "continue", "goto", "return", "void", "do", "if", "static",
        "while"
    };

    vector<CppTokenType> rw_keys =
    {
        CppTokenType::AUTO,
        CppTokenType::BREAK,
        CppTokenType::CASE,
        CppTokenType::CHAR,
        CppTokenType::CLASS,
        CppTokenType::CONST,
        CppTokenType::CONTINUE,
        CppTokenType::DO,

        CppTokenType::DOUBLE,
        CppTokenType::ELSE,
        CppTokenType::ENUM,
        CppTokenType::EXTERN,
        CppTokenType::FLOAT,
        CppTokenType::FOR,
        CppTokenType::GOTO,
        CppTokenType::IF,

        CppTokenType::INT,
        CppTokenType::LONG,
        CppTokenType::NAMESPACE,
        CppTokenType::OPERATOR,
        CppTokenType::PROTECTED,
        CppTokenType::PUBLIC,
        CppTokenType::RETURN,
        CppTokenType::STATIC,

        CppTokenType::STRUCT,
        CppTokenType::SWITCH,
        CppTokenType::TEMPLATE,
        CppTokenType::THIS,
        CppTokenType::THROW,
        CppTokenType::UNION,
        CppTokenType::VOID,

        CppTokenType::WHILE
        // CppTokenType::VAR,
        // CppTokenType::WHILE,  Pascal reserved words
        // CppTokenType::WITH
    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
        "~", "!", "@", "%", "^", "&", "*", "-", "+", "=", "|", "/",
        ":", ";", "?", "<", ">", ".", ",", "'", "\"", "(",  ")", "[",
        "]", "{", "}", "++", "--", "<<", ">>", "<=", ">=", "+=", "-=",
        "*=", "/=", "==", "|=", "%=", "&=", "^=", "!=", "<<=", ">>=",
        "||", "&&", "//", "/*", "*/"
    };

    vector<CppTokenType> ss_keys =
    {
        CppTokenType::TILDA,
        CppTokenType::EXCLAMATION,
        CppTokenType::AT,
        CppTokenType::PERCENT,
        CppTokenType::CARROT,
        CppTokenType::AMPERSAND,
        CppTokenType::STAR,
        CppTokenType::MINUS,
        CppTokenType::PLUS,
        CppTokenType::EQUALS,
		CppTokenType::BITWISEOR, //added in
        CppTokenType::SLASH,

        CppTokenType::COLON,
        CppTokenType::SEMICOLON,
        CppTokenType::QUESTIONMARK,
        CppTokenType::LESS_THAN,
        CppTokenType::GREATER_THAN,
        CppTokenType::DOT,
        CppTokenType::COMMA,
        CppTokenType::SINGLE_QUOTE,
        CppTokenType::DOUBLE_QUOTE,
        CppTokenType::LEFT_PAREN,
        CppTokenType::RIGHT_PAREN,
        CppTokenType::LEFT_SQ_BRACKET,

        CppTokenType::RIGHT_SQ_BRACKET,
        CppTokenType::LEFT_BRACKET,
        CppTokenType::RIGHT_BRACKET,
        CppTokenType::PLUS_PLUS,
        CppTokenType::MINUS_MINUS,
        CppTokenType::LEFT_SHIFT,
        CppTokenType::RIGHT_SHIFT,
        CppTokenType::LESS_THAN_EQUALS,
        CppTokenType::GREATER_THAN_EQUALS,
        CppTokenType::PLUS_EQUALS,
        CppTokenType::MINUS_EQUALS,

        CppTokenType::STAR_EQUALS,
        CppTokenType::SLASH_EQUALS,
        CppTokenType::EQUALS_EQUALS,
        CppTokenType::OR_EQUALS,
        CppTokenType::PERCENT_EQUALS,
        CppTokenType::AND_EQUALS,
        CppTokenType::CARROT_EQUALS,
        CppTokenType::EXCLAMATION_EQUALS,
        CppTokenType::LEFT_SHIFT_EQUALS,
        CppTokenType::RIGHT_SHIFT_EQUALS,

        CppTokenType::OR_OR,
        CppTokenType::AND_AND,
        CppTokenType::SLASH_SLASH,
        CppTokenType::SLASH_STAR,
        CppTokenType::STAR_SLASH
        
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
        "TILDA", "EXCLAMATION", "AT", "PERCENT", "CARROT", "AMPERSAND", "STAR",
        "MINUS", "PLUS", "EQUALS", "BITWISEOR", "SLASH",

		"COLON", "SEMICOLON", "QUESTIONMARK", "LESS_THAN", "GREATER_THAN", "DOT",
        "COMMA", "SINGLE_QUOTE", "DOUBLE_QUOTE", "LEFT_PAREN",
        "RIGHT_PAREN", "LEFT_SQ_BRACKET",

		"RIGHT_SQ_BRACKET", "LEFT_BRACKET", "RIGHT_BRACKET", "PLUS_PLUS", "MINUS_MINUS",
		"LEFT_SHIFT", "RIGHT_SHIFT", "LESS_THAN_EQUALS", "GREATER_THAN_EQUALS",
        "PLUS_EQUALS", "MINUS_EQUALS",

		"STAR_EQUALS", "SLASH_EQUALS", "EQUALS_EQUALS", "OR_EQUALS", "PERCENT_EQUALS",
		"AND_EQUALS", "CARROT_EQUALS", "EXCLAMATION_EQUALS", "LEFT_SHIFT_EQUALS",
        "RIGHT_SHIFT_EQUALS", "OR_OR", "AND_AND", "SLASH_SLASH",
        "SLASH_STAR", "STAR_SLASH"
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
 
