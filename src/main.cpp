//============================================================================
// Name        : ShapsDrawingForTest
// Author      : ivan-ch
// Version     : 0.0.1
// Copyright   :
// Description : Drawing shapes for test assignment in C++
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
#include <windows.h>

#include "shapes/Triangle.h"
#include "Point2D.h"

int main(int argc, char *argv[])
{
	std::cout << "start test!" << std::endl;

	// Putting the current thread to sleep to fully load the console before
	// creating and drawing objects. 2 milliseconds.
	Sleep(2);

	Shape* tr1 = new Triangle(100, 120, 180, new Point2D(200, 200));
	tr1->drow();
	if(tr1) delete tr1;


	std::cout << "end test!" << std::endl;
	_getch();

	return 0;



}













