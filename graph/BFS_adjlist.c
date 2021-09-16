#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_VERTEX_NUM 100
#define MAX_QUEUE_SIZE 20

typedef struct node{
   int vertex;
   struct node * next;
}Node;
typedef struct {
   int vertexNum;
   Node* adjList[MAX_VERTEX_NUM];
} Graph;
int visited[MAX_VERTEX_NUM];

typedef int element;
typedef struct {
   int front;
   int rear;
   element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message)
{
   fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType* q)
{
   q->rear = 0;
   q->front = 0;
}

int is_full(QueueType* q)
{
   return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

int is_empty(QueueType* q)
{
   return (q->front == q->rear);
}

void enqueue(QueueType* q, element item)
{
   if (is_full(q))
   {
      error("Queue is full.");
      return;
   }
   q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
   q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
   if (is_empty(q))
   {
      error("Queue is empty.");
      return -1;
   }
   q->front = (q->front + 1) % MAX_QUEUE_SIZE;
   return q->data[q->front];
}

void BFS_List(Graph* g, int s) {
   Node* p;

   QueueType q;
   init_queue(&q);
   for (int i = 1; i <= g->vertexNum; i++)
      visited[i] = 0;

   visited[s] = 1;
   printf("%d ", s);
   enqueue(&q, s);
   while (!is_empty(&q))
   {
      int u = dequeue(&q);
      for( p = g->adjList[u]; p!= NULL;p = p->next)
      {
         if(visited[p->vertex] == 0)
         {
            visited[p->vertex] = 1;
            printf("%d ", p->vertex);
            enqueue(&q, p->vertex);
         }
      }
   }
}

Graph* NewGraph(int vNum) {
   Graph* graph = (Graph*)malloc(sizeof(Graph));
   graph->vertexNum = vNum;
   for(int i = 0;i<= vNum;i++)
      graph->adjList[i] = NULL;
   return graph;
}

void AddEdge(Graph *g, int start, int end)
{
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode->vertex = end;
   newNode->next = g->adjList[start];
   g->adjList[start] = newNode;

   newNode = (Node *)malloc(sizeof(Node));
   newNode->vertex = start;
   newNode->next = g->adjList[end];
   g->adjList[end] = newNode;
}

void printGraph(Graph *graph)
{
   Node *p;
   for (int i = 1; i <= graph->vertexNum; i++)
   {
      p = graph->adjList[i];
      printf("%d: ", i);
      while (p != NULL)
      {
         printf("%d ", p->vertex);
         p = p->next;
      }
      printf("\n");
   }
}

int main() {
   Graph* g = NewGraph(8);
   AddEdge(g, 1, 2);
   AddEdge(g, 1, 3);
   AddEdge(g, 2, 4);
   AddEdge(g, 2, 5);
   AddEdge(g, 3, 5);
   AddEdge(g, 3, 7);
   AddEdge(g, 3, 8);
   AddEdge(g, 4, 5);
   AddEdge(g, 5, 6);
   AddEdge(g, 7, 8);
   printGraph(g);
   printf("\nBFS: ");
   BFS_List(g, 1);
}
