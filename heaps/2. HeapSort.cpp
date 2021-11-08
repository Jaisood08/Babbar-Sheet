#include<bits/stdc++.h>
using namespace std;


class Heap
{
    public:
      vector<int> V = {-1};

    void insert(int val)
    {
        V.push_back(val);
        int i = V.size()-1;
        while(i>1 && V[i]<V[i/2])
        {
            swap(V[i],V[i/2]);
            i = i/2;
        }
    }

    int remove()
    {
        int RV = V[1];
        V[1] = V[V.size()-1];
        V.pop_back();
        int i = 1;
        int j = 2;
        int n = V.size();
        while(j<n)
        {
            if(V[j+1]<=V[j])
            {
                j = j+1;
            }
            if(V[i]>V[j])
            {
                swap(V[i],V[j]);
                i = j;
                j = 2*i;
            }
            else
            {
                break;
            }
        }
        return RV;
    }
    void display()
    {
        for(int i=0;i<V.size();i++)
        {
            cout<<V[i]<<" ";
        }
        cout<<endl;
    }
};


void HeapSort(int *A,int n)
{
    Heap H;
    for(int i=0;i<n;i++)
    {
        H.insert(A[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        A[i] = H.remove();
    }
}

int main()
{
    int n = 6;
    int A[n] = {12,3,7,23,1,12};

    cout<<" Input \n";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
        cout<<"\n";
        
    HeapSort(A,n);
    
    cout<<" Output \n";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
        cout<<"\n";
return 0;
}