| libfacedetection v1（caffe）   | 0.65      | 0.5       | 0.233     |
| ------------------------------ | --------- | --------- | --------- |
| libfacedetection v2（caffe）   | 0.714     | 0.585     | 0.306     |
| version-slim(原版)             | 0.765     | 0.662     | 0.385     |
| version-RFB(原版)              | 0.784     | 0.688     | **0.418** |
| version-slim(our)              | 0.795     | 0.683     | 0.34.5    |
| version-RFB(our)               | **0.814** | **0.710** | 0.363     |
| Retinaface-Mobilenet-0.25(our) | 0.811     | 0.697     | 0.376     |

对于每个候选窗口，预测它与最近的样本真实值(ground truth，在有监督学习中，Ground Truth通常指代样本集中的标签)之间的偏移量（即边界框的左边、顶部、高度和宽度）。这是一个回归问题。对于每个样本![[公式]](https://www.zhihu.com/equation?tex=x_i)，使用欧式距离来度量损失：

其中，![[公式]](https://www.zhihu.com/equation?tex=\hat{y}_i^{box})是网络预测的回归结果，![[公式]](https://www.zhihu.com/equation?tex=y_i^{box})是样本真实值的坐标（包含四个维度：左边、顶部、高度和宽度，因此是一个四维向量）。