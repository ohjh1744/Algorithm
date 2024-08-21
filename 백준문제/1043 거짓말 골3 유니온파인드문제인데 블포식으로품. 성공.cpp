#include <iostream>
#include <vector>
using namespace std;

int n, m, know, f_know;
vector <int> knum; // �ƴ»�� ��ȣ 
vector <int> v[51]; // ��Ƽ 
int parent[51]; // �˰Ե�  ��� üũ�ϱ� 
int ans;

int main()
{
	for(int i = 1; i <= 50; i++){
		parent[i] = i;
	}
	
	cin >> n >> m;
	cin >> know;  
	for(int i = 0; i < know; i++){   
		int number;
	    cin >> number;
	    knum.push_back(number);
		if(i == 0){
			f_know = number;
		} 
	}
	
	for(int i = 0; i < knum.size(); i++){// ���Ǿƴ»���鳢�� parent ��� ��ó���ƴ»������ �ٲ��ֱ�
		parent[knum[i]] = f_know;
	}
	
		
	for(int i = 1; i <= m; i++){
		int num;
		cin >> num;
		bool b = false; // ��ó���ƴ»���� ������Ƽ���� Ȯ�� 
		for(int j = 0; j < num; j++){
			int person;
			cin >> person;
			v[i].push_back(person);
			if(parent[person] == f_know){
				b = true;
			} 
		}	
	    
	    // �ƴ»���� ������Ƽ�� 
	    if(b == true){
	    	for(int k = 0; k < v[i].size(); k++){
	    		parent[v[i][k]] = f_know;
			}
		}
	}	
	
	// �Է¼����� �տ��� ��¥�̾߱⸦ ��� �ڿ��� ��¥�̾߱⸦ ���� ��찡 �����Ƿ� ������ ��üũ(�ִ� m��ŭ Ȯ���غ�����) 
	//6 5
    //1 6
    //2 4 5
    //2 1 2  
    //2 2 3
    //2 3 4
    //2 5 6
	int t = m;
	while(t--){
		for(int i = 1; i <= m; i++){
		    for(int j = 0; j < v[i].size(); j++){
			    if(parent[v[i][j]] == f_know){
				    for(int k = 0; k < v[i].size(); k++){
					    parent[v[i][k]] = f_know;
			        }
			    }
		    }
        }
	}
    
	ans = m;
	//�������Ҽ��ִ� ��Ƽ Ȯ��
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < v[i].size(); j++){
			if(parent[v[i][j]] == f_know){
				ans--;
				break;
			}
		}
		
	}
	
	cout << ans << "\n";
	
}
