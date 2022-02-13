
# Table of Contents

1.  [Linked Lists (Week 3)](#linked-list)
    1.  [Q1: Reverse Nodes from A to B](#org0188ae2)
    2.  [Q2: Tri-Partition](#orgb52c6b2)
    3.  [Q3: Reverse Every K Nodes](#org3c7ca71)
    4.  [Q4: Rearrange Nodes](#org3fe7da2)
2.  [Stack & Queue (Week 4)](#orga1eedfb)
    1.  [Q5: Arithmetic Expression Queue](#orgd7b0bd9)
    2.  [Q6: Number of Visible Pairs](#org0212fb0)
    3.  [Q7: Infix String to Prefix Expression](#org704f219)

Questions from SC1007 assignments  


<a id="linked-list"></a>

# Linked Lists (Week 3)


<a id="org0188ae2"></a>

## Q1: Reverse Nodes from A to B

Input: Start (Integer), End(Integer), singly linked list.  
Write a function to reverse node of the linked list from start index to end index. If indices are out of range / invalid, linked list remains unchanged.  

Sample Input:  

    2 5
    1.1 1.2 1.3 1.4 1.5 1.6 1.7 a

Sample Output:  

    1.10 1.20 1.60 1.50 1.40 1.30 1.70 


<a id="orgb52c6b2"></a>

## Q2: Tri-Partition

Input: Pivot (Integer), singly linked list  
Move nodes with number less than the pivot to the front, followed by nodes with the same number, and nodes greater than the pivot.  

Sample Input:  

    5
    8 1 5 5 5 7 2 a

Sample Output:  

    1 2 5 5 5 8 7 


<a id="org3c7ca71"></a>

## Q3: Reverse Every K Nodes

Input: K (integer), Singly linked list  
Every K nodes form a segment. Reverse every segment in the linked list. If the last few nodes are less than K, ignore them.  

Sample Input:  

    3
    1 2 3 4 5 6 7 8 9 10 a

Sample Output:  

    3 2 1 6 5 4 9 8 7 10


<a id="org3fe7da2"></a>

## Q4: Rearrange Nodes

Input: Singly linked list  
Given a linked list, split the list into two lists L, R (with the second list having one more node if length is odd). Rearrange the list such that R(0) -> L(0) -> R(1) -> &#x2026;. Divide the resultant list the same manner and rearrange such that L(0) -> R(0) -> L(1) -> &#x2026;. If length of list is odd, the last node remains at the last position.  

Sample Input:  

    1 2 3 4 5 6 7 8 9 10 a

Sample Output:  

    6 3 1 9 7 4 2 10 8 5 


<a id="orga1eedfb"></a>

# Stack & Queue (Week 4)


<a id="orgd7b0bd9"></a>

## Q5: Arithmetic Expression Queue

Input: Arithmetic Expression (String)  
Given a character string of an integer arithmetic expression, write a function to split the operands, operators and parentheses into a queue.  

Sample Input:  

    1+15*121/(1311-84)

Sample Output:  

    1  +  15  *  121  /  (  1311  -  84  ) 


<a id="org0212fb0"></a>

## Q6: Number of Visible Pairs

Input: Number of test cases, mountains (doubly circular linked list)  
Given a doubly circular linked list with non-negative integers, where each integer represents the height of a mountain, find the number of mutually visible pairs.  
The mountains A and B are mutually visible if  

1.  A and B are not the same mountain
2.  A and B are adjacent
3.  When A and B are not adjacent, &forall; x &isin; {mountains between A and B (either clockwise or anticlockwise)}, height(x) <=  min(height(A), height(B))

Sample Input:  

    3
    1 2 3 4 5 a
    5 2 2 4 3 a
    5 4 4 4 3 2 1 5 1 a

Sample Output:  

    Current List: 5 4 3 2 1
    7 Pairs.
    Current List: 3 4 2 2 5
    8 Pairs.
    Current List: 1 5 1 2 3 4 4 4 5
    18 Pairs.


<a id="org704f219"></a>

## Q7: Infix String to Prefix Expression

Input: Infix expression (String)  
Convert an infix expression into a prefix expression stored in a linked list.  

Sample Input:  

    99+(88-77)*(66/(55-44)+33)

Sample Output:  

    99  *  -  88  77  +  /  66  -  55  44  33 

