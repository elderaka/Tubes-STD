#include "main.h"
#include "player.h"
playerList PL;
objectList OL;
skillTree ST;
classTree CT;
player Player;
object Object;
skill Skill;
Class cls;
playerAddress adrPlayer;
objectAddress adrObject;

void addObjectToPlayer(playerList &PL, objectList OL, string player,string object){

    adrPlayer = findPlayer(PL,player);
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
void addSkillToPlayer(playerList &PL, skillTree ST, string player, string skill){
    playerAddress adrPlayer = findPlayer(PL,player);
    skillAddress adrSkill = findskill(ST,skill);

    if(adrPlayer != NULL && adrSkill != NULL){
        sListAddress R = new elementSkill;
        R = createNewSkillElement(adrSkill);
        insertLastSkill(skill(adrPlayer),R);
    }
}
void removeSkillFromPlayer(playerList &PL, skillList &SL, string player, string skill){
    playerAddress adrPlayer = findPlayer(PL,player);
    if(adrPlayer != NULL){
        skillList ski = skill(adrPlayer);
        removeSkill(ski,ST,skill);
    }else{
        cout << "Player not found" << endl;
    }
}
void changePlayerClass(string player, string Class){
    playerAddress adrPlayer = findPlayer(PL,player);
    classAddress adrClass = findClass(CT,Class);

    if(adrPlayer != NULL && adrClass != NULL){
        Class(adrPlayer) = adrClass;
        addSkillToPlayer(PL,ST,player,info(skill(adrClass)).name);
        info(adrPlayer).Class = info(adrClass).name;
    }
}
void deleteObject(playerList &PL, objectList &OL, string name){
    playerAddress P = first(PL);
    while(P != NULL){
        removeObject(inventory(P),OL, name);
    }
    objectAddress Q = findObject(OL,name);
    if(Q != NULL){
        objectAddress prec = prev(Q);
        next(prec) = next(Q);
        if(next(prec) != NULL){
            prev(next(Q)) = prec;
        }
        next(Q) = NULL;
        prev(Q) = NULL;
    }

}
void initiateObjects(objectList &OL){
    createObjectList(OL);
    object Object;
    Object.name = "Stone";
    addObject(OL,createNewObjectElement(Object));
    Object.name = "Paper";
    addObject(OL,createNewObjectElement(Object));
    Object.name = "Scissor";
    addObject(OL,createNewObjectElement(Object));
}
void initiateSkillAndClass(skillTree &ST, classTree &CT){
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
    skill.id = 1;
    Skill.desc = "Scream out on top of your lungs and swing voraciously, invigorating you for 2 turns";
    Skill.cost = player.stamina - (5 * player.level);
    skill.dmg  = player.stamina + (10 * player.level);
    skill.heal = player.health + (15 * player.level);
    skill.buff = player.attack + (15 * player.level);
    skill.duration = 3;
    skill.type = "Support, Buff";
    skill.isMultiple = false;
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
    skill.id = 2;
    Skill.desc = "Uses the power of your will Spirit to throw your weapon at an enemy";
    Skill.cost = player.stamina - (10 * player.level);
    skill.dmg  = player.defaultAttack * 1.5;
    skill.heal = 0;
    skill.buff = 0;
    skill.duration = 1;
    skill.type = "Offensive";
    skill.isMultiple = false;
    cls.bonusAttack = 10;
    cls.bonusDefense = 5;
    cls.bonusSpeed = 5;
    cls.bonusHealth = 20;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);



      //Offensive Based Tier 2
    cls.name = "Vagabond";
    cls.desc = " One who doesn't belong anywhere wanders from place to place without any objective whatsoever, relied on various means to sustain themselves, often through begging, odd jobs, or temporary work..";
    skill.id = 3;
    Skill.name = "Dual Slash";
    Skill.desc = "perform a quick strike from below then a follow up with striking down";
    Skill.cost = player.stamina - (25 * player.level);
    skill.dmg  = (player.defaultAttack * 3) * 2;
    skill.heal = 0;
    skill.buff = 0;
    skill.duration = 1;
    skill.type = "Offensive";
    skill.isMultiple = true;
    cls.bonusAttack = 25;
    cls.bonusDefense = 10;
    cls.bonusSpeed = 15;
    cls.bonusHealth = 10;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


      //Offensive Based Tier 3
    cls.name = "Ronin";
    cls.desc = "Masterless samurai, used to be an honored warrior who had lost their lord through death or disgrace. Now marked by a sense of rootlessness and a constant search for purpose. .";
    skill.id = 4;
    Skill.name = "Sword Dance";
    Skill.desc = "Dance along with your sword 'rythm' as if the battlefield was your 'stage', recalling your old master's teaching.";
    Skill.cost = player.stamina - (37 * player.level);
    skill.dmg  = (player.speed * 0.5) + (player.defaultAttack * 2.5) * 4;
    skill.heal = 0;
    skill.buff =  player.attack + (10 * player.level);
    skill.duration = 1;
    skill.type = "Offensive";
    skill.isMultiple = false;
    cls.bonusAttack = 60;
    cls.bonusDefense = 15;
    cls.bonusSpeed = 50;
    cls.bonusHealth = 15;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


          //Offensive Based Tier 3
    cls.name = "Pirate";
    cls.desc = "Throwing their own humility, Seafaring criminals who engaged in acts of robbery and violence on the high seas.";
    skill.id = 5;
    Skill.name = "Plunder";
    Skill.desc = "Play dirty using cheap tricks like using mud and cuts shallow inflicting 'bleeding' and steal their valueables";
    Skill.cost = player.stamina - (35 * player.level);
    skill.dmg  = (player.defaultAttack * 2.5) * 2; //tambah overtime dmg
    skill.heal = player.health + (25 * player.level);
    skill.buff = 0;
    skill.duration = 2;
    skill.type = "Offensive";
    skill.isMultiple = true;
    cls.bonusAttack = 50;
    cls.bonusDefense = 35;
    cls.bonusSpeed = 30;
    cls.bonusHealth = 30;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


          //Offensive Based Ulti
    cls.name = "Sun Hashira";
    cls.desc = "The Hashira are regarded as the most skilled and feared combatants in the entire world, protecting humanity against demons or more dangerous threats that cannot be handled by others.";
    skill.id = 6;
    Skill.name = "Dance of the Fire God";
    Skill.desc = "It was once intended to use it as a ritual ceremony practiced every new year, where the Breathing Style user offers the Fire God a dance from sunset to sunrise to ward off threats and diseases.";
    Skill.cost = player.stamina - (50 * player.level);
    skill.dmg  = player.speed + (player.defaultAttack * 1.5) * 12;
    skill.heal = 0;
    skill.buff = player.attack + (10 * player.level);
    skill.duration = 1;
    skill.type = "Offensive";
    skill.isMultiple = false;
    cls.bonusAttack = 70;
    cls.bonusDefense = 25;
    cls.bonusSpeed = 75;
    cls.bonusHealth = 30;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


        //Offensive Based Ulti
    cls.name = "Pirate Hunter";
    cls.desc = "With a reputation as a skilled swordsman who took on jobs as a bounty hunter. Known for hunting down pirates to collect bounties on their heads. Now dreaming to be the world's greatest swordsman... but with having a hard time navigating ";
    skill.id = 7;
    Skill.name = "Kyuuto-ryū : Ashura";
    Skill.desc = "An extreme application of one's spirit projection abilities. With sufficient anger, a dark aura surrounds One and somehow managed to create a solid illusion of Oneself with multiple heads and arms that can actually slice though even the strongest of opponents, giving the essence of nine swords.";
    Skill.cost = player.stamina - (45 * player.level);
    skill.dmg  = (player.defaultAttack * 2) * 9; //nnt tambah overtime player.defaultAttack * 1 selama 2 turn
    skill.heal = 0;
    skill.buff = player.attack + (10 * player.level);
    skill.duration = 2;
    skill.type = "Offensive";
    skill.isMultiple = true;
    cls.bonusAttack = 60;
    cls.bonusDefense = 45;
    cls.bonusSpeed = 55;
    cls.bonusHealth = 40;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


        //Offensive Multi Based tier 2
    cls.name = "Squire";
    cls.desc = "After surviving multiple war on the battlefield and with basic training, One could imagine being proud after promoted to a basic Squire";
    skill.id = 8;
    Skill.name = "Sword Sweep";
    Skill.desc = "Sweep strike multiple enemies grounds swiftly with your sword";
    Skill.cost = player.stamina - (20 * player.level);
    skill.dmg  = (player.defaultAttack * 2) + (player.defaultAttack * 1.5); //1.5 to adjacent
    skill.heal = 0;
    skill.buff = 0;
    skill.duration = 1;
    skill.type = "Offensive";
    skill.isMultiple = true;
    cls.bonusAttack = 15;
    cls.bonusDefense = 20;
    cls.bonusSpeed = 10;
    cls.bonusHealth = 15;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);

         //Offensive Multi Based AoE tier 3
     cls.name = "Royale Knight";
    cls.desc = "Members of the noble class, a skilled warriors trained in the art of warfare. They swore an oath of loyalty to their lord and were expected to serve in times of war. ";
    skill.id = 9;
    Skill.name = "Divided Will";
    Skill.desc = "Gathers strength into your sword and shields to smash down onto the surface, dealing damage to enemies in a wide area.";
    Skill.cost = player.stamina - (37.5 * player.level);
    skill.dmg  = (player.defaultAttack * 5.5) ; //ALL
    skill.heal = 0;
    skill.buff = 0;
    skill.duration = 1;
    skill.type = "Offensive";
    skill.isMultiple = true;
    cls.bonusAttack = 35;
    cls.bonusDefense = 40;
    cls.bonusSpeed = 20;
    cls.bonusHealth = 45;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);

                 //Offensive Multi Based Single-AoE Tier 3
     cls.name = "Broadknight";
    cls.desc = "A knight who had distinguished himself in battle and was granted the right to lead his own group of soldiers in battle.";
    skill.id = 10;
    Skill.name = "Pulverize";
    Skill.desc = "Widely spin in place, inflicting damage to surrounding enemies. Inflicts even bigger damage when spinning stops.";
    Skill.cost = player.stamina - (35 * player.level);
    skill.dmg  = (player.defaultAttack * 3) + (player.defaultAttack * 4) ; //follow up 4 to all
    skill.heal = 0;
    skill.buff = 0;
    skill.duration = 1;
    skill.type = "Offensive";
    skill.isMultiple = true;
    cls.bonusAttack = 45;
    cls.bonusDefense = 30;
    cls.bonusSpeed = 30;
    cls.bonusHealth = 35;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


                 //Offensive Multi Based Single-AoE Ulti
     cls.name = "Black Swordsman";
    cls.desc = "A former mercenary and branded wanderer who travels the world in a constant internal struggle between pursuing his own ends and upholding his attachments to those dear to him.";
    skill.id = 11;
    Skill.name = "Brand of Sacrifice";
    Skill.desc = "Using the power of marks those anointed for the Invocation of Doom, a sacrificial ceremony in which those consecrated by the laws of causality transcend their humanity";
    Skill.cost = player.stamina - (45 * player.level) ; (player.health - (10 * player.level)); //jadi 45.5 stamina dan 10% health
    skill.dmg  = (player.defaultAttack * 4) + (player.defaultAttack * 5) ; //follow up 5 to all
    skill.heal = 0;
    skill.buff = player.defaultAttack + (2.5* player.level); player.defaultDefence + (1.5* player.level) //jadi tambah 2 stats
    skill.duration = 1;
    skill.type = "Offensive";
    skill.isMultiple = true;
    cls.bonusAttack = 50;
    cls.bonusDefense = 40;
    cls.bonusSpeed = 40;
    cls.bonusHealth = 70;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


                 //Offensive Multi Based Multi-AoE Ulti
     cls.name = "Shinigami";
    cls.desc = "They are impure spirits with supernatural powers that devour the souls of both the living and the dead.";
    skill.id = 12;
    Skill.name = "Zangetsu";
    Skill.desc = "Using the power of a Hollow, Zangetsu represents the dark side of One's soul. He says he represents One's purest instincts.";
    Skill.cost = player.stamina - (50 * player.level)
    skill.dmg  = (player.defaultAttack * 6); // All
    skill.heal = 0;
    skill.buff = player.defaultAttack + (2.5* player.level); player.defaultDefence + (1.5* player.level) //jadi tambah 2 stats
    skill.duration = 1;
    skill.type = "Offensive";
    skill.isMultiple = true;
    cls.bonusAttack = 40;
    cls.bonusDefense = 80;
    cls.bonusSpeed = 40;
    cls.bonusHealth = 40;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);

         //Defensive Based Tier 1
    skill.id = 13;
    Skill.name = "Shield Ready!";
    Skill.desc = "Readied up your shield to prepare an incoming attack.";
    Skill.cost = player.stamina - (5 * player.level);
    skill.dmg  = 0;
    skill.heal = 0;
    skill.buff = player.defaultDefence + (1* player.level);
    skill.duration = 3;
    skill.type = "Defence";
    skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


            //Defensive-Buff Based Tier 2
    skill.id = 14;
    Skill.name = "War Shout!";
    Skill.desc = "Slam your sword twice on your shield and shout to invigorate yourself for 2 turns.";
    Skill.cost = player.stamina - (15 * player.level);
    skill.dmg  = 0;
    skill.heal = 0;
    skill.buff = player.defaultDefence + (3 * player.level), player.defaultAttack + (1.5 * player.level);
    skill.duration = 3;
    skill.type = "Defence";
    skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


            //Defensive-Offence Based Tier 2
    skill.id = 15;
    Skill.name = "Shield Mirror";
    Skill.desc = "Enters the Counter state. When attacked, acts immediately and slams your shield on the attacker.";
    Skill.cost = player.stamina - (20 * player.level);
    skill.dmg  = player.defaultDefence - (0.5 * player.defaultDefence);
    skill.heal = 0;
    skill.buff = player.defaultDefence + (3 * player.level), player.defaultAttack + (1.5 * player.level);
    skill.duration = 3;
    skill.type = "Defence";
    skill.isMultiple = true;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);




            //Defensive-buff buff Based Tier 3
    skill.id = 16;
    Skill.name = "Unyielding Might";
    Skill.desc = "With a roar that echoes through the battlefield, becoming an indomitable force of destruction.";
    Skill.cost = player.stamina - (30 * player.level);
    skill.dmg  = 0;
    skill.heal = player.health + (5 * player.level);
    skill.buff = player.defaultAttack + (3 * player.level);
    skill.duration = 2;
    skill.type = "Defence";
    skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);


            //Defensive-defence buff Based Tier 3
    skill.id = 17;
    Skill.name = "Vindicta";
    Skill.desc = "Let the enemies come, for with Vindicta, your defense stands as an unassailable wall.";
    Skill.cost = player.stamina - (32 * player.level);
    skill.dmg  = 0;
    skill.heal = player.health + (10 * player.level);
    skill.buff = player.defaultDefence + (4 * player.level);
    skill.duration = 2;
    skill.type = "Defence";
    skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);



         //Defensive-Leach Shield buff Based Tier 3
    skill.id = 18;
    Skill.name = "Shell of Meropide";
    Skill.desc = "A shimmering barrier manifests, warding off attacks and inflicting damage upon each assailant foolhardy enough to breach its sanctity.";
    Skill.cost = player.stamina - (40 * player.level);
    skill.dmg  = player.defaultDefence + (30 * player.level);
    skill.heal = player.health + (10 * player.level);
    skill.buff = player.stamina + (20 * player.level);
    skill.duration = 2;
    skill.type = "Defence";
    skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);

           //Defensive-Sheild thorn buff Based Tier 3
    skill.id = 19;
    Skill.name = "Shield of Thorns";
    Skill.desc = "Weaves a defensive tapestry of nature's vengeance. each hits taken, retaliates against assailants..";
    Skill.cost = player.stamina - (38 * player.level);
    skill.dmg  = (2 * player.defaultDefence);
    skill.heal = 0;
    skill.buff = 0;
    skill.duration = 3;
    skill.type = "Defence";
    skill.isMultiple = true;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);
          //Defensive-Buff buff Based ult
    skill.id = 20;
    Skill.name = "Freedom Speech";
    Skill.desc = "'From the moment I was born, those stifling walls were the farthest I could see. Water that glows like fire. Fields of ice. Sandy snowfields. To witness all that..Was to know the greatest freedom this world could offer. We're here, We're FREE.'";
    Skill.cost = player.stamina - (40 * player.level);
    skill.dmg  = 0;
    skill.heal = player.health + (player.level * 5);
    skill.buff = player.defaultAttack + (player.level * 55) ;
    skill.duration = 2;
    skill.type = "Defence";
    skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);

    //Defensive-defence buff Based ult
      skill.id = 21;
    Skill.name = "Guardian's Embrace";
    Skill.desc = "Feeling determined to protect those who you've cherished, forms a spiritual manifestation similar to a certain shield hero";
    Skill.cost = player.stamina - (40 * player.level);
    skill.dmg  = 0;
    skill.heal = player.health + (player.level * 10);
    skill.buff = player.defaultDefence + (player.level * 65) ;
    skill.duration = 3;
    skill.type = "Defence";
    skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);

