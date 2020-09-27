# 路径总和问题（树的遍历）

#### [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)

#### 题目：

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

#### 分析：

遍历一遍树，在每个叶子节点判断一下

#### 代码

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root ) return false;
        if(!root->left && !root->right) return sum == root->val;
        bool res = false;
        if(root->left) res |= hasPathSum(root->left, sum - root->val);
        if(root->right) res |= hasPathSum(root->right, sum - root->val);
        return res;
    }
};
```

#### [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

#### 题目：

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

#### 思路

遍历一遍树，在叶子节点的时候判断路径是否满足要求，路径用一个临时变量path来记录

#### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(TreeNode* root,int sum){
        if(!root) return ;
        path.push_back(root->val);
        if(root->val==sum&&(root->left==NULL&&root->right==NULL)){
            res.push_back(path);
        }
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return res;
    }
};
```

#### [437. 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/)

#### 题目

给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

#### 思路：

用前缀和记录路径前的和，每个节点判断；

#### 易错点：

用递归容易不满足连续性，如下面的例子，父子节点可以不连续； 10 —— -2 也会被计算在内

```cpp
		dfs(root->left, sum - root->val);
        dfs(root->left, sum);
        dfs(root->right, sum - root->val);
        dfs(root->right, sum);
```

![image-20200707100400306](https://raw.githubusercontent.com/ImAlien/pictures/master/img/20200707100407.png)

前缀和有点忘了：首先mp[0]要设置为1，然后查询要在增加之前（解决sum = 0的情况)

#### 代码：

```cpp
class Solution {
public:
    int res = 0, cnt = 0;
    map<int,int> mp;
    void dfs(TreeNode* root, int& sum){
        if(!root) return;
        cnt += root->val;
        if(mp.count(cnt - sum))res += mp[cnt-sum];
        mp[cnt]++; //该句要在上一句的下面
        dfs(root->left, sum);
        dfs(root->right, sum);
        mp[cnt]--;
        cnt -= root->val;
    }
    int pathSum(TreeNode* root, int sum) {
        mp[0]++;//这个别忘
        dfs(root,sum);
        return res;
    }
};
```

递归的话，第一个递归要在主函数里

```cpp
class Solution {
public:
    int count = 0;
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        dfs(root, sum) ;
        pathSum(root->left, sum) ;
        pathSum(root->right, sum);
        return count;
    }
    void dfs(TreeNode* root, int sum) {
        if (!root) return;
        if (sum - root->val == 0) count++;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};
```

#### [129. 求根到叶子节点数字之和](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/)

#### 题目

给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

#### 思路：

用一个变量来记录路径值，每次到叶子节点加上这个值

#### 代码

```cpp
class Solution {
public:
    int res, temp;
    void dfs(TreeNode* root){
        if(!root) return;
        temp = temp*10 + root->val;
        if(!root->left && !root->right) res += temp;
        dfs(root->left);
        dfs(root->right);
        temp = (temp - root->val)/10;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return res;
    }
};
```

#### [124. 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

#### 题目

给定一个**非空**二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径**至少包含一个**节点，且不一定经过根节点。

#### 思路

后序遍历树，在每个节点记录一下最大路径和，节点的最大路径和等于左节点的最大路径和加上自己加上右节点的最大路径和

#### 代码

```cpp
class Solution {
public:
    int res = INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        res = max(res, l + r + root->val);
        return max(max(l,r) + root->val,0);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
```

