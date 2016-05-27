#include <iostream>
#include <string>
typedef struct{
	int row;
	int col;
}Point;
#define TIE 0
#define W 3
#define H 3
#define Change_Turn(x) ((x)%2 +1 )
using namespace std;

class Board{
	private:
		int mvBoard[H][W];
		int turn;
		int Num_Stone;
		int Num_Poss_Choice;
		Point Poss_Choice[9];
	public:
		Board(){
			Num_Stone = 0;
			turn = 0;
			Num_Poss_Choice = 0;
			for (int i = 0; i < 9; i++)
				*((*mvBoard) + i) = 0;
		}
		void Set_mvBoard(){
			string tmp;
			for (int i = 0; i < 3; i++){
				cin >> tmp;
				for (int j = 0; j < 3; j++){
					if (tmp[j] == 'x'){
						mvBoard[i][j] = 1;
						Num_Stone++;
					}
					else if (tmp[j] == 'o'){
						mvBoard[i][j] = 2;
						Num_Stone++;
					}
					else mvBoard[i][j] = 0;
				}
			}
		}
		bool Is_Win(int _turn){
			int Value = _turn*_turn*_turn;
			return Value == mvBoard[0][0] * mvBoard[0][1] * mvBoard[0][2] ||
				Value == mvBoard[1][0] * mvBoard[1][1] * mvBoard[1][2] ||
				Value == mvBoard[2][0] * mvBoard[2][1] * mvBoard[2][2] ||
				Value == mvBoard[0][0] * mvBoard[1][0] * mvBoard[2][0] ||
				Value == mvBoard[0][1] * mvBoard[1][1] * mvBoard[2][1] ||
				Value == mvBoard[0][2] * mvBoard[1][2] * mvBoard[2][2] ||
				Value == mvBoard[0][0] * mvBoard[1][1] * mvBoard[2][2] ||
				Value == mvBoard[0][2] * mvBoard[1][1] * mvBoard[2][0];
		}
		bool Find_Point(int _turn,Point* Ret_V){
			Point False = { -1, -1 };
			for (int i = 0; i < Num_Poss_Choice; i++){
				if (mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] == 0){
					mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = _turn;
					if (Is_Win(_turn)){
						mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = 0;
						Ret_V->row = Poss_Choice[i].row;
						Ret_V->col = Poss_Choice[i].col;
						return true;
					};
					mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = 0;
				}
			}
			return false;
		}
		int win(int _turn){
			int Ret_V;
			Point Tmp;
			Point False = { -1, -1 };
			for (int i = 0; i < Num_Poss_Choice; i++){
				if (mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] == 0){
					if (Find_Point(Change_Turn(_turn),&Tmp)){
						Num_Stone++;
						mvBoard[Tmp.row][Tmp.col] = _turn;
						Print_Board();
						Ret_V = win(Change_Turn(_turn));
						if (Ret_V != _turn){
							mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = 0;
							Print_Board();
							Num_Stone--;
						}
						else{
							mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = 0;
							Print_Board();
							Num_Stone--;
							return _turn;
						}
					}
					else if (!Find_Point(_turn,&Tmp)){
						Num_Stone++;
						mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = _turn;
						Print_Board();
						Ret_V = win(Change_Turn(_turn));
						if (Ret_V != _turn){
							mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = 0;
							Print_Board();
							Num_Stone--;
						}
						else{
							mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = 0;
							Print_Board();
							Num_Stone--;
							return _turn;
						}
					}
					else
						return _turn;
				}
			}
			if (Num_Stone == 9)
				return TIE;
			else
				return Change_Turn(_turn);
		}
		
		int Who_Win(){
			int i;
			if (Num_Stone < 1)
				return TIE;
			if (win(turn)==turn)
				return turn;
			else{
				Print_Board();
				for ( i = 0; i < Num_Poss_Choice; i++){
					mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = turn;
					if (win(Change_Turn(turn)) != Change_Turn(turn))
						break;
					mvBoard[Poss_Choice[i].row][Poss_Choice[i].col] = 0;
				}
				if (i ==Num_Poss_Choice)
					return Change_Turn(turn);
				else
					return TIE;
			}
			
		}
		void Print_Board(){
			cout << endl;
			for (int row = 0; row < H; row++){
				for (int col = 0; col < W;col++)
					switch (mvBoard[row][col]){
					case 0:printf("."); break;
					case 1:printf("x"); break;
					case 2:printf("o"); break;
				}
				printf("\n");
			}
			cout << endl;

	
		}
		
		void Find_Poss(){
			for (int row = 0; row < H; row++)
				for (int col = 0; col < H; col++)
					if (mvBoard[row][col] == 0){
						Point tmp = { row, col };
						Poss_Choice[Num_Poss_Choice++] = tmp;
					}
		}
	void mPlay(){
		int Value;
		Set_mvBoard();
			Find_Poss();
		if (Num_Stone % 2 == 0)
			turn = 1;
		else
			turn = 2;
		Value = Who_Win();
		if (Value == TIE)
			cout << "TIE" << endl;
		else if (Value == 1)
			cout << "x" << endl;
		else if (Value == 2)
			cout << "o" << endl;
	}
	
};
int main(){
	Board Main_Board;
	int Case;
	cin >> Case;
	for (int i = 0; i < Case; i++)
		Main_Board.mPlay();
}
