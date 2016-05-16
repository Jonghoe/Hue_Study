#include<stdio.h>
#include<string.h>

int main(){
	int Case,size,i,len;
	int Where[2000];
	char list[2000][80];
	scanf("%d", &Case);
	for (size = 0; size < Case; size++){
		scanf("%d",&Where[size]);
		scanf("%s", &list[size]);
		len = strlen(list[size]);
		for (i = Where[size] - 1; i < len; i++)
			list[size][i] = list[size][i + 1];
	}

	printf("\n");
	for (size = 0; size < Case; size++)
		printf("%d %s\n", size + 1 , list[size]);
}