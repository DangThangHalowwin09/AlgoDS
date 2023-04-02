using System;
using System.Collections;
using System.Collections.Generic;
class GFG {
     
    // Stores the maximum sum of a path
    static int maxSumPath = 0;
     
    // Structure of a node in the tree
    class Node {
        
        public int val;
        public List<Node> child;
        
        public Node(int key)
        {
            val = key;
            child = new List<Node>();
        }
    }
     
    // Utility function to create a
    // new node in the tree
    static Node newNode(int key)
    {
        Node temp = new Node(key);
        return temp;
    }
      
    // Recursive function to calculate the
    // maximum sum in a path using DFS
    static void DFS(Node root, int sum)
    {
        // If current node is a leaf node
        if (root.child.Count == 0) {
            maxSumPath = Math.Max(maxSumPath, sum);
            return;
        }
      
        // Traversing all children of
        // the current node
        for (int i = 0;
             i < root.child.Count; i++) {
      
            // Recursive call for all
            // the children nodes
            DFS(root.child[i],
                sum + root.child[i].val);
        }
    }
     
  static void Main() {
    // Given Generic Tree
    Node root = newNode(1);
    (root.child).Add(newNode(2));
    (root.child).Add(newNode(3));
    (root.child[0].child).Add(newNode(4));
    (root.child[1].child).Add(newNode(6));
    (root.child[0].child).Add(newNode(5));
    (root.child[1]).child.Add(newNode(7));
    (root.child[1].child).Add(newNode(8));
    
    // Function Call
    DFS(root, root.val);
    
    Console.Write(maxSumPath);
  }
}