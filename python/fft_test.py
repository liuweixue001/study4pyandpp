import numpy as np
import cv2
import matplotlib.pyplot as plt

def fourier_compress(image_path, compression_ratio=0.1):
    # 读取图像
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

    # 执行傅里叶变换
    f_transform = np.fft.fft2(img)
    f_shift = np.fft.fftshift(f_transform)

    # 获取图像大小
    rows, cols = img.shape

    # 计算中心频率
    center_row, center_col = rows // 2, cols // 2

    # 计算要保留的频率分量数目
    retain_rows = int(rows * compression_ratio)
    retain_cols = int(cols * compression_ratio)

    # 将保留的频率分量置零
    f_shift[center_row - retain_rows // 2:center_row + retain_rows // 2,
            center_col - retain_cols // 2:center_col + retain_cols // 2] = 0

    # 执行反傅里叶变换
    img_compressed = np.abs(np.fft.ifft2(np.fft.ifftshift(f_shift)))

    return img, img_compressed

# 选择一张图像进行压缩
image_path = 'path_to_your_image.jpg'

# 进行频域压缩
original_image, compressed_image = fourier_compress(image_path, compression_ratio=0.1)

# 显示原始图像和压缩后的图像
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.imshow(original_image, cmap='gray')
plt.title('Original Image')

plt.subplot(1, 2, 2)
plt.imshow(compressed_image, cmap='gray')
plt.title('Compressed Image')

plt.show()
