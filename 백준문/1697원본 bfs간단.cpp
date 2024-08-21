#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

queue<pair<int,int > > q;
bool visit[100001];
int N, K, result;

// �ش� ��ġ�� ��ȿ���� Ȯ���ϴ� �Լ�
bool valid(int n) {
	if (n < 0 || n > 100000 || visit[n])
		return false;
	return true;
}

void bfs(int n) {
	while (!q.empty()) {
		// ť���� ������
		int data = q.front().first;
		int depth = q.front().second;
		q.pop();
        // K�� ������ �ٷ� �� ���� depth�� ��� ����
		if (data == K) {
			result = depth;
			break;
		}
        // �� �� �ִ� 3������ ��ǥ�� ��ȿ���� �Ǵ��ϰ� ť�� push
		if (valid(data - 1)){ 
			visit[data - 1] = true;
			q.push({ data - 1, depth + 1 });
		}
		if (valid(data + 1)) {
			visit[data + 1] = true;
			q.push({ data + 1, depth + 1 });
		}
		if (valid(data * 2)) {
			visit[data * 2] = true;
			q.push({ data * 2, depth + 1 });
		}
	}
}

int main() {


	cin >> N >> K;
	q.push({ N, 0 });
	visit[N] = true;
	bfs(N);
    
	cout << result;
	return 0;
}
