#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
bool CanMake;

// s에서 t를 찾는건 시간초과, t에서 s를 찾는 식으로 유도. 
void dfs(string st){
	
	if(st.length() == s.length()){
		if(st == s){
			CanMake = true;
		}
		return;
	}
	
	// 총 2가지 경우가 존재. 
	// 맨뒤가 A인경우. 
	// 맨앞이 B면서 맨뒤가 A인경우도 포함. ->  이경우는 조건1, 조건2 모두 경우의 수가 존재.조건1먼저 탐색해보고 아니라면  뒤에서 조건2탐색. 
	if(st[st.length() -1] == 'A'){
		string temp = st;
		temp.pop_back();
		dfs(temp);
	}
	

	//맨앞이 b인경우
	// 맨앞이 A이고 맨뒤가 B인경우는 존재할수가 없ㅇ므. ex) AAB 이경우는 s로 만들수가없음.  
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
