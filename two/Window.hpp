#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

#include <string>

class Window{
public:
	Window(int height=640, int width=480,std::string window_name="w1n");
	~Window();

	void update();
private:
	const int height,width;
	const std::string name;
	GLFWwindow* window_handle;
};

#endif