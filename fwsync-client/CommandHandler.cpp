#include "CommandHandler.h"
#include "CommandFactory.h"

namespace fwsync
{

	CommandHandler::CommandHandler()
	{

	}

	CommandHandler::CommandHandler(string sCommand)
	{
		CommandFactory::assign(sCommand, this);
	}
}