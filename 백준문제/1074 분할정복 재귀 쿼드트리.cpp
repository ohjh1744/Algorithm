#include <iostream>
#include <cmath>
using namespace std;

// 블로그 참고 
int n, r, c;
int ans;

//size는 1변의 길이 
void dc(int size, int y, int x){
	
	if(y == r && x == c){
		cout << ans << endl;
		return;
	}
	else if(r < y + size && c < x + size && r >= y && c >=x ){
		dc(size/2, y, x);
		dc(size/2, y, x + size/2);
		dc(size/2, y + size/2, x);
		dc(size/2, y + size/2, x + size/2);
	}
	else{
		ans += size * size;
	}
	
}
int main(){
	cin >> n >> r >> c;
	
	dc(pow(2, n), 0, 0);
	
	// dc안에서 원하는 ans를 출력하고,  dc과정이 모두 끝나면 
	// ans는 결국 size-1값을 가짐.  
	cout << ans; 

}
