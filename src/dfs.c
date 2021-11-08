/*
 * Search an expression using DFS.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */
#include "../include/dfs.h"
#include <assert.h>

void DFT(node *root)

{
  assert(root != NULL);
  stack *temp = (struct stack *)malloc(sizeof(struct stack *));
  temp = push(temp, root);
  while (temp != NULL)
  {
    node *toppp = temp->node;
    temp = pop(temp);

    if (toppp->rchild != NULL)
      temp = push(temp, toppp->rchild);

    if (toppp->lchild != NULL)
      temp = push(temp, toppp->lchild);
  }
}

node *make_node(int num, node *left, node *right)
{
  //Creating a node pointer
  struct node *n;                                
  n = (struct node *)malloc(sizeof(struct node));
  n->num = num;                                   
  //l- and rchild is made NULL
  n->lchild = left;                               
  n->rchild = right;                             
  return n;                                      
}

void free_node(node *p)
{
  free_node(p->lchild);
  free_node(p->rchild);
  free(p);
}

void print_node(node *p)
{
  if (p == NULL)
    printf("NULL\n");
  else
    printf("%d", p->num);
}

void print_tree(node *p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->num);

  if (p->lchild)
  {
    print_tree(p->lchild, depth + 1);
  }

  if (p->rchild)
    print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *newnode)
{
  struct stack *temp = (struct stack *)malloc(sizeof(struct stack *));
  //A new stack is created
  temp->node = newnode; 
  temp->next = topp;
  return temp;
}

bool isEmpty(stack *topp)
{
  return false;
}

node *top(stack *topp)
{
  return 0;
}

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp)
{
  stack *toppp;
  printf("%d, ", topp->node->num);
  //Top element popped
  toppp = topp->next;
  free(topp);
  return toppp;
}

void print_stack(stack *topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
  {

    print_node(temp->node);
    printf("\n");

    temp = temp->next;
  }

  printf("====\n");

  return;
}
