/**
 * TriPartition.c -- Q2: Tri-Partition
 *
 * Written on Wednesday, 26 January 2022.
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

void triPartition(ListNode** head, int pivot);

int main()
{
  ListNode *head = NULL, *temp;
	int i = 0;
	int pivot = 0;

	scanf("%d",&pivot);

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


	triPartition(&head, pivot);
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

// Links up left, middle and right partitions to one linked list
ListNode* joinPartition(ListNode *left, ListNode *middle, ListNode *right) {
  ListNode *newHead;
  if (left) {
    newHead = left;
    while (left->next) {
      left = left->next;
    }

    if (middle) {
      left->next = middle;
      while (middle->next) {
        middle = middle->next;
      }
      middle->next = right;
    }
    else left->next = right;
  }
  else if (middle) {
    newHead = middle;
    while (middle->next) {
      middle = middle->next;
    }
    middle->next = right;
  }
  else newHead = right;
  return newHead;
}

void append(ListNode **head, ListNode *node) {
  node->next = NULL;
  ListNode* tmp = *head;
  if (tmp) {
    while (tmp->next) tmp = tmp->next;
    tmp->next = node;
  }
  else *head = node;

}

void triPartition(ListNode** head, int pivot){

  ListNode *left = NULL, *middle = NULL, *right = NULL, *curr = *head, *tmp;

  // Partitions around pivot
  while(curr) {
    int value = curr->item;
    tmp = curr;
    curr = curr->next;
    if (value < pivot) append(&left, tmp);
    else if (value == pivot) append(&middle, tmp);
    else append(&right, tmp);
  }

  // Links up Partitions
  ListNode *newHead = joinPartition(left, middle, right);

  // Set headPtr
  *head = newHead;
}
