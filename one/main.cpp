#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <cstdio>

using namespace std;

//GLFW error callback, called on glfw errors
void error_callback(int error, const char* description){
  printf("%s\n",description);
}

//GLFW key callback, called on key events
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
    glfwSetWindowShouldClose(window,GL_TRUE);
  }
}

int main(){

  //init the GLFW library
  if(!glfwInit()){
    printf("GLFW init failed, exiting \n");
    exit(-1);
  }
  //tell GLFW where the error callback is
  glfwSetErrorCallback(error_callback);

  //create a window and an opengl context
  GLFWwindow* window = glfwCreateWindow(640,480,"w1n",NULL,NULL);

  //tell GLFW where the key callback is, so keypresses in the window are sent there
  glfwSetKeyCallback(window,key_callback);

  //make sure the window was created properly
  if(!window){
    glfwTerminate();
    printf("failed to create window, exiting\n");
    exit(-1);
  }

  //activate the windows opengl context
  glfwMakeContextCurrent(window);

  //run as long as the window is not closed
  while(!glfwWindowShouldClose(window)){
    float ratio;
    int width,height;
    
    ratio = (float)width / (float)height;
    glViewport(0,0,width,height);
    glClear(GL_COLOR_BUFFER_BIT);

    //code to draw stuff goes here..

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  //destroy the window
  glfwDestroyWindow(window);
  //shut down GLFW library
  glfwTerminate();
	return 0;
}
