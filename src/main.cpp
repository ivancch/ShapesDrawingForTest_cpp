//============================================================================
// Name        : ShapsDrawingForTest
// Author      : ivan-ch
// Version     : 0.0.1
// Copyright   :
// Description : Drawing shapes for test assignment in C++
//============================================================================

#include <iostream>
#include <conio.h>
#include <windows.h>

void drowLineInConsole();

int main(int argc, char *argv[])
{
	std::cout << "test!" << std::endl;
	Sleep(50);


	drowLineInConsole();


	_getch();

	return 0;



}

void drowLineInConsole()
{
	HWND hwnd = GetConsoleWindow(); // Loading the handle of the current window
	HDC hdc = GetDC(hwnd);			// Getting the context for drawing
    HPEN pen1 = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // Create a white pen
    SelectObject(hdc, pen1);  // Putting the white pen into the drawing context
    MoveToEx(hdc, 100, 100, NULL); // Move the starting point to the specified position
    LineTo(hdc,200,200);    // Draw a line
    ReleaseDC(hwnd,hdc);    // Release the drawing context
    DeleteObject(pen1);     // Delete the created pen
}
