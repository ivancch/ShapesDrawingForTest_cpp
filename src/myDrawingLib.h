

#ifndef SHAPES_MYDRAWINGLIB_H_
#define SHAPES_MYDRAWINGLIB_H_

#include <windows.h>
#include <vector>
#include <cmath>

/**
 * The definition of pi, since such a definition was not in my compiler.
 */
#ifndef M_PI
#define M_PI (4*std::atan(1))
#endif /* M_PI */










#include <iostream>











namespace myDrawingLib
{

	/**
	 * This class is intended to return a handle to the console window, with a drawing context
	 * already created and a white non-transparent pen selected.
	 * In the descriptor releases all created objects and context.
	 * Non a singleton!
	 *
	 * This class needs to be optimized when creating a large number of objects!
	 */
	class Context
	{
	private:
		HWND m_hwnd = NULL;
		HDC m_hdc = NULL;
		HPEN m_pen = NULL;
	public:
		/**
		 * Creating a context. Read the class description.
		 */
		Context();

		/**
		 * @return[out] The return value is a handle to the window used by
		 * 				 the console associated with the calling process or
		 * 				 NULL if there is no such associated console.
		 */
		const HDC& getHDC() const ;

		virtual ~Context();
	};

	/**
	 * The function iterates through all the elements of the vector
	 * and calls the draw() function on each element.
	 * Please use this function only for classes that implement
	 * the "Shape" interface class.
	 *
	 * @tparam T type
	 * @param vec Vector
	 */


	template<typename T>
	void drawAllElements(const std::vector<T> &vec);


}

#endif /* SHAPES_MYDRAWINGLIB_H_ */

