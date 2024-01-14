import cv2
import numpy as np
from matplotlib import pyplot as plt

# 读取图像
image = cv2.imread('images/test.jpg', cv2.IMREAD_GRAYSCALE)

# 使用Sobel算子进行边缘检测
sobel_x = cv2.Sobel(image, cv2.CV_64F, 1, 0, ksize=3)
sobel_y = cv2.Sobel(image, cv2.CV_64F, 0, 1, ksize=3)

# 计算边缘梯度和方向
gradient_magnitude = np.sqrt(sobel_x**2 + sobel_y**2)
gradient_direction = np.arctan2(sobel_y, sobel_x)

# 显示原始图像和边缘检测结果
plt.subplot(2, 2, 1), plt.imshow(image, cmap='gray')
plt.title('Original Image'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 2, 2), plt.imshow(sobel_x, cmap='gray')
plt.title('Sobel X'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 2, 3), plt.imshow(sobel_y, cmap='gray')
plt.title('Sobel Y'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 2, 4), plt.imshow(gradient_direction, cmap='gray')
plt.title('Gradient Magnitude'), plt.xticks([]), plt.yticks([])

plt.show()
