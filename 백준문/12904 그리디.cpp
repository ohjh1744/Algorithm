#include <iostream>
#include <algorithm> // reverse함수 사용하기위해

using namespace std;

string s, t;

void bfs()
{
	while(t.size()){
		if(s == t){
			cout << "1";
			return;
		}
		
		else if(t[t.size()-1] == 'A'){
			t.pop_back();
		}
		else{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
	
	cout << "0";
	return;
}

int main()
{
	cin >> s >> t;
	bfs();
}
