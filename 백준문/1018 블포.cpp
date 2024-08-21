#include <iostream>
#include <algorithm>
using namespace std;
string f_w[8] = {
	    "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"	
};
	string f_b[8] = {
	    "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int ct_fw, ct_fb;
int m, n;
char input[50][50];

void cp_fw(int y, int x)
{
	for(int i = 0; i< 8; i++){
		for(int j = 0; j < 8; j++){
			if(input[i+y][j+x] != f_w[i][j]){
				ct_fw++;
			}
		}
	}
}

void cp_fb(int y, int x)
{
	for(int i = 0; i< 8; i++){
		for(int j = 0; j < 8; j++){
			if(input[i+y][j+x] != f_b[i][j]){
				ct_fb++;
			}
		}
	}
}
	
int main()
{	
	cin >> m >> n;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> input[i][j];
		}
	}
	
	int ans = 10000000;
	for(int i = 0; i+8 <= m; i++){
		for(int j = 0; j+8 <= n; j++){
			cp_fw(i, j);
			cp_fb(i, j);
			ans = min(ans, min(ct_fw, ct_fb));
			ct_fw = 0;
			ct_fb = 0;
		}
	}
	cout << ans << endl;
	
	
}
