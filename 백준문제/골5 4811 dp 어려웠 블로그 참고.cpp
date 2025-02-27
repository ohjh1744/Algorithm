#include <iostream>

using namespace std;

//참고
// https://velog.io/@y00913/%EB%B0%B1%EC%A4%80-4811-%EC%95%8C%EC%95%BD-C 

int N;
//앞이 알 하나, 뒤에가 반절 
long long dp[31][31];

void solution() {
	// 반절씩만 남은경우 경우의수는 1개 밖에 없음. HHHHH.. 
    for (int i = 0; i <= 30; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
        	//알 하나남은경우 
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
                continue;
            }
            
            //알과 반절이 각각 남아있는경우  
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    while (1) {
        cin >> N;
        if (!N) break;
        cout << dp[N][0] << endl;
    }

    return 0;
}
