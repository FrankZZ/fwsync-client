#include "GetCommandHandler.h"

using namespace std;

namespace fwsync
{

	GetCommandHandler GetCommandHandler::m_getCmdHandler(wstring(L"get"));

	GetCommandHandler::GetCommandHandler(wstring sCommand) : CommandHandler(sCommand)
	{

	}

	GetCommandHandler::GetCommandHandler()
	{

	}

	void GetCommandHandler::process(ClientSocket* socket, vector<wstring>& params)
	{
		if (params.size() != 3)
			throw(L"Syntax error");
		

		char buff[BUFFERSIZE + 1];

		socket->readline(buff, BUFFERSIZE);
		
		int iFileSize = stoi(buff);

		if (iFileSize >= 0)
		{
			int iBytesToRead = iFileSize;

			ofstream osFile("test.exe", ofstream::binary | ofstream::trunc);
			
			if (osFile.bad())
			{
				throw(L"Cannot open file for writing");
			}
			
			/*void (*prev_handler) (int);
			prev_handler = signal(SIGTERM, interrupt);*/

			int iBytesRead, iPercentCompleted;
			while (iBytesToRead > 0)
			{
				try
				{
					iBytesRead = socket->read(buff, iBytesToRead > BUFFERSIZE ? BUFFERSIZE : iBytesToRead);
				}
				catch (SocketException& ex)
				{
					osFile.close();
					throw ex;
				}
	
				osFile.write(buff, iBytesRead);
				
				iBytesToRead -= iBytesRead;

				wcout << L"\rProgress: " << (((long long)(iFileSize - iBytesToRead) * 100) / iFileSize) << "% " << (iFileSize - iBytesToRead) / 1000 << L"/" << iFileSize / 1000 << L" KB";
			}

			//signal(SIGTERM, prev_handler);

			osFile.close();
			wcout << endl << L"Done." << endl;
		}
		else
		{
			while (socket->readline(buff, BUFFERSIZE) > 0)
			{
				wcout << buff << L"\n";
			}
		}
	}

	void interrupt(int param)
	{
		remove("test.exe");
	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}