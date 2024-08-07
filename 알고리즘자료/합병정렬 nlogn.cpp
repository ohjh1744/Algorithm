#include <iostream>
#define N 10000 // 원하는 원소의 갯수

using namespace std;

int arr[N];
int result[N];

void merges(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			result[k++] = arr[i++];
		}
		// 양쪽 리스트에서 최솟값을 비교했는데 오른쪽 리스트가 더 컸을 경우
		// 그대로 왼쪽 리스트의 최솟값이 결과배열에 내려오면 됩니다.
		else {
			result[k++] = arr[j++];
		}
	}

	// 오른쪽 리스트에 아직 결과배열에 들어가지 못한 값이 있으면 그대로 넣어줍니다.
	while (i <= mid) {
			result[k++] = arr[i++];
	}
	while (j <= right) {
			result[k++] = arr[j++];
		}
	

	// 다시 원래 배열에 옮겨담는 작업
	for (int a = left; a <= right; a++) {
		arr[a] = result[a];
	}
}

void partition(int left, int right) {
	int mid;
	// 두개로 분할하고, 병합하는 과정
	// 병합 함수 merges를 보면 알 수 있듯이, while문 등으로 정렬하면서 병합하게 된다.
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merges(left, right);
	}
}


int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	partition(0, N - 1);

    // 이후 결과 배열인 result를 출력하거나 활용하면 됩니다.

	return 0;
}
