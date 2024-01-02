#include "player.h"
#include "main.h"
void createPlayerList(playerList &L){
    first(L) = NULL;
    last(L) = NULL;
}
bool isPlayerEmpty(playerList L){
    return first(L) == NULL;
}
playerAddress createNewPlayerElement(player x){
    playerAddress p = new elementPlayer;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void addPlayer(playerList &L,playerAddress p){
    createInventoryList(inventory(p));
    createSkillList(skill(p));
    insertLastSkill(skill(p),createNewSkillElement(ST));
    if (isPlayerEmpty(L)){
        first(L) = p;
        last(L) = p;
    }
    else{

        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;

    }
}
void deletePlayer(playerList &L,string name){
    playerAddress P = findPlayer(L,name);

    if(P != NULL){
        playerAddress prec = prev(P);
        if(P == first(L)){
            first(L) = next(P);
        }else if (P == last(L)){
            last(L) = prev(P);
        }else{
            next(prec) = next(P);
            if(next(prec) != NULL){
                prev(next(P)) = prec;
            }
            next(P) = NULL;
            prev(P) = NULL;
        }


    }

}
playerAddress findPlayer(playerList L, string name){
    playerAddress prec = first(L);
    while(prec != NULL){
        if(info(prec).name == name){
            return prec;
        }
        prec = next(prec);
    }
    return NULL;
}
void showPlayer(playerList L){
    playerAddress p = first(L);
    while(p != NULL){
        cout << info(p).name << " ";
        p = next(p);
    }
    cout << endl;
}

int nextLevel(player Player){
    return floor(4*(pow(Player.level,3))/5);
}
void levelUp(player &Player){
    int bonusStat = 2*getClassTier(CT,Player.Class);
    cout << "Tier Up!" << endl;
    cout << "Sekarang kamu level " << Player.level + 1 << endl;
    cout << "Exp berikutnya: " << nextLevel(Player) << endl;
    cout << "Pilih Tier baru kamu (1-2): " <<endl;
    showClassByParent(findClass(CT,Player.Class));
    int choice;
    do{
        cin >> choice;
        cout << "Pilihan salah. Pilih Tier baru kamu (1-2): "
    }while(choice > 2 || choice < 1)
    cout << "Pilih Defense Skill kamu (1-2): " <<endl;

    while(bonusStat > 0){
        cout << "Pilih Status yang ingin kamu tambahkan" << endl;
        cout << "(Kamu mendapatkan tambahan setengah poin sesuai dengan Class kamu)" << endl;
        cout << "Health: "<< Player.health;
    }
}
void showPlayerInfo(player Player){
    cout << "==============================" << endl;
    cout << "===== Player Information =====" << endl;
    cout << "==============================" << endl;
    cout << "Name: " << Player.name << endl;
    cout << "Class: " << Player.Class << endl;
    cout << info(findClass(CT, Player.Class)).desc << endl;
    cout << "Health: " << Player.currentHealth << "/"<< Player.health<<endl;
    cout << "Stamina: " << Player.currentStamina <<"/" << Player.stamina << endl;

    cout << "Attack: " << Player.defaultAttack << "(+" << info(findClass(CT, Player.Class)).bonusAttack << ")" <<endl;
    cout << "Defense: " << Player.defaultDefence << "(+" << info(findClass(CT, Player.Class)).bonusDefense << ")" << endl;
    cout << "Speed: " << Player.speed << "(+" << info(findClass(CT, Player.Class)).bonusSpeed << ")" << endl;
    cout << "Level: " << Player.level << endl;
    cout << "Coin: " << Player.coin << endl;
    cout << "Experience Points: " << Player.exp << endl;
    cout << "Next Level at: " << Player.nextLevel << " XP" << endl;
}
