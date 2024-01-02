#include "main.h"
#include "player.h"
playerList PL;
objectList OL;
skillTree ST;
classTree CT;
entityList eL;
enemyList EL;
player Player;
object Object;
skill Skill;
Class cls;
enemy Enemy;
playerAddress adrPlayer;
objectAddress adrObject;
menuStack Menu;
int position[2] = {0,0};
int choice;
string path;

void addObjectToPlayer(playerList &PL, objectList OL, string player,string object){

    adrPlayer = findPlayer(PL,player);
    cout << info(adrPlayer).name;
    adrObject = findObject(OL,object);
    cout << info(adrObject).name;
    if(adrPlayer != NULL && adrObject != NULL){
        inventoryAddress R = new elementInventory;
        R = createNewInventoryElement(adrObject);
        insertLastInventory(inventory(adrPlayer),R);
    }
}
void removeObjectFromPlayer(playerList &PL,objectList &OL, string player, string name){
    playerAddress adrPlayer = findPlayer(PL,player);
    if(adrPlayer != NULL){
        inventoryList inv = inventory(adrPlayer);
        removeObject(inv,OL,name);
    }else{
        cout << "Player not found" << endl;
    }
}

inventoryAddress findObjectinInventory(inventoryList L, string name){
    //Who's fucking ideas it is to use mc(PL) instead of the playerAddress
    //Edit: oh ya, it's my past self
    inventoryAddress prec = first(L);
    while(prec != NULL){
        if(info(object(prec)).name == name){
            return prec;
        }
        prec = next(prec);
    }
    return NULL;
}
void addSkillToPlayer(playerList &PL, skillTree ST, string player, string skill){
    playerAddress adrPlayer = findPlayer(PL,player);
    skillAddress adrSkill = findskill(ST,skill);

    if(adrPlayer != NULL && adrSkill != NULL){
        sListAddress R = new elementSkill;
        R = createNewSkillElement(adrSkill);
        if(info(adrSkill).id < 13){
            insertLastSkill(offensive(adrPlayer),R);
        }else{
            insertLastSkill(defensive(adrPlayer),R);

        }

    }
}
void removeSkillFromPlayer(playerList &PL, skillList &SL, string player, string skill){
    playerAddress adrPlayer = findPlayer(PL,player);
    skillAddress adrSkill = findskill(ST,skill);
    if(adrPlayer != NULL){
        skillList ski;
        if(info(adrSkill).id < 13){
            ski = offensive(adrPlayer);
        }else{
            ski = defensive(adrPlayer);

        }
        removeSkill(ski,ST,skill);
    }
}
void changePlayerClass(string pl, string Class){
    playerAddress adrPlayer = findPlayer(PL, pl);

    classAddress adrClass = findClass(CT,Class);
    if(adrPlayer != NULL && adrClass != NULL){
        Class(adrPlayer) = adrClass;
        addSkillToPlayer(PL,ST,pl,info(skill(adrClass)).name);
        info(adrPlayer).Class           = info(adrClass).name;
        info(adrPlayer).stamina         += getClassTier(CT,Class) * 5 + 20;
        info(adrPlayer).currentStamina  = info(adrPlayer).stamina;
        info(adrPlayer).defaultAttack   += info(adrClass).bonusAttack;
        info(adrPlayer).defaultDefence  += info(adrClass).bonusDefense;
        info(adrPlayer).speed           += info(adrClass).bonusSpeed;
        info(adrPlayer).health          += info(adrClass).bonusHealth;
        info(adrPlayer).currentHealth   = info(adrPlayer).health;
    }

}
void deleteObject(playerList &PL, objectList &OL, string name){
    playerAddress P = first(PL);
    while(P != NULL){
        removeObject(inventory(P),OL, name);
        P = next(P);
    }
    objectAddress Q = findObject(OL,name);
    if(Q != NULL){
        objectAddress prec = prev(Q);
        if(Q == first(OL)){
            first(OL) = next(Q);
        }else if (Q == last(OL)){
            last(OL) = prev(Q);
        }else{
            next(prec) = next(Q);
            if(next(prec) != NULL){
                prev(next(Q)) = prec;
            }
            next(Q) = NULL;
            prev(Q) = NULL;
        }
    }

}
void initiateObjects(objectList &OL){
    createObjectList(OL);
     //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    //Equipable (Artifacts)

    Object.name = "Ring of Senicianus";
    Object.desc = "[-30%] health throughout the game, [+30%] Stamina. \n It was apparently stolen by a person named Senicianus, there's an engraving of which says 'Ash nazg durbatulûk, ash nazg gimbatul, Ash nazg thrakatulûk, agh burzum-ishi krimpatul.'";
    Object.isArtefact = true;
    Object.isConsumable = false;
    Object.isEquipable = false;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "health";
    Object.bonusStat[1] = "stamina";
    Object.bonus[0] = {-30};
    Object.bonus[1] = {30};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "[Fissured] Ring of Senicianus";
    Object.desc = "[+30%] health throughout the game, [+30%] Stamina. \n It was apparently stolen by a person named Senicianus,there's an engraving of which says 'One ring to rule them all, one ring to find them, One ring to bring them all and in the darkness bind them.', upon whom Silvianus called down a curse until it is returned to the temple of Nodens.";
    Object.isArtefact = true;
    Object.isConsumable = false;
    Object.isEquipable = false;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "health";
    Object.bonusStat[1] = "stamina";
    Object.bonus[0] = {30};
    Object.bonus[1] = {30};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Disciple's Dewy Feather Garb";
    Object.desc = "[+30%] health, [-10%] defence, [-20%] attack. \n A feather garb made according to old scrolls. Its owner was either __e__n___r___il__d______ in the pages of history or a sa___r of hum__i_y. The rest of the  words on the scroll becomes more faded.";
    Object.isArtefact = true;
    Object.isConsumable = false;
    Object.isEquipable = false;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "health";
    Object.bonusStat[1] = "defence";
    Object.bonusStat[2] = "attack";
    Object.bonus[0] = {30};
    Object.bonus[1] = {-20};
    Object.bonus[2] = {-10};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "[Fissured]Disciple's Dewy Feather Garb";
    Object.desc = "[+30%] health, [+10%] defence, [+20%] attack . \n Its owner was either a demon reviled in the pages of history or a savior of humanity. The rest of the  words on the scroll becomes more faded.";
    Object.isArtefact = true;
    Object.isConsumable = false;
    Object.isEquipable = false;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "health";
    Object.bonusStat[1] = "defence";
    Object.bonusStat[2] = "attack";
    Object.bonus[0] = {30};
    Object.bonus[1] = {20};
    Object.bonus[2] = {10};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Bloodstained Flower of Iron";
    Object.desc = "[+30%] Attack, [-15%] Health,  [-15%] Stamina. \n 'For a knight, chivalry is its own reward. This flower shall be my medal. That is all I need.'";
    Object.isArtefact = true;
    Object.isConsumable = false;
    Object.isEquipable = false;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "health";
    Object.bonusStat[1] = "stamina";
    Object.bonusStat[2] = "attack";
    Object.bonus[0] = {-15};
    Object.bonus[1] = {-15};
    Object.bonus[2] = {30};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

        Object.name = "[Fissured] Bloodstained Flower of Iron";
    Object.desc = "[-30%] health throughout the game, [+30%] Stamina. \n 'For a knight, chivalry is its own reward. This flower shall be my medal. That is all I need.' , said the  Bloodstained Knight that could no longer tell whether the blood that stained him was his own or that of his enemies.";
    Object.isArtefact = true;
    Object.isConsumable = false;
    Object.isEquipable = false;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "health";
    Object.bonusStat[1] = "stamina";
    Object.bonusStat[2] = "attack";
    Object.bonus[0] = {15};
    Object.bonus[1] = {15};
    Object.bonus[2] = {30};
    Object.heal = 0;
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//Usable
    object Object;
    Object.name = "Provision";
    Object.desc = "[1/3 heal]. \nLong lasting food, great for long travels.";
    Object.isArtefact = false;
    Object.isConsumable = true;
    Object.isEquipable = false;
    Object.armorType = "";
    Object.buff = 0;
    Object.buffStat = "";
    Object.duration = 0;
    Object.heal = 0.3 * MC.health;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Health Potion";
    Object.desc = "[2/3 heal]. \nA regular and reliable health potion, trusted by many travelers alike.";
    Object.isArtefact = false;
    Object.isConsumable = true;
    Object.isEquipable = false;
    Object.armorType = "";
    Object.buff = 0;
    Object.buffStat = "";
    Object.heal = 0.6 * MC.health;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "L. Health Potion";
    Object.desc = "[MAX heal]. \nNot all traveler can carry this thing inside their pouch.";
    Object.isArtefact = false;
    Object.isConsumable = true;
    Object.isEquipable = false;
    Object.armorType = "";
    Object.buff = 0;
    Object.buffStat = "";
    Object.heal = 1 * MC.health;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Attack Potion";
    Object.desc = "[1/2 attack buff for 2 turns]. \n Makes you feel like you could crack a melanite ore with your bare fist";
    Object.isArtefact = false;
    Object.isConsumable = true;
    Object.isEquipable = false;
    Object.armorType = "";
    Object.buff = 0.5 * MC.defaultAttack ;
    Object.buffStat = "attack";
    Object.heal = 0;
    Object.duration = 3;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Defence Potion";
    Object.desc = "[1/2 def buff for 2 turns]. \n Do NOT actually compare your skin for a rock";
    Object.isArtefact = false;
    Object.isConsumable = true;
    Object.isEquipable = false;
    Object.armorType = "";
    Object.buff = 0.5 * MC.defaultDefence;
    Object.buffStat = "defence";
    Object.heal = 0;
    Object.duration = 3;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Speed Potion";
    Object.desc = "[1/2 spd buff for 2 turns]. \n Your body feels like it's light, as if the wind fleets you";
    Object.isArtefact = false;
    Object.isConsumable = true;
    Object.isEquipable = false;
    Object.armorType = "";
    Object.buff = 0.5 * MC.speed;
    Object.buffStat = "speed";
    Object.heal = 0;
    Object.duration = 3;
    addObject(OL,createNewObjectElement(Object));

    //A Manual scroll from distant lands [Upgrade to the next class of their choosing + skills, 120 gold piece]

    Object.name = "Enchiridion";
    Object.desc = "[2500 xp]. \n Upgrade to the next class of their choosing + skills";
    Object.isArtefact = false;
    Object.isConsumable = true;
    Object.isEquipable = false;
    Object.armorType = "";
    Object.buff = 2500;
    Object.buffStat = "exp";
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    //Equipable (Swords)

    Object.name = "Basic Iron Sword";
    Object.desc = "[+5 Attack]. \n The blade is made from a solid piece of well-forged iron, boasting a straight, double-edged design that is easy to maintain and versatile in battle.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "sword";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "attack";
    Object.bonus[0] = 5;
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Sword of Phantasmal Flames";
    Object.desc = "[+20 Attack]. \n Forged in the ethereal forges of spectral artisans and bathed in the elusive fires of the netherworld, transcends the boundaries between the physical and the otherworldly. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "sword";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "attack";
    Object.bonus[0] = 20;
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Scarlet";
    Object.desc = "[+25 Attack, 5 bleed dmg per turn]. \n Used to be owned by a Hero in a distant lands. The blade is dented, chipped, and dirty. Its hilt is black with some worn leather grip-straps and a red gemstone in the pommel.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "sword";
    Object.buff = 5;
    Object.buffStat = "bleed";
    Object.bonusStat[0] = "attack";
    Object.bonus[0] = 25;
    Object.heal = 0;
    Object.duration = 2;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Terraforge Claymore";
    Object.desc = "[+20 Attack, 15 health]. \n A formidable weapon designed for those who wish to channel the power of the earth in their strikes.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "sword";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"attack"};
    Object.bonusStat[1] = {"health"};
    Object.bonus[0] = 20;
    Object.bonus[1] = 15;
    Object.heal = 0;
    Object.duration = 2;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Grass Sword";
    Object.desc = "[+25 Attack, +3 Leech Effect]. \n  A cursed the sword so it will bond itself to its owner for eternity. Can quickly carve object into various objects with extreme precision. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "sword"; //leech mirip vampiric, kita dmg, dpt heal
    Object.buff = 3;
    Object.buffStat = "leech";
    Object.bonusStat[0] = "attack";
    Object.bonus[0] = 25;
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));



    Object.name = "Night Sword";
    Object.desc = "[+30 Attack]. \n The blade is crafted from a rare, darkened steel that seems to absorb and swallow light, giving it an obsidian-like appearance.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "sword";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "attack";
    Object.bonus[0] = {30};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Devilsknife";
    Object.desc = "[+50 Attack]. \n Skull-emblazoned scythe-ax.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "sword";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"attack"};
    Object.bonus[0] = {50};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Jevilstail";
    Object.desc = "[+25 Attack, +25 Speed]. \n  A hardened J-Shaped tail that gives you devilenergy.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "sword";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "attack";
    Object.bonusStat[1] = "speed";
    Object.bonus[0] = 25; // for "attack"
    Object.bonus[1] = 25; // for "speed"
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    //Equipable (helmet)
    Object.name = "Basic Helm";
    Object.desc = "[+5 Health]. \n The helm is constructed from durable iron, providing a solid layer of protection for the wearer's head. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "helmet";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"health"};
    Object.bonus[0] = {5};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Helm of Clairvoyant Insight";
    Object.desc = "[+20 Health]. \n The helm's shimmering design, adorned with arcane symbols imbued with magic. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "helmet";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0]= {"health"};
    Object.bonus[0] = {20};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Lead Splunking Helmet";
    Object.desc = "[+15 Defence, +10 Attack]. \n Once used by a lead miner, worshiper of Qlipoth ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "helmet";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "defence";
    Object.bonusStat[1] = "attack";

    Object.bonus[0] = 15; // for "defence"
    Object.bonus[1] = 10; // for "attack"

    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Jester's delight";
    Object.desc = "[+15 Speed, +5% Crit Chance]. \n  The vibrant multicolored fabric covering the helmet is adorned with tiny bells that jingle with every movement, with a mischievous touch and a flair for the theatrical, ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "helmet";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "speed";
    Object.bonusStat[1] = "critChance";
    Object.bonus[0] = 15;
    Object.bonus[1] = 1;
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));


    Object.name = "Gambler's Top Hat";
    Object.desc = "[- 10 Defence, +30 Attack]. \n Fashioned for those who navigate the unpredictable currents of chance and luck. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "helmet";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = "defence";
    Object.bonusStat[1] = "attack";
    Object.bonus[0] = -10;
    Object.bonus[1] = 30;
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Regal Specter Crown";
    Object.desc = "[+20 Defence, +25 Attack]. \n Crafted from ethereal essence and shadowy opulence, this crown is both a symbol of regal authority and a testament to the spectral legacy of the undead monarch.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "helmet";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"defence"};
    Object.bonusStat[1] = {"attack"};
    Object.bonus[0] = {20};
    Object.bonus[1] = {25};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    //Equipable (Chestplate)
    Object.name = "Basic Chestplate";
    Object.desc = "[+5 Defence]. \n The chestplate is constructed from a combination of reinforced leather and hardened metal plates, providing a solid defense against both edged weapons and blunt force.  ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "chestplate";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"defence"};
    Object.bonus[0] = {5};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Spectral's Cloak";
    Object.desc = "[+20 Defence]. \n Woven from the spectral threads, a garment that shrouds its wearer in an enigmatic aura. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "chestplate";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"defence"};
    Object.bonus[0] = {20};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Hunter's Garb";
    Object.desc = "[+15 Defence, +5 Speed]. \n Woven from the spectral threads, a garment that shrouds its wearer in an enigmatic aura ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "chestplate";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"defence"};
    Object.bonusStat[1] = {"speed"};
    Object.bonus[0] = {15};
    Object.bonus[1] = {5};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Runic Chestplate";
    Object.desc = "[+10 Defence, +15 health]. \n Forged in the arcane fires of ancient craftsmanship, the Runic Chestplate is a majestic piece of armor that bears the mystic symbols of forgotten realms.  ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "chestplate";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"defence"};
    Object.bonusStat[1] = {"health"};
    Object.bonus[0] = {10};
    Object.bonus[1] = {15};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Jim Hall's Chestplate";
    Object.desc = "[+ 5 Attack, +20 health]. \n Though worn and weathered, carries an undeniable aura of craftsmanship that transcends its battered appearance.  ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "chestplate";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"attack"};
    Object.bonusStat[1] = {"health"};
    Object.bonus[0] = {5};
    Object.bonus[1] = {20};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));


    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    //Equipable (Legplates)

    Object.name = "Basic Legplate";
    Object.desc = "[+ 5 Speed]. \n The legguards are constructed from toughened leather and reinforced with metal plating around the shins and knees. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "legplates";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"speed"};
    Object.bonus[0] = {5};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Sticky Silk Legplate";
    Object.desc = "[+ 10 Speed, +10 health]. \n The legging's surface is adorned with an iridescent sheen, reflecting a subtle play of colors reminiscent of a spider's delicate web.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "legplates";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"speed"};
    Object.bonusStat[1] = {"health"};
    Object.bonus[0] = {10};
    Object.bonus[1] = {10};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Ringmaster's Pants";
    Object.desc = "[+ 10 Speed, +10 Attack]. \n The pants are made from a durable yet flexible fabric, designed to withstand the acrobatics and lively movements of the circus ring.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "legplates";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"speed"};
    Object.bonusStat[1] = {"health"};
    Object.bonus[0] = {10};
    Object.bonus[1] = {10};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Legplates of Ethereal Stride";
    Object.desc = "[+ 17 Speed]. \n As the wearer dons the it, they experience a subtle weightlessness, as if they are walking on the very fabric of dreams. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "legplates";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"speed"};
    Object.bonus[0] = {17};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Titanium Legplates";
    Object.desc = "[+ 25 Defence]. \n These legplates offer unparalleled protection , making them a coveted choice for warriors who value defense on the battlefield. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "legplates";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"defence"};
    Object.bonus[0] = {25};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Beastskin Legging";
    Object.desc = "[+ 15 Defence, +10 Speed]. \n The legguards are crafted from a combination of thick beast hides and reinforced leather, providing a robust defense against the rigors of the wild.  ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "legplates";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"defence"};
    Object.bonusStat[1] = {"speed"};
    Object.bonus[0] = {15};
    Object.bonus[1] = {10};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

        //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    //Equipable (Charms)
    Object.name = "Amber Ring";
    Object.desc = "[+ 15 Defence]. \n Forged under the watchful gaze of an Amber Lord, the Ring of Qlipoth is a sacred artifact infused with the essence of primal energies and the blessings of ancient deities.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"defence"};
    Object.bonus[0] = {15};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Entropic Die";
    Object.desc = "[+ 15 Speed, +10 Attack]. \n The Entropic Die is a six-sided die, each face marked with arcane symbols representing the chaotic forces that govern the unraveling of destinies.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"speed"};
    Object.bonusStat[1] = {"attack"};
    Object.bonus[0] = {15};
    Object.bonus[1] = {10};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Ring of Attunement";
    Object.desc = "[+10 Defence, +10 Health,+ 10 Speed, +10 Attack]. \nThe ring features a circular band made from a material that seems to shift in color, reflecting the ever-changing essence of the elements. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"speed"};
    Object.bonusStat[1] = {"attack"};
    Object.bonusStat[2] = {"health"};
    Object.bonusStat[3] = {"defence"};
    Object.bonus[0] = {10};
    Object.bonus[1] = {10};
    Object.bonus[2] = {10};
    Object.bonus[3] = {10};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Amulet of Lifespring";
    Object.desc = "[+ Heal 20% for 2 turns at every battle]. \n The amulet features a delicate pendan from a luminescent crystal, Encased within the crystal is a tiny, verdant leaf, a symbol of growth and renewal. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "health";
    Object.bonusStat[0] = {""};
    Object.bonus[0] = {0};
    Object.heal = 0.2 ; //heal 2 turns awal battle
    Object.duration = 2;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Tonic of Efficacious Chaos";
    Object.desc = "[+ 20 attack]. \n  Tonic of Efficacious Chaos imparts a temporary surge of unpredictable effects, both beneficial and capricious.  ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"attack"};
    Object.bonus[0] = {20};
    Object.heal =0 ;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));


    Object.name = "Boon of Boons";
    Object.desc = "[+ 15% gold piece and + 15% xp bonus from battle]. \n  Greed manifests as a crystalline amulet suspended from a delicate chain. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm"; //tbh w kg tw cara apply gmn, jd w blm apa2in
    Object.buff = 0.15;
    Object.buffStat = "attack";
    Object.bonusStat[1] = {""};
    Object.bonus[1] = {0};
    Object.heal = 0;
    Object.duration = 2;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "'Good Value'";
    Object.desc = "[+ 15 Health]. \n  A charm with an exquisite display of understated elegance and unparalleled sarcasm.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"health"};
    Object.bonus[0] = {15};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Bloodied Necklace";
    Object.desc = "[+ 40% attack , - 30 health]. \n   This enigmatic necklace is said to harbor glimpses of the past, present, and the untold tapestry of the future, all stained with the essence of the bearer's own blood.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0.4;
    Object.buffStat = "attack";
    Object.bonusStat[0] = {"health"};
    Object.bonusStat[0] = {"attack"};
    Object.bonus[0] = {-30};
    Object.bonus[0] = {40};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Trickster Gloves";
    Object.desc = "[+ 15 Speed]. \n   Suited for those who revel in clever deception and swift, cunning maneuvers, these gloves carry an air of playful unpredictability.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"speed"};
    Object.bonus[0] = {15};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Yin Amulet";
    Object.desc = "[+ 10 Attack, + 5 Health]. \n Sought after by those who seek to align themselves with the tranquil forces of Yin, finding peace in the delicate interplay of opposites.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0.4 *MC.defaultAttack;
    Object.buffStat = "";
    Object.bonusStat[0] = {"attack"};
    Object.bonusStat[1] = {"health"};
    Object.bonus[0] = {10};
    Object.bonus[1] = {5};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Yang Amulet";
    Object.desc = "[+ 10 Health, + 5 Attack]. \n   Sought after by those who seek to align themselves with the tranquil forces of Yang,fiery energy that invigorates the wearer with the force of the sun.";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"health"};
    Object.bonusStat[1] = {"attack"};
    Object.bonus[0] = {10};
    Object.bonus[1] = {5};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Ring of Tempting Tune";
    Object.desc = " [+ 10% Crit Chance]. \n   The Ring is a bewitching trinket that harbors the captivating power of the sea's most alluring tunes. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"critChance"};
    Object.bonus[0] = {2};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));

    Object.name = "Living Bone";
    Object.desc = "[+ 15% Crit Chance]. \n   This necklace is a testament to the enduring resilience of bone transformed into an instrument of life. ";
    Object.isArtefact = false;
    Object.isConsumable = false;
    Object.isEquipable = true;
    Object.armorType = "charm";
    Object.buff = 0;
    Object.buffStat = "";
    Object.bonusStat[0] = {"critChance"};
    Object.bonus[0] = {3};
    Object.heal = 0;
    Object.duration = 0;
    addObject(OL,createNewObjectElement(Object));




}
void initiateSkillAndClass(skillTree &ST, classTree &CT){
    //TODO: CHANGE THE FUCKIN THINGS INTO BST, WHAT ARE THE SKILL ID USED FOR IF WE DON"T USE IT

    createSkillTree(ST);
    createClassTree(CT);
    skill Skill;
    Class cls;
    skillAddress adrSkill;
    classAddress adrClass;
    //Awalan Tier 0
    cls.name = "Newbie";
    cls.desc = "Can't climb up if you don't know where to start";
    Skill.name = "Battle Rage";
    Skill.id = 1;
    Skill.desc = "Scream out on top of your lungs and swing voraciously, invigorating you for 2 turns";
    Skill.cost[0] =  5 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = Player.defaultAttack + 10;
    Skill.heal = Player.health + 5 ;
    Skill.buff[0] = Player.defaultAttack + 5 ;
    Skill.duration = 3;
    Skill.type = "Buff";
    Skill.isMultiple = false;
    cls.bonusAttack = 5;
    cls.bonusDefense = 3;
    cls.bonusSpeed = 2;
    cls.bonusHealth = 20;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


     //Offensive Based Tier 1
    cls.name = "Pawn";
    cls.desc = "Mere nothing but a pawn on the battlefield, destined to die in vain";
    Skill.name = "Piercing Strike";
    Skill.id = 2;
    Skill.desc = "Uses the power of your will Spirit to throw your weapon at an enemy";
    Skill.cost[0] =  8 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = Player.defaultAttack*multiplier(50,100);
    Skill.heal = 0;
    Skill.buff[0] = 0;
    Skill.duration = 1;
    Skill.type = "Offensive";
    Skill.isMultiple = false;
    cls.bonusAttack = 10;
    cls.bonusDefense = 5;
    cls.bonusSpeed = 5;
    cls.bonusHealth = 20;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    left(ST) = adrSkill;
    skill(adrClass) = adrSkill;
    right(CT) = adrClass;



      //Offensive Based Tier 2
    cls.name = "Vagabond";
    cls.desc = "One who doesn't belong anywhere wanders from place to place without any objective whatsoever, relied on various means to sustain themselves, often through begging, odd jobs, or temporary work..";
    Skill.id = 3;
    Skill.name = "Dual Slash";
    Skill.desc = "perform a quick strike from below then a follow up with striking down";
    Skill.cost[0] = 15 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = (Player.defaultAttack*multiplier(100,150));
    Skill.heal = 0;
    Skill.buff[0] = 0;
    Skill.duration = 1;
    Skill.type = "Offensive";
    Skill.isMultiple = false;
    cls.bonusAttack = 25;
    cls.bonusDefense = 10;
    cls.bonusSpeed = 15;
    cls.bonusHealth = 10;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    left(left(ST)) = adrSkill;
    skill(adrClass) = adrSkill;
    left(right(CT)) = adrClass;


      //Offensive Based Tier 3
    cls.name = "Ronin";
    cls.desc = "Masterless samurai, used to be an honored warrior who had lost their lord through death or disgrace. Now marked by a sense of rootlessness and a constant search for purpose. .";
    Skill.id = 4;
    Skill.name = "Sword Dance";
    Skill.desc = "Dance along with your sword 'rythm' as if the battlefield was your 'stage', recalling your old master's teaching.";
    Skill.cost[0] = 27 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = ((Player.speed*multiplier(50,100)) + (Player.defaultAttack*multiplier(100,150)));
    Skill.heal = 0;
    Skill.buff[0] =  Player.defaultAttack + 10 ;
    Skill.duration = 1;
    Skill.type = "Offensive";
    Skill.isMultiple = false;
    cls.bonusAttack = 60;
    cls.bonusDefense = 15;
    cls.bonusSpeed = 50;
    cls.bonusHealth = 15;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    left(left(left(ST))) = adrSkill;
    skill(adrClass) = adrSkill;
    left(left(right(CT))) = adrClass;


          //Offensive Based Tier 3
    cls.name = "Pirate";
    cls.desc = "Throwing their own humility, Seafaring criminals who engaged in acts of robbery and violence on the high seas.";
    Skill.id = 5;
    Skill.name = "Plunder";
    Skill.desc = "Play dirty using cheap tricks like using mud and cuts shallow inflicting 'bleeding' and steal their valueables";
    Skill.cost[0] = 25 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = Player.defaultAttack*multiplier(150,250); //tambah overtime dmg
    Skill.heal = Player.health + 25 ;
    Skill.buff[0] = 0;
    Skill.duration = 2;
    Skill.type = "Offensive";
    Skill.isMultiple = false;
    cls.bonusAttack = 50;
    cls.bonusDefense = 35;
    cls.bonusSpeed = 30;
    cls.bonusHealth = 30;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(left(left(ST))) = adrSkill;
    skill(adrClass) = adrSkill;
    right(left(right(CT))) = adrClass;


    //Offensive Based Ulti
    cls.name = "Sun Hashira";
    cls.desc = "The Hashira are regarded as the most skilled and feared combatants in the entire world, protecting humanity against demons or more dangerous threats that cannot be handled by others.";
    Skill.id = 6;
    Skill.name = "Dance of the Fire God";
    Skill.desc = "It was once intended to use it as a ritual ceremony practiced every new year, where the Breathing Style user offers the Fire God a dance from sunset to sunrise to ward off threats and diseases.";
    Skill.cost[0] = 30 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = ((Player.speed*multiplier(100,120)) + (Player.defaultAttack*multiplier(150,220)));
    Skill.heal = 0;
    Skill.buff[0] = Player.defaultAttack + 10 ;
    Skill.duration = 1;
    Skill.type = "Offensive";
    Skill.isMultiple = false;
    cls.bonusAttack = 70;
    cls.bonusDefense = 25;
    cls.bonusSpeed = 75;
    cls.bonusHealth = 30;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(left(left(left(ST)))) = adrSkill;
    skill(adrClass) = adrSkill;
    right(left(left(right(CT)))) = adrClass;


    //Offensive Based Ulti
    cls.name = "Pirate Hunter";
    cls.desc = "With a reputation as a skilled swordsman who took on jobs as a bounty hunter. Known for hunting down pirates to collect bounties on their heads. Now dreaming to be the world's greatest swordsman... but with having a hard time navigating ";
    Skill.id = 7;
    Skill.name = "Kyuuto-ryuu : Ashura";
    Skill.desc = "An extreme application of one's spirit projection abilities. With sufficient anger, a dark aura surrounds One and somehow managed to create a solid illusion of Oneself with multiple heads and arms that can actually slice though even the strongest of opponents, giving the essence of nine swords.";
    Skill.cost[0] = 35 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = Player.defaultAttack*multiplier(250,350); //nnt tambah overtime Player.defaultAttack * 1 selama 2 turn
    Skill.heal = 0;
    Skill.buff[0] = Player.defaultAttack + 10 ;
    Skill.duration = 2;
    Skill.type = "Offensive";
    Skill.isMultiple = false;
    cls.bonusAttack = 60;
    cls.bonusDefense = 45;
    cls.bonusSpeed = 55;
    cls.bonusHealth = 40;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(right(left(left(ST)))) = adrSkill;
    skill(adrClass) = adrSkill;
    right(right(left(right(CT)))) = adrClass;


        //Offensive Multi Based tier 2
    cls.name = "Squire";
    cls.desc = "After surviving multiple war on the battlefield and with basic training, One could imagine being proud after promoted to a basic Squire";
    Skill.id = 8;
    Skill.name = "Sword Sweep Stance";
    Skill.desc = "Sweep strike multiple enemies grounds swiftly with your sword";
    Skill.cost[0] = 12 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = (Player.defaultDefence*multiplier(50,100)) + (Player.defaultAttack* multiplier(50,100)); //1 to adjacent
    Skill.heal = 0;
    Skill.buff[0] = 0;
    Skill.duration = 1;
    Skill.type = "Offensive";
    Skill.isMultiple = true;
    cls.bonusAttack = 15;
    cls.bonusDefense = 20;
    cls.bonusSpeed = 10;
    cls.bonusHealth = 15;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(left(ST)) = adrSkill;
    skill(adrClass) = adrSkill;
    right(right(CT)) = adrClass;

         //Offensive Multi Based AoE tier 3
     cls.name = "Royale Knight";
    cls.desc = "Members of the noble class, a skilled warriors trained in the art of warfare. They swore an oath of loyalty to their lord and were expected to serve in times of war. ";
    Skill.id = 9;
    Skill.name = "Divided Will";
    Skill.desc = "Gathers strength into your sword and shields to smash down onto the surface, dealing damage to enemies in a wide area.";
    Skill.cost[0] = 25 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = ((Player.defaultDefence*multiplier(100,120)) + (Player.defaultAttack *multiplier(70,100))) ; //ALL
    Skill.heal = 0;
    Skill.buff[0] = 0;
    Skill.duration = 1;
    Skill.type = "Offensive";
    Skill.isMultiple = true;
    cls.bonusAttack = 35;
    cls.bonusDefense = 40;
    cls.bonusSpeed = 20;
    cls.bonusHealth = 45;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    left(right(left(ST))) = adrSkill;
    skill(adrClass) = adrSkill;
    left(right(right(CT))) = adrClass;

    //Offensive Multi Based Single-AoE Tier 3 NEEDS HP .LOLOLOL
    cls.name = "Broadknight";
    cls.desc = "A knight who had distinguished himself in battle and was granted the right to lead his own group of soldiers in battle.";
    Skill.id = 10;
    Skill.name = "Pulverize";
    Skill.desc = "Widely spin in place, inflicting damage to surrounding enemies. Inflicts even bigger damage when spinning stops.";
    Skill.cost[0] = 22;
    Skill.cost[1] = 15;
    Skill.costStat[0] = "Stamina";
    Skill.costStat[1] = "Health";
    Skill.dmg  = (Player.defaultAttack*multiplier(120,170)) ; //follow up 4 to all
    Skill.heal = 0;
    Skill.buff[0] = 0;
    Skill.duration = 1;
    Skill.type = "Offensive";
    Skill.isMultiple = true;
    cls.bonusAttack = 45;
    cls.bonusDefense = 30;
    cls.bonusSpeed = 30;
    cls.bonusHealth = 35;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(right(left(ST))) = adrSkill;
    skill(adrClass) = adrSkill;
    right(right(right(CT))) = adrClass;


                 //Offensive Multi Based Single-AoE Ulti
     cls.name = "Black Swordsman";
    cls.desc = "A former mercenary and branded wanderer who travels the world in a constant internal struggle between pursuing his own ends and upholding his attachments to those dear to him.";
    Skill.id = 11;
    Skill.name = "Brand of Sacrifice";
    Skill.desc = "Using the power of marks those anointed for the Invocation of Doom, a sacrificial ceremony in which those consecrated by the laws of causality transcend their humanity";
    Skill.cost[0] = 35;
    Skill.cost[1] = 25; //jadi 45.5 stamina dan 10% health
    Skill.costStat[0] = "Stamina";
    Skill.costStat[1] = "Health";
    Skill.dmg  = (Player.defaultAttack*multiplier(170,250)) ; //follow up 5 to all
    Skill.heal = 0;
    Skill.buff[0] = Player.defaultDefence + 10;
    Skill.buff[1] = Player.defaultAttack + 5;  //jadi tambah 2 stats
    Skill.duration = 1;
    Skill.type = "Offensive";
    Skill.isMultiple = true;
    cls.bonusAttack = 50;
    cls.bonusDefense = 40;
    cls.bonusSpeed = 40;
    cls.bonusHealth = 70;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    left(left(right(left(ST)))) = adrSkill;
    skill(adrClass) = adrSkill;
    right(left(right(right(CT)))) = adrClass;


                 //Offensive Multi Based Multi-AoE Ulti
    cls.name = "Shinigami";
    cls.desc = "They are impure spirits with supernatural powers that devour the souls of both the living and the dead.";
    Skill.id = 12;
    Skill.name = "Zangetsu";
    Skill.desc = "Using the power of a Hollow, Zangetsu represents the dark side of One's soul. He says he represents One's purest instincts.";
    Skill.cost[0] = 32;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = ((Player.defaultDefence*multiplier(120,170)) + (Player.defaultAttack *multiplier(100,120))); // All
    Skill.heal = 0;
    Skill.buff[0] = Player.defaultAttack + 13;
    Skill.buff[1] = Player.defaultDefence + 7;
    Skill.duration = 1;
    Skill.type = "Offensive";
    Skill.isMultiple = true;
    cls.bonusAttack = 40;
    cls.bonusDefense = 80;
    cls.bonusSpeed = 40;
    cls.bonusHealth = 40;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    left(right(right(left(ST)))) = adrSkill;
    skill(adrClass) = adrSkill;
    right(right(right(right(CT)))) = adrClass;

         //Defensive Based Tier 1
    Skill.id = 13;
    Skill.name = "Shield Ready!";
    Skill.desc = "Readied up your shield to prepare an incoming defaultAttack.";
    Skill.cost[0] = 5;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = 0;
    Skill.heal = 0;
    Skill.buff[0] = Player.defaultDefence + 5;
    Skill.duration = 3;
    Skill.type = "Defensive";
    Skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(ST) = adrSkill;


            //Defensive-Buff Based Tier 2
    Skill.id = 14;
    Skill.name = "War Shout!";
    Skill.desc = "Slam your sword twice on your shield and shout to invigorate yourself for 2 turns.";
    Skill.cost[0] = 11 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = 0;
    Skill.heal = 0;
    Skill.buff[0] = Player.defaultDefence + 7;
    Skill.buff[1]= Player.defaultAttack + 13;
    Skill.duration = 3;
    Skill.type = "Defensive";
    Skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    left(right(ST)) = adrSkill;


            //Defensive-Offence Based Tier 2
    Skill.id = 15;
    Skill.name = "Shield Mirror";
    Skill.desc = "Enters the Counter state. When attacked, acts immediately and slams your shield on the attacker.";
    Skill.cost[0] = 13 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = Player.defaultDefence *multiplier(50,100);
    Skill.heal = 0;
    Skill.buff[0] = Player.defaultDefence + 15;
    Skill.buff[1] = Player.defaultAttack + 5 ;
    Skill.duration = 3;
    Skill.type = "Defensive";
    Skill.isMultiple = true;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(right(ST)) = adrSkill;



            //Defensive-buff buff Based Tier 3
    Skill.id = 16;
    Skill.name = "Unyielding Might";
    Skill.desc = "With a roar that echoes through the battlefield, becoming an indomitable force of destruction.";
    Skill.cost[0] = 19 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = 0;
    Skill.heal = Player.health + 5 ;
    Skill.buff[0] = Player.defaultAttack + 20 ;
    Skill.duration = 2;
    Skill.type = "Defensive";
    Skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    left(left(right(ST))) = adrSkill;

            //Defensive-defaultDefence buff Based Tier 3
    Skill.id = 17;
    Skill.name = "Vindicta";
    Skill.desc = "Let the enemies come, for with Vindicta, your defense stands as an unassailable wall.";
    Skill.cost[0] = 18 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = 0;
    Skill.heal = Player.health + 10 ;
    Skill.buff[0] = Player.defaultDefence + 25 ;
    Skill.duration = 2;
    Skill.type = "Defensive";
    Skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(left(right(ST))) = adrSkill;



         //Defensive-Leach Shield buff Based Tier 3
    Skill.id = 18;
    Skill.name = "Shell of Meropide";
    Skill.desc = "A shimmering barrier manifests, warding off attacks and inflicting damage upon each assailant foolhardy enough to breach its sanctity.";
    Skill.cost[0] = 18 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = Player.defaultDefence + 15 ;
    Skill.heal = Player.health + 15 ;
    Skill.buff[0] = Player.currentHealth + 20 ;
    Skill.duration = 2;
    Skill.type = "Defensive";
    Skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    left(right(right(ST))) = adrSkill;

           //Defensive-Sheild thorn buff Based Tier 3
    Skill.id = 19;
    Skill.name = "Shield of Thorns";
    Skill.desc = "Weaves a defensive tapestry of nature's vengeance. each hits taken, retaliates against assailants..";
    Skill.cost[0] = 18 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = Player.defaultDefence *multiplier(100,150);
    Skill.heal = 0;
    Skill.buff[0] = 0;
    Skill.duration = 2;
    Skill.type = "Defensive";
    Skill.isMultiple = true;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(right(right(ST))) = adrSkill;

          //Defensive-Buff buff Based ult
    Skill.id = 20;
    Skill.name = "Freedom Speech";
    Skill.desc = "'From the moment I was born, those stifling walls were the farthest I could see. Water that glows like fire. Fields of ice. Sandy snowfields. To witness all that..Was to know the greatest freedom this world could offer. We're here, We're FREE.'";
    Skill.cost[0] = 26 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = 0;
    Skill.heal = Player.health + 20;
    Skill.buff[0] = Player.defaultAttack + 30 ;
    Skill.duration = 2;
    Skill.type = "Defensive";
    Skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(left(left(right(ST)))) = adrSkill;

    //Defensive-defaultDefence buff Based ult
      Skill.id = 21;
    Skill.name = "Guardian's Embrace";
    Skill.desc = "Feeling determined to protect those who you've cherished, forms a spiritual manifestation similar to a certain shield hero";
    Skill.cost[0] = Player.stamina - 26 ;
    Skill.costStat[0] = "Stamina";
    Skill.dmg  = 0;
    Skill.heal = Player.health + 30;
    Skill.buff[0] = Player.defaultDefence + 40 ;
    Skill.duration = 3;
    Skill.type = "Defensive";
    Skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(right(left(right(ST)))) = adrSkill;

//Defensive-Leach sheidl Based ult
      Skill.id = 22;
    Skill.name = "Gate of Babylon";
    Skill.desc = "Searching for a true meaning of pleasure, One ready to sacrifice everything to gain it.";
    Skill.cost[0] = 30;
    Skill.cost[1] = 15 ;
    Skill.costStat[0] = "Stamina";
    Skill.costStat[1] = "Health";
    Skill.dmg  = Player.currentHealth + 30 ;
    Skill.heal = Player.health + 20;
    Skill.buff[0] = Player.defaultDefence + 10;
    Skill.duration = 2;
    Skill.type = "Defensive";
    Skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(left(right(right(ST)))) = adrSkill;

    //Defensive-offence Based ult
      Skill.id = 23;
    Skill.name = "Iron Fortress of Kabaneri";
    Skill.desc = "Exo Skeleton suit made of iron while trying to resist a mysterious virus and becoming something else, enhancing their skin alike of sharp thorns and their heart plated with steel.";
    Skill.cost[0] =  28;
    Skill.cost[1] = 15;
    Skill.costStat[0] = "Stamina";
    Skill.costStat[1] = "Health";
    Skill.dmg  =  Player.defaultDefence *multiplier(150,170);
    Skill.heal =0;
    Skill.buff[0] = 0;
    Skill.duration = 2;
    Skill.type = "Defensive";
    Skill.isMultiple = true;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    right(right(right(right(ST)))) = adrSkill;
}
void initiatePlayer(playerList &PL){
    createPlayerList(PL);
    Player.name = "Mike";
    Player.Class = "Newbie";
    Player.defaultAttack = 10;
    Player.defaultDefence = 10;
    Player.coin = 100;
    Player.health = 20;
    Player.currentHealth = Player.health;
    Player.speed = 10;
    Player.stamina = 10;
    Player.currentStamina = 10;
    Player.exp = 0;
    Player.level = 1;
    Player.nextLevel = 10;
    adrPlayer = createNewPlayerElement(Player);
    addPlayer(PL,adrPlayer);

    Player.name = "Master Bait";
    Player.defaultAttack = 10;
    Player.defaultDefence = 10;
    Player.coin = 51234;
    Player.health = 20;
    Player.currentHealth = Player.health;
    Player.speed = 10;
    Player.stamina = 10;
    Player.currentStamina = 10;
    Player.exp = 1532;
    Player.level = 10;
    Player.nextLevel = 51223;
    adrPlayer = new elementPlayer;
    adrPlayer = createNewPlayerElement(Player);
    addPlayer(PL,adrPlayer);
    changePlayerClass(Player.name, "Pawn");
    changePlayerClass(Player.name, "Vagabond");
    changePlayerClass(Player.name, "Ronin");
    changePlayerClass(Player.name, "Sun Hashira");
    addSkillToPlayer(PL,ST,Player.name,info(right(ST)).name);
    addSkillToPlayer(PL,ST,Player.name,info(right(right(ST))).name);
    addSkillToPlayer(PL,ST,Player.name,info(left(right(right(ST)))).name);
    addSkillToPlayer(PL,ST,Player.name,info(right(left(right(right(ST))))).name);

    Player.name = "Jetstream";
    Player.defaultAttack = 10;
    Player.defaultDefence = 10;
    Player.coin = 100;
    Player.health = 20;
    Player.currentHealth = Player.health;
    Player.speed = 10;
    Player.stamina = 10;
    Player.currentStamina = 10;
    Player.exp = 0;
    Player.level = 1;
    Player.nextLevel = 10;
    adrPlayer = createNewPlayerElement(Player);
    addPlayer(PL,adrPlayer);
    changePlayerClass(Player.name, "Pawn");
    changePlayerClass(Player.name, "Squire");
    changePlayerClass(Player.name, "Royale Knight");

    addSkillToPlayer(PL,ST,Player.name,info(right(ST)).name);
    addSkillToPlayer(PL,ST,Player.name,info(left(right(ST))).name);
    addSkillToPlayer(PL,ST,Player.name,info(right(left(right(ST)))).name);


}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void initiateEnemy(enemyList &EL){
    createEnemyList(EL);
    //Dari Bount Hunter (occurance)
    Enemy.name = "Reunion Bounty Hunter"; //medium dif
    Enemy.health = 150; //+50
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 40; //+25
    Enemy.defaultDefence = 35; // +10
    Enemy.speed = 15; // +5
    Enemy.xp = 425;
    Enemy.coin = 10;
    Enemy.basicName = "Infected Slash";
    Enemy.skillName = "Originium Healing";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 0;
    Enemy.skillHeal = 75;
    Enemy.skillStatus = "Heal";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "Reunion's Garb";
    Enemy.dropChance = 1;
    addEnemy(EL,createNewEnemyElement(Enemy));

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Saleo (Battle)
    Enemy.name = "Older Brother Leo"; //medium dif
    Enemy.health = 180; //+30
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 45; //+30
    Enemy.defaultDefence = 25; // +10
    Enemy.speed = 30; // +20
    Enemy.xp = 425;
    Enemy.coin = 10;
    Enemy.basicName = "Hot Pitchfork";
    Enemy.skillName = "Tricked";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1.50;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.5;
    Enemy.itemDrop = "Yin Charm";
    Enemy.dropChance = 1;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Younger Brother Sal";//easy dif
    Enemy.health = 160; //+20
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 25; //+10
    Enemy.defaultDefence = 25; // +10
    Enemy.speed = 25; // +10
    Enemy.xp = 300;
    Enemy.coin = 5;
    Enemy.basicName = "Cold Pitchfork";
    Enemy.skillName = "Treat";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 0;
    Enemy.skillHeal = 40;
    Enemy.skillStatus = "Heal";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "Yang Charm";
    Enemy.dropChance = 1;
    addEnemy(EL,createNewEnemyElement(Enemy));


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Dari House of Nildis (Occurance)
    Enemy.name = "One-Eyed 'Kent'"; //hard dif
    Enemy.health = 270; //+80
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 65; //+50
    Enemy.defaultDefence = 25; // +10
    Enemy.speed = 40; // +30
    Enemy.xp = 600;
    Enemy.coin = 20;
    Enemy.basicName = "Blade Arm Chop";
    Enemy.skillName = "Pinball Cannon";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1.5;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "Gambler's Brooch";
    Enemy.dropChance = 1;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Kent's Elite Rogue"; //med dif x 3
    Enemy.health = 110; //+10
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 40; //+25
    Enemy.defaultDefence = 25; // +10
    Enemy.speed = 35; // +25
    Enemy.xp = 425;
    Enemy.coin = 10;
    Enemy.basicName = "Flash Slash";
    Enemy.skillName = "Mini Bomb";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1.25;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "Stun";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Dari Nomadic Miners (occurance)
    Enemy.name = "Lead Miner"; // medium
    Enemy.health = 180; //+20
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 30; //+15
    Enemy.defaultDefence = 65; // +50
    Enemy.speed = 15; // +5
    Enemy.xp = 425;
    Enemy.coin = 10;
    Enemy.basicName = "Brick Break";
    Enemy.skillName = "Defensive Stance"; //nnt dia ngasih defaultDefence tambahan ke tmn smua selama 2 turn
    Enemy.skillDamaging = false;
    Enemy.isMultiple = true;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 32;
    Enemy.skillHeal = 0; //defaultDefence gain
    Enemy.skillStatus = "Buff";
    Enemy.skillBuff = "defence";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "Lead Splunking Helmet";
    Enemy.dropChance = 1;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Miner"; // easy
    Enemy.health = 120; //+0
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 30; //+15
    Enemy.defaultDefence = 35; // +20
    Enemy.speed = 25; // +15
    Enemy.xp = 300;
    Enemy.coin = 5;
    Enemy.basicName = "Shovel Smash";
    Enemy.skillName = "Excavate";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1.5;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.30;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Dari Insect Nest (occurance)
    Enemy.name = "Insect";
    Enemy.health = 135; //+15
    Enemy.defaultAttack = 30; //+15
    Enemy.defaultDefence = 30; // +15
    Enemy.speed = 30; // +20
    Enemy.xp = 150;
    Enemy.coin = 5;
    Enemy.basicName = "Lunge";
    Enemy.skillName = "Infestation";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1.25; //ovt dmg 2 turns
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "bleed";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "none"; //tergantung choice drop
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Dari  We Are Cowboys (Battle)
    Enemy.name = "Cowboy"; //med x 4
    Enemy.health = 160; //+20
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 35; //+20
    Enemy.defaultDefence = 45; // +20
    Enemy.speed = 40; // +30
    Enemy.xp = 425;
    Enemy.coin = 10;
    Enemy.basicName = "Trample";
    Enemy.skillName = "Guns Blazing";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 2;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "10 Coins";
    Enemy.dropChance = 1;
    addEnemy(EL,createNewEnemyElement(Enemy));

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Dari Beast Horde  (Battle)
    Enemy.name = "Young Beast"; //medium x 4
    Enemy.health = 175; //+25
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 55; //+40
    Enemy.defaultDefence = 15; // +0
    Enemy.speed = 35; // +25
    Enemy.xp = 425;
    Enemy.coin = 10;
    Enemy.basicName = "Scratch";
    Enemy.skillName = "Sharp Fang";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 0.5; // bleed for 2 turns
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "Bleed";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 1;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Adult Beast"; //Hard x 2
    Enemy.health = 300; //+100
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 65; //+50
    Enemy.defaultDefence = 15; // +0
    Enemy.speed = 35; // +20
    Enemy.xp = 600;
    Enemy.coin = 20;
    Enemy.basicName = "Chomp";
    Enemy.skillName = "Envigorating Howl";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = true;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 0.5;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "Buff";
    Enemy.skillBuff = "attack";
    Enemy.skillChance = 0.30;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Dari Rock, Paper, Bullet(Battle)
    Enemy.name = "Ring Master"; //Hard 170
    Enemy.health = 260; //+50
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 30; //+15
    Enemy.defaultDefence = 65; // +50
    Enemy.speed = 50; // +40
    Enemy.xp = 600;
    Enemy.coin = 20;
    Enemy.basicName = "Disciplined Whip";
    Enemy.skillName = "Team Building";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = true;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 0;
    Enemy.skillHeal = 0.5; //dia buff semua team defaultAttack 0.5 selama 2 turns
    Enemy.skillStatus = "Buff";
    Enemy.skillBuff = "attack";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "Ringmaster's Pants";
    Enemy.dropChance = 1;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Strong Performer"; //Medium x 4
    Enemy.health = 180; //+40
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 55; //+40
    Enemy.defaultDefence = 15; // +0
    Enemy.speed = 20; // +10
    Enemy.xp = 425;
    Enemy.coin = 10;
    Enemy.basicName = "Slam";
    Enemy.skillName = "Head Lock";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 1.5;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.20;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Dari Dueling Tavern(Battle)
    Enemy.name = "Security Guard"; //Hard x 2
    Enemy.health = 260; //+60
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 65; //+50
    Enemy.defaultDefence = 75; // +60
    Enemy.speed = 10; // +0
    Enemy.xp = 600;
    Enemy.coin = 20;
    Enemy.basicName = "Shoulder Slam";
    Enemy.skillName = "Ready for Duty";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 0;
    Enemy.skillHeal = 0.5; // 0.25 defaultAttack n defaultDefence 2 turn
    Enemy.skillStatus = "Buff";
    Enemy.skillBuff = "defence";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "Defence Potion";
    Enemy.dropChance = 0.75;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Mercenary"; //Medium x 3
    Enemy.health = 170; //+30
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 45; //+30
    Enemy.defaultDefence = 15; // +0
    Enemy.speed = 40; // +30
    Enemy.xp = 425;
    Enemy.coin = 10;
    Enemy.basicName = "Slash";
    Enemy.skillName = "Sticky Blade!";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 0.5; //leech effect 2 turn
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "Leech";
    Enemy.skillBuff = "defence";
    Enemy.skillChance = 0.40;
    Enemy.itemDrop = "Attack Potion";
    Enemy.dropChance = 0.75;
    addEnemy(EL,createNewEnemyElement(Enemy));

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Dari Runic Chest (Occurance)
    Enemy.name = "Red Mimic"; //Hard
    Enemy.health = 250; //+0
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 75; //+60
    Enemy.defaultDefence = 65; // +50
    Enemy.speed = 70; // +60
    Enemy.xp = 600;
    Enemy.coin = 20;
    Enemy.basicName = "Bite";
    Enemy.skillName = "Devour";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 2; //w rencana instant death tp nvm lol
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "Runic Chestplate";
    Enemy.dropChance = 0.5; //50/50 bjir
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Blue Mimic"; //Hard
    Enemy.health = 250; //+0
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 75; //+60
    Enemy.defaultDefence = 65; // +50
    Enemy.speed = 70; // +60
    Enemy.xp = 600;
    Enemy.coin = 20;
    Enemy.basicName = "Bite";
    Enemy.skillName = "Blinding Light";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1; //w rencana instant death tp nvm lol
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "Stun";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "Runic Legging";
    Enemy.dropChance = 0.5; //50/50 bjir
    addEnemy(EL,createNewEnemyElement(Enemy));


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Dari Enchanting Song (occurance)
    Enemy.name = "Siren";
    Enemy.health = 250; //+50
    Enemy.currentHealth = Enemy.health;
    Enemy.defaultAttack = 20; //+30
    Enemy.defaultDefence = 25; // +50
    Enemy.speed = 15; // +40
    Enemy.xp = 600;
    Enemy.coin = 20;
    Enemy.basicName = "Screeching Song";
    Enemy.skillName = "Healing Song";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = true;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 0;
    Enemy.skillHeal = 0.30; //Heal ALL
    Enemy.skillStatus = "Heal";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.35;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Dari Moonlight's End (occurance)
Enemy.name = "Skeletal King";
    Enemy.health = 500; //+100
    Enemy.defaultAttack = 45; //+30
    Enemy.defaultDefence = 115; // +100
    Enemy.speed = 40; // +30
    Enemy.xp = 1200;
    Enemy.coin = 30;
    Enemy.basicName = "Bludgeon Smash";
    Enemy.skillName = "Undead Healing";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = true;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 0; //Spawn/'revive' 2 Skelly
    Enemy.skillHeal = 1;
    Enemy.skillStatus = "Heal";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.20;
    Enemy.itemDrop = "none"; //tergantung choice drop
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Skeleton Goon"; //easy
    Enemy.health = 150; //+0
    Enemy.defaultAttack = 40; //+25
    Enemy.defaultDefence = 15; // +0
    Enemy.speed = 40; // +25
    Enemy.xp = 150;
    Enemy.coin = 0;
    Enemy.basicName = "Punch";
    Enemy.skillName = "Decayed Blows";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1.25;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Dari Mad Jester(Boss Battle)
    Enemy.name = "Jevil";
    Enemy.health = 670; //+50
    Enemy.defaultAttack = 135; //+120
    Enemy.defaultDefence = 45; // +30
    Enemy.speed = 70; // +60
    Enemy.xp = 1200;
    Enemy.coin = 30;
    Enemy.basicName = "'Heart defaultAttack'";
    Enemy.skillName = "Chaos Bomb";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 2.2;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "none"; //tergantung choice drop
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Dari Fate's End(Final Battle)
    Enemy.name = "The Shrouded One, Ka'as";
    Enemy.health = 500;
    Enemy.defaultAttack = 105;
    Enemy.defaultDefence = 45;
    Enemy.speed = 40;
    Enemy.xp = 2000;
    Enemy.coin = 30;
    Enemy.basicName = "Conjure Fireball";
    Enemy.skillName = "Ancient Chant";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1.2;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

    //ketika ad artifact
    Enemy.name = "The True Master of Chaos, Ka'as";
    Enemy.health = 1500; //+50
    Enemy.defaultAttack = 235; //+120
    Enemy.defaultDefence = 145; // +30
    Enemy.speed = 70; // +60
    Enemy.xp = 1200;
    Enemy.coin = 30;
    Enemy.basicName = "Chaos Blast";
    Enemy.skillName = "Harness Artifact";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 1;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "none"; //tergantung choice drop
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Pillars of Preserverance";
    Enemy.health = 150; //+50
    Enemy.defaultAttack = 0; //+120
    Enemy.defaultDefence = 100; // +30
    Enemy.speed = 50; // +60
    Enemy.xp = 700;
    Enemy.coin = 30;
    Enemy.basicName = "Harnessing Power";
    Enemy.skillName = "Power of Preserverance";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = true;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 1;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "buff";
    Enemy.skillBuff = "defence";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "none"; //tergantung choice drop
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));


    Enemy.name = "Pillars of Courage";
    Enemy.health = 150; //+50
    Enemy.defaultAttack = 100; //+120
    Enemy.defaultDefence = 0; // +30
    Enemy.speed = 50; // +60
    Enemy.xp = 700;
    Enemy.coin = 30;
    Enemy.basicName = "Harnessing Power";
    Enemy.skillName = "Power of Courage";
    Enemy.skillDamaging = true;
    Enemy.isMultiple = false;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1;
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "none";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "none"; //tergantung choice drop
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Pillars of Altruistic";
    Enemy.health = 150; //+50
    Enemy.defaultAttack = 0; //+120
    Enemy.defaultDefence = 0; // +30
    Enemy.speed = 50; // +60
    Enemy.xp = 700;
    Enemy.coin = 30;
    Enemy.basicName = "Harnessing Power";
    Enemy.skillName = "Power of Altruistic";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = true;
    Enemy.skillDuration = 2;
    Enemy.skillMultiplier = 0;
    Enemy.skillHeal = 1; //kek 150 buat semua
    Enemy.skillStatus = "Heal";
    Enemy.skillBuff = "none";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));

    Enemy.name = "Pillars of Determination";
    Enemy.health = 150; //+50
    Enemy.defaultAttack = 100; //+120
    Enemy.defaultDefence = 0; // +30
    Enemy.speed = 50; // +60
    Enemy.xp = 700;
    Enemy.coin = 30;
    Enemy.basicName = "Harnessing Power";
    Enemy.skillName = "Power of Determination";
    Enemy.skillDamaging = false;
    Enemy.isMultiple = true;
    Enemy.skillDuration = 1;
    Enemy.skillMultiplier = 1; //kek buff 100 attack buat 1 turn
    Enemy.skillHeal = 0;
    Enemy.skillStatus = "Buff";
    Enemy.skillBuff = "attack";
    Enemy.skillChance = 0.25;
    Enemy.itemDrop = "none";
    Enemy.dropChance = 0;
    addEnemy(EL,createNewEnemyElement(Enemy));




}
void initiateMenu(){
    createMenuStack(Menu);
    splashScreen();
}
