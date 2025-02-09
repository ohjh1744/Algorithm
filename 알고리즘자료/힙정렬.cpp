#include <iostream>
using namespace std;

int arr[];
//https://reakwon.tistory.com/43 ���� ���� �ߴ�����. 
// ���� 1���� n���� �ִٰ� ���� 
//������ ����°� ��Ÿ(n), ������ nlogn 

void heapify(int &arr[], int here, int size) {
    int left = here * 2;
    int right = here * 2 + 1;
    int max = here;
    if (left <= size && arr[left]>arr[max])
        max = left;
    if (right <= size && arr[right]>arr[max])
        max = right;
 
    if (max != here) {
    	int temp = arr[here];
    	arr[here] = arr[max];
    	arr[max] = temp;
        heapify(arr, max, size);
    }
}

void buildHeap(int &arr[], int size) {
    int i;
    for (i = size / 2; i >= 1; i--) {
        heapify(arr, i, size);
    }
}

void heapSort(int &arr[],int size) {
    buildHeap(arr, size);
    for (int i = size; i >= 2; i--) {
        swap(&arr[0], &arr[treeSize]);
        heapify(arr, 1, i-1);
    }
}
