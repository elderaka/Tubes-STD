#include "fight.h"

FQueue fqueue;
void createFQueue(FQueue &S){
    head(S) = NULL;
    tail(S) = NULL;
    S.Size = 0;
}
bool isFEmpty(FQueue S){
    return !head(S);
}
Faddress createFElm(entity x){
    Faddress P = new ElmFQueue;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void EnFQueue(FQueue &S, entity P){
    Faddress Q = createFElm(P);
    if(isFEmpty(S)){
        head(S) = Q;
        tail(S) = Q;
    }else{
        next(tail(S)) = Q;
        tail(S) = Q;
    }
    S.Size++;
}
entity DeFQueue(FQueue &S){
    Faddress P = NULL;
    if(isFEmpty(S)){
        cout << "List Kosong";
    }else if(tail(S) == head(S)){
        P = head(S);
        createFQueue(S);
    }else{
        P = head(S);
        head(S) = next(P);
        next(P) = NULL;
        S.Size--;
    }

    return info(P);
}

void showFQueue(FQueue &S){
    Faddress p = head(S);
    cout << "[Turn Queue: ";
    while(p != NULL){
        if(info(p).isPlayer){
            cout <<info(p).Player.name;
        }else{
            cout <<info(p).Enemy.name;
        }
        if(next(p) != NULL){
            cout  << ", ";
        }
        p = next(p);
    }
    cout << "]" << endl;
}


void createEntityList(entityList &L){
    first(L) = NULL;
    last(L) = NULL;
}
bool isEntityEmpty(entityList L){
    return first(L) == NULL;
}

entityAddress createNewEntityElement(entity x){
    entityAddress p = new elementEntity;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void addEntity(entityList &L,entityAddress p){
    if (isEntityEmpty(L)){
        first(L) = p;
        last(L) = p;
    }
    else{
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

entityAddress findEntity(entityList L, string name){
    entityAddress prec = first(L);

    while(prec != NULL){
        //if(info(prec).name == name){
//
  //          return prec;
    //    }
        prec = next(prec);
    }
    return NULL;

}
void showEntity(entityList L){
    entityAddress p = first(L);
    int i = 1;
    while(p != NULL){
        if(info(p).isPlayer){
            cout << i << "." <<info(p).Player.name << endl;
        }else{
            cout << i << "." <<info(p).Enemy.name << endl;
        }
        p = next(p);
        i++;
    }
    cout << endl;
}

void initiateFight(FQueue &S,entityList &eL,enemy enemies[]){
    createEntityList(eL);
    createFQueue(S);
    entity Entity;
    Entity.Player = info(mc(PL));
    Entity.isPlayer = true;
    Entity.actionValue = 0;
    addEntity(eL,createNewEntityElement(Entity));
    for(int i = 0; i < sizeof(enemies)-1;i++){
        Entity.no = i;
        Entity.isPlayer = false;
        Entity.actionValue = 0;
        Entity.Enemy = enemies[i];
        addEntity(eL,createNewEntityElement(Entity));
    }

    while(S.Size < 5){
        entityAddress P = first(eL);
        while(P != NULL){
            if(info(P).isPlayer){
                info(P).actionValue += info(P).Player.speed*multiplier(80,125);
            }else{
                info(P).actionValue += info(P).Enemy.speed*multiplier(75,125);
            }
            if(info(P).actionValue >= 100){
                info(P).actionValue -= 100;
                EnFQueue(S,info(P));
            }
            P = next(P);
        }
    }

}

entity reFQueue(FQueue &S, entityList eL){
    showFQueue(S);
    entity E = DeFQueue(S);
    if(E.isPlayer){
        cout << E.Player.name<< "'s turn.\n";
    }else{
        cout << E.Enemy.name << "'s turn.\n";
    }
    while(S.Size < 5){
        entityAddress P = first(eL);
        while(P != NULL){
            if(info(P).isPlayer){
                info(P).actionValue += info(P).Player.speed*multiplier(80,125);
            }else{
                info(P).actionValue += info(P).Enemy.speed*multiplier(75,125);
            }
            if(info(P).actionValue >= 100){
                info(P).actionValue -= 100;
                EnFQueue(S,info(P));
                break;
            }
            P = next(P);
        }
    }
    return E;
}
