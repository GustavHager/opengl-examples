#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include "RenderSystem.hpp"

#include <string> 

class Window{
public:
	Window(std::string window_name="w1n",int height=640, int width=480);
	~Window();
  void setRenderer(RenderSystem* renderer);
  void show(void);
  void setInputManager(void (*f)(GLFWwindow*,int,int,int,int) );
  GLFWwindow* getWindowHandle(void);
  bool windowShouldClose(void);
  void redraw(void);

private:
	const int height,width;
	const std::string window_name;
	GLFWwindow* window_handle;
  RenderSystem* renderer;
};

#endif
