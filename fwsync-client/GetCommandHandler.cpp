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
		std::string szFileName;

		char* buff = new char[BUFFERSIZE + 1];

		socket->readline(buff, BUFFERSIZE);
		
		int iFileSize = stoi(buff);

		if (iFileSize >= 0)
		{
			int iBytesToRead = iFileSize;

			ofstream osFile("test.test");


			while (iBytesToRead > 0)
			{
				iBytesToRead -= socket->read(buff, iBytesToRead > BUFFERSIZE ? BUFFERSIZE : iBytesToRead);
				osFile << buff;
				cout << "\rProgress: " << (iFileSize - iBytesToRead) / 1000 << "/" << iFileSize / 1000 << " KB";
			}

			osFile.close();
			cout << endl;
		}
		else
		{
			socket->readline(buff, BUFFERSIZE);
			cout << buff << "\n";
		}
		
		delete[] buff;
	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}