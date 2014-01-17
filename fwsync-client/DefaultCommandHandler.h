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
		DefaultCommandHandler(wstring);

	public:
		virtual void process(ClientSocket*, vector<wstring>&);
		virtual CommandHandler* clone();

	private:
		static DefaultCommandHandler m_defaultCmdHandler;
	};
}
