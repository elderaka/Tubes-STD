#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "player.h"
#include "object.h"
#include "skill.h"

void addObjectToPlayer(playerList &PL, objectList OL, string player,string object);
void removeObjectFromPlayer(playerList &PL, objectList &OL, string player, string name);
void deleteObject(playerList &PL, objectList &OL, string name);
void initiateObjects(objectList &OL);
void initiateSkills(skillTree &ST);
#endif // MAIN_H_INCLUDED
