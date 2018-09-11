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
        STAR, MINUS, PLUS, EQUALS, BITWISEOR, SLASH, COLON, SEMICOLON,
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
        
        IDENTIFIER, STRING, INTEGER, REAL, ERROR,
        END_OF_FILE
    };
    
    //Reserved Words
    constexpr CppTokenType CppT_AUTO = CppTokenType::AUTO;
    constexpr CppTokenType CppT_BREAK = CppTokenType::BREAK;
    constexpr CppTokenType CppT_CASE = CppTokenType::CASE;
    constexpr CppTokenType CppT_CHAR = CppTokenType::CHAR;
    constexpr CppTokenType CppT_CLASS = CppTokenType::CLASS;
    constexpr CppTokenType CppT_CONST = CppTokenType::CONST;
    constexpr CppTokenType CppT_CONTINUE = CppTokenType::CONTINUE;
    constexpr CppTokenType CppT_DO = CppTokenType::DO;
    
    constexpr CppTokenType CppT_DOUBLE = CppTokenType::DOUBLE;
    constexpr CppTokenType CppT_ELSE = CppTokenType::ELSE;
    constexpr CppTokenType CppT_ENUM = CppTokenType::ENUM;
    constexpr CppTokenType CppT_EXTERN = CppTokenType::EXTERN;
    constexpr CppTokenType CppT_FLOAT = CppTokenType::FLOAT;
    constexpr CppTokenType CppT_FOR = CppTokenType::FOR;
    constexpr CppTokenType CppT_GOTO = CppTokenType::GOTO;
    constexpr CppTokenType CppT_IF = CppTokenType::IF;
    
    constexpr CppTokenType CppT_INT = CppTokenType::INT;
    constexpr CppTokenType CppT_LONG = CppTokenType::LONG;
    constexpr CppTokenType CppT_NAMESPACE = CppTokenType::NAMESPACE;
    constexpr CppTokenType CppT_OPERATOR = CppTokenType::OPERATOR;
    constexpr CppTokenType CppT_PROTECTED = CppTokenType::PROTECTED;
    constexpr CppTokenType CppT_PUBLIC = CppTokenType::PUBLIC;
    constexpr CppTokenType CppT_RETURN = CppTokenType::RETURN;
    constexpr CppTokenType CppT_STATIC = CppTokenType::STATIC;
    
    constexpr CppTokenType CppT_STRUCT = CppTokenType::STRUCT;
    constexpr CppTokenType CppT_SWITCH = CppTokenType::SWITCH;
    constexpr CppTokenType CppT_TEMPLATE = CppTokenType::TEMPLATE;
    constexpr CppTokenType CppT_THIS = CppTokenType::THIS;
    constexpr CppTokenType CppT_THROW = CppTokenType::THROW;
    constexpr CppTokenType CppT_UNION = CppTokenType::UNION;
    constexpr CppTokenType CppT_VOID = CppTokenType::VOID;
    
    constexpr CppTokenType CppT_WHILE = CppTokenType::WHILE;
    
    
    //Special Symbols
    constexpr CppTokenType CppT_TILDA = CppTokenType::TILDA;
    constexpr CppTokenType CppT_EXCLAMATION = CppTokenType::EXCLAMATION;
    constexpr CppTokenType CppT_AT = CppTokenType::AT;
    constexpr CppTokenType CppT_PERCENT = CppTokenType::PERCENT;
    constexpr CppTokenType CppT_CARROT = CppTokenType::CARROT;
    constexpr CppTokenType CppT_AMPERSAND = CppTokenType::AMPERSAND;
    constexpr CppTokenType CppT_STAR = CppTokenType::STAR;
    constexpr CppTokenType CppT_MINUS = CppTokenType::MINUS;
    constexpr CppTokenType CppT_PLUS = CppTokenType::PLUS;
    constexpr CppTokenType CppT_EQUALS = CppTokenType::EQUALS;
    constexpr CppTokenType CppT_BITWISEOR = CppTokenType::BITWISEOR;
    constexpr CppTokenType CppT_SLASH = CppTokenType::SLASH;
    
    constexpr CppTokenType CppT_COLON = CppTokenType::COLON;
    constexpr CppTokenType CppT_SEMICOLON = CppTokenType::SEMICOLON;
    constexpr CppTokenType CppT_QUESTIONMARK = CppTokenType::QUESTIONMARK;
    constexpr CppTokenType CppT_LESS_THAN = CppTokenType::LESS_THAN;
    constexpr CppTokenType CppT_GREATER_THAN = CppTokenType::GREATER_THAN;
    constexpr CppTokenType CppT_DOT = CppTokenType::DOT;
    constexpr CppTokenType CppT_COMMA = CppTokenType::COMMA;
    constexpr CppTokenType CppT_SINGLE_QUOTE = CppTokenType::SINGLE_QUOTE;
    constexpr CppTokenType CppT_DOUBLE_QUOTE = CppTokenType::DOUBLE_QUOTE;
    constexpr CppTokenType CppT_LEFT_PAREN = CppTokenType::LEFT_PAREN;
    constexpr CppTokenType CppT_RIGHT_PAREN = CppTokenType::RIGHT_PAREN;
    constexpr CppTokenType CppT_LEFT_SQ_BRACKET = CppTokenType::LEFT_SQ_BRACKET;
    
    constexpr CppTokenType CppT_RIGHT_SQ_BRACKET = CppTokenType::RIGHT_SQ_BRACKET;
    constexpr CppTokenType CppT_LEFT_BRACKET = CppTokenType::LEFT_BRACKET;
    constexpr CppTokenType CppT_RIGHT_BRACKET = CppTokenType::RIGHT_BRACKET;
    constexpr CppTokenType CppT_PLUS_PLUS = CppTokenType::PLUS_PLUS;
    constexpr CppTokenType CppT_MINUS_MINUS = CppTokenType::MINUS_MINUS;
    constexpr CppTokenType CppT_LEFT_SHIFT = CppTokenType::LEFT_SHIFT;
    constexpr CppTokenType CppT_RIGHT_SHIFT = CppTokenType::RIGHT_SHIFT;
    constexpr CppTokenType CppT_LESS_THAN_EQUALS = CppTokenType::LESS_THAN_EQUALS;
    constexpr CppTokenType CppT_GREATER_THAN_EQUALS = CppTokenType::GREATER_THAN_EQUALS;
    constexpr CppTokenType CppT_PLUS_EQUALS = CppTokenType::PLUS_EQUALS;
    constexpr CppTokenType CppT_MINUS_EQUALS = CppTokenType::MINUS_EQUALS;
    constexpr CppTokenType CppT_STAR_EQUALS = CppTokenType::STAR_EQUALS;
    
    constexpr CppTokenType CppT_SLASH_EQUALS = CppTokenType::SLASH_EQUALS;
    constexpr CppTokenType CppT_EQUALS_EQUALS = CppTokenType::EQUALS_EQUALS;
    constexpr CppTokenType CppT_OR_EQUALS = CppTokenType::OR_EQUALS;
    constexpr CppTokenType CppT_PERCENT_EQUALS = CppTokenType::PERCENT_EQUALS;
    constexpr CppTokenType CppT_AND_EQUALS = CppTokenType::AND_EQUALS;
    constexpr CppTokenType CppT_CARROT_EQUALS = CppTokenType::CARROT_EQUALS;
    constexpr CppTokenType CppT_EXCLAMATION_EQUALS = CppTokenType::EXCLAMATION_EQUALS;
    constexpr CppTokenType CppT_LEFT_SHIFT_EQUALS = CppTokenType::LEFT_SHIFT_EQUALS;
    constexpr CppTokenType CppT_RIGHT_SHIFT_EQUALS = CppTokenType::RIGHT_SHIFT_EQUALS;
    constexpr CppTokenType CppT_OR_OR = CppTokenType::OR_OR;
    constexpr CppTokenType CppT_AND_AND = CppTokenType::AND_AND;
    constexpr CppTokenType CppT_SLASH_SLASH = CppTokenType::SLASH_SLASH;
    
    constexpr CppTokenType CppT_SLASH_STAR = CppTokenType::SLASH_STAR;
    constexpr CppTokenType CppT_STAR_SLASH = CppTokenType::STAR_SLASH;
    
    
    constexpr CppTokenType CppT_IDENTIFIER = CppTokenType::IDENTIFIER;
    constexpr CppTokenType CppT_INTEGER = CppTokenType::INTEGER;
    constexpr CppTokenType CppT_STRING = CppTokenType::STRING;
    constexpr CppTokenType CppT_REAL = CppTokenType::REAL;
    constexpr CppTokenType CppT_ERROR = CppTokenType::ERROR;
    constexpr CppTokenType CppT_END_OF_FILE = CppTokenType::END_OF_FILE;
    
    
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
