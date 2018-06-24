int getHeight(Node* root){

	Node *tmp = root;

	if (root == NULL)
	{
		  return -1;
	}

	int countLeft = getHeight(tmp->left);
	int countRight = getHeight(tmp->right);

  if (countLeft >countRight)
  {
      return countLeft+1;
  }
  else
  {
      return countRight+1;
  }              
}


