#include <iostream>

using namespace std;

struct tree;
void insert_value();
void inorder_traversal(tree*);
void preorder_traversal(tree*);
void postorder_traversal(tree*);


tree *root = NULL, 
     *parent = NULL;

int main() {
    int num_nodes;
    cout << "How many values would you like to create on this tree? " << endl;
    cin >> num_nodes;
    cin.ignore();

    for(int i = 0; i < num_nodes; i++) {
        insert_value();
    }

    cout << "In-order Traversal: " << endl;
    inorder_traversal(root);
    cout << endl;
    cout << "Pre-order Traversal: " << endl;
    preorder_traversal(root);
    cout << endl;
    cout << "Post-order Traversal: " << endl;
    postorder_traversal(root);
    cout << endl;
    return 0;
}

struct tree
{
    tree *left, *right;
    char data;
};



void insert_value()  {
    //If no root exists, initialize our root node
    if (root == NULL) {
        root = new tree;
        cout << "enter value of root node\n";
        cin >> root->data;
        cin.ignore();
        root->right = NULL;
        root->left = NULL;
    //If a root exists, start the construction process
    } else {
        char value;
        //Set our initialize parent node to our tree's root
        parent = root;
        //Get user input for next node to insert
        cout<<"enter value of node\n";
        cin>>value;
        cin.ignore();

        //We must keep looping until we can insert our value
        while(true) {
            //If the value is greater than the parent node, traverse on the left
            if (value < parent->data) {
                //If the left side node is null, create a new node for our value here. Restart the process 
                if (parent->left == NULL) {
                    parent->left  = new tree;
                    parent = parent ->left;
                    parent->data  = value;
                    parent->left  = NULL;
                    parent->right = NULL; 
                    break;
                //If the left is not null, continue traversal by setting the current node as the parent and Restarting the process
                } else if (parent->left != NULL)  {
                    // if left null
                    parent  = parent->left;
                }
            //If the value is less than the parent node, traverse to the right
            } else if (value > parent->data) {
                //If the right side node is null, create a new node for our value here. Restart the process 
                if (parent->right == NULL) {
                    parent->right = new tree;
                    parent = parent->right ;
                    parent->data  = value;
                    parent->left  = NULL;
                    parent->right = NULL;
                    break;
                //If the right is not null, continue recursive traversal by setting the current node as the parent and Restarting the process
                } else if (parent->right  != NULL) {
                    parent = parent->right ;
                }
            } else {
                cout << "Cannot enter the same value twice" << endl;
                break;
            }
        }
    }
}

//L V R
void inorder_traversal(tree* tree) {
    if(tree != NULL) {
        //Recursively traverse the left subtree (L)
        inorder_traversal(tree->left);
        //output the value of our current node (V)
        cout << tree->data << " ";
        //Recursively traverse the right subtree (R)
        inorder_traversal(tree->right);
    }
}

//V L R
void preorder_traversal(tree* tree) {
    if(tree != NULL) {
        //output the value of our current node (V)
        cout << tree->data << " ";
        //Recursively traverse the left subtree (L)
        preorder_traversal(tree->left);
        //Recursively traverse the right subtree (R)
        preorder_traversal(tree->right);
    }
}

//L R V
void postorder_traversal(tree* tree) {
    if(tree != NULL) {
        //Recursively traverse the left subtree (L)
        postorder_traversal(tree->left);
        //Recursively traverse the right subtree (R)
        postorder_traversal(tree->right);
        //output the value of our current node (V)
        cout << tree->data << " ";
    }
}

