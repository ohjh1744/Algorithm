#include <iostream>
#define N 10000 // ���ϴ� ������ ����

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
		// ���� ����Ʈ���� �ּڰ��� ���ߴµ� ������ ����Ʈ�� �� ���� ���
		// �״�� ���� ����Ʈ�� �ּڰ��� ����迭�� �������� �˴ϴ�.
		else {
			result[k++] = arr[j++];
		}
	}

	// ������ ����Ʈ�� ���� ����迭�� ���� ���� ���� ������ �״�� �־��ݴϴ�.
	while (i <= mid) {
			result[k++] = arr[i++];
	}
	while (j <= right) {
			result[k++] = arr[j++];
		}
	

	// �ٽ� ���� �迭�� �Űܴ�� �۾�
	for (int a = left; a <= right; a++) {
		arr[a] = result[a];
	}
}

void partition(int left, int right) {
	int mid;
	// �ΰ��� �����ϰ�, �����ϴ� ����
	// ���� �Լ� merges�� ���� �� �� �ֵ���, while�� ������ �����ϸ鼭 �����ϰ� �ȴ�.
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

    // ���� ��� �迭�� result�� ����ϰų� Ȱ���ϸ� �˴ϴ�.

	return 0;
}
