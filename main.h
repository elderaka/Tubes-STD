#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "player.h"
#include "object.h"
#include "skill.h"
#include "menu.h"

extern playerList PL;
extern objectList OL;
extern skillTree ST;
extern player Player;
extern object Object;
extern skill Skill;
extern playerAddress adrPlayer;
extern objectAddress adrObject;

void addObjectToPlayer(playerList &PL, objectList OL, string player,string object);
void removeObjectFromPlayer(playerList &PL, objectList &OL, string player, string name);
void deleteObject(playerList &PL, objectList &OL, string name);
void initiateObjects(objectList &OL);
void initiateSkills(skillTree &ST);
void initiateMenu();
#endif // MAIN_H_INCLUDED
