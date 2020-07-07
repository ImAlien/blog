# PAT甲级复习

## 考纲分析

1. 具有充分的英文阅读理解能力；

2. 理解并掌握基础数据结构，包括：线性表、树、图；

3. 理解并熟练编程实现经典高级算法，包括哈希映射、并查集、最短路径、拓扑排序、关键路径、贪心、深度优先搜索、广度优先搜索、回溯剪枝等；

4. 具备较强的问题抽象和建模能力，能实现对复杂实际问题的模拟求解。

## 题型及其例题

# 最短路径

## Dijkstra模板

```c++
void dijkstra(int s){
    //初始化
    fill(dis, dis + N, inf);
    fill(vis , vis +N, 0);
    dis[s] = 0;
    path[s] = -1;//前一节点
    num[s] = 1;//路径数
    for(int i = 0; i < N; i++){
        //找到最近节点
        int pos = -1, mindis = inf;
        for(int j = 0; j <N; j++){
            if(!vis[j] && dis[j] < mindis){
                pos = j; mindis = dis[j];
            }
        }
        if(pos == -1) break;//不是连通图，则退出
        vis[pos] = 1;//加入已访问
        for(int j = 0; j <N; j++){
            if(!vis[j]){
                int temp = dis[pos] + g[pos][j];
                if(temp < dis[j]){
                    dis[j] = temp;//更新距离
                    //更新其他信息
                }else if(temp == dis[j]){
                    //更新其他信息
                }
            }
        }
    }
}
//输出路径
void PrintPath(int v){
    if(v == S) cout << name[S];
    else{
        PrintPath(path[v]);
        cout << ' ' << name[v];
    }
}
```



 ## 1. 1003 [Emergency](https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376)

#### 原题：

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input

5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output

2 4

#### 题目大意：

n个城市m条路，每个城市有救援小组，所有的边的边权已知。给定起点和终点，求从起点到终点的最短路径条数以及最短路径上的救援小组数目之和。如果有多条就输出点权（城市救援小组数目）最大的那个～

#### 分析：

用一遍Dijkstra算法, 比只记录距离的Dijkstra需要多加记录路径条数，点权

#### 代码：

```c++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,m,a,b;
    const int inf = 0x3f3f3f3f;
    cin >> n>>m>>a>>b;
    vector<vector<int>> mp(n,vector<int>(n,0x3f3f3f3f));
    //节点权值
    vector<int> v(n);
    for(int i = 0; i <n; i++) cin >> v[i];
    int t1,t2,t3;
    //地图
    while(m--){
        cin>>t1>>t2>>t3;
        mp[t1][t2] = mp[t2][t1] = t3;
    }
    vector<int> vis(n,0);
    vector<int> dis(n,inf);
    vector<int> p(n,0);//道路数
    vector<int> mv(n);//最大值
    for(int i = 0; i < n; i++) {mv[i] = v[i];}
    dis[a] = 0;
    p[a] = 1;
    int mm = 0;
    while(vis[b] == 0){
        // find min vertex.
        int nx,minnx = inf;
        for(int i = 0; i< n; i++){
            if(!vis[i] && dis[i]< minnx){
                minnx = dis[i];
                nx = i;
            } 
        }
        if(minnx == inf) break;
        vis[nx] = 1;
        // update other nodes
        for(int j = 0; j < n; j++)
            if(!vis[j] && mp[nx][j] != inf){
                if(dis[j] > dis[nx]+ mp[nx][j]){ //小于写成大于了
                    dis[j] = dis[nx] + mp[nx][j];
                    mv[j] = mv[nx]+v[j];
                    p[j] = p[nx];// don't forget!
                }
                else if(dis[j] == dis[nx]+mp[nx][j]){
                    mv[j] = max(mv[j],mv[nx]+v[j]);
                    p[j] += p[nx]; // attention !
                }
                    
            }
    }  
    cout << p[b] << ' ' << mv[b];
    system("pause");
}
```

## 2. 1018 [Public Bike Management](https://pintia.cn/problem-sets/994805342720868352/problems/994805489282433024)

#### 原题：

There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

