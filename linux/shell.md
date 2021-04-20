#### 变量

```shell
# 等号前后不能有空格
name="cxl"
name2=$name
a = 3
readonly a
# 删除
unset a

```

#### 字符串

单引号字符串的限制：

- 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的；
- 单引号字串中不能出现单独一个的单引号（对单引号使用转义符后也不行），但可成对出现，作为字符串拼接使用。

```shell
str = 'this is a string'
```

双引号的优点：

- 双引号里可以有变量
- 双引号里可以出现转义字符

```
your_name='runoob'
str="Hello, I know you are \"$your_name\"! \n"
echo -e $str
```

拼接字符串

```shell
your_name="runoob"
# 使用双引号拼接
greeting="hello, "$your_name" !"
greeting_1="hello, ${your_name} !"
echo $greeting  $greeting_1
# 使用单引号拼接
greeting_2='hello, '$your_name' !'
greeting_3='hello, ${your_name} !'
echo $greeting_2  $greeting_3

hello, runoob ! hello, runoob !
hello, runoob ! hello, ${your_name} !
```

字符串长度

```shell
string="abcd"
echo ${#string} #输出 4
```

子串

```
string="runoob is a great site"
echo ${string:1:4} # 输出 unoo
```

查找

```shell
echo `expr index "hello world" oi`
```

#### 数组

```shell
a = (0, 1, 2, 3, 4, 5)
${a[n]}
${a[@]}
length = ${#a[@]}

```

