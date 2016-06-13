#include<stdio.h>
int main(){
	int Case, Stage, Len ;
	int i, Tmp_Max, Max, j = 0, Check;
	int Array1[100000];
	int Array2[100000];
	scanf("%d", &Case);
	for (Stage = 0; Stage < Case; Stage++){
		j = 0;
		scanf("%d", &Len);
		do{
			scanf("%d", &Array1[0]);
			if (Array1[0] >= 0)
				Check = 0;
			else
				Check = 1;
			Array2[0] = Array1[0];
		} while (!(-100 <= Array1[0] && Array1[0] <= 100));
		for (i = 1; i < Len; i++){
			scanf("%d", &Array1[i]);
			if (-100 <= Array1[i] && Array1[i] <= 100){
				if (Check == 0 && Array1[i] >= 0)
					Array2[j] += Array1[i];
				else if (Check == 1 && Array1[i] < 0)
					Array2[j] += Array1[i];
				else{
					Array2[++j] = Array1[i];
					Check = (Check + 1) % 2;
				}
			}
			else
				i--;
		}
		Max = Tmp_Max = 0;
		for (i = 0; i <= j; i++){
			if (Tmp_Max + Array2[i] >= 0)
				Tmp_Max += Array2[i];
			else
				Tmp_Max = 0;
			if (Tmp_Max > Max)
				Max = Tmp_Max;
		}
		printf("%d\n", Max);
	}
}



#include<stdio.h>
#include<string.h>
int AS(int Start, int D, int n){
	int i = 0, Val = Start;
	for (i = 0; i < n; i++)
		Val += D;
	return Val;
}
int main(){
	int A, i;
	for (i = 1; i < 6; i++){
		A = AS(0, AS(0, 1, i), i);
		printf("%d\n", A);
	}
}
