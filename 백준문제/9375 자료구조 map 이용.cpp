#include <iostream>
#include <map>

using namespace std;

string name, option;
int t, n;
int ans = 1;

int main()
{
   cin >> t;
   for(int i = 0; i < t; i++){
   	 map<string, int> m;
	 cin >> n;
   	 for(int j = 0; j < n; j++){
   		cin >> name >> option;
   		if(m.find(option)== m.end()){
   			m.insert({option , 1});
		}
		else{
			m[option]++;
	        m[option] = 2;
		}
	 }
	 map<string, int>::iterator iter;
	 for(iter = m.begin(); iter != m.end(); iter++){
		cout << iter -> second << endl;
	 }
	  ans = ans - 1;
	  cout << ans << endl; 
	  ans = 1;
	}
   
 	
}
