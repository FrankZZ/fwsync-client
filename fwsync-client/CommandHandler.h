#pragma once
#include <string>
#include "socket.h"
#include <vector>

using namespace std;

namespace fwsync
{
	class CommandHandler
	{
	public:
		CommandHandler();
		CommandHandler(wstring);
		virtual void process(ClientSocket*, vector<wstring>&) = 0;
		virtual CommandHandler* clone() = 0;
	};
}