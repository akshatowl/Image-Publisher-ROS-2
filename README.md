# Image-Publisher-ROS-2
Image Publisher with ROS-2 and OpenCV C++

Loads an image penguin.png  

Used ros2topic hz and ros2topic bw to verify, also saw the image load up in Rviz without any problems.

**Requirements**  
  ROS-2 Humble source build on Ubuntu 20.04    
  Rviz dependencies     

**Run it yourself**  

Clone the repository on your local machine    
```
git clone https://github.com/akshatowl/Image-Publisher-ROS-2.git   
``` 
If ROS-2 is built from source, clone this inside the src folder of the ROS-2 folder.    
Make sure to build the new dependencies using colcon before running.

Running the node  

```
rosrun image_publisher image_node  
```
