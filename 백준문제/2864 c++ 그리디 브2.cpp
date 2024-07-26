#include <iostream>
#include <string>
using namespace std;

string a, b;

int main()
{
	cin >> a >> b;
	//ÃÖ¼Ú°ª 
	for(int i = 0 ; i < a.length(); i++){
		if(a[i] == '6'){
			a[i] = '5';
		}
	}
	
	for(int i = 0 ; i < b.length(); i++){
		if(b[i] == '6'){
			b[i] = '5';
		}
	}
	
	int min_a = stoi(a);
	int min_b = stoi(b);
	cout << min_a + min_b << " ";
	//ÃÖ´ñ°ª  
	for(int i = 0 ; i < a.length(); i++){
		if(a[i] == '5'){
			a[i] = '6';
		}
	}
	
	for(int i = 0 ; i < b.length(); i++){
		if(b[i] == '5'){
			b[i] = '6';
		}
	}
	int max_a = stoi(a);
	int max_b = stoi(b);
	cout << max_a + max_b << "\n";
	 
	
	
}
