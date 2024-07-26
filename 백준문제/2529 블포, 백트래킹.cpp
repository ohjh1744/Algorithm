#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
vector<char> v; //�ε�ȣ����
vector <int> v_dfs; 
char num[10]; 
vector <string> ans; // k+1�ڸ��� ���� ���� 
bool b[10];
bool check = true; // �ε�ȣ�´��� Ȯ�� 

void dfs(int ct)
{
	if(ct == k+1){
		for(int i = 0; i < v.size() ; i++){
			if(check == false){
				continue;
			}			
			if(v[i] == '<'){
				if(v_dfs[i] >= v_dfs[i+1]){
					check = false; 
				}
			}
			else if(v[i] == '>'){
				if(v_dfs[i] <= v_dfs[i+1]){
					check = false;
				}
			}
		}
		if(check){
			string val = "";
			for(int i = 0; i < v_dfs.size(); i++){
				val = val + to_string(v_dfs[i]);
			}
			ans.push_back(val);
		}
		check = true;
		return;
	}
	
	for(int i = 0; i <= 9 ; i++){
		if(b[i] == true){
			continue;
		}
		b[i] = true;
		v_dfs.push_back(i);
		dfs(ct+1);
		v_dfs.pop_back();
		b[i] = false;
	}
}




int main()
{
	cin >> k;
	
	char input;
	for(int i = 0; i < k; i++){
		cin >> input;
		v.push_back(input); 
	}
	
	dfs(0);
    cout << ans[ans.size()-1] << endl;
    cout << ans[0] << endl;	
	
}
