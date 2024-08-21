#include <iostream>
#include <deque> 
using namespace std;

deque <int> dq; //������ 
bool robot[100]; // ��ġ �κ��� �����ٸ� �̵��ϰ�ٴϹǷ� 

int n, k; 
int ans; // Ƚ�� 
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
		
		//1��° ���� : ������ ���� ���� 
		dq.push_front(dq.back());
		dq.pop_back();		
		for(int i = n-1 ; i >= 0; i--){
			if(robot[i] == true){		
				// �����°��� �κ��� �־��ٸ� ��Ʈ�� �̵��ϸ�  
				if(i == n-1){
					robot[i] = false;
				}
				else{
					robot[i] = false;
					robot[i+1] = true;
				}
			}
			
		}

		//2��° ����
		for(int i= n-1 ; i >= 0; i--){
			if(robot[i] == true){
				//�̵��ϱ��� ���ʿ� ������ ��ġ�� �κ��� �ִ� ��� 
			    if(i == n-1){
				    robot[i] = false;
			    } 
				else if(robot[i+1] == false && dq[i+1] > 0){
					robot[i] = false;
					robot[i+1] = true;
					// ���� �̵��� ��ġ�� ������ ��ġ��� �κ��� ������. 
					if(i+1 == n-1){
						robot[i+1] = false;
					}
					dq[i+1]--; 
				}
			}
		}
		
		//3��° ����
		if(dq[0] > 0 && robot[0] == false){
			robot[0] = true;
		    dq[0]--;
		}
		
		//4��° ����
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
