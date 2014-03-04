#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"

/*
* Class to represent a camera, to move it around the world
* and to extract the camera matrix. Nothing fancy.
*/

//TODO implement some kind of distortion?

class Camera{
public:
  Camera(glm::vec3 pos = glm::vec3(0.0,0.0,0.0),
         glm::quat orientation = glm::quat()) : pos(pos), orientation(orientation){ }
    
  glm::mat4 getVMatrix();
  
  void translate(glm::vec3 t);
  void rotate(glm::quat r); 

private:
  glm::vec3 pos;
  glm::quat orientation;

};

#endif
