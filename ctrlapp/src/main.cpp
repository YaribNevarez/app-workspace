/*
 * Empty C++ Application
 */
#include "ctrlapp.hpp"
#include "framework/daemon.hpp"

int main(int argc, char * argv[])
{
	ControlApp app(argc, argv);

	Daemon::become(0);

	return app.run();
}
