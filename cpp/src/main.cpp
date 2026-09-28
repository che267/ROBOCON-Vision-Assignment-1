#include "transform.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "用法: " << argv[0] << " <输入视频路径> <输出视频路径>" << std::endl;
        return -1;
    }

    std::string inputVideo = argv[1];
    std::string outputVideo = argv[2];

    std::cout << "输入视频: " << inputVideo << std::endl;
    std::cout << "输出视频: " << outputVideo << std::endl;

    processVideo(inputVideo, outputVideo);
    return 0;
}
