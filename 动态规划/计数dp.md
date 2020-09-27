#### 方法一、完全背包法

```cpp
const int N = 1007;
int f[N];
signed main(){
    int n;
    cin >> n;
    f[0]=1;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++)
            f[j] += f[j - i], f[j]%= mod;
    }
    print(f[n]);
    return 0;
}
```

#### (其他状态表示的方法) O(n2)

状态表示：
f\[i][j]表示总和为i，总个数为j的方案数

状态转移方程：
f\[i][j]=f\[i−1][j−1]+f\[i−j][j];

```cpp
#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N][N];

int main()
{
    cin >> n;

    f[1][1] = 1;
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;

    //注意求和
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = (res + f[n][i]) % mod;

    cout << res << endl;

    return 0;
}
```

