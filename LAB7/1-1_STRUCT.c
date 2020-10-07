#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

int
countIt (struct node *node)
{
  if (node == NULL)
    return 0;
  if (node->left == NULL && node->right == NULL && node->data != -1)
    return 1;
  else
    return countIt (node->left) + countIt (node->right);
}

struct node *
newNode (int data)
{
  struct node *node = (struct node *) malloc (sizeof (struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

int
main ()
{
  struct node *root = newNode (1);
  root->left = newNode (2);
  root->left->left = newNode (4);
  root->left->right = newNode (5);
  root->right = newNode (3);
  root->right->right = newNode (7);
  root->right->left = newNode (6);
  root->right->left->right = newNode (-1);

  printf ("Leaf count of the tree is %d", countIt (root));
  return 0;
}
