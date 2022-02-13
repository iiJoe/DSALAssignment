/**
 * VisiblePairs.c -- Q6: The Number of Visible Pairs
 *
 * Written on Thursday,  3 February 2022.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _dbllistnode
{
    int  item;
	struct _dbllistnode *next;
	struct _dbllistnode *pre;
} CDblListNode;

typedef struct _dbllinkedlist{
   int size;
   CDblListNode *head;
} CDblLinkedList;

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value);
void deleteList(CDblLinkedList *ptrCDLL);
void printList(CDblLinkedList CDLL);

int numMountainPairs(CDblLinkedList CDLL);

int main()
{
    CDblLinkedList himalayas;
    himalayas.head = NULL;
    himalayas.size = 0;

    int item;
    int i,cases;
    int numP;
    scanf("%d",&cases);
    for(i=0; i<cases; i++)
    {
        while(scanf("%d",&item))
            insertNode_AtFront(&himalayas, item);
        scanf("%*s");

        numP = numMountainPairs(himalayas);
        printList(himalayas);
        printf("%d Pairs.\n",numP);

        deleteList(&himalayas);
    }

    return 0;
}

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value){
      //create a new node
      CDblListNode* newNode;
      newNode = (CDblListNode *) malloc(sizeof(CDblListNode));
      newNode->item = value;

      if(ptrCDLL->size==0) //first node
      {
          newNode->next = newNode;
          newNode->pre = newNode;
          ptrCDLL->head = newNode;
      }
      else{
        newNode->next = ptrCDLL->head;
        newNode->pre = ptrCDLL->head->pre;

        newNode->pre->next = newNode; //update last node next link;
        ptrCDLL->head->pre = newNode;

        ptrCDLL->head = newNode;
      }
      ptrCDLL->size++;
}

void printList(CDblLinkedList CDLL){

    if(CDLL.head==NULL) return;

    CDblListNode* temp = CDLL.head;
    printf("Current List: ");

    while (temp->next != CDLL.head){
        printf("%d ", temp->item);
        temp = temp->next;

    }
    printf("%d\n",temp->item);
}

void deleteList(CDblLinkedList *ptrCDLL){
    if(ptrCDLL->head==NULL) return;
    CDblListNode *cur = ptrCDLL->head;
    CDblListNode *temp;

    while (cur->next!= ptrCDLL->head) {
        temp=cur->next;
        free(cur);
        cur=temp;
    }

    free(cur);
    ptrCDLL->head =NULL;
    ptrCDLL->size =0;

}

int numMountainPairs(CDblLinkedList CDLL)
{

  int count = 0;

  if (CDLL.size == 2) count = 1;
  else if (CDLL.size == 3) count = 3;
  else if (CDLL.size > 3) {
    CDblListNode *head = CDLL.head, *curr = head, *tmp, *fmax, *bmax;
    int currValue;

    for (int i = 0; i < CDLL.size - 1; i++) {

      // Check how many nodes are connected to curr
      currValue = curr->item;

      // iterate in the forward direction
      tmp = curr->next;
      count++;
      fmax = tmp;

      if (tmp->item <= currValue) {
        tmp = tmp->next;
        while (tmp != head) {
          if (curr == head && tmp == head->pre) {break;}
          else if (tmp->item > currValue) {
            fmax = tmp;
            count++;
            break;
          }
          else if (tmp->item >= fmax->item) {
            fmax = tmp;
            count++;
          }
          tmp = tmp->next;
        }
      }

      tmp = curr->pre;
      _Bool isBlocked = 0;
      if (tmp->item <= currValue) {
          bmax = tmp;
          // If current iteration is not on head, traverse backwards without counting (explored nodes) until head
          if (curr != head) {
            while (tmp != head) {
              tmp = tmp->pre;
              if (tmp->item > currValue) {
                isBlocked = 1;
                break;
              }
              else {
                if (tmp->item >= bmax->item) {
                  bmax = tmp;
                }
              }
            }
          }

          if (curr == head) tmp = curr;

          // Loop nodes from head to current
          if (!isBlocked) {
            tmp = tmp->pre;
            if (curr == head && tmp == head->pre) {
              if (fmax == tmp) {
                curr = curr->next;
                continue;
              } else
                tmp = tmp->pre;
            }
            while (tmp != fmax) {
              if (tmp->item > currValue) {
                count++;
                break;
              }
              else if (tmp->item >= bmax->item) {
                bmax = tmp;
                count++;
              }
              tmp = tmp->pre;
            }
          }
        }



      curr = curr->next;
    }
    count++;
  }
  return count;

}
