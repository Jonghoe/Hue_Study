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
//	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
//	���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
//	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
//	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
//	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
//	// freopen("input.txt", "r", stdin);
//
//	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� '�ð� �ʰ�'�� ���� ���� �Ǿ��� ��,
//	printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
//	�ð� �ʰ� ������ ����� ��� ������ �ް��� �ϽŴٸ� "setbuf(stdout, NULL);" �� ����Ͻñ� �ٶ��ϴ�. */
//	setbuf(stdout, NULL);
//
//	int T;
//	int test_case;
//
//	scanf("%d", &T);
//	for (test_case = 1; test_case <= T; test_case++) {
//		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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
//		// �� �κп��� ������ ����Ͻʽÿ�.
//		printf("Case #%d\n", test_case);
//		printf("%d\n", countJump%1000000009);
//	}
//
//	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
//}

#include <stdio.h>
int stoneArr[50001][101];
int main(void) {
	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	// freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� '�ð� �ʰ�'�� ���� ���� �Ǿ��� ��,
	printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	�ð� �ʰ� ������ ����� ��� ������ �ް��� �ϽŴٸ� "setbuf(stdout, NULL);" �� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", Ret_V%1000000009);
		for (i = 0; i <= numStone; ++i)
			for (j = 0; j <= maxJump && j <= i;++j)
			stoneArr[i][j] = 0;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}