#include "fwsync-client.h"

using namespace std;

namespace fwsync
{
	Client::Client()
	{

	}

	Client::~Client()
	{
		/*
		socket->close();
		delete socket;
		*/
	};

	void Client::connect(const char* szIp, int iPort)
	{
		ClientSocket* socket = new ClientSocket(szIp, iPort);
		
		ReadFromSocket(socket); //Read welcome message

		string szLine;

		while (getline(std::cin, szLine))
		{
			socket->writeline(szLine.c_str());

			vector<string> params = *new vector<string>();

			strsplit(szLine, params);

			if (params.size() > 0)
			for (int i = 0; i < params[0].length(); i++)
				params[0][i] = tolower(params[0][i]);

			CommandHandler* pCommand = CommandFactory::create(params[0]);

			if (pCommand != NULL)
			{
				pCommand->process(socket, params);
			}
			else
				CommandFactory::create("DEFAULT")->process(socket, params);
		}

		delete socket;
	}

	void Client::ReadFromSocket(Socket* socket)
	{
		char line[MAXPATH + 1];

		while (socket->readline(line, MAXPATH) > 0)
		{
			//vector<string> params = *new vector<string>();
			cout << line << "\n";
		}
	}
}