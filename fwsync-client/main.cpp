#include "fwsync-client.h"

using namespace fwsync;

int main()
{
	Client* client = new Client();

	client->connect("localhost", 1080);

	return 0;
}
