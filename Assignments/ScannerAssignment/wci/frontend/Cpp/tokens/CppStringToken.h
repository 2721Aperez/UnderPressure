/**
 * <h1>CppStringToken</h1>
 *
 * <p> Cpp string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_CPP_TOKENS_CPPSTRINGTOKEN_H_
#define WCI_FRONTEND_CPP_TOKENS_CPPSTRINGTOKEN_H_

#include <string>
#include "../CppToken.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {
    
    using namespace std;
    using namespace wci::frontend::Cpp;
    
    class CppStringToken : public CppToken
    {
    public:
        /**
         * Constructor.
         * @param source the source from where to fetch the token's characters.
         * @throw a string message if an error occurred.
         */
        CppStringToken(Source *source) throw (string);
        
    protected:
        /**
         * Extract a Cpp string token from the source.
         * Override of wci::frontend::Token.
         * @throw a string message if an error occurred.
         */
        void extract() throw (string);
    };
    
}}}}  // namespace wci::frontend::Cpp::tokens

#endif /* WCI_FRONTEND_CPP_TOKENS_CPPSTRINGTOKEN_H_ */

