#include "menu.h"
void print(string text[100], int i, bool interactable){
    string x = text[i];
    if(top(Menu) > 0){
        cout << "[" << position[0] << "," << position[1] << "]" << endl;
    }
    if(i != 0){

        for(int j = 0; j < i; j++){
            cout << text[j] << endl;
        }

    }
    for( int i = 0; x[i] != '\0'; i++ ) {
        cout << x[i];
        if( x[i] == '!' || x[i] == '.')
            Sleep(10 + rand() % 10);
        else
            Sleep(10 + rand() % 10);
        if (_kbhit()) {
            while (_kbhit()) {
                _getch();
            }
            for(int j = i+1; x[j] != '\0';j++){
                cout << x[j];
            }
            break;
        }
    }
    if(!interactable){
        cout << " " << endl;
        cout <<"Ketik mana saja untuk lanjut"<< endl;
        getch();
        system("cls");
    }

}




void createMenuStack(menuStack &S){
    top(S) = 0;
}
bool isMenuEmpty(menuStack S){
    return top(S) == 0;
}
void pushMenu(menuStack &S, int x){
    top(S)++;
    S.info[top(S)] = x;
}
void popMenu(menuStack &S){
    top(S)--;
}
void printStack(menuStack &S){
    for(int i = 1; i <= top(S);i++){
        cout << S.info[i];
    }
}




void splashScreen(){
    system("cls");
    cout << " __| |____________________________________________| |__\n"
"(__   ____________________________________________   __)\n"
"   | |           Welcome To  Brave Hearts:        | |\n"
"   | |               Journey to the               | |\n"
"   | |              Lands of Erudera              | |\n"
"   | |                                            | |\n"
"   | |                                            | |\n"
"   | |                                            | |\n"
" __| |____________________________________________| |__\n"
"(__   ____________________________________________   __)\n"
"   | |                                            | |"
"                                   \n"
"                 ---------------------------\n"
"                 |1. Permainan Baru         |\n"
"                 ---------------------------\n"
"                 |2. Lanjutkan Permainan    |\n"
"                 ---------------------------\n"
"                 |3. Lihat Data Game        |\n"
"                 ---------------------------\n"
"                 |4. Keluar                 |\n"
"                 ---------------------------\n"
"                   Tentukan Pilihan kamu:                  \n"
"                              ";
    int menuChoice;
    do{
        cin >> menuChoice;
        switch(menuChoice){
        case 1:
            system("cls");
            introduction();
            break;
        case 2:
            cout << "Coming soon\n";
            break;
        case 3:
            pushMenu(Menu,5);
            break;
        case 4:
            break;
        default:
            cout << "          Pilihan tidak valid. Tentukan Pilihan kamu:                  \n                              ";
            break;
        }
    }while(menuChoice < 0 || menuChoice > 4);
}
void introduction(){
    string x[100];
    player newPlayer;
    addPlayer(PL,createNewPlayerElement(newPlayer));
    x[0] = "Selamat datang pemberani, di dunia mistis Eldoria! Sebuah tanah yang penuh dengan sihir, makhluk mitos, kejahatan, dan dihiasi dengan harta karun yang tak terhitung jumlahnya. Angin takdir membawamu ke kota kecil Everhaven, di mana sebuah ramalan kuno meramalkan penemuan Pusaka yang Hilang—artefak kuat yang menyimpan kunci untuk mengembalikan keseimbangan dunia.\n";
    print(x,0,false);
    x[1] = "Saat kamu memasuki kota Everhaven yang ramai, jalan-jalan berkerikil dan bangunan-bangunan berkerangka kayu bergema dengan kisah-kisah pahlawan dan bisikan kegelapan yang akan datang. Penduduk kota yang tentram sedang menjalani hidup mereka sendiri-sendiri, dengan tanpa kesadaran adanya bahaya dalam dunia Eldoria. Namun, suatu berita yang akan merubah segalanya dalam kota Everhaven. \n";
    print(x,1,false);
    x[2] = "Sekarang, pahlawan yang berani, saatnya bagi Anda untuk masuk ke dalam karakter Anda. Apa nama Anda, yang akan dinyanyikan dalam balada sepanjang negeri? Ucapkan dengan lantang, dan biarkan namamu terukir dalam gulungan sejarah Eldoria.\n";
    print(x,2,true);
    cout << "\nMasukkan nama kamu: ";;
    getline(cin,MC.name);getline(cin,MC.name);
    system("cls");
    x[3] = "Ah, " + MC.name + ", sebuah nama yang membawa beban takdir. \n\nSaat Anda menjelajahi kota, Anda menemukan seorang pedagang tua misterius di sudut terpencil pasar. Dia merasakan percikan petualangan Anda. \n";
    print(x,3,false);
    x[4] = "Pedagang tua: Wahai petualang, saya merasa ada suatu potensial tinggi dalam diri anda, keberuntungan saja saya lagi kelebihan stok suatu barang yang anda mungkin tertarik, \n\nKemudian pedagang tua tersebut mengeluarkan 3 barang yang tidak familiar dimana-mana. \n ";
    print(x,4,false);
    x[5] = "Pedagang tua: Hehe, anak muda. Dari setiap barang ini memiliki kekuatan yang akan bisa membuatmu SANGAT kuabt dibanding siapapun dan bisa dibilang kekuatan yang KEKAL,\n";
    print(x,5,false);
    x[6] = "Pedagang tua: TAPI, jika kau sudah memilih, kau tidak akan bisa lagi berpisah dengan barangnya dan akan ada efek samping di setiap barang tersebut ini. Silahkan pilih salah satu dengan hati-hati: \n1. Shitty item\n2. Even more shitty item\n3. Item\n"; // show barang2 apa aja
    print(x,6,true);
    cout << "Pilih salah satu (1-3): "; // kan ad 3 pilihan nnt pilihan 4 kl bs mending kg ush pilih, jg show barang dh nnt yang ada apa aja
    int pickArtifact;
    string object;
    do{
        cin >> pickArtifact;
        if(pickArtifact == 1){
            object = "Shitty Item";
        }else if(pickArtifact == 2){
            object = "More Shitty Item";
        }else if(pickArtifact == 3){
            object = "Even more Shitty Item";
        }else{
        }cout << "Pilihan tidak valid. Pilih salah satu (1-3): ";
    }while(pickArtifact < 0 || pickArtifact > 3);
    addObjectToPlayer(PL,OL,MC.name,"Stone");

    x[7] = "\nKamu memilih: " + object +"\n\nPedagang tua: Muahahaha, sekarang nasib kau sudah tercatat dalam gulungan takdir\n"; //Jika kg pilih samsek, makany replyny "Kau adalah petualang yang konyol dan bodoh menolak kekuatan kekal, PERGILAH SEKARANG"

    print(x,7,false);

    x[8] = "Sekarang, kamu akan memulai sebagai newbie\n"; //kg ush krn skill awalan emg
    print(x,8,false);
    x[9] = "Dengan pemilihan class yang bijak, kamu merasa kekuatan magis mengalir dalam dirimu. Kini, sebagai seorang " + cls.name + ", petualanganmu di Eldoria dimulai.\n";
    print(x, 9, false);

    x[10] = "Berbekal senjata, sihir, dan tekad, kamu meninggalkan pasar menuju pintu gerbang kota. Angin sepoi-sepoi menyambut langkahmu, dan matahari terbenam memberikan warna keemasan pada langit.\n";
    print(x, 10, false);

    x[11] = "Perjalananmu di dunia Eldoria dimulai di kota kecil Everhaven. Dengan Pusaka yang Hilang sebagai tujuan utama, siapakah yang akan kamu temui, dan apakah takdirmu yang terpatri dalam gulungan sejarah ini?\n";
    print(x, 11, false);
    pushMenu(Menu,0);
}

