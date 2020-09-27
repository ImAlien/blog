

## 分类

#### AVL树：

AVL树是自平衡二叉搜索树。 在AVL树中，任何节点的两个子子树的高度最多相差一个；如果在任何时候它们相差多于一个，则重新平衡以恢复此属性。

#### 模板：

```cpp
struct AVLTreeNode{
    int val, depth;
    AVLTreeNode* left;
    AVLTreeNode* right;
    AVLTreeNode(int v):val(v),depth(0),left(nullptr),right(nullptr){};
};
typedef AVLTreeNode AVL;
int height(AVL* r){
    return r? r->depth:0;
}
AVL* rotateRight(AVL* root){//右旋,第一种,注意更新深度
    AVL* t = root->left;
    root->left = t->right;
    t->right = root;
    root->depth = max(height(root->left),height(root->right)) + 1;//注意更新时顺序
    t->depth = max(height(t->left),height(t->right)) + 1;
     return t;
}
AVL* rotateLeft(AVL* root){//左旋,第二种，注意更新深度
    AVL* t = root->right;
    root->right = t->left;
    t->left = root;
    root->depth = max(height(root->left),height(root->right)) + 1;//注意更新时顺序
    t->depth = max(height(t->left),height(t->right)) + 1;
    return t;
}
AVL* rotateLeftRight(AVL* root){//左右双旋,第四种,先将左子树左旋，再自己右旋
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
AVL* rotateRightLeft(AVL* root){//右左双旋，先将右子树右旋，再自己左旋
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
AVL* insert(AVL* root, int x){
    if(!root) root = new AVL(x);
    else if(x < root->val){
        root->left = insert(root->left, x);
        //左子树失去平衡
        if(height(root->left) - height(root->right) == 2) //第1,4种情况
            root = x < root->left->val? rotateRight(root) : rotateLeftRight(root);
    }
    else if(x > root->val){
        root ->right = insert(root->right, x);
        //右子树失去平衡
        if(height(root->right) - height(root->left) == 2) //第1,3种情况
            root = x > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
    }
    root->depth = max(height(root->left), height(root->right)) + 1;//更新深度
    return root;
}
```

#### 简易：

```cpp
struct node{
    int val;
    node* left, *right;
    node(int x): val(x), left(nullptr), right(nullptr){};
};
int height(node* root){
    if(!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}
node* left_rotate(node* root){
    node* t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
node* right_rotate(node* root){
    node* t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node* left_right_rotate(node* root){
    root->left = left_rotate(root->left);
    return right_rotate(root);
}
node* right_left_rotate(node* root){
    root->right = right_rotate(root->right);
    return left_rotate(root);
}
node* insert(node* root, int x){
    if(!root) root = new node(x);
    else if(x > root->val){
        root->right = insert(root->right, x);
        if(height(root->right) - height(root->left) == 2){
            if(x > root->right->val) root = left_rotate(root);
            else root = right_left_rotate(root);
        }
    }
    else if(x < root->val){
        root->left = insert(root->left, x);
        if(height(root->left) - height(root->right) == 2){
            if(x < root->left->val) root = right_rotate(root);
            else root = left_right_rotate(root);
        }
    }
    return root;
}
```



