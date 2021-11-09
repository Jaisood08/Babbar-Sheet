int kthSmallest(int arr[], int l, int r, int k) 
    {
        priority_queue<int> PQ;
        
        for(int i=l;i<k;i++)
        {
            PQ.push(arr[i]);
        }
        for(int i=k;i<=r;i++)
        {
            int T = PQ.top();
            if(T>arr[i])
            {
                PQ.pop();
                PQ.push(arr[i]);
            }
        }
        return PQ.top();
    }