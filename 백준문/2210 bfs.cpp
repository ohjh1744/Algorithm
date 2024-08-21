#include <iostream>

#include <algorithm>

#include <queue>



using namespace std;



int l;

int x, y, dx, dy;



// 나이트의 이동 방향

int my[8] = { 2,1,-2,-1,-1,-2,1,2 };

int mx[8] = { -1, -2, 1, 2, -2, -1, 2, 1 };



const int MAX = 300;


bool visited[MAX][MAX];

// 이동 횟수 저장 cnt

int cnt;



void BFS(int y, int x)

{

	visited[y][x] = true;

	queue<pair<pair<int, int>, int > > q;

// 처음은 y, x 값과 이동 횟수가 0이니 0을 넣어준다.

	q.push({{y, x}, 0});



	while (!q.empty())

	{

//  q에 다음 나올 y ,x 값이 도착 값과 같다면

		if (q.front().first.first == dy && q.front().first.second == dx)

		{

// 그때에 이동 횟수를 저장하고 마친다.

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

// num은 다음 칸으로 이동하니 +1 해준다.

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

// chess 와 visited 배열 초기화

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
