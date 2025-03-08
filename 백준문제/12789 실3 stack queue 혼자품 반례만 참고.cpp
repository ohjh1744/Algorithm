#include <iostream>
#include <stack>
#include <queue> 
using namespace std;

stack <int> st;
queue <int > q;
int n;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int input;
		cin >> input;
		q.push(input);
	}
	
	int ct = 1;
	// ct 순서가 n번째 올때까지 반복
	while(!q.empty()){
		
		int currentNum = q.front();
		
		//stack에 있는 것이 다음 차례인경우
		if(!st.empty() && st.top() == ct){
			st.pop();
			ct++;
			continue;
		} 

        // ct번 찾을때까지 stack에 추가
		if(currentNum != ct){
			
			//스택은 top일수록 수가 작아져야함.
			// 아니면 모두가 순서대로 간식을 못받음. 
			if(!st.empty()){
				if(st.top() < currentNum){
					cout << "Sad";
					return 0; 
				}
			}
			
			q.pop();
			st.push(currentNum);
		}
		// ct번 찾아서 간식을 받음 
		else{
			q.pop();
			ct++;
		}
	}
	
	cout << "Nice";
 
}
