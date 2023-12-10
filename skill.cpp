#include "skill.h"

void createSkillList(skillList &L){
    first(L) = NULL;
    last(L) = NULL;
}
bool isSkillEmpty(skillList L){
    return first(L) == NULL;
}
skillAddress createNewSkillElement(skill x){
    skillAddress p = new elementSkill;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void addSkill(skillList &L,skillAddress p){
    if (isSkillEmpty(L)){
        first(L) = p;
        last(L) = p;
    }
    else{
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}
skillAddress findskill(skillList L, string name){
    skillAddress prec = first(L);
    while(prec != NULL){
        if(info(prec).name == name){
            return prec;
        }
    }
    return NULL;
}
void showSkill(skillList L){
    skillAddress p = first(L);
    while(p != NULL){
        cout << info(p).name << " ";
        p = next(p);
    }
    cout << endl;
}
