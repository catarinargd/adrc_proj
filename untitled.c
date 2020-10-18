#include "main.h"


array_pos *node_vector;
int nr_nodes =1;

int main(int argc, char *argv[])
{
	read_file();
	Graph *graph = createGraph();
	//printf("-- %d\n", graph_connect(graph));

	BFS(graph);

	printf("BFS \n");
	printVector(graph);

	

/*
	-- ler o ficheiro do professor - por numa funcao
	-- ver quantos vertices existem
	-- fazer o algoritmo BFS
	-- fazer o algoritmo para verificar se e conexo

*/
}

void read_file (int argc , char **argv)
{
	
	char *fileNameIn = NULL;
	if(argc == 2)
		fileNameIn = argv[1];
	
	else 
	{
		printf("Usage: ./untitled <file.txt>\n");
        exit(-1);
	}

	char buff[255]; // 255 ou mais 
	FILE *fp;
	fp = fopen (fileNameIn, "r");

	Node* head = NULL; 
	//struct Node* tail = NULL; 
	
    
  
 /*   // allocate 3 nodes in the heap 
    head = (struct Node*)malloc(sizeof(struct Node)); 
    head->ID = 0;

    
*/
	// 1st 2nd 3nd 
	int edge_tail, edge_head, type;

	//dynamic array to save id and adjacency list
    node_vector = (array_pos*)malloc(sizeof(array_pos)*2);

    //first value read in the file corresponds to the id of an internet and it's saved in the arrat

    int vector_tail, vector_head;

	while(fgets(buff, 255, (FILE*)fp) != NULL)
	{ 
		sscanf(buff, "%d %d %d", &edge_tail, &edge_head, &type);

		//read first line of the file
		if (nr_nodes == 1)
		{
			// saves first internet node	
			node_vector[0].ID = edge_tail;
			head = (Node*)malloc(sizeof(Node)); 
    		head->ID = edge_head;
    		head->connection_type = type;
    		head->index = 1;

			node_vector[0].list = head;
			head->next = NULL;

			//increment number of nodes to know the size of the array
			nr_nodes++;
			// saves 2nd internet node
			node_vector[1].ID = edge_head;
			node_vector[1].list = NULL;
		}
		else{
			//flags to identify
			vector_tail = -1;
			vector_head = -1;

			for (int i=0; i< nr_nodes; i++){

				//if the read value (tail) is equal to another this already saved in the array
				if( node_vector[i].ID == edge_tail)
				{
					//saves new connection to list
					head = (Node*)malloc(sizeof(Node)); 
		    		head->ID = edge_head;
		    		head->connection_type = type;
		    		head->next = node_vector[i].list;

		    		node_vector[i].list = head;

		    		vector_tail = i; // value was already read , it is not necessary to insert in the array
		    	}

				//if the read value (head) is equal to another that is already saved in the array		    	
		    	else if ( node_vector[i].ID == edge_head)
		    	{
		    		vector_head = i; // value was already read, it is not necessary to insert in the array
		    	}
			}

			// read value is new
			if (vector_tail == -1)
			{
				//increment number of nodes to know the size of the array
				nr_nodes++;

				//alocate memory for the dynamic array
				node_vector = (array_pos*)realloc(node_vector, sizeof(array_pos)*nr_nodes);
				node_vector[nr_nodes-1].ID = edge_tail;

				head = (Node*)malloc(sizeof(Node)); 
	    		head->ID = edge_head;
	    		head->connection_type = type;
	    		head->index = nr_nodes;
	    		head->next = NULL;
				

				node_vector[nr_nodes-1].list = head;
			}

			
			if (vector_head == -1)
			{
				// increment number of nodes to know the size of the array
				nr_nodes++;
				//alocate memory for the dynamic array
				node_vector = (array_pos*)realloc(node_vector, sizeof(array_pos)*nr_nodes);
				node_vector[nr_nodes-1].ID = edge_head;
				node_vector[nr_nodes-1].list = NULL;
				vector_head = nr_nodes-1;
			}

			// read value already existed in the vector
			if (vector_tail != -1)
			{
				// include vector position in the list
				node_vector[vector_tail].list->index = vector_head;
			}

		}

	}

	/*
	Node* aux = NULL; 

	
	//print the array and list of adjacency
	for (int i=0; i<nr_nodes; i++)
	{
		printf("\n Node - %d --  ", node_vector[i].ID);
		aux = node_vector[i].list;
		
		while(aux!= NULL)
		{
			printf(" ID: %d, type: %d, position %d \n", aux->ID, aux->connection_type, aux->index);
			aux=aux->next;
		}

	}*/
}
