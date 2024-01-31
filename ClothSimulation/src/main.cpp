#include <iostream>
#include <math.h>
#include "app.h"

int main(int argc, char* args[])
{
	application app;

	app.set_up();

	while (app.is_running())
	{
		app.input();
		app.update();
		app.render();
	}

	app.shutdown();

	return 0;
}