![image-20200704152114990](https://raw.githubusercontent.com/ImAlien/pictures/master/img/image-20200704152114990.png)

Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.

Sample Input:

10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

Sample Output:

3 0->2->3 0

#### 题目大意

每个车站的最大容量为一个偶数Cmax，如果车站中自行车的数量为Cmax/2，则认为该车站处于“完美状态”，如果有一个车站自行车数量为0或者为Cmax，则认为该车站有问题，从控制中心PBMC出发携带一定数量的自行车前往该车站，并在路上收集一些自行车，使得沿途的车站以及最终到达的问题车站达到“完美状态”，求出从PBMC到达该问题车站的最短路径，如果有多条，选择需要从PBMC携带自行车数量最少的路径；如果仍有多条，选择从问题车站带回自行车最少的。

#### 分析

利用Dijkstra算法求出所有距离最短的路径，然后再用DFS找出最短路径。只有Dijkstra是不可以的，因为minNeed和minBack在路径上的传递不满足最优子结构，不是简单的相加的过程，只有在所有路径都确定了之后才能区选择最小的need和最小的back。因此还需要DFS找出最短路径。为了编码方便，不妨在读入每个车站的自行车数量时都减去Cmax/2，如果仍为正表示该车站需要带回自行车，如果为负表示该车站需要从PBMC获取自行车。

#### 代码

```c++
#include<bits/stdc++.h>

const int inf = 0x3f3f3f3f;
int c, n, target, m;
using namespace std;
int g[505][505];
int value[505], vis[505],dis[505];
vector<int> pre[505]; //储存每个节点的可能前节点
vector<int> path,res; //记录临时路径，最短路径
int minneed = inf, minback = inf; //记录最少需要，最少带回
void dfs(int v){   
    if(v == 0){//递归终点判断
        int need = 0, back = 0,sum = 0;
        //需要获取的自行车之和，但是不能小于0
        for(int i = 0; i < path.size(); i++)
            need = max(0, need - value[path[i]]), sum += value[path[i]];
        back = need + sum;
        //更新 minneed 和 minback
        if(need < minneed){
            res = path;
            minneed = need;
            minback = back;
        }
        else if(need == minneed && back < minback){
            res = path;
            minback = back;
        }
        return;
    }
    path.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    path.pop_back();
}
int main(){
    //input
    cin >> c >>n >> target >>m;
    for(int i = 1; i <= n; i++) cin >> value[i], value[i] -= c/2;
    fill(g[0],g[0]+505*505,inf);//注意，别忘了！
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    //init;
    fill(dis,dis + n+ 1,inf);
    dis[0] = 0;
    //dijkstra
    for(int i = 0; i <= n; i++){
        int pos = -1;
        int minv = inf;
        for(int j = 0; j <= n; j++){
            if(!vis[j] && dis[j] < minv){
                pos = j; minv = dis[j];
            }
        }
        if(pos == -1) break;
        vis[pos] = 1;
        for(int j = 0; j <= n; j++){
            if(!vis[j]){
                if(dis[j] > dis[pos] + g[pos][j]){
                    dis[j] = dis[pos] + g[pos][j];
                    pre[j].clear();pre[j].push_back(pos);
                }
                else if(dis[j] == dis[pos] + g[pos][j]){
                        pre[j].push_back(pos);
                }
            }
        }
    }
    // get the path
    dfs(target);
    //output 
    cout << minneed << " 0";
    for(int i = res.size()-1; i>= 0; i--) cout <<"->" << res[i];
    cout <<' '<< minback;
    system("pause");
}
```

## 3. 1030 [Travel Plan](https://pintia.cn/problem-sets/994805342720868352/problems/994805464397627392)

#### 原题：

A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input

4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

Sample Output

0 2 3 3 40

#### 分析

dijkstra + 记录路径 模板, 中间记录cost

#### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int n, m , s, d;
int vis[505], path[505], cost[505], dis[505];
int g[505][505];
int co[505][505];
void outputpath(int v){
    if(v == -1) return;
    outputpath(path[v]);
    cout << v << ' ';
}
void dijkstra(){
    for(int i = 0; i < n; i++){
        //find the nearest
        int pos = -1, mind = inf;
        for(int j = 0; j < n; j++){
            if(vis[j] == 0 && dis[j] < mind){//don't forget vis[j] == 0
                pos = j; mind = dis[j];
            }
        }
        if(pos == -1) break;
        vis[pos] = 1;
        //update other nodes
        for(int j = 0; j < n; j++){
            if(vis[j] == 0){
                int t = dis[pos] + g[pos][j];
                if(t < dis[j]){
                    dis[j] = t;
                    path[j] = pos;
                    cost[j] = cost[pos] + co[pos][j];
                }
                else if(t == dis[j]){
                    int c = cost[pos] + co[pos][j];
                    if(cost[j] > c){
                        path[j] = pos; cost[j] = c;
                    }
                }
            }
        }
    }
}
int main(){
    // input
    cin >> n >> m >> s >> d;
    fill(g[0],g[0] + 505*505, inf);
    fill(co[0],co[0] + 505*505, inf);
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a][b] = g[b][a] = c;
        co[a][b] = co[b][a] = d;
    }
    //init
    fill(dis,dis + n, inf);
    fill(cost, cost + n, inf);
    cost[s] = 0;
    dis[s] = 0;
    path[s] = -1;
    dijkstra();
    //output
    outputpath(d);
    cout << dis[d] <<' '<< cost[d]; // dis[d]写成d，debug近1小时
    system("pause");
}
```

## 4. 1072 [Gas Station](https://pintia.cn/problem-sets/994805342720868352/problems/994805396953219072)

#### 原题：

A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.

Output Specification:

For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output “No Solution”.

Sample Input 1:

4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2

Sample Output 1:

G1
2.0 3.3
Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution

#### 题目大意：

求出符合下列要求的加油站：

1. 到所有住宅区的距离都在服务范围之内
2. 到最近的住宅区的距离最远的（这里有点绕）
3. 如果有多个加油站符合要求选择到所有住宅区平均距离最小的
4. 如果仍有多个加油站符合要求选择编号最小的

#### 分析：

首先，加油站按G1、G2……等形式编号可以把加油站的编号映射为n+1、n+2……。由于加油站最多有10个，可以采取暴力搜索的方法，对每一个加油站都使用一次Dijkstra算法，求出该加油站到所有住宅区的最短距离，然后找出符合要求的加油站即可。

#### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int N,M,K,Ds,station=-1;//station表示符合要求的加油站编号
double minDis=-1,avgDis=1e9;//到最近的住宅区距离、到所有住宅区的平均距离
int graph[1015][1015],dis[1015];//图、到住宅区和加油站的最短距离
bool visit[1015];//是否已访问过
int trans(const string&s){//将加油站的“Gi”形式的编号转换成N+i，住宅区的编号不变
    if(s[0]=='G')
        return stoi(s.substr(1))+N;
    else
        return stoi(s);
}
void Dijkstra(){
    for(int j=0;j<N+M;++j){//循环N+M次
        int v=-1,MIN=INT_MAX;
        for(int i=1;i<=N+M;++i)//找出目前距离最小的编号
            if(!visit[i]&&dis[i]<MIN){
                MIN=dis[i];
                v=i;
            }
        if(v==-1)//如果图不连通，直接返回
            return;
        visit[v]=true;//当前编号已访问
        for(int i=1;i<M+N+1;++i)//更新能到达的编号的最短距离
            if(!visit[i]&&graph[v][i]!=0&&dis[i]>dis[v]+graph[v][i])
                dis[i]=dis[v]+graph[v][i];
    }
}
int main(){
    scanf("%d%d%d%d",&N,&M,&K,&Ds);
    for(int i=0;i<K;++i){
        string s1,s2;
        int k1;
        cin>>s1>>s2>>k1;
        int k2=trans(s1),k3=trans(s2);
        graph[k2][k3]=graph[k3][k2]=k1;
    }
    for(int i=N+1;i<=N+M;++i){//对M个加油站使用M次Dijkstra算法
        fill(dis,dis+N+M+1,INT_MAX);
        dis[i]=0;
        fill(visit,visit+M+N+1,false);
        Dijkstra();
        double currentMindis=INT_MAX*1.0,currentAvgDis=0.0;//记录当前加油站到最近的住宅区距离、到所有住宅区的平均距离
        bool flag=true;//表示到所有住宅区的距离是否都在服务范围内
        for(int j=1;j<=N&&flag;++j)//更新相应变量信息
            if(j!=i&&dis[j]<=Ds){
                currentMindis=min(currentMindis,dis[j]*1.0);
                currentAvgDis+=dis[j]*1.0;
            }
            else if(dis[j]>Ds)
                flag=false;
        currentAvgDis/=N;
        if(flag&&(currentMindis>minDis||(currentMindis==minDis&&currentAvgDis<avgDis))){
            station=i;
            minDis=currentMindis;
            avgDis=currentAvgDis;
        }
    }
    if(station!=-1)//有符合要求的加油站，输出
        printf("G%d\n%.1f %.1f",station-N,minDis,avgDis);
    else
        printf("No Solution");
    return 0;
}
```

