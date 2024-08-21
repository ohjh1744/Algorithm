#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> st;
vector<string> result;

int main()
{
  
  int n;
  cin >> n; 
  int ct = 1;
  for(int i=0; i <n; i++){
  	int z;
	cin >> z;
	
	while(ct <= z){
		st.push(ct);
		ct++;
		result.push_back("+");
	}
	
	if(st.top() == z){
		st.pop();
		result.push_back("-");
	
	}
	else{
		cout << "NO" ;
		return 0;
	}		
  }
  for(int i=0; i<result.size(); i++){
  	cout << result[i] << "\n";
  }
  
  
	
}
