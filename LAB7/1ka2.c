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
  printf("Testing vala %d has nodes \n\n",node->data);
  if (node == NULL )
    return 0;
  
  else{
    if (node->data != -1) {
      printf("Andar bhi aaya hai \n");
    
    //all present
    if ((node->left != NULL && node->right != NULL) && (node->left->data != -1 && node->right->data != -1)) {
      printf("%d has: %d nodes those aer %d and %d\n",node->data,2,node->left->data,node->right->data);
      countIt(node->left) + countIt (node->right);
      //return 1;
    }

    //all null
    else if ((node->left == NULL && node->right == NULL)){
      printf("%d has: %d nodes \n",node->data,0);
      //return 1;
    }

    //ek null
    else if ((node->left != NULL && node->right == NULL) && (node->left->data != -1)){
      printf("%d has: %d nodes \n",node->data,1);
      countIt (node->left);
      //return 1;
    }
    //ek null
    else if ((node->left == NULL && node->right != NULL) && (node->right->data != -1)){
      printf("%d has: %d nodes \n",node->data,1);
      countIt (node->right);
      //return 1;
    }
  }
  printf("----------------------------------\n");
  
    return countIt (node->left) + countIt (node->right);
  }
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

int countChildren(struct node *node) {
  int leftCount = 0;
  int rightCount = 0;
  if(node->left != NULL) {
    leftCount =  node->left->data == -1 ? 0 : (countChildren(node->left) + 1);
  }
  if(node->right != NULL) {
    rightCount = node->right->data == -1 ? 0 : (countChildren(node->right) + 1);
  }

  int totalChildren = (leftCount ? 1:0) + (rightCount ? 1:0);

  printf("%d has %d number of child nodes\n",node->data ,totalChildren);
  return totalChildren;
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
  countChildren(root);
  return 0;
}


