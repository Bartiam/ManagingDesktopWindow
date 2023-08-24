#include "myWindow.h"

void MyWindow::setX(const int& x) { this->x = x; }

void MyWindow::setY(const int& y) { this->y = y; }

int MyWindow::getX() { return x; }

int MyWindow::getY() { return y; }

int MyWindow::getWidth() { return width; }

int MyWindow::getHeight() { return height; }

void MyWindow::setWidth(const int& width) { this->width = width; }

void MyWindow::setHeight(const int& height) { this->height = height; }

void Screen::fillDisplay()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (i == 0 || i == 50 - 1 || j == 0 || j == 80 - 1)
				display[i][j] = '#';
			else display[i][j] = ' ';
		}
	}
	
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 80; j++)
		{
			if (i == myWindow.getY() && j >= myWindow.getX() && j <= (myWindow.getX() + myWindow.getWidth()))
				display[i][j] = 'O';
			else if (i == (myWindow.getY() + myWindow.getHeight()) && j >= myWindow.getX() && j <= (myWindow.getX() + myWindow.getWidth()))
				display[i][j] = 'O';
			else if (j == myWindow.getX() && i >= myWindow.getY() && i <= (myWindow.getY() + myWindow.getHeight()))
					display[i][j] = 'O';
			else if (j == (myWindow.getX() + myWindow.getWidth()) && i >= myWindow.getY() && i <= (myWindow.getY() + myWindow.getHeight()))
				display[i][j] = 'O';
		}
	}
}

void Screen::draw()
{
	system("cls");
	fillDisplay();
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 80; j++)
		{
			std::cout << display[i][j];
		}
		std::cout << std::endl;
	}
}

bool Screen::move(const int& x, const int& y)
{
	if (x < 0 || y < 0 || (x + myWindow.getWidth()) > 80 - 1 || (y + myWindow.getHeight()) > 50 - 1)
	{
		std::cerr << "Error! Incorrect input coordinates. Try again. " << std::endl; 
		return false;
	}
	myWindow.setX(x);
	myWindow.setY(y);

	std::cout << "Coordinates of the upper left corner of the window: " <<
		myWindow.getX() << " " << myWindow.getY() << "\nWindow width: " <<
		myWindow.getWidth() << "\nWindow height: " << myWindow.getHeight() << std::endl;
	return true;
}

bool Screen::resize(const int& width, const int& height)
{
	if (width < 0 || height < 0 || (width + myWindow.getX()) > 80 - 1 || (height + myWindow.getY()) > 50 - 1)
	{
		std::cerr << "Error! Incorrect input coordinates. Try again. " << std::endl;
		return false;
	}
	myWindow.setWidth(width);
	myWindow.setHeight(height);

	std::cout << "The currect width: " << myWindow.getWidth() << "\nHeight: " << myWindow.getHeight() << std::endl;

	return true;
}