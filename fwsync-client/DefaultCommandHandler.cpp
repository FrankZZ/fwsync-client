#include "DefaultCommandHandler.h"

using namespace std;

namespace fwsync
{

	DefaultCommandHandler DefaultCommandHandler::m_defaultCmdHandler(string("DEFAULT"));

	DefaultCommandHandler::DefaultCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	DefaultCommandHandler::DefaultCommandHandler()
	{

	}

	void DefaultCommandHandler::process(ClientSocket* socket, vector<string>& params)
	{
		wchar_t line[MAXPATH + 1];

		while (socket->readline(line, MAXPATH) > 0)
		{
			wcout << line << endl;
		}
		
	}

	CommandHandler* DefaultCommandHandler::clone()
	{
		return new DefaultCommandHandler();
	}

}