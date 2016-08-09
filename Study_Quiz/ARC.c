#include<stdio.h>
#include<math.h>
typedef struct Point_tag Point;
struct Point_tag{
	double x, y;
	int Region;
};
#define CalcDist(A ,  B) sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2))
Point City[100];
int main()
{
	int Case;
	scanf("%d", &Case);
	while (Case--){
		int regionNum = 0;
		int numCity,i,j;
		scanf("%d", &numCity);
		for (i = 0; i < numCity; ++i){
			scanf("%lf %lf", &City[i].x, &City[i].y);
			City[i].Region = -1;
		}
		for (i = 0; i < numCity; ++i){
			double min = 1500.0;
			int index = -1;
			for (j = 0; j < numCity;++j)
				if (j != i){
					double dist = CalcDist(City[i], City[j]);
					if (min > dist){
						min = dist;
						index = j;
					}
				}
			if (City[index].Region != -1)
				City[i].Region = City[index].Region;
			else
				City[i].Region = City[index].Region = regionNum++;
				
		}
			
	}
}