#include <iosteram>
using namespace std;

int main()
{
	int list[11] = {0,9,4,3,7,10,34,1,2,22,8};
	
	//�������� 
	//����ū�Ű��� ���� 
	for(int i = 10; i >= 2; i--){
		int k = 1;
		for(int j = 2; j <= i; j++){
			if(list[k] < list[j]){
				k = j;
			}
		}
		
		int temp = list[i];
		list[i] = list[max];
		list[max] = temp;		
	}
	
	//�������� 
	for(int i = 10; i >= 2; i--){
		for(int j = 1; j <= i-1; j++){
			if(list[j] > list[j+1]){
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	} 
	
	//����ȭ�� ��������
	for(int i = 10; i >= 2; i--){
		bool s = false; 
		for(int j = 1; j <= i-1; j++){
			if(list[j] > list[j+1]){
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
				s = true;
			}
		}
		if(!s){
			return;
		}
	}  
	
	//�������� 
	for(int i = 2; i <= n; i++){
		int max = list[i];
		int j = i-1;
		while(max < list[j] && j >= 1){
			list[j+1] = list[j];
			j = j-1;
		}
		list[j+1] = max;
	}
	
	
	
}
