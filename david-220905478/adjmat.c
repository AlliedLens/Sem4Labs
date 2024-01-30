#include<stdio.h>
#include<stdlib.h>

int vertices;

void addEdge(int arr[vertices][vertices], int i, int j){
	arr[i][j] = 1;
	arr[j][i] = 1;
}

void printAdjMat(int arr[vertices][vertices]){
	int i = 0;
	int j = 0;
	printf("adjacency matrix\n");
	for (i = 0; i < vertices; i++){
		for (j = 0; j < vertices; j++){
			printf(" %d ", arr[i][j]);
		}
		printf("\n");
	}
}
void printAdjList(int adjMat[vertices][vertices]){
	printf("adjacency list\n");
	int i = 0;
	int j = 0;
	for (i = 0; i < vertices;i++){
		printf("%d : ", i);
		for (j = 0; j < vertices; j++){
			if (adjMat[i][j]>0) printf(" %d ", j);
		}
		printf("\n");
	}

}

void init(int arr[vertices][vertices]){
	int i = 0;int j =0;
	for (i=0;i<vertices;i++){
		for (j=0;j<vertices;j++){
			arr[i][j] =0;
		}
	}
}

void main(){

	printf("how many vertices: ");
	scanf("%d", &vertices);
	int adjMat[vertices][vertices];
	int vertex = 0;

	int v1 = -1;
	int v2 = -1;

	init(adjMat);

	do{
		printf("v1: ");
		scanf("%d", &v1);

		printf("v2: ");
		scanf("%d", &v2);

		addEdge(adjMat, v1, v2);

		printAdjMat(adjMat);
		printAdjList(adjMat);
	}while (v1 != -1);

}

