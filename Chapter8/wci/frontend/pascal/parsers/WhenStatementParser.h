/*
 * WhenStatementParser.h
 *
 *  Created on: Sep 18, 2018
 *      Author: aleja
 */

#ifndef WCI_FRONTEND_PASCAL_PARSERS_WHENSTATEMENTPARSER_H_
#define WCI_FRONTEND_PASCAL_PARSERS_WHENSTATEMENTPARSER_H_

#include <string>
#include <set>
#include "StatementParser.h"
#include "../../Token.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class WhenStatementParser : public StatementParser
{
public:
	WhenStatementParser(PascalParserTD *parent);



    ICodeNode *parse_statement(Token *token) throw (string);

private:
    static set<PascalTokenType> ARROW_SET;

    static bool INITIALIZED;

    static bool initialize();
};


}}}}




#endif /* WCI_FRONTEND_PASCAL_PARSERS_WHENSTATEMENTPARSER_H_ */
