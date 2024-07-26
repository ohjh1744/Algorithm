#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int stack = 0; // n¿œ∂ß break; 
    int i = 666;
    string s;
    
	while(true){
    	 s = to_string(i);
		 if(s.find("666") != string :: npos){
    	 	stack++;
		 }
		 if(stack == n){
		 	break;
		 }
		 i++;
	}
	
	cout << i << endl;
}
