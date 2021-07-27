#### 基础

```python
print (list)            # 输出完整列表
print (list[0])         # 输出列表第一个元素
print (list[1:3])       # 从第二个开始输出到第三个元素
print (list[2:])        # 输出从第三个元素开始的所有元素
print (tinylist * 2)    # 输出两次列表
print (list + tinylist) # 连接列表

##创建
l = list(map(int,input().split()))
test = [[0]*m for i in range(n)]
##增
l.append() # 末尾加元素；
l.extend() #末尾添加可迭代元素
l.insert(index, obj) 在index前插入obj
##删
l.pop(i) # 返回并删除第i个元素，i不写默认最后一个
l.remove(x) #函数用于移除列表中某个值的第一个匹配项。
del l[3]
https://www.zhihu.com/question/49098374
不建议在for循环中修改列表，否则将导致python难以跟踪其中的元素？python会在for循环中跟踪列表的元素吗？跟踪做什么？为什么又建议在while循环中修改列表，是因为while循环不会跟踪列表元素吗？
https://segmentfault.com/a/1190000007214571
用filter或者列表解析或者while语句：

##查
x in l
l.count()  #统计
l.index(x)  #查找第一个x的位置
```

#### 列表推导式

```python
s = "hello python"
l = [ord(x) for x in s]
l = [ord(x) for x int s if x > 'c']

```

#### 切片

```python

```

