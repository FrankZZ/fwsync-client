#pragma once
#include "CommandHandler.h"
#include <string>
#include <iostream>
#include <fstream>
#include "constants.h"
#include "SocketException.h"
#include <signal.h>

using namespace std;

namespace fwsync
{

	class GetCommandHandler : public CommandHandler
	{
		private:
			GetCommandHandler();
			GetCommandHandler(string);
			string m_szFileName;
			

		public:
			virtual void process(ClientSocket* socket, std::vector<std::string>& params);
			virtual CommandHandler* clone();

		private:
			static GetCommandHandler m_getCmdHandler;
	};
	void interrupt(int param);
}