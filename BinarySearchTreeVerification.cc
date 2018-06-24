/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include <limits.h>
bool isBST (Node *node, int min, int max)
{
    if (node == NULL)
    {
        return true;
    }
    else if ( min < node->data && node->data < max)
    {
        return isBST (node->right, node->data, max) &&
               isBST (node->left, min , node->data);
    }
    else
    {
        return false;
    }      
}

bool checkBST(Node* root) {
            
    return (isBST (root->right, root->data, INT_MAX) &&
            isBST (root->left, INT_MIN, root->data)
           );        

}
