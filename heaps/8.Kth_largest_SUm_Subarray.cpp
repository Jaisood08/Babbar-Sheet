#include<bits/stdc++.h>
using namespace std;

int SOL(int *A,int n,int k)
{
    priority_queue<int> PQ;

    for(int i=0;i<n;i++)
    {
        PQ.push(A[i]);
        int T = A[i];
        for(int j=i+1;j<n;j++)
        {
            T += A[j];
            PQ.push(T);
        }
    }

    while(--k)
    {
       PQ.pop();
    }
    return PQ.top();
}

int main()
{
    // int n = 3;
    // int A[n] = {20,-5,-1};
    // int K = 3;


    int n = 4;
    int A[n] = {10,-10,20,-40};
    int K = 6;


    cout<<SOL(A,n,K)<<endl;

    return 0;
}