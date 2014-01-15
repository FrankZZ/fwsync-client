#include "DefaultCommandHandler.h"

namespace fwsync
{

	DefaultCommandHandler DefaultCommandHandler::m_infoCmdHandler(std::string("DEFAULT"));

	DefaultCommandHandler::DefaultCommandHandler(std::string sCommand) : CommandHandler(sCommand)
	{

	}

	DefaultCommandHandler::DefaultCommandHandler()
	{

	}

	void DefaultCommandHandler::process(ClientSocket* socket, std::vector<std::string>& params)
	{
		char line[MAXPATH + 1];

		while (socket->readline(line, MAXPATH) > 0)
		{
			cout << line << "\n";
		}
	}

	CommandHandler* DefaultCommandHandler::clone()
	{
		return new DefaultCommandHandler();
	}

}