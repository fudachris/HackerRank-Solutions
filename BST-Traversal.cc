int height(Node * node)
{
    if (node==NULL)
    {
        return 0;
    }
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (rheight>lheight)
        {
            return rheight+1;
        }
        else
        {
            return lheight+1;
        }
    }
}

void printLevel(Node * root, int level)
{
    if (root==NULL)
    {
        return;
    }
    else if (level==1)
    {
        cout << root->data << " ";
    }
    else if (level >1)
    {
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
}
void levelOrder(Node * root){

    int h = height(root);
    
    for (int i = 0; i <= h; i++)
    {
        printLevel(root,i);
    }
}
