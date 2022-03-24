/* Implementation of Binary Trees... A Binary Tree Node can have maximum Two Child Nodes...
The Maximum Nodes with level x is 2^x... The Maximum Nodes in Tree of Height h is 2^h - 1... For x
Nodes the minimum possible level is log(x + 1)... A Binary tree with n leaves has atleast 
log(n + 1) + 1 number of levels */
#include <iostream>
#include <queue>
using namespace std;
class Node                    // Node class created for each Tree Node creation
{
    public:
    int data;         // Data member
    Node* left;      // Left Node pointer
    Node* right;     // Right Node pointer
    Node* root;      // Root Node pointer
    public:
    Node (int val)    // Parametrized Constructor
    {
        data = val;
        left = NULL;
        right = NULL;
        root = NULL;
    }
};
class BinaryTree     //  Class created for Binary Tree Implementation ( Non-Linear Data Structure )
{
    public:
    Node* InsertNodeInTree(Node* root, int val)   // Inserting Node recursively.. O(log n) time
    {
        if(root == NULL)               // If No root node is there, create one
            return new Node(val);
        if(val <= root -> data)   // If data is lesser than or equal to parent store in left subtree
            root -> left = InsertNodeInTree(root -> left, val);
        else         // If data is greater than the parent stor it in right subtree
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    void ShowTree(Node* root)   // Displaying tree with Node.. O(log n) time
    {
        Node* temp = root;
        if(temp == NULL)    // If Tree is empty nothing to show
            return;                            // Control moves out of the function
        ShowTree(temp -> left);     // Recursive Call
        cout << "Node: " << endl;
        if(temp -> left != NULL)    // If left subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> left -> data << "\t Left ( Occupied )" << endl;
        else      // If left subtree is empty
            cout << "\t" << temp -> data << "\t\t Left ( Empty )" << endl;
        if(temp -> right != NULL)   // If right subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> right -> data << "\t Right ( Occupied ) " << endl;
        else     // If right subtree is empty
            cout << "\t" << temp -> data << "\t\t Right ( Empty )" << endl;
        ShowTree(temp -> right);     // Recursive Call
    }
    int CalculateHeightOfTree(Node* root)  // It will run for every Node... O(n) time
    {   // Recursive Call to calculate Height of both Left and Right subtrees 
        if(root == NULL)
            return 0;      // If root is zero then backtrack (reaching the end of a branch )
        int height_left = CalculateHeightOfTree(root -> left);
        int height_right = CalculateHeightOfTree(root -> right);
        return max(height_left, height_right) + 1;    // Adding one to the maximum to include root Node also
    }
    int CalculateDiameterOfTree(Node* root)
    {
        if(root == NULL)  // If current is empty add Null and backtrack
            return 0;
        int dia_left = CalculateDiameterOfTree(root -> left);   // Taking diameter of Left Subtree Recursively
        int dia_right = CalculateDiameterOfTree(root -> right);  // Taking diameter of Right Subtree Recursively
        int h_left = CalculateHeightOfTree(root -> left);         // Taking height of Left Subtree Recursively
        int h_right = CalculateHeightOfTree(root -> right);     // Taking height of the Right Subtree Recursively
        int curr_dia = h_left + h_right + 1;                 // Adding diameter of left and right 
        return max(curr_dia, max(dia_left, dia_right));   // Taking maximum of both left and right ( if the tree has only one
    }                                                     // Side entirely otherwise curr dia will be more than the sum of dia of left and right
};
int main()
{
    Node* root = NULL;      // Root node initialization
    BinaryTree binarytree;      // Object creation of Binary Tree
    int s, x;
    cout << "Enter root Node value : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);    // Root Node created
    cout << "Enter the number of Nodes to Insert in the Binary Search Tree : ";
    cin >> s;
    for(int i = 1; i <= s; i++)   // Loop begins
    {
        cout << "Enter the New Node value : ";
        cin >> x;
        binarytree.InsertNodeInTree(root, x);   // Calling Insert Tree function
    }
    binarytree.ShowTree(root);
    cout << "The Height of Binary Tree is : " << binarytree.CalculateHeightOfTree(root) << endl;
    cout << "The Diameter of Binary Tree is : " << binarytree.CalculateDiameterOfTree(root) << endl;
    return 0;          // End of Program
}