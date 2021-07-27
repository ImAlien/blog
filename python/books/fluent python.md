[TOC]

### 第三部分 把函数视作对象

#### 第五章 一等函数

##### 5.1把函数视作对象

函数是function 的实例，用许多属性__

```python
f.__doc__ 
help(f) # 输出帮助文本

#可以进行赋值
def f2(int x):
    print(x)
f = f2
f(x)
```

##### 5.2高阶函数

接受函数为参数，或者把函数作为结果返回的函数是高阶函数

```python
#soted()函数的key参数
fruits = ['strawberry', 'fig', 'apple', 'cherry', 'raspberry', 'banana']
sorted(fruits, key=len)
['fig', 'apple', 'cherry', 'banana', 'raspberry', 'strawberry']

#map

list(map(fact, range(6))) 
[1, 1, 2, 6, 24, 120]
[fact(n) for n in range(6)] 
[1, 1, 2, 6, 24, 120]
#filter
list(map(factorial, filter(lambda n: n % 2, range(6)))) 
[1, 6, 120]
[factorial(n) for n in range(6) if n % 2]
[1, 6, 120]
#reduce
from functools import reduce
from operator import add
reduce(add, range(100))
4950
sum(range(100))
```

##### 5.3匿名函数

lambda 函数的定义体只能使用纯表达式。换句话说，
lambda 函数的定义体中不能赋值，也不能使用while 和try 等Python 语句。

一般在参数列表中用lambda函数

```python
fruits = ['strawberry', 'fig', 'apple', 'cherry', 'raspberry', 'banana']
sorted(fruits, key=lambda word: word[::-1])
['banana', 'apple', 'fig', 'raspberry', 'strawberry', 'cherry']
```

##### 5.4可调用对象

用户定义的函数
使用def 语句或lambda 表达式创建。

内置函数
使用C 语言（CPython）实现的函数，如len 或time.strftime。

内置方法
使用C 语言实现的方法，如dict.get。

方法
在类的定义体中定义的函数。

类
调用类时会运行类的\_\__new__ 方法创建一个实例，然后运行\_\_init__ 方法，初始化实
例，最后把实例返回给调用方。

类的实例
如果类定义了\_\_call__ 方法，那么它的实例可以作为函数调用。

生成器函数
使用yield 关键字的函数或方法。

```python
callable(str)
True
```

##### 5.5 用户定义的可调用类型

```python
class test():
    def __init__(self, l):
        self.data = list(l)

    def pick(self):
        try:
            return self.data.pop()
        except IndexError:
            raise LookupError('pick from empty list')

    def __call__(self):
        return self.pick()
t = test(range(5))
print(t.pick())
print(t())
```

##### 5.6函数内省

```python
dir(obj) # 列出对象的属性
```

![image-20210428154233649](https://i.loli.net/2021/04/28/PUaovWkB1uwM9Kh.png)

##### 5.7 定位参数和仅限关键字参数

```python
def tag(name, *content, cls=None, **attrs):
	"""生成一个或多个HTML标签"""
    if cls is not None:
    	attrs['class'] = cls
    if attrs:
    	attr_str = ''.join(' %s="%s"' % (attr, value)
    						for attr, value
    						in sorted(attrs.items()))
    else:
    attr_str = ''
    if content:
    	return '\n'.join('<%s%s>%s</%s>' %
    	(name, attr_str, c, name) for c in content)
    else:
    	return '<%s%s />' % (name, attr_str)
###name是位置参数，cls是仅限关键字参数，name也可以作为关键字参数
第一个参数后面的任意个参数会被*content 捕获，存入一个元组。
tag 函数签名中没有明确指定名称的关键字参数会被**attrs 捕获，存入一个字典。
def f(a, *, b):
  return a, b
f(1, b = 2) # 没有默认值则强制必须传入实参。
```

