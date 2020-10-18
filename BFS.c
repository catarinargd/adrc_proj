#include "main.h"

extern array_pos *node_vector;
extern int nr_nodes;

Graph* createGraph()
{
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	if(graph==NULL)
		exit(0);

	graph->V=nr_nodes;
	graph->node_vector = node_vector;

	graph->visited = (int*) malloc(sizeof(int)*nr_nodes);

	

	return graph;
}


void BFS(Graph *graph)
{
	for(int i=0; i<nr_nodes; i++)
		graph->visited[i] = 0;

	graph->visited[0] = 1;
	Queue* q =createQueue();

	// First node 
	enqueue(q,0);
	int current_node;
	

	while(q->rear != -1)
	{ 
		//printQueue(q);
		current_node = dequeue(q);
		Node *aux = graph->node_vector[current_node].list;

		while(aux != NULL)
		{
			if (graph->visited[aux->index] == 0)
			{
				enqueue(q, aux->index);
				graph->visited[aux->index] = 1;
			}
			aux = aux->next;
		}
	}
}


// Create a queue
Queue* createQueue() {
  Queue* q = malloc(sizeof(Queue));
  q->items = (int*)malloc(sizeof(int)*nr_nodes);
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(Queue* q, int value) {

	if (q->rear == nr_nodes - 1)
		printf("\nQueue is Full!!");
  	else {
	    if (q->front == -1){
	    	q->front = 0;
	    }
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(Queue* q) {
  	int item;
  	if (isEmpty(q)) {
    //printf("Queue is empty");
    item = -1;
  	}
  	else 
  	{
	    item = q->items[q->front];
	    q->front++;
	    if (q->front > q->rear) 
	    {
	      	//printf("Resetting queue ");
	      	q->front = q->rear = -1;
    }
  }
  return item;
}


// Print the queue
void printQueue(Queue* q) {
  	int i = q->front;

  	if (isEmpty(q)) {
    	printf("Queue is empty");
  	} 
  	else 
  	{
    	printf("\nQueue contains \n");
	    for (i = q->front; i < q->rear + 1; i++) 
	    {
	      	printf("%d ", q->items[i]);
	    }
  	}
}

void printVector(Graph *graph)
{
	printf("vector: ");
	for (int i=0; i<nr_nodes; i++)
		printf("%d  ",graph->visited[i]);
}
