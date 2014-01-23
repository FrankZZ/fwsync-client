#pragma once
#include <map>
#include <string>
#include "CommandHandler.h"

using namespace std;

namespace fwsync
{

	class CommandFactory
	{
	public:
		static CommandHandler* create(string);

	private:
		typedef map<string, CommandHandler*> CommandHandlerMap;

		static CommandHandlerMap& getMap();

		static void assign(string, CommandHandler*);
		friend class CommandHandler;
	};
}