#include "main.h"
playerList PL;
objectList OL;
skillTree ST;
player Player;
object Object;
skill Skill;
playerAddress adrPlayer;
objectAddress adrObject;

void addObjectToPlayer(playerList &PL, objectList OL, string player,string object){
    playerAddress adrPlayer = findPlayer(PL,player);
    objectAddress adrObject = findObject(OL,object);

    if(adrPlayer != NULL && adrObject != NULL){
        inventoryAddress R = new elementInventory;
        R = createNewInventoryElement(adrObject);
        insertLastInventory(inventory(adrPlayer),R);
    }
}
void removeObjectFromPlayer(playerList &PL,objectList &OL, string player, string name){
    playerAddress adrPlayer = findPlayer(PL,player);
    if(adrPlayer != NULL){
        inventoryList inv = inventory(adrPlayer);
        removeObject(inv,OL,name);
    }else{
        cout << "Player not found" << endl;
    }
}
void deleteObject(playerList &PL, objectList &OL, string name){
    playerAddress P = first(PL);
    while(P != NULL){
        removeObject(inventory(P),OL, name);
    }
    objectAddress Q = findObject(OL,name);
    if(Q != NULL){
        objectAddress prec = prev(Q);
        next(prec) = next(Q);
        if(next(prec) != NULL){
            prev(next(Q)) = prec;
        }
        next(Q) = NULL;
        prev(Q) = NULL;
    }

}
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
void initiateSkills(skillTree &ST){
    createSkillTree(ST);
    skill Skill;
    Skill.name = "Slash";
    addSkill(ST,createNewSkillNode(Skill));
    Skill.name = "Bash";
    addSkill(ST,createNewSkillNode(Skill));
    Skill.name = "Suck";
    addSkill(ST,createNewSkillNode(Skill));

}
void initiateMenu(){
    mainmenu();
    introduction();
}
