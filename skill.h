#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED
#include "DLL.h"

struct skill{
    string name;
};
typedef struct elementSkill *skillAddress;

struct elementSkill{
    skill info;
    skillAddress prev;
    skillAddress next;
};

struct skillList{
    skillAddress first;
    skillAddress last;
};

void createSkillList(skillList &L);
bool isSkillEmpty(skillList L);
skillAddress createNewSkillElement(skill x);
void addSkill(skillList &L,skillAddress p);
skillAddress findskill(skillList L, string name);
void showSkill(skillList L);

#endif // skill_H_INCLUDED
