#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int alphabet[26]; // 0: A ~~~ 
int oddnum; //Ȧ�� ���� ���� ������ ��
bool check[26]; // Ȧ���� ���� Ȯ�� 
string ans1= "";
string ans2= "";
string r_ans = "";
 
int main()
{
	cin >> s; 
	for(int i = 0; i < s.length(); i++){
		char c = s[i];
		int a = c - 'A';
		alphabet[a]++;
	}

	// �Ӹ���Ҹ�����ִ���, Ȧ���� ���ĺ��� �ΰ��̻��̸� ������ .
	for(int i = 0; i < 26; i++){ // �Ӹ���� ����� ���� ����Ȯ�� 		
		if(alphabet[i] % 2 == 1){
			oddnum++;
		}
		if(oddnum >= 2){
			cout << "I'm Sorry Hansoo" << "\n";
			return 0;
		}
	}
	
	//1. �˹ٺ��� �� ¦���� ��� 
	if(oddnum == 0){
		for(int i = 0; i < 26; i++){
			if(alphabet[i] > 0){
				for(int j = 0; j < alphabet[i] / 2 ; j++){
					char ch = i + 65;
					ans1 = ans1 + ch;
				}
			}
		}
		
		r_ans = ans1;
	    reverse(ans1.begin(), ans1.end());
	    ans2 = ans1;
	    r_ans = r_ans + ans2;
     	cout << r_ans << endl;
	} 
	
	//2. Ȧ������ ���ĺ��� ������ 
	if(oddnum == 1){
		for(int i = 0; i < 26; i++){
			if(alphabet[i] > 0){
				if(alphabet[i] % 2 == 1){
					check[i] = true; 
				} 
				for(int j = 0; j < alphabet[i] / 2 ; j++){
					char ch = i + 65;
					ans1 = ans1 + ch;
				}
			}
		}
		
		r_ans = ans1;
		for(int i = 0; i < 26; i++){
			if(check[i] == true){
				char ch = i + 65;
				r_ans = r_ans + ch;
			}
		}
		reverse(ans1.begin(), ans1.end());
	    ans2 = ans1;
	    r_ans = r_ans + ans2;
     	cout << r_ans << endl;
	} 
	return 0;
	
}
