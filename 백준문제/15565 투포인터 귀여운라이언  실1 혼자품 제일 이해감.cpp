#include <iostream>
using namespace std;

int n, k;
int temp[1000001];
int ans = 99999999;

//1��° �������� ���� ���� 
int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	
	int st = 0;
	int end = 0;
	int sum = 0; // ����ũ�� 
	int ct = 0; // k�������� 
	
	
	while(end <= n){
		if(ct == k){
			if(sum < ans){
				ans = sum;
			}
			sum--;
			st++;
			if(temp[st] == 1){
				ct--;
			}
			
		}
		else if(ct < k){
			sum++;
			end++;
			if(temp[end] == 1){
				ct++;
			}
			
		}
	}
	
	if(ans == 99999999){
		cout << -1 << "\n";
	}
	else{
		cout << ans << "\n";
	}
	
}

//2��° ���� �����ϰ� § ��������
#include <iostream>
using namespace std;

int n, k;
int temp[1000001];
int ans = 99999999;

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> temp[i];
	}
	
	int st = 0;
	int end = 0;
	int sum = 0; // ����ũ�� 
	int ct = 0; // k�������� 
	
	
	while(end <= n){
		if(ct == k){
			if(sum < ans){
				ans = sum;
			}
			st++;
			if(temp[st] == 1){
				ct--;
			}
			sum--;
		}
		else if(ct < k){
			end++;
			if(temp[end] == 1){
				ct++;
			}
			sum++;
		}
	}
	
	if(ans == 99999999){
		cout << -1 << "\n";
	}
	else{
		cout << ans << "\n";
	}
	
}   
