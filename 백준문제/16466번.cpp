#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  int t;
  cin >> t;
  
  vector<int> v(t);
  for(int i=0; i<t; i++){
  	cin >> v[i];
  }
    
  sort(v.begin(), v.end());
  
  
  int n =1;
  for(int i=0; i<v.size(); i++){
  	if(n >= v[i]){
		n++;
	}
  }
  
  cout << n;
  
  
  
}
