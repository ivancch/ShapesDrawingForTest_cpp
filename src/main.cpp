//============================================================================
// Name        : ShapesDrawingForTest
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



typedef std::shared_ptr<Shape> ShapePtr;

int main(int argc, char *argv[])
{
	// Putting the current thread to sleep to fully load the console before
	// creating and drawing objects. 10 milliseconds.
	Sleep(10);

	// Creating a vector of pointers to Shapes
	std::vector<ShapePtr> shapesVector{};
	shapesVector.push_back(ShapePtr(new TriangleDemo(50, 70, 100, new Point2D(10, 300))));
	shapesVector.push_back(ShapePtr(new TriangleDemo(100, 100, 141.43, new Point2D(80, 300))));
	shapesVector.push_back(ShapePtr(new TriangleDemo(70, 100, 100, new Point2D(200, 300))));
	shapesVector.push_back(ShapePtr(new RectangleDemo(60, 120, new Point2D(290,300))));
	shapesVector.push_back(ShapePtr(new RectangleDemo(80, 80, new Point2D(370,300))));
	shapesVector.push_back(ShapePtr(new CircleDemo(60, new Point2D(520, 240))));
	shapesVector.push_back(ShapePtr(new CircleDemo(70, 50, new Point2D(660, 230))));

	// Outputting information about shapes to the console.
	for (size_t index = 0; index < shapesVector.size(); index++)
			std::cout << "Created " << *shapesVector[index] << std::endl;

	// Drawing to console.
	myDrawingLib::drawAllElements(shapesVector);

	_getch();

	return 0;



}



