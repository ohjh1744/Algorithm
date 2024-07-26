#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int day[500001];
int month[500001];
int year[500001];
int n;

// w 가 숫자 길이, n은 배열길이(깊이) -> w길이의 숫자가 n개. 
void radix_sort(int arr[], int n, int w)
{
	queue <pair < pair < int, int > , int > > q[10];
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= n; j++){
			int d = (arr[j] / int(pow(10, i-1))) % 10;
			q[d].push({{day[j], month[j]}, year[j]});
		}
		
		int p = 1;
		for(int i = 0; i <= 9; i++){
			while(!q[i].empty()){
				day[p] = q[i].front().first.first;
				month[p] = q[i].front().first.second;
				year[p] = q[i].front().second;
				q[i].pop();
				p++; 
			}
		}
	}
	
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> day[i];
		cin >> month[i];
		cin >> year[i];
	}
	
	radix_sort(day, n, 2);
	radix_sort(month, n, 2);
	radix_sort(year, n, 4);
	
	for(int i = 1; i <= n; i++){
		cout << day[i] << " " << month[i] << " " <<year[i] << endl;
	}

}
