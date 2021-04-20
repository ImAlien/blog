#### 参考

https://www.jianshu.com/p/f05d33475c78

#### urllib.request

urllib中，`request`这个模块主要负责构造和发起网络请求，并在其中加入Headers、Proxy等。

```python
## get
from urllib import request
resp = request.urlopen('http://www.baidu.com')
print(resp.read().decode())
访问的结果会是一个http.client.HTTPResponse对象，使用此对象的read()方法，则可以获取访问网页获得的数据。但是要注意的是，获得的数据会是bytes的二进制格式，所以需要decode()一下，转换成字符串格式。

## post
from urllib import request
resp = request.urlopen('http://httpbin.org/post', data=b'word=hello', timeout=10)
print(resp.read().decode())

##添加headers
from urllib import request
url = 'http://httpbin.org/get'
## f12查看
headers = {'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.181 Safari/537.36'}
# 需要使用url和headers生成一个Request对象，然后将其传入urlopen方法中
req = request.Request(url, headers=headers)
resp = request.urlopen(req)
print(resp.read().decode())
```

cookie

```python
from http import cookiejar
from urllib import request

url = 'https://www.baidu.com'
# 创建一个cookiejar对象
cookie = cookiejar.CookieJar()
# 使用HTTPCookieProcessor创建cookie处理器
cookies = request.HTTPCookieProcessor(cookie)
# 并以它为参数创建Opener对象
opener = request.build_opener(cookies)
# 使用这个opener来发起请求
resp = opener.open(url)

# 查看之前的cookie对象，则可以看到访问百度获得的cookie
for i in cookie:
    print(i)
```

