# C-Binary_search_tree 
 
<strong>Self-balancing binary search tree <em>(a.k.a. AVL tree)</em></strong> <br>
 
Program options:<br>
1 - Creates a tree from scratch <br>

2 - Creates a tree by adding nodes one at a time <br>

3 - Deletes a node by providing its value <br>
 
4 - Prints tree elements: <em>in-order</em> or <em>pre-order</em> with their respectives balance factors
 
5 - Ends program <br><br>

- This particular tree uses left->right orientation

- in-order: (1) visits all nodes from the root's left side, (2)visits root, and then(3) visits all nodes from root's right side <br>

- pre-order: (1) visits root, (2) visits left-child-node and calls pre-order, (3) visits right-child-node and calls pre-order <br>

- any given node has a <strong>balance factor</strong> of 1, 0, or -1

- calculating the <strong>balance factor</strong> of any given node: (depth of left-sub-node) - (depth of right-sub-node)

- repeated values aren't added to the tree

- <em>binary_tree.exe </em> to try it out
