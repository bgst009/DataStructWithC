# 树

## 二叉树

### 链式存储结构

```c
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
```

### 树的基本操作

####  定义

```c
/**
 * 先序构造二叉树，空格字符表示空树
 * @param biTree 二叉树
 * @return 成功构造二叉树 true
 */
bool CreateBiTree(BiTree *biTree);
/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @return 前序遍历成功 true
 */
bool PreOrderTravers(BiTree biTree);
/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @return 中序遍历成功 true
 */
bool InOrderTravers(BiTree biTree);

/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @return 后序遍历成功 true
 */
bool PostOrderTravers(BiTree biTree);

/**
 * 初始条件：二叉树存在
 *
 * @param biTree 二叉树
 * @return 层序遍历成功 true
 */
bool LevelOrderTravers(BiTree biTree);
```

#### 具体实现

1. `CreateBiTree`

   ```c
   bool CreateBiTree(BiTree *biTree) {
   
   
       char ch;
       scanf("%c", &ch);
   
       // # 表示为空节点
       if (ch == '#') {
           *biTree = NULL;
       } else {
           (*biTree) = (BiTNode *) malloc(sizeof(BiTNode));
           //动态分配内存失败
           if (!(*biTree)) {
               printf("\n No Space !!\n");
               return false;
           }
           //生成根节点
           (*biTree)->data = ch;
           (*biTree)->rchild = NULL;
           (*biTree)->rchild = NULL;
           //构造左子树
           CreateBiTree(&((*biTree)->lchild));
           //构造右子树
           CreateBiTree(&((*biTree)->rchild));
       }
   
   
       return true;
   }
   ```
   
2. `PreOrderTravers`

   ```c
   bool PreOrderTravers(BiTree biTree) {
       //空树返回 True
       if (BiTreeEmpty(biTree)) {
           return false;
       }
   
       Visit(biTree);
       PreOrderTravers(biTree->lchild);
       PreOrderTravers(biTree->rchild);
   
       return true;
   }
   ```

3. `InOrderTravers`

   ```c
   bool InOrderTravers(BiTree biTree) {
       if (BiTreeEmpty(biTree)) {
           return false;
       }
   
       InOrderTravers(biTree->lchild);
       Visit(biTree);
       InOrderTravers(biTree->rchild);
   
       return true;
   }
   ```

4. `PostOrderTravers`

   ```c
   bool PostOrderTravers(BiTree biTree) {
       if (BiTreeEmpty(biTree)) {
           return false;
       }
   
       PostOrderTravers(biTree->lchild);
       PostOrderTravers(biTree->rchild);
       Visit(biTree);
   
       return true;
   
   }
   ```

5. `LevelOrderTravers`

   ```c
   bool LevelOrderTravers(BiTree biTree) {
       //空树
       if (BiTreeEmpty(biTree)) {
           printf("\n Tree is Empty \n");
           return false;
       }
   
       //只有根节点
       if (biTree->lchild == NULL && biTree->rchild == NULL) {
           printf("\n %c \n", biTree->data);
           return true;
       }
   
       LinkQueue linkQueue;
       InitQueue_LQ(&linkQueue);
   
       //保存出队节点
       BiTNode *p;
   
       EnQueue_LQ(&linkQueue, biTree);
   
       //队列不空一直出队
       while (!QueueEmpty_LQ(&linkQueue)) {
           DeQueue_LQ(&linkQueue, &p);
           Visit(p);
           if (p->lchild) {
               EnQueue_LQ(&linkQueue, p->lchild);
           }
           if (p->rchild) {
               EnQueue_LQ(&linkQueue, p->rchild);
           }
       }
   
       return true;
   }
   ```

   
