#include <iostream>
#include <algorithm>
using namespace std;

int n, l;
int temp[1000];

int main()
{
	cin >> n >> l;
	for(int i = 0; i <n; i++){
		cin >> temp[i];
	}
	
	sort(temp, temp+n);
	int start = temp[0];
	
	int tape = 0;
	for(int i = 1 ; i < n; i++){
		if(l <= temp[i] - start){ // ���̰� ���̱��̺��� ª�ų� ���ٸ� ���� ������ �������� ������ ���̱� ���� 
			tape++;
			start = temp[i];
		}
	}
	cout << tape + 1 << endl;  // ������ ���� ������ �Ⱥٿ����Ƿ� 
}
