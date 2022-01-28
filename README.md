
# Table of Contents

1.  [Linked Lists](#linked-list)
    1.  [Q1: Reverse Nodes from A to B](#org6cb834c)
    2.  [Q2: Tri-Partition](#org0f18682)
    3.  [Q3: Reverse Every K Nodes](#orgde98915)
    4.  [Q4: Rearrange Nodes](#org1653e08)

Contains the questions done for this module's assignments  


<a id="linked-list"></a>

# Linked Lists


<a id="org6cb834c"></a>

## Q1: Reverse Nodes from A to B

Input: Start (Integer), End(Integer), singly linked list.  
Write a function to reverse node of the linked list from start index to end index. If indices are out of range / invalid, linked list remains unchanged.  

Sample Input:  

    2 5
    1.1 1.2 1.3 1.4 1.5 1.6 1.7 a

Sample Output:  

    1.10 1.20 1.60 1.50 1.40 1.30 1.70 


<a id="org0f18682"></a>

## Q2: Tri-Partition

Input: Pivot (Integer), singly linked list  
Move nodes with number less than the pivot to the front, followed by nodes with the same number, and nodes greater than the pivot.  

Sample Input:  

    5
    8 1 5 5 5 7 2 a

Sample Output:  

    1 2 5 5 5 8 7 


<a id="orgde98915"></a>

## Q3: Reverse Every K Nodes

Input: K (integer), Singly linked list  
Every K nodes form a segment. Reverse every segment in the linked list. If the last few nodes are less than K, ignore them.  

Sample Input:  

    3
    1 2 3 4 5 6 7 8 9 10 a

Sample Output:  

    3 2 1 6 5 4 9 8 7 10


<a id="org1653e08"></a>

## Q4: Rearrange Nodes

Input: Singly linked list  
Given a linked list, split the list into two lists L, R (with the second list having one more node if length is odd). Rearrange the list such that R(0) -> L(0) -> R(1) -> &#x2026;. Divide the resultant list the same manner and rearrange such that L(0) -> R(0) -> L(1) -> &#x2026;. If length of list is odd, the last node remains at the last position.  

Sample Input:  

    1 2 3 4 5 6 7 8 9 10 a

Sample Output:  

    6 3 1 9 7 4 2 10 8 5 

