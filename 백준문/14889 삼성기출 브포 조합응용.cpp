#include <iostream>
#include <algorithm>
using namespace std;

int n;
int graph[21][21];

bool check[21];

int result = 10000000;


void dfs(int index, int cnt)  //combi 조합이용 
{
	if (cnt == n/2)
    {
    	int a =0; 
		int b =0;
	
        for (int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++){
            	if(check[i] == true && check[j] == true){
					a = a + graph[i][j] + graph[j][i];
				}
				else if(check[i] == false && check[j] == false){
					b = b + graph[i][j] + graph[j][i];
				}
			}
        }
		result = min(result, abs(a-b));  
        return;
    }
    for (int i = index; i < n; i++)
    {
    	check[i] = true;
        dfs(i+1, cnt + 1); 
        check[i] = false;
    }
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
		}
	}
	
	
	dfs(0, 0);
	cout << result << endl;
}
