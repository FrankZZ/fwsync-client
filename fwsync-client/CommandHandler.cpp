#include "CommandHandler.h"
#include "CommandFactory.h"

namespace fwsync
{

	CommandHandler::CommandHandler()
	{

	}

	CommandHandler::CommandHandler(wstring sCommand)
	{
		CommandFactory::assign(sCommand, this);
	}
}