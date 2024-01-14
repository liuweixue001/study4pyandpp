import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.onnx
import onnxruntime as ort
import numpy as np
import cv2


def Pad(h, w):
    m_pad = nn.Conv2d(in_channels=1, out_channels=1,kernel_size=(1,1),stride=(1,1),padding=(h, w))
    nn.init.constant_(m_pad.weight, 1.0)
    nn.init.constant_(m_pad.bias, 0.0)
    return m_pad

class SimpleCNN(nn.Module):
    def __init__(self):
        super(SimpleCNN, self).__init__()
        self.conv1 = nn.Conv2d(1, 32, kernel_size=3, stride=1, padding=1)
        self.pool = nn.MaxPool2d(kernel_size=2, stride=2, padding=0)
        self.fc = nn.Linear(32 * 14 * 14, 10)
        
    def forward(self, x, size, pad):
        x = F.interpolate(x, size=(size[0, 0], size[0, 1]), mode='bilinear', align_corners=False)
        # x = Pad(pad[0], pad[1])(x)
        x = F.pad(x, pad=(pad[0, 1], pad[0, 1], pad[0, 0], pad[0, 0]), mode='constant', value=114)
        print(x.shape)
        x = self.conv1(x)
        x = F.relu(x)
        x = self.pool(x)
        x = x.view(-1, 32 * 14 * 14)
        x = self.fc(x)
        return x

if __name__ == "__main__":

    EXPORT = 0
    CONV2D = 0
    INTERPOLATE = 0
    PAD = 0
    
if EXPORT:

    input = torch.randn(1, 1, 56, 48) 
    size = (torch.Tensor([[28, 24]]).to(torch.long))
    pad = (torch.Tensor([[0, 2]]).to(torch.long))

    example_input = (input, size, pad)

    model = SimpleCNN()
    model.eval()

    output = model(input, size, pad)

    print(output)

    onnx_filename = "simple_cnn.onnx"
    torch.onnx.export(model, 
                    example_input, 
                    onnx_filename, 
                    input_names=["input", "size", "pad"],
                    verbose=False, 
                    opset_version=13,
                    dynamic_axes={"input": {2:"img_h", 3:"img_w"}}
                    )
    print(f"Model exported to {onnx_filename}")

    ort_session = ort.InferenceSession(onnx_filename)

    input_data = input.numpy()  

    size = np.array([[28, 26]], dtype=np.int64)
    pad = np.array([[0, 1]], dtype=np.int64)


    output = ort_session.run(None, {"input": input_data, "size": size, "pad": pad})

    print("Model Output:", output)
    
elif CONV2D:
    a = torch.ones(1, 1, 3, 3)
    m_pad = nn.Conv2d(in_channels=1, out_channels=1,kernel_size=(1,1),stride=(1,1),padding=(0, 1))
    nn.init.constant_(m_pad.weight, 1.0)
    nn.init.constant_(m_pad.bias, 0.0)
    b = m_pad(a)

    print(a)
    print(b)

elif INTERPOLATE:
    img = cv2.imread("images/test.jpg")
    b_cv = cv2.resize(img, (50, 50))
    b_interpolate = F.interpolate(torch.from_numpy(img/255)[None,...].permute(0, 3, 1, 2), size=(50, 50), mode='bilinear', align_corners=False)
    b_interpolate = b_interpolate.permute(0, 2, 3, 1).numpy()[0] * 255
    print(np.max(np.abs(b_cv - b_interpolate)))


elif PAD:
    a = torch.ones(1, 1, 3, 3)
    b = F.pad(a, pad=(1, 2, 3, 4), mode='constant', value=114)
    print(a)
    print(b)

else:
    print("set one of (EXPORT/CONV2D/INTERPOLATE/PAD) = 1")