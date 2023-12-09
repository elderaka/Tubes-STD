#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "DLL.h"
struct player{
    string name;
    int health; //100
    int Stamina; //50
    int defaultAttack; // 25
    int defaultDef; //25
  // att dan def bs ditambah am equipment


};

struct skill{
	string name;
	integer id;
	integer damage;
	integer heal;
	integer buffs;
}

struct Item {
    string nameItem;
    int jumlahItem;
    // Informasi item lainnya

};

struct Location {
    string name;
// point ke tempat mana aja 
    Location* nextLocation;
    Character* inLocation;
    Encounter *placeEncounter;



};
struct Inventory {
    int gold;
    
    //point ke item mw ditambah;


    // Pointer ke karakter yang memiliki item ini
    Character* owner;
};
typedef player infotype;
typedef struct elementPlayer *playerAddress;

struct elementPlayer{
    infotype info;
    playerAddress prev;
    playerAddress next;

};

struct playerList{
    address first;
    address last;
};

void createPlayerList(List &L);
bool isPlayerEmpty(List L);
address createNewPlayerElement(infotype x);
void insertFirstPlayer(List &L,address p);
void insertAfterPlayer(List &L,address prec, address p);
void insertLastPlayer(List &L,address p);
void deleteFirstPlayer(List &L,address p);
void deleteAfterPlayer(List &L,address prec,address p);
void deleteLastPlayer(List &L,address p);
address findLagu_1301223115(string judul,List L);
void removeLagu_1301223115(string judul,List &L);
void show_1301223115(List L);
void swapDescending(List &L);


#endif // PLAYER_H_INCLUDED
