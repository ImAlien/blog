#### 变量

```shell
# 等号前后不能有空格
name="cxl"
name2=$name
a = 3
readonly a
# 删除
unset a

read num1
read num2

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
a=(0 1 2 3 4 5) #创建， 空格分开，等号不要空格
${a[n]} # 下标没有限制
${a[@]} #所有数组元素
length = ${#a[@]} #长度只统计有值的下标数


```

#### 流程控制

```shell
if condition
then
	command1
	command2
else
	command3
fi

if [ $(ps -ef | grep -c "ssh") -gt 1 ]; then echo "true"; fi

a=10
b=20
if [ $a == $b ]
then
   echo "a 等于 b"
elif [ $a -gt $b ]
then
   echo "a 大于 b"
elif [ $a -lt $b ]
then
   echo "a 小于 b"
else
   echo "没有符合的条件"
fi
```

```shell
for val in t1 t2 t3 t4 #不能接数组
do
	command
done

for((i=1;i<=5;i++));do
    echo "这是第 $i 次调用";
done;
```

```shell
while condition
do
	command
done
```

#### 函数

```shell
funWithParam(){
    echo "第一个参数为 $1 !"
    echo "第二个参数为 $2 !"
    echo "第十个参数为 $10 !"
    echo "第十个参数为 ${10} !"
    echo "第十一个参数为 ${11} !"
    echo "参数总数有 $# 个!"
    echo "作为一个字符串输出所有参数 $* !"
}
```

