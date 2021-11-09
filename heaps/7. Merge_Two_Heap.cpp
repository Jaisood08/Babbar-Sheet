void insert(vector<int> &a)
    {
        int n = a.size();
        int i = n-1;
        while(i>1)
        {
            if(a[i]>a[i/2])
            {
                swap(a[i],a[i/2]);
                i = i/2;
            }
            else
            {
                break;
            }
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) 
    {
        a.insert(a.begin(),-1);
        for(int i=0;i<m;i++)
        {
            a.push_back(b[i]);
            insert(a);
        }
        a.erase(a.begin());
        return a;
    }