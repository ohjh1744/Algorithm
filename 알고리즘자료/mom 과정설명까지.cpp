#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int temp[10001];

int partition(int A[], int left, int right)
{
   int pivot = A[right];
   int i = left - 1;
   for(int j = left; j <= right-1; j++){
      if(A[j] <= pivot){
         i++;
         int temp = A[i];
         A[i] = A[j];
         A[j] = temp;
      }
   }
   
   int temp = A[i+1];
   A[i+1] = A[right];
   A[right] = temp;
   return i+1; 
}

int mom_partition(int A[], int l, int r, int M)
{
   for(int i = l; i <= r; i++){
      if(A[i] == M ){
         int temp = A[i];
         A[i] = A[r];
         A[r] = temp;
      }
   }
   return partition(A, l, r);
}


int quick_select(int A[], int l, int r, int i)
{
   if (l == r){
      return A[l];
   }
   
   int p = partition(A, l , r);
   int k = p -l + 1;
   if(i < k){
      return quick_select(A, l, p-1 , i);
   }
   else if(i == k){
      return A[p];
   }
   else if(i > k){
      return quick_select(A, p+1, r , i- k);
   }
}

int mom_select(int A[], int l, int r, int i)
{
	cout << "mom_select: " << l << " " << r << " " << i << endl;
   int n = r - l + 1;
   if(n <=5){
      return quick_select(A, l , r, i);
   }
   else{
      int G = ceil(n / 5.0);
      int B[G+1]; 
      
      vector < pair < int, int > > v[G+1];
      int num = l;
      
      for(int i = 1; i <= n/5; i++){
         v[i].push_back({num, num+4});
         num = num + 5;
      }
      
      //마지막그룹  l, r정하기 
      if(n%5 != 0){
         int ll = r - (n%5)+1;
         int rr = r;
         v[G].push_back({ll, rr});
      }
      
      for(int j = 1; j <= G-1; j++){
         int m_j = quick_select(A, v[j][0].first, v[j][0].second, 3);
         B[j] = m_j;
      }
      
      // 마지막그룹 중간값찾기
      if(n%5 == 4 || n%5 == 3){
         int m_j = quick_select(A, v[G][0].first, v[G][0].second, 2);
         B[G] = m_j;
      }
      else if(n%5 == 2 || n%5 == 1){
         int m_j = quick_select(A, v[G][0].first, v[G][0].second, 1);
         B[G] = m_j;
      }
      else if(n%5 == 0){
         int m_j = quick_select(A, v[G][0].first, v[G][0].second, 3);
         B[G] = m_j;
      }
         
     cout << "B" << G << ": "   ; 
     for(int i = 1; i <= G; i++){
     	cout << B[i] << " ";
	 }    
	 cout << endl;
   
      int M = mom_select(B, 1, G, ceil(G/ 2.0));
      
      int p = mom_partition(A, l, r , M);
        
      int k = p - l + 1;
      
      cout << M << " " << k << " " << n << " " << k/n << endl;
      for(int i = l; i <= r; i++){
      	cout << A[i] << " ";
	  }
	  cout << endl;
      if(i < k){
          return mom_select(A, l, p-1 , i);
       }
       else if(i == k){
          return A[p];
       }
        else if(i > k){
          return mom_select(A, p+1, r , i- k);
       }   
      
   }
}


int main()
{
   int n, i;
   cin >> n >> i;
   
   for(int i = 1; i <= n; i++){
      cin >> temp[i];
   }
   mom_select(temp, 1, n, i);
}
