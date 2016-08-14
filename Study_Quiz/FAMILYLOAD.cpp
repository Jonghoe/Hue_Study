#include<stdio.h>
int order[100000];
int main()
{
	int Case;
	scanf("%d",&Case);
	while (Case--){
		int numP,numT;
		scanf("%d %d", &numP, &numT);
		order[0] = -1;
		for (int i = 1; i < numP; ++i)
			scanf("%d", &order[i]);
	
		for (int i = 0; i < numT; ++i){
			int f1, f2, tmp;
			int count[100000];
			for (int j = 0; j < numP; ++j)
				count[j] = -1;
			scanf("%d %d", &f1, &f2);
			//-----------------------f1의 0 조상까지 조사--------------------------
			int Count = 0;
			int Find = 0;
			for (tmp = f1; tmp != -1 && !Find; tmp = order[tmp], ++Count){
				if (tmp == f2){
					Find = 1;
					--Count;
				}
				count[tmp] = Count;
			}
			//------------------------찾았을 경우-------------------------------
			if (Find)
				printf("%d\n", Count);
			//-------------------------못 찾은 경우----------------------------
			else{
				Count = 0;
				for (tmp = f2; (tmp != -1) && (count[tmp] == -1); tmp = order[tmp], ++Count)
					;
				printf("%d\n", Count + count[tmp]);
			}

		}
	
	}
}