/**
 * ExpressionTree.c -- Q6: Expression Tree
 *
 * Written on Sunday, 13 February 2022.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
  char prefix[SIZE];

  BTNode *root = NULL;

  // printf("Enter an prefix expression:\n");
  fgets(prefix, SIZE, stdin);

  createExpTree(&root, prefix);

  // printf("The Infix Expression:\n");
  printTree(root);
  printf("\n");

  // printf("The Postfix (Reverse Polish) Expression:\n");
  printTreePostfix(root);
  printf("\n");

  // printf("Answer ");
  printf("%.2f\n", computeTree(root));
  deleteTree(&root);
  return 0;
}

void push(Stack *sPtr, BTNode *item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}

_Bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int calcNum(char *start, char *end) {
  int res = 0;
  while (start != end) {
    res *= 10;
    res += *start - '0';
    start++;
  }
  return res;
}

void createExpTree(BTNode** root,char* prefix)
{
  Stack opts;
  opts.head = NULL;
  opts.size = 0;

  char *msd = NULL, *lsd = NULL, curr;

  while (*prefix) {

    curr = *prefix;

    if (isOperator(curr)) {
      BTNode *opt = (BTNode *) malloc(sizeof(BTNode));
      opt->item = curr;
      opt->left = NULL;
      opt->right = NULL;

      if (!*root) *root = opt; // set root of whole tree

      if (!isEmptyStack(opts)) {
        BTNode *top = peek(opts);
        if (top->left) {
          top->right = opt;
          pop(&opts);
        }
        else top->left = opt;
      }
      push(&opts, opt);
    }
    else if (curr == ' ') {
      if (msd && lsd) {
        BTNode *opt = peek(opts);
        BTNode *oper = (BTNode *)malloc(sizeof(BTNode));

        oper->item = calcNum(msd, lsd + sizeof(char));
        oper->left = NULL;
        oper->right = NULL;

        // to reset pointers
        msd = NULL;
        lsd = NULL;

        if (opt->left) {
          opt->right = oper;
          pop(&opts);
        } else
          opt->left = oper;
      }
    }
    else{
      if (!msd) msd = prefix;
      lsd = prefix;
    }

    prefix++;
  }

  // Read last input and tie to tree, because sample input has no white space at the end
  if (!isEmptyStack(opts)) {
    BTNode *lastOpt = peek(opts);
    BTNode *lastOper = (BTNode *)malloc(sizeof(BTNode));
    lastOper->item = calcNum(msd, lsd); // On hackerrank, need to add sizeof(char) to lsd, my guess is something about nil char or the compiler reading the while(*prefix) differently;
    lastOper->left = NULL;
    lastOper->right = NULL;
    lastOpt->right = lastOper;
    pop(&opts);
  }
}

void printTree(BTNode *node){
  if (node->left && node->right){
    printTree(node->left);
    printf(" %c ", (char) node->item);
    printTree(node->right);
  }
  else {
    printf("%d", node->item);
  }
}


void printTreePostfix(BTNode *node){
  if (node->left && node->right) {
    printTreePostfix(node->left);
    printTreePostfix(node->right);
    printf("%c", (char)node->item);
  } else {
    printf("%d", node->item);
  }
  printf(" ");
}

double computeTree(BTNode *node){
  if (node -> left && node ->right) {
    char opt = (char) node->item;

    double left = computeTree(node->left);
    double right = computeTree(node->right);
    double res;
    switch(opt) {
    case '+' : res =  left + right;
      break;
    case '-' : res = left - right;
      break;
    case '*' : res = left * right;
      break;
    case '/' : res = left / right;
      break;
    }
    return res;
  }
  else return (double) node->item;

}

