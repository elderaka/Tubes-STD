#include "enemy.h"
void createEnemyList(enemyList &L){
    first(L) = NULL;
    last(L) = NULL;
}
bool isEnemyEmpty(enemyList L){
    return first(L) == NULL;
}
enemyAddress createNewEnemyElement(enemy x){
    enemyAddress p = new elementEnemy;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void addEnemy(enemyList &L,enemyAddress p){
    info(p).currentHealth = info(p).health;
    if (isEnemyEmpty(L)){
        first(L) = p;
        last(L) = p;
    }
    else{
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}
void deleteEnemy(enemyList &L,string name){
    enemyAddress P = findEnemy(L,name);
    if(P != NULL){
        enemyAddress prec = prev(P);
        next(prec) = next(P);
        if(next(prec) != NULL){
            prev(next(P)) = prec;
        }
        next(P) = NULL;
        prev(P) = NULL;
    }

}
enemyAddress findEnemy(enemyList L, string name){
    enemyAddress prec = first(L);
    while(prec != NULL){
        if(info(prec).name == name){
            return prec;
        }
        prec = next(prec);
    }
    return NULL;
}
void showEnemy(enemyList L){
    enemyAddress p = first(L);
    while(p != NULL){
        cout << info(p).name << " ";
        p = next(p);
    }
    cout << endl;
}
void showEnemyInfo(enemy Enemy){
}
