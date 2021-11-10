pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        pair<int,int> Ans = {1e-5, 1e5};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
        int D[k];
        memset(D,0,sizeof(D));
        int Max = INT_MIN;

        for(int i=0;i<k;i++)
        {
            PQ.push({KSortedArray[i][D[i]],i});
            if(Max<KSortedArray[i][D[i]])
            {
                Max = KSortedArray[i][D[i]];
            }
        }

        while(1)
        {
            pair<int,int> T = PQ.top();
            PQ.pop();
            // cout<<Max<<" , "<<T.first<<endl;
            if((Max - T.first) < (Ans.second - Ans.first))
            {
                Ans.first = T.first;
                Ans.second = Max;
            }
            D[T.second]++;
            if(D[T.second]>=n)
                break;
            PQ.push({KSortedArray[T.second][D[T.second]],T.second});
            if(Max<KSortedArray[T.second][D[T.second]])
                Max = KSortedArray[T.second][D[T.second]];
        }
        return Ans;
    }