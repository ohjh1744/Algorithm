#include <bits/stdc++.h>

using namespace std;

int in[101][101];
int visited[101][101]; //0�ʱ�ȭ���� 

int n , m;

bool check(int y, int x){
	if(y<1 || y> n || x<1 || x>m){
		return false;   // y���� x���� �ʹ�ũ�ų� ��������
		 
	}
	if(in[y][x] == 0){
		return false; // y�� x��ǥ�� 0�α��� �������� 
	}
	if(visited[y][x]){
		return false;   //�ǳʰ����ϴ°��� �湮�Ѱ�����üũ
		 
	}
	return true;
}

int main()
{ 
   
   cin >> n ;
   cin >> m;
   
   for(int i =1; i <= n ; i++){
   	for(int j= 1; j <= m; j++){
   		scanf("%1d" , &in[i][j]);
	   }
   }
   
   queue<int> qy, qx , qc;
   qy.push(1), qx.push(1) , qc.push(1);
   int cnt = 0;
   
   while(!qy.empty()){
   	int cy = qy.front();
   	qy.pop();
   	int cx = qx.front();
   	qx.pop();
   	int cc = qc.front();
   	qc.pop();
   	if(visited[cy][cx]){
   		continue;      //�湮�Ѵ�� �Ʒ��ڵ� �ǳʰ���
		    
	}
	visited[cy][cx] = 1;
   	
   	if(cy == n && cx == m){
   		cnt = cc;
	   break;
	}
   	
   	if(check(cy-1,cx)){
		   qy.push(cy-1), qx.push(cx) , qc.push(cc+1); //�� 
	   }
	   
   	if(check(cy+1,cx)){
		   qy.push(cy+1), qx.push(cx) , qc.push(cc+1); //��	
	   }
	    
   	if(check(cy,cx-1)){
		   qy.push(cy), qx.push(cx-1) , qc.push(cc+1); //�� 
	   }
	   
   	if(check(cy,cx+1)){
		   qy.push(cy), qx.push(cx+1) , qc.push(cc+1); //��
	   }
	      	
   }
   
   cout << cnt;
   return 0;
   
}
