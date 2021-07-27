![image-20210414215520595](https://i.loli.net/2021/04/14/LzacI6gGDhkmONi.png)

#### 文档

https://docs.python-requests.org/zh_CN/latest/

#### get

```python
headers = {'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.181 Safari/537.36'}
r = requests.get(url, headers=headers)
```



#### post

```python
payload = {'key1': 'value1', 'key2': 'value2'}
payload = (('key1', 'value1'), ('key1', 'value2'))
r = requests.post("http://httpbin.org/post", data=payload)
print(r.text)

```

#### 传递url

```python
payload = {'key1': 'value1', 'key2': 'value2'}
r = requests.get("http://httpbin.org/get", params=payload)

http://httpbin.org/get?key2=value2&key1=value1
```

#### 内容

```python
r.text
```

#### cookie

```python
url = 'http://httpbin.org/cookies'
cookies = dict(cookies_are='working')

r = requests.get(url, cookies=cookies)
r.text
```

