/*
 * CppCharToken.h
 *
 *  Created on: Sep 11, 2018
 *      Author: aleja
 */

#ifndef WCI_FRONTEND_CPP_TOKENS_CPPCHARTOKEN_H_
#define WCI_FRONTEND_CPP_TOKENS_CPPCHARTOKEN_H_

#include <iostream>
#include "../CppToken.h"

namespace wci{ namespace frontend { namespace Cpp{ namespace tokens{

	using namespace std;
	using namespace wci::frontend::Cpp;

	class CppCharToken: public CppToken{

	public:

		CppCharToken(Source *source) throw (char);

	protected:
		void extract() throw(char);
	};

}}}}



#endif /* WCI_FRONTEND_CPP_TOKENS_CPPCHARTOKEN_H_ */
