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
	// ct ������ n��° �ö����� �ݺ�
	while(!q.empty()){
		
		int currentNum = q.front();
		
		//stack�� �ִ� ���� ���� �����ΰ��
		if(!st.empty() && st.top() == ct){
			st.pop();
			ct++;
			continue;
		} 

        // ct�� ã�������� stack�� �߰�
		if(currentNum != ct){
			
			//������ top�ϼ��� ���� �۾�������.
			// �ƴϸ� ��ΰ� ������� ������ ������. 
			if(!st.empty()){
				if(st.top() < currentNum){
					cout << "Sad";
					return 0; 
				}
			}
			
			q.pop();
			st.push(currentNum);
		}
		// ct�� ã�Ƽ� ������ ���� 
		else{
			q.pop();
			ct++;
		}
	}
	
	cout << "Nice";
 
}
