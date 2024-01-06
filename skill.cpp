#include "skill.h"
void createSkillTree(skillTree &root){
    root = NULL;
}
bool isSkillEmpty(skillTree root){
    return root == NULL;
}
skillAddress createNewSkillNode(skill x){
    skillAddress p = new skillNode;
    info(p) = x;
    left(p) = NULL;
    right(p) = NULL;
    return p;
}
void addSkill(skillTree &root,skillAddress p){
    if(root == NULL){
        root = p;
    }else{
        Queue Q;
        createQueue(Q);
        Enqueue(Q,root);
        while(!isEmpty(Q)){
            skillAddress temp = Dequeue(Q);
            if(left(temp) != NULL){
                Enqueue(Q,left(temp));
            }else{
                left(temp) = p;
                break;
            }
            if(right(temp) != NULL){
                Enqueue(Q, right(temp));
            }else{
                right(temp) = p;

                break;
            }
        }
    }
}
skillAddress findskill(skillTree root, string name){
    Queue Q;
    createQueue(Q);
    Enqueue(Q,root);
    while(!isEmpty(Q)){
        skillAddress N;
        N = Dequeue(Q);
        if(info(N).name == name){
            return N;
        }
        if(left(N)){
            Enqueue(Q,left(N));
        }
        if(right(N)){
            Enqueue(Q,right(N));
        }
    }
    return NULL;
}
void showSkillTree(string prefix, skillTree root, bool isLeft){
    if(root != NULL){
        cout << prefix;
        cout << (isLeft ? "|--" : "|__" );
        cout << info(root).name << endl;
        showSkillTree(prefix + (isLeft ? "|   " : "    "), left(root), true);
        showSkillTree(prefix + (isLeft ? "|   " : "    "), right(root), false);
    }
}
void showSkillByParent(skillAddress T){
    cout << "1."<<info(left(T)).name << endl;
    cout << "2."<<info(right(T)).name << endl;
}

void createSkillList(skillList &L){
    first(L) = NULL;
    last(L) = NULL;
}
sListAddress createNewSkillElement(skillAddress x){
    sListAddress p = new elementSkill;
    skill(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void insertLastSkill(skillList &L, sListAddress p){
    if (first(L) == NULL) {
        first(L) = p;
        last(L) = p;
    } else {
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}
void removeSkill(skillList &SL,skillTree ST,string name){
    skillAddress P = findskill(ST,name);
    sListAddress Q = first(SL);
    while(Q != NULL && skill(Q) != P){
        Q = next(Q);
    }
    if(Q != NULL){
        sListAddress prec = prev(Q);
        next(prec) = next(Q);
        if(next(prec) != NULL){
            prev(next(Q)) = prec;
        }
        next(Q) = NULL;
        prev(Q) = NULL;
    }else{
        cout << "Skill not found" << endl;
    }
}
sListAddress findSkillinPlayer(int id,skillList L){
    sListAddress prec = first(L);
    while (prec != NULL) {
        if (info(skill(prec)).id == id) {
            return prec;
        }
        prec = next(prec);
    }
    return NULL;
}
void showSkill(skillList L){
    sListAddress p = L.first;
    while (p != NULL) {
        cout << info(skill(p)).id << ". " <<info(skill(p)).name<< " "<< info(skill(p)).desc << " " << info(skill(p)).type << endl;
        string aoe;
        aoe = info(skill(p)).isMultiple ? "Area of Effect" : "Single Target";
        cout << aoe << endl;
        string type;
        type = info(skill(p)).type == "Offensive" ? "Deals " + to_string(info(skill(p)).dmg) + " damage" : "damage " + to_string(info(skill(p)).heal) + " Heals\n";
        cout << type << endl;
        p = next(p);
    }
}
