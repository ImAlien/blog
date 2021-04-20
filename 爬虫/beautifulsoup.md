#### 创建beautifulsoup对象

```python
#创建Beautiful Soup对象
soup = BeautifulSoup(html,'lxml')
soup = BeautifulSoup(open(test.html),'lxml')
## 输出
print(soup.prettify())
```

#### 四大对象

 Beautiful Soup将复杂HTML文档转换成一个复杂的树形结构,每个节点都是Python对象,所有对象可以归纳为4种:

(1) tag

```python
print(soup.title)
#<title>Jack_Cui</title>
print(soup.head)
#<head> <title>Jack_Cui</title></head>
print(soup.a)
#<a class="sister" href="http://blog.csdn.net/c406495762/article/details/58716886" id="link1">Python3网络爬虫(一)：利用urllib进行简单的网页抓取</a>
print(soup.p)
#<p class="title" name="blog"><b>My Blog</b></p>
查找的是在所有内容中的第一个符合要求的标签

#对于Tag，有几个重要的属性：name和attrs，text
name 就是标签名
attrs是一个字典
print(soup.a['class'])
print(soup.a.get('class'))
#['sister']
tag.text # 标签内的文字
```

**(2)NavigableString**

```python
print(soup.title.string)
#Jack_Cui
```

**(3)BeautifulSoup**

 BeautifulSoup 对象表示的是一个文档的全部内容.大部分时候,可以把它当作 Tag 对象，是一个特殊的 Tag，我们可以分别获取它的类型，名称，以及属性：

```python
print(type(soup.name))
print(soup.name)
print(soup.attrs)
#<class 'str'>
#[document]
#{}
```

**(4)Comment**

  Comment对象是一个特殊类型的NavigableString对象，其实输出的内容仍然不包括注释符号，但是如果不好好处理它，可能会对我们的文本处理造成意想不到的麻烦。

```python
print(soup.li)
print(soup.li.string)
print(type(soup.li.string))
#<li><!--注释--></li>
#注释
#<class 'bs4.element.Comment'>
```

#### 遍历搜索

```python
## 子节点
tag的content属性可以将tag的子节点以列表的方式输出：
输出方式为列表，我们可以用列表索引来获取它的某一个元素：

for child in soup.body.children:
     print(child)
## 搜索
find_all(name, attrs, recursive, text, limit, **kwargs)
##find_all() 方法搜索当前tag的所有tag子节点,并判断是否符合过滤器的条件。
name参数：
可以传递字符串，正则，列表(表示多中选一)
attrs参数：包含特殊属性的tag
print(soup.find_all(attrs={"class":"title"}))
recursive参数: 
false时只查找子节点
text参数：
可以传递字符串，正则，列表(表示多中选一)
limit参数:
搜索数量
kwargs参数:
print(soup.find_all(class_="title"))
#[<p class="title" name="blog"><b>My Blog</b></p>]
```

