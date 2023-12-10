#include "object.h"

void createObjectList(objectList &L){
    first(L) = NULL;
    last(L) = NULL;
}
bool isObjectEmpty(objectList L){
    return first(L) == NULL;
}
objectAddress createNewObjectElement(object x){
    objectAddress p = new elementObject;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void addObject(objectList &L,objectAddress p){
    if (isObjectEmpty(L)){
        first(L) = p;
        last(L) = p;
    }
    else{
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

objectAddress findObject(objectList L, string name){
    objectAddress prec = first(L);
    while(prec != NULL){
        if(info(prec).name == name){
            return prec;
        }
        prec = next(prec);
    }
    return NULL;

}
void showObject(objectList L){
    objectAddress p = first(L);
    while(p != NULL){
        cout << info(p).name << " ";
        p = next(p);
    }
    cout << endl;
}
