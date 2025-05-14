#include <iostream>
#include <map>
using namespace std;

int n;
char temp[27][2]; // 0은 왼자식, 1은 우자식 

void PreNotation(int root){
	
	char c = root + 'A' - 1;
	cout << c;
	
	if(temp[root][0] != '.'){
		int num = (int)temp[root][0] - 64;
		PreNotation(num);
	}
	
	if(temp[root][1] != '.'){
		int num = (int)temp[root][1] - 64;
		PreNotation(num);
	}
}

void InNotation(int root){
	
	if(temp[root][0] != '.'){
		int num = (int)temp[root][0] - 64;
		InNotation(num);
	}
	
	char c = root + 'A' - 1;
	cout << c;
	
	if(temp[root][1] != '.'){
		int num = (int)temp[root][1] - 64;
		InNotation(num);
	}
}

void PostNotation(int root){

	if(temp[root][0] != '.'){
		int num = (int)temp[root][0] - 64;
		PostNotation(num);
	}
	
	if(temp[root][1] != '.'){
		int num = (int)temp[root][1] - 64;
		PostNotation(num);
	}
	
	char c = root + 'A' - 1;
	cout << c;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		char parent, child1, child2;
		cin >> parent >> child1 >> child2;
		temp[(int)parent - 64][0] = child1;
		temp[(int)parent - 64][1] = child2;		
	}
	

	
	PreNotation(1);
	cout << "\n";
	InNotation(1);
	cout << "\n";
	PostNotation(1);
	cout << "\n";
}
