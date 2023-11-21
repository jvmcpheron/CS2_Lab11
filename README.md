# CS2_Lab11

## Introduction
As discussed in class, a binary search tree can end up being unbalanced.  Keeping a tree closer to balance is a bit complex, but in this lab I want you to do some simple balancing along the edges of a tree.  Specifically, I want you to look through a tree and rebalance nodes that fit certain criteria:

A parent node A that has one child B, and
node B has one child C, and
C has no children
There are four possible ways this can happen, as illustrated in the binary search tree shown below:

The unbalanced nodes that meet these requirements are:

10, with children 7 and then 5,
40, with children 30 and then 35,
60, with children 70 and then 65, and 
90, with children 95 and then 100
You should write code that recognizes when these occur in traversing a tree and the code should then rebalance those little subtrees of the original tree.  The result of rebalancing those subtrees would be:


## What to Submit
Submit your solution as a CPP file. Give the file the name AssignmentTypeNumberLastNameFirstName.cpp (so, for example, my submission for Lab 3 would be named Lab3MaclinRichard.cpp). You should also include your first and last name in the file as a comment. Add a long comment in your code showing examples of the results produced from your code.