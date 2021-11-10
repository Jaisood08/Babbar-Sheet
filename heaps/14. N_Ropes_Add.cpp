    long long minCost(long long arr[], long long n) 
    {
        priority_queue<long long,vector<long long>,greater<long long>> PQ;
        
        for(long long i=0;i<n;i++)
            PQ.push(arr[i]);
        long long Cost = 0;
        while(PQ.size()>=2)
        {
            long long a = PQ.top();
            PQ.pop();
            long long b = PQ.top();
            PQ.pop();
            long long temp = a+b;
            PQ.push(temp);
            Cost += temp;
        }
        
        return Cost;
    }