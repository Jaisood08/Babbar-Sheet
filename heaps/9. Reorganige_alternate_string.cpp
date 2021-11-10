string reorganizeString(string s) 
    {
        
        unordered_map<char,int> M;
        
        for(auto i:s)
        {
            M[i]++;
        }
        
        priority_queue<pair<int,char>> PQ;
        
        for(auto i:M)
        {
            PQ.push({i.second,i.first});
        }

        string A;
        pair<int,char> B = PQ.top();
        PQ.pop();
        A = A+B.second;
        while(!PQ.empty())
        {
            pair<int,char> T = PQ.top();
            PQ.pop();
            A = A+T.second;
            B.first--;
            if(B.first>0)
                PQ.push(B);
            B = T;
        }
        if(A.length() == s.length())
            return A;
        else
            return "";
    }