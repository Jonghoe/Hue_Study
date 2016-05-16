#include<stdio.h>
#include<string.h>
typedef struct {
	int row;
	int col;
}Point;

int Board[3][3];
Point Poss_p[9];
int Is_Win(int _turn){
	int Value = _turn*_turn*_turn;
	return Value == *(*(Board + 0) + 0) * *(*(Board + 0) + 1) * *(*(Board + 0) + 2) ||
		Value == *(*(Board + 1) + 0) * *(*(Board + 1) + 1) * *(*(Board + 1) + 2) ||
		Value == *(*(Board + 2) + 0) * *(*(Board + 2) + 1) * *(*(Board + 2) + 2) ||
		Value == *(*(Board + 0) + 0) * *(*(Board + 1) + 0) * *(*(Board + 2) + 0) ||
		Value == *(*(Board + 0) + 1) * *(*(Board + 1) + 1) * *(*(Board + 2) + 1) ||
		Value == *(*(Board + 0) + 2) * *(*(Board + 1) + 2) * *(*(Board + 2) + 2) ||
		Value == *(*(Board + 0) + 0) * *(*(Board + 1) + 1) * *(*(Board + 2) + 2) ||
		Value == *(*(Board + 2) + 0) * *(*(Board + 1) + 1) * *(*(Board + 0) + 2);
}
int win(int _turn,int Num){
	int Ret_V;
	for (int i = 0; i < Num; i++){
		if (*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) == 0){
			*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) = _turn;
			if (Is_Win(_turn)){
				*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) = 0;
				return _turn;
			}
			else{
				Ret_V = win(_turn % 2 + 1, Num);
				if (Ret_V != _turn)
					*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) = 0;
			}
		}
	}
	return 0;
}
int Who_Win(int Num_Stone,int turn,int Num_Poss_Choice){
	int i;
	if (Num_Stone <= 1)
		return 0;
	if (win(turn,Num_Poss_Choice) == turn)
		return turn;
	else{
		for (i = 0; i < Num_Poss_Choice; i++){
			*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) = turn;
			if (win(turn % 2 + 1, Num_Poss_Choice) != turn % 2 + 1)
				break;
			*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) = 0;
		}
		if (i == Num_Poss_Choice)
			return turn % 2 + 1;
		else
			return 0;
	}

}

int main(){
	int turn,j,i,C;
	int row, col;
	int Case,Num=0,Num_Poss=0,Value,T; 
	if (scanf("%d", &Case) != 1)
		return 0;
	getchar();
	for (C = 0; C < Case; C++){
		char tmp[3][3];
		for (i = 0; i < 3; i++){
			for (T = 0; T < 3; T++){
				scanf("%c",&tmp[i][T]);
			}
			for ( j = 0; j < 3; j++){
				if (tmp[i][j] == 'x'){
					Board[i][j] = 1;
					Num++;
				}
				else if (tmp[i][j] == 'o'){
					Board[i][j] = 2;
					Num++;
				}
				else Board[i][j] = 0;
			}
		}
		for ( row = 0; row < 3; row++)
			for ( col = 0; col < 3; col++)
				if (Board[row][col] == 0){
					Point tmp = { row, col };
					Poss_p[Num_Poss++] = tmp;
				}
		if (Num % 2 == 0)
			turn = 1;
		else
			turn = 2;
		Value = Who_Win(Num,turn,Num_Poss);
		if (Value == 0)
			printf("TIE");
		else if (Value == 1)
			printf("x");
		else if (Value == 2)
			printf("o");
		if (C != Case - 1)
			printf("\n");
	}
}