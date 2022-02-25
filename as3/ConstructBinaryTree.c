/**
 * ConstructBinaryTree.c -- Q8: Construct a Binary Tree
 *
 * Written on Friday, 18 February 2022.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 120

typedef struct _btnode{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode** node, char* preO, char* postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s",preO);
    scanf("%s",postO);

    BTNode* root=NULL;
    buildTree(&root,preO,postO);
    if(root==NULL) printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur){
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c",cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur){
    if (cur == NULL)
        return;

    printf("%c",cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur){
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c",cur->id);
}

typedef struct _node {
  BTNode* data;
  struct _node *next;
} Node;

typedef struct {
  int length;
  Node *head;
} Stack;

BTNode* peek(Stack s) { return s.head->data; }

void push(Stack *s, BTNode* data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = s->head;
  s->head = node;
  s->length++;
}

void pop(Stack *s) {
  Node *tmp = s->head;
  if (tmp) {
    s->head = s->head->next;
    free(tmp);
    s->length--;
  }
}

void buildTree(BTNode** node, char* preO, char* postO)
{
  Stack nodes;
  nodes.length = 0;
  nodes.head = NULL;
  char *post;
  while (*preO) {
    BTNode *curr = (BTNode *)malloc(sizeof(BTNode));
    curr->id = *preO;
    curr->left = NULL;
    curr->right = NULL;
    if (!*node) {
      push(&nodes, curr);
      *node = curr;
    }
    else {
      post = postO;
      BTNode *top = peek(nodes);
      while (*post) {
        if (*post == top->id) {
          pop(&nodes);
          top = peek(nodes);
        }
        else if (*post == curr->id) {
          if (top->left) {
            top->right = curr;
            pop(&nodes);
          }
          else top->left = curr;
          push(&nodes, curr);
          break;
        }
        post++;
      }
    }
    preO++;
  }
}
