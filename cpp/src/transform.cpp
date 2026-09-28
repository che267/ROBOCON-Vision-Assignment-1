#include "transform.hpp"

cv::Mat processImage(const cv::Mat& input) {
    cv::Mat gray, edges;
    // 转灰度
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    // Canny 边缘检测
    cv::Canny(gray, edges, 50, 150);
    // 转回三通道，方便写入视频
    cv::Mat output;
    cv::cvtColor(edges, output, cv::COLOR_GRAY2BGR);
    return output;
}

void processVideo(const std::string& inputPath, const std::string& outputPath) {
    cv::VideoCapture cap(inputPath);
    if (!cap.isOpened()) {
        std::cerr << "错误：无法打开视频文件 " << inputPath << std::endl;
        return;
    }

    int fps = cap.get(cv::CAP_PROP_FPS);
    if (fps == 0) fps = 30;
    int width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    cv::VideoWriter writer(outputPath, cv::VideoWriter::fourcc('m', 'p', '4', 'v'), fps, cv::Size(width, height));

    cv::Mat frame;
    int count = 0;
    std::cout << "开始处理视频..." << std::endl;
    while (cap.read(frame)) {
        cv::Mat processed = processImage(frame);
        writer.write(processed);
        count++;
    }
    cap.release();
    writer.release();
    std::cout << "处理完成！共处理 " << count << " 帧，输出文件：" << outputPath << std::endl;
}
