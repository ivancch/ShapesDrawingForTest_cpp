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
#include <vector>
#include <memory>

#include "Point2D.h"
#include "shapes/RectangleDemo.h"
#include "shapes/TriangleDemo.h"
#include "shapes/CircleDemo.h"
#include "myDrawingLib.h"

int main(int argc, char *argv[])
{
	std::cout << "start test!" << std::endl;

	// Putting the current thread to sleep to fully load the console before
	// creating and drawing objects. 2 milliseconds.
	Sleep(2);

	std::shared_ptr<Shape> tr1(new TriangleDemo(100, 120, 180, new Point2D(200, 200)));
	tr1.get()->drow();

	std::shared_ptr<Shape> re1(new RectangleDemo(80, 120, new Point2D(200,200)));
	re1.get()->drow();

	std::shared_ptr<Shape> ci1(new CircleDemo(50, 10, new Point2D(200, 200)));
	ci1.get()->drow();
//
//	std::unique_ptr<Shape> ptr(tr1);
//	std::shared_ptr<Shape> ptr2 = tr1;
//
//	std::vector<std::shared_ptr<Shape>> shapesVector;
//	shapesVector.push_back(tr1);
//	shapesVector.push_back(re1);
//	shapesVector.push_back(ci1);
//
//	myDrawingLib::drawAllElements(shapesVector);


	std::cout << "end test!" << std::endl;
	_getch();

	return 0;



}













