#include "main.h"

extern array_pos *node_vector;
extern int nr_nodes, time = 0;


// d-> node discovery time
// l-> oldest ancestor discovery (...)
int d[nr_nodes], l[nr_nodes];

// DFS initialization
void init_DFS(Graph *graph)
{
	for(int i=0; i<nr_nodes; i++)
		graph->visited[i] = 0;
	DFS(graph, 0);
}

void DFS(Graph *graph, int current_node)
{
	graph->visited[current_node] = 1;

	time = time + 1;
	d[current_node] = time;
	l[current_node] =  time;

	Node *aux = graph->node_vector[current_node].list;

	printf(" batata %d,  visited %d   \n", current_node+1, graph->visited[current_node]);

	while(aux != NULL)
	{
		current_node = aux->index;

		if(graph->visited[current_node] == 0)
		{
			DFS(graph, current_node);
		}

		aux = aux->next;
		if(graph->visited[current_node] == 1)
		{
			
		}

	}
}