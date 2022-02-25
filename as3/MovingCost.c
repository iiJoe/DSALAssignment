/**
 * MovingCost.c -- Q7: The Moving Cost from A to B in a Binary Tree
 *
 * Written on Thursday, 17 February 2022.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int nodeV;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queuenode{
    BTNode* node;
    struct _queuenode *next;
}QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

void printBTNode(BTNode *root, int space,int left);
//Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode * node);
int dequeue(Queue *qPtr);
BTNode* getFront(Queue q);
int isEmptyQueue(Queue q);

int twoNodesCost(BTNode* node, int nodeV1,int nodeV2);

int main()
{
    BTNode* root = (BTNode*) malloc(sizeof(BTNode));

    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    BTNode* node;
    enqueue(&q,root);

    int nodeV;
    char opL, opR;

    while(!isEmptyQueue(q)){
            scanf("%d %c %c",&nodeV,&opL,&opR);
            node = getFront(q);dequeue(&q);
            node->nodeV = nodeV;

            if(opL != '@'){
                node->left = (BTNode*) malloc(sizeof(BTNode));
                enqueue(&q,node->left);
            }
            else node->left =NULL;
            if(opR != '@'){
                node->right = (BTNode*) malloc(sizeof(BTNode));
                enqueue(&q,node->right);
            }
            else
                node->right = NULL;
    }

    int v1,v2;
    scanf("%d %d",&v1,&v2);
    int cost = twoNodesCost(root,v1,v2);

    printBTNode(root,0,0);

    printf("Distance is %d\n",cost);
    return 0;
}

void enqueue(Queue *qPtr, BTNode *node){
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr){
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

BTNode* getFront(Queue q){
    return q.head->node;
}

int isEmptyQueue(Queue q){
    if(q.size==0) return 1;
    else return 0;
}
void printBTNode(BTNode *root,int space,int left){
      if (root != NULL)
      {

          int i;
          for (i = 0; i < space-1; i++)
                 printf("|\t");


          if(i<space){
            if(left==1)
              printf("|---");
            else
              printf("|___");
          }

          printf("%d\n", root->nodeV);

          space++;
          printBTNode(root->left, space,1);
          printBTNode(root->right, space,0);
      }
}

typedef struct {
  int value;
  _Bool isPathFound;
} Pair;

int traverseChildren(BTNode* node, int dest) {
  if (!node) return -1;
  else if (node->nodeV == dest) return dest;
  else {
    int left = traverseChildren(node->left, dest);
    int right = traverseChildren(node->right, dest);

    if (left < 0) {
      if (right < 0) return -1;
      else return node->nodeV + right;
    }
    else {
      return node->nodeV + left;
    }
  }
}

Pair traverseTree (BTNode* node, int nodeV1, int nodeV2) {
  if (!node) {
    Pair p;
    p.value = -1;
    p.isPathFound = 0;
    return p;
  }
  else {
    int curr = node->nodeV;
    if (curr == nodeV1) {
      int path = traverseChildren(node, nodeV2);
      Pair p;

      if (path < 0) {
        p.isPathFound = 0;
        p.value = curr;
      }
      else {
        p.isPathFound = 1;
        p.value = path;
      }

      return p;

    } else if (curr == nodeV2) {
      int path = traverseChildren(node, nodeV1);
      Pair p;

      if (path < 0) {
        p.isPathFound = 0;
        p.value = curr;
      }
      else {
        p.isPathFound = 1;
        p.value = path;
      }

      return p;
    }
    else {

      Pair left = traverseTree(node->left, nodeV1, nodeV2);
      Pair right = traverseTree(node->right, nodeV1, nodeV2);

      Pair p;
      p.isPathFound = left.isPathFound || right.isPathFound;
      if (p.isPathFound) {
        p.value = (left.value < 0 ? 0 : left.value) + (right.value < 0 ? 0: right.value);
      } else {
        if (left.value >= 0 && right.value >= 0) {
          p.isPathFound = 1;
          p.value = left.value + right.value + curr;
        } else if (left.value < 0 && right.value < 0) {
          p.value = -1;
        } else {
          p.value = (left.value < 0 ? 0 : left.value) + (right.value < 0 ? 0 : right.value) + curr;
        }
      }

      return p;
    }
  }
}

int twoNodesCost(BTNode* node, int nodeV1,int nodeV2)
{
  return traverseTree(node, nodeV1, nodeV2).value;
}
