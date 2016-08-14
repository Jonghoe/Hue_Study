#include<stdio.h>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef vector<int> Container;
int arr[50] ;
int Determine(int id,int N,Container& c,int MAX){
	Container tmp;
	int Size = c.size();
	// 이전 값 저장
	for (int i = 0; i < Size; ++i){
		int tmpI = c.back();
		tmp.push_back(tmpI);
		c.pop_back();
	}
	// 마지막 계산일 경우 저장하지 않고 Max 값만 찾음
	if (id == N - 1){
		int Ret_V = -1;
		sort(tmp.begin(), tmp.end(),greater<int>());

		for (int i = 0; i < tmp.size() && !(Ret_V != -1); ++i)
			if (tmp[i] + arr[id] <= MAX)
				Ret_V = tmp[i] + arr[id];
		
		Ret_V = Ret_V > tmp[0] - arr[id] ? Ret_V : tmp[0] - arr[id];
		return Ret_V;
	}
	//마지막 계산이 아닌 경우 
	else
		for (int i = 0; i < tmp.size(); ++i){
			if (0 <= tmp[i] + arr[id] && tmp[i] + arr[id] <= MAX){
				int j;
				for (j = 0; j < c.size() && !(c[j] == tmp[i] + arr[id]); ++j);
				if (j == c.size())
					c.push_back(tmp[i] + arr[id]);
			}
			if (0 <= tmp[i] - arr[id] && tmp[i] - arr[id] <= MAX){
				int j;
				for (j = 0; j < c.size() && !(c[j] == tmp[i] - arr[id]); ++j);
				if (j == c.size())
					c.push_back(tmp[i] - arr[id]);
			}
		}
	if (c.size() == 0)
		return -1;
	
	return Determine(id + 1, N, c, MAX);
}

int main(){
	int Case, i,Ret_V;	
	scanf("%d", &Case); 
	while(Case--){
		Container V;
		int N, VS, VM,_N;
		i = 0;
		scanf("%d",&N); 
		
		scanf("%d", &VS);
		scanf("%d", &VM);
		_N = N;
		while (_N--)
			scanf("%d", &arr[i++]);
		V.push_back(VS);
		if ((Ret_V = Determine(0,N,V,VM))>=0)
			printf("%d", Ret_V);
		else
			printf("%d",-1);
		if (Case != 0)
			printf("\n");
	}
}
