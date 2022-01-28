/**
 * ReverseNodes.c -- Q1: Reverse Nodes from A to B
 *
 * Written on Wednesday, 26 January 2022.
 */

#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
	}
	temp->next = NULL;

	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
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

int sizeList(ListNode * head) {
  int count = 0;
  //while head is not null
  while (head) {
    count++;
    head = head->next;
  }
  return count;
}

ListNode *reverseSegment(ListNode* head, int start, int end)
{
  int length = sizeList(head);
  // Check for Invalid range, invalid index
  if (start >= end || end >= length || start >= length ) return head;
  else {
    int diff = end - start;

    ListNode *curr, *prev = NULL, *next = head, *pre = NULL, *revHead;
    // Get the node at start index
    for (int i = 0; i < start; i++) {
      pre = next; // Store last pointer of pre reversed-portion
      next = next->next;
    }

    revHead = next; // Store head pointer of reversed portion

    // Reverse the nodes from start to end (inclusive)
    for (int j = 0; j <= diff; j++) {
      curr = next;
      next = curr->next;
      curr->next = prev;
      prev = curr;
    }

    // Connecting the reversed portion back to main list;
    if (pre) pre->next = curr;
    else head = curr;
    revHead->next = next;

    return head;
  }
}
