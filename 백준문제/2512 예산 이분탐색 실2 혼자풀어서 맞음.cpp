#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int m;
int ans = 0;

void binearySearch(){
   
   int left = 1;
   int right = v[v.size()-1];
   int middle = 0;
   while(left <= right){
   	  //예산상한선 
      middle = (left + right) / 2; 
      int cost = 0; 
      
      // 줄 수 있는 예산 총합 구하기 
      for(int i = 0; i < v.size(); i++){
         if(middle < v[i]){
            cost += middle;
         }
         else{
            cost += v[i];
         }
      }
       
      //예산총합이 국가예산보다 큰경우 
      if(cost > m){
         right = middle - 1;
      }
      //예산총합이 국가예산보다 작거나 같은 경우 
      else{
         left = middle + 1;
         // 예산상한선이 기존의 예산상한선보다 크면 Update 
		 if(ans < middle){
         	ans = middle;
		 }
		 // 예산상한선이 국가예산보다 같으면 그대로 break 
		 if(cost == middle){
		 	break;
		 } 
      }      
   }

}
 

int main(){
   
   cin >> n;
   
   int currentSum = 0;
   
   for(int i = 1; i <= n; i++){
      int input;
      cin >> input;
      v.push_back(input);
      currentSum += input;
   }
   
   cin >> m;
   
   sort(v.begin(), v.end());
   
   if(m >= currentSum){
   	  ans = v[n-1];
   }
   else{
      binearySearch();
   }
   
   cout << ans;
   
}
