https://docs.python.org/zh-cn/3/howto/argparse.html#id1

```python
import argparse
parser = argparse.ArgumentParser() # 创建

parser.add_argument("echo", help ="echo the string you use here")  # 增加一个必须的参数

parser.add_argument("-square", help="display a square of a given number",type=int) # 变量前面加-，变为可选参数

parser.add_argument("-v", "--verbose", help="increase output verbosity",action="store_true") # 短版本，action表示存在则真,不存在则假

args = parser.parse_args()

if args.verbose:
    print("verbosity turned on")
print(args.square**2)
print(args.echo)
```

#### add_argument()方法详解

acction

```python
## 默认储存值,消耗一个命令行参数
parser.add_argument('--foo')
parser.parse_args('--foo 1'.split())
Namespace(foo='1')
## store_const,不消耗
parser.add_argument('--foo', action='store_const', const=42)
parser.parse_args(['--foo'])
Namespace(foo=42)
## store_true, 出现就设置为true,不消耗命令行参数
parser = argparse.ArgumentParser()
parser.add_argument('--foo', action='store_true')
parser.add_argument('--bar', action='store_false')
parser.add_argument('--baz', action='store_false')
parser.parse_args('--foo --bar'.split())
Namespace(foo=True, bar=False, baz=True)
###count 统计次数，不消耗命令行参数
parser = argparse.ArgumentParser()
parser.add_argument('--verbose', '-v',action='count',default=0)
parser.parse_args(['-vvv'])
Namespace(verbose=3)
```

nargs

```python

```



