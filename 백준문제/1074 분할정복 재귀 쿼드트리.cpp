#include <iostream>
#include <cmath>
using namespace std;

// ��α� ���� 
int n, r, c;
int ans;

//size�� 1���� ���� 
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
	
	// dc�ȿ��� ���ϴ� ans�� ����ϰ�,  dc������ ��� ������ 
	// ans�� �ᱹ size-1���� ����.  
	cout << ans; 

}
