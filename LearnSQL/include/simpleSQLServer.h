#pragma once
#include "sqlIncludes.h"
#include "simpleLoggerInstance.h"

namespace ssqls {
	class SimpleSQLServer {
	private:
		SQLHANDLE m_sqlEnvHandle = NULL;
		SQLHANDLE m_sqlConnectionHandle = NULL;
		SQLHANDLE m_sqlStatementHandle = NULL;
		SQLRETURN m_sqlReturnCode = 0;
		char m_sqlQuery[21] = "SELECT * FROM people";

	public:
		SimpleSQLServer() { //!<constructor
			bool successfulSetup = false;
			//setup the server
			do {
				if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &m_sqlEnvHandle)) break;

				if (SQL_SUCCESS != SQLSetEnvAttr(m_sqlEnvHandle,SQL_ATTR_ODBC_VERSION,(SQLPOINTER)SQL_OV_ODBC3,0)) break;

				if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, m_sqlEnvHandle, &m_sqlConnectionHandle)) break;

				if (SQL_SUCCESS != SQLSetConnectAttr(m_sqlConnectionHandle,SQL_LOGIN_TIMEOUT,(SQLPOINTER)5,0)) break;

				SQLWCHAR retConString[1024];

				switch (SQLDriverConnect(m_sqlConnectionHandle, NULL,
					(SQLWCHAR*)"DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=myDB; UID =myID; PWD=myPWD",
					SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {

					case SQL_SUCCESS_WITH_INFO:
					case SQL_SUCCESS: {
						break;
					}
					case SQL_ERROR:
					case SQL_INVALID_HANDLE:
					case SQL_NO_DATA_FOUND: {
						showSQLError(SQL_HANDLE_DBC, m_sqlConnectionHandle);
						m_sqlReturnCode = -1;
						break;
					}
					default: {
						break;
					}

				}

				if (m_sqlReturnCode == -1) break;

				if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, m_sqlConnectionHandle, &m_sqlStatementHandle)) break;

				//SQLExecDirect(m_sqlConnectionHandle,(SQLWCHAR*),SQL_NTS);

			} while (successfulSetup);
		
		};

		void showSQLError(unsigned int handleType, const SQLHANDLE& handle) { //!<prints the error
			SQLWCHAR sqlState[1024];
			SQLWCHAR message[1024];
			if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, sqlState, NULL, message, 1024, NULL)) {
				s_logger.info("SQL Driver Message: {0} \nSQL State: {1}.", message, sqlState);
			}
		}
	};
}