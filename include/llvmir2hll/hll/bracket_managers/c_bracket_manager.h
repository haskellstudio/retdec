/**
* @file include/llvmir2hll/hll/bracket_managers/c_bracket_manager.h
* @brief A brackets manager of redundant brackets for the C language.
* @copyright (c) 2017 Avast Software, licensed under the MIT license
*/

#ifndef LLVMIR2HLL_HLL_BRACKET_MANAGERS_C_BRACKET_MANAGER_H
#define LLVMIR2HLL_HLL_BRACKET_MANAGERS_C_BRACKET_MANAGER_H

#include "llvmir2hll/hll/bracket_manager.h"

namespace llvmir2hll {

/**
* @brief A class that contains precedence table and overrided methods which
*        decide of elimination redundant brackets for the C language.
*/
class CBracketManager: public BracketManager {
public:
	CBracketManager(ShPtr<Module> module);

	virtual std::string getId() const override;

private:
	virtual ItemOfPrecTable checkPrecTable(Operators currentOperator,
		Operators prevOperator) override;
	virtual bool isOperatorSupported(Operators currentOperator) override;

private:
	/// Precedence table of operators.
	static ItemOfPrecTable precedenceTable[PREC_TABLE_SIZE][PREC_TABLE_SIZE];
};

} // namespace llvmir2hll

#endif
