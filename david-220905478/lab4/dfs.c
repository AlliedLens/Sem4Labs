#include"graph.h"
#include<stdio.h>
#include<stdlib.h>
int STACK_HEIGHT=1000;

int search(int* arr, int target, int n){
	int i = 0;
	for (i = 0; i < n;i++){
		if (arr[i] == target) return 1;
	}
	return 0;
}

void printArr(int* arr, int n){
	int i = 0;
	for (i=0;i< n;i++) printf(" %d ", arr[i]);
	printf("\n");
}

int DFS(Graph* g, int vertices, int target){
	int visited[1000] = {0};
	int t1 = 0;

	int explored[1000] = {};
	int t2 = -1;

	Node* temp;
	int visit;

	while (t1 >= 0){
		printf(" visit %d-> \n", visited[t1]);
		temp = g->adjLists[visited[t1]];


		t2++;
		explored[t2] = visited[t1];

		t1--;


		printf("visited: ");
		printArr(visited, t1+1);

		printf("explored: ");
		printArr(explored, t2+1);

		printf("-----\n");

		if (temp->vertex == target) return 1;

		while (temp!=NULL){
			visit = temp->vertex;
			if (search(explored, visit, t2+1)==0 && search(visited, visit, t1+1)==0){
				t1++;
				visited[t1] = visit;
			}
			temp = temp->next;
		}

	}

	return 0;
}


void main(){
	Graph* g = createGraph(5);
	addEdge(g, 0,2);
	addEdge(g,0,1);
	addEdge(g,0,3);
	addEdge(g,2,3);
	addEdge(g,2,1);

	// printGraph(g);
	printf("%d", DFS(g,5, 3));

}