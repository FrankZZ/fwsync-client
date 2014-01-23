#pragma once
#include <string>

using namespace std;

namespace fwsync
{
	static const int MAXPATH = 256; // Maximale lengte van padnaam

	static const string PATHSEPERATOR =
#if defined(__APPLE__) || defined(__linux__)
		"/";
#else //windows
		"\\";
#endif

	static const int BUFFERSIZE = 4096;

	static const char DELIMITER = '|';

}