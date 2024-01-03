#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include "DLL.h"
#include "skill.h"
struct Class{
    string name;
    string desc;
    int bonusHealth;
    int bonusAttack;
    int bonusDefense;
    int bonusSpeed;

};

typedef struct classNode *classAddress;
struct classNode{
    Class info;
    skillAddress skill;
    classAddress left;
    classAddress right;
};

typedef classAddress classTree;
typedef struct ElmCQueue *Caddress;

struct ElmCQueue{
    classTree info;
    Caddress next;
};
struct CQueue{
    Caddress head;
    Caddress tail;
};

void createCQueue(CQueue &S);
Caddress createElmC(classTree x);
bool isCEmpty(CQueue S);
void EnCqueue(CQueue &S, classTree P);
classTree DeCqueue(CQueue &S);

void createClassTree(classTree &root);
bool isClassEmpty(classTree root);
void deleteClass(classTree root, classAddress p);
classAddress createNewClassNode(Class x);
void addClass(classTree &root,classAddress p);
classAddress findClass(classTree root, string name);
int CTHeight(classTree root);
int getcol(int h);
int getClassTier(classTree root, string name);
void showClass(string prefix, classTree T, bool isLeft);
void showClassInfo(classAddress T);
void showClassByParent(classAddress T);

#endif // CLASS_H_INCLUDED
