#include <iostream>
using namespace std;

int check[10001];

void dn()
{
	for(int i = 1; i <= 10000; i++){
		int num = i + (i / 1000) + (i % 1000 / 100) + (i % 100 / 10) + (i % 10);
		check[num] = true; 
	}
}


int main()
{
	dn();
	for(int i = 1; i <= 10000; i++){
		if(check[i] == false){
			cout << i << "\n";
		}
	}
}
