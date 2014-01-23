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
		CommandHandler(string);
		virtual void process(ClientSocket*, vector<string>&) = 0;
		virtual CommandHandler* clone() = 0;
	};
}