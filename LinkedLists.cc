Node* removeDuplicates(Node *head)
{
  Node *tmp = head;
  Node *cur;
  Node *dup;
  
  while (tmp!=NULL && tmp->next!=NULL)
  {
      cur = tmp;
      while(cur->next != NULL)
      {
          if (tmp->data == cur->next->data)
          {
              dup = cur->next;
              cur->next = cur->next->next;
              delete(dup);
          }
          else
          {
             cur = cur->next;    
          }
      }
      tmp = tmp->next;
  }
    return head;
}
