#include "fwsync-client.h"

namespace fwsync
{
	Client::Client()
	{

	}

	Client::~Client()
	{

	};

	void Client::connect(const char* szIp, int iPort)
	{
		ClientSocket* socket = new ClientSocket(szIp, iPort);

		char line[MAXPATH + 1];

		while (socket->readline(line, MAXPATH))
		{
			vector<string> params = *new vector<string>();
			cout << line << "\r\n";

			strsplit(line, params);

			if (params.size() > 0)
			for (int i = 0; i < params[0].length(); i++)
				params[0][i] = tolower(params[0][i]);

			// echo request to terminal
			cout << "Got request: " << params[0] << "\r\n";

			CommandHandler* pCommand = CommandFactory::create(params[0]);

			if (pCommand != NULL)
			{
				pCommand->process(socket, params);
			}
			else
				cout << "Unexpected response from server\r\n";
		}
		
		delete socket;
	}
}