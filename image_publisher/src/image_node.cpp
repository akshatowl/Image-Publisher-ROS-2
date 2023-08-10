#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <opencv2/opencv.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/hal/interface.h>
#include "cv_bridge/cv_bridge.h"
#include <image_transport/image_transport.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <std_msgs/msg/header.hpp>

using namespace std::chrono_literals;
using namespace std;

class image_publisher :public rclcpp::Node
{
  private:
  void callback()
  {
        cv_bridge::CvImagePtr cv_ptr;

           cv::Mat img=cv::imread("/home/esptguest/penguin.png");
        // cv::Mat img(cv::Size(512, 512), CV_8UC3);
        // cv::randu(img, cv::Scalar(0, 0, 0), cv::Scalar(255, 255, 255));
        
        sensor_msgs::msg::Image::SharedPtr msg =
            cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", img)
                .toImageMsg();

        image_pub->publish(*msg.get());
        cout << "Published!" << endl;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub;
  size_t count_;
  int data_block_size_;
  int delay_in_us_;

public:
image_publisher() : Node("image_publisher"), count_(0)
{
  image_pub=this->create_publisher<sensor_msgs::msg::Image>("image_topic",1);
  timer_ = this->create_wall_timer(33ms, bind(&image_publisher::callback, this));
}
  
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(make_shared<image_publisher>());
  rclcpp::shutdown();
  return 0;
}
