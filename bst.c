#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stddef.h>
#include "bst.h"





BST bst_new()
{

    BST tree={ NULL,0 };
    return tree;
}

static TreeNode*  _make_new_node(int32_t element)
{
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->data=element;
    node->left=NULL;
    node->right=NULL;
    return node;
}
/*count the number of elements*/
uint32_t bst_count(BST *tree)
{
    assert(tree!=NULL);
    return tree->mass;
}

/*ADD the elements to BST*/
BST* bst_add_node(BST *tree,int32_t element)
{

    assert(tree!=NULL);
    TreeNode *cur,*parent;
    cur=parent=tree->root;
    while(cur!=NULL && cur->data!=element)
    {

        parent=cur;
        if(element < cur->data)
        {
            cur=cur->left;
        }
        else if(element > cur->data)
        {
            cur=cur->right;
        }
    }
    if(cur==NULL)
    {
        TreeNode *tnode=_make_new_node(element);
        if(parent==NULL)
        {
            tree->root=tnode;
        }
        else if(element < parent->data)
        {
            parent->left=tnode;
        }
        else if(element > parent->data)
        {
            parent->right=tnode;
        }
        ++tree->mass;
    }
    return tree;
}

/*Search the  elements in BST*/
uint32_t bst_lookup(BST *tree,int32_t key)
{
    assert(tree!=NULL);
    TreeNode *cur=tree->root;
    while(cur!=NULL && cur->data!=key)
    {
        if(key < cur->data)
        {
            cur=cur->left;
        }
        else if(key > cur->data)
        {
            cur=cur->right;
        }
    }
    return(cur!=NULL);
}

/*Delete the element from BST*/
static TreeNode* _findMin_(TreeNode *node)
{
    if(node->left==NULL)
    {
        return node;
    }
    else
        return(_findMin_(node->left));
}

static TreeNode* _delete_(BST *tree,TreeNode *node,int32_t key)
{
    TreeNode *temp;
    if(node==NULL)
    {
        return node;
    }
    else if(key < node->data)
    {
        node->left=_delete_(tree,node->left,key);
    }
    else if(key > node->data)
    {
        node->right=_delete_(tree,node->right,key);
    }
    else if(node->left && node->right)
    {
        temp=_findMin_(node->right);
        node->data=temp->data;
        node->right=_delete_(tree,node->right,node->data);
    }
    else{
        temp=node;
        if(node->right==NULL)
        {
            node=node->left;
        }
        else{
            node=node->right;
        }
        free(temp);
        --tree->mass;
    }
    return node;
}

BST* bst_delete(BST *tree,int32_t element)
{
    assert(tree!=NULL);
    tree->root=_delete_(tree,tree->root,element);
    return tree;
}
/*inorder traversal*/
static void _inorder_(TreeNode *node)
{
    if(node)
    {
    _inorder_(node->left);
    printf("%d\t",node->data);
    _inorder_(node->right);
    }
}
void bst_inorder(BST *tree)
{
    assert(tree->root!=NULL);
    _inorder_(tree->root);
}

/*pre-order traversal*/
static void _preorder_(TreeNode *node)
{
    if(node)
    {
     printf("%d\t",node->data);
    _preorder_(node->left);
    _preorder_(node->right);
    }
}
void bst_preorder(BST *tree)
{
    assert(tree->root!=NULL);
    _preorder_(tree->root);
}
/*post-order traversal*/
static void _postorder_(TreeNode *node)
{
    if(node)
    {
    _preorder_(node->left);
    _preorder_(node->right);
    printf("%d\t",node->data);
    }
}
void bst_postorder(BST *tree)
{
    assert(tree->root!=NULL);
    _postorder_(tree->root);
}

/*method to find the height of binary search tree*/
int _height_(TreeNode *node)
{
    if(node!=NULL)
    {
        uint32_t Lheight,Rheight;
        Lheight=_height_(node->left);
        Rheight=_height_(node->right);
        if(Lheight > Rheight)
            return(Lheight+1);
        else
            return(Rheight+1);
    }
}

uint32_t bst_height(BST *tree)
{
    assert(tree->root!=NULL);
    _height_(tree->root);
}


/*method to count the number of terminal nodes in BST*/

uint32_t _getleafcount_(TreeNode *node)
{
    if(node==NULL)
        return 0;
    else if(node->left==NULL && node->right==NULL)
        return 1;
    else
        return _getleafcount_(node->left)+_getleafcount_(node->right);
}

uint32_t bst_leafcount_(BST *tree)
{
    assert(tree->root!=NULL);
    _getleafcount_(tree->root);

}

/*methods to find  min element in BST */
uint32_t _minvalue_(TreeNode *node)
{
    TreeNode *cur=node;
    while(cur->left!=NULL)
    {
        cur=cur->left;
    }
    return(cur->data);
}

uint32_t minvalue(BST *tree)
{
    assert(tree->root!=NULL);
    _minvalue_(tree->root);

}

/*methods to find  max element in BST */
uint32_t _maxvalue_(TreeNode *node)
{
    TreeNode *cur=node;
    while(cur->right!=NULL)
    {
        cur=cur->right;
    }
    return(cur->data);
}
uint32_t maxvalue(BST *tree)
{
    assert(tree->root!=NULL);
    _maxvalue_(tree->root);
}

/*method to display elements in ascending order*/

static void _ascending_(TreeNode *node)
{
    if(node)
    {
    _ascending_(node->left);
    printf("%d\t",node->data);
    _ascending_(node->right);
    }
}
void bst_ascending(BST *tree)
{
    assert(tree->root!=NULL);
    _ascending_(tree->root);
}

/*method to display elements in descending order */
static void _descending_(TreeNode *node)
{
    if(node)
    {
    _descending_(node->right);
    printf("%d\t",node->data);
    _descending_(node->left);
    }
}
void bst_descending(BST *tree)
{
    assert(tree->root!=NULL);
    _descending_(tree->root);
}

