/**
 * ReverseKNodes.c -- Q3: Reverse Every K Nodes
 *
 * Written on Thursday, 27 January 2022.
 */

#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void reverseKNodes(ListNode** head, int K);

int main()
{
  ListNode *head = NULL, *temp;
	int i = 0;
	int K = 0;

	scanf("%d",&K);

	while (scanf("%d", &i)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
	}
	temp->next = NULL;


	reverseKNodes(&head, K);
	printList(head);
  deleteList(&head);
	return 0;
}

void printList(ListNode *head){
  while(head !=NULL){
    printf("%d ",head->item);
    head = head->next;
  }
  printf("\n");
}

void deleteList(ListNode **ptrHead){
  ListNode *cur = *ptrHead;
  ListNode *temp;
  while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

void reverse(ListNode* nodes[], int k) {
  ListNode *curr, *prev = NULL, *next = nodes[0];
  // reverse the pointers within the array
  for (int i = 0; i < k; i++) {
    curr = next;
    next = curr->next;
    curr->next = prev;
    prev = curr;
  }
}

void reverseKNodes(ListNode** head, int K){
  if (K <= 1) return;
  ListNode* headNode = *head, *tmp, *old;
  int count = 0, isNewHead = 0;
  ListNode* reversed[K];
  while (headNode || count == K) {
    if (count == K) {

      // Check if new head has been reassigned
      if (!isNewHead) {
        *head = reversed[K - 1];
        isNewHead = 1;
      } else {
        tmp->next = reversed[K - 1];
      }

      tmp = reversed[0];
      reverse(reversed, K);
      tmp->next = headNode;
      count = 0;

    }
    else {
      reversed[count++] = headNode;
      headNode = headNode->next;
    }
  }
}
