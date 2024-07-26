#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int main()
{
	int m , n;
	cin >> m >> n;
	
	for(int i = m ; i <= n; i++){
		for(int j = 1; j <= i; j++){
		   if(j*j == i){
		   	 v.push_back(i);
		   }			
		}
	}
	
	int temp = 0;
	if(v.empty()){
		cout << "-1" << endl;
	}
	else{
		for(int i = 0; i < v.size(); i++)
	    {
		  temp = temp + v[i];
	    }
	
	    cout << temp << endl << v[0]; 
	}
	
}
