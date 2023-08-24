#include "myWindow.h"
#include <string>

int main()
{
	Screen myScreen;
	bool isTrue = false;
	std::string command;

	while (true)
	{
		std::cout << "Commands: \nMove\nResize\nDisplay\nClose." << std::endl;
		std::cout << "Enter the command: ";
		std::cin >> command;
		if (command == "Move" || command == "move")
		{
			while (!isTrue)
			{
				int x, y;
				std::cout << "Enter the coordinates: ";
				std::cin >> x >> y;
				isTrue = myScreen.move(x, y);
			}
		}
		else if (command == "Resize" || command == "resize")
		{
			while (!isTrue)
			{
				int x, y;
				std::cout << "Enter the width and height of the window: ";
				std::cin >> x >> y;
				isTrue = myScreen.resize(x, y);
			}
		}
		else if (command == "Display" || command == "display")
			myScreen.draw();
		else if (command == "Close" || command == "close") return 0;
	}
	
	return 0;
}
