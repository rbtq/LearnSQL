#pragma once
#include "sqlIncludes.h"
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
			do {
				if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &m_sqlEnvHandle)) break;

				if (SQL_SUCCESS != SQLSetEnvAttr(m_sqlEnvHandle,SQL_ATTR_ODBC_VERSION,(SQLPOINTER)SQL_OV_ODBC3,0)) break;

				if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, m_sqlEnvHandle, &m_sqlConnectionHandle)) break;

				if (SQL_SUCCESS != SQLSetConnectAttr(m_sqlConnectionHandle,SQL_LOGIN_TIMEOUT,(SQLPOINTER)5,0)) break;

			} while (successfulSetup);
		
		};
	};
}