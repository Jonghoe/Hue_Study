#include <stdio.h>
double Composition[100][100];
double composition(int n, int r) {
	int i;
	double Val = 1;
	if (r == 0 || n == r)
		return 1;
	for (i = 0; i < r; i++)
		Val *= n-i;
	for (i = r; i > 1; i--)
		Val /= i;
	return Val;
}
int main() {
	int numcases, As, Bs, nth,Loc=0,Or=1,F_Loc;
	int Strip[200];
	int i, j;
	//----------- а╤гу (Combination)----------------
	for (i = 0; i < 100; i++)
	for (j = 0; j <=i; j++)
		Composition[i][j] = composition(i + j, j);
	for (i = 0; i < 100; i++)
		for (j = i + 1; j < 100; j++)
			Composition[i][j] = Composition[j][i];
	//-----------------------------------------------
	scanf("%d", &numcases);
	while (numcases--) {
		int Len;
		scanf("%d %d %d", &As, &Bs, &nth);
		Len = As + Bs - 1;
		for (i = 0; i < As + Bs; i++)
			Strip[i] = 0;
		Or = 1;
		F_Loc = As;
		while (Or <= Bs){
			F_Loc = Len - (Bs - Or);
			for (Loc = 0; nth - Composition[Loc][Bs - Or] > 0; ++Loc){
				nth -= Composition[Loc][Bs - Or];
				--F_Loc;
			}
			Strip[F_Loc] = 1;
			++Or;
		}
		for (i = 0; i < As + Bs; i++){
			if (Strip[i]==0)
				printf("-");
			else
				printf("o");
		}
		printf("\n");
	}

	return 0;
}