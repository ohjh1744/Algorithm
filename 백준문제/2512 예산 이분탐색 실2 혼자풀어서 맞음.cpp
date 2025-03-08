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
   	  //������Ѽ� 
      middle = (left + right) / 2; 
      int cost = 0; 
      
      // �� �� �ִ� ���� ���� ���ϱ� 
      for(int i = 0; i < v.size(); i++){
         if(middle < v[i]){
            cost += middle;
         }
         else{
            cost += v[i];
         }
      }
       
      //���������� �������꺸�� ū��� 
      if(cost > m){
         right = middle - 1;
      }
      //���������� �������꺸�� �۰ų� ���� ��� 
      else{
         left = middle + 1;
         // ������Ѽ��� ������ ������Ѽ����� ũ�� Update 
		 if(ans < middle){
         	ans = middle;
		 }
		 // ������Ѽ��� �������꺸�� ������ �״�� break 
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
