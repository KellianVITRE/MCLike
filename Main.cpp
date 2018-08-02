#include "Application.h"

int main() {

	Application* app = new Application(800, 600, 60);

	app->run();

	system("PAUSE");

	return 0;
}