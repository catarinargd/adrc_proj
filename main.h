#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40

// A linked list node 
typedef struct Node { 
    int ID;
    int connection_type; 
    int index;
    struct Node* next; 
} Node; 
// suport structure for the array of adjacency list
typedef struct array_pos{
	int ID;
	struct Node* list;
} array_pos;


typedef struct Graph{
	int V;
	array_pos *node_vector;
	int *visited;
}Graph;

void read_file ();

//connect.c
int graph_connect(Graph* graph);

// BFS.c
Graph* createGraph();
void BFS(Graph *graph);
void printVector(Graph *graph);



// Queue - BFS.c

typedef struct Queue{
	int rear;
	int front;
	int *items;
}Queue;

Queue* createQueue();
int isEmpty(Queue* q); // Nao usamos
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void printQueue(Queue* q);





// DFS.c
void init_DFS(Graph *graph);
void DFS(Graph *graph, int Node);