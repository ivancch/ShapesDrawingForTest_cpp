

#include <windows.h>
#include "myDrawingLib.h"

myDrawingLib::Context::Context()
{
	m_hwnd = GetConsoleWindow(); // Loading the handle of the current window
	m_hdc = GetDC(m_hwnd);			// Getting the context for drawing
	m_pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // Create a white pen
	SelectObject(m_hdc, m_pen);  // Putting the white pen into the drawing context
}


myDrawingLib::Context::~Context()
{
	ReleaseDC(m_hwnd, m_hdc);    // Release the drawing context
	DeleteObject(m_pen);     // Delete the created pen
}

const HDC& myDrawingLib::Context::getHDC() const
{
	return m_hdc;
}


#include <iostream>

template<typename T>
void myDrawingLib::drawAllElements(const std::vector<T> &vec)
{
	for (const T &element : vec)
	{
		std::cout << *element << '\n';
	}
		std::cout << '\n';
}
