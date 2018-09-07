/**
 * <h1>PascalWordToken</h1>
 *
 * <p> Pascal word tokens (identifiers and reserved words).</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_PASCAL_TOKENS_PASCALWORDTOKEN_H_
#define WCI_FRONTEND_PASCAL_TOKENS_PASCALWORDTOKEN_H_

#include <string>
#include "../CppToken.h"

namespace wci { namespace frontend { namespace pascal { namespace tokens {

using namespace std;
using namespace wci::frontend::Cpp;

class CppWordToken : public CppToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CppWordToken(Source *source) throw (string);

protected:
    /**
     * Extract a Cpp word token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::Cpp::tokens

#endif /* WCI_FRONTEND_CPP_TOKENS_CPPWORDTOKEN_H_ */
