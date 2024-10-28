#include "sqlIncludes.h"
#include "simpleLoggerInstance.h"


int main() {
	s_logger.start(ssw::LogSettings());


	s_logger.stop();
	return 0;

}