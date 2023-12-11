#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include "DLL.h"

struct skill{
    string name;
};

//                           Heavy Strike
//                           /           \
//                   Thrust                 Parry
//                  /      \               /     \
//          Sweep          Gatling   Dominance    Aura

typedef struct elementSkill *skillAddress;

struct skillNode{
    skill info;
    skillAddress left;
    skillAddress right;
};

struct skillTree{
    skillAddress root;
};

void createSkillTree(skillList &L);
bool isSkillEmpty(skillList L);
skillAddress createNewSkillNode(skill x);
void addSkill(skillList &L,skillAddress p);
skillAddress findskill(skillList L, string name);
void showSkill(skillList L);

#endif // skill_H_INCLUDED
