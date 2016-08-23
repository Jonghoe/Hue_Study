#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int B_Search(vector<int>& vc, int left,int right,int V){
	int mid = (left + right) / 2;
	if (mid== left)
		return left;
	if (vc[mid] <= V)
		return B_Search(vc, mid, right, V);
	else
		return B_Search(vc, left, mid, V);
}
int main(){
	
	int Case, prev,now,loc=1,b,e;
	vector<int> vLoc;
	prev = getchar();
	vLoc.push_back(0);
	while ((now = getchar()) != '\n'){
		if (now != prev){
			vLoc.push_back(loc);
			prev = now;
		}
		++loc;
	}
	vLoc.push_back(loc);
	scanf("%d", &Case);

	while (Case--){
		int B, E;
		scanf("%d%d", &b, &e);
		B = B_Search(vLoc, 0, vLoc.size(), b);
		E = B_Search(vLoc, 0, vLoc.size(), e);
		if (B == E)
			printf("Yes\n");
		else
			printf("No\n");
	}
}