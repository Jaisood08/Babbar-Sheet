vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> V;
        int in = 0;
        multiset<int> S;
        for(int i=0;i<k;i++)
        {
            S.insert(arr[i]);
        }
        V.push_back(*(--S.end()));
        
        for(int i=k;i<n;i++)
        {
            S.erase(S.find(arr[in]));
            S.insert(arr[i]);
            V.push_back(*(--S.end()));
            in++;
        }
        return V;
    }