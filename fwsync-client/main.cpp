#include "fwsync-client.h"

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "utility.h"
#include <vector>
#include <string>

using namespace fwsync;

void askConnect(Client& client)
{
	wcout << L"Please type [host] [port]" << endl;

	string szLine;

	while (getline(std::cin, szLine))
	{
		if (szLine.length() == 0)
			continue;

		vector<std::string> params;

		strsplit(szLine, params, ' ');

		if (params.size() != 2)
		{
			wcout << L"Syntax error" << endl;
			continue;
		}

		client.connect(params[0].c_str(), stoi(params[1]));

	}
}

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	Client client = Client();

	while (1)
	{
		try
		{
			askConnect(client);
		}
		catch (SocketException& ex)
		{
			std::wcout << L"Connection lost..." << endl;
		}
		catch (invalid_argument& ex)
		{
			std::wcout << L"Invalid argument" << endl;
		}
		catch (out_of_range& ex)
		{
			std::wcout << L"Port out of range" << endl;
		}
		catch (runtime_error& ex)
		{
			std::wcout << L"Cannot connect" << endl;
		}
	}

	return 0;
}