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

	// Сreating variables shapes and outputting information about them to the console.
	ShapePtr tr1(new TriangleDemo(50, 70, 100, new Point2D(10, 300)));
	std::cout << "Created triangle(50, 70, 100) " << *tr1 << std::endl;
	ShapePtr tr2(new TriangleDemo(100, 100, 141.43, new Point2D(80, 300)));
	std::cout << "Created triangle(100, 100, 141.43) " << *tr2 << std::endl;
	ShapePtr tr3(new TriangleDemo(70, 100, 100, new Point2D(200, 300)));
	std::cout << "Created triangle(70, 100, 100) " << *tr2 << std::endl;

	ShapePtr re1(new RectangleDemo(60, 120, new Point2D(290,300)));
	std::cout << "Created rectangle(60, 120) " << *re1 << std::endl;
	ShapePtr re2(new RectangleDemo(80, 80, new Point2D(370,300)));
	std::cout << "Created rectangle(80, 80) " << *re2 << std::endl;

	ShapePtr ci1(new CircleDemo(60, new Point2D(520, 240)));
	std::cout << "Created circle(radius 60, polygons default(10)) " << *ci1 << std::endl;
	ShapePtr ci2(new CircleDemo(70, 50, new Point2D(660, 230)));
	std::cout << "Created circle(radius 70, polygons 50) " << *ci2 << std::endl;


	// Creating a vector of pointers to Shapes
	std::vector<ShapePtr> shapesVector = {tr1, tr2, tr3, re1, re2, ci1, ci2};

	// Drawing to console.
	myDrawingLib::drawAllElements(shapesVector);


	_getch();

	return 0;



}



