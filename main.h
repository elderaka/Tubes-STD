#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "player.h"
#include "object.h"
#include "skill.h"
#include "Class.h"
#include "menu.h"
#include "dice.h"
#include "enemy.h"
#include "fight.h"
extern playerList PL;
extern objectList OL;
extern enemyList EL;
extern skillTree ST;
extern classTree CT;
extern entityList eL;
extern enemyList EL;
extern player Player;
extern object Object;
extern skill Skill;
extern Class cls;
extern enemy Enemy;
extern playerAddress adrPlayer;
extern objectAddress adrObject;
extern menuStack Menu;

extern int choice;
extern int position[2];
extern string path;


void addObjectToPlayer(playerList &PL, objectList OL, string player,string object);
void removeObjectFromPlayer(playerList &PL, objectList &OL, string player, string name);
void deleteObject(playerList &PL, objectList &OL, string name);
inventoryAddress findObjectinInventory(string name);
void addSkillToPlayer(playerList &PL, skillTree ST, string player, string skill);
void removeSkillFromPlayer(playerList &PL, skillList &SL, string player, string skill);
void changePlayerClass(string pl, string Class);
void initiateObjects(objectList &OL);
void initiateSkillAndClass(skillTree &ST, classTree &CT);
void initiatePlayer(playerList &PL);
void initiateEnemy(enemyList &EL);
void initiateMenu();
#endif // MAIN_H_INCLUDED
