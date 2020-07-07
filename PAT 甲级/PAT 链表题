## PAT链表题型总结

#### 存储方式

1. 利用数组或者结构体

   数组下标用来表示自己的地址，数组值指向下一个节点

   **1032** **Sharing** 

   直接储存

   **1052** **Linked List Sorting**

   排序时可以用vector存地址和值就好；

#### 例题

**1074** **Reversing Linked List**

每K个节点反转链表

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int list_[maxn], vis[maxn], data_[maxn];
int K;
int reverse(int head){
    int p = head;
    int cnt = 0;
    while(cnt < K && p != -1){
        p = list_[p];cnt++;
    }
    if(cnt < K) return head;
    int pre = reverse(p);
    int newhead = maxn - 2;
    list_[newhead] = pre; //反转单链表是指向-1
    p = head;
    for(int i = 0; i < K; i++){
        int t = list_[p];
        list_[p] = list_[newhead];
        list_[newhead] = p;
        p = t;
    }
    return list_[newhead];
}
int main(){
    int  N, head;
    cin >> head >> N >> K;
    for(int i = 0; i <N; i++){
        int a, c;
        int b;
        cin >>a >>b >>c;
        list_[a] = c;
        data_[a] = b;
    }
    int p = reverse(head);
    while(p != -1){
        if(list_[p] != -1)
        printf("%05d %d %05d\n",p, data_[p],list_[p]);
        else printf("%05d %d -1\n",p, data_[p]);
        p = list_[p];
    }
    system("pause");
}

```

或者直接将地址和数值用vector储存，进行反转；

#### 1097 **Deduplication on a Linked List**

#### 题意：

把重复绝对值的节点删除放入另一个链表；

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+ 6;
int list_[maxn], data_[maxn];
int main(){
    int head, N;
    cin >> head >> N;
    for(int i = 0 ; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        list_[a] = c;
        data_[a] = b;
    }
    int p = head, pre = head;
    set<int> s;
    int head2 = maxn- 2;
    list_[head2] = -1;
    int p2 = head2;
    while(p != -1){
        if(s.count(abs(data_[p]))){
            list_[p2] = p; p2 = p; list_[pre] = list_[p];
        }
        else{
            s.insert(abs(data_[p]));pre = p;
        }     
        p = list_[p];
    }
    p = head;
    while(p != -1){
        if(list_[p] != -1){
            printf("%05d %d %05d\n", p, data_[p], list_[p]);
        }
        else printf("%05d %d -1\n", p, data_[p]);
         p = list_[p];
    }
    p = list_[head2];
    list_[p2] = -1;
     while(p != -1){
        if(list_[p] != -1){
            printf("%05d %d %05d\n", p, data_[p], list_[p]);
        }
        else printf("%05d %d -1\n", p, data_[p]);
         p = list_[p];
    }
    system("pause");
}
```

做法二：直接遍历一次链表，把节点值都拿出来vector里面判断

```c++
#include<bits/stdc++.h>
using namespace std;
int data[(int)(1e5+5)],Next[(int)(1e5+5)];
void output(vector<int>&v){//输出链表
    if(v.empty())//链表为空
        return;//直接返回
    for(int i=0;i<v.size()-1;++i)//输出
        printf("%05d %d %05d\n",v[i],data[v[i]],v[i+1]);
    printf("%05d %d -1\n",v.back(),data[v.back()]);
}
int main(){
    int N,first;
    scanf("%d%d",&first,&N);
    while(N--){
        int a;
        scanf("%d",&a);
        scanf("%d%d",&data[a],&Next[a]);
    }
    unordered_set<int>value;//存储遍历过的链表结点数据域的绝对值
    vector<int>RemainL,RemoveL;
    for(;first!=-1;first=Next[first])
        if(value.find(abs(data[first]))==value.end()){
            value.insert(abs(data[first]));
            RemainL.push_back(first);
        }else
            RemoveL.push_back(first);
    output(RemainL);
    output(RemoveL);
    return 0;
}
————————————————
版权声明：本文为CSDN博主「日沉云起」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/richenyunqi/article/details/80150728
```

**1133** **Splitting A Linked List**

题意： 链表中负数，0<= K的数，>K的数分开

#### 分析：

直接遍历一遍链表，对数据分类讨论

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int list_[maxn], vis[maxn], data_[maxn];
int K;
int main(){
    int  N, head;
    cin >> head >> N >> K;
    for(int i = 0; i <N; i++){
        int a, c;
        int b;
        cin >>a >>b >>c;
        list_[a] = c;
        data_[a] = b;
    }
    int p = head;
    vector<int> a, b, c;
    while(p != -1){
        if(data_[p] < 0) a.push_back(p);
        else if(data_[p] <= K) b.push_back(p);
        else c.push_back(p);
        p = list_[p];
    }
    for(int x: b) a.push_back(x);
    for(int x:c) a.push_back(x);
    for(int i = 0; i < a.size() - 1; i++){
        printf("%05d %d %05d\n",a[i], data_[a[i]], a[i+1]);
    }
    int t = a.size() - 1;
    printf("%05d %d -1",a[t], data_[a[t]]);
    system("pause");
}

```

