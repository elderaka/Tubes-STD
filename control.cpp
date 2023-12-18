#include "main.h"
playerList PL;
objectList OL;
skillTree ST;
classTree CT;
player Player;
object Object;
skill Skill;
Class cls;
playerAddress adrPlayer;
objectAddress adrObject;

void addObjectToPlayer(playerList &PL, objectList OL, string player,string object){

    adrPlayer = findPlayer(PL,player);
    adrObject = findObject(OL,object);
    cout << info(adrObject).name;
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
void addSkillToPlayer(playerList &PL, skillTree ST, string player, string skill){
    playerAddress adrPlayer = findPlayer(PL,player);
    skillAddress adrSkill = findskill(ST,skill);

    if(adrPlayer != NULL && adrSkill != NULL){
        sListAddress R = new elementSkill;
        R = createNewSkillElement(adrSkill);
        insertLastSkill(skill(adrPlayer),R);
    }
}
void removeSkillFromPlayer(playerList &PL, skillList &SL, string player, string skill){
    playerAddress adrPlayer = findPlayer(PL,player);
    if(adrPlayer != NULL){
        skillList ski = skill(adrPlayer);
        removeSkill(ski,ST,skill);
    }else{
        cout << "Player not found" << endl;
    }
}
void changePlayerClass(string player, string Class){
    playerAddress adrPlayer = findPlayer(PL,player);
    classAddress adrClass = findClass(CT,Class);

    if(adrPlayer != NULL && adrClass != NULL){
        Class(adrPlayer) = adrClass;
        addSkillToPlayer(PL,ST,player,info(skill(adrClass)).name);
        info(adrPlayer).Class = info(adrClass).name;
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
}
void initiateSkillAndClass(skillTree &ST, classTree &CT){
    createSkillTree(ST);
    createClassTree(CT);
    skill Skill;
    Class cls;
    skillAddress adrSkill;
    classAddress adrClass;
    Skill.name = "Battle Roar";
    cls.name = "Newbie";
    cls.desc = "Normal fighter";
    cls.bonusAttack = 5;
    cls.bonusDefense = 3;
    cls.bonusSpeed = 2;
    cls.bonusHealth = 20;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


    cls.name = "Fighter";
    cls.desc = "Normal Fighter";
    cls.bonusAttack = 7;
    cls.bonusDefense = 4;
    cls.bonusSpeed = 4;
    cls.bonusHealth = 15;
    Skill.name = "Piercing Strike";
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);

    cls.name = "Knight";
    cls.desc = "Normal Knight";
    cls.bonusAttack = 6;
    cls.bonusDefense = 5;
    cls.bonusSpeed = 3;
    cls.bonusHealth = 20;
    Skill.name = "Nicha Attack";
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);

}
void initiatePlayer(playerList &PL){
    createPlayerList(PL);
    Player.name = "Mike";
    Player.Class = "Newbie";
    Player.defaultAttack = 10;
    Player.defaultDefence = 10;
    Player.health = 20;
    Player.speed = 10;
    Player.stamina = 10;
    Player.xp = 0;
    Player.level = 1;
    Player.nextLevel = 10;
    adrPlayer = createNewPlayerElement(Player);
    addPlayer(PL,adrPlayer);
    changePlayerClass(Player.name,"Newbie");



}
void initiateMenu(){
    mainmenu();
    introduction();
}
