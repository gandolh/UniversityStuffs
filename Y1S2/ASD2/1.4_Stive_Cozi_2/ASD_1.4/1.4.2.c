#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

typedef struct queue {
    int* arr;
    int head, tail;
    int limit, nrElem;
} Queue;

Queue create_queue(int limit) {
    Queue q;
    q.arr = malloc(sizeof(int) * limit);
    q.head = 0;
    q.tail = 0;
    q.limit = limit - 1;
    q.nrElem = 0;
    return q;
}

void enqueue(Queue* q, int x) {
    if (q->nrElem <= q->limit) {
        q->arr[q->tail % q->limit] = x;
        q->tail++;
    }
    q->nrElem++;
}
int dequeue(Queue* q) {
    //q->arr[q->head] = 0;
    q->head++;
    q->nrElem--;
}
void print(Queue* q) {
    if (q->nrElem >= q->limit)
        printf("Limit exceeded\n");
    for (int i = q->head; i < q->tail; i++)
        printf("%d\n", q->arr[i % q->limit]);
}

int main() {
    Queue q = create_queue(5);
    int x, i;

    scanf("%d", &x);
    while (x > 0) {
        scanf("%d", &i);
        enqueue(&q, i);
        x--;
    }
    dequeue(&q);
    dequeue(&q);
    print(&q);
}