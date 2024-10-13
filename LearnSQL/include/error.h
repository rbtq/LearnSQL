#pragma once
#include "sqlIncludes.h"

void showSQLError(unsigned int handleType, const SQLHANDLE& handle) { //!<prints the error
	SQLWCHAR sqlState[1024];
	SQLWCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, sqlState, NULL, message, 1024, NULL)) {

	}
}
