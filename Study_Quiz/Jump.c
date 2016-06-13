#include<stdio.h>
int Board[100][100];
int Board_Tmp[100][100];
int Len;

int Find_Load(int row,int col){
	if (row >= Len || col >= Len)
		return 0;
	if (Board_Tmp[row][col] == 1)
		return 0;
	if (row == Len - 1 && col == Len - 1)
		return 1;
	
	Board_Tmp[row][col] = 1;
	return Find_Load(Board[row][col] + row, col) 
		|| Find_Load(row, col + Board[row][col]);
}
int main(){
	int Case,C=0;
	do{
		scanf("%d", &Case);
	} while (!(0 <= Case&&Case <= 50));
	while (Case--){
		int Row, Col, Val,i;
		do{
			scanf("%d", &Len);
		} while (!(2 <= Len&&Len <= 100));

		//--------- 점프판 초기화 --------
		for (Row = 0; Row < Len; Row++)
		for (Col = 0; Col < Len; Col++){
			if (!(Row == Len - 1 && Col == Len - 1)){
				do{
					scanf("%d", &Val);
				} while (!(1 <= Val&&Val <= 9));
				Board[Row][Col] = Val;
			}
			Board_Tmp[Row][Col] = 0;
		}
		//--------------------------------
		if (Find_Load(0,0))
			printf("YES\n");
		else
			printf("NO\n");
		
	}
}
