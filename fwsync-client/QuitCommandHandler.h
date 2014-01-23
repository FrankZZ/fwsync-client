#pragma once
#include "CommandHandler.h"
#include <string>
#include <vector>
#include "socket.h"
#include "time.h"

namespace fwsync
{

	class QuitCommandHandler : public CommandHandler
	{
	private:
		QuitCommandHandler();
		QuitCommandHandler(string);

	public:
		virtual void process(ClientSocket*, vector<string>&);
		virtual CommandHandler* clone();

	private:
		static QuitCommandHandler m_quitCmdHandler;
	};
}
