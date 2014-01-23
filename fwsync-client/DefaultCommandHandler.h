#pragma once
#include "CommandHandler.h"
#include <string>
#include "socket.h"
#include "constants.h"
#include "SocketException.h"

using namespace std;

namespace fwsync
{

	class DefaultCommandHandler : public CommandHandler
	{
	private:
		DefaultCommandHandler();
		DefaultCommandHandler(string);

	public:
		virtual void process(ClientSocket*, vector<string>&);
		virtual CommandHandler* clone();

	private:
		static DefaultCommandHandler m_defaultCmdHandler;
	};
}
