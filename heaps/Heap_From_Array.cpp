#include <bits/stdc++.h>
using namespace std;

class heap
{ 
 public:
 vector<int> V;

 heap()
 {
   V.push_back(-1);
 }
 
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
   int j = 2*i;
   int n = V.size();
   while(j<n)
   {
     if(V[j+1]<V[j])
	j=j+1;
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
 int Top()
 {
   if(V.size()==1)
      return -1;
   return V[1];
 }
 void display()
 {
   for(int i=1;i<V.size();i++)
   {
      cout<<V[i]<<" ";
   }
   cout<<endl;
 }

};


int main()
{
  heap H;
  H.insert(1);
  H.insert(3);
  H.insert(2);
  H.insert(5);
  H.insert(4);
  H.insert(6);
  H.display();
  cout<<H.Top()<<endl;
  cout<<H.remove()<<" -> ";
  H.display();
  cout<<H.remove()<<" -> ";
  H.display();
  cout<<H.remove()<<" -> ";
  H.display();
  cout<<H.remove()<<" -> ";
  H.display();
  cout<<H.remove()<<" -> ";
  H.display();
  return 0;
}
