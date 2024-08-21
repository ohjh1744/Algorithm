#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	map < string, int > book;
	string input;
	for(int i = 0; i < n; i++){
		cin >> input;
		if(book.find(input) == book.end()){
			book[input] = 1;
		}
		else{
			book[input]++;
		}
	}
	
	map<string, int> :: iterator iter;
	string ans;
	int ct = 0;
	for(iter = book.begin(); iter != book.end(); iter++){
		if(iter->second > ct){
			ct = iter -> second;
			ans = iter -> first;
		}
	}
	cout << ans << endl;

}
