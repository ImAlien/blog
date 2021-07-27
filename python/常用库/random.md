#### 生成数

```python
random.random() # 0-1随机数

random.randint(a, b) # [a, b]

```

#### 返回列表中的对象

```python
mylist = ["apple", "banana", "cherry"]
print(random.choice(mylist))

print(random.choices(mylist, weights = [10, 1, 1], k = 14))
# weights is the  the possibility for each value
# k is the length of return list

random.sample()
```

