#include <iostream>
using namespace std;

int max_digit;
int cnt[10001];
int n;

//��������� int�� �迭�� ����ؾ��ϴµ� int��ũ�� õ���� ����ϱ⶧���� �޸��Ѱ�
//��������� ����ϸ� int��ũ�� 10000���Ϸ� �����Ͽ� �޸𸮹��� �߻� x. 
//���� ī��Ʈ ������ ��� �迭���� ������� ������ �����ϱ� ���ؼ� �������� ��ȸ�ϸ鼭 ����������,
//�� ������ ��� �޸��Ѱ赵 �ְ� ������� ������ ������ �ʿ䰡 ���� ����� ����ϸ� �Ǳ� ������ 
//count������ ���� ������ ���� 
void count_sort(int n, int k)
{

	for(int i = 1; i <= max_digit; i++ ){
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << "\n";
		}
	}
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i <n; i++){
		int index;
		cin >> index;
		cnt[index]++;
		if(max_digit < index){
			max_digit = index;
		}
	}
	
	count_sort(n, max_digit);
	
	
}

