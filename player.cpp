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
    createSkillList(offensive(p));
    createSkillList(defensive(p));
    insertLastSkill(offensive(p),createNewSkillElement(ST));
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

int addGold(playerAddress Player, int gold){
	return findObjectinInventory(inventory(mc(PL)),"Boon of Boons") != NULL ? gold * 1.15 : gold;
}

int addExp(playerAddress Player, int exp){
	return findObjectinInventory(inventory(mc(PL)),"Boon of Boons") != NULL ? exp * 1.15 : exp;
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
void tierUp(player &Player){
    cout << "Tier Up!" << endl;
    cout << "Sekarang kamu Tier " << Player.level + 1 << endl;
    cout << "Exp berikutnya: " << nextLevel(Player) << endl;
    cout << "Pilih Tier baru kamu (1-2): " <<endl;
    showClassByParent(findClass(CT,Player.Class));
    int choice;
    do{
        cin >> choice;
        if(choice == 1){
            changePlayerClass(MC.name,info(left(findClass(CT,MC.Class))).name);
        }else if(choice == 2){
            changePlayerClass(MC.name,info(right(findClass(CT,MC.Class))).name);
        }else{
            cout << "Pilihan salah. Pilih Tier baru kamu (1-2): ";
        }
    }while(choice > 2 || choice < 1);

    cout << "Pilih Defense Skill kamu (1-2): " <<endl;
    //WHAT THE FUCK IS THIS
    //Damn my bad G
    showSkillByParent(skill(last(defensive(mc(PL)))));
    do{
        cin >> choice;
        if(choice == 1){
            addSkillToPlayer(PL,ST,MC.name,info(left(findskill(ST,info(skill(last(defensive(mc(PL))))).name))).name );
        }else if(choice == 2){
            addSkillToPlayer(PL,ST,MC.name,info(right(findskill(ST,info(skill(last(defensive(mc(PL))))).name))).name );
        }else{
            cout << "Pilihan salah. Pilih Defense Skill baru kamu (1-2): ";
        }
    }while(choice > 2 || choice < 1);
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
    cout << "Tier: " << Player.level << endl;
    cout << "Coin: " << Player.coin << endl;
    cout << "Experience Points: " << Player.exp << endl;
    cout << "Next Tier at: " << Player.nextLevel << " XP" << endl;
}
