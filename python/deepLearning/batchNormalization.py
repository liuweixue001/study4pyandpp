import numpy as np

def batch_norm_forward(X, gamma, beta, epsilon=1e-5):
    # X: 输入数据，维度为 (N, D)，N 为批量大小，D 为特征维度
    # gamma: 缩放因子，维度为 (D,)
    # beta: 偏移项，维度为 (D,)
    # epsilon: 为了防止除零错误的小数值
    
    # 计算均值
    mean = np.mean(X, axis=0)
    print(f"mean = {mean}")
    # 计算方差
    var = np.var(X, axis=0)
    print(f"var = {var}")
    # 标准化
    X_normalized = (X - mean) / np.sqrt(var + epsilon)
    
    # 缩放和平移
    out = gamma * X_normalized + beta # 这里并不准确, gammashape为(c,), X_normalized(c, -1), 计算完成后再转为原先的维度
    
    # 返回结果和中间结果（用于反向传播）
    return out, X_normalized, mean, var

# 生成随机输入数据
np.random.seed(42)
X = np.array([34, 12, -3, 88, -12, 2, 1, -60, 22, -1, -23, 57]).reshape(3, 2, 2)

# 初始化缩放因子和偏移项
gamma = np.ones((X.shape[1], ))
beta = np.zeros((X.shape[1], ))

# 进行 Batch Normalization
output, _, _, _ = batch_norm_forward(X, gamma, beta)

# 打印结果
print("输入数据：")
print(X)
print("\nBatch Normalization 后的输出：")
print(output)
