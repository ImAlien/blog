#### 创建bitset

```cpp
bitset<16> foo; //全0
bitset<16> bar (0xfa2);
bitset<16> b(43);
bitset<16> baz (std::string("0101111001"));
```

#### 统计其中的0和1

```cpp
all() 是否全是1
none() 是否全是0
any() 是否有1
count() 其中1的个数
size() bitset的位数
```
#### 改变其中0和1
```cpp
用[] ,位数从0到 size() - 1
reset(size_t pos) //把某位置0,无参数把所有置0
set(size_t pos) //把某位置1，无参数把所有置1
flip(size_t pos) //把某位反转，无参数把所有位反转
```
#### 转成其他类型
```cpp
to_string()
to_ullong()
to_ulong()
```

#### 运算符

```cpp
~, &, |, ^
    >>, <<
    ==, !=
```

