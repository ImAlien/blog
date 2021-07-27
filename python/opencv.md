#### 基本处理

##### 读取图像

读取后是numpy的多维数组

```python
cv2.imread('path')
# 读取单通道
gray_img=cv2.imread('4.jpg',cv2.IMREAD_GRAYSCALE)
print(gray_img.shape)
# 直接彩色图像是1， 灰度图像是0
```

##### 存储图像

```python
# 指定jpg质量，范围从1~100，默认95，值越高画质越好，文件越大
cv2.imwrite('anglababy.jpg',color_img,(cv2.IMWRITE_JPEG_QUALITY,20))

cv2.imshow('name', pic)
cv2.waitKey (0) #一直显示
cv.destroyAllWindows()
```

##### 缩放，裁剪，补边

```python
# 缩小为200x200的正方形
img_200x200=cv2.resize(img,(200,200))

# 不直接指定缩放后的大小，通过fx和fy指定缩放比例，0.5表示长宽各一半
# 插值方法默认为cv2.INTER_LINEAR,这里指定为最近邻插值
img_half=cv2.resize(img,(0,0),fx=0.5,fy=0.5,interpolation=cv2.INTER_NEAREST)

# 转格式
cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
```

##### 翻转

```python
import cv2
image = cv2.imread("girl.jpg")

# Flipped Horizontally 水平翻转
h_flip = cv2.flip(image, 1)
cv2.imwrite("girl-h.jpg", h_flip)

# Flipped Vertically 垂直翻转
v_flip = cv2.flip(image, 0)
cv2.imwrite("girl-v.jpg", v_flip)

# Flipped Horizontally & Vertically 水平垂直翻转
hv_flip = cv2.flip(image, -1)
cv2.imwrite("girl-hv.jpg", hv_flip)
```

#### 图象处理

##### 边缘检测

关于2个阈值参数：

1. 低于阈值1的像素点会被认为不是边缘；
2. 高于阈值2的像素点会被认为是边缘；
3. 在阈值1和阈值2之间的像素点,若与第2步得到的边缘像素点相邻，则被认为是边缘，否则被认为不是边缘。

```python
import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt
img = cv.imread('mikasa.jpg',0)
edges = cv.Canny(img,50,100)
plt.subplot(121),plt.imshow(img,cmap = 'gray')
plt.title('Original Image'), plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(edges,cmap = 'gray')
plt.title('Edge Image'), plt.xticks([]), plt.yticks([])
cv.imwrite('mikasa_process.jpg',edges)
plt.show()
```

