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
void showSkill(skillTree T){
    Queue Q;
    createQueue(Q);
    Enqueue(Q,T);
    while(!isEmpty(Q)){
        skillAddress N;
        N = Dequeue(Q);
        cout << info(N).name << endl;
        if(left(N)){
            Enqueue(Q,left(N));
        }
        if(right(N)){
            Enqueue(Q,right(N));
        }
    }
}
