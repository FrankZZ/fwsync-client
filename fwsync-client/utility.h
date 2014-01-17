#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace fwsync
{
	void strsplit(wstring str, vector<wstring> &tokens);
	void strsplit(string str, vector<string> &tokens);
}
