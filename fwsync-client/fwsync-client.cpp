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
		ClientSocket* socket = NULL;
		
		try
		{
			socket = new ClientSocket(szIp, iPort);
		}
		catch (runtime_error& ex)
		{
			delete socket;
			throw(ex);
		}

		ReadFromSocket(socket); //Read welcome message

		wstring szLine;

		while (getline(wcin, szLine))
		{
			if (szLine.size() == 0)
				continue;

			socket->writeline(szLine.c_str());

			vector<wstring> params = vector<wstring>();

			strsplit(szLine, params);

			if (params.size() > 0)
			{

				for (int i = 0; i < params[0].length(); i++)
					params[0][i] = tolower(params[0][i]);

				CommandHandler* pCommand = CommandFactory::create(params[0]);

				if (pCommand != NULL)
				{
					try
					{
						pCommand->process(socket, params);
					}
					catch (const wchar_t* ex)
					{
						wcout << ex << endl;
					}
				}
				else
					CommandFactory::create(L"DEFAULT")->process(socket, params);

				delete pCommand;
			}
			
		}

		delete socket;
	}

	void Client::ReadFromSocket(Socket* socket)
	{
		wchar_t line[MAXPATH + 1];

		while (socket->readline(line, MAXPATH) > 0)
		{
			//vector<string> params = *new vector<string>();
			wcout << line << L"\n";
		}
	}
}