#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int main()
{
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		int n;
		cin >> n;
		if(n == 0){
			v.pop_back();
		}
		else{
			v.push_back(n);
		}
	}
	
	int temp = 0;
	
	for(int i =0; i< v.size(); i++){
		temp = temp + v[i];
	}
	cout << temp << endl;
	
}
