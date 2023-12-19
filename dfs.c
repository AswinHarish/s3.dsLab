#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode
{
    int vertex;
    struct GraphNode *next;
} GraphNode;

typedef struct Graph
{
    int numVertices;
    int *visited;
    GraphNode **adjLists;
} Graph;

Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void DFS(Graph *graph, int vertex);
GraphNode *createNode(int v);

int main()
{
    int numVertices = 5;
    Graph *graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("Depth First Search starting from vertex 2:\n");
    DFS(graph, 2);

    return 0;
}

GraphNode *createNode(int v)
{
    GraphNode *newNode = (GraphNode *) malloc(sizeof(GraphNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (GraphNode **) malloc(vertices * sizeof(GraphNode *));
    graph->visited = (int *) malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    GraphNode *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(Graph *graph, int vertex)
{
    GraphNode *adjList = graph->adjLists[vertex];
    GraphNode *temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

