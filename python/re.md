```python
## match 起始位置
matchObj = re.match(pattern, string, flags=0)
matchObj.span()
matchObj.group(1)
使用group(num) 或 groups() 匹配对象函数来获取匹配表达式。
## search  找到第一个位置
schobj = re.search(pattern, string, flags=0)
schobj.span()
schobj.group()
## sub
newstr = re.sub(pattern, repl, string, count=0, flags=0)

```



```python
#re.compile 函数
re.compile(pattern[, flags])
pattern : 一个字符串形式的正则表达式
flags : 可选，表示匹配模式，比如忽略大小写，多行模式等，具体参数为：
re.I 忽略大小写
re.L 表示特殊字符集 \w, \W, \b, \B, \s, \S 依赖于当前环境
re.M 多行模式
re.S 即为 . 并且包括换行符在内的任意字符（. 不包括换行符）
re.U 表示特殊字符集 \w, \W, \b, \B, \d, \D, \s, \S 依赖于 Unicode 字符属性数据库
re.X 为了增加可读性，忽略空格和 # 后面的注释

pat = re.compile()
str_list = pat.findall(str)


```

