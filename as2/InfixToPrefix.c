/**
 * InfixToPrefix.c -- Q7: Infix string to prefix expression linked list
 *
 * Written on Friday,  4 February 2022.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);


void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
}

void push(Stack *sPtr, char item){
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

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

int getNumber(Stack* numS) {
  int size = numS->size, num = 0, count = 0;

  char numStr[size];

  while (!isEmptyStack(*numS)) {
    numStr[count++] = peek(*numS) - '0';
    pop(numS);
  }

  for (int i = 0; i < size; i++) {
    num *= 10;
    num += numStr[i];
  }


  return num;
}

int isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int precedence(char c) {
  if (c == '*' || c == '/') return 1;
  else if (c == '+' || c == '-') return 0;
  else return -1;
}

void in2PreLL(char* infix, LinkedList *inExpLL)
{
  Stack optS, numStack, strS;
  optS.size = 0;
  numStack.size = 0;
  strS.size = 0;
  optS.head = NULL;
  numStack.head = NULL;
  strS.head = NULL;

  while (*infix) {
    push(&strS, *infix);
    infix++;
  }

  char c;

  while (!isEmptyStack(strS)) {
    c = peek(strS);
    if (isOperator(c)) {
      if (!isEmptyStack(numStack)) {
        insertNode(inExpLL, getNumber(&numStack), OPERAND);
      }

      if (c == ')') {
        push(&optS, c);
      }
      else if (c == '(') {
        while (peek(optS) != ')') {
          insertNode(inExpLL, peek(optS), OPT);
          pop(&optS);
        }
        pop(&optS);
      }
      else {
        while (!isEmptyStack(optS) && peek(optS) != ')' && precedence(peek(optS)) > precedence(c)) {
          insertNode(inExpLL, peek(optS), OPT);
          pop(&optS);
        }
        push(&optS, c);
      }
    }
    else {
      push(&numStack, c);
    }
    pop(&strS);

  }

  if (!isEmptyStack(numStack)) {
    insertNode(inExpLL, getNumber(&numStack), OPERAND);
  }

  while (!isEmptyStack(optS)) {
    insertNode(inExpLL, peek(optS), OPT);
    pop(&optS);
  }
}

