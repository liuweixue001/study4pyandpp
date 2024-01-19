import torch

"""卷积层和bn层防fp16溢出映射,应结合卷积和bn层"""

x = torch.randn((1, 3, 224, 224))
testConv = torch.nn.Conv2d(3, 3, (3, 3), (1, 1)).eval()

def warp_conv(x, conv, factor: int=32):
    """(W*(x/p)+b)*p-b*(p-1) == Wx+b
    conv(x) == warp_conv(x, conv)
    """
    x_tmp = conv(x / factor)
    return factor * x_tmp - (factor - 1) * conv.bias.reshape(
        1, -1, 1, 1).repeat(1, 1, x_tmp.size(2), x_tmp.size(3))
    
    
def warp_bn(x, bn, factor: int=32):
    import torch
    scale = bn.weight / torch.sqrt(bn.running_var + bn.eps)
    bias = bn.bias - bn.running_mean * scale
    bias_t = bias.reshape(1, -1, 1, 1).repeat(1, 1, x.size(2), x.size(3))
    return bn(x / factor) * factor - (factor - 1) * bias_t

output1 = testConv(x)
output2 = warp_conv(x, testConv)

print(f"diff max = {torch.max(output1 - output2)}")
print(f"diff mean = {torch.mean(output1 - output2)}")