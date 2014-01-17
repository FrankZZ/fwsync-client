#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "constants.h"
#include "utility.h"
#include "socket.h"
#include "CommandHandler.h"
#include "CommandFactory.h"
#include "SocketException.h"

namespace fwsync
{

	class Client
	{
		public:
			Client::Client();
			Client::~Client();

			void Client::connect(const char*, int);

		private:
			void Client::ReadFromSocket(Socket*);

	};

}