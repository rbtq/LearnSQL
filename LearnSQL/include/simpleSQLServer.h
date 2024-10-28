#pragma once
#include "sqlIncludes.h"
namespace ssqls {
	class SimpleSQLServer {
	private:
		SQLHANDLE m_sqlEnvHandle = NULL;
		SQLHANDLE m_sqlConnectionHandle = NULL;
		SQLHANDLE m_sqlStatementHandle = NULL;
		SQLRETURN m_sqlReturnCode = 0;

	public:
	};
}