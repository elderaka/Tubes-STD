#include "main.h"
void addObjectToPlayer(playerList &PL, objectList OL, string player,string object){
    playerAddress adrPlayer = findPlayer(PL,player);
    objectAddress adrObject = findObject(OL,object);

    if(adrPlayer != NULL && adrObject != NULL){
        inventoryAddress R = new elementInventory;
        R = createNewInventoryElement(adrObject);
        insertLastInventory(inventory(adrPlayer),R);
    }
}
void removeObjectFromPlayer(playerList &PL, string player, string name);
void deletePlayer(playerList &PL, string player);
void deleteObject(playerList &PL, objectList &OL, string name);
void initiateObjects(objectList &OL){
    createObjectList(OL);
    object Object;
    Object.name = "Stone";
    addObject(OL,createNewObjectElement(Object));
    Object.name = "Paper";
    addObject(OL,createNewObjectElement(Object));
    Object.name = "Scissor";
    addObject(OL,createNewObjectElement(Object));
    Object.name = "Lol";
    addObject(OL,createNewObjectElement(Object));
}
