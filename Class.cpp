#include "Class.h"

void createCQueue(CQueue &S){
    head(S) = NULL;
    tail(S) = NULL;
}
Caddress createElmC(classTree x){
    Caddress P = new ElmCQueue;
    info(P) = x;
    next(P) = NULL;
    return P;
}
bool isCEmpty(CQueue S){
    return !head(S);
}
void EnCqueue(CQueue &S, classTree P){
    Caddress Q = createElmC(P);
    if(isCEmpty(S)){
        head(S) = Q;
        tail(S) = Q;
    }else{
        next(tail(S)) = Q;
        tail(S) = Q;
    }
}
classTree DeCqueue(CQueue &S){
    Caddress P = NULL;
    if(isCEmpty(S)){
        cout << "List Kosong";
    }else if(tail(S) == head(S)){
        P = head(S);
        createCQueue(S);
    }else{
        P = head(S);
        head(S) = next(P);
        next(P) = NULL;
    }
    return info(P);
}

void createClassTree(classTree &root){
    root = NULL;
}
bool isClassEmpty(classTree root){
    return root == NULL;
}
classAddress createNewClassNode(Class x){
    classAddress p = new classNode;
    info(p) = x;
    left(p) = NULL;
    right(p) = NULL;
    return p;
}
int getClassTier(classTree root, string name){
    CQueue Q;
    createCQueue(Q);
    EnCqueue(Q,root);
    int i = 1;
    while(!isCEmpty(Q)){
        classAddress N;
        N = DeCqueue(Q);
        i++;
        if(info(N).name == name){
            return floor(log2(i))+1;
        }
        if(left(N)){
            EnCqueue(Q,left(N));
        }
        if(right(N)){
            EnCqueue(Q,right(N));
        }
    }
    return 1;
}
void addClass(classTree &root,classAddress p){
    if(root == NULL){
        root = p;
    }else{
        CQueue Q;
        createCQueue(Q);
        EnCqueue(Q,root);
        while(!isCEmpty(Q)){
            classAddress temp = DeCqueue(Q);
            if(left(temp) != NULL){
                EnCqueue(Q,left(temp));
            }else{
                left(temp) = p;
                break;
            }
            if(right(temp) != NULL){
                EnCqueue(Q, right(temp));
            }else{
                right(temp) = p;
                break;
            }
        }
    }
}
classAddress findClass(classTree root, string name){
    CQueue Q;
    createCQueue(Q);
    EnCqueue(Q,root);
    while(!isCEmpty(Q)){
        classAddress N;
        N = DeCqueue(Q);
        if(info(N).name == name){
            return N;
        }
        if(left(N)){
            EnCqueue(Q,left(N));
        }
        if(right(N)){
            EnCqueue(Q,right(N));
        }
    }
    return NULL;
}
void showClass(string prefix,classTree T, bool isLeft){
    if(T != NULL){
        cout << prefix;

        cout << (isLeft ? "|--" : "|__" );
        cout << info(T).name << endl;
        showClass(prefix + (isLeft ? "|    " : "     "), left(T), true);
        showClass(prefix + (isLeft ? "|    " : "     "), right(T), false);
    }
}

void showClassInfo(classAddress T){
    Class lefts = info(T);
    cout << setw(30) << left << "==========================="<< endl;
    cout << setw(30) << left << "Class: " + lefts.name<< endl;
    cout << setw(30) << left << lefts.desc                   << endl;
    cout << setw(30) << left << "Attack: +" + to_string(lefts.bonusAttack)    << endl;
    cout << setw(30) << left << "Defense: +" + to_string(lefts.bonusDefense)  << endl;
    cout << setw(30) << left << "Speed: +" + to_string(lefts.bonusSpeed)      << endl;
    cout << setw(30) << left << "Health: +" + to_string(lefts.bonusHealth)    << endl;
    cout << setw(30) << left << "Class Skill:"      << endl;
    cout << setw(30) << left << info(skill(T)).name << endl;
    cout << setw(30) << left << "===========================" << endl;
}
void showClassByParent(classAddress T){
    Class lefts = info(left(T));
    Class rights = info(right(T));
    cout << setw(30) << left << "==========================="               << "|" << "==========================="               << endl;
    cout << setw(30) << left << "       Class: " + lefts.name                 << "|" << "       Class: " + rights.name                 << endl;
    cout << setw(30) << left << "==========================="               << "|" << "==========================="               << endl;
    cout << setw(30) << left << lefts.desc                                    << "|" << rights.desc                                    << endl;
    cout << setw(30) << left << "Attack: +" + to_string(lefts.bonusAttack)    << "|" << "Attack: +" + to_string(rights.bonusAttack)    << endl;
    cout << setw(30) << left << "Defense: +" + to_string(lefts.bonusDefense)  << "|" << "Defense: +" + to_string(rights.bonusDefense)  << endl;
    cout << setw(30) << left << "Speed: +" + to_string(lefts.bonusSpeed)      << "|" << "Speed: +" + to_string(rights.bonusSpeed)      << endl;
    cout << setw(30) << left << "Health: +" + to_string(lefts.bonusHealth)    << "|" << "Health: +" + to_string(rights.bonusHealth)    << endl;
    cout << setw(30) << left << "Class Skill:"                              << "|" << "Class Skill:"                              << endl;
    cout << setw(30) << left << info(skill(left(T))).name                         << "|" << info(skill(right(T))).name                         << endl;
}
