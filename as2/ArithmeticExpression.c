/**
 * ArithmeticExpression.c -- Q5: Arithmetic Expression Queue
 *
 * Written on Thursday,  3 February 2022.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

enum ExpType {OPT,OPERAND};

typedef struct _queueNode
{
    int item;
    enum ExpType type;
    struct _queueNode *next;
}QueueNode;

typedef struct _queue{
    int size;
    QueueNode *head;
    QueueNode *tail;
}Queue;

void enqueue (Queue *qptr, int item, enum ExpType type);
int dequeue(Queue *qPtr);
QueueNode* getFront(Queue q);
int isEmptyQueue(Queue q);

void expressionQ(char *infix, Queue* qPtr);
void printExpQ(Queue* qPtr);

int main()
{
    char infix[SIZE];
    scanf("%[^\n]%*c",infix);

    Queue inExpQ;
    inExpQ.head = NULL;
    inExpQ.tail = NULL;
    inExpQ.size = 0;

    expressionQ(infix,&inExpQ);
    printf("Output:\n");
    printExpQ(&inExpQ);

    return 0;
}

void enqueue (Queue *qPtr, int item, enum ExpType type)
{
    QueueNode *newNode;
    newNode = (QueueNode*) malloc(sizeof(QueueNode));
    newNode->item = item;
    newNode->type = type;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head = newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail =newNode;
    qPtr->size++;

}
int dequeue(Queue *qPtr)
{
    if(qPtr == NULL || qPtr->head ==NULL)
        return 0;
    else{
        QueueNode *temp = qPtr->head;
        qPtr->head = qPtr->head->next;

        if(qPtr->head == NULL)
            qPtr->tail = NULL;

        free(temp);
        qPtr->size--;
        return 1;
    }
}

QueueNode* getFront(Queue q)
{
    return q.head;
}

int isEmptyQueue(Queue q){
   if(q.size==0) return 1;
   else return 0;
}

void printExpQ(Queue *qPtr){
    if(qPtr==NULL) return;

    QueueNode* temp = NULL;
    temp = getFront(*qPtr);

    while(temp!=NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        dequeue(qPtr);
        temp = getFront(*qPtr);
    }
    printf("\n");

}

_Bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')';
}

// numQ: the queue that contains the digits of number
// qPtr: Output queue
void getNumber(Queue *numQ, Queue* qPtr) {
  int size = numQ->size;
  if (size != 0) {
    char number[size];
    int i = 0;

    while (!isEmptyQueue(*numQ)) {
      number[i++] = getFront(*numQ)->item;
      dequeue(numQ);
    }

    int num = 0;
    for (int j = 0; j < size; j++) {
      num *= 10;
      num += number[j];
    }

    enqueue(qPtr, num, OPERAND);
  }
}

void expressionQ(char *infix, Queue* qPtr)
{
  char curr = *infix;
  int index = 0;

  Queue numQ;
  numQ.head = NULL;
  numQ.tail = NULL;
  numQ.size = 0;

  // loop until null character
  while (curr) {
    if (isOperator(curr)) {
      getNumber(&numQ, qPtr);
      enqueue(qPtr, curr, OPT);
    }
    else {
      enqueue(&numQ, curr - '0', OPERAND);
    }


    curr = *(infix + sizeof(char) * ++index);
  }
  if (numQ.size != 0) {
    getNumber(&numQ, qPtr);
  }
}
