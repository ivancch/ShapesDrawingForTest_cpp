

#ifndef SHAPES_MYDRAWINGLIB_H_
#define SHAPES_MYDRAWINGLIB_H_

#include <windows.h>

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
		HDC& getHDC();

		virtual ~Context();
	};

}

#endif /* SHAPES_MYDRAWINGLIB_H_ */

