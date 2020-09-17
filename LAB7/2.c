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
  if (node == NULL && node->data != -1 && node->data != NULL)
    return 0;
  else if (1) {
    //all present
    printf("Testing vala %d has nodes \n\n",node->data);
    if ((node->left != NULL && node->right != NULL) || (node->left != -1 && node->right != -1)) {
      printf("%d has: %d nodes \n",node->data,2);
      //return 2;
    }
    //all null
    else if ((node->left == NULL && node->right == NULL) || (node->left == -1 && node->right == -1)){
      printf("%d has: %d nodes \n",node->data,0);
      //return 2;
    }
    //ek null
    else if ((node->left != NULL && node->right == NULL) || (node->left != -1 && node->right == -1)){
      printf("%d has: %d nodes \n",node->data,1);
      //return 2;
    }
    
    else if ((node->left == NULL && node->right != NULL) || (node->left == -1 && node->right != -1)){
      printf("%d has: %d nodes \n",node->data,1);
      //return 1;
    }
  }
  
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
