#include<stdio.h>
#include<string.h>
typedef struct {
	int row;
	int col;
}Point;
int Num_Stone;
int Board[3][3];
Point Poss_p[9];
int Is_Win(int _turn){
	int Value = _turn*_turn*_turn;
	return
		Value == *(*(Board + 0) + 0) * *(*(Board + 0) + 1) * *(*(Board + 0) + 2) ||
		Value == *(*(Board + 1) + 0) * *(*(Board + 1) + 1) * *(*(Board + 1) + 2) ||
		Value == *(*(Board + 2) + 0) * *(*(Board + 2) + 1) * *(*(Board + 2) + 2) ||
		Value == *(*(Board + 0) + 0) * *(*(Board + 1) + 0) * *(*(Board + 2) + 0) ||
		Value == *(*(Board + 0) + 1) * *(*(Board + 1) + 1) * *(*(Board + 2) + 1) ||
		Value == *(*(Board + 0) + 2) * *(*(Board + 1) + 2) * *(*(Board + 2) + 2) ||
		Value == *(*(Board + 0) + 0) * *(*(Board + 1) + 1) * *(*(Board + 2) + 2) ||
		Value == *(*(Board + 2) + 0) * *(*(Board + 1) + 1) * *(*(Board + 0) + 2);
}

Point Find_Point(int _turn,int Num){
	Point False = { -1, -1 };
	for (int i = 0; i < Num; i++){
		if (Board[Poss_p[i].row][Poss_p[i].col] == 0){
			Board[Poss_p[i].row][Poss_p[i].col] = _turn;
			if (Is_Win(_turn)){
				Board[Poss_p[i].row][Poss_p[i].col] = 0;
				Point tmp = { Poss_p[i].row, Poss_p[i].col };
				return tmp;
			}
			Board[Poss_p[i].row][Poss_p[i].col] = 0;
		}
	}
	return False;
}
void Print_Board(){
	int row, col;
	for (row = 0; row < 3; row++){
		for (col = 0; col < 3; col++)
			switch (Board[row][col]){
			case 0:printf("."); break;
			case 1:printf("x"); break;
			case 2:printf("o"); break;
		}
	printf("\n");
	}
	printf("\n");
}
int win(int _turn,int Num){
	int Tmp_Ret_V = -1;
	int Ret_V=0;
	for (int i = 0; i < Num; i++){
		if (*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) == 0){
			if (Find_Point(_turn % 2 + 1, Num).row == -1){
				if (Find_Point(_turn, Num).row == -1){
					Num_Stone++;
					*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) = _turn;
					Print_Board();
					if (Tmp_Ret_V == -1){
						Ret_V = win(_turn % 2 + 1, Num);
						Tmp_Ret_V = Ret_V;
					}
					else{
						Tmp_Ret_V = win(_turn % 2 + 1, Num);
						if (Tmp_Ret_V == _turn % 2 + 1 && Ret_V != 0)
							Ret_V = Tmp_Ret_V;
					}
					*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) = 0;
					Print_Board();
					Num_Stone--;
					if (Ret_V == _turn)
						return _turn;
				}
				else
					return _turn;
			}
			else{
				Num_Stone++;
				*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) = _turn;
				Print_Board();
				if (Tmp_Ret_V == -1){
					Ret_V = win(_turn % 2 + 1, Num);
					Tmp_Ret_V = Ret_V;
				}
				else{
					Tmp_Ret_V = win(_turn % 2 + 1, Num);
					if (Tmp_Ret_V == _turn % 2 + 1 && Ret_V != 0)
						Ret_V = Tmp_Ret_V;
				}
				*(*(Board + (Poss_p + i)->row) + (Poss_p + i)->col) = 0;
				Print_Board();
				Num_Stone--;
				if (Ret_V == _turn)
					return _turn;
			}
		}
	}
	if (Ret_V == 0)
		return 0;
	if (Num_Stone != 9  )
		return _turn % 2 + 1;
	else
		return 0;
}
int Who_Win(int turn,int Num_Poss_Choice){
	int i;
	if (Num_Stone < 1)
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
		if (i == Num_Poss_Choice && Num_Poss_Choice != 0)
			return turn % 2 + 1;
		else
			return 0;
	}

}

int main(){
	int turn,j,i,C;
	int row, col;
	int Case,Num_Poss=0,Value,T; 
	if (scanf("%d", &Case) != 1)
		return 0;
	getchar();
	for (C = 0; C < Case; C++){
		char tmp[3][3];
		Num_Stone = 0;
		Num_Poss = 0;
		for (row = 0; row < 3; row++)
			for (col = 0; col < 3; col++)
				Board[row][col] = 0;
		for (i = 0; i < 3; i++){
			for (T = 0; T < 3; T++)
				scanf("%c",&tmp[i][T]);
			
			for ( j = 0; j < 3; j++){
				if (tmp[i][j] == 'x'){
					Board[i][j] = 1;
					Num_Stone++;
				}
				else if (tmp[i][j] == 'o'){
					Board[i][j] = 2;
					Num_Stone++;
				}
				else Board[i][j] = 0;
			}
			getchar();
		}
		for ( row = 0; row < 3; row++)
			for ( col = 0; col < 3; col++)
				if (Board[row][col] == 0){
					Point tmp = { row, col };
					Poss_p[Num_Poss++] = tmp;
				}
		if (Num_Stone % 2 == 0)
			turn = 1;
		else
			turn = 2;
		Value = Who_Win(turn,Num_Poss);
		printf("\n");
		if (Value == 0)
			printf("TIE");
		else if (Value == 1)
			printf("x");
		else if (Value == 2)
			printf("o");
		
	}
}