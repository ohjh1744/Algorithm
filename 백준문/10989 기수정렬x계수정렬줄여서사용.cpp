#include <iostream>
using namespace std;

int max_digit;
int cnt[10001];
int n;

//기수정렬은 int형 배열을 사용해야하는데 int형크기 천만을 사용하기때문에 메모리한계
//계수정렬을 사용하면 int형크기 10000이하로 가능하여 메모리문제 발생 x. 
//원래 카운트 정렬의 경우 배열내의 상대적인 순서를 유지하기 위해서 역순으로 조회하면서 정렬하지만,
//이 문제의 경우 메모리한계도 있고 상대적인 순서를 유지할 필요가 없이 결과만 출력하면 되기 때문에 
//count누적합 뒤의 과정은 생략 
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

