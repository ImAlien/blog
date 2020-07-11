### 树的遍历

#### 模板

```cpp
//已知先序中序求后序
void post(int root, int start, int end) {
    if(start > end) 
        return ;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    post(root + 1, start, i - 1);
    post(root + 1 + i - start, i + 1, end);
    printf("%d ", pre[root]);
}
TreeNode* buildTree(int root, int start, int end) {
    if(start > end) return NULL;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    TreeNode* t = new TreeNode();
    t->left = buildTree(root + 1, start, i - 1);
    t->right = buildTree(root + 1 + i - start, i + 1, end);
    t->data = pre[root];
    return t;
}
```

```cpp
//已知后序中序求先序
void pre(int root, int start, int end) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    printf("%d ", post[root]);
    pre(root - 1 - end + i, start, i - 1);
    pre(root - 1, i + 1, end);
}
//已知后序中序求层序
map<int, vector<int>> level;
void pre(int root, int start, int end, int depth) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[depth].push_back(post[root]);
    pre(root - 1 - end + i, start, i - 1, depth + 1);
    pre(root - 1, i + 1, end, depth+1);
}
```

#### 例题：

[1043 Is It a Binary Search Tree (25)-PAT甲级真题](1043.md)

[1053 Path of Equal Weight (30)-PAT甲级真题(树的遍历)](1053.md)

[1064 Complete Binary Search Tree (30)-PAT甲级真题（树的层序遍历）](1064.md)

[1079 Total Sales of Supply Chain (25)-PAT甲级真题（dfs,bfs,树的遍历）](1079.md)