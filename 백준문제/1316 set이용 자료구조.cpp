#include <iostream>
#include <set>
using namespace std;


int n;
int ans;


int main(){
	
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
    set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);

	
	set<int>:: iterator it;
	
	for(it = s.begin(); it != s.end(); it++){
		cout << *it << " ";
	} 
	
}
