//#include<stdio.h>
//int bomLoc[25000] = { 0, };
//int numStone, numBom, maxJump,  bomInd = 0;
//int countJump;
//int BomLoc(int Loc,int Left,int Right,int mid){
//	if (bomLoc[mid] == Loc)
//		return 1;
//
//	if (Left > Right||Right<Left)
//		return 0;
//	if (Left == Right)
//		return 0;
//	if (Loc > bomLoc[mid])
//		return BomLoc(Loc, mid, Right, (mid + Right) / 2);
//	else if (Loc< bomLoc[mid])
//		return BomLoc(Loc, Left, mid, (mid + Left) / 2);
//	
//
//}
//int Jump(int start, int end,int jump, int canNot){
//	int i,Ret_V;
//	if (jump == canNot)
//		return 0;
//	else if ( BomLoc(start,0,numBom,numBom/2))
//		return 0;
//	else if (start > end)
//		return 0;
//
//	if (start == end){
//		++countJump;
//		return 1;
//	}
//	
//	for (i = maxJump; i > 0; --i)
//		Ret_V = Jump(start + i, end, i, jump);
//	return 0;
//	
//}
//
//int main(void) {
//	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
//	만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
//	그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
//	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
//	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
//	// freopen("input.txt", "r", stdin);
//
//	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 '시간 초과'로 강제 종료 되었을 때,
//	printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
//	시간 초과 전까지 실행된 결과 점수를 받고자 하신다면 "setbuf(stdout, NULL);" 를 사용하시기 바랍니다. */
//	setbuf(stdout, NULL);
//
//	int T;
//	int test_case;
//
//	scanf("%d", &T);
//	for (test_case = 1; test_case <= T; test_case++) {
//		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
//		int i;
//		countJump = 0;
//		scanf("%d", &numStone);
//		scanf("%d", &maxJump);
//		scanf("%d", &numBom);
//		for (i = 0; i < numBom; ++i)
//			scanf("%d", &bomLoc[i]);
//		if (numStone<=5000)
//		for (i = maxJump; i > 0; --i)
//			Jump(0 + i, numStone, i, 0);
//
//		// 이 부분에서 정답을 출력하십시오.
//		printf("Case #%d\n", test_case);
//		printf("%d\n", countJump%1000000009);
//	}
//
//	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
//}

#include <stdio.h>
int stoneArr[50001][101];
int main(void) {
	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
	그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	// freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 '시간 초과'로 강제 종료 되었을 때,
	printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	시간 초과 전까지 실행된 결과 점수를 받고자 하신다면 "setbuf(stdout, NULL);" 를 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int numStone, maxJump,  numBomb,i,bombLoc,jump,j,Ret_V=0;
		scanf("%d", &numStone);
		scanf("%d", &maxJump);
		scanf("%d", &numBomb);
		if (numStone > 5000)
			break;
		for (i = 0; i < numBomb; i++){
			scanf("%d", &bombLoc);
			stoneArr[bombLoc][0] = -1;
		}
		
		for (i = 1; i <= numStone; ++i)
			if (stoneArr[i][0] != -1)
				for (jump = 1; jump <= maxJump && jump <= i; ++jump)
					if (i - jump == 0)
						stoneArr[i][jump] = 1;

					else if (i > jump)
						for (j = 1; j <= maxJump&& j <= i; ++j)
							if (stoneArr[i-jump][0]!=-1 && j != jump)
								stoneArr[i][jump] = (stoneArr[i][jump] + stoneArr[i - jump][j])%1000000009;

		for (j = 1; j <= maxJump; ++j)
			Ret_V =(Ret_V+ stoneArr[numStone][j])% 1000000009;
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", Ret_V%1000000009);
		for (i = 0; i <= numStone; ++i)
			for (j = 0; j <= maxJump && j <= i;++j)
			stoneArr[i][j] = 0;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}