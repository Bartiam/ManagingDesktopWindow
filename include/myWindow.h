#pragma once
#include <iostream>

class MyWindow
{
private:
	int x = 2;
	int y = 2;
	int width = 2;
	int height = 2;
public:
	void setX(const int& x);
	void setY(const int& y);
	int getX();
	int getY();

	int getWidth();
	int getHeight();
	void setWidth(const int& width);
	void setHeight(const int& height);
};

class Screen
{
private:
	MyWindow myWindow;
	char display[50][80];
	void fillDisplay();
public:
	void draw();
	bool move(const int& x, const int& y);
	bool resize(const int& width, const int& height);
};