/*
 * WhenStatementParser.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: aleja
 */

#include <string>
#include <set>
#include "IfStatementParser.h"
#include "WhenStatementParser.h"
#include "StatementParser.h"
#include "AssignmentStatementParser.h"
#include "ExpressionParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"


namespace wci { namespace frontend { namespace pascal { namespace parsers {
    
    using namespace std;
    using namespace wci::frontend::pascal;
    using namespace wci::intermediate;
    using namespace wci::intermediate::icodeimpl;
    
    bool WhenStatementParser::INITIALIZED = false;
    
    set<PascalTokenType> WhenStatementParser::ARROW_SET;
    
    void WhenStatementParser::initialize()
    {
        if (INITIALIZED) return;
        
        ARROW_SET = StatementParser::STMT_START_SET;
        ARROW_SET.insert(PascalTokenType::THEN);
        
        set<PascalTokenType>::iterator it;
        for (it  = StatementParser::STMT_FOLLOW_SET.begin();
             it != StatementParser::STMT_FOLLOW_SET.end();
             it++)
        {
            ARROW_SET.insert(*it);
        }
        
        INITIALIZED = true;
    }
    
    WhenStatementParser::WhenStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
    {
        initialize();
    }

    ICodeNode *WhenStatementParser::parse_statement(Token *token) throw(string)
	{
    	token = next_token(token); //Consume When

    	//Create When Node
    	ICodeNode *when_node = ICodeFactory::create_icode_node((ICodeNodeType) NT_IF);

        //Parse
        ExpressionParser expression_parser(this);
        when_node -> add_child(expression_parser.parse_statement(token));

        token = synchronize(ARROW_SET);
        

	}
    
}}}}
