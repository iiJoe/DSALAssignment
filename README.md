
# Table of Contents

1.  [Linked Lists (Week 3)](#linked-list)
    1.  [Q1: Reverse Nodes from A to B](#org86d93a3)
    2.  [Q2: Tri-Partition](#org363fb50)
    3.  [Q3: Reverse Every K Nodes](#org7c5697f)
    4.  [Q4: Rearrange Nodes](#org6c813a4)
2.  [Stack & Queue (Week 4)](#stack-queue)
    1.  [Q5: Arithmetic Expression Queue](#org30f9d16)
    2.  [Q6: Number of Visible Pairs](#org0e9ca3f)
    3.  [Q7: Infix String to Prefix Expression](#org6b3b768)
3.  [Binary Trees (Week 5)](#binary-trees)
    1.  [Q6: Expression Trees](#orgd13dad8)
    2.  [Q7: The Moving Cost from A to B in a Binary Tree](#orgc7350e3)
    3.  [Q8: Construct A Binary Tree](#orgf29d656)
4.  [Binary Search Trees (Week 6)](#org57b70aa)
    1.  [Q1: Finding Largest Binary Search Subtree](#org7b0ca3a)
    2.  [Q2: Correction of Binary Search Tree](#org0924164)

Questions from SC1007 assignments  


<a id="linked-list"></a>

# Linked Lists (Week 3)


<a id="org86d93a3"></a>

## Q1: Reverse Nodes from A to B

Input: Start (Integer), End(Integer), singly linked list.  
Write a function to reverse node of the linked list from start index to end index. If indices are out of range / invalid, linked list remains unchanged.  

Sample Input:  

    2 5
    1.1 1.2 1.3 1.4 1.5 1.6 1.7 a

Sample Output:  

    1.10 1.20 1.60 1.50 1.40 1.30 1.70 


<a id="org363fb50"></a>

## Q2: Tri-Partition

Input: Pivot (Integer), singly linked list  
Move nodes with number less than the pivot to the front, followed by nodes with the same number, and nodes greater than the pivot.  

Sample Input:  

    5
    8 1 5 5 5 7 2 a

Sample Output:  

    1 2 5 5 5 8 7 


<a id="org7c5697f"></a>

## Q3: Reverse Every K Nodes

Input: K (integer), Singly linked list  
Every K nodes form a segment. Reverse every segment in the linked list. If the last few nodes are less than K, ignore them.  

Sample Input:  

    3
    1 2 3 4 5 6 7 8 9 10 a

Sample Output:  

    3 2 1 6 5 4 9 8 7 10


<a id="org6c813a4"></a>

## Q4: Rearrange Nodes

Input: Singly linked list  
Given a linked list, split the list into two lists L, R (with the second list having one more node if length is odd). Rearrange the list such that R(0) -> L(0) -> R(1) -> &#x2026;. Divide the resultant list the same manner and rearrange such that L(0) -> R(0) -> L(1) -> &#x2026;. If length of list is odd, the last node remains at the last position.  

Sample Input:  

    1 2 3 4 5 6 7 8 9 10 a

Sample Output:  

    6 3 1 9 7 4 2 10 8 5 


<a id="stack-queue"></a>

# Stack & Queue (Week 4)


<a id="org30f9d16"></a>

## Q5: Arithmetic Expression Queue

Input: Arithmetic Expression (String)  
Given a character string of an integer arithmetic expression, write a function to split the operands, operators and parentheses into a queue.  

Sample Input:  

    1+15*121/(1311-84)

Sample Output:  

    1  +  15  *  121  /  (  1311  -  84  ) 


<a id="org0e9ca3f"></a>

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


<a id="org6b3b768"></a>

## Q7: Infix String to Prefix Expression

Input: Infix expression (String)  
Convert an infix expression into a prefix expression stored in a linked list.  

Sample Input:  

    99+(88-77)*(66/(55-44)+33)

Sample Output:  

    99  *  -  88  77  +  /  66  -  55  44  33 


<a id="binary-trees"></a>

# Binary Trees (Week 5)


<a id="orgd13dad8"></a>

## Q6: Expression Trees

Input: Prefix Expression (String)  
Create an expression tree structure using a prefix expression. Write two functions to print the tree nodes by in-order and post-order traversal to print the infix and postfix expression respectively. Write an expession evaluation function to calculate the given arithmetic expression.  

Sample Input:  

    +  99  *  -  88  77  +  /  66  -  55  44  33 

Sample Output:  

    99 + 88 - 77 * 66 / 55 - 44 + 33 
    99 88 77 - 66 55 44 - / 33 + * + 
    528.00


<a id="orgc7350e3"></a>

## Q7: The Moving Cost from A to B in a Binary Tree

Input: Binary Tree with Weighted Nodes  
In a given binary tree, each node represents a toll gate, which value indicates a unique non-negative toll fee. To move from one node to another, the total cost is the toll fees for every gate that is passed. Calculate the mininmum of the total cost.  

Sample Input: (a represents an edge, @ represents no edge)  

    1 a a
    2 a a
    3 a @
    4 a a
    7 @ @
    8 a @
    5 @ @
    6 @ @
    9 @ @
    5 7

Sample Output:  

    1
    |---2
    |	|---4
    |	|	|---5
    |	|	|___6
    |	|___7
    |___3
    |	|---8
    |	|	|---9
    Distance is 18


<a id="orgf29d656"></a>

## Q8: Construct A Binary Tree

Input: Pre-order traversal String, Post-order traversal String  
Given a valid preorder and postorder traversal strings, write a function to reconstruct the binary tree. (If a node only has one child, the child must be the left child)  

Sample Input:  

    124567389ABC
    56472BCA9831

Sample Output:  

    124567389ABC
    56472BCA9831
    546271BAC983


<a id="org57b70aa"></a>

# Binary Search Trees (Week 6)


<a id="org7b0ca3a"></a>

## Q1: Finding Largest Binary Search Subtree

Input: Binary Tree (level-by-level traversal string)  
Write a function to find the largest binary search subtree from a given binary tree.  

Sample Input:  

    70 35 79 15 50 -1 99 18 -1 40 60 a

Sample Output:  

    Enter a list of numbers for a Binary Tree, terminated by any non-digit character: 
    The input binary tree:
    70
    |---35
    |	|---15
    |	|	|---18
    |	|___50
    |	|	|---40
    |	|	|___60
    |___79
    |	|___99
    
    The largest binary search subtree:
    50
    |---40
    |___60


<a id="org0924164"></a>

## Q2: Correction of Binary Search Tree

Input: Binary Search Tree (level-by-level traversal string)  
For a given binary search tree, the data of two nodes are swapped. Find the two error nodes in the binary search tree and swap the values.  

Sample Input:  

    4 2 6 1 -1 -1 7 -1 0 a

Sample Output:  

    Enter a list of numbers for a Binary Tree, terminated by any non-digit character: 
    The input binary search tree:
    4
    |---2
    |	|---1
    |	|	|___0
    |___6
    |	|___7
    
    The corrected binary search tree:
    4
    |---2
    |	|---0
    |	|	|___1
    |___6
    |	|___7

