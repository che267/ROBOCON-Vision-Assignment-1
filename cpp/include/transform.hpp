#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

// 声明一个函数：将图像转为灰度并做边缘检测
cv::Mat processImage(const cv::Mat& input);

// 声明一个函数：处理视频
void processVideo(const std::string& inputPath, const std::string& outputPath);

#endif
