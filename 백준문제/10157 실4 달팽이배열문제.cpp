#include <iostream>
#include <vector>
using namespace std;

int c, r, k;  
int graph[1001][1001];

int main()
{
	cin >> c >> r;  //   7 6 : y  x
	cin >> k;
	
	int sw = 1;
	int limit = 0;
	int y = 1;
	int x = 0;
	 
	for(int ct = 1; ct <= c*r;){
		for(int i = 1; i<= r - limit; i++){  //6
			x = x + sw;
			graph[y][x] = ct;
			if(ct == k){
				cout << y << " " << x;
				return 0;
			}
			ct++;
		}
		
		for(int i = 1; i<= c - limit-1; i++){ //7
			y = y + sw;
			graph[y][x] = ct;
			if(ct == k){
				cout << y << " " << x;
				return 0;
			}
			ct++;
		}
		sw= sw * -1;
		limit++;
	}
	
	cout << 0;
	
}
