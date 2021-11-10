bool isHeap(struct Node* root) 
  {
    queue<Node*> D;
    D.push(root);
    
    while(!D.empty())
    {
        int N = D.size();
        bool F = 0;
        
        while(N--)
        {
            Node* temp = D.front();
            //cout<<temp->data<<" "; 
            D.pop();
            
            //Complete Binary Tree
            if(F == 1)
            {
                if(temp->left !=NULL || temp->right!= NULL)
                {
                    return false;
                }
            }
            if(temp->left ==NULL && temp->right== NULL)
            {
                F = 1;
            }
            if(temp->left ==NULL && temp->right!= NULL)
            {
                return false;
            }
            //Value Check
            
            if(temp->left !=NULL)
            {
                if(temp->data<temp->left->data)
                {
                    return false;
                }
                D.push(temp->left);
            }
            if(temp->right !=NULL )
            {
                if(temp->data<temp->right->data)
                {
                    return false;
                }
                D.push(temp->right);
            }
        }
        
    }
    return true;
  }