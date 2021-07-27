```bash
netstat -ano|findstr "8080" # 查看80端口被哪些占用

tasklist|findstr "1828" # 根据进程id找到进程

#终止进程
taskkill /f /pid 1828
taskkill /f /t /im java.exe
```

```shell
# 中文乱码  
chcp 65001
```



