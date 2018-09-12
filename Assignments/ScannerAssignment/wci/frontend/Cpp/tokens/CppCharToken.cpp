
#include "CppCharToken.h"

#include "../CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

	using namespace std;
	using namespace wci::frontend;
	using namespace wci::frontend::Cpp;

	CppCharToken::CppCharToken(Source *source) throw(char): CppToken(source)
	{
		extract();
	}

	void CppCharToken::extract() throw(char)
	{
		char val_ch = '';

        char current_ch = next_char();
        text ='\'';

        do
        {
            // Replace any whitespace character with a blank.
            if (isspace(current_ch)) current_ch = ' ';

            if ((current_ch != '\'') && (current_ch != EOF))
            {
                text += current_ch;
                value_ch  += current_ch;
                current_ch = next_char();  // consume character
            }

            // Quote?  Each pair of adjacent quotes represents a single-quote.
            if (current_ch == '\'')
            {
                while ((current_ch == '\'') && (peek_char() == '\''))
                {
                    text += "''";
                    value_ch  += current_ch;  // append single-quote
                    current_ch = next_char();  // consume pair of quotes
                    current_ch = next_char();
                }
            }
        } while ((current_ch != '\'') && (current_ch != Source::END_OF_FILE));

        if (current_ch == '\'')
        {
            next_char();  // consume final quote
            text += '\'';
            type = (TokenType) CppT_STRING;
            value = value_ch;
        }
        else
        {
            type = (TokenType) CppT_ERROR;
            value = (int) UNEXPECTED_EOF;
        }



	}


}}}}
