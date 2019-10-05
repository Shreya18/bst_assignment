#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

void test_empty_BST()
{
	BST t=bst_new();
	BST *tree=&t;
	assert(bst_count(tree) ==0);

}

void test_cases()
{
    BST t=bst_new();
	BST *tree=&t;
	tree=bst_add_node(tree,50);
	assert(bst_count(tree) ==1);
	/* Add the elements into BST */
    tree=bst_add_node(tree,30);
    tree=bst_add_node(tree,70);
    tree=bst_add_node(tree,20);
    tree=bst_add_node(tree,45);
    tree=bst_add_node(tree,60);
    tree=bst_add_node(tree,80);
    tree=bst_add_node(tree,25);
    tree=bst_add_node(tree,65);
    tree=bst_add_node(tree,75);
    tree=bst_add_node(tree,90);
    /*Number of elements in BST*/
    assert(bst_count(tree) ==11);
    /*search the element 45 in BST */
    assert(bst_lookup(tree,45));
    /*assertion failed condition check*/
    //assert(bst_lookup(TreeNode,10));

    /*To delete the element from BST */
    tree=bst_delete(tree,45);
    tree=bst_delete(tree,60);
    assert(bst_count(tree) ==9);

    /*to find the height of binary search tree*/
    assert(bst_height(tree)==4);

    /*to count the number of terminal nodes in BST*/
    assert(bst_leafcount_(tree)==4);

    /*to find max and min element in BST*/
    assert(minvalue(tree)==20);
    assert(maxvalue(tree)==90);

    /*in-order, pre-order, post-order and level-order traversals*/
    printf("\n\ninoder of a tree is \n\n");
    bst_inorder(tree);
    printf("\n\npre-oder of a tree is \n");
    bst_preorder(tree);
    printf("\n\npost-oder of a tree is \n");
    bst_postorder(tree);

    /*to display elements in ascending order*/
    printf("\n \n Ascending order  of a tree is \n");
    bst_ascending(tree);
    printf("\n \n Descending order  of a tree is \n");
    bst_descending(tree);
    /*to display elements in descending order */



}

int main()
{
    test_empty_BST();
    test_cases();
    return 0;
}
