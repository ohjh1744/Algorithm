#include <iostream>
using namespace std;

int arrX[100001];
int arrY[100001];
int n;

void down_heap(int parent, int len, int arr1[], int arr2[]){
	
	int big = parent;
	int left = parent*2;
	int right = parent*2 + 1;
	
	if(left <= len){
		if(arr1[left] > arr1[big]){
			big = left;
		}
		else if(arr1[left] == arr1[big] && arr2[left] > arr2[big]){
			big = left;
		}
	} 
	
	if(right <= len){
		if(arr1[right] > arr1[big]){
			big = right;
		}
		else if(arr1[right] == arr1[big] && arr2[right] > arr2[big]){
			big = right;
		}
	} 
	
	if(big != parent){
		
		int temp = arr1[parent];
		arr1[parent] = arr1[big];
		arr1[big] = temp;
		
		temp = arr2[parent];
		arr2[parent] = arr2[big];
		arr2[big] = temp;
		
		down_heap(big, len, arr1, arr2);
	}
}

void HeapSort(int len, int arr1[] ,int arr2[]){
	// 힙구조 생성 
	for(int i = len/2; i >= 1; i--){
		down_heap(i, len, arr1, arr2);
	}
	
	//오름차순 정렬 
	for(int i = len; i >= 2; i--){
		int temp = arr1[i];
		arr1[i] = arr1[1];
		arr1[1] = temp;
		
		temp = arr2[i];
		arr2[i] = arr2[1];
		arr2[1] = temp;
		
		down_heap(1, i-1, arr1 , arr2);
	}
	
}


int main(){
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arrX[i] >> arrY[i];
	}
	HeapSort(n, arrX, arrY);	
	
	for(int i = 1; i <= n; i++){
		cout << arrX[i] << " " << arrY[i] << "\n";
	}
		
}
