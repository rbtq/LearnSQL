#pragma once
#include "sqlIncludes.h"
#include "simpleLoggerInstance.h"

void showSQLError(unsigned int handleType, const SQLHANDLE& handle) { //!<prints the error
	SQLWCHAR sqlState[1024];
	SQLWCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, sqlState, NULL, message, 1024, NULL)) {
		s_logger.info("SQL Driver Message: {0} \nSQL State: {1}.", message, sqlState);
	}
}
