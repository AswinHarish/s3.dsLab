
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
    GraphNode **adjLists;
} Graph;

typedef struct Queue
{
    int items[100];
    int front;
    int rear;
} Queue;

Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void BFS(Graph *graph, int startVertex);
GraphNode *createNode(int v);
Queue *createQueue();
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int isEmpty(Queue *q);

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

    printf("Breadth First Search starting from vertex 2:\n");
    BFS(graph, 2);

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

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
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

Queue *createQueue()
{
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == 99)
        printf("\nQueue is full\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}

int isEmpty(Queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void BFS(Graph *graph, int startVertex)
{
    Queue *queue = createQueue();

    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex);

        GraphNode *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;

            if (visited[adjVertex] == 0)
            {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

