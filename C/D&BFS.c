#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
	int items[SIZE];
	int front;
	int rear;
};

struct node {
	int vertex;
	struct node* next;
};

struct Graph {
	int numVertices;
	struct node** adjLists;
	int* visited;
};


void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);
void addEdge(struct Graph* graph, int src, int dest);
struct node* createNode(int v);
struct Graph* createGraph(int vertex_nums);
struct queue* createQueue();
struct node* createNode(int);
void bfs(struct Graph* graph, int startVertex);

struct node* createNode(int v)
{
	struct node* new = malloc(sizeof(struct node));
	new->vertex = v;
	new->next = NULL;

	return new;
}
struct queue* createQueue() {
	struct queue* q = malloc(sizeof(struct queue));
	q->front = -1;
	q->rear = -1;
	return q;
}
void enqueue(struct queue* q, int v)
{
	if(q->rear == SIZE-1)
	{
		printf("Queue is full\n");
		return;
	}
	if(q->front == -1)
	{
		q->front = 0;
	}
	q->rear++;
	q->items[q->rear] = v;
}
int isEmpty(struct queue *q)
{
	if(q->rear == -1)
		return 1;
	return 0;
}
int dequeue(struct queue *q)
{
	int index;
	index = q->front++;
	if(q->front > q->rear)
	{
		//reset
		q->front = q->rear = -1;
	}
	return q->items[index];
}
void addEdge(struct Graph* graph, int src, int des)
{
	struct node* newnode = createNode(des);
	newnode->next = graph->adjLists[src];
	graph->adjLists[src] = newnode;

	newnode = createNode(src);
	newnode->next = graph->adjLists[des];
	graph->adjLists[des] = newnode;


}
struct Graph* createGraph(int vertex_nums)
{
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertex_nums;

	graph->adjLists = malloc(vertex_nums * sizeof(struct node*));
	graph->visited = malloc(vertex_nums * vertex_nums);

	int i;
	for(i=0; i<vertex_nums; i++)
	{
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}

	return graph;
}
void bfs(struct Graph* graph, int startVertex)
{
	struct queue* q = createQueue();
	graph->visited[startVertex] = 1;
	enqueue(q, startVertex);

	while(!isEmpty(q))
	{
		int vertex = dequeue(q);
		printf("%d ->", vertex);
		struct node* nodelist = graph->adjLists[vertex];
		while(nodelist)
		{
			int adjvertex = nodelist->vertex;
			if(graph->visited[adjvertex] == 0)
			{
				enqueue(q, adjvertex);
				graph->visited[adjvertex] = 1;
			}
			nodelist = nodelist->next;
		}

	}
}
int isStackempty(struct queue *q)
{
	if(q->rear == -1)
		return 1;
	return 0;
}
void push(struct queue* q, int v)
{
	if(q->rear == SIZE-1)
	{
		printf("Stack is full\n");
		return;
	}
	if(q->front == -1)
		q->front = 0;
	q->rear++;
	q->items[q->rear] = v;
}
int pop(struct queue* q)
{
	if(isStackempty(q))
	{
		printf("Stack is empty!\n");
		return -1;
	}
	int index = q->rear;
	q->rear--;

	return q->items[index];

}

void dfs(struct Graph* graph, int startVertex)
{
	//struct queue* q =createQueue();
	struct node* temp = graph->adjLists[startVertex];
	if(graph->visited[startVertex] == 0)
	{
		printf("%d -> ", startVertex);
		graph->visited[startVertex] = 1;
	}
	while(temp)
	{
		int vertex = temp->vertex;
		if(graph->visited[vertex] == 0)
			dfs(graph, vertex);
		temp = temp->next;

	}

}

void dfs_stack(struct Graph* graph, int startVertex)
{
	struct queue* q = createQueue();
	graph->visited[startVertex] = 1;
	push(q, startVertex);

	while(!isStackempty(q))
	{
		int vertex = pop(q);
		printf("%d -> ", vertex);
		struct node* temp = graph->adjLists[vertex];

		//struct node* temp;
		

		while(temp)
		{
			if(graph->visited[temp->vertex] == 0)
				push(q, temp->vertex);
			graph->visited[temp->vertex] = 1;
			temp = temp->next;
		}
		
	}
}


int main() {
	struct Graph* graph = createGraph(7);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 5);
	addEdge(graph, 2, 6);

	dfs_stack(graph, 0);

	return 0;
}