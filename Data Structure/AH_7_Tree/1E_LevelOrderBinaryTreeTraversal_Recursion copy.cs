using System;
using System.Collections.Generic;
 
/* Class to represent Tree node */
public class Node {
    public int data;
    public Node left, right;
 
    public Node(int item)
    {
        data = item;
        left = null;
        right = null;
    }
}
 
/* Class to print Level Order Traversal */
public class BinaryTree {
 
    Node root;
 
    /* Given a binary tree. Print
    its nodes in level order using
     array for implementing queue */
    void printLevelOrder()
    {
        Queue<Node> queue = new Queue<Node>();
        queue.Enqueue(root);
        while (queue.Count != 0) {
 
            Node tempNode = queue.Dequeue();
            Console.Write(tempNode.data + " ");
 
            /*Enqueue left child */
            if (tempNode.left != null) {
                queue.Enqueue(tempNode.left);
            }
 
            /*Enqueue right child */
            if (tempNode.right != null) {
                queue.Enqueue(tempNode.right);
            }
        }
    }
 
    // Driver code
    public static void Main()
    {
        /* creating a binary tree and entering
        the nodes */
        BinaryTree tree_level = new BinaryTree();
        tree_level.root = new Node(1);
        tree_level.root.left = new Node(2);
        tree_level.root.right = new Node(3);
        tree_level.root.left.left = new Node(4);
        tree_level.root.left.right = new Node(5);
 
        Console.WriteLine("Level order traversal "
                          + "of binary tree is - ");
        tree_level.printLevelOrder();
    }
}