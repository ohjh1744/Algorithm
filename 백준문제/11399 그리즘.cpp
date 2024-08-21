#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];

int main()
{
  int n;
  cin >> n;
  
  for(int i = 1; i <= n; i++){
  	cin >> arr[i];
  }  
  
  sort(arr, arr+n+1);
  int temp = 0;
  int ans = 0;
  for(int i = 1; i <= n; i++){
  	temp = temp + arr[i];
  	ans = ans + temp;
  }
  
  
  cout << ans << endl; 
  
}

