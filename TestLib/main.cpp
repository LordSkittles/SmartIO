#define CATCH_CONFIG_RUNNER
#include "Catch.hpp"

#include <conio.h>

int main(int argc, char **argv)
{
	int result = Catch::Session().run(argc, argv);

	while (true)
	{
		if (kbhit())
			break;
	}

	return result;
}