## 5. 1087 [All Roads Lead to Rome](https://pintia.cn/problem-sets/994805342720868352/problems/994805379664297984)

#### 原题：

Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<=N<=200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N-1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format “City1 City2 Cost”. Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.

Output Specification:

For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommended. If such a route is still not unique, then we output the one with the maximum average happiness — it is guaranteed by the judge that such a solution exists and is unique.

Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommended route. Then in the next line, you are supposed to print the route in the format “City1->City2->…->ROM”.

Sample Input:

6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1

Sample Output:

3 3 195 97
HZH->PRS->ROM

#### 题目大意：

有N个城市，M条无向边，从某个给定的起始城市出发，前往名为ROM的城市。每个城市（除了起始城市）都有一个点权（称为幸福值），和边权（每条边所需的花费）。求从起点到ROM所需要的最少花费，并输出其路径。如果路径有多条，给出幸福值最大的那条。如果仍然不唯一，选择路径上的城市平均幸福值最大的那条路径

#### 分析：

dijkstra 加路径输出，增加路径条数，最大幸福值，路径长度信息；

#### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int N;
int inf = 0x3f3f3f3f;
int dis[1005], vis[1005];
int maxh[1005],pre[1005], path[1005],num[1005];
int g[1001][1001];
struct cities{
    string name;
    int happines;
}node[202];
map<string,int> mp;
void dijkstra(int s){
    //初始化
    fill(dis, dis + N, inf);
    fill(vis , vis +N, 0);
    dis[s] = 0;
    path[s] = -1;
    num[s] = 1;
    for(int i = 0; i < N; i++){
        //找到最近节点
        int pos = -1, mindis = inf;
        for(int j = 0; j <N; j++){
            if(!vis[j] && dis[j] < mindis){
                pos = j; mindis = dis[j];
            }
        }
        if(pos == -1) break;//不是连通图，则退出
        vis[pos] = 1;//加入已访问
        for(int j = 0; j <N; j++){
            if(!vis[j]){
                int temp = dis[pos] + g[pos][j];
                if(temp < dis[j]){
                    dis[j] = temp;//更新距离
                    //更新其他信息
                    maxh[j] = maxh[pos] + node[j].happines;
                    path[j] = pos;
                    pre[j] = pre[pos] + 1;
                    num[j] = num[pos];
                }else if(temp == dis[j]){
                    //更新其他信息
                    int t = maxh[pos] + node[j].happines;
                    num[j] += num[pos];
                    if(t > maxh[j]){
                        maxh[j] = t;
                        path[j] = pos;
                        pre[j] = pre[pos] + 1;
                    }
                    else if(t == maxh[j]){
                        int p = pre[pos] + 1;
                        if(p < pre[j]){
                            pre[j] = p;
                            path[j] = pos;
                        }
                    }
                }
            }
        }
    }
}
int S = 0;
void PrintPath(int v){
    if(v == S) cout << node[S].name;
    else{
        PrintPath(path[v]);
        cout << "->" << node[v].name;
    }
}
int main(){
    string begin;
    int K;
    cin >>N >> K >>begin;
    node[0].name = begin;node[0].happines = 0;
    mp[begin] = 0;
    for(int i = 1; i < N; i++){
        cin >> node[i].name >> node[i].happines;
        mp[node[i].name] = i;
    }
    //fill(g[0], g[0] + 205*205, inf); 
    // 这里和声明的地方一定要一样
    fill(g[0], g[0] + 1001*1001, inf); 
    for(int i = 0; i <K; i++){
        string t1, t2;
        int a;
        cin >> t1 >> t2 >> a;
        g[mp[t1]][mp[t2]] = g[mp[t2]][mp[t1]] = a;
    }
    int end = mp["ROM"];
    dijkstra(0);
    cout << num[end] <<' ' << dis[end] << ' ' << maxh[end] << ' ' << maxh[end]/pre[end] << endl;
    PrintPath(end);
    system("pause");
}
```

## 6. 1111 [Online Map](https://pintia.cn/problem-sets/994805342720868352/problems/994805358663417856)

#### 原题：

Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two paths to your user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request.

Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers N (2 <= N <= 500), and M, being the total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, each describes a street in the format:

V1 V2 one-way length time

where V1 and V2 are the indices (from 0 to N-1) of the two ends of the street; one-way is 1 if the street is one-way from V1 to V2, or 0 if not; length is the length of the street; and time is the time taken to pass the street.

Finally a pair of source and destination is given.

Output Specification:

For each case, first print the shortest path from the source to the destination with distance D in the format:

Distance = D: source -> v1 -> … -> destination

Then in the next line print the fastest path with total time T:

Time = T: source -> w1 -> … -> destination

In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique. In case the fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed to be unique.

In case the shortest and the fastest paths are identical, print them in one line in the format:

Distance = D; Time = T: source -> u1 -> … -> destination

Sample Input 1:

10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5

Sample Output 1:

Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5

Sample Input 2:

7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5

Sample Output 2:

Distance = 3; Time = 4: 3 -> 2 -> 5

#### 题意：

给一张地图，两个结点中既有距离也有时间，有的单行有的双向，要求根据地图推荐两条路线：一条是最快到达路线，一条是最短距离的路线。
第一行给出两个整数N和M，表示地图中地点的个数和路径的条数。接下来的M行每一行给出：道路结点编号V1 道路结点编号V2 是否单行线 道路长度 所需时间
要求第一行输出最快到达时间Time和路径，第二行输出最短距离Distance和路径

#### 分析：

用两次Dijkstra+DFS算法求出最短路径和最快路径，为了方便编码在Dijkstra和DFS算法的参数中均有index这个参数，index==0时表示求的是最短路径；index==1时表示求的是最快路径。将两个路径存储在两个vector中，为了方便编码，也可以定义一个长度为2的vector的数组，下标为0存储最短路径，下标为1存储最快路径，比较两个路径，根据是否完全一致按要求输出。

#### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int N,M,source,des,shortest[2];//source表示起点，des表示终点，shortest存储最短路径的长度(下标为0)和最快路径的时间(下标为1)
int graph[505][505][2];//图的邻接矩阵，下标为0的邻接矩阵表示长度，下标为1的邻接矩阵表示时间
int dis[505],past[505],num[505];//存储到各点的最短距离、各点的父节点、还有一个辅助数组num，求最短路径时存储时间，求最快路径时存储当前路径上结点个数
bool visit[505];//是否已访问
vector<int>path[2];//下标为0存储最短路径，下标为1存储最快路径
void Dijkstra(int index){//Dijkstra算法，index==0时表示求的是最短路径；index==1时表示求的是最快路径
    while(!visit[des]){//还没有访问到终点
        int v=-1,MIN=INT_MAX;
        for(int i=0;i<N;++i)//求出目前距离最短的未访问结点
            if(!visit[i]&&MIN>dis[i]){
                MIN=dis[i];
                v=i;
            }
        if(v==-1)//不是连通图，直接返回
            return;
        visit[v]=true;//结点v已访问
        for(int i=0;i<N;++i)//遍历v能到达的结点
            if(!visit[i]&&graph[v][i][index]!=0&&dis[i]>dis[v]+graph[v][i][index]){//距离更短
                dis[i]=dis[v]+graph[v][i][index];//更新距离
                past[i]=v;//更新父节点
                if(index==0)//求最短路径
                    num[i]=num[v]+graph[v][i][1];//更新到达当前结点时间
                else if(index==1)//求最快路径
                    num[i]=num[v]+1;//更新路径上结点个数
            }else if(graph[v][i][index]!=0&&dis[i]==dis[v]+graph[v][i][index])//距离相等
                if(index==0&&num[i]>num[v]+graph[v][i][1]){//求最短路径且时间更短
                    past[i]=v;//更新父节点
                    num[i]=num[v]+graph[v][i][1];//更新到达当前结点时间
                }else if(graph[v][i][index]!=0&&index==1&&num[i]>num[v]+1){//求最快路径且路径上结点数更少
                    past[i]=v;//更新父节点
                    num[i]=num[v]+1;//更新路径上结点个数
                }
    }
    shortest[index]=dis[des];//得出最短路径或最快路径的到达终点时的值
}
void DFS(int v,int index){//DFS算法求出路径，index==0时表示求的是最短路径；index==1时表示求的是最快路径
    if(v==source){//到达起点
        path[index].push_back(v);//将起点压入路径中
        return;//返回
    }
    DFS(past[v],index);//递归遍历
    path[index].push_back(v);//将当前点压入路径中
}
bool cmp(){//比较两个路径是否完全一致
    if(path[0].size()!=path[1].size())
        return false;
    for(int i=0;i<path[0].size();++i)
        if(path[0][i]!=path[1][i])
            return false;
    return true;
}
void output(int index){//输出路径
    for(int i=0;i<path[index].size();++i)
        printf("%s%d",i>0?" -> ":"",path[index][i]);
    printf("\n");
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int a,b,c,d,e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        graph[a][b][0]=d;
        graph[a][b][1]=e;
        if(c==0){
            graph[b][a][0]=d;
            graph[b][a][1]=e;
        }
    }
    scanf("%d%d",&source,&des);
    for(int i=0;i<2;++i){//用两次Dijkstra+DFS算法
        fill(visit,visit+N,false);
        fill(dis,dis+N,INT_MAX);
        fill(num,num+N,INT_MAX);
        dis[source]=0;
        num[source]=0;
        Dijkstra(i);
        DFS(des,i);
    }
    if(cmp()){
        printf("Distance = %d; Time = %d: ",shortest[0],shortest[1]);
        output(0);
    }else{
        printf("Distance = %d: ",shortest[0]);
        output(0);
        printf("Time = %d: ",shortest[1]);
        output(1);
    }
    return 0;
}
```