//Defensive-Leach sheidl Based ult
      skill.id = 22;
    Skill.name = "Gate of Babylon";
    Skill.desc = "Searching for a true meaning of pleasure, One ready to sacrifice everything to gain it.";
    Skill.cost = player.stamina - (50 * player.level), player.health + (15 * player.level);
    skill.dmg  = player.health + (40 * player.level);
    skill.heal = player.health + (player.level * 20);
    skill.buff = player.defaultDefence + (player.level * 20) ;
    skill.duration = 2;
    skill.type = "Defence";
    skill.isMultiple = false;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);

    //Defensive-offence Based ult
      skill.id = 23;
    Skill.name = "Iron Fortress of Kabaneri";
    Skill.desc = "Exo Skeleton suit made of iron while trying to resist a mysterious virus and becoming something else, enhancing their skin alike of sharp thorns and their heart plated with steel.";
    Skill.cost = player.stamina - (40 * player.level), player.health + (25 * player.level);
    skill.dmg  = (player.defaultDefence * 1.5) + (30 * player.level);
    skill.heal =0;
    skill.buff = 0;
    skill.duration = 3;
    skill.type = "Defence";
    skill.isMultiple = true;
    adrClass = createNewClassNode(cls);
    adrSkill = createNewSkillNode(Skill);
    addSkill(ST,adrSkill);
    skill(adrClass) = adrSkill;
    addClass(CT,adrClass);
}
void initiatePlayer(playerList &PL){
    createPlayerList(PL);
    Player.name = "Mike";
    Player.Class = "Newbie";
    Player.defaultAttack = 10;
    Player.defaultDefence = 10;
    Player.health = 20;
    Player.speed = 10;
    Player.stamina = 10;
    Player.xp = 0;
    Player.level = 1;
    Player.nextLevel = 10;
    adrPlayer = createNewPlayerElement(Player);
    addPlayer(PL,adrPlayer);
    changePlayerClass(Player.name,"Newbie");



}
void initiateMenu(){
    mainmenu();
    introduction();
}
