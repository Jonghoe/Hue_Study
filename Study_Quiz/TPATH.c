#include<stdio.h>
#include<stdlib.h>
#define MALLOC() &HEAP_EDGE[(I++)%8000]
typedef struct tag_Node Node;
typedef struct tag_Edge Edge;
typedef struct tag_Graph Graph;
struct tag_Edge{
	Node* Start, *End;
	Edge* Next;
	int Velocity;
};
struct tag_Node{
	int Index;
	int Min, Max;
	Edge* e;
};
struct tag_Graph{
	Node node[2000];
};
Graph graph;
int N, M, I;
Edge* HEAP_EDGE;
int Input_Num(int Start,int End){
	int Ret_V;
	do{
		scanf("%d", &Ret_V);
	} while (!(Start <= Ret_V&&Ret_V <= End));
	return Ret_V;
}
void Set_Edge( Node* A, Node*B, int C){
	Edge* AtoB = MALLOC();
	AtoB->Start = A;
	AtoB->End = B;
	AtoB->Velocity = C;
	AtoB->Next = NULL;
	if (A->e == NULL)
		A->e = AtoB;
	else{
		AtoB->Next = A->e;
		A->e = AtoB;
	}
}

int Compare_Node(Edge* Now){
	int Ret_V = 0;
	int Max, Min;
	Max = Now->Start->Max > Now->Velocity ? Now->Start->Max : Now->Velocity;
	Min = Now->Start->Min < Now->Velocity ? Now->Start->Min : Now->Velocity;
	if ((Now->End->Max - Now->End->Min) > Max - Min){
		Now->End->Max = Max;
		Now->End->Min = Min;
		Ret_V = 1;
	}
	return Ret_V;
}
int Calculate_MAXMIN(){
	int Case,Max,Min;
	Edge* F_N = graph.node[0].e;
	Edge* Tmp = F_N;
	for (; Tmp != 0; Tmp = Tmp->Next)
		Tmp->End->Min = Tmp->End->Max = Tmp->Velocity;
	
	do{
		int Top = 0;
		Edge *Stack[4000];
		Stack[Top++] = F_N;
		while (Top != 0){
			Edge* Now = Stack[--Top]->End->e;
			for (; Now != 0 && Now->Velocity != 0; Now= Now->Next)
				if (Now->End != &graph.node[0]){
					if (Compare_Node(Now))
						Stack[Top++] = Now;
				}
		}
	} while (F_N = F_N->Next);
	return graph.node[N - 1].Max - graph.node[N - 1].Min;
}

void Set_Node(){
	int i = 0;
	for (; i < N; i++){
		graph.node[i].Index = i;
		graph.node[i].Max = 1000;
		graph.node[i].Min = 0;
	}
}
int main(){
	int Case;
	HEAP_EDGE = (Edge*)malloc(sizeof(Edge) * 8000);
	Case = Input_Num(0, 50);
	while (Case--){
		int A,B,C;
		N = Input_Num(0, 2000);
		M = Input_Num(0, 4000);
		Set_Node();
		while (M--){
			Edge* Tmp = (Edge*)malloc(sizeof(Edge));
			A = Input_Num(0, N);
			B = Input_Num(0, N);
			C = Input_Num(0, 1000);
			Set_Edge(&graph.node[A], &graph.node[B], C);
			Set_Edge(&graph.node[B], &graph.node[A], C);
		}
		printf("%d\n", Calculate_MAXMIN());
	}
}