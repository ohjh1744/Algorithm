#include <iostream>
#include <queue>
#include <deque>
using namespace std;


queue <int> q; // ��üƮ�� 
queue <int> b_q; //�ٸ����� Ʈ���� 
int n, w, l;

int main()
{
	cin >> n >> w >> l; // w �ٸ����� l ���� 
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		q.push(num);
	}
	

	int t = 0; //�ð�
	int m_l = 0; 	
	for(int i = 0 ;i < w-1; i++){
		b_q.push(0);
	}
	
	while(1){
		if(q.empty()){
			break;
		}
		if(b_q.size() < w){
			if(m_l + q.front()<= l){
				b_q.push(q.front());
				m_l = m_l + q.front();
				q.pop();
			}
			else{
				b_q.push(0);
				m_l = m_l + 0;
			}
		}
		
		if(b_q.size() == w){
			t++;
			m_l = m_l - b_q.front();
			b_q.pop();
		}		
	}
	cout << t + w;
	
	
}
