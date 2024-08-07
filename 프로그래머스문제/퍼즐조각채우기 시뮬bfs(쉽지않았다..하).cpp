#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


// 90도로 변환한 테이블 저장
int table90[51][51];

int visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1}; 

// 빈 공간의 좌표들과 block좌표들 저장.
vector < pair < int , int > > origin_temp_board[2601];
vector < pair < int , int > > origin_temp_table[2601];
vector < pair < int , int > > temp_board[2601];
vector < pair < int , int > > temp_table[2601];
bool putbloc[2601] = {false};

int answer = 0;
int re = 0;

void bfs(int y, int x, int checknum, int num ,vector<vector<int>> v , vector < pair < int , int > > temp[], bool isboard){
	visited[y][x] = true;
	queue < pair < int, int > > q;
	q.push({y, x});
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
        temp[num].push_back({cy-y, cx-x});
        if(isboard == true){
            origin_temp_board[num].push_back({cy, cx});
        }
        else if(isboard == false){
        	origin_temp_table[num].push_back({cy, cx});
		}
		for(int i = 0; i < 4 ; i++){
			int ny = cy + dy[i];
			int nx= cx + dx[i];
			if(ny < 0 || nx <0 || ny >= v.size() || nx >= v.size()){
				continue;
			}
            if(visited[ny][nx]){
                continue;
            }
			if(v[ny][nx] == checknum ){
				q.push({ny, nx});
				visited[ny][nx] = true;
			}
		}
	}	 
} 
 
void Rotation90(vector<vector<int>> table){
	for(int i = 0; i < table.size(); i++){
		for(int j = 0; j < table.size(); j++){
			table90[j][table.size()-1-i]  = table[i][j]; 
		}
	}
}

vector<vector<int>> UpdateTable(vector<vector<int>> table){
	for(int i = 0; i < table.size(); i++){
		for(int j = 0; j < table.size(); j++){
			table[i][j] = table90[i][j];
		}
	}
	
	return table;
} 

void reset(int ysize, int xsize){
    for(int i = 0; i < ysize; i++){
        for(int j = 0; j < xsize; j++){
            visited[i][j] = 0;
        }
    }
}

void reset2(int ysize, int xsize){
    for(int i = 0; i < ysize; i++){
        for(int j = 0; j < xsize; j++){
            table90[i][j] = 0;
        }
    }
    for(int i = 0; i < 2601; ++i) {
        origin_temp_board[i].clear();
        origin_temp_table[i].clear();
        temp_board[i].clear();
        temp_table[i].clear();
        putbloc[i] = 0; 
    }   
    
}

int solution(vector < vector < int >> game_board, vector < vector < int >> table) {

    int ysize = game_board.size();
    int xsize = game_board.size();

    while (re < 4) {
    	reset2(ysize, xsize);
    	
        reset(ysize, xsize);
        int numplace = 0;
        for (int i = 0; i < ysize; i++) {
            for (int j = 0; j < xsize; j++) {
                if ( !visited[i][j] && game_board[i][j] == 0) {
                    bfs(i, j, 0, numplace, game_board, temp_board, true);
                    numplace++;
                }
            }
        }

        reset(ysize, xsize);
        int numbloc = 0;
        
        for (int i = 0; i < ysize; i++) {
            for (int j = 0; j < xsize; j++) {
                if (!visited[i][j] && table[i][j] == 1) {
                    bfs(i, j, 1, numbloc, table, temp_table, false);
                    numbloc++;
                }
            }
        }

        //순서번호
        int i_board = 0;
        int i_table = 0;
        int j_board = 0;
        int j_table = 0;
        int isright = 0;
        
        // 첫번째 블록부터 numbloc번째 블록까지 순서대로 빈공간과 비교 
        while (i_table < numbloc) {
            j_table = 0;
            j_board = 0;
            isright = 0;
            
			//마지막 빈공간까지 비교했다면 다음 블록을 첫번째블록부터 다시 비교 
            if (i_board == numplace) {
                i_table++;
                i_board = 0;
                continue;
            }
            //블록사이즈와 빈공간사이즈가 다르거나, 공간이 채워져있다면 넘어감. 
            if (temp_table[i_table].size() != temp_board[i_board].size() || putbloc[i_board] == true) {
                i_board++;
                continue;
            }
            
			// 사이즈가 같다면, 하나하나 비교시작. 
            while (j_table < temp_table[i_table].size()) {
                if (temp_table[i_table][j_table].first == temp_board[i_board][j_board].first && temp_table[i_table][j_table].second == temp_board[i_board][j_board].second) {
                    isright++;
                    j_table++;
                    j_board++;
                } else {
                    break;
                }
            }

            // 만약 동일한 도형일 경우
            if (isright == temp_table[i_table].size()) {
                putbloc[i_board] = true;
                // board 빈칸 2로 채워주기
                for (int i = 0; i < origin_temp_board[i_board].size(); i++) {
                    int y = origin_temp_board[i_board][i].first;
                    int x = origin_temp_board[i_board][i].second;
                    game_board[y][x] = 2;
                    answer += 1;
                }
                //table에도 사용한 블럭 2로 바꿔주기 
                for (int i = 0; i < origin_temp_table[i_table].size(); i++) {
                    int y = origin_temp_table[i_table][i].first;
                    int x = origin_temp_table[i_table][i].second;
                    table[y][x] = 2;
                }
                i_table++;
                i_board = 0;
            } 
			else {
                //동일한 도형이 아닐경우
                i_board++;
            }
        }

        Rotation90(table);
        table = UpdateTable(table);      
        re +=1;
        
    }

    return answer;
}
