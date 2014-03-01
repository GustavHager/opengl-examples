#include "Window.hpp"

//GLFW error callback, called on glfw errors
void glfw_error_callback(int error, const char* description){
  printf("%s\n",description);
}

//GLFW key callback, called on key events
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
  
}

int main(int argc, char** argv){

	//init the GLFW library
  if(!glfwInit()){
    printf("GLFW init failed, exiting \n");
    exit(-1);
  }

  //tell GLFW where the error callback is
  glfwSetErrorCallback(glfw_error_callback);


  while(!glfwWindowShouldClose(window)){
    float ratio;
    int width,height;
    glfwGetFramebufferSize(window,&width,&height);
    ratio = (float)width / (float)height;
    glViewport(0,0,width,height);
    glClear(GL_COLOR_BUFFER_BIT);

    //code to draw stuff goes here..

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
}