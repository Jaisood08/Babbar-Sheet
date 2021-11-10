 Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue<int,vector<int>,greater<int>> PQ;
        
        for(int i=0;i<K;i++)
        {
            Node* temp = arr[i];
            while(temp!=NULL)
            {
                PQ.push(temp->data);
                temp = temp->next;
            }
        }
        
        Node *Head = NULL;
        Node *temp = NULL;
        
        while(!PQ.empty())
        {
            if(Head == NULL)
            {
                temp = new Node(PQ.top());
                Head = temp;
            }
            else
            {
                temp->next = new Node(PQ.top());
                temp = temp->next;
            }
            PQ.pop();
        }
        return Head;
    }