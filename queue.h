#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "DLL.h"
#include "skill.h"
typedef skillTree infotype;
typedef struct ElmQueue *address;

struct ElmQueue{
    infotype info;
    address next;
};
struct Queue{
    address head;
    address tail;
};
void createQueue(Queue &S);
address createElm(infotype x);
bool isEmpty(Queue S);
void Enqueue(Queue &S, infotype x);
infotype Dequeue(Queue &S);


#endif // QUEUE_H_INCLUDED
