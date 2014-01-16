#include "GetCommandHandler.h"
namespace fwsync
{

	GetCommandHandler GetCommandHandler::m_getCmdHandler(std::string("get"));

	GetCommandHandler::GetCommandHandler(std::string sCommand) : CommandHandler(sCommand)
	{

	}

	GetCommandHandler::GetCommandHandler()
	{

	}

	void GetCommandHandler::process(ClientSocket* socket, std::vector<std::string>& params)
	{
		if (params.size() != 3)
			throw("Syntax error");

		std::string szFileName;

		char* buff = new char[BUFFERSIZE + 1];

		socket->readline(buff, BUFFERSIZE);
		
		int iFileSize = stoi(buff);

		if (iFileSize >= 0)
		{
			int iBytesToRead = iFileSize;

			ofstream osFile(params[2], ofstream::binary | ofstream::trunc);
			
			if (osFile.bad())
			{
				delete[] buff;
				throw("Cannot open file for writing");
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
					delete[] buff;
					throw ex;
				}
	
				osFile.write(buff, iBytesRead);
				
				iBytesToRead -= iBytesRead;

				cout << "\rProgress: " << (((long long)(iFileSize - iBytesToRead) * 100) / iFileSize) << "% " << (iFileSize - iBytesToRead) / 1000 << "/" << iFileSize / 1000 << " KB";
			}

			//signal(SIGTERM, prev_handler);

			osFile.close();
			cout << endl << "Done." << endl;
		}
		else
		{
			while (socket->readline(buff, BUFFERSIZE) > 0)
			{
				cout << buff << "\n";
			}
		}
		
		delete[] buff;
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