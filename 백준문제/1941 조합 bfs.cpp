#include <iostream>
#include <queue>
using namespace std;

int arr[5][5];
bool sel[25];
int ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check_select[5][5]; // ���� ������ �л������� Ȯ��  adj�Լ����� 
bool visit_select[5][5]; //�湮���� Ȯ��  adj�Լ����� 

void clear()  //adj�Լ����� �ʱ�ȭ��� 
{
	for(int i = 0; i <5; i++){
		for(int j = 0; j <5; j++){
			check_select[i][j] = false;
			visit_select[i][j] = false;
		}
	}
}

bool four()
{
	int ct= 0;
	for(int i = 0; i < 25; i++){
		if(sel[i] == true){
			int y = i / 5;
			int x = i % 5 ;
			if(arr[y][x] == 2){
				ct++;
			}
		}
	}
	if(ct >= 4){
		return true;
	}
	else{
		return false;
	}
}

bool ajc()
{
	queue <pair< int, int > > q; 
	bool chk = false;  // 7��Ȯ���� �����ϸ� true 
	clear();
	
	bool start = true; 
	for(int i = 0; i < 25; i++){
		if(sel[i] == true){
			int y = i / 5;
			int x = i % 5 ;
			check_select[y][x] = true;
			
			if(start == true){  //���������� �ֱ��ϴ� 
				q.push({y, x});
				visit_select[y][x] = true;
				start = false;
			}
		}
	}
	
	int cnt = 1; // 7��Ȯ�� 
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		if(cnt == 7){
			chk = true;
			break;
		}
		
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 0 || nx < 0 || ny >= 5  || nx >= 5){
				continue;
			}
			if(check_select[ny][nx] == true && visit_select[ny][nx] == false){
				cnt++;
				q.push({ny, nx});
				visit_select[ny][nx] = true;
			}
		}
	}
	
	if(chk == true){
		return true;
	}
	else{
		return false;
	}
	
}


void dfs(int idx, int cnt) // ���� 7 �j�� 
{
	if(cnt == 7){
		if(four() == true){
			if(ajc() == true){
				ans++;
			} 
		}
	}
	
	for(int i = idx; i < 25; i++){
		if(sel[i] == true){
			continue;  
		}
		sel[i] = true;
		dfs(i , cnt+1);
		sel[i] = false;
	}
}



int main()
{
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			char input;
			cin >> input;
			if(input == 'Y'){
				arr[i][j] = 1;
			}
			else if(input == 'S'){
				arr[i][j] = 2;
			}
		}
	}
	
	dfs(0, 0);
	cout << ans << endl;
	
	
}


