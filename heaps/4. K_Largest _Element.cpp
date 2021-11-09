vector<int> kLargest(int arr[], int n, int k) 
	{
	    priority_queue<int> PQ;
	    
	    for(int i=0;i<n;i++)
	    {
	        PQ.push(arr[i]);
	    }
	    
	    vector<int> V;
	    for(int i=0;i<k;i++)
	    {
	        V.push_back(PQ.top());
	        PQ.pop();
	    }
	    return V;
	}