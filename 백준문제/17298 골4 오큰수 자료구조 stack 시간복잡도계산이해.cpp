#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[1000001];
stack < int> st;
int ans[1000001];

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	// 시간복잡도가 2n인 이유
	// 스택에 들어가는 원소당 각각 1번씩만 push되고, pop됨.
	// 즉, n개의 원소 각각 2번씩 연산되므로 2n. 
	for(int i = n; i >= 1 ; i--){
		
		while(!st.empty() && st.top() <= arr[i]){
			st.pop();
		}
		
		if(st.empty()){
			ans[i] = -1;
		}
		else {
			ans[i] = st.top();
		} 
		
		st.push(arr[i]);
			
	}
	
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	
	
	
}
