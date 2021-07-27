```python

```

#### 时间元组

| 序号 | 属性     | 值                                   |
| :--- | :------- | :----------------------------------- |
| 0    | tm_year  | 2008                                 |
| 1    | tm_mon   | 1 到 12                              |
| 2    | tm_mday  | 1 到 31                              |
| 3    | tm_hour  | 0 到 23                              |
| 4    | tm_min   | 0 到 59                              |
| 5    | tm_sec   | 0 到 61 (60或61 是闰秒)              |
| 6    | tm_wday  | 0到6 (0是周一)                       |
| 7    | tm_yday  | 1 到 366(儒略历)                     |
| 8    | tm_isdst | -1, 0, 1, -1是决定是否为夏令时的旗帜 |

```python
time = time.time() #返回时间戳
localtime = time.localtime(time.time()) #时间元组
print ("本地时间为 :", localtime)

gmtime = time.gmtime() # 0时区时间元组
astime = time.asctime(localtime) #时间字符串
print(astime)
```

#### 格式化时间

```python
import time
 
# 格式化成2016-03-20 11:45:39形式
print (time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())) 
 
# 格式化成Sat Mar 28 22:24:24 2016形式
print (time.strftime("%a %b %d %H:%M:%S %Y", time.localtime())) 
  
# 将格式字符串为时间元组
a = "Sat Mar 28 22:24:24 2016"
print (time.strptime(a,"%a %b %d %H:%M:%S %Y"))
#转化为时间戳
print(time.mktime(time.localtime()))
```

#### 计时

```python
t0 = time.perf_counter()
t1 = time.process_time()

```

