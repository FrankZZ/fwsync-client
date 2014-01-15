#pragma once
#include "CommandHandler.h"
#include <string>
#include "socket.h"
#include "constants.h"

namespace fwsync
{

	class DefaultCommandHandler : public CommandHandler
	{
	private:
		DefaultCommandHandler();
		DefaultCommandHandler(std::string);

	public:
		virtual void process(ClientSocket*, std::vector<std::string>&);
		virtual CommandHandler* clone();

	private:
		static DefaultCommandHandler m_infoCmdHandler;
	};
}