void explore(){
    cout << "Explore to the unknown, who knows what you may encounter, be either friend, foe, or something else..";

    for(position[1] = 0; position[1] <= 10; position[1]++){
        if(position[0] == 1000){
            cout << "You died";
            getch();
            break;
        }
        if(position[1] == 0){
            encounter(0);
        }else{
            encounter(18);
        }
    }
    popMenu(Menu);
}
void encounter(int id){
    string x[100];
    string choice;
    system("cls");
    switch(id){
    case 0:
        x[0] = "==This is not a Story, but a Journey's End.==\n\n\nAfter your departure with the Old Merchant, ";
        x[0] = MC.pickArtifact ? x[0] + "you cant help but to ponder what kind of artifact was he giving you for and why was it free in the first place" : x[0] + "you can't help but to ponder what kind of artifact was he offering, and now you think this is the right choice because you sensed something wrong and malicious with the artifact in the firstplace";
        print(x,0,false);
        x[1] = "Before roaming around, you decided to prepare some stuff for the journey and bought provisions and appropriate gears for this land.";
        print(x,1,false);
        x[2] = "you got:\n	- 3 Provisions\n	- starting gear (basic sword, basic helm, basic chestplate, basic legplate)\n	- 1 Healing Potions";
        print(x,2,false);
        x[3] = "Now to embark for your own journey to bring peace back once more to the lands of Eldoria!\nChoose to where to go now:\n1. Left\n2. Right\nYour choice: ";
        print(x,3,true);
        do{
            cin >> choice;
            if(choice == "1"){
                path = "Left";
                position[0] -= 1;
            }else if(choice == "2"){
                path = "Right";
                position[0] += 1;
            }else{
                cout << "Wrong choice. Choose to where to go now:\n1. Left\n2. Right\nYour choice: " << endl;
            }
        }while(choice != "1" && choice != "2");
        break;
    case 1:
        x[0] = "==Astral Tavern== \n Special Encounter ";
        print(x,0,false);
        x[1] = "'Welcome to the Enchanted Wanderer, ready to serve weary travelers and intrepid rogues alike to step through its ethereal doors.' The atmosphere is an eclectic blend of 	whimsy and mystery, with flickering candles illuminating ancient tapestries that tell tales of forgotten realms.	" ;
        print(x,1,false);
        x[2] = "The barkeep, a spectral figure with a twinkle in their eye, serves drinks that bring courage, strength, and arcane insights" ;
        print(x,2,false);
        x[3] = "'Now fellow wanderer, what can I do for ye?'\n";
        print(x,3,false);
        x[4] = "1. Rent A Room  [Replenish your health, cost 5 gold piece]\n";
        print(x,4,false);
        x[5] = "2. Enchiridion [Upgrade to the next class of their choosing + skills] - 60 gold piece.   \n	3. Spectral Cloak [+20 Defence] - 20 gold piece. \n 4. Helm of Clairvoyant Insight [+20 health] - 20 gold piece.\n	5. Legplates of Ethereal Stride [+ 20 speed] - 20 gold piece. \n   6. Sword of Phantasmal Flames [+20 attack] - 20 gold piece.\n  7. Large Healing Potion[+MAX HEAL] - 8 gold piece. \n 8. Healing Potions [+ heal 2/3 Health] - 5 gold piece. \n  9. Defence Potions [+ 30 defence for 2 turns] - 5 gold piece. \n  	10. Attack Potions [+ 30 attack for 2 turns] - 8 gold piece. \n  11. Speed Potions [+ 30 Speed boost for 2 turn]- 8 gold piece. \n  12. Provisions [ + heal 1/3 Health] - 8 gold piece. \n  13. Entropic Die [charms, +15 attack, + 15 Speed] - 15 gold piece. \n  14. Amulet of Lifespring [charms, at the start of the battle (+ heal 10 for 2 turns)] - 20 gold piece.  \n  15. Ring of Attunement [charms,  + 10 attack, +10 defence, + 10 Speed, +10 health for perma] - 40 gold piece. \n  16. Leave. \n";
        print(x,5,false);
        x[10] = "'Welcome to the Enchanted Wanderer, ready to serve weary travelers and intrepid rogues alike to step through its ethereal doors.' The atmosphere is an eclectic blend of 	whimsy and mystery, with flickering candles illuminating ancient tapestries that tell tales of forgotten realms.	" ;
        print(x,6,true);
        do{
            cin >> choice;
            if (choice == "1"){
                cout << "Well goodnight then.. or morn, Im not sure myself because time here is irrelevant\n";
                MC.coin -= 5;
                MC.currentHealth = MC.health;
            }else if (choice == "2"){
                if(findObjectinInventory(inventory(mc(PL)),"Enchiridion") != NULL){
                    cout << "Sorry kid, you already bought it before\n";
                }else{
                    MC.coin -= 60;
                    addObjectToPlayer(PL,OL,MC.name,"Enchiridion");
                    //addObjectToPlayer(PL,OL,MC.name,"Enchiridion");
                    cout << "Huh.. I thought this thing was destroyed. what Else Can I get for ye?\n";
                }
            }else if (choice == "3"){
                if(findObjectinInventory(inventory(mc(PL)),"Spectral Cloak") != NULL){
                    cout << "Sorry kid, you already bought it before\n";
                }else{
                    MC.coin -= 20;
                    addObjectToPlayer(PL,OL,MC.name,"Spectral Cloak");
                    //addObjectToPlayer(PL,OL,MC.name,"Spectral Cloak");
                    cout << "good choice, I made em myself from a unicorn hairs (Animal Cruelty Free)\n";
                }
            }else if (choice == "4"){
                if(findObjectinInventory(inventory(mc(PL)),"Helm of Clairvoyant Insight") != NULL){
                    cout << "Sorry kid, you already bought it before\n";
                }else{
                    MC.coin -= 20;
                    addObjectToPlayer(PL,OL,MC.name,"Helm of Clairvoyant Insight");
                    //addObjectToPlayer(PL,OL,MC.name,"Helm of Clairvoyant Insight");
                    cout << "Good decision, I can even do a little bit of blacksmithing myself other than barkeeping and tailoring\n";
                }
            }else if (choice == "5") {
                if (findObjectinInventory(inventory(mc(PL)),"Legplates of Ethereal Stride") != NULL) {
                    cout << "Sorry kid, you already bought it before\n";
                } else {
                    MC.coin -= 20;
                     addObjectToPlayer(PL,OL,MC.name,"Legplates of Ethereal Stride");
                    // addObjectToPlayer(PL, OL, MC.name, "Legplates of Ethereal Stride");
                    cout << "I carved this piece with moon ore to rival some old basic stuff \n";
                }
            }else if (choice == "6") {
                if (findObjectinInventory(inventory(mc(PL)),"Sword of Phantasmal Flames ") != NULL) {
                    cout << "Sorry kid, you already bought it before\n";
                }else {
                    MC.coin -= 20;
                     addObjectToPlayer(PL,OL,MC.name,"Sword of Phantasmal Flames ");
                    // addObjectToPlayer(PL, OL, MC.name, "Sword of Phantasmal Flames");
                    cout << "Negotiated with Surtur myself to forge this beauty\n";
                }
            }else if (choice == "7") {
                MC.coin -= 8;
                addObjectToPlayer(PL,OL,MC.name,"L. Healing Potion");
                // addObjectToPlayer(PL, OL, MC.name, "Healing Potion");
                cout << "Ready to fight out with em big boys are ye?\n";
            } else if (choice == "8") {
                MC.coin -= 5;
                addObjectToPlayer(PL,OL,MC.name,"Healing Potion");
                // addObjectToPlayer(PL, OL, MC.name, "Healing Potion");
                cout << "Wise decision, a good traveler is an alive traveler\n";
            } else if (choice == "9") {
                MC.coin -= 5;
                addObjectToPlayer(PL,OL,MC.name,"Defence Potion");
                // addObjectToPlayer(PL, OL, MC.name, "Defence Potion");
                cout << "Make ya skin feels like a stone, in a good way\n";
            } else if (choice == "10") {
                MC.coin -= 5;
                addObjectToPlayer(PL,OL,MC.name,"Attack Potion");
                // addObjectToPlayer(PL, OL, MC.name, "Attack Potion");
                cout << "Don't do weird magix kids! Just try my brew, it'll feel like you could lift a mountain (don't actually do it)\n";
            } else if (choice == "11") {
                MC.coin -= 5;
                addObjectToPlayer(PL,OL,MC.name,"Speed Potion");
                // addObjectToPlayer(PL, OL, MC.name, "Speed Potion");
                cout << "Can't keep up with a carriage? try this one for size\n";
            } else if (choice == "12") {
                MC.coin -= 3;
                addObjectToPlayer(PL,OL,MC.name,"Provision");
                // addObjectToPlayer(PL, OL, MC.name, "Provision");
                cout << "Can't afford a Health Potion? try this alternative, the taste is bland but it's better than nothing right?\n";
            } else if (choice == "13") {
                if (findObjectinInventory(inventory(mc(PL)),"Entropic Die") != NULL) {
                    cout << "Sorry kid, you already bought it before";
                } else {
                MC.coin -= 20;
                addObjectToPlayer(PL, OL, MC.name, "Entropic Die");
                // addObjectToPlayer(PL, OL, MC.name, "Entropic Die");
                cout << "I forgot where I got it from, but I can guarantee you that this will help you.. I hope\n";
                }
            } else if (choice == "14") {
                if (findObjectinInventory(inventory(mc(PL)),"Amulet of Lifespring") != NULL) {
                    cout << "Sorry kid, you already bought it before";
                } else {
                    MC.coin -= 20;
                    addObjectToPlayer(PL, OL, MC.name, "Amulet of Lifespring");
                    // addObjectToPlayer(PL, OL, MC.name, "Amulet of Lifespring");
                    cout << "An amulet blessed by a Harvest Goddess in a land called Leaf Valley\n";
                }
            } else if (choice == "15") {
                if (findObjectinInventory(inventory(mc(PL)),"Ring of Attunement") != NULL) {
                    cout << "Sorry kid, you already bought it before";
                } else {
                    MC.coin -= 30;
                    addObjectToPlayer(PL, OL, MC.name, "Ring of Attunement");
                    // addObjectToPlayer(PL, OL, MC.name, "Ring of Attunement");
                    cout << "This thing will make you feel in balance every time you battle just as all things should be\n";
                }
            } else if (choice == "16"){
                cout << "Do be seein' ya come back again someday, may the astral thread weaves you a good journey";
            }else{
                cout << "That Item does not exist or I dont know what you are talkin about";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 16);
        break;
    case 2:
        x[0] = " == Insect Nest (Occurance) == " ;
        print(x,0,false);
        x[1] = "You accidentally step into a ground trap made of branches and leaves — the type you believe to be used only by the most old-fashioned hunter on planet Bled. You get to 	your feet, and the entrance of a nest is before you. " ;
        print(x,1,false);
    	x[2] = "What do you do now? \n  1. Stop at the entrance of the nest and attempt to climb out. \n  2. Go deeper into the insect nest. Wait for 'them.' \n  3. Enter the Insect Nest 	and snuff them out! " ;
        print(x,2,true);
        do{
            cin >> choice;
            if (choice == "1"){
                MC.coin += addGold(mc(PL),20);
                //[Walk Away and 10 gold piece];
            }else if (choice == "2"){
                MC.coin += addGold(mc(PL),20);
                MC.currentHealth -= 0.25 * MC.currentHealth;
                //[Lose 1/2 total health, obtain 30 gold piece]
            }else if (choice == "3"){
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Insect")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Insect")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Insect")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Insect")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Insect")))));
                fight(enemies);
                //[Enter battle with 5 insects];
                //enemy enemies[] = {info(findEnemy(EL,"A"),}
                cout << "you've found Legging made out of... sticky silk?\n";
                addObjectToPlayer(PL, OL, MC.name, "Sticky Silk Legplate");
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 3);
       MC.exp += addExp(mc(PL),250);
        break;
    case 3:
        x[0] = " ==  Exchanging Gifts (Transaction) == ";
        print(x,0,false);
        x[1] = "The Express of the Nameless makes a stop at Budley with an abundance of gifts in its rear carriage. A traveler wearing a felt hat is leaning against the front of the 	carriage. His clothes are tattered and his boots mud-stained.\n";
        print(x,1,false);
    	x[2] = "He approaches and waves at you. 'Akivili had an adventure with us under the guise of a civilian. We exchanged a lot of fun experiences during the journey.'\n";
        print(x,2,false);
    	x[3] = "1. Blessing Exchange. \n  2. Leave. — You're not interested.\n";
        print(x,3,true);
        do{
            cin >> choice;
            if (choice == "1"){
                addObjectToPlayer(PL, OL, MC.name, "Boon of Boons");
                cout << "OH! How Joyful it is to have a stranger in this time\n";
            }else if (choice == "2"){
                //gain [nothing and small xp]
                cout << "How disappointing encounter tis is\n";
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 4:
        x[0] = " ==  Jim Hulk and Hall Jim (Occurance) == " ;
        print(x,0,false);
        x[1] = "You are in a sprawling desert, and your vision is obscured by abandoned containers. Thick smoke permeates the air, and scrapped crate are dismantled into broken parts. The 	words 'Arasaka' are printed on one of the wood plank, almost no longer visible." ;
        print(x,1,false);
    	x[2] = "A rustling comes from the pile of trash behind you. You sense someone's eyes on you. As you turn around, you notice a vagrant hiding behind a crate. " ;
        print(x,2,false);
    	x[3] = "You approach the vagrant and find that it is bleeding with its legs twisted." ;
        print(x,3,false);
    	x[4] = "Hall Jim: 'We were hailed as the Amber Lord's Support Team. Karavan Keane trained us, used us, and ultimately abandoned us.' The vagrants shows you the items it is trying 	its best to keep safe." ;
        print(x,4,false);
        x[5] = "Hall Jim: 'Jim Hulk wont get up 4 days ago. Im about to pass out in a day and can no longer keep my brother's items. Please help me. Buy one of them out of here." + 	to_string(id);
        print(x,5,false);
    	x[6] = "1. Jim Hulk's collection. (requires 15 gold piece) \n  2. Jim Hall's Collection. [req 20 gold piece] \n  3. Sorry I cant help you.";
        print(x,6,true);
        do{
            cin >> choice;
            if (choice == "1"){

                MC.coin -= 10;
            cout << "Ah... thank you, with these we can live another day.";
                //[gain 'Tonic of Efficacious Chaos' Charm, +attack (20 * char lv) for 1 turn].
             addObjectToPlayer(PL, OL, MC.name, "Tonic of Efficacious Chaos");
            }else if (choice == "2"){
                cout << "As he handed over the chestplate, a faint smile played on his lips, reminiscent of the pride that once defined him.";
                MC.coin -= 20;
                addObjectToPlayer(PL, OL, MC.name, "Jim Hall's Chestplate");
            }else if (choice == "3"){
                cout << "I guess this is it for us.. sorry brother I've failed you";
                MC.coin += addGold(mc(PL),10);
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 5:
        x[0] = " ==  Nomadic Miners (Occurance) ==" ;
        print(x,0,false);
        x[1] = "It's dusk, and you're standing amid the heat waves. The atmosphere at the mines makes you dizzy, the mineral veins burning like melted butter." ;
        print(x,1,false);
        x[2] = "'Great Qlipoth, Aeon of Preservation... They can hear our voices.' The miners raise and dip their shovels like frenzied animals — or the faithful." ;
        print(x,2,false);
        x[3] = "Someone notices you — It's the 'lead miner' wearing a detector lamp. His arms are dark and muscular, and his lips are in a similar shade of ink. His hearty smile is very 	memorable. He has a gold tooth that ceaselessly expands and twists in your brain, till all you can see is his 'smile' — His lips and eyes fuse together, like the melting sludge of 	paint on a palette.\n" ;
        print(x,3,false);
        x[4] = "'Qlipoth, the blessing of the Amber Lord, preserves these leylines. You can have one of them.'";
        print(x,4,false);
        x[5] = "Choice: \n 1. Fight with the lead miner and grab the stuff!\n  2. Qlipoth's Blessing.\n";
        print(x,5,true);
        do{
            cin >> choice;
            if (choice == "1"){
                x[6] = "Very well... FOR QLIPOTH!!!\n";
                print(x,6,false);
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Miner")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Miner")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Miner")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Miner")))));
                fight(enemies);
            }else if (choice == "2"){
                cout << "May the Blessings of the Amber Lord be with you\n";
                //gets ['Ring of Amber' charm, + 15 defence perma]
                 addObjectToPlayer(PL, OL, MC.name, "Amber Ring");
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 6:
        x[0] = " == Hunter (Occurance) ==" ;
        print(x,0,false);
        x[1] = "You wander on the forest plains wrapped tightly in a your coat and sword strapped to your side. A man is coming your way. The tall and slender man has crimson curly hair 	and a freckled face. He is wearing leather boots and holding a rifle." ;
        print(x,1,false);
        x[2] = "He points at a rectangular building in the distance and says, 'The pharmaceutical branch of the Rhodes Island is hunting biological materials to manufacture precious 	drugs, and so are recruiting operators in the Snowlands.'";
        print(x,2,false);
        x[3] = "According to a secret source, the S-rank bounty for Snow Plains Leopard comes with a handsome reward. 'I'm surprised by how cold that place is. Could you lend me your 	coat?' 	You catch sight of the almost torn Mask of Reunion worn on his face to conceal his identity..." ;
        print(x,3,false);
        x[4] = "Now What do You do? \n  1. give him your coat [discard your current chestplate and obtain 30 gold piece] \n  2. I wont give you anything, and also I'll be taking ur 	stuff: enter battle,[enter batlle] \n  3. walk away [gain nothing]";
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
                //[discard your current chestplate and obtain 30 gold piece];
                cout << "Appreciate it stranger to another land\n";
            }else if (choice == "2"){
                cout << "Go ahead and try \n";
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Reunion Bounty Hunter")))));
                fight(enemies);
            }else if (choice == "3"){
                cout << "No thanks\n";
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 3);
       MC.exp += addExp(mc(PL),250);
        break;
    case 7:
        x[0] = " == Saleo(Battle) == \n";
        print(x,0,false);
        x[1] = "You enter a dimly-lit motel on Layton. At the stairway, you meet a massive guest who looks intimidating. Its body is formed by a transparent gel-like substance, and it has 	two heads knocking each other — one of them has red antennae, while the other has a white halo.\n";
      	print(x,1,false);
        x[2] = "You find your neighbor terrifying. It seems like you have to choose between its two personalities.'Our name is Saleo. Sal, the older one, is the demon. Leo, the younger 	one, is the angel. Which one do you want as your neighbor?'\n";
      	print(x,2,false);
        x[3] = "1. Pick Sal \n  2. Pick Leo \n";
        print(x,3,true);
        do{
            cin >> choice;
            if (choice == "1"){
                MC.health -= 0.2 * MC.health ;
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Sal")))));
                fight(enemies);

            }else if (choice == "2"){
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Leo")))));
                fight(enemies);
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 8:
        x[0] = " == Flash Bazar (Transaction) == " ;
        print(x,0,false);
        x[1] = "You arrive at the busiest bazaar in Varunix. One of the stalls catches your attention. The stall owner's face is obscured by the hood he is wearing. He sits cross-legged 	on a purple floor mat with various mineral bottles displayed around him." ;
        print(x,1,false);
    	x[2] = "'I'm the disciple of Oswaldo Schneider. Both of us are from the Fanaticism Department of Arasaka!',The man says out of nowhere. 'Do you know how commercial activities in 	these land started in the first place?'" ;
        print(x,2,false);
    	x[3] = "'Of course. It all started from our belief in Nanook. To help the Aeon in building the wall, the support team needed materials from different places across these lands of 	Erudera. We learned to exchange resources during that time,'he says while scratching his face. 'Now, let's try to exchange something. I guarantee you that whatever you've spent won't be in vain.'" ;
        print(x,3,false);
    	x[4] = "1. Purchase a metal Wish-In-A-Bottle. — (Consume 10 gold piece and obtain 1 'Good Value' Charms). 2. Purchase a silver ore Wish-In-A-Bottle. — (Consume 20 gold piece and 	obtain 1 'Surprising' equipment.) \n3. Leave. — You're not interested.\n" ;
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
                MC.coin -= 10;
                //[+ (10 * char lv)health, named "Good Value" charms.];
                cout << "Im sure you'll be pleased to have that\n";
                 addObjectToPlayer(PL, OL, MC.name, "'Good Value'");
            }else if (choice == "2"){
                MC.coin -= 20;

                //[+25 attack, sword named "Scarlet".];
                cout << "I'm *surprised* you picked that one";
                 addObjectToPlayer(PL, OL, MC.name, "Scarlet");
            }else if (choice == "3"){
                //gain [10 gold piece and small xp];
            }else{
                cout << "you cant do that";
            }
           MC.exp += addExp(mc(PL),250);
        }while(stoi(choice) < 0 || stoi(choice) > 3);
       MC.exp += addExp(mc(PL),250);
        break;
    case 9:
        x[0] = " == House of Nildis (Occurance) == " ;
        print(x,0,false);
        x[1] = "You sit at the card table across from a one-eyed dealer whose metal prosthetic legs are intertwined with the legs of the Nildis table. His torso runs through a hole in the 	center of the table with a pinball circling his waist." ;
        print(x,1,false);
    	x[2] = "He moves his eyeballs to look at you before bowing at you respectfully. Next, the dealer distributes the gold piece and shuffles the cards gracefully with his 2 wooden 	prosthetic arms." ;
        print(x,2,false);
    	x[3] = "'There is a certain chance that you will unfold the most wonderful memory of this world.' The dealer deals a stack of cards to you and adds, 'However, you might also reveal some mysterious affairs that aren't supposed to be made known. If you are unlucky, the consequences will be dire.'" ;
        print(x,3,false);
    	x[4] = "1. Flip the Card. (50% chance fighting 2 elite rogue) \n  2. walk away \n 3. Flip over the game table" ;
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"One-Eyed 'Kent'")))));
                fight(enemies);
                //(50% gains +20 defence, 50% gains +20 attack battle) Chestpiece ];
            }else if (choice == "2"){
                //[gain nothing and small xp]
            }else if (choice == "3"){
                cout << "Wise move, dead man";
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"One-Eyed 'Kent'")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Kent's Elite Rogue")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Kent's Elite Rogue")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Kent's Elite Rogue")))));
                fight(enemies);
            }else{
                cout << "you cant do that";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 3);
       MC.exp += addExp(mc(PL),250);
        break;
    case 10:
        x[0] = " == Insights from the Minstrels. (Transaction) == \n";
        print(x,0,false);
        x[1] = "A Minstrels approaches you. She makes a mischievous shushing gesture at you before lifting the curtain to the hall for you.\n";
        print(x,1,false);
    	x[2] = "Before these seven pots of incense kneel countless dancers from all over the stars, who are getting madder by the day. They prostrate themselves before the meeting hall, 	and sing and pray to the 13th self-strangler - there are already 13 of them. The dancers will lie prone before God, pleading to know their end after the cosmic dance ends.\n";
        print(x,2,false);
    	x[3] = "Here's a talisman about your fate. If you don't believe this type of thing, just treat it as a famous rumor of the cosmos. Deep down inside, you are tempted...\n";
        print(x,3,false);
    	x[4] = "1. Tell Fortune. [spend 30 gold piece]  \n  2. It's just a rumor, Leave. — You're not interested.\n";
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
                cout << "'What an interesting fate you've got there, be sure to come back after you succeeded teehee~'";
                MC.coin -= 30;
                //[25% obtaining, 'Bloodied Necklace' charms [if atleast 1 enemy killed, get + (20 * char lv) attack]]
                addObjectToPlayer(PL, OL, MC.name, "Bloodied Necklace");
            }else if (choice == "2"){
                //gain [nothing and small xp]
                cout << "Oh well.. be sure to come back next time~\n";
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 11:
        x[0] = " == Jester Pedler. (Transaction) == \n";
        print(x,0,false);
        x[1] = "You see an adorable jester waving at you. When you get near it, it speaks: 'This is a kingdom of me.. of sale! You can find everything you desire here!' On the board, you 	see medical, entertainment, and other services offered at affordable prices... \n";
        print(x,1,false);
    	x[2] = "or you can even buy my specialty, JAck-In-A-Box, who knows what you might get? and I could even a guranteed goldback especially for you.\n";
        print(x,2,false);
    	x[3] = "1. Purchase entertainment services. [5 gold piece]  \n  2. Try to haggle for his goofy ahh hat. [15 gold piece]  \n  3. Purchase a JAck-in-a-Box [20 gold piece]  \n  4. Leave. — You're not interested. ";
        print(x,3,true);
        do{
            cin >> choice;
            if (choice == "1"){
                MC.coin -=5;
                cout << "'Jolly goodshow my good man, pleasure doing business' \n";
                MC.currentHealth += 999;
            }else if (choice == "2"){
                MC.coin -=15;
                cout << "'Ugh fine *with a different deeper voice*' \n";
                //gain [Helmet Jester's Delight, +15 defence and +1 Crit counter]
                addObjectToPlayer(PL, OL, MC.name, "Jester's Delight");
            }else if (choice == "3"){
                MC.coin -= 20;
                cout << "As you open the box, a huge light came out of it and you hear a wind blowing through your ear \n";
                cout << "Inside the box there's a single note saying " << "Beware of the long eared Jester" << "'well.. that was a waste of gol- wait where did he even 	go?! ... f***..' Said to 	yourself";
                MC.exp += 650;
            }else if (choice == "4"){
                cout << "'What a real bummer you are' \n";
                //nothing
            }else{
                  cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 4);
       MC.exp += addExp(mc(PL),250);
        break;
        case 12:
            x[0] = " == Showman's Sleight. (Transaction) == " ;
            print(x,0,false);
            x[1] = "A Mourning Actor riding a cosmic elephant slowly comes into sight... She is still weeping for some reasons. Then, she dismounts the elephant and offers to perform a special magic show to you for free." ;
            print(x,1,false);
            x[2] = "She stuffs your 20 gold piece into four cups in front of you... Then, she quickly moves the cups around, and the show ends in an instant. The Actor then places her hand 	on her chest and politely asks you to choose a cup..." ;
            print(x,2,false);
            x[3] = "1. Select the cup on the left. \n  2. Select the cup on the right." ;
            print(x,3,true);
            cin >> choice;
        do{
            if (choice == "1"){
                cout << "'A nice eye, but a fair game is a fair game'\n";
                addObjectToPlayer(PL, OL, MC.name, "Tricster Gloves");
                //	get [equipment back and gained 'Trickster Gloves' charms, +15 speed]
            }else if (choice == "2"){
                cout << "'Too bad, don't be mad at me, that's just how the game is' \n";
                MC.coin -= 20;
                MC.exp += addExp(mc(PL),60);
                //[discard that equipment and gained 600 xp]
            }else{
                  cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 13:
        x[0] = "== Faring Hawkers. (Transaction) == \n";
        print(x,0,false);
        x[1] = "You bump into a struggling merchant at the road. He looks like an aged man. 'The economy on Varunix is in recession, and the bazaar is quiet and deserted. I do not know how to keep myself alive at this point' he says indifferently.\n";
        print(x,1,false);
    	x[2] = "'The price difference is the fees you have to pay for the lesson, and no one can be the exception. The rule of thumb in business is to buy low and sell high. Master it, and you will never suffer a loss in the future, They say..' he says indifferently. \n";
        print(x,2,false);
    	x[3] = "'I do not own much at this point, but will you take a look at my wares, it'll just take a few times of your day'. \n ";
        print(x,3,false);
        x[3] = "1. Purchase an 'Amber' bag. [15 gold piece]  \n  2. Purchase a 'Supernium' Bag [15 gold piece] \n  3. Leave. — You're not interested. ";
        print(x,3,true);
        do{
            cin >> choice;
            if (choice == "1"){
                cout << "I looted this one of from a battlefield I feel ashamed to this day, but a man's have to eat something. \n";
                addObjectToPlayer(PL, OL, MC.name, "Terra Sword");
                //get [Sword, 'Terra Sword' ,(Leech Effect and +10 attack)];
            }else if (choice == "2"){
                cout << "'I've never dared to it peeked once, I found it on a ruined blacksmith village in the far region of Lumaroth ' \n";
                addObjectToPlayer(PL, OL, MC.name, "Titanium Chestplate");
                //get [Chestplate, 'Titanium Chestplate' (+20 defence and +10 attack)]]
            }else if (choice == "3"){
                cout << "*he lets out a huge sigh* Another day, another bad luck for the 'wicked' \n";
                //nothing
            }else{
                  cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 3);
       MC.exp += addExp(mc(PL),250);
        break;
    case 14:
        x[0] = " == Mad Jester. (Boss Battle) == " ;
        print(x,0,false);
        x[1] = "A short, pudgy imp with a round gray face, elven ears, clown-like eyes with small yellow pupils, and a large smiling mouth with yellow, sharp teeth. He has a long, purple 	tongue which can be seen either when he laughs. He has a purple tail shaped like a capital letter J. suddenly approaches you" ;
      	print(x,1,false);
        x[2] = "'Nice to meet you, the name's Jevil and I know who you are' He then snaps hit fingers" ;
      	print(x,2,false);
        x[3] = "A single white flash temporarily blinds you and suddenly He materialize a white space with you in it, He then invites the party to enter. Jevil waits at the far right of 	the area, and wants to 	'PLAY' a 'SIMPLE NUMBERS GAME. WHEN YOUR HP DROPS TO 0, YOU LOSE!'" ;
        print(x,3,false);
        x[4] = "1. LET'S PLAY! LET'S PLAY! LET'S PLAY! (Intent to beat Jevil). \n  2. LET'S PLAY! LET'S PLAY! LET'S PLAY! (Intent to pacify Jevil)" ;
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
                cout << "*The figures jumps at you with full speed*, 'GET READY TO HAVE FUN FUN FUN!'";
                //[fight Jevil (hell)
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Jevil")))));
                fight(enemies);
                cout << "'HA HA HA. WHAT FUN!!!, YOU'RE FAST, FAST, STRONG, STRONG. BUT THERE ARE YET FASTER, YET STRONGER. TAKE ME AND DO YOUR STRONGEST---!' \n";
                addObjectToPlayer(PL, OL, MC.name, "Devilsknife");
                //get [Sword, Devilsknife, [+50 attack] and gained 1200 xp]
            }else if (choice == "2"){
                cout << "*The figures jumps at you with full speed*, 'GET READY TO HAVE FUN FUN FUN!'";
                //[fight Jevil (hell)
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Jevil")))));
                fight(enemies);
                cout << "'WHAT FUN!! I'M EXHAUSTED!! YOU KID TIRED ME UP!!, NOW I WILL SLEEP FOR THE OTHER 100 YEARS. TAKE THIS AND DO YOUR STRONGEST---!' \n";
                addObjectToPlayer(PL, OL, MC.name, "Jevilstail");
                //get [Sword, Jevilstail, [+25 attack and +25 speed] and gained 1200 xp]
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 15:
        x[0] = " == Saleo. (Battle) == " ;
        print(x,0,false);
        x[1] = "You enter a dimly-lit motel on Layton. At the stairway, you meet a massive guest who looks intimidating. Its body is formed by a transparent gel-like substance, and it has 	two heads knocking each other — one of them has red antennae, while the other has a white halo. \n" ;
      	print(x,1,false);
        x[2] = "You find your neighbor terrifying. It seems like you have to choose between its two personalities.'Our name is Saleo. Sal, the older one, is the demon. Leo, the younger 	one, is the angel. Which one do you want as your neighbor?' \n" ;
      	print(x,2,false);
        x[3] = "1. Pick Sal \n  2. Pick Leo " ;
        print(x,3,true);
        do{
            cin >> choice;
            if (choice == "1"){
                MC.currentHealth -= 0.2*MC.currentHealth;
           //[-20% health]
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Sal")))));
                fight(enemies);
            //get [Charm, Yin Charm]
            }else if (choice == "2"){
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Leo")))));
                fight(enemies);
            //get [Charm, Yang Charm]
            }else{
            cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 16:
        x[0] = " == Rock, Paper, Bullets?(Battle) == " ;
        print(x,0,false);
        x[1] = "The ringmaster before you, with a curved mustache and a distinctavely pants, is running a performance. While it seems to be a normal performance, only you know that you 	are playing a game of rock-paper-scissors with it.  \n" ;
      	print(x,1,false);
        x[2] = "'There is an 82.49% chance of you playing rock in the first game, and a 94.61% of you playing scissors in the second. If you choose to flip the table with me and battle 	with the other perfromer, there is a 99.37% of me NOT putting a bullet through your head.'  \n" ;
      	print(x,2,false);
        x[3] = "'But if you leave some gold pieces behind, your chance of survival is 100%.' they are waiting for your response. \n" ;
        print(x,3,false);
        x[4] = "1. Fight for the 0.63% chance. \n  2. Pick 100% safe" ;
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
            cout << "'THE SHOW MUST CONTINUE!!' *shouts the ring leader* \n";
             enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Ring Master")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Strong Performer")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Strong Performer")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Strong Performer")))));
                fight(enemies);
            }else if (choice == "2"){
            cout << "A good lad knows where he belongs.. NOT IN CIRCUS HA! \n";
            MC.coin -= 20;
            //[lose 20 gold piece]

            }else{
            cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 17:
        x[0] = " == We Are Cowboys. (Battle) == " ;
        print(x,0,false);
        x[1] = " You are grazing grass on the sun-baked earth when a bunch of beefy guys comes your way. They are the street bandits who wreak havoc wherever they go. They are followed by a team of mercenaries. \n"  ;
      	print(x,1,false);
        x[2] = "'We're the last cowboys!' Shouts the leader who flails his arms happily. The red ibis armbands indicate their submission to the royal family. You believe they are the 	royal bandits. \n" ;
      	print(x,2,false);
        x[3] = "'Leave your gold coins behind. We need funds to oil the development of the city. Generosity is in line with the cowboy's spirit!' Scowling at the shameless bandits, you bite off the grass with your mouth... \n" ;
        print(x,3,false);
        x[4] = "1.  Let them experience the real 'cowboy'.  \n  2. Pay." ;
        print(x,4,true);
        do{
        cin >> choice;
        if (choice == "1"){
		cout << "So'd be it partner \n";
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Cowboy")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Cowboy")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Cowboy")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Cowboy")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Cowboy")))));
                fight(enemies);

        }else if (choice == "2"){
		cout << "You ain't so bad, after all we're just a fellow goodmen \n";
        MC.coin -= 0.5*MC.coin;
        }else{
            cout << "you cant do that";
        }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
    case 18:
        x[0] = " == Dueling Tavern. (Battle) == " ;
        print(x,0,false);
        x[1] = "You reach an Elway-style tavern with a lively atmosphere." ;
      	print(x,1,false);
        x[2] = "'Welcome to Tavern World's End.' Bragi, the bartender, bows deeply to the patrons and continues, 'We only serve customers with a sense of humor.' \n  " ;
      	print(x,2,false);
        x[3] = "'In keeping with Aha's will, we will have some fun next. Mr. France and his team of bodyguards will be the next to join the arena. His opponent will be Avila. He and his 	mercenaries are burly and not to be underestimated! Who else is coming? Who's up for the 78,201st round?' \n " ;
        print(x,3,false);
        x[4] = "1.Challenge Mr. France's security team.  \n  2. Challenge the burly Avila's mercenary company  \n  3. Fight both together! \n" ;
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
            //[enter battle with 2 Security Guards
            enemyList enemies;
            createEnemyList(enemies);
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Security Guard")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Security Guard")))));
            fight(enemies);
            }else if (choice == "2"){
            enemyList enemies;
            createEnemyList(enemies);
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Mercenary")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Mercenary")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Mercenary")))));
            fight(enemies);
            }else if (choice == "3"){
            enemyList enemies;
            createEnemyList(enemies);
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Security Guard")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Security Guard")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Mercenary")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Mercenary")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Mercenary")))));
            fight(enemies);
            }else{
            cout << "you cant do that";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 3);
       MC.exp += addExp(mc(PL),250);
        break;
    case 19:
         x[0] = " == Beast Horde. (Battle) == " ;
        print(x,0,false);
        x[1] = "You encounter a group of ancient bloodthirsty behemoths in an ancient city of an abandoned lands. Their hot, steamy breaths brush against your face... \n" ;
      	print(x,1,false);
        x[2] = "You notice signs of mutation on one of them... Its skin is covered by a layer of gilded hard shell, and it seems to be suffering from the mutation. \n" ;
      	print(x,2,false);
        x[3] = "You stare straight into its droopy eyes. Its whiskers are moving up and down. You notice it is protecting some cubs behind it.. \n" ;
        print(x,3,false);
        x[4] = "1. Help the young beasts 'get free.'  /n  2. Take care of the adult beast's 'pain.' \n" ;
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
                cout << "Slaughter the Younglings";
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Young Beast")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Young Beast")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Young Beast")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Young Beast")))));
                fight(enemies);
            }else if (choice == "2"){
                cout << "The Creature growls with frenzied eyes";
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Adult Beast")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Adult Beast")))));
                fight(enemies);
                addObjectToPlayer(PL, OL, MC.name, "Beastskin Legging");
            }else{
                cout << "you cant do that";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);

       MC.exp += addExp(mc(PL),250);
        break;
     case 20:
        x[0] = " == Runic Chest. (Occurance) == " ;
        print(x,0,false);
        x[1] = "As you traverse through the dense Enigma Woods, the air thickens with an eerie silence. The trees cast long shadows, and an uneasy feeling settles in the pit of your stomach. Suddenly, you stumble upon a clearing, and in its center stands two chest, seemingly left behind by a forgetful adventurers. \n" ;
      	print(x,1,false);
        x[2] = "The chest is made of dark mahogany, adorned with intricate carvings, one with a Blue Paint and the other one with Red Paint. \n" ;
      	print(x,2,false);
        x[3] = "Curiosity piqued, you approach the twin chests cautiously. The carvings on the dark mahogany surface seem to depict ancient symbols and arcane patterns. As you examine them closely, you notice that the Blue Painted chest bears symbols reminiscent of flowing water, while the Red Painted chest is adorned with fiery motifs.\n" ;
        print(x,3,false);
        x[4] = "1. Open the Blue Painted Chest. \n  2.  Open the Red Painted Chest. \n  3. Try to open both chest at the same time \n   4. Tiptoe away slowly, avoiding any confrontation." ;
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
            enemyList enemies;
            createEnemyList(enemies);
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Blue Mimic")))));
            fight(enemies);
            MC.coin += 10;
            }else if (choice == "2"){
            enemyList enemies;
            createEnemyList(enemies);
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Red Mimic")))));
            fight(enemies);
            MC.coin += 15;
            }else if (choice == "3"){
            enemyList enemies;
            createEnemyList(enemies);
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Blue Mimic")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Red Mimic")))));
            fight(enemies);
            }else if (choice == "4"){
                cout << "You ran away!";
            }else{
                cout << "you cant do that";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 4);
       MC.exp += addExp(mc(PL),250);
        break;
     case 21:
        x[0] = " == Grassy Tent. (Transaction) == " ;
        print(x,0,false);
        x[1] = "As you traverse through the dense Enigma Woods, the air thickens with an eerie silence. The trees cast long shadows, and an uneasy feeling settles in the pit of your stomach. Suddenly, you stumble upon a clearing, and in its center stands a chest, seemingly left behind by a forgetful adventurer. \n" ;
      	print(x,1,false);
        x[2] = "You go shopping in town of Nearbrought, where a sign leads into the teepee made out of grass as you had heard it was 'the place to get swords'. You're impressed that it stayed stable long enough \n" ;
      	print(x,2,false);
        x[3] = "As you enter the tent, you hear an eary voice saying 'close the curtain behind you please', A Grassy Wizard greets you 'Heard you searching for a new sword have ye? look no further, just a measly 15 gold will help you much in your travels'. \n" ;
        print(x,3,false);
        x[4] = "You're very confused on why such claims would just go for 15 gold pieces, he insist on you trying it out first \n" ;
      	print(x,4,false);
        x[5] = "The sword is very sharp, like every swing produce an aftersound of wind slicing in air, even though it's just made of grass. \n" ;
        print(x,5,false);
        x[6] = "1. Buy it [Requires 15 gold piece] \n 2. Leave " ;
        print(x,6,true);
        do{
            cin >> choice;
            if (choice == "1"){
                MC.coin -= 15;
                addObjectToPlayer(PL, OL, MC.name, "Grass Sword");
                cout << "Wise decision, and also no refunds!";
            }else if (choice == "2"){
                cout << "'Not even worthy of the sword'";
                cout << "You left the tent";
            }else{
                cout << "you cant do that";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
     case 22:
        x[0] = " == Enchanting Song. (occurance) == " ;
        print(x,0,false);
        x[1] = "Deep within the ethereal Whispering Grove, where moonlight bathes the towering trees in an iridescent glow, you stumble upon a glade adorned with bioluminescent flowers. The air is thick with the sweet scent of blooming petals, and the tranquil melody of the grove seems to resonate with the heartbeat of the forest.\n" ;
      	print(x,1,false);
        x[2] = "As you traverse the glade, the atmosphere changes, and a hauntingly beautiful chorus of voices fills the air. Emerging from the shadows, three enchanting figures appear, their features an ethereal blend of grace and allure. Each figure possesses a voice that could rival the most enchanting symphonies. \n" ;
      	print(x,2,false);
        x[3] = "'Welcome, traveler, to the Whispering Grove,' they sing in harmony, their voices weaving a hypnotic melody. 'Our song transcends time and space, and we invite you to join us in a dance of eternal bliss. Let the music carry you away.'" ;
        print(x,3,false);
        x[4] = "Their eye's gleam with an otherworldly allure, and the tendrils of their enchanting song wrap around your senses. A captivating aura surrounds them, promising an experience beyond mortal comprehension. \n" ;
      	print(x,4,false);
        x[5] = "1. 1.Yield to the allure and join the Sirens in their mesmerizing dance. \n 2.Politely decline the invitation and exit the glade. " ;
        print(x,5,true);
        do{
            cin >> choice;
            if (choice == "1"){
            cout << "As you enjoying your time as time fleeting throughout the night, one Siren trying to eat your head, and now you realised you stepped on a trap";
            enemyList enemies;
            createEnemyList(enemies);
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Siren")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Siren")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Siren")))));
            addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Siren")))));
            addObjectToPlayer(PL, OL, MC.name, "Ring of Tempting Tune");
            fight(enemies);
            }else if (choice == "2"){
            cout << "'Aww, Hun don't go just yet'. The alluring voices kept reaching farther and farther as you run to the opposite direction";
            MC.currentHealth -= 0.2*MC.currentHealth;

            }else{
            cout << "you cant do that";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
     case 23:
        x[0] = " == Moonlight's End. (Boss Battle) == " ;
        print(x,0,false);
        x[1] = "In the heart of the desolate Graveyard of Sayuki, where the moonlight struggles to penetrate the thick canopy of twisted trees, you come across an ancient crypt. The air is heavy with the scent of decay, and the ground beneath your feet seems to echo with the whispers of long-forgotten souls.\n" ;
      	print(x,1,false);
        x[2] = "As you approach the crypt's entrance, an otherworldly chill permeates the air, sending shivers down your spine. The rusty iron gates creak open on their own accord, revealing a dimly lit chamber adorned with tattered banners and faded regal insignias. \n" ;
      	print(x,2,false);
        x[3] = "At the far end of the crypt, seated upon a spectral throne of bone and adorned in tattered royal garments, is the fabled Skeletal King, Egress. Hollow eyes burn with an ethereal flame, and a crown of tarnished silver rests upon its skull. The Skeletal King slowly rises, and the sound of rattling bones fills the chamber like a macabre symphony. \n" ;
        print(x,3,false);
        x[4] = "'Ancient ruler of the twilight realm, keeper of the cryptic echoes,' it intones with a voice that seems to emanate from the depths of the underworld. 'The hour has come for a dance with the shadows, mortal intruder.' \n" ;
      	print(x,4,false);
        x[5] = "1. Engage in battle with the Skeletal King! (Attempt to exorcise it) \n 2. Engage in battle with the Skeletal King! (Attempt to defeat it) " ;
        print(x,5,true);
        do{
            cin >> choice;
            if (choice == "1"){
                //start bdengan 1 skeletal king dan 2 goons, si king bs summon tiap 4 turns
                cout<< "This place will be your final rest";
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeletal King")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeleton Goon")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeleton Goon")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeleton Goon")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeleton Goon")))));
                fight(enemies);
                addObjectToPlayer(PL, OL, MC.name, "Living Bone");
                 MC.coin += 20;
            // [Enter a challenging battle with the Skeletal King [HELL]. If victorious, gain (charms, "Living Bone", + 3 Crit counter and extra 20 gold pieces.]
            cout << "A soft voice saying 'Thank You' slowly fades, the chamber grows silent once more"; //jika menang
            }else if (choice == "2"){
                cout<< "This place will be your final rest";
                enemyList enemies;
                createEnemyList(enemies);
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeletal King")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeleton Goon")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeleton Goon")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeleton Goon")))));
                addEnemy(enemies,(createNewEnemyElement(info(findEnemy(EL,"Skeleton Goon")))));
                fight(enemies);
                addObjectToPlayer(PL, OL, MC.name, "Regal Specter Crown");
                MC.coin += addGold(mc(PL),30);
                // [Enter a challenging battle with the Skeletal King [HELL]. If victorious, gain (helmt,"Regal Specter Crown" +20 	attack and +25 defence) and 30 gold pieces.]
            cout << "'Within a Millenia of waiting, a worthy foe comes and replace me in my throne...' *The giant skeletal figures becomes a spec of dust*";
            }else{
            cout << "you cant do that";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
       MC.exp += addExp(mc(PL),250);
        break;
            case 24:
            x[0] = " == Dreamscape (Fated Encounter) == " ;
            print(x,0,false);
            x[1] = "You walk into the most adorable Kiliro Fish Restaurant on Pier Point — a place made of a giant bubble in the shape of a fish eye. Through the curved glass, you can see the subspace barrier. You have a good time in the pleasant afternoon sunshine. \n" ;
            print(x,1,false);
            x[2] = "While the other customers are enjoying the piscatorial ultrasonic wave cerebral fascia massage, you stuff a fish eye into your mouth and plunge into a social dreamland. Pier Point is seeing a period of development during which the country's currency will be raining down regularly from the sky. You are thrilled, as you own the Arasaka's bonds. \n" ;
            print(x,2,false);
            x[3] = "Your mind returns to reality when the fish eye is fully digested in your stomach. It's time for you to go to work, but you are reluctant to move... \n" ;
            print(x,3,false);
            x[4] = "if have artifact: 1. Catch more fish eyes...  \n 2.Return to work. " ;
            print(x,4,true);
            x[5] = "if not have artifact: 1.  Swallow the other fish eye and continue to enjoy the massage. \n  2. Return to work." ;
            print(x,5,true);
        do{
            cin >> choice;
            if(MC.artifact == 1){ //ketika ada
                if (choice == "1"){
                   // [Obtain a 'Fissured [Artifact name]', (5 * char lv) -health but (10*char lv) attack]
                   MC.exp += 1000;
                    //[1000 xp]
                }else if (choice == "2"){
                   MC.exp += addExp(mc(PL),1000);
                   MC.coin += addGold(mc(PL),30);
                    //[1000 xp]
                    //[30 gold piece]
                }else{
                    cout << "you cant do that";
                }
            }else{
                if (choice == "1"){
                    MC.exp += 1000;
                    MC.coin -= 0.5 * MC.coin;
                    addObjectToPlayer(PL, OL, MC.name, "Night Sword");
                    //[1000 xp]
                    //[-50% gold piece, obtain Night Sword, +30 attack]
                }else if (choice == "2"){
                    MC.coin += 30;
                    MC.exp += 1000;
                    //[1000 xp]
                   // [30 gold piece]
                }else{
                    cout << "you cant do that";

                }
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
    break;
}

    if(id != 0){
        cout << "\nThe path diverged again. What's your next step?" << endl;
        cout << "1. Going Left" << endl;
        cout << "2. Going Right" << endl;
        cout << "3. Check Stats" << endl;
        cout << "4. Give up" << endl;
        cout << "Your choice? (1-4): ";

        do{
            cin >> choice;
            string confirm;
            if(choice == "1"){
                path = "Left";
                position[0] -= 1;
            }else if(choice == "2"){
                path = "Right";
                position[0] += 1;
            }else if(choice == "3"){
                showPlayerInfo(info(mc(PL)));
                cout << "\nWhat's your next step? (1-4): ";
            }else if(choice == "4"){
                cout << "Are you sure? (y/n): ";
                do{
                    cin >> confirm;
                    if(confirm == "y"){
                        position[0] = 1000;
                        choice = "1";
                    }else if(confirm == "n"){
                        cout << "\nWhat's your next step? (1-4): ";
                    }else{
                        cout << "Wrong choice. Are you sure? (y/n): ";
                    }
                }while(confirm != "y" && confirm != "n");
            }else{
                cout << "Wrong choice. Your choice? (1-4): ";
            }
        }while(choice != "1" && choice != "2");
    }
}
void stats(){

    getch();
    popMenu(Menu);
}

void checkInventory(){
    cout << "Use Item";
    getch();
    popMenu(Menu);
}
void interactorTalk(){
    cout << "Interact with an object or something else";
    getch();
    popMenu(Menu);
}
//5 strsny situational
void shop(){
    cout << "Buy something from the shop";
    getch();
    popMenu(Menu);
}
//ni nnt ketika battle phase
void fight(enemyList enemies){
    string x[100];
    system("cls");
    x[0] = " -=+=-\nBATTLE!\n -=+=-\n";
    print(x,0,false);
    int id = roll();
    bool fleed = false;
    int sumEnemy = 0;
    enemyAddress adrEnemy = first(enemies);

    while(adrEnemy != NULL){
        sumEnemy++;
        adrEnemy = next(adrEnemy);
    }
    int randomEnemy = (roll() % sumEnemy);
    adrEnemy = first(enemies);
    for(int i = 0; i < randomEnemy;i++){
        adrEnemy = next(adrEnemy);
    }
    string introEnemy = info(adrEnemy).name;
    switch(id) {
    case 1:
        x[1] = introEnemy + " seems feisty tonight.\n";
        break;
    case 2:
        x[1] = introEnemy + " is angry!\n";
        break;
    case 3:
        x[1] = MC.name + " is kind of quirky.\n";
        break;
    case 4:
        x[1] = MC.name + " is doing a little bit of trolling.\n";
        break;
    case 5:
        x[1] = introEnemy + " seems feisty tonight.\n";
        break;
    case 6:
        x[1] = introEnemy + " eyes " + MC.name + " with a mix of curiosity and hostility.\n";
        break;
    case 7:
        x[1] = MC.name + " and " + introEnemy + " exchange a few sarcastic remarks before the battle.\n";
        break;
    case 8:
        x[1] = "As " + MC.name + " approaches, " + introEnemy + " snickers and says, 'You're in for a surprise.'\n";
        break;
    case 9:
        x[1] = "The tension is palpable as " + MC.name + " and " + introEnemy + " share a moment of awkward silence.\n";
        break;
    case 10:
        x[1] = "In a strange turn of events, " + introEnemy + " starts memeing, leaving " + MC.name + " utterly confused.\n";
        break;
    case 11:
        x[1] = MC.name + " retorts with a well-timed meme, causing " + introEnemy + " to reconsider their life choices.\n";
        break;
    case 12:
        x[1] = "The battlefield echoes with the sound of laughter as " + MC.name + " and " + introEnemy + " bond over shared meme references.\n";
        break;
    case 13:
        x[1] = "Suddenly, " + MC.name + " and " + introEnemy + " break into synchronized dance moves, turning the battlefield into a surreal spectacle.\n";
        break;
    case 14:
        x[1] = "In a moment of confusion, " + MC.name + " accidentally sends a 'dank' meme to the enemy, creating an unexpected ceasefire.\n";
        break;
    case 15:
        x[1] = MC.name + " clenches their fists, radiating an unusual level of agitation that sends shivers down the enemies' spines.\n";
        break;
    case 16:
        x[1] = "The air crackles with tension as " + MC.name + " stares down the enemy, their eyes ablaze with a burning intensity.\n";
        break;
    case 17:
        x[1] = "For reasons unknown, " + MC.name + " is unusually irritable today, and the enemies can sense the storm brewing within them.\n";
        break;
    case 18:
        x[1] = MC.name + " has an intense desire for battle, their every move exuding a ferocity that surprises even the most battle-hardened foes.\n";
        break;
    case 19:
        x[1] = "The enemies exchange nervous glances as " + MC.name + " channels an unexpected surge of power, ready to unleash it upon them.\n";
        break;
    default:
        x[1] = "In a rare moment, " + MC.name + " utters a cryptic phrase that leaves the enemies bewildered and questioning their decision to engage in this battle.\n";
        break;
    }
    initiateFight(fqueue,eL,enemies);
    print(x,1,false);
    int i = 1;

    do{
        entity E;
        cout << " -=+=-\nTURN " + to_string(i) +"\n -=+=-\n";
        E = reFQueue(fqueue,eL);
        if(E.isPlayer){
            cout << E.Player.name<< "'s turn.\n";
        }else{
            cout << E.Enemy.name << "'s turn.\n";
        }
        int dice = roll();
        float attackMultiplier;
        if(E.isPlayer){
            int choice;
            cout << "What's your choice?" << endl;
            cout << "1.Attack\t2.Skill\t\n3.Item\t\t4.Run\n";
            cout << "Select your choice (1-4): ";
            do{
            //What the actual fuck is this, nnt lu ja yg jelasin
                cin >> choice;
                if(choice == 1){
                    cout << "Enemies: "<< endl;
                    entityAddress adrEntity = next(first(eL));
                    while(adrEntity != NULL){
                        cout << info(adrEntity).Enemy.name << " (" << info(adrEntity).no << ")"<<endl;
                        adrEntity = next(adrEntity);
                    }
                    cout << "Select your target:";
                    int target;
                    bool notDied = true;
                    do{
                        cin >> target;
                        if(findEntity(eL,target) == NULL){
                            cout << "Target invalid. Select your target:";
                        }else{
                            bool hit = false;
                            if(dice == 1){
                                cout<< "It's a critical!";
                                getch();
                                cout<< " Miss..." << endl;
                                attackMultiplier = 0;
                                hit = false;
                            }else if(dice <= 5){
                                for(int k = 0; k < dice; k++){
                                    int coin = flipcoin();
                                    if(coin == 1){
                                        hit = true;
                                    }
                                }
                            }
                            if(dice > 5 || hit){
                                if(dice > 15){
                                    cout<< "It's a critical!";
                                    getch();
                                    cout<< " Hit!" << endl;
                                    attackMultiplier = 0.5+(dice/10);
                                }else{
                                    attackMultiplier = 0.5+(dice)/25;
                                }
                            }
                            //NOTE: YES, THIS IS DUMB. BUT I HAVe GGONE TOO FAR FOR THIS
                            //TODO: instead of calling findEntity everytime we needed it, why don't we make new variable?
                            cout << MC.name + " dealt " << MC.defaultAttack * attackMultiplier << " damage!\n";
                            info(findEntity(eL,target)).Enemy.currentHealth -= MC.defaultAttack * attackMultiplier;
                            cout << info(findEntity(eL,target)).Enemy.name << " (" <<info(findEntity(eL,target)).no <<") only have " << info(findEntity(eL,target)).Enemy.currentHealth << " HP left!\n";
                            if(info(findEntity(eL,target)).Enemy.currentHealth <= 0){
                                cout << info(findEntity(eL,target)).Enemy.name << " (" <<info(findEntity(eL,target)).no <<") died!" <<endl;
                                cout << "You gained " << info(findEntity(eL,target)).Enemy.xp << " xp\n";
                                cout << "You gained " << info(findEntity(eL,target)).Enemy.coin << " coin\n";
                                int drop = roll();
                                if(drop < 20* info(findEntity(eL,target)).Enemy.dropChance){
                                    cout << "You got " << info(findEntity(eL,target)).Enemy.itemDrop << "!\n";
                                }
                                removeEntityFromQueue(fqueue,info(findEntity(eL,target)));
                                removeEntity(eL,findEntity(eL,target));
                                notDied = false;
                            }
                        }
                    }while(!findEntity(eL,target) && notDied);
                }else if(choice == 2){
                    showSkill(offensive(mc(PL)));
                    cout << "Select your skills: ";
                    int skillid;
                    do{
                        cin >> skillid;
                        if(!findSkillinPlayer(skillid,offensive(mc(PL)))){
                            cout << "Skill invalid. Select your skills:";
                        }else{
                            int target;
                            bool notDied = true;
                            bool hit = false;
                            if(info(skill(findSkillinPlayer(skillid,offensive(mc(PL))))).type == "Offensive"){
                                cout << "Enemies: "<< endl;
                                entityAddress adrEntity = next(first(eL));
                                while(adrEntity != NULL){
                                    cout << info(adrEntity).Enemy.name << " (" << info(adrEntity).no << ")"<<endl;
                                    adrEntity = next(adrEntity);
                                }
                                cout << "Select your target:";
                                int target;
                                bool notDied = true;
                                do{
                                    cin >> target;
                                    if(findEntity(eL,target) == NULL){
                                        cout << "Target invalid. Select your target:";
                                    }else{
                                        bool hit = false;
                                        if(dice == 1){
                                            cout<< "It's a critical!";
                                            getch();
                                            cout<< " Miss..." << endl;
                                            attackMultiplier = 0;
                                            hit = false;
                                        }else if(dice <= 5){
                                            for(int k = 0; k < dice; k++){
                                                int coin = flipcoin();
                                                if(coin == 1){
                                                    hit = true;
                                                }
                                            }
                                        }
                                        if(dice > 5 || hit){
                                            if(dice > 15){
                                                cout<< "It's a critical!";
                                                getch();
                                                cout<< " Hit!" << endl;
                                                attackMultiplier = 0.5+(dice/10);
                                            }else{
                                                attackMultiplier = 0.5+(dice)/25;
                                            }
                                        }
                                        //TODO: The fuck is this code
                                        //My fella, i'm askin the same
                                        skill sukiru = info(skill(findSkillinPlayer(skillid,offensive(mc(PL)))));
                                        cout << MC.name + " dealt " << (sukiru.dmg + MC.defaultAttack) * attackMultiplier << " damage!\n";
                                        info(findEntity(eL,target)).Enemy.currentHealth -= (sukiru.dmg + MC.defaultAttack) * attackMultiplier;
                                        cout << info(findEntity(eL,target)).Enemy.name << " (" <<info(findEntity(eL,target)).no <<") only have " << info(findEntity(eL,target)).Enemy.currentHealth << " HP left!\n";
                                        if(info(findEntity(eL,target)).Enemy.currentHealth <= 0){
                                            cout << info(findEntity(eL,target)).Enemy.name << " (" <<info(findEntity(eL,target)).no <<") died!" <<endl;
                                            cout << "You gained " << info(findEntity(eL,target)).Enemy.xp << " xp\n";
                                            cout << "You gained " << info(findEntity(eL,target)).Enemy.coin << " coin\n";
                                            int drop = roll();
                                            if(drop < 20* info(findEntity(eL,target)).Enemy.dropChance){
                                                cout << "You got " << info(findEntity(eL,target)).Enemy.itemDrop << "!\n";
                                            }
                                            removeEntityFromQueue(fqueue,info(findEntity(eL,target)));
                                            removeEntity(eL,findEntity(eL,target));
                                            notDied = false;
                                        }
                                    }
                                }while(!findEntity(eL,target) && notDied);
                            }else{
                                cout << "Fuck my life" << endl;
                            }
                        }
                    }while(!findSkillinPlayer(skillid,offensive(mc(PL))));
                    getch();
                }else if(choice == 3){

                }else if(choice == 4){
                    int fleeRoll = roll();
                    cout << "Trying to run away..."<<endl;
                    getch();
                    cout << "...\n";
                    getch();
                    cout << "...\n";
                    getch();
                    cout << "...\n";
                    if(fleeRoll < (10 + MC.speed/10)){
                        cout << "You ran away!\n";
                        fleed = true;
                    }else{
                        cout << "You failed to run away!\n";
                    }
                }else{
                    cout << "Wrong selection! Select your choice (1-4): ";
                }
            }while(choice < 0 || choice > 4);
            getch();
        }else{
            int rollskill = roll();
            //cout << E.Enemy.name + " is rolling..." << endl;
            bool hit = false;
            if(dice == 1){
                cout<< "It's a critical!";
                getch();
                cout<< " Miss..." << endl;
                attackMultiplier = 0;
            }else if(dice <= 5){
                for(int l = 0; l < dice; l++){
                    int coin = flipcoin();
                    if(coin == 1){
                        hit = true;
                    }
                }
            }
            if(dice > 5 || hit){
                if(dice > 15){
                    cout<< "It's a critical!";
                    getch();
                    cout<< " Hit!" << endl;
                    attackMultiplier = 0.5+(dice/10);
                }else{
                    attackMultiplier = 0.5+(dice)/25;
                }
            }
            if(rollskill < 20*E.Enemy.skillChance){
                if(E.Enemy.skillDamaging){
                    cout << E.Enemy.name + " (" + to_string(E.no) +") casted " + E.Enemy.skillName +"!" << endl;
                    if(attackMultiplier == 0){
                        cout << "...But it was a miss! ";
                    }
                    cout << E.Enemy.name + " deals " + to_string(E.Enemy.skillMultiplier * E.Enemy.defaultAttack * attackMultiplier) + " damage!" << endl;
                    MC.currentHealth -= E.Enemy.skillMultiplier * E.Enemy.defaultAttack * attackMultiplier ;
                }
            }else{
                cout << E.Enemy.name + " (" + to_string(E.no) +") is attacking!" << endl;
                if(attackMultiplier == 0){
                    cout << "...But it was a miss! ";
                }
                cout << E.Enemy.name + " deals " + to_string(attackMultiplier * E.Enemy.defaultAttack) + " damage!" << endl;
                MC.currentHealth -= attackMultiplier * E.Enemy.defaultAttack ;
            }
            if(MC.currentHealth <= 0){
                cout << "You died!\n";
                position[0] = 1000;
                getch();
                exit(0);
            }
            getch();
        }
        i++;
        if(next(first(eL)) != NULL){
            system("cls");
        }

    }while(next(first(eL)) != NULL && MC.currentHealth > 0 && !fleed);
    if(!fleed){
        cout << "You won!";
    }

    getch();
    popMenu(Menu);
}
void run(){
    cout << "Abandon this encounter, might not see it again";
    getch();
    popMenu(Menu);
}
//2 ni self explanatory
void moveAttack(){
    cout << "Initiate an offensive moves";
    getch();
    popMenu(Menu);
}

void moveDefence(){
    cout << "initiate a defencesive moves";
    getch();
    popMenu(Menu);
}
//nnt sini di battlephase recall yg inventory buat bs pake barang

void checkMenu(){
    int pick;
    int datachoice;

    cout << "  ___________________\n"
            "((                   ))\n"
            " )) Check Game Data ((\n"
            "((                   ))\n"
            "  -------------------\n";
    cout << "1. Show Player\n";
    cout << "2. Show All Items\n";
    cout << "3. Show All Class\n";
    cout << "4. Show All Skill\n";
    cout << "5. Find Data\n";
    cout << "6. Delete Data\n";
    cout << "7. Change Data\n";
    cout << "8. Leaderboard\n";
    cout << "9. Back to main Menu\n";
    cout << "Select your choice (1-9): ";
    do{
        cin >> pick;
        switch(pick){
        case 1:
            cout << "How do you want your Player presented? (1-4): " << endl;
            cout << "1. All\n";
            cout << "2. By Item\n";
            cout << "3. By Class\n";
            cout << "4. Back\n";
            cout << "Select your choice (1-4): ";
            do{
                cin >> datachoice;
                switch(datachoice){
                case 1:
                    pushMenu(Menu, 6);
                    break;
                case 2:
                    pushMenu(Menu, 18);
                    break;
                case 3:
                    pushMenu(Menu, 19);
                    break;
                case 4:
                    pushMenu(Menu, 15);
                    break;
                default:
                    cout << "Wrong Number. Select your choice (1-4): ";
                    break;
                }
            }while(datachoice < 1 || datachoice > 4);
            break;
            pushMenu(Menu,6);
            break;
        case 2:
            pushMenu(Menu,7);
            break;
        case 3:
            pushMenu(Menu,8);
            break;
        case 4:
            pushMenu(Menu,9);
            break;
        case 5:

            cout << "Which data do you want to find?\n";
            cout << "1. Player\n";
            cout << "2. Item\n";
            cout << "3. Class\n";
            cout << "4. Skill\n";
            cout << "5. Back" << endl;
            cout << "Select your choice (1-5): ";
            do{
                cin >> datachoice;
                switch(datachoice){
                case 1:
                    pushMenu(Menu, 10);
                    break;
                case 2:
                    pushMenu(Menu, 11);
                    break;
                case 3:
                    pushMenu(Menu, 12);
                    break;
                case 4:
                    pushMenu(Menu, 13);
                    break;
                case 5:
                    pushMenu(Menu, 15);
                    break;
                default:
                    cout << "Wrong Number. Select your choice (1-9): ";
                    break;
                }
            }while(datachoice < 1 || datachoice > 5);
            break;
        case 6:
            cout << "Which data do you want to delete?\n";
            cout << "1. Player\n";
            cout << "2. Item\n";
            cout << "3. Class\n";
            cout << "4. Back\n";
            cout << "Select your choice (1-5): ";
            do{
                cin >> datachoice;
                switch(datachoice){
                case 1:
                    pushMenu(Menu, 20);
                    break;
                case 2:
                    pushMenu(Menu, 22);
                    break;
                case 3:
                    pushMenu(Menu, 21);
                    break;
                case 4:
                    pushMenu(Menu, 15);
                    break;
                default:
                    cout << "Wrong Number. Select your choice (1-5): ";
                    break;
                }
            }while(datachoice < 1 || datachoice > 5);
            break;
        case 7:
            cout << "Which data do you want to find?\n";
            cout << "1. Player\n";
            cout << "2. Item\n";
            cout << "3. Class\n";
            cout << "4. Skill\n";
            cout << "5. Back\n";
            cout << "Select your choice (1-5): ";
            do{
                cin >> datachoice;
                switch(datachoice){
                case 1:
                    pushMenu(Menu, 28);
                    break;
                case 2:
                    pushMenu(Menu, 29);
                    break;
                case 3:
                    pushMenu(Menu, 30);
                    break;
                case 4:
                    pushMenu(Menu, 31);
                    break;
                case 5:
                    pushMenu(Menu, 15);
                    break;
                default:
                    cout << "Wrong Number. Select your choice (1-9): ";
                    break;
                }
            }while(datachoice < 1 || datachoice > 5);
            break;
        case 8:
            pushMenu(Menu,27);
            break;
        case 9:
            break;
        default:
            cout << "Wrong Number. Select your choice (1-9): ";
            break;
        }
    }while(pick < 1 || pick > 11);

    if(pick == 9){
        splashScreen();
        popMenu(Menu);
    }
}
void showAllPlayer(){
    system("cls");
    cout << "List of all Player:\n";
    int i = 1;
    playerAddress prec = first(PL);
    while(prec != NULL){
        cout << i << "." << info(prec).name << "\t|\t" << info(prec).Class << "\t|\t" << info(prec).level << endl << endl;
        prec = next(prec);
        i++;
    }
    getch();
    popMenu(Menu);
}
void showAllObject(){
    system("cls");
    cout << "List of all Object:\n";
    int i = 1;
    objectAddress prec = first(OL);
    while(prec != NULL){
        cout << i << "." << info(prec).name << " " << info(prec).desc << endl << endl;
        prec = next(prec);
        i++;
    }
    getch();
    popMenu(Menu);
}
void showAllClass(){
    system("cls");
    cout << "List of All Class:\n";
    showClass("",CT,false);
    getch();
    popMenu(Menu);
}
void showAllSkill(){
    cout << "List of All Skill:\n";
    system("cls");
    showSkillTree("",ST,false);
    getch();
    popMenu(Menu);
}
void findPlayerData(){
    string name;
    cout << "Enter Player name (type 0 to get back): ";
    do{
        getline(cin,name);
        if(findPlayer(PL,name)){
            playerAddress findplayer = findPlayer(PL,name);
            cout <<"Name            : " <<  info(findplayer).name << endl;
            cout <<"Class           : " <<  info(findplayer).Class << endl;
            cout <<"Level           : " <<  info(findplayer).level << endl;
            cout <<"Current Exp     : " <<  info(findplayer).exp << endl;
            cout <<"Coin            : " <<  info(findplayer).coin << endl;
            cout <<"--------------------------------" << endl;
            cout <<"             Stats" << endl;
            cout <<"--------------------------------" << endl;
            cout <<"Health          : " <<  info(findplayer).currentHealth << "/" <<info(findplayer).health << endl;
            cout <<"Stamina         : " <<  info(findplayer).currentStamina << "/" <<info(findplayer).stamina << endl;
            cout <<"Attack          : " <<  info(findplayer).defaultAttack << endl;
            cout <<"Defence         : " <<  info(findplayer).defaultDefence << endl;
            cout <<"Speed           : " <<  info(findplayer).speed << endl;
            cout <<"Critical Chance : " <<  info(findplayer).critChance << endl;
            cout <<"Offensive Skill :" << "[";
            if(first(offensive(findplayer)) == NULL){
                cout << "None!";
            }else{
                sListAddress prec = first(offensive(findplayer));
                while(prec != NULL){
                    cout << info(skill(prec)).name;
                    if(prec != last(offensive(findplayer))){
                        cout << ", ";
                    }
                    prec = next(prec);
                }
            }
            cout << "]" << endl;
        }else if(name == "0"){
            break;
        }else{
            cout << "Player not found! Enter Player name (type 0 to get back): ";
        }
    }while(!findPlayer(PL,name) && name != "0");
    getch();
    popMenu(Menu);
}
void findItemData(){
    string name;
    cout << "Enter Item name (type 0 to get back): ";
    do{
        getline(cin,name);
        if(findObject(OL,name)){
            object Object = info(findObject(OL,name));
            cout <<"Name: " <<  Object.name << endl;
            cout <<"Description: " <<  Object.desc << endl;
            if(Object.isEquipable){
                cout << "Armor Type: " << Object.armorType << endl;
                cout << "Buff 1: " << Object.bonusStat[1] <<" (" << Object.bonus[1] << ")"<< endl;
                if(Object.bonus[2] != 0){
                    cout << "Buff 2: " << Object.bonusStat[2] <<" (" << Object.bonus[2] << ")"<< endl;
                }

            }else if(Object.isConsumable){
                if(Object.heal > 0){
                    cout << "Heal: " << (Object.heal*100 / MC.health) << "%" <<endl;
                }else{
                    cout << "Buff: " << Object.buffStat <<" (" << Object.buff << ")"<< endl;
                }
            }
        }else if(name == "0"){
            break;
        }else{
            cout << "Item not found! Enter Item name (type 0 to get back): ";
        }
    }while(!findObject(OL,name) && name != "0");
    getch();
    popMenu(Menu);
}
void findClassData(){
    string name;
    cout << "Enter Class name (type 0 to get back): ";
    do{
        getline(cin,name);
        if(findClass(CT,name)){
            Class cls = info(findClass(CT,name));
            cout <<"Name            : " <<  cls.name << endl;
            cout <<"Description     : " <<  cls.desc<< endl;
            cout <<"Bonus Health    : " <<  cls.bonusHealth << endl;
            cout <<"Bonus Attack    : " <<  cls.bonusAttack << endl;
            cout <<"Bonus Defense   : " <<  cls.bonusDefense << endl;
            cout <<"Bonus Speed     : " <<  cls.bonusSpeed << endl;
            cout <<"Unlocked Skill  : " <<  info(skill(findClass(CT,name))).name << endl;
        }else if(name == "0"){
            break;
        }else{
            cout << "Class not found! Enter Class name (type 0 to get back): ";
        }
    }while(!findClass(CT,name) && name != "0");
    getch();
    popMenu(Menu);
}
void findSkillData(){
    string name;
    cout << "Enter Skill name (type 0 to get back): ";
    do{
        getline(cin,name);
        if(findskill(ST,name)){
            skill Skill = info(findskill(ST,name));
            cout <<"Name            : " <<  Skill.name << endl;
            cout <<"Description     : " <<  Skill.desc<< endl;
            cout <<"Cost            : " <<  Skill.cost[1] << endl;
            cout <<"Skill Type      : " <<  Skill.type << endl;
            if(Skill.dmg > 0){
                cout <<"Skill Damage   : " <<  Skill.dmg << endl;
            }

            string multiple = Skill.isMultiple ? "Yes" : "No";
            //string buff = Skill.buff == 0 ? "None" : to_string(Skill.buff);
            //cout <<"Skill Buff      : " <<  buff << endl;
            cout <<"Is Multiple?    : " <<  multiple << endl;
            cout <<"Skill Heal      : " << Skill.heal << endl;
        }else if(name == "0"){
            break;
        }else{
            cout << "Skill not found! Enter Skill name (type 0 to get back): ";
        }
    }while(!findskill(ST,name) && name != "0");
    getch();
    popMenu(Menu);
}
void showAllPlayerInventory(){
    system("cls");
    cout << "List of all Inventory:" << endl;
    int i = 1;
    playerAddress prec = first(PL);
    while(prec != NULL){
        cout << i << "." << info(prec).name << endl;
        cout << "[";
        if(isInventoryEmpty(inventory(prec))){
            cout << "None!";
        }else{
            showInventory(inventory(prec));
        }
        cout << "]\n";
        prec = next(prec);
        i++;
    }
    getch();
    popMenu(Menu);
}
void showAllPlayerClass(){
    system("cls");
    cout << "List of all Inventory: " << endl;
    int i = 1;
    playerAddress prec = first(PL);
    while(prec != NULL){
        cout << i << "." << info(prec).name << endl;
        cout << "[";
        showSkill(offensive(prec));
        cout << "]\n";
        prec = next(prec);
        i++;
    }
    getch();
    popMenu(Menu);
}
void showPlayerInventory(){
    string name;
    cout << "Enter Player name (type 0 to get back): ";
    do{
        getline(cin,name);
        if(findPlayer(PL,name)){
            playerAddress prec = findPlayer(PL,name);
            cout << "[";
            if(isInventoryEmpty(inventory(prec))){
                cout << "None!";
            }else{
                showInventory(inventory(prec));
            }
            cout << "]\n";
        }else if(name == "0"){
            break;
        }else{
            cout << "Player not found! Enter Player name (type 0 to get back): ";
        }
    }while(!findPlayer(PL,name) && name != "0");
    getch();
    popMenu(Menu);
}
void showPlayerClass(){
    string name;
    cout << "Enter Player name (type 0 to get back): ";
    do{
        getline(cin,name);
        if(findPlayer(PL,name)){
            playerAddress prec = findPlayer(PL,name);
            showClassInfo(findClass(CT,info(prec).Class));
        }else if(name == "0"){
            break;
        }else{
            cout << "Player not found! Enter Player name (type 0 to get back): ";
        }
    }while(!findPlayer(PL,name) && name != "0");
    getch();
    popMenu(Menu);
}
void showObjectByPlayer(){
    system("cls");
    string name;
    cout << "Enter Item name (type 0 to get back): ";
    int i = 1;
    do{
        getline(cin,name);
        if(findObject(OL,name)){

            playerAddress prec = first(PL);
            while(prec != NULL){
                if(findObjectinInventory(inventory(prec),name)){
                    cout << i << "." << info(prec).name << endl;
                    i++;
                }
                prec = next(prec);

            }
            if(i == 1){
                cout << "Player not found!" << endl;
            }
        }else if(name == "0"){
            break;
        }else{
            cout << "Item not found! Enter Item name (type 0 to get back): ";
        }

    }while(!findObject(OL,name) && name != "0");
    getch();
    popMenu(Menu);
}
void showClassByPlayer(){
    system("cls");
    cout << "List of all Class: " << endl ;

    string name;
    cout << "Enter Class name (type 0 to get back): ";
    int i = 1;
    do{
        getline(cin,name);
        if(findClass(CT,name)){

            playerAddress prec = first(PL);

            while(prec != NULL){
                if(Class(prec) == findClass(CT,name)){
                    cout << i << "." << info(prec).name << endl;
                    i++;
                }
                prec = next(prec);

            }
            if(i == 1){
                cout << "Player not found!" << endl;
            }
        }else if(name == "0"){
            break;
        }else{
            cout << "Class not found! Class Item name (type 0 to get back): ";
        }

    }while(!findClass(CT,name) && name != "0");
    getch();
    popMenu(Menu);
}
void deletePlayerData(){
    string name;
    bool deleted = false;
    cout << "Enter Player name (type 0 to get back): ";
    do{
        getline(cin,name);
        if(findPlayer(PL,name)){
            string confirm;
            cout << "Are you sure(y/n)?: ";
            do{
                cin >> confirm;
                if(confirm == "y"){
                    deletePlayer(PL,name);
                    cout << "Player succesfully deleted!" << endl;
                    deleted = true;
                }else if(confirm != "y" && confirm != "n"){
                    cout << "Input is not valid. Are you sure(y/n)?: ";
                }
            }while(confirm != "y" && confirm != "n");

        }else if(name == "0"){
            break;
        }else if(!deleted){
            cout << "Player not found! Enter Player name (type 0 to get back): ";
        }
    }while((!findPlayer(PL,name) && name != "0") && !deleted);
    getch();
    popMenu(Menu);
}
void deleteObjectData(){
    string name;
    bool deleted = false;
    cout << "Enter Item name (type 0 to get back): ";
    do{
        getline(cin,name);
        if(findObject(OL,name)){
            string confirm;
            cout << "Are you sure(y/n)?: ";
            do{
                cin >> confirm;
                if(confirm == "y"){
                    deleteObject(PL,OL,name);
                    cout << "Item succesfully deleted!" << endl;
                    deleted = true;
                }else if(confirm != "y" && confirm != "n"){
                    cout << "Input is not valid. Are you sure(y/n)?: ";
                }
            }while(confirm != "y" && confirm != "n");

        }else if(name == "0"){
            break;
        }else if(!deleted){
            cout << "Item not found! Enter Item name (type 0 to get back): ";
        }
    }while((!findObject(OL,name) && name != "0") && !deleted);
    getch();
    popMenu(Menu);
}
void deleteClassData(){
    string name;
    bool deleted = false;
    cout << "Enter Class name (type 0 to get back): ";
    do{
        getline(cin,name);
        if(findClass(CT,name)){
            string confirm;
            cout << "Are you sure(y/n)?: ";
            do{
                cin >> confirm;
                if(confirm == "y"){
                    //deleteClass(OL,name);
                    cout << "Item succesfully deleted!" << endl;
                    deleted = true;
                }else if(confirm != "y" && confirm != "n"){
                    cout << "Input is not valid. Are you sure(y/n)?: ";
                }
            }while(confirm != "y" && confirm != "n");

        }else if(name == "0"){
            break;
        }else if(!deleted){
            cout << "Class not found! Enter Class name (type 0 to get back): ";
        }
    }while((!findClass(CT,name) && name != "0") && !deleted);
    getch();
    popMenu(Menu);

}
void deleteObjectByPlayer(){
    getch();
    popMenu(Menu);
}
void deleteSkillByPlayer(){
    getch();
    popMenu(Menu);
}
void showMostItem(){
    getch();
    popMenu(Menu);
}
void showMostClass(){
    getch();
    popMenu(Menu);
}
void showTopThree(){
    getch();
    popMenu(Menu);
}
void changePlayerData(){
    getch();
    popMenu(Menu);
}
void changeObjectData(){
    getch();
    popMenu(Menu);
}
void changeClassData(){
    getch();
    popMenu(Menu);
}
void changeSkillData(){
    getch();
    popMenu(Menu);
}

void initiateTop(){

    if(!isMenuEmpty(Menu)){
        switch(Menu.info[Menu.top]){
        case 0:
            system("cls");
            explore();
            break;
        case 1:
            explore();
            break;
        case 2:
            stats();
            break;
        case 3:
            checkInventory();
            break;
        case 4:
            interactorTalk();
            break;
        case 5:
            system("cls");
            checkMenu();
            break;
        case 6:
            system("cls");
            showAllPlayer();
            break;
        case 7:
            showAllObject();
            break;
        case 8:
            showAllClass();
            break;
        case 9:
            showAllSkill();
            break;
        case 10:
            findPlayerData();
            break;
        case 11:
            findItemData();
            break;
        case 12:
            findClassData();
            break;
        case 13:
            findSkillData();
            break;
        case 14:
            showAllPlayerInventory();
            break;
        case 15:
            showAllPlayerClass();
            break;
        case 16:
            showPlayerInventory();
            break;
        case 17:
            showPlayerClass();
            break;
        case 18:
            showObjectByPlayer();
            break;
        case 19:
            showClassByPlayer();
            break;
        case 20:
            deletePlayerData();
            break;
        case 21:
            deleteObjectData();
            break;
        case 22:
            deleteClassData();
            break;
        case 23:
            deleteObjectByPlayer();
            break;
        case 24:
            deleteSkillByPlayer();
            break;
        case 25:
            showMostItem();
            break;
        case 26:
            showMostClass();
            break;
        case 27:
            showTopThree();
            break;
        case 28:
            changePlayerData();
            break;
        case 29:
            changeObjectData();
            break;
        case 30:
            changeClassData();
            break;
        case 31:
            changeSkillData();
            break;
        }
    }
}
