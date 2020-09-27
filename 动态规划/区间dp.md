##### 石子合并

```cpp
for(int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i-1];
    for(int len = 2; len <= n; len++)
        for(int i = 1; i + len-1 <= n; i++){
            int j = i + len - 1;
            f[i][j] = inf;
            for(int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + s[j] - s[i-1]);
        }
```

