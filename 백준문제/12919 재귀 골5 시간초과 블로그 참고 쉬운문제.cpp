#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
bool CanMake;

// s���� t�� ã�°� �ð��ʰ�, t���� s�� ã�� ������ ����. 
void dfs(string st){
	
	if(st.length() == s.length()){
		if(st == s){
			CanMake = true;
		}
		return;
	}
	
	// �� 2���� ��찡 ����. 
	// �ǵڰ� A�ΰ��. 
	// �Ǿ��� B�鼭 �ǵڰ� A�ΰ�쵵 ����. ->  �̰��� ����1, ����2 ��� ����� ���� ����.����1���� Ž���غ��� �ƴ϶��  �ڿ��� ����2Ž��. 
	if(st[st.length() -1] == 'A'){
		string temp = st;
		temp.pop_back();
		dfs(temp);
	}
	

	//�Ǿ��� b�ΰ��
	// �Ǿ��� A�̰� �ǵڰ� B�ΰ��� �����Ҽ��� ������. ex) AAB �̰��� s�� �����������.  
	if(st[0] == 'B'){
		string temp = st;
		reverse(temp.begin(), temp.end());
		temp.pop_back();
		dfs(temp);
	}
	
}
int main(){
	cin >> s >> t;
	dfs(t);
	cout << CanMake;
} 