## 7. 1131 [Subway Map](https://pintia.cn/problem-sets/994805342720868352/problems/994805347523346432)

#### 原题：

1131. Subway Map (30)
In the big cities, the subway systems always look so complex to the visitors. To give you some sense, the following figure shows the map of Beijing subway. Now you are supposed to help people with your computer skills! Given the starting position of your user, your task is to find the quickest way to his/her destination.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (< =100), the number of subway lines. Then N lines follow, with the i-th (i = 1, ..., N) line describes the i-th subway line in the format:

M S[1] S[2] ... S[M]

where M (<= 100) is the number of stops, and S[i]’s (i = 1, ... M) are the indices of the stations (the indices are 4-digit numbers from 0000 to 9999) along the line. It is guaranteed that the stations are given in the correct order -- that is, the train travels between S[i] and S[i+1] (i = 1, ..., M-1) without any stop.

Note: It is possible to have loops, but not self-loop (no train starts from S and stops at S without passing through another station). Each station interval belongs to a unique subway line. Although the lines may cross each other at some stations (so called "transfer stations"), no station can be the conjunction of more than 5 lines.

After the description of the subway, another positive integer K (<= 10) is given. Then K lines follow, each gives a query from your user: the two indices as the starting station and the destination, respectively.

The following figure shows the sample map.
Note: It is guaranteed that all the stations are reachable, and all the queries consist of legal station numbers.

Output Specification:

For each query, first print in a line the minimum number of stops. Then you are supposed to show the optimal path in a friendly format as the following:

Take Line#X1 from S1 to S2.
Take Line#X2 from S2 to S3.
......
where Xi's are the line numbers and Si's are the station indices. Note: Besides the starting and ending stations, only the transfer stations shall be printed.

If the quickest path is not unique, output the one with the minimum number of transfers, which is guaranteed to be unique.

Sample Input:
4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
3
3011 3013
6666 2001
2004 3001
Sample Output:
2
Take Line#3 from 3011 to 3013.
10
Take Line#4 from 6666 to 1306.
Take Line#3 from 1306 to 2302.
Take Line#2 from 2302 to 2001.
6
Take Line#2 from 2004 to 1204.
Take Line#1 from 1204 to 1306.
Take Line#3 from 1306 to 3001.

#### 题意：

找出一条路线，使得对任何给定的起点和终点，可以找出中途经停站最少的路线；如果经停站一样多，则取需要换乘线路次数最少的路线

#### 分析：

