#include <iostream>
using namespace std;

int main()
{
	string  s;
	getline(cin, s);
	
	string f;
	getline(cin , f);
	
	int ct = 0;
	
	bool b = true;
	for(int i = 0; i < s.length(); i++){
		b = true;
		for(int j = 0; j < f.length(); j++){
			if(s[i+j] != f[j]){
				b = false;
				break;
			}
		}
		if(b){
			ct++;
			i = i + f.length() - 1;
		}
	}
    cout << ct << endl;
}
