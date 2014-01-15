#pragma once
#include "CommandHandler.h"
#include <string>
#include <iostream>
#include <fstream>
#include "constants.h"

namespace fwsync
{

	class GetCommandHandler : public CommandHandler
	{
	private:
		GetCommandHandler();
		GetCommandHandler(std::string);

	public:
		virtual void process(ClientSocket* socket, std::vector<std::string>& params);
		virtual CommandHandler* clone();

	private:
		static GetCommandHandler m_getCmdHandler;
	};
}