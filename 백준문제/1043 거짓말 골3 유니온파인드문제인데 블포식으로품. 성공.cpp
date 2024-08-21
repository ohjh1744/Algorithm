#include <iostream>
#include <vector>
using namespace std;

int n, m, know, f_know;
vector <int> knum; // 아는사람 번호 
vector <int> v[51]; // 파티 
int parent[51]; // 알게된  사람 체크하기 
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
	
	for(int i = 0; i < knum.size(); i++){// 진실아는사람들끼리 parent 모두 맨처음아는사람으로 바꿔주기
		parent[knum[i]] = f_know;
	}
	
		
	for(int i = 1; i <= m; i++){
		int num;
		cin >> num;
		bool b = false; // 맨처음아는사람과 같은파티인지 확인 
		for(int j = 0; j < num; j++){
			int person;
			cin >> person;
			v[i].push_back(person);
			if(parent[person] == f_know){
				b = true;
			} 
		}	
	    
	    // 아는사람과 같은파티면 
	    if(b == true){
	    	for(int k = 0; k < v[i].size(); k++){
	    		parent[v[i][k]] = f_know;
			}
		}
	}	
	
	// 입력순서가 앞에선 가짜이야기를 듣고 뒤에서 진짜이야기를 들은 경우가 있으므로 여러번 더체크(최대 m만큼 확인해봐야함) 
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
	//거짓말할수있는 파티 확인
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
