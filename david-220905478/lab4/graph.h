#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int vertex;
	struct Node* next;
}Node;

typedef struct Graph{
	int vertices;
	Node** adjLists;
}Graph;

Node* createNode(int v){
	Node* nn = (Node*)malloc(sizeof(Node));
	nn->next = NULL;
	nn->vertex = v;
	return nn;
}

Graph* createGraph(int vertices){
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertices = vertices;

	graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));

	int i;

	for (i = 0; i < vertices;i++){
		graph->adjLists[i] = NULL;
	}

	return graph;
}

void addEdge(Graph* g, int s, int d){
	Node* nn = createNode(d);
	nn->next = g->adjLists[s];
	g->adjLists[s] = nn;

	nn = createNode(s);
	nn->next = g->adjLists[d];
	g->adjLists[d] = nn;
}

void printGraph(Graph* g){
	int i;
	for (i = 0; i < g->vertices;i++){
		printf(" %d:  ", i);
		Node* temp = g->adjLists[i];
		while (temp != NULL){
			printf(" %d ->", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}