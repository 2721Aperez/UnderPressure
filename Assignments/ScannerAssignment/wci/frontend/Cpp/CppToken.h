/**
 * <h1>CppToken</h1>
 *
 * <p>Base class for Cpp token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_CPP_CPPTOKEN_H_
#define WCI_FRONTEND_CPP_CPPTOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace Cpp {
    
    using namespace std;
    using namespace wci::frontend;
    
    /**
     * Cpp token types.
     */
    enum class CppTokenType
    {
        // Reserved words.
         AUTO, BREAK, CASE, CHAR, CLASS, CONST, CONTINUE, DO, DOUBLE,
         ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF, INT, LONG, NAMESPACE,
         OPERATOR, PROTECTED, PUBLIC, RETURN, STATIC, STRUCT, SWITCH,
         TEMPLATE, THIS, THROW, UNION, VOID, WHILE,
         
         // Special symbols.
         TILDA, EXCLAMATION, AT, PERCENT, CARROT, AMPERSAND,
         STAR, MINUS, PLUS, EQUALS, SLASH, COLON, SEMICOLON,
         QUESTIONMARK, LESS_THAN, GREATER_THAN, DOT, COMMA,
         SINGLE_QUOTE, DOUBLE_QUOTE, LEFT_PAREN, RIGHT_PAREN,
         LEFT_SQ_BRACKET, RIGHT_SQ_BRACKET, LEFT_BRACKET,
         RIGHT_BRACKET, PLUS_PLUS, MINUS_MINUS, LEFT_SHIFT,
         RIGHT_SHIFT, LESS_THAN_EQUALS, GREATER_THAN_EQUALS,
         PLUS_EQUALS, MINUS_EQUALS, STAR_EQUALS, SLASH_EQUALS,
         EQUALS_EQUALS, OR_EQUALS, PERCENT_EQUALS, AND_EQUALS,
         CARROT_EQUALS, EXCLAMATION_EQUALS, LEFT_SHIFT_EQUALS,
         RIGHT_SHIFT_EQUALS, OR_OR, AND_AND, SLASH_SLASH,
         SLASH_STAR, STAR_SLASH,

         INDENTIFIER, STRING, INTEGER, REAL, ERROR, 
         END_OF_FILE
         };
         
         constexpr CppTokenType CppT_AUTO = CppTokenType::AUTO;
         constexpr CppTokenType CppT_BREAK = CppTokenType::BREAK;
         constexpr CppTokenType CppT_CASE = CppTokenType::CASE;
         constexpr CppTokenType CppT_CHAR = CppTokenType::CHAR;
         constexpr CppTokenType CppT_CLASS = CppTokenType::CLASS;
         constexpr CppTokenType CppT_CONST = CppTokenType::CONST;
         constexpr CppTokenType CppT_CONTINUE = CppTokenType::CONTINUE;
         constexpr CppTokenType CppT_DO = CppTokenType::DO;
         
         constexpr CppTokenType CppT_ELSE = CppTokenType::DOUBLE;
         constexpr CppTokenType CppT_END = CppTokenType::ELSE;
         constexpr CppTokenType CppT_FILE = CppTokenType::ENUM;
         constexpr CppTokenType CppT_FOR = CppTokenType::EXTERN;
         constexpr CppTokenType CppT_FUNCTION = CppTokenType::FLOAT;
         constexpr CppTokenType CppT_GOTO = CppTokenType::FOR;
         constexpr CppTokenType CppT_IF = CppTokenType::GOTO;
         constexpr CppTokenType CppT_IN = CppTokenType::IF;
         
         constexpr CppTokenType CppT_LABEL = CppTokenType::INT;
         constexpr CppTokenType CppT_MOD = CppTokenType::LONG;
         constexpr CppTokenType CppT_NIL = CppTokenType::NAMESPACE;
         constexpr CppTokenType CppT_NOT = CppTokenType::OPERATOR;
         constexpr CppTokenType CppT_OF = CppTokenType::PROTECTED;
         constexpr CppTokenType CppT_OR = CppTokenType::PUBLIC;
         constexpr CppTokenType CppT_PACKED = CppTokenType::RETURN;
         constexpr CppTokenType CppT_PROCEDURE = CppTokenType::STATIC;
         
         constexpr CppTokenType CppT_PROGRAM = CppTokenType::STRUCT;
         constexpr CppTokenType CppT_RECORD = CppTokenType::SWITCH;
         constexpr CppTokenType CppT_REPEAT = CppTokenType::TEMPLATE;
         constexpr CppTokenType CppT_SET = CppTokenType::THIS;
         constexpr CppTokenType CppT_THEN = CppTokenType::THROW;
         constexpr CppTokenType CppT_TO = CppTokenType::UNION;
         constexpr CppTokenType CppT_TYPE = CppTokenType::VOID;
         
         constexpr CppTokenType CppT_WHILE = CppTokenType::WHILE;
         
         constexpr CppTokenType CppT_PLUS = CppTokenType::TILDA;
         constexpr CppTokenType CppT_MINUS = CppTokenType::EXCLAMATION;
         constexpr CppTokenType CppT_STAR = CppTokenType::AT;
         constexpr CppTokenType CppT_SLASH = CppTokenType::PERCENT;
         constexpr CppTokenType CppT_COLON_EQUALS = CppTokenType::CARROT;
         constexpr CppTokenType CppT_DOT = CppTokenType::AMPERSAND;
         constexpr CppTokenType CppT_COMMA = CppTokenType::STAR;
         constexpr CppTokenType CppT_SEMICOLON = CppTokenType::MINUS;
         constexpr CppTokenType CppT_COLON = CppTokenType::PLUS;
         constexpr CppTokenType CppT_QUOTE = CppTokenType::EQUALS;
         constexpr CppTokenType CppT_EQUALS = CppTokenType::SLASH;
         constexpr CppTokenType CppT_NOT_EQUALS = CppTokenType::COLON;
         
         constexpr CppTokenType CppT_LESS_THAN = CppTokenType::SEMICOLON;
         constexpr CppTokenType CppT_LESS_EQUALS = CppTokenType::QUESTIONMARK;
         constexpr CppTokenType CppT_GREATER_EQUALS = CppTokenType::LESS_THAN;
         constexpr CppTokenType CppT_GREATER_THAN = CppTokenType::GREATER_THAN;
         constexpr CppTokenType CppT_LEFT_PAREN = CppTokenType::DOT;
         constexpr CppTokenType CppT_RIGHT_PAREN = CppTokenType::COMMA;
         constexpr CppTokenType CppT_LEFT_BRACKET = CppTokenType::SINGLE_QUOTE;
         constexpr CppTokenType CppT_RIGHT_BRACKET = CppTokenType::DOUBLE_QUOTE;
         constexpr CppTokenType CppT_LEFT_BRACE = CppTokenType::LEFT_PAREN;
         constexpr CppTokenType CppT_RIGHT_BRACE = CppTokenType::RIGHT_PAREN;
         constexpr CppTokenType CppT_UP_ARROW = CppTokenType::LEFT_SQ_BRACKET;
         constexpr CppTokenType CppT_DOT_DOT = CppTokenType::RIGHT_SQ_BRACKET;
         
         constexpr CppTokenType CppT_LESS_THAN = CppTokenType::LEFT_BRACKET;
         constexpr CppTokenType CppT_LESS_EQUALS = CppTokenType::RIGHT_BRACKET;
         constexpr CppTokenType CppT_GREATER_EQUALS = CppTokenType::PLUS_PLUS;
         constexpr CppTokenType CppT_GREATER_THAN = CppTokenType::MINUS_MINUS;
         constexpr CppTokenType CppT_LEFT_PAREN = CppTokenType::LEFT_SHIFT;
         constexpr CppTokenType CppT_RIGHT_PAREN = CppTokenType::RIGHT_SHIFT;
         constexpr CppTokenType CppT_LEFT_BRACKET = CppTokenType::LESS_THAN_EQUALS;
         constexpr CppTokenType CppT_RIGHT_BRACKET = CppTokenType::GREATER_THAN_EQUALS;
         constexpr CppTokenType CppT_LEFT_BRACE = CppTokenType::PLUS_EQUALS;
         constexpr CppTokenType CppT_RIGHT_BRACE = CppTokenType::MINUS_EQUALS;
         constexpr CppTokenType CppT_UP_ARROW = CppTokenType::STAR_EQUALS;
         constexpr CppTokenType CppT_DOT_DOT = CppTokenType::SLASH_EQUALS;
         
         constexpr CppTokenType CppT_LESS_THAN = CppTokenType::EQUALS_EQUALS;
         constexpr CppTokenType CppT_LESS_EQUALS = CppTokenType::OR_EQUALS;
         constexpr CppTokenType CppT_GREATER_EQUALS = CppTokenType::PERCENT_EQUALS;
         constexpr CppTokenType CppT_GREATER_THAN = CppTokenType::AND_EQUALS;
         constexpr CppTokenType CppT_LEFT_PAREN = CppTokenType::CARROT_EQUALS;
         constexpr CppTokenType CppT_RIGHT_PAREN = CppTokenType::EXCLAMATION_EQUALS;
         constexpr CppTokenType CppT_LEFT_BRACKET = CppTokenType::LEFT_SHIFT_EQUALS;
         constexpr CppTokenType CppT_RIGHT_BRACKET = CppTokenType::RIGHT_SHIFT_EQUALS;
         constexpr CppTokenType CppT_LEFT_BRACE = CppTokenType::OR_OR;
         constexpr CppTokenType CppT_RIGHT_BRACE = CppTokenType::AND_AND;
         constexpr CppTokenType CppT_UP_ARROW = CppTokenType::SLASH_SLASH;
         constexpr CppTokenType CppT_DOT_DOT = CppTokenType::SLASH_STAR;
         
         constexpr CppTokenType CppT_DOT_DOT = CppTokenType::STAR_SLASH;
         constexpr CppTokenType CppT_IDENTIFIER = CppTokenType:: IDENTIFIER;
         constexpr CppTokenType CppT_INTEGER = CppTokenType::INTEGER;
         constexpr CppTokenType CppT_STRING = CppTokenType::STRING;
         
         constexpr CppTokenType CppT_REAL = CppTokenType::REAL;
         constexpr CppTokenType CppT_ERROR = CppTokenType::ERROR;
         constexpr CppTokenType CppT_END_OF_FILE = CppTokenType::END_OF_FILE;
        
        // // Reserved words.
        // AND, ARRAY, BEGIN, CASE, CONST, DIV, DO, DOWNTO, ELSE, END,
        // FILE, FOR, FUNCTION, GOTO, IF, IN, LABEL, MOD, NIL, NOT,
        // OF, OR, PACKED, PROCEDURE, PROGRAM, RECORD, REPEAT, SET,
        // THEN, TO, TYPE, UNTIL, VAR, WHILE, WITH,
        
        // // Special symbols.
        // PLUS, MINUS, STAR, SLASH, COLON_EQUALS,
        // DOT, COMMA, SEMICOLON, COLON, QUOTE,
        // EQUALS, NOT_EQUALS, LESS_THAN, LESS_EQUALS,
        // GREATER_EQUALS, GREATER_THAN, LEFT_PAREN, RIGHT_PAREN,
        // LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
        // UP_ARROW, DOT_DOT,
        
        // IDENTIFIER, INTEGER, REAL, STRING,
        // ERROR, END_OF_FILE,
    };
    
    // constexpr CppTokenType CppT_AND = CppTokenType::AND;
    // constexpr CppTokenType CppT_ARRAY = CppTokenType::ARRAY;
    // constexpr CppTokenType CppT_BEGIN = CppTokenType::BEGIN;
    // constexpr CppTokenType CppT_CASE = CppTokenType::CASE;
    // constexpr CppTokenType CppT_CONST = CppTokenType::CONST;
    // constexpr CppTokenType CppT_DIV = CppTokenType::DIV;
    // constexpr CppTokenType CppT_DO = CppTokenType::DO;
    // constexpr CppTokenType CppT_DOWNTO = CppTokenType::DOWNTO;
    
    // constexpr CppTokenType CppT_ELSE = CppTokenType::ELSE;
    // constexpr CppTokenType CppT_END = CppTokenType::END;
    // constexpr CppTokenType CppT_FILE = CppTokenType::FILE;
    // constexpr CppTokenType CppT_FOR = CppTokenType::FOR;
    // constexpr CppTokenType CppT_FUNCTION = CppTokenType::FUNCTION;
    // constexpr CppTokenType CppT_GOTO = CppTokenType::GOTO;
    // constexpr CppTokenType CppT_IF = CppTokenType::IF;
    // constexpr CppTokenType CppT_IN = CppTokenType::IN;
    
    // constexpr CppTokenType CppT_LABEL = CppTokenType::LABEL;
    // constexpr CppTokenType CppT_MOD = CppTokenType::MOD;
    // constexpr CppTokenType CppT_NIL = CppTokenType::NIL;
    // constexpr CppTokenType CppT_NOT = CppTokenType::NOT;
    // constexpr CppTokenType CppT_OF = CppTokenType::OF;
    // constexpr CppTokenType CppT_OR = CppTokenType::OR;
    // constexpr CppTokenType CppT_PACKED = CppTokenType::PACKED;
    // constexpr CppTokenType CppT_PROCEDURE = CppTokenType::PROCEDURE;
    
    // constexpr CppTokenType CppT_PROGRAM = CppTokenType::PROGRAM;
    // constexpr CppTokenType CppT_RECORD = CppTokenType::RECORD;
    // constexpr CppTokenType CppT_REPEAT = CppTokenType::REPEAT;
    // constexpr CppTokenType CppT_SET = CppTokenType::SET;
    // constexpr CppTokenType CppT_THEN = CppTokenType::THEN;
    // constexpr CppTokenType CppT_TO = CppTokenType::TO;
    // constexpr CppTokenType CppT_TYPE = CppTokenType::TYPE;
    
    // constexpr CppTokenType CppT_UNTIL = CppTokenType::UNTIL;
    // constexpr CppTokenType CppT_VAR = CppTokenType::VAR;
    // constexpr CppTokenType CppT_WHILE = CppTokenType::WHILE;
    // constexpr CppTokenType CppT_WITH = CppTokenType::WITH;
    
    // constexpr CppTokenType CppT_PLUS = CppTokenType::PLUS;
    // constexpr CppTokenType CppT_MINUS = CppTokenType::MINUS;
    // constexpr CppTokenType CppT_STAR = CppTokenType::STAR;
    // constexpr CppTokenType CppT_SLASH = CppTokenType::SLASH;
    // constexpr CppTokenType CppT_COLON_EQUALS = CppTokenType::COLON_EQUALS;
    // constexpr CppTokenType CppT_DOT = CppTokenType::DOT;
    // constexpr CppTokenType CppT_COMMA = CppTokenType::COMMA;
    // constexpr CppTokenType CppT_SEMICOLON = CppTokenType::SEMICOLON;
    // constexpr CppTokenType CppT_COLON = CppTokenType::COLON;
    // constexpr CppTokenType CppT_QUOTE = CppTokenType::QUOTE;
    // constexpr CppTokenType CppT_EQUALS = CppTokenType::EQUALS;
    // constexpr CppTokenType CppT_NOT_EQUALS = CppTokenType::NOT_EQUALS;
    
    // constexpr CppTokenType CppT_LESS_THAN = CppTokenType::LESS_THAN;
    // constexpr CppTokenType CppT_LESS_EQUALS = CppTokenType::LESS_EQUALS;
    // constexpr CppTokenType CppT_GREATER_EQUALS = CppTokenType::GREATER_EQUALS;
    // constexpr CppTokenType CppT_GREATER_THAN = CppTokenType::GREATER_THAN;
    // constexpr CppTokenType CppT_LEFT_PAREN = CppTokenType::LEFT_PAREN;
    // constexpr CppTokenType CppT_RIGHT_PAREN = CppTokenType::RIGHT_PAREN;
    // constexpr CppTokenType CppT_LEFT_BRACKET = CppTokenType::LEFT_BRACKET;
    // constexpr CppTokenType CppT_RIGHT_BRACKET = CppTokenType::RIGHT_BRACKET;
    // constexpr CppTokenType CppT_LEFT_BRACE = CppTokenType::LEFT_BRACE;
    // constexpr CppTokenType CppT_RIGHT_BRACE = CppTokenType::RIGHT_BRACE;
    // constexpr CppTokenType CppT_UP_ARROW = CppTokenType::UP_ARROW;
    // constexpr CppTokenType CppT_DOT_DOT = CppTokenType::DOT_DOT;
    
    // constexpr CppTokenType CppT_IDENTIFIER = CppTokenType::IDENTIFIER;
    // constexpr CppTokenType CppT_INTEGER = CppTokenType::INTEGER;
    // constexpr CppTokenType CppT_REAL = CppTokenType::REAL;
    // constexpr CppTokenType CppT_STRING = CppTokenType::STRING;
    // constexpr CppTokenType CppT_ERROR = CppTokenType::ERROR;
    // constexpr CppTokenType CppT_END_OF_FILE = CppTokenType::END_OF_FILE;
    
    class CppToken : public Token
    {
    public:
        static map<string, CppTokenType> RESERVED_WORDS;
        static map<string, CppTokenType> SPECIAL_SYMBOLS;
        static map<CppTokenType, string> SPECIAL_SYMBOL_NAMES;
        
    protected:
        /**
         * Constructor.
         * @param source the source from where to fetch the token's characters.
         * @throw a string message if an error occurred.
         */
        CppToken(Source *source) throw (string);
        
    private:
        static bool INITIALIZED;
        
        /**
         * Initialize the static maps.
         */
        static void initialize();
    };
    
}}}  // namespace wci::frontend::Cpp

#endif /* WCI_FRONTEND_CPP_CPPTOKEN_H_ */
