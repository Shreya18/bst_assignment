#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
#include<stdint.h>
typedef struct _tree_node_ TreeNode;
typedef struct _bst_ BST;

struct _tree_node_
{
    int32_t data;
    TreeNode *left;
    TreeNode *right;
};

struct _bst_
{

    TreeNode *root;
    uint32_t mass;
};

BST bst_new();
uint32_t bst_count(BST *tree);
BST* bst_add_node(BST *tree,int32_t element);
BST* bst_delete_node(BST *tree,int32_t element);
uint32_t bst_lookup(BST *tree,int32_t key);
void bst_inorder(BST *tree);
void bst_preorder(BST *tree);
void bst_postorder(BST *tree);
BST* bst_levelorder(BST *tree);
uint32_t bst_height(BST *tree);
uint32_t bst_leafcount_(BST *tree);
uint32_t minvalue(BST *tree);
uint32_t maxvalue(BST *tree);
void bst_ascending(BST *tree);
void bst_descending(BST *tree);
#endif // _INCLUDED_BST_
