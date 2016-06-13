#include<stdio.h>
int* Add(int A){
	return &(++A);
}
int main(){
	int A = 5;
	int B[5] = { 1, 2, 3, 4, 5 };
	int* C;
	C = &A;
	printf("%d",C[0]);
}