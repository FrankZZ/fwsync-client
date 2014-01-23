#pragma once
#include "CommandHandler.h"
#include <string>
#include <vector>
#include "socket.h"

using namespace std;

namespace fwsync
{

	class SyncCommandHandler : public CommandHandler
	{
		private:
			SyncCommandHandler();
			SyncCommandHandler(string);

		public:
			virtual void process(ClientSocket*, vector<string>&);
			virtual CommandHandler* clone();

		private:
			static SyncCommandHandler m_syncCmdHandler;
	};
}
