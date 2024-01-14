import cv2
import numpy as np
import matplotlib.pyplot as plt

def canny_edge_detection(image_path, low_threshold, high_threshold):
    # 读取图像
    image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

    # 1. 高斯滤波
    blurred = cv2.GaussianBlur(image, (5, 5), 0)

    # 2. 计算图像梯度
    gradient_x = cv2.Sobel(blurred, cv2.CV_64F, 1, 0, ksize=3)
    gradient_y = cv2.Sobel(blurred, cv2.CV_64F, 0, 1, ksize=3)

    # 3. 计算梯度幅值和方向
    magnitude = np.sqrt(gradient_x**2 + gradient_y**2)
    angle = np.arctan2(gradient_y, gradient_x) * (180 / np.pi)

    # 4. 非极大值抑制
    non_maximized = np.zeros_like(magnitude)
    for i in range(1, magnitude.shape[0] - 1):
        for j in range(1, magnitude.shape[1] - 1):
            if (angle[i, j] <= 45 and angle[i, j] > -45) or (angle[i, j] > 135) or (angle[i, j] <= -135):
                if (magnitude[i, j] >= magnitude[i, j - 1]) and (magnitude[i, j] >= magnitude[i, j + 1]):
                    non_maximized[i, j] = magnitude[i, j]
            elif (angle[i, j] > 45 and angle[i, j] <= 135) or (angle[i, j] <= -45 and angle[i, j] > -135):
                if (magnitude[i, j] >= magnitude[i - 1, j]) and (magnitude[i, j] >= magnitude[i + 1, j]):
                    non_maximized[i, j] = magnitude[i, j]

    # 5. 边缘跟踪和双阈值处理
    edges = np.zeros_like(non_maximized)
    strong_edge_pixels = (non_maximized > high_threshold)
    weak_edge_pixels = (non_maximized >= low_threshold) & (non_maximized <= high_threshold)
    edges[strong_edge_pixels] = 255
    edges[weak_edge_pixels] = 50  # 可以根据需要调整弱边缘像素的值

    # 6. 使用滞后阈值进行边缘连接
    _, edges = cv2.threshold(edges, 50, 255, cv2.THRESH_BINARY)

    return edges

# 图像路径
image_path = "images/test.jpg"

# 设定低阈值和高阈值
low_threshold = 30
high_threshold = 100

# 执行 Canny 边缘检测
edges = canny_edge_detection(image_path, low_threshold, high_threshold)

# 显示结果
plt.imshow(edges, cmap='gray')
plt.title("Canny Edge Detection")
plt.show()
