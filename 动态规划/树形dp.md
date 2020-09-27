285. #### 没有上司的舞会

Ural大学有N名职员，编号为1~N。

他们的关系就像一棵以校长为根的树，父节点就是子节点的直接上司。

每个职员有一个快乐指数，用整数 HiHi 给出，其中 1≤i≤N。

现在要召开一场周年庆宴会，不过，没有职员愿意和直接上司一起参会。

在满足这个条件的前提下，主办方希望邀请一部分职员参会，使得所有参会职员的快乐指数总和最大，求这个最大值。

```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 6007;
int f[N][2];
vector<int> tr[N];
int st[N];
int h[N];
void dfs(int u){
    if(!tr[u].size()){
        f[u][1] = h[u]; return ;
    }
    for(auto& v: tr[u]){
        dfs(v);
    }
    f[u][1] = h[u];
    for(auto& v:tr[u]){
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][1], f[v][0]);
    } 
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n;i ++) cin >> h[i];
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        tr[b].push_back(a);
        st[a]++;
    }
    int root= 1;
    while(st[root]) root++;
    dfs(root);
    cout << max(f[root][0], f[root][1]);
}
```

