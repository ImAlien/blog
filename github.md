## 创建一个本地文件夹到仓库

#### 参考：

#### https://juejin.im/post/5ceba62e6fb9a07ed36e8886

​	https://blog.csdn.net/solo_ws/article/details/77095901

```
…or create a new repository on the command line

echo "# blog" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/ImAlien/blog.git
git push -u origin master

…or push an existing repository from the command line

git remote add origin https://github.com/ImAlien/blog.git
git push -u origin master
```

