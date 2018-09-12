/**
 * <h1>CppSpecialSymbolToken</h1>
 *
 * <p> Cpp special symbol tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak & Under Pressure</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../../Cpp/tokens/CppSpecialSymbolToken.h"

#include <string>

#include "../../Cpp/CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

    using namespace std;
    using namespace wci::frontend;
    using namespace wci::frontend::Cpp;

    CppSpecialSymbolToken::CppSpecialSymbolToken(Source *source) throw (string)
    : CppToken(source)
    {
        extract();
    }

    void CppSpecialSymbolToken::extract() throw (string)
    {
        char current_ch = current_char();
        bool good_symbol = true;


        text = current_ch;

        switch (current_ch)
        {
                // Single-character special symbols.
            case '~':  case '@':  case ':':  case ';':  case '?':
            case '.':  case ',':  case '\'': case '"':  case '(':
            case ')':  case '[':  case ']':  case '{':  case '}':

            {
                next_char();  // consume character
                break;
            }

                // ! or !=
            case '!':
            {
                current_ch = next_char();  // consume '!';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }

                break;
            }

                // % or %=
            case '%':
            {
                current_ch = next_char();  // consume '%';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }

                break;
            }

                // = or ==
            case '=':
            {
                current_ch = next_char();  // consume '=';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }

                break;
            }

                // ^ or ^=
            case '^':
            {
                current_ch = next_char();  // consume '^';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }

                break;
            }

                // & or &= or &&
            case '&':
            {
                current_ch = next_char();  // consume '&';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }
                else if (current_ch == '&')
                {
                    text += current_ch;
                    next_char();  // consume '&'
                }

                break;
            }

                // * or *= or */
            case '*':
            {
                current_ch = next_char();  // consume '*';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }
                else if (current_ch == '/')
                {
                    text += current_ch;
                    next_char();  // consume '/'
                }

                break;
            }

                // - or -= or --
            case '-':
            {
                current_ch = next_char();  // consume '-';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }
                else if (current_ch == '-')
                {
                    text += current_ch;
                    next_char();  // consume '-'
                }

                break;
            }

                // + or += or ++
            case '+':
            {
                current_ch = next_char();  // consume '+';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }
                else if (current_ch == '+')
                {
                    text += current_ch;
                    next_char();  // consume '+'
                }

                break;
            }

                // | or |= or ||
            case '|':
            {
                current_ch = next_char();  // consume '|';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }
                else if (current_ch == '|')
                {
                    text += current_ch;
                    next_char();  // consume '|'
                }

                break;
            }

                // / or /= or // or /*
            case '/':
            {
                current_ch = next_char();  // consume '/';

            	if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }

                if(current_ch == '/')
            	{
                		text = "";

            			do
            			{
            				current_ch = next_char();
            			}while(current_ch != Source::END_OF_FILE && current_ch != Source::END_OF_LINE);
            	}

            	else if(current_ch == '*')
            		{
            			current_ch = 'a';
            			text = "";
            			do
            			{
            				if(current_ch != '*'){current_ch = next_char();}
            				if(current_ch == '*')
            				{
            					current_ch = next_char();
            					if(current_ch == '/'){break;}

            				}
            			}while(current_ch != Source::END_OF_FILE);
            		}
            		else
            		{
            			current_ch = next_char();
            		}
                break;
            	}


                // for \n or \t
                //            case '\\':
                //            {
                //                current_ch = next_char(); // Consumes the \
                //
                //                if(current_ch == 'n')
                //                {
                //                    text += current_ch;
                //                    next_char(); //Consumes the n
                //                }
                //                else if(current_ch == 't')
                //                {
                //                    text += current_ch;
                //                    next_char(); // Consumes the t
                //                }
                //
                //                break;
                //            }

                // < or <= or << or <<=
            case '<':
            {
                current_ch = next_char();  // consume '<';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }
                else if (current_ch == '<')
                {
                    text += current_ch;
                    current_ch = next_char();  // consume '<'

                    if (current_ch == '=')
                    {
                        text += current_ch;
                        next_char();     // consume '='
                    }
                }

                break;
            }

                // > or >= or >> or >>=
            case '>':
            {
                current_ch = next_char();  // consume '>';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
                }
                else if (current_ch == '>')
                {
                    text += current_ch;
                    current_ch = next_char();  // consume '>'

                    if (current_ch == '=')
                    {
                        text += current_ch;
                        next_char();     // consume '='
                    }
                }

                break;
            }

            default:
            {
                next_char();  // consume bad character
                type = (TokenType) (CppT_ERROR);
                value = (int) INVALID_CHARACTER;
                good_symbol = false;
            }
        }

        // Set the type if it wasn't an error.
        if (good_symbol) {
            type = (TokenType) (CppToken::SPECIAL_SYMBOLS[text]);
        }
    }

}}}}  // namespace wci::frontend::Cpp::tokens

