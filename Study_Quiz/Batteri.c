// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include<math.h>
#define MAX 1000000000
int main(void) {
	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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
		
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%f", Result);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}