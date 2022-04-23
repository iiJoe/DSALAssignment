
# Table of Contents

1.  [Linked Lists (Week 3)](#linked-list)
    1.  [Q1: Reverse Nodes from A to B](#org57cc1ba)
    2.  [Q2: Tri-Partition](#org90f1502)
    3.  [Q3: Reverse Every K Nodes](#orgc460025)
    4.  [Q4: Rearrange Nodes](#orgd876150)
2.  [Stack & Queue (Week 4)](#stack-queue)
    1.  [Q5: Arithmetic Expression Queue](#org85d9e4f)
    2.  [Q6: Number of Visible Pairs](#orga48952a)
    3.  [Q7: Infix String to Prefix Expression](#org9e44c0a)
3.  [Binary Trees (Week 5)](#binary-trees)
    1.  [Q6: Expression Trees](#org03347b4)
    2.  [Q7: The Moving Cost from A to B in a Binary Tree](#orgea72ef8)
    3.  [Q8: Construct A Binary Tree](#org1d1e6ca)
4.  [Binary Search Trees (Week 6)](#org98ffeff)
    1.  [Q1: Finding Largest Binary Search Subtree](#orgba47d33)
    2.  [Q2: Correction of Binary Search Tree](#orgcd12d59)
5.  [Hash Table and Graph (Week 9)](#hash-table)
    1.  [Q6: Degree of a Vertex](#org8c05fbc)
    2.  [Q7: Adjacency List to Adjacency Matrix](#orgb40bf57)
    3.  [Q8: Hash Table - Delete a Key](#orgd9e852c)
6.  [BFS & DFS (Week 10)](#orgeae5b4d)
    1.  [Q6: Undirected Graph Connection](#org969f85a)
    2.  [Q7: Shortest Distance](#org06a0e3d)
    3.  [Q8: Directed Graph Connection](#org413c375)
7.  [Backtracking and DP (Week 12)](#org68ebf28)
    1.  [Q6: Linear Recurrence](#org5c71cbf)
    2.  [Q7: Knapsack](#orgde8d635)
    3.  [Q8: Coloring Regions](#orgc959538)

Questions from SC1007 assignments  


<a id="linked-list"></a>

# Linked Lists (Week 3)


<a id="org57cc1ba"></a>

## Q1: Reverse Nodes from A to B

Input: Start (Integer), End(Integer), singly linked list.  
Write a function to reverse node of the linked list from start index to end index. If indices are out of range / invalid, linked list remains unchanged.  

Sample Input:  

    2 5
    1.1 1.2 1.3 1.4 1.5 1.6 1.7 a

Sample Output:  

    1.10 1.20 1.60 1.50 1.40 1.30 1.70 


<a id="org90f1502"></a>

## Q2: Tri-Partition

Input: Pivot (Integer), singly linked list  
Move nodes with number less than the pivot to the front, followed by nodes with the same number, and nodes greater than the pivot.  

Sample Input:  

    5
    8 1 5 5 5 7 2 a

Sample Output:  

    1 2 5 5 5 8 7 


<a id="orgc460025"></a>

## Q3: Reverse Every K Nodes

Input: K (integer), Singly linked list  
Every K nodes form a segment. Reverse every segment in the linked list. If the last few nodes are less than K, ignore them.  

Sample Input:  

    3
    1 2 3 4 5 6 7 8 9 10 a

Sample Output:  

    3 2 1 6 5 4 9 8 7 10


<a id="orgd876150"></a>

## Q4: Rearrange Nodes

Input: Singly linked list  
Given a linked list, split the list into two lists L, R (with the second list having one more node if length is odd). Rearrange the list such that R(0) -> L(0) -> R(1) -> &#x2026;. Divide the resultant list the same manner and rearrange such that L(0) -> R(0) -> L(1) -> &#x2026;. If length of list is odd, the last node remains at the last position.  

Sample Input:  

    1 2 3 4 5 6 7 8 9 10 a

Sample Output:  

    6 3 1 9 7 4 2 10 8 5 


<a id="stack-queue"></a>

# Stack & Queue (Week 4)


<a id="org85d9e4f"></a>

## Q5: Arithmetic Expression Queue

Input: Arithmetic Expression (String)  
Given a character string of an integer arithmetic expression, write a function to split the operands, operators and parentheses into a queue.  

Sample Input:  

    1+15*121/(1311-84)

Sample Output:  

    1  +  15  *  121  /  (  1311  -  84  ) 


<a id="orga48952a"></a>

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


<a id="org9e44c0a"></a>

## Q7: Infix String to Prefix Expression

Input: Infix expression (String)  
Convert an infix expression into a prefix expression stored in a linked list.  

Sample Input:  

    99+(88-77)*(66/(55-44)+33)

Sample Output:  

    99  *  -  88  77  +  /  66  -  55  44  33 


<a id="binary-trees"></a>

# Binary Trees (Week 5)


<a id="org03347b4"></a>

## Q6: Expression Trees

Input: Prefix Expression (String)  
Create an expression tree structure using a prefix expression. Write two functions to print the tree nodes by in-order and post-order traversal to print the infix and postfix expression respectively. Write an expession evaluation function to calculate the given arithmetic expression.  

Sample Input:  

    +  99  *  -  88  77  +  /  66  -  55  44  33 

Sample Output:  

    99 + 88 - 77 * 66 / 55 - 44 + 33 
    99 88 77 - 66 55 44 - / 33 + * + 
    528.00


<a id="orgea72ef8"></a>

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


<a id="org1d1e6ca"></a>

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


<a id="org98ffeff"></a>

# Binary Search Trees (Week 6)


<a id="orgba47d33"></a>

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


<a id="orgcd12d59"></a>

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


<a id="hash-table"></a>

# Hash Table and Graph (Week 9)


<a id="org8c05fbc"></a>

## Q6: Degree of a Vertex

Write a function to compute vertex degrees using adjacency matrix  

Sample Input:  

    7
    1 2
    1 3
    2 3
    2 4
    4 1
    4 3
    4 6
    5 3
    5 7
    6 1
    6 3
    7 4
    7 5
    a

Sample Output:  

    Enter the number of vertices:
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Print graph matrix 
    0	1	1	1	0	1	0	
    1	0	1	1	0	0	0	
    1	1	0	1	1	1	0	
    1	1	1	0	0	1	1	
    0	0	1	0	0	0	1	
    1	0	1	1	0	0	0	
    0	0	0	1	1	0	0	
    
    Print vertex's degree 
    1: 4 degree
    2: 3 degree
    3: 5 degree
    4: 5 degree
    5: 2 degree
    6: 3 degree
    7: 2 degree


<a id="orgb40bf57"></a>

## Q7: Adjacency List to Adjacency Matrix

Write a function to convert an adjacency list to an adjacency matrix  

Sample Input:  

    7
    1 2
    1 3
    2 3
    2 4
    4 1
    4 3
    4 6
    5 3
    5 7
    6 1
    6 3
    7 4
    7 5
    a

Sample Output:  

    Enter the number of vertices:
    Enter two vertices which are adjacent to each other (enter a to stop):
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Enter two vertices which are adjacent to each other: (enter a to stop)
    Adjacency matrix:
    0	1	1	1	0	1	0	
    1	0	1	1	0	0	0	
    1	1	0	1	1	1	0	
    1	1	1	0	0	1	1	
    0	0	1	0	0	0	1	
    1	0	1	1	0	0	0	
    0	0	0	1	1	0	0


<a id="orgd9e852c"></a>

## Q8: Hash Table - Delete a Key

Implement the function of key deletion in a closed addressing hash table with a modulo hash function. Return 1 if the deletion is successful, 0 if not.  

Sample Input:  

    1
    3
    2
    1
    2
    2
    2
    3
    2
    4
    2
    5
    2
    6
    2
    7
    2
    8
    2
    9
    3
    5
    4
    5
    3
    5
    3
    4
    3
    6
    6

Sample Output:  

    ============= Hash Table ============
    |1. Create a hash table             |
    |2. Insert a key to the hash table  |
    |3. Search a key in the hash table  |
    |4. Delete a key in the hash table  |
    |5. Print the hash table            |
    |6. Quit                            |
    =====================================
    Enter selection: Enter the size of hash table:
    HashTable is created.
    Enter selection: Enter a key to be inserted:
    1 is inserted.
    Enter selection: Enter a key to be inserted:
    2 is inserted.
    Enter selection: Enter a key to be inserted:
    3 is inserted.
    Enter selection: Enter a key to be inserted:
    4 is inserted.
    Enter selection: Enter a key to be inserted:
    5 is inserted.
    Enter selection: Enter a key to be inserted:
    6 is inserted.
    Enter selection: Enter a key to be inserted:
    7 is inserted.
    Enter selection: Enter a key to be inserted:
    8 is inserted.
    Enter selection: Enter a key to be inserted:
    9 is inserted.
    Enter selection: Enter a key for searching in the HashTable:
    5 is found.
    Enter selection: Enter a key to be deleted:
    5 is deleted.
    Enter selection: Enter a key for searching in the HashTable:
    5 is not found.
    Enter selection: Enter a key for searching in the HashTable:
    4 is found.
    Enter selection: Enter a key for searching in the HashTable:
    6 is found.
    Enter selection:


<a id="orgeae5b4d"></a>

# BFS & DFS (Week 10)


<a id="org969f85a"></a>

## Q6: Undirected Graph Connection

Using DFS, determine if an undirected graph is connected. Assume input graph has no duplicate edges or invalid links  

Sample Input:  

    5
    1 2
    1 3
    4 5
    a

Sample Output:  

    Enter the number of vertices:
    Enter two vertices which are adjacent to each other: (press a to stop)
    Enter two vertices which are adjacent to each other: (press a to stop)
    Enter two vertices which are adjacent to each other: (press a to stop)
    Enter two vertices which are adjacent to each other: (press a to stop)
    The graph is not connected.


<a id="org06a0e3d"></a>

## Q7: Shortest Distance

Using BFS, write a function to find the shortest distance from \(v\) to \(w\) in an undirected graph. If there is no path from \(v\) to \(w\), return -1. Assume input graph has no duplicate edges or invalid links  

Sample Input:  

    5
    1 2
    1 4
    2 3
    3 4
    4 5
    a
    1 5

Sample Output:  

    Enter the number of vertices:
    Enter two vertices which are adjacent to each other:
    Enter two vertices which are adjacent to each other: (press a to stop)
    Enter two vertices which are adjacent to each other: (press a to stop)
    Enter two vertices which are adjacent to each other: (press a to stop)
    Enter two vertices which are adjacent to each other: (press a to stop)
    Enter two vertices which are adjacent to each other: (press a to stop)
    Enter two vertices for finding their shortest distance: (press a to stop)
    The shortest distance is 2


<a id="org413c375"></a>

## Q8: Directed Graph Connection

Using DFS, determine if a directed graph is strongly connected. Assume input graph has no duplicate edges or invalid links  

Sample Input:  

    5
    1 2
    1 4
    2 3
    3 4
    4 1
    4 5
    a

Sample Output:  

    Enter the number of vertices:
    Enter a directed edge: (press a to stop)
    Enter a directed edge: (press a to stop)
    Enter a directed edge: (press a to stop)
    Enter a directed edge: (press a to stop)
    Enter a directed edge: (press a to stop)
    Enter a directed edge: (press a to stop)
    Enter a directed edge: (press a to stop)
    The graph is not strongly connected.


<a id="org68ebf28"></a>

# Backtracking and DP (Week 12)


<a id="org5c71cbf"></a>

## Q6: Linear Recurrence

Given a function \(F(n): F(n - 1) + 2 * F(n - 2) - 3 * F(n - 3)\) with \(F(0) = 0, F(1) = 1, F(2) = 2\),  
Write a function using DP to calculate the value of F(n)  

Sample Input:  

    5

Sample Output:  

    Enter the value of n:
    The value of F(5) is: 7


<a id="orgde8d635"></a>

## Q7: Knapsack

Given n items, where item i has size s<sub>i</sub> and value v<sub>i</sub>, place the items into a knapsack of capacity C such that the items contain the maximum possible value.  

Sample Input:  

    4
    5
    2 1 3 2
    12 10 20 15

Sample Output:  

    Enter the number of items n:
    Enter the capacity C:
    Enter the sizes of items (as a list, separate by spacing:
    Enter the values of items (as a list, separate by spacing:
    The maximum value is: 37 


<a id="orgc959538"></a>

## Q8: Coloring Regions

Write a function to count the number of solutions of the ways to color V regions and m colors.  

Sample Input:  

    3
    4
    0 1 1 1
    1 0 1 0
    1 1 0 1
    1 0 1 0

Sample Output:  

    Enter number of colors:
    Enter number of regions:
    Input the adjacency matrix:
    There is/are total 6 solution(s)

