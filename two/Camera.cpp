#include "Camera.hpp"

glm::mat4 Camera::getVMatrix(){
  glm::mat4 vMatrix = glm::mat4_cast(glm::conjugate(orientation)); 
 
  vMatrix[4][0] = -pos[0];
  vMatrix[4][1] = -pos[1];
  vMatrix[4][2] = -pos[2];
  vMatrix[4][3] = -pos[3];  
  
  return vMatrix;
}

void Camera::translate(glm::vec3 t){
  pos = pos + t;
}

void Camera::rotate(glm::quat r){
  //we guarantee that the orientation quaternion is
  //normalized by not allowing it to be modified
  //elsewhere
  orientation = orientation * glm::normalize(r) * glm::conjugate(orientation);
  orientation = glm::normalize(orientation);
}
