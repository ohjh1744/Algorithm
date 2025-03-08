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
	
	// �ð����⵵�� 2n�� ����
	// ���ÿ� ���� ���Ҵ� ���� 1������ push�ǰ�, pop��.
	// ��, n���� ���� ���� 2���� ����ǹǷ� 2n. 
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
