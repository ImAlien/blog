```python

data = [[1,2],[3,4]]
xdata = torch.tensor(data)
#与numpy转换
np_array = np.array(data)
x_np = torch.from_numpy(np_array)
np_array = xdata.numpy()
# 相同维度
x_ones = torch.ones_like(x_data) # retains the properties of x_data
print(f"Ones Tensor: \n {x_ones} \n")
x_rand = torch.rand_like(x_data, dtype=torch.float) # overrides the datatype of x_data
print(f"Random Tensor: \n {x_rand} \n")

#自定义维度
shape = (2,3,)
rand_tensor = torch.rand(shape)
ones_tensor = torch.ones(shape)
zeros_tensor = torch.zeros(shape)
tensor = torch.rand(3,4) #直接
#属性
tensor.shape
tensor.dtype
tensor.device

#常用操作
# We move our tensor to the GPU if available
if torch.cuda.is_available():
  tensor = tensor.to('cuda')

y1 = tensor @ tensor.T
y2 = tensor.matmul(tensor.T) # 点乘
z1 = tensor * tensor
z2 = tensor.mul(tensor) #叉乘
tensor.add_(5) #自加,最后_
```

