void heapify(int *arr,int n,int i)
    {
        int lar = i;
        int l = 2*i+1;
        int r = 2*i+2;
        
        if(l<n && arr[lar]<arr[l])
        {
            lar = l;
        }
        if(r<n && arr[lar]<arr[r])
        {
            lar = r;
        }
        if(arr[i] != arr[lar])
        {
            swap(arr[i],arr[lar]);
            heapify(arr,n,lar);
        }
    }
    
    void buildHeap(int arr[], int n)
    {
        int startIdx = (n / 2) - 1;
     
        for (int i = startIdx; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }
  
    
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       int H[k];
       for(int i=0;i<k;i++)
        H[i] = arr[i];
        
       int in = 0;
       vector<int> Sol;
       buildHeap(H,k);
        
       Sol.push_back(H[0]);
       
       for(int i=k;i<n;i++)
       {
           for(int j=0;j<k;j++)
           {
               if(H[j]==arr[in])
               {
                   H[j] = arr[i];
                   in++;
                   break;               
               }
           }
           buildHeap(H,k);
           Sol.push_back(H[0]);
       }
       return Sol;
    }