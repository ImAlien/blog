#### 计数问题

```cpp
const int N = 11;
int f[N]; // f[i] 表示i位数出现x的个数
int a[N];
ll qpow(int a, int b){//a 的 b次方
    ll ans = 1;
    while(b--){
        ans *= a;
    }
    return ans;
}
ll left(int pos){ //统计当前位数后面所剩的数字比如 53, 5后面的数字是3
    ll ans = 0;
    for(int i = pos -1; i >= 0; i--) ans = ans*10 + a[i];
    return ans;
}
ll dfs(int pos, bool lead, bool limit, int& ta){
    if(pos == -1) return 0;
    if(!lead && !limit && f[pos] != -1) return f[pos];
    ll ans = 0;
    int up = limit? a[pos]: 9;
    for(int i = 0; i <= up; i++){ 
        if(i == ta && (ta != 0 || ta == 0 && !lead)) {//统计0时不能有前导0
            if( limit && i == a[pos])
                ans+= left(pos) + 1; //出现次数是后面的数字加一
            else ans += qpow(10, pos);
        }
        ans += dfs(pos - 1, lead && i == 0, limit && i == a[pos], ta);
    }
    if(!limit && !lead) f[pos] = ans;
    return ans;
}
ll solve(int x, int v){
    int cnt = 0;
    while(x) a[cnt++] = x%10, x /= 10;
    return dfs(cnt-1, true, true,v);
}
```

#### [面试题 17.06. 2出现的次数](https://leetcode-cn.com/problems/number-of-2s-in-range-lcci/)

```cpp
int f[20];
int a[20];
class Solution {
public:
    int left[20], p[20];
    int dfs(int pos, bool limit){
        if(pos == -1) return 0;
        if(!limit && f[pos]!= -1) return f[pos];
        int up = limit? a[pos]:9;
        int ans = 0;
        for(int i = 0; i <= up; i++){
            if( i == 2){
                if(limit && i == a[pos]) //这个条件一定是同时出现
                    	ans += left[pos]+1;
                else ans += p[pos];
            }
            ans += dfs(pos-1, limit && i == a[pos]);
        }
        if(!limit) f[pos] = ans;
        return ans;
    }
    int solve(int n){
        int cnt = 0;
        while(n) a[cnt++] = n%10, n /= 10;
        long long t = 0;
        t = 1;
        for(int i = 0; i < cnt; i++){
            p[i] = t;
            t *= 10;
        }
        t = 0;
        for(int i = 0; i < cnt ; i++){
            left[i] = t;
            t += a[i]*p[i];
        }
        int ans = dfs(cnt-1, true);
        return ans;
    }
    int numberOf2sInRange(int n) {
        memset(f, -1, sizeof f);
        return solve(n);
    }
};
```

