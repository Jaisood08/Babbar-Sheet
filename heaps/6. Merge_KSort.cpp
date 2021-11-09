    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> V;
        priority_queue<int> PQ;
        
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<K;j++)
            {
                PQ.push(arr[i][j]);
            }
        }
        while(!PQ.empty())
        {
            V.push_back(PQ.top());
            PQ.pop();
        }
        reverse(V.begin(),V.end());

        return V;
    }