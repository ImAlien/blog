#### [378. 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)

给定一个 *`n x n`* 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 `k` 小的元素。
请注意，它是排序后的第 `k` 小元素，而不是第 `k` 个不同的元素。

#### 方法一：归并排序

```cpp
struct node{//储存节点信息
        int val,x, y;
        node(int val_, int x_,int y_):x(x_),y(y_),val(val_){};
    };
bool operator < (const node& n1,const node& n2){//排序
        return n1.val > n2.val;
    }
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<node> pq;
        for(int i = 0; i < m; i++){
            pq.push({matrix[i][0],i,0});
        }
        int cnt = 0;
        while(pq.size()){//找到第k小的数
            node now = pq.top();
            pq.pop();
            cnt++;
            if(cnt == k) return now.val;
            if(now.y != n-1){
                pq.push({matrix[now.x][now.y+1], now.x, now.y + 1});
            }
        }
        return -1;
    }
};
```

#### 方法二：二分查找

```cpp
class Solution {
public:
    int m ,n;
    int check(vector<vector<int>>& matrix, int num){
        //返回小于num的个数
        int res = 0, x = 0, y = n-1;
        while(x < m && y >= 0){
            if(num >= matrix[x][y]){
                res += y+1; x++;
            }
            else y--;
        }
        return res;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size();
        n = matrix[0].size();
        int l = matrix[0][0], r = matrix[m-1][n-1];
        while( l < r){
            int mid = (l + r)/2;
            if(check(matrix, mid) >= k)
                r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
```

