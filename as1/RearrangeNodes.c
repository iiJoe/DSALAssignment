/**
 * RearrangeNodes.c -- Q4: Rearrange Nodes
 *
 * Written on Friday, 28 January 2022.
 */

#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

typedef struct _linkedList{
    ListNode *head;
    int size;
}LinkedList;

void printList(LinkedList ll);
void deleteList(LinkedList* llptr);

LinkedList rearrange (LinkedList ll);

int main()
{
    LinkedList ll;

    ll.head = NULL;
    ll.size = 0;
    ListNode* temp;

	int i = 0;

	while (scanf("%d", &i)){
		if (ll.head == NULL){
			ll.head = (ListNode*) malloc(sizeof(ListNode));
			temp = ll.head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
		ll.size++;
	}
	temp->next = NULL;

	ll=rearrange(ll);

	printList(ll);
    deleteList(&ll);
	return 0;
}

void printList(LinkedList ll){
    ListNode* temp = ll.head;

    while(temp !=NULL){
        printf("%d ",temp->item);
        temp = temp->next;
    }
    printf("\n");
}
void deleteList(LinkedList* llptr){
    ListNode *cur = llptr->head;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	llptr->head=NULL;
	llptr->size =0;
}

LinkedList rearr(LinkedList ll, int isArrRight) {
  LinkedList right, res;
  ListNode *curr = NULL, *newHead, *leftPtr, *rightPtr, *lNext, *rNext;
  int length = ll.size, mid = length / 2;

  for (int i = 0; i < mid; i++) {
    if (curr == NULL) curr = ll.head;
    else curr = curr->next;
  }

  right.head = curr->next;
  right.size = length - mid;

  curr->next = NULL;
  ll.size = mid;

  lNext = ll.head;
  rNext = right.head;
  newHead = isArrRight ? rNext : lNext;

  if (isArrRight) {
    for (int j = 0; j < mid; j++) {
      leftPtr = lNext;
      rightPtr = rNext;

      rNext = rightPtr->next;
      lNext = leftPtr->next;

      rightPtr->next = leftPtr;
      leftPtr->next = rNext;
    }
  }

  else {
    for (int j = 0; j < mid; j++) {
      leftPtr = lNext;
      rightPtr = rNext;

      lNext = leftPtr->next;
      rNext = rightPtr->next;

      leftPtr->next = rightPtr;
      rightPtr->next = lNext;
    }
    if (ll.size != right.size) {
      rightPtr->next = rNext;
    }
  }

  res.size = length;
  res.head = newHead;
  return res;
}

LinkedList rearrange (LinkedList ll){
  if (ll.size <= 1) return ll;
  else return rearr(rearr(ll, 1), 0);
}
