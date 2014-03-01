#include "Window.hpp"

Window::Window(int height,int width,std::string window_name) : height(height), width(width), window_name(window_name){
	window_handle = glfwCreateWindow(height,width,window_name,NULL,NULL);

	if(!window_handle){
		printf("Failed to create window!");
		exit(-1);
	}
}

Window::~Window(){
	glfwDestroyWindow(window_handle);
}

void Window::update(){
	//call the asssinged draw function here.
}