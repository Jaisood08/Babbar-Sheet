    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        //PUSH
        if(left.empty())
        {
            left.push(x);
        }
        else if( left.top()>x)
        {
            left.push(x);
        }
        else
        {
            right.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        //BALANCE
        if(left.size()>right.size()+1)
        {
            right.push(left.top());
            left.pop();
        }
        else if(left.size()<right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size()==right.size())
        {
            return ((left.top()+right.top())/2);
        }
        else
        {
            return left.top();
        }
    }