# KMP算法

***

## 理解

KMP算法的核心，是一个被称为部分匹配表(Partial Match Table)的数组。我觉得理解KMP的最大障碍就是很多人在看了很多关于KMP的文章之后，仍然搞不懂PMT中的值代表了什么意思。这里我们抛开所有的枝枝蔓蔓，先来解释一下这个数据到底是什么。

对于字符串“abababca”，它的PMT如下表所示：

![image-20200703091328179](C:\Users\Alien\AppData\Roaming\Typora\typora-user-images\image-20200703091328179.png)

**PMT中的值是字符串的前缀集合与后缀集合的交集中最长元素的长度**。

我们看到如果是在 j 位 失配，那么影响 j 指针回溯的位置的其实是第 j −1 位的 PMT 值，所以为了编程的方便， 我们不直接使用PMT数组，而是将PMT数组向后偏移一位。我们把新得到的这个数组称为next数组。

![image-20200703091803488](C:\Users\Alien\AppData\Roaming\Typora\typora-user-images\image-20200703091803488.png)

## 例题

[HDU1711](http://acm.hdu.edu.cn/showproblem.php?pid=1711) 

给定两个数组，问能不能再第一个数组中匹配得到第二个数组，如果可以，那么输出最早匹配的起始位置，否则输出-1

代码：

```c++
#include<bits/stdc++.h>
using namespace std;

int s[1000005],p[10005], ne[10005];//next是关键字
int n, m;

void getNext(){
    int i = 0, j = -1;
    ne[0] = -1;
    while(i < m){
        if(j == -1 || p[i] == p[j]){
            i++; j++; ne[i] = j; //attention!
        }
        else j = ne[j];
    }
}
int KMP(){
    int i = 0, j = 0;
    getNext();
    while(i < n &&j <m){
        if(j == -1 || s[i] == p[j]){
            i++; j++;
        }
        else j = ne[j];
    }
    if(j == m) return i - j + 1;
    return -1;
}
int main(){   
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i <n; i++) scanf("%d",&s[i]);
        for(int i = 0; i < m ;i++) scanf("%d",&p[i]);
        int t = KMP();
        cout << t << endl;
    }
    system("pause");
}
```

### [HDU1358](http://acm.hdu.edu.cn/showproblem.php?pid=1358)

#### 原题：

Problem Description

For each prefix of a given string S with N characters (each character has an ASCII code between 97 and 126, inclusive), we want to know whether the prefix is a periodic string. That is, for each i (2 <= i <= N) we want to know the largest K > 1 (if there is one) such that the prefix of S with length i can be written as A^K, that is A concatenated K times, for some string A. Of course, we also want to know the period K.

Input

The input file consists of several test cases. Each test case consists of two lines. The first one contains N (2 <= N <= 1 000 000) – the size of the string S. The second line contains the string S. The input file ends with a line, having the number zero on it.

Output

For each test case, output “Test case #” and the consecutive test case number on a single line; then, for each prefix with length i that has a period K > 1, output the prefix size i and the period K separated by a single space; the prefix sizes must be in increasing order. Print a blank line after each test case.

Sample Input

```
3
aaa
12
aabaabaabaab
0
```

Sample Output

```
Test case #1
2 2
3 3

Test case #2
2 2
6 2
9 3
12 4
```

#### 题目大意：

找出一个字符串的所有周期前缀；周期性：能由由一个子串重复多次组成

#### 分析：

得出next数组，根据 len - next[i] 就是可能的周期串的长度

#### 代码：

```c++
#include<Bits/stdc++.h>
using namespace std;
char s[1000007];
int next_[1000007];
int N;
void getNext(){
    int i = 0, j = -1;
    next_[0] = -1;
    while( i < N){
        if(j == -1 || s[i] == s[j]){
            i++;j++;
            next_[i] = j;
        }
        else j = next_[j];
    }
}
int main(){
    cin >> N;
    int cnt = 1;
    while( N != 0){
        scanf("%s",&s);
        getNext();
        printf("Test case #%d\n",cnt++);

        for(int i = 2; i <= N; i++){
                int m=i-next_[i];//如果前缀是周期串，那么m就为一个周期的子串的长度
            if(i%m==0&&next_[i]!=0)
                printf("%d %d\n",i,i/m);//i/m就为一共有多少个周期
        }
        cout << endl;
        cin >> N;
    }
}
```



