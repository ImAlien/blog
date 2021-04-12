### 区间dp：

#### [730. 统计不同回文子序列](https://leetcode-cn.com/problems/count-different-palindromic-subsequences/)

给定一个字符串 S，找出 S 中不同的非空回文子序列个数，并返回该数字与 10^9 + 7 的模。

通过从 S 中删除 0 个或多个字符来获得子序列。

如果一个字符序列与它反转后的字符序列一致，那么它是回文字符序列。

### 树形dp：

#### [968. 监控二叉树](https://leetcode-cn.com/problems/binary-tree-cameras/)

给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视**其父对象、自身及其直接子对象。**

计算监控树的所有节点所需的最小摄像头数量。

#### [834. 树中距离之和](https://leetcode-cn.com/problems/sum-of-distances-in-tree/)

给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。

第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。

返回一个表示节点 i 与其他所有节点距离之和的列表 ans。

### 线性dp：

#### [1458. 两个子序列的最大点积](https://leetcode-cn.com/problems/max-dot-product-of-two-subsequences/)

给你两个数组 `nums1` 和 `nums2` 。

请你返回 `nums1` 和 `nums2` 中两个长度相同的 **非空** 子序列的最大点积。

#### [940. 不同的子序列 II](https://leetcode-cn.com/problems/distinct-subsequences-ii/)

给定一个字符串 `S`，计算 `S` 的不同非空子序列的个数。

因为结果可能很大，所以**返回答案模** **`10^9 + 7`**.

#### [629. K个逆序对数组](https://leetcode-cn.com/problems/k-inverse-pairs-array/)

给出两个整数 `n` 和 `k`，找出所有包含从 `1` 到 `n` 的数字，且恰好拥有 `k` 个逆序对的不同的数组的个数。

### 多状态线性dp：

#### [LCP 19. 秋叶收藏集](https://leetcode-cn.com/problems/UlBDOe/)

小扣出去秋游，途中收集了一些红叶和黄叶，他利用这些叶子初步整理了一份秋叶收藏集 leaves， 字符串 leaves 仅包含小写字符 r 和 y， 其中字符 r 表示一片红叶，字符 y 表示一片黄叶。
出于美观整齐的考虑，小扣想要将收藏集中树叶的排列调整成「红、黄、红」三部分。每部分树叶数量可以不相等，但均需大于等于 1。每次调整操作，小扣可以将一片红叶替换成黄叶或者将一片黄叶替换成红叶。请问小扣最少需要多少次调整操作才能将秋叶收藏集调整完毕。

```cpp
int f[n+1][3];//f[i][j]表示前i个字符在j状态下的最小操作次数，j: 0表示前红，1表示黄,2表示后红
memset(f, inf, sizeof f);
f[0][0] = 0;
rep(i, 1, n){
    f[i][0] = f[i-1][0] + (s[i-1] != 'r');
    if(i > 1) f[i][1] = min(f[i-1][0], f[i-1][1]) +(s[i-1] != 'y');
    f[i][2] = min(f[i-1][2], f[i-1][1]) + (s[i-1] != 'r');
}
```

