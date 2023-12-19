#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *builtree();
void preorder(TreeNode *root);
void inorder(TreeNode *root);
void postorder(TreeNode *root);

int main()
{
    TreeNode *root = NULL;

    root = builtree();

    printf("\nPreorder Traversal:\n");
    preorder(root);

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\nPostorder Traversal:\n");
    postorder(root);

    return 0;
}

TreeNode *builtree()
{
    int data;
    char choice;

    printf("Enter data (-1 for no data): ");
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }

    TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
    node->data = data;

    printf("Does %d have a left child? (y/n): ", data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        node->left = builtree();
    }
    else
    {
        node->left = NULL;
    }

    printf("Does %d have a right child? (y/n): ", data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        node->right = builtree();
    }
    else
    {
        node->right = NULL;
    }

    return node;
}

void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
