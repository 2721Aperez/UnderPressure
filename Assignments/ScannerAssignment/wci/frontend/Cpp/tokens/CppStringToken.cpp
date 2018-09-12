/**
 * <h1>CppStringToken</h1>
 *
 * <p> Cpp string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak & Under Pressure</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../../Cpp/tokens/CppStringToken.h"

#include <string>

#include "../../Cpp/CppError.h"

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
        text += '"';
        
        // Get string characters.
        do
        {
            // Replace any whitespace character with a blank.
            if (isspace(current_ch)) current_ch = ' ';
            
            if ((current_ch != '"') && (current_ch != EOF) && (current_ch != '\\'))
            {
                text += current_ch;
                value_str  += current_ch;
                current_ch = next_char();  // consume character
            }
            
            // Check for \n and \t and '\\'
            if (current_ch == '\\')
            {
                current_ch = next_char(); //consume \
                
                if(current_ch == 'n')
                {
                    current_ch = next_char();
                }
                else if (current_ch == 't')
                {
                    current_ch = next_char();
                }
                else if (current_ch == '\\')
                {
                    current_ch = next_char();
                }
            }
        } while ((current_ch != '"') && (current_ch != Source::END_OF_FILE));
        
        if (current_ch == '"')
        {
            next_char();  // consume final quote
            text += '"';
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
