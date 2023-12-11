#include "queue.h"

void createQueue(Queue &S){
    head(S) = NULL;
    tail(S) = NULL;
}
bool isEmpty(Queue S){
    return !head(S);
}
address createElm(infotype x){
    address P = new ElmQueue;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void Enqueue(Queue &S, infotype P){
    address Q = createElm(P);
    if(isEmpty(S)){
        head(S) = Q;
        tail(S) = Q;
    }else{
        next(tail(S)) = Q;
        tail(S) = Q;
    }
}
infotype Dequeue(Queue &S){
    address P = NULL;
    if(isEmpty(S)){
        cout << "List Kosong";
    }else if(tail(S) == head(S)){
        P = head(S);
        createQueue(S);
    }else{
        P = head(S);
        head(S) = next(P);
        next(P) = NULL;
    }
    return info(P);
}
