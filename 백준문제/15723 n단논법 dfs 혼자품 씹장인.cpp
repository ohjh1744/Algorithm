#include <iostream>
#include <vector>
using namespace std;

int n;
int m; 
vector <char> v[26];
bool visited[26];

void dfs(char from)
{
	int fr = from - 'a';
	visited[fr] = true;
	for(int i = 0; i < v[fr].size(); i++){
		char to = v[fr][i];
		int tto = to - 'a';
		if(visited[tto] == true){
			continue;
		}
		dfs(to);
	}
}

void reset()
{
	for(int i = 0; i < 26; i++){
		visited[i] = 0;
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		char start, end;
		string equal;
		cin >> start >> equal >> end;
		int from = start - 'a';
		v[from].push_back(end);
	}
	
	cin >> m;
	
	for(int i = 0; i < m; i++){
		char a , b;
		string c;
		cin >> a >> c >> b;
		dfs(a);
		int num = b - 'a';
		if(visited[num] == true){
			cout << "T" << "\n";
		}
		else if(visited[num] == false){
			cout << "F" << "\n";
		}
		reset();
	}
	
}

