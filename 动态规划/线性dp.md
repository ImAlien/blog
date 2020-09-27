##### 最长上升子序列

##### 最长公共子序列

```cpp
for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                f[i][j] = max(f[i-1][j-1]+1, f[i][j]);
            }
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
```

##### 编辑距离

```cpp
 //边界情况
    for(int i = 0; i <= m; i++) f[0][i] = i;
    for(int i = 0; i <= n; i++) f[i][0] = i;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            f[i][j] = min({f[i-1][j], f[i-1][j-1], f[i][j-1]})+1; //增删改操作
            if(a[i-1] == b[j-1]) f[i][j] = min(f[i-1][j-1], f[i][j]); //不操作
        }
```

