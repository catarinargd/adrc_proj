#include "main.h"

extern int nr_nodes;

int graph_connect (struct Graph* graph)
{
	BFS(graph);

	for( int i=0; i<nr_nodes-1; i++)
	{

		// Graph isn't connected
		if(graph->visited[i] == 0)
			return 0;
	}
	return 1;
}