#include "player.h"
//Ballz
void createPlayerList(playerList &L){
    first(L) = NULL;
    last(L) = NULL;
}
bool isPlayerEmpty(playerList L){
    return first(L) == NULL;
}
playerAddress createNewPlayerElement(player x){
    playerAddress p = new elementPlayer;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void addPlayer(playerList &L,playerAddress p){
    createInventoryList(inventory(p));
    if (isPlayerEmpty(L)){
        first(L) = p;
        last(L) = p;
    }
    else{
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}
void deletePlayer(playerList &L,string name){
    playerAddress P = findPlayer(L,name);
    if(P != NULL){
        playerAddress prec = prev(P);
        next(prec) = next(P);
        if(next(prec) != NULL){
            prev(next(P)) = prec;
        }
        next(P) = NULL;
        prev(P) = NULL;
    }

}
playerAddress findPlayer(playerList L, string name){
    playerAddress prec = first(L);
    while(prec != NULL){
        if(info(prec).name == name){
            return prec;
        }
    }
    return NULL;
}
void showPlayer(playerList L){
    playerAddress p = first(L);
    while(p != NULL){
        cout << info(p).name << " ";
        p = next(p);
    }
    cout << endl;
}
