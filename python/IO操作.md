打开文件

```python
file object = open(file_name [, access_mode][, buffering])
fileObject.write(string)

##中文
f = open(file_name, 'w', encoding = "utf-8")
```

![image-20210414205345784](https://i.loli.net/2021/04/14/tkRQcWu9UgYN2hv.png)



读取数据

```python
path =  'ex1data1.txt'
data = pd.read_csv(path, header=None, names=['Population', 'Profit'])
print(data.head())


```

