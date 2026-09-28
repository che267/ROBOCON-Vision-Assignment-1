import cv2

def process_video(input_path, output_path):
    # 读取原始视频
    cap = cv2.VideoCapture(input_path)
    if not cap.isOpened():
        print(f"错误：无法打开视频文件 {input_path}")
        return

    # 获取视频参数
    fps = cap.get(cv2.CAP_PROP_FPS)
    width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    
    # 设置输出视频编码和参数
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter(output_path, fourcc, fps, (width, height))

    print("开始处理视频...")
    frame_count = 0

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        # 这里进行离线处理：比如转成灰度并加边缘检测
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 50, 150)
        
        # 把边缘检测结果转回三通道，方便写入视频
        processed_frame = cv2.cvtColor(edges, cv2.COLOR_GRAY2BGR)

        # 写入输出视频
        out.write(processed_frame)
        frame_count += 1

    # 释放资源
    cap.release()
    out.release()
    print(f"处理完成！共处理 {frame_count} 帧，输出文件：{output_path}")

if __name__ == "__main__":
    # 注意：输入路径是 Project A 生成的 raw_capture.mp4
    input_video = "test_video.mp4"
    output_video = "processed_output.mp4"
    process_video(input_video, output_video)
