// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include<math.h>
#define MAX 1000000000
int main(void) {
	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
	그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int Num_Line;
		int LEFT=MAX,RIGHT=0, UP=0, DOWN=MAX;
		double C_X, C_Y;
		double Result;
		scanf("%d", &Num_Line);
		while (Num_Line--){
			int X1, Y1,X2,Y2,Tmp;
			scanf("%d %d %d %d", &X1, &Y1,&X2,&Y2);
			LEFT = LEFT > (Tmp = X1 < X2 ? X1 : X2) ? Tmp : LEFT;
			RIGHT = RIGHT < (Tmp = X1 > X2 ? X1 : X2) ? Tmp : RIGHT;
			DOWN = DOWN >(Tmp = Y1 < Y2 ? Y1 : Y2) ? Tmp : DOWN;
			UP = UP <(Tmp = Y1 > Y2 ? Y1 : Y2) ? Tmp : UP;
		}
		C_X = (LEFT + RIGHT) / 2.0;
		C_Y = (UP+ DOWN) / 2.0;
		Result = sqrt(pow(LEFT - C_X, 2));
		Result = Result > sqrt(pow(RIGHT - C_X, 2)) ? Result : sqrt(pow(RIGHT - C_X, 2));
		Result = Result > sqrt(pow(UP - C_Y, 2)) ? Result : sqrt(pow(UP- C_X, 2));
		Result = Result > sqrt(pow(DOWN - C_Y, 2)) ? Result : sqrt(pow(DOWN - C_X, 2));
		
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%f", Result);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}