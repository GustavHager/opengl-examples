#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>


//GLFW error callback, called on glfw errors
void error_callback(int error, const char* description){
  printf(description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action int mods){
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
    glfwSetWindowShouldClose(window,GL_TRUE);
  }
}

int main(){

  //init the GLFW library
  if(!glfwinit()){
    printf("GLFW init failed, exiting \n");
    exit(-1);
  }
  //set the error callback
  glfwSetErrorCallback(error_callback);


  //create a window and an opengl context
  GLFWwindow* window = glfwCreateWindow(640,480,"w1n",NULL,NULL);
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
    //ruuuuuun!
  }

  //destroy the window
  glfwDestroyWindow(window);
  //shut down GLFW library
  glfwTerminate();
	return 0;
}
