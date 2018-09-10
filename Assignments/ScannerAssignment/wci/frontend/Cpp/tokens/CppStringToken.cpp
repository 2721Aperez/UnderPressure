/**
 * <h1>CppStringToken</h1>
 *
 * <p> Cpp string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak & Under Pressure</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "CppStringToken.h"

#include <string>
#include "../CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {
    
    using namespace std;
    using namespace wci::frontend;
    using namespace wci::frontend::Cpp;
    
    CppStringToken::CppStringToken(Source *source) throw (string)
    : CppToken(source)
    {
        extract();
    }
    
    void CppStringToken::extract() throw (string)
    {
        string value_str = "";
        
        char current_ch = next_char();  // consume initial quote
        text += "'";
        
        // Get string characters.
        //This needs to be able to catch double quotes ""
        do
        {
            // Replace any whitespace character with a blank.
            if (isspace(current_ch)) current_ch = ' ';
            
            if ((current_ch != '\'' && current_ch != '\"') && (current_ch != EOF))
            {
                text += current_ch;
                value_str  += current_ch;
                current_ch = next_char();  // consume character
            }
            
            // Quote?  Each pair of adjacent quotes represents a single-quote.
            if (current_ch == '\'' || current_ch == ' \" ')
            {
                while ((current_ch == '\'' || current_ch == '\"') && (peek_char() == '\'' || peek_char() == '\"'))
                {
                    text += "''";
                    value_str  += current_ch;  // append single-quote
                    current_ch = next_char();  // consume pair of quotes
                    current_ch = next_char();
                }
            }
        } while ((current_ch != '\'' && current_ch != '\"') && (current_ch != Source::END_OF_FILE));
        
        if (current_ch == '\'' || current_ch == '\"')
        {
            next_char();  // consume final quote
            text += '\'';
            type = (TokenType) CppT_STRING;
            value = value_str;
        }
        else
        {
            type = (TokenType) CppT_ERROR;
            value = (int) UNEXPECTED_EOF;
        }
    }
    
}}}}  // namespace wci::frontend::Cpp::tokens
