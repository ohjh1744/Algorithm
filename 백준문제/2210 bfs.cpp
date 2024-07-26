#include <iostream>

#include <algorithm>

#include <queue>



using namespace std;



int l;

int x, y, dx, dy;



// ����Ʈ�� �̵� ����

int my[8] = { 2,1,-2,-1,-1,-2,1,2 };

int mx[8] = { -1, -2, 1, 2, -2, -1, 2, 1 };



const int MAX = 300;


bool visited[MAX][MAX];

// �̵� Ƚ�� ���� cnt

int cnt;



void BFS(int y, int x)

{

	visited[y][x] = true;

	queue<pair<pair<int, int>, int > > q;

// ó���� y, x ���� �̵� Ƚ���� 0�̴� 0�� �־��ش�.

	q.push({{y, x}, 0});



	while (!q.empty())

	{

//  q�� ���� ���� y ,x ���� ���� ���� ���ٸ�

		if (q.front().first.first == dy && q.front().first.second == dx)

		{

// �׶��� �̵� Ƚ���� �����ϰ� ��ģ��.

			cnt = q.front().second; 

		

		}
		
		int xx = q.front().first.first;
		int yy= q.front().first.second;
        int num = q.front().second;
        q.pop();
        
		for (int i = 0; i < 8; ++i)

		{

			int ny = xx + my[i];

			int nx = yy + mx[i];

			
			

			if (ny >= 0 && ny < l && nx >= 0 && nx < l)

				if (visited[ny][nx] == false)

				{

					visited[ny][nx] = true;

// num�� ���� ĭ���� �̵��ϴ� +1 ���ش�.

					q.push(make_pair(make_pair(ny, nx), num + 1));

				}

		}


	}

}

void reset()
{
	for(int i =0; i < l; i++){
		for(int j =0; j<l; j++){
			visited[i][j] = false;
		}
	}

}

int main()

{

	int C;

	cin >> C;

	while (C--) {

// chess �� visited �迭 �ʱ�ȭ

		reset();

		cnt = 0;

		cin >> l;

		cin >> y >> x;

		cin >> dy >> dx;

		BFS(y, x);

		cout << cnt << endl;

	}

	return 0;

}
