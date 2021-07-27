#### 矩阵操作

```python
# 创建
l = [1,2,3,4]
z = np.array(l)
z = np.zeros((1,2))
z = np.ones((4, 3)) np.ones_like(a)
z = np.arange(9).reshape(3,3)
z = np.eye(10) # 10*10
Z = np.random.random((3,3,3))
np.full(shape, val)# 生成全为val
Z = np.random.uniform(0,10,(3,4))

z = np.diag(v, k = 0)
#https://numpy.org/doc/stable/reference/generated/numpy.diag.html
#If v is a 2-D array, return a copy of its k-th diagonal. If v is a 1-D array, return a 2-D array with v on the k-th diagonal.
#Use k>0 for diagonals above the main diagonal, and k<0 for diagonals below the main diagonal.

#将前一个矩阵repeat次数
a = np.array([[1,0],[0,1]])
z= np.tile(a, (2, 2))


```

#### 矩阵运算

```python
### 矩阵乘法
np.dot(A, B) 
A @ B
### 数乘: 对应相乘
A * B
np.multiply(A,B)  
### 其他运算
Z = np.arange(6).reshape((2,3))
Z ** Z
2 << Z
Z > Z*2
Z / 2
Z + 3
Z - 6
## 原地算法
np.add(A,B,out=B)
np.divide(A,2,out=A)
np.negative(A,out=A)
np.multiply(A,B,out=A)

#维度变换
.reshape(shape) : 不改变当前数组，依shape生成
.resize(shape) : 改变当前数组，依shape生成
.swapaxes(ax1, ax2) : 将两个维度调换
.flatten() : 对数组进行降维，返回折叠后的一位数组
```

逻辑运算

```python
a = [True, False, True]
b = [False, True, True]
np.bitwise_and(a, b) # [Flase, False, True]
np.bitwise_or(a, b)
```



#### 索引

切片(numpy中是引用，**python中是复制**)

```python
###### python规则
## 范围
z[0:3], z[-5:4], z[-10:5],z[-5:-1],默认是正着
# 缺省
#按照扩充索引范围的观点，start的缺省值是无穷小(​)，stop的缺省值是无穷大(​)。
z[:], z[-4:]
## 倒着
# start的缺省值是无穷大(​)，stop的缺省值是无穷小(​)
z[3:0:-1], z[::-1]
#跳着
z[1:6:2], z[1:7:3]


##下标可以是list，选取某几行
Z[[1,3], :]
```

bool索引

```python
a[a < 3] *= -1 # 引用
c = a[a < 3]  # 值传递
c *= -1
```



#### 查询

```python
#-------------属性
z.ndim
z.shape
z.size
z.itemsize #数据类型的字节数
z.dtype
#--------------数值
z.min()
z.max()
z.mean()
#standard deviation 标准差
z.std()
np.unravel_index(indices, shape)
# 找到对应下标在矩阵中的位置，矩阵是按行从上到下排列
np.unravel_index(1621, (6,7,8,9))
(3, 1, 4, 1)
#----------------查找
np.all(z > 0)
np.any(z < 0)
a = np.arange(10)
np.where(a < 5, a, 10*a) # 类似三目运算符
array([ 0,  1,  2,  3,  4, 50, 60, 70, 80, 90])
#交集
np.intersect1d([1, 3, 4, 3], [3, 1, 2, 1])
array([1, 3])
#多个
from functools import reduce
reduce(np.intersect1d, ([1, 3, 4, 3], [3, 1, 2, 1], [6, 3, 4, 2]))
array([3])
```

