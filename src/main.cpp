//============================================================================
// Name        : ShapsDrawingForTest
// Author      : ivan-ch
// Version     : 0.0.1
// Copyright   :
// Description : Drawing shapes for test assignment in C++.
//
// 				 To correctly compile the code, you need to add "-lgdi32"
//				 to the end for the linker. The code will only compile
//				 on Windows due to the use of the Windows API.
//
//				 To complicate the example from the windowsAPI,
//				 only drawing straight lines was used.
//============================================================================

/**
 * Задание такое:
 * Необходимо привести пример программы или библиотеки на C++,
 * которая выводит на экран различные геометрические фигуры: круг, квадрат,
 * треугольник, прямоугольник и т.п.
 * Глубина проработки примера (количество фигур, параметры, методы)
 * на Ваше усмотрение.
 * Программа не обязательно должна запускаться и работать (хотя это будет плюсом).
 *
 * В задании Вам необходимо продемонстрировать умение использовать ООП.
 * Просим не пользоваться библиотекой QT при выполнении задания.
 */
#include <iostream>
#include <conio.h>

#include "shapes/Triangle.h"
#include "shapes/Rectangle.h"
#include "Point2D.h"

int main(int argc, char *argv[])
{
	std::cout << "start test!" << std::endl;

	// Putting the current thread to sleep to fully load the console before
	// creating and drawing objects. 2 milliseconds.
	Sleep(2);

//	Shape *tr1 = new TriangleDemo(100, 120, 180, new Point2D(200, 200));
//	tr1->drow();
//	if(tr1) delete tr1;

	Shape *re1 = new RectangleDemo(80, 120, new Point2D(200,200));
	re1->drow();
	if(re1) delete re1;

//	Rectangle



	std::cout << "end test!" << std::endl;
	_getch();

	return 0;



}













