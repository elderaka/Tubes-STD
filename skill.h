#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include "DLL.h"
struct skill{
    int id;
    string name;
    string desc;
    string type; //offensive, deffensive, support
    int cost[2];
    string costStat[2];
    int dmg;
    int heal;
    int buff[2];
    int duration; //semisal buff overtime
    bool isMultiple;
};
typedef struct skillNode *skillAddress;
struct skillNode{
    skill info;
    skillAddress left;
    skillAddress right;
};
typedef struct elementSkill *sListAddress;
struct elementSkill{
    skillAddress skill;
    sListAddress next;
    sListAddress prev;

};
struct skillList{
    sListAddress first;
    sListAddress last;

};

typedef skillAddress skillTree;
#include "queue.h"
void createSkillTree(skillTree &root);
bool isSkillEmpty(skillTree root);
skillAddress createNewSkillNode(skill x);
void addSkill(skillTree &root,skillAddress p);
skillAddress findskill(skillTree root, string name);
int STHeight(skillTree root);
void deleteSkill(skillTree root, int id);
int getcol(int h);
void showSkillTree(string prefix, skillTree root, bool isLeft);
void showSkillByParent(skillAddress T);

void createSkillList(skillList &L);
sListAddress createNewSkillElement(skillAddress x);
void insertLastSkill(skillList &L, sListAddress p);
void removeSkill(skillList &SL,skillTree ST,string name);
sListAddress findSkillinPlayer(int id,skillList L);
void showSkill(skillList L);

#endif // skill_H_INCLUDED
