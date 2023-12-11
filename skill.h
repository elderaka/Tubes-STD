#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include "DLL.h"

struct skill{
    int id;
    string name;
    string desc;
    string type; //offensive, deffensive, support
    int cost;
    int dmg;
    int heal;
    int buff;
    int duration; //semisal buff overtime
    bool isMultiple;

};
/*
                           Heavy Strike
                           /           \
                   Thrust                 Parry
                  /      \               /     \
          Sweep          Gatling   Dominance    Aura
*/
typedef struct skillNode *skillAddress;

struct skillNode{
    skill info;
    skillAddress left;
    skillAddress right;
};

typedef skillAddress skillTree;
#include "queue.h"
void createSkillTree(skillTree &root);
bool isSkillEmpty(skillTree root);
skillAddress createNewSkillNode(skill x);
void addSkill(skillTree &root,skillAddress p);
skillAddress findskill(skillTree root, string name);
int STHeight(skillTree root);
int getcol(int h);
void showSkill(skillTree root);

#endif // skill_H_INCLUDED
