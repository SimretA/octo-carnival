#include <stdio.h>
#include <stdlib.h>

// Define maximum number of vertices in the graph
#define N 6

// Data structure to store graph
struct Graph {
	//adjacency list
	struct Node* head[N];
};


struct Node {
	int dest;
	struct Node* next;
};


struct Edge {
	int src, dest;
};


struct Graph* createGraph(struct Edge edges[], int n)
{
	unsigned i;

	// allocate memory for graph data structure
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

	// initialize head pointer for all vertices
	for (i = 0; i < N; i++)
		graph->head[i] = NULL;

	// add edges to the directed graph one by one
	for (i = 0; i < n; i++)
	{
		// get source and destination vertex
		int src = edges[i].src;
		int dest = edges[i].dest;

		// allocate new node of Adjacency List from src to dest
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->dest = dest;

		// point new node to current head
		newNode->next = graph->head[src];

		// point head pointer to new node
		graph->head[src] = newNode;
	}

	return graph;
}


void printGraph(struct Graph* graph)
{
	int i;
	for (i = 0; i < N; i++)
	{
		// print current vertex and all ts neighbors
		struct Node* ptr = graph->head[i];
		while (ptr != NULL)
		{
			printf("(%d -> %d)\t", i, ptr->dest);
			ptr = ptr->next;
		}

		printf("\n");
	}
}

void printBFS(struct Graph * graph){
    printf("Hello");
    struct Node** queue = (struct Node**)malloc( N * sizeof(struct Node));
    struct Node* ptr = graph->head[0];
    *queue = ptr;
    int count = 0;
    while (count<N && (*queue+count)->dest)
    {
        printf("%d -> %d",(*queue+count)->dest,(*queue+count)->next->dest);
        count += 1;
        *(queue + count) = graph->head[count];

    }
    
    if(count>N){
        printf("ERROR: Out of space\n");
    }

    
    
}

int main(void)
{

	struct Edge edges[] =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// calculate number of edges
	int n = sizeof(edges)/sizeof(edges[0]);

	// construct graph from given edges
	struct Graph *graph = createGraph(edges, n);

	// print adjacency list representation of graph
	printBFS(graph);
    printGraph(graph);

	return 0;
}