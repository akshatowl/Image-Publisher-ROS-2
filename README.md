# Image-Publisher-ROS-2
Image Publisher with ROS-2 and OpenCV C++

Loads an image penguin.png

Used ros2topic hz and ros2topic bw to verify, also saw the image load up in Rviz without any problems.

<b1> Requirements </b1>
  ROS-2 Humble source build on Ubuntu 20.04  
  Rviz dependencies   

<b2> Run it yourself </b2>

Clone the repository on your local machine  
'''
git clone   
'''  
If ROS-2 is built from source, clone this inside the src folder of the ROS-2 root folder.  
Make sure to build the new dependencies using colcon.

Running the node  

'''
rosrun image_publisher image_node  
'''
