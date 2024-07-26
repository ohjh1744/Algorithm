#include <iostream>
#include <deque> 
using namespace std;

deque <int> dq; //내구도 
bool robot[100]; // 위치 로봇은 맨윗줄만 이동하고다니므로 

int n, k; 
int ans; // 횟수 
int main()
{
	cin >> n >> k;
	
	for(int i = 1; i <= n*2; i++){
		int num;
		cin >> num;
		dq.push_back(num);
	}
	
	bool b= true;

	while(b){
		ans++;
		
		//1번째 과정 : 내구도 달일 없음 
		dq.push_front(dq.back());
		dq.pop_back();		
		for(int i = n-1 ; i >= 0; i--){
			if(robot[i] == true){		
				// 내리는곳에 로봇이 있었다면 벨트가 이동하면  
				if(i == n-1){
					robot[i] = false;
				}
				else{
					robot[i] = false;
					robot[i+1] = true;
				}
			}
			
		}

		//2번째 과정
		for(int i= n-1 ; i >= 0; i--){
			if(robot[i] == true){
				//이동하기전 애초에 내리는 위치에 로봇이 있는 경우 
			    if(i == n-1){
				    robot[i] = false;
			    } 
				else if(robot[i+1] == false && dq[i+1] > 0){
					robot[i] = false;
					robot[i+1] = true;
					// 만약 이동한 위치가 내리는 위치라면 로봇을 내려줌. 
					if(i+1 == n-1){
						robot[i+1] = false;
					}
					dq[i+1]--; 
				}
			}
		}
		
		//3번째 과정
		if(dq[0] > 0 && robot[0] == false){
			robot[0] = true;
		    dq[0]--;
		}
		
		//4번째 과정
		int ct = 0;
		for(int i = 0; i < dq.size(); i++){
			if(dq[i] == 0){
				ct++;
			}
			if(ct == k){
				b = false;
			}
		} 		 
	}

	cout << ans << endl;
	
}
