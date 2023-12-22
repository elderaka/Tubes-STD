#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "player.h"
#include "object.h"
#include "skill.h"
#include "Class.h"
#include "menu.h"
extern playerList PL;
extern objectList OL;
extern skillTree ST;
extern classTree CT;
extern player Player;
extern object Object;
extern skill Skill;
extern Class cls;
extern playerAddress adrPlayer;
extern objectAddress adrObject;
extern menuStack Menu;
extern int choice;


void addObjectToPlayer(playerList &PL, objectList OL, string player,string object);
void removeObjectFromPlayer(playerList &PL, objectList &OL, string player, string name);
void deleteObject(playerList &PL, objectList &OL, string name);
void addSkillToPlayer(playerList &PL, skillTree ST, string player, string skill);
void removeSkillFromPlayer(playerList &PL, skillList &SL, string player, string skill);
void changePlayerClass(string player, string Class);
void initiateObjects(objectList &OL);
void initiateSkillAndClass(skillTree &ST, classTree &CT);
void initiatePlayer(playerList &PL);
void initiateMenu();
#endif // MAIN_H_INCLUDED
