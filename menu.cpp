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
            Sleep(500 + rand() % 500);
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
    cout << " __| |____________________________________________| |__\n"
"(__   ____________________________________________   __)\n"
"   | |           Welcome To  Brave Hearts:        | |\n"
"   | |               Journey to the               | |\n"
"   | |              Lands of Eldoria              | |\n"
"   | |                                            | |\n"
"   | |         Ketik Mana Saja Untuk Lanjut       | |\n"
"   | |                                            | |\n"
" __| |____________________________________________| |__\n"
"(__   ____________________________________________   __)\n"
"   | |                                            | |";
    getch();
    system("cls");
}
void introduction(){
    string x[100];
    x[0] = "Selamat datang pemberani, di dunia mistis Eldoria! Sebuah tanah yang penuh dengan sihir, makhluk mitos, kejahatan, dan dihiasi dengan harta karun yang tak terhitung jumlahnya. Angin takdir membawamu ke kota kecil Everhaven, di mana sebuah ramalan kuno meramalkan penemuan Pusaka yang Hilang—artefak kuat yang menyimpan kunci untuk mengembalikan keseimbangan dunia.\n";
    print(x,0,false);
    x[1] = "Saat kamu memasuki kota Everhaven yang ramai, jalan-jalan berkerikil dan bangunan-bangunan berkerangka kayu bergema dengan kisah-kisah pahlawan dan bisikan kegelapan yang akan datang. Penduduk kota yang tentram sedang menjalani hidup mereka sendiri-sendiri, dengan tanpa kesadaran adanya bahaya dalam dunia Eldoria. Namun, suatu berita yang akan merubah segalanya dalam kota Everhaven. \n";
    print(x,1,false);
    x[2] = "Sekarang, pahlawan yang berani, saatnya bagi Anda untuk masuk ke dalam karakter Anda. Apa nama Anda, yang akan dinyanyikan dalam balada sepanjang negeri? Ucapkan dengan lantang, dan biarkan namamu terukir dalam gulungan sejarah Eldoria.\n";
    print(x,2,true);
    cout << "\nMasukkan nama kamu: ";;
    getline(cin,MC.name);
    system("cls");
    x[3] = "Ah, " + MC.name + ", sebuah nama yang membawa beban takdir. \n\nSaat Anda menjelajahi kota, Anda menemukan seorang pedagang tua misterius di sudut terpencil pasar. Dia merasakan percikan petualangan Anda. \n";
    print(x,3,false);
    x[4] = "Pedagang tua: Wahai petualang, saya merasa ada suatu potensial tinggi dalam diri anda, keberuntungan saja saya lagi kelebihan stok suatu barang yang anda mungkin tertarik, \n\nKemudian pedagang tua tersebut mengeluarkan 3 barang yang tidak familiar dimana-mana. \n ";
    print(x,4,false);
    x[5] = "Pedagang tua: Hehe, anak muda. Dari setiap barang ini memiliki kekuatan yang akan bisa membuatmu SANGAT kuabt dibanding siapapun dan bisa dibilang kekuatan yang KEKAL,\n";
    print(x,5,false);
    x[6] = "Pedagang tua: TAPI, jika kau sudah memilih, kau tidak akan bisa lagi berpisah dengan barangnya dan akan ada efek samping di setiap barang tersebut ini. Silahkan pilih salah satu dengan hati-hati: \n1. Shitty item\n2. Even more shitty item\n3. Item"; // show barang2 apa aja
    print(x,6,true);
    cout << "Pilih salah satu:" << endl; // kan ad 3 pilihan nnt pilihan 4 kl bs mending kg ush pilih, jg show barang dh nnt yang ada apa aja
    cin >> Object.name;
    while(findObject(OL,Object.name) == NULL){
        cout << "Barang tidak tersedia, Pilih salah satu" << endl;
        cin >> Object.name;
    }
    addObjectToPlayer(PL,OL,MC.name,Object.name);

    x[7] = "\nKamu memilih: " + Object.name +"\n\nPedagang tua: Muahahaha, sekarang nasib kau sudah tercatat dalam gulungan takdir\n"; //Jika kg pilih samsek, makany replyny "Kau adalah petualang yang konyol dan bodoh menolak kekuatan kekal, PERGILAH SEKARANG"

    print(x,7,false);

    x[8] = "Sekarang, pilih class kamu:\n"; //kg ush krn skill awalan emg
    print(x,8,true);
    showClassByParent(Class(mc(PL)));
    cout << "Pilih salah satu: " << endl; //  same kek atas
    getline(cin,cls.name);
    getline(cin,cls.name);
    while(cls.name != info(left(Class(mc(PL)))).name && cls.name != info(right(Class(mc(PL)))).name){
        cout << "Class tidak tersedia, Pilih salah satu" << endl;
        getline(cin,cls.name);
    }
    changePlayerClass(MC.name,cls.name);
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
            encounter(roll()%19 + 1);
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
        x[1] = "'Welcome to the Enchanted Wanderer, ready to serve weary travelers and intrepid rogues alike to step through its ethereal doors.' The atmosphere is an eclectic blend of 	whimsy and mystery, with flickering candles illuminating ancient tapestries that tell tales of forgotten realms.	" + to_string(id);
        print(x,1,false);
        x[2] = "The barkeep, a spectral figure with a twinkle in their eye, serves drinks that bring courage, strength, and arcane insights" + to_string(id);
        print(x,2,false);
        x[3] = "'Now fellow wanderer, what can I do for ye?'\n";
        print(x,3,false);
        x[4] = "1. Rent A Room  [Replenish your health, cost 5 gold piece]\n";
        print(x,4,false);
        x[5] = "2. A Manual scroll from distant lands [Upgrade to the next class of their choosing + skills, cost 60 gold piece]    \n	3. Spectral Cloak [+20 Defence, cost 20 gold 	piece]\n 3. Helm of Clairvoyant Insight [+20 health, cost 20 gold piece] \n	4. Legplates of Ethereal Stride [+ 20 speed, cost 20 gold piece] \n   5. Sword of Phantasmal Flames 	[+30 attack and 5  speed, cost 20 gold piece] \n 6. Healing Potions [+ heal (33 * level), cost 5 gold piece] \n  7. Defence Potions [+ 30 defence for 2 turns, cost 5 gold piece] \n  	8. Attack Potions [+ 30 attack for 2 turns, cost 5 gold piece] \n  9. Speed Potions [+ 30 Speed boost for 2 turns, cost 5 gold piece] \n  10. Provisions [ + heal (20 * level), cost 	3 gold piece] \n  11. Entropic Die [cahrms, tiap start battle ad chance +20 attack, + 20 defence, + 20 speed, +25 health for 2 turns, tiap buff jadi hanya 1 dpt dgn 1/25 chance, 	cost 30 gold piece] \n  12. Amulet of Lifespring [charms, at the start of the battle (+ heal (10 * level) for 2 turns), cost 20 gold piece]  \n  13. Ring of Attunement [charms,  +	10 attack, +10 defence, + 10 Speed, +10 health for perma, 30 gold piece] + to_string(id)";
        print(x,5,false);
        x[10] = "'Welcome to the Enchanted Wanderer, ready to serve weary travelers and intrepid rogues alike to step through its ethereal doors.' The atmosphere is an eclectic blend of 	whimsy and mystery, with flickering candles illuminating ancient tapestries that tell tales of forgotten realms.	" + to_string(id);
        print(x,6,true);
        do{
            cin >> choice;
            if (choice == "1"){
                cout << "Well goodnight then.. or morn, Im not sure myself because time here is irrelevant\n";
                MC.coin -= 5;
                MC.currentHealth = MC.health;
            }else if (choice == "2"){
                if(findObjectinInventory("Enchiridion") != NULL){
                    cout << "Sorry kid, you already bought it before\n";
                }else{
                    MC.coin -= 60;
                    //addObjectToPlayer(PL,OL,MC.name,"Enchiridion");
                    cout << "Huh.. I thought this thing was destroyed. what Else Can I get for ye?\n";
                }
            }else if (choice == "3"){
                if(findObjectinInventory("Spectral Cloak") != NULL){
                    cout << "Sorry kid, you already bought it before\n";
                }else{
                    MC.coin -= 20;
                    //addObjectToPlayer(PL,OL,MC.name,"Spectral Cloak");
                    cout << "good choice, I made em myself from a unicorn hairs (Animal Cruelty Free)\n";
                }
            }else if (choice == "4"){
                if(findObjectinInventory("Legplates of Etheral Stride") != NULL){
                    cout << "Sorry kid, you already bought it before\n";
                }else{
                    MC.coin -= 20;
                    //addObjectToPlayer(PL,OL,MC.name,"Legplates of Etheral Stride");
                    cout << "good decision, I can even do a little bit of blacksmithing myself other than barkeeping and tailoring\n";
                }
            }else if (choice == "5") {
                if (findObjectinInventory("Sword of Phantasmal Flames") != NULL) {
                    cout << "Sorry kid, you already bought it before\n";
                } else {
                    MC.coin -= 20;
                    // addObjectToPlayer(PL, OL, MC.name, "Sword of Phantasmal Flames");
                    cout << "Negotiated with Surtur myself to forge this beauty\n";
                }
            } else if (choice == "6") {
                MC.coin -= 5;
                // addObjectToPlayer(PL, OL, MC.name, "Healing Potion");
                cout << "Wise decision, a good traveler is an alive traveler\n";
            } else if (choice == "7") {
                MC.coin -= 5;
                // addObjectToPlayer(PL, OL, MC.name, "Defence Potion");
                cout << "Make ya skin feels like a stone, in a good way\n";
            } else if (choice == "8") {
                MC.coin -= 5;
                // addObjectToPlayer(PL, OL, MC.name, "Attack Potion");
                cout << "Don't do weird magix kids! Just try my brew, it'll feel like you could lift a mountain (don't actually do it)\n";
            } else if (choice == "9") {
                MC.coin -= 5;
                // addObjectToPlayer(PL, OL, MC.name, "Speed Potion");
                cout << "Can't keep up with a carriage? try this one for size\n";
            } else if (choice == "10") {
                MC.coin -= 3;
                // addObjectToPlayer(PL, OL, MC.name, "Provision");
                cout << "Can't afford a Health Potion? try this alternative, the taste is bland but it's better than nothing right?\n";
            } else if (choice == "11") {
                MC.coin -= 30;
                // addObjectToPlayer(PL, OL, MC.name, "Entropic Die");
                cout << "I forgot where I got it from, but I can guarantee you that this will help you.. I hope\n";
            } else if (choice == "12") {
                if (findObjectinInventory("Amulet of Lifespring") != NULL) {
                    cout << "Sorry kid, you already bought it before";
                } else {
                    MC.coin -= 20;
                    // addObjectToPlayer(PL, OL, MC.name, "Amulet of Lifespring");
                    cout << "An amulet blessed by a Harvest Goddess in a land called Leaf Valley\n";
                }
            } else if (choice == "13") {
                if (findObjectinInventory("Ring of Attunement") != NULL) {
                    cout << "Sorry kid, you already bought it before";
                } else {
                    MC.coin -= 30;
                    // addObjectToPlayer(PL, OL, MC.name, "Ring of Attunement");
                    cout << "This thing will make you feel in balance every time you battle just as all things should be\n";
                }
            } else if (choice == "14"){
                cout << "Do be seein' ya come back again someday, may the astral thread weaves you a good journey";
            }else{
                cout << "That Item does not exist or I dont know what you are talkin about";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 14);
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
                //[Walk Away and 10 gold piece];
            }else if (choice == "2"){
                //[Lose 1/2 total health, obtain 30 gold piece]
            }else if (choice == "3"){
                //[Enter battle with 5 insects];
                cout << "you've found Legging made out of... sticky silk?\n";
                //get [Sticky Silk Legging];
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 10);
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
                //[Discard a random charms from your inventory/equip, exchange it with 'Boons of Boons' charms (+ 15% gold piece and xp bonus)];
                cout << "OH! How Joyful it is to have a stranger in this time\n";
            }else if (choice == "2"){
                //gain [nothing and small xp]
                cout << "How disappointing encounter tis is\n";
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
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
    	x[6] = "1. Jim Hulk's collection. (requires 15 gold piece) \n  2. Sorry I cant help you.\n";
        print(x,6,true);
        do{
            cin >> choice;
            if (choice == "1"){
                //[gain 'Tonic of Efficacious Chaos' Charm, +attack (20 * char lv) for 1 turn].
            }else if (choice == "2"){
                cout << "I guess this is it for us.. sorry brother I've failed you";
                //[gain 10 gold piece and small xp]
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
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
                cout << "Very well... FOR QLIPOTH!!!\n";
                //[Enter Battle with 1 lead miner and 2 other miners];
            }else if (choice == "2"){
                cout << "May the Blessings of the Amber Lord be with you\n";
                //gets ['Ring of Amber' charm, + 15 defence perma]
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
        break;
    case 6:
        x[0] = " ==  Bounty Hunter (Occurance) ==" ;
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
                cout << "YOU SON OF A- I'LL KILL YOU FOR THIS\n";
                getch();
                //[Enter Battle With a Bounty Hunter]
            }else if (choice == "3"){
                cout << "No thanks\n";
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 3);
        MC.xp += 10;
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
                MC.health *= 1-MC.level/10;
                //[figth Sal]
            }else if (choice == "2"){
                //[discard random item from inventory]
                //[fight Leo]
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
        break;
    case 8:
        x[0] = " == Flash Bazar (Transaction) == " ;
        print(x,0,false);
        x[1] = "You arrive at the busiest bazaar in Varunix. One of the stalls catches your attention. The stall owner's face is obscured by the hood he is wearing. He sits cross-legged 	on a purple floor mat with various mineral bottles displayed around him." ;
        print(x,1,false);
    	x[2] = "'I'm the disciple of Oswaldo Schneider. Both of us are from the Fanaticism Department of Arasaka!',The man says out of nowhere. 'Do you know how commercial activities in 	these land started in the first place?'" ;
        print(x,2,false);
    	x[3] = "'Of course. It all started from our belief in Nanook. To help the Aeon in building the wall, the support team needed materials from different places across these lands of 	Erudera. We learned to exchange resources during that time,'he says while scratching his face. 'Now, let's try to exchange something. I guarantee you that whatever you've spent 	won't be in vain.'" ;
        print(x,3,false);
    	x[4] = "1. Purchase a metal Wish-In-A-Bottle. — (Consume 10 gold piece and obtain 1 'Good Value' Charms). 2. Purchase a silver ore Wish-In-A-Bottle. — (Consume 20 gold piece and 	obtain 1 'Surprising' equipment.) \n3. Leave. — You're not interested.\n" ;
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
                //[+ (10 * char lv)health, named "Good Value" charms.];
                cout << "Im sure you'll be pleased to have that";
            }else if (choice == "2"){
                //[+25 attack, sword named "Scarlet".];
                cout << "I'm *surprised* you picked that one";
            }else if (choice == "3"){
                //gain [10 gold piece and small xp];
            }else{
                cout << "you cant do that";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 3);
        break;
    case 9:
        x[0] = " == House of Nildis (Occurance) == " ;
        print(x,0,false);
        x[1] = "You sit at the card table across from a one-eyed dealer whose metal prosthetic legs are intertwined with the legs of the Nildis table. His torso runs through a hole in the 	center of the table with a pinball circling his waist." ;
        print(x,1,false);
    	x[2] = "He moves his eyeballs to look at you before bowing at you respectfully. Next, the dealer distributes the gold piece and shuffles the cards gracefully with his 2 wooden 	prosthetic arms." ;
        print(x,2,false);
    	x[3] = "He moves his eyeballs to look at you before bowing at you respectfully. Next, the dealer distributes the gold piece and shuffles the cards gracefully with his 2 wooden 	prosthetic arms." ;
        print(x,3,false);
    	x[4] = "He moves his eyeballs to look at you before bowing at you respectfully. Next, the dealer distributes the gold piece and shuffles the cards gracefully with his 2 wooden 	prosthetic arms." ;
        print(x,4,false);
    	x[5] = "5. Flip the Card. (50% chance fighting 2 elite rogue) \n  2. walk away \n 3. Flip over the game table" ;
        print(x,5,true);
        do{
            cin >> choice;
            if (choice == "1"){
                //[50% chance gains 'Gambler's Brooch'(50% gains +20 defence, 50% gains +20 attack for 2 turns at every start battle) Chestpiece ];
            }else if (choice == "2"){
                //[gain nothing and small xp]
            }else if (choice == "3"){
                cout << "Wise move, dead man";
                //[fight 4 elite rogues];
            }else{
                cout << "you cant do that";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 3);
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
    	x[4] = "1. Tell Fortune. [spend 5  gold piece]  \n  2. It's just a rumor, Leave. — You're not interested.\n";
        print(x,4,true);
        do{
            cin >> choice;
            if (choice == "1"){
                cout << "'What an interesting fate you've got there, be sure to come back after you succeeded teehee~'";
                //[25% obtaining, 'Bloodied Necklace' charms [if atleast 1 enemy killed, get + (20 * char lv) attack]]
            }else if (choice == "2"){
                //gain [nothing and small xp]
                cout << "A stranger's fate lies once more in the deep\n";
            }else{
                cout << "you cant do that\n";
            }
        }while(stoi(choice) < 0 || stoi(choice) > 2);
        break;
    case 11:
        do{

        }while(stoi(choice) < 0 || stoi(choice) > 10);
        break;
    case 12:
        do{
            cin >> choice;
        }while(stoi(choice) < 0 || stoi(choice) > 10);
        break;
    case 13:
        do{
            cin >> choice;
        }while(stoi(choice) < 0 || stoi(choice) > 10);
        break;
    case 14:
        do{
            cin >> choice;
        }while(stoi(choice) < 0 || stoi(choice) > 10);
        break;
    case 15:
        do{

        }while(stoi(choice) < 0 || stoi(choice) > 10);
        break;
    case 16:
        do{
            cin >> choice;
        }while(stoi(choice) < 0 || stoi(choice) > 10);
        break;
    case 17:
        do{
            cin >> choice;
        }while(stoi(choice) < 0 || stoi(choice) > 10);
        break;
    case 18:
        do{

        }while(stoi(choice) < 0 || stoi(choice) > 10);
        break;
    case 19:
        do{
            cin >> choice;
        }while(stoi(choice) < 0 || stoi(choice) > 10);
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
void fight(enemy enemies[]){
    string x[100];
    x[0] = " -=+=-\nBATTLE!\n -=+=-\n";
    print(x,0,false);
    int id = roll();
    switch(id) {
    case 1:
        x[1] = enemies[roll() % sizeof(enemies)-1].name + " seems feisty tonight.\n";
        break;
    case 2:
        x[1] = enemies[roll() % sizeof(enemies)-1].name + " is angry!\n";
        break;
    case 3:
        x[1] = MC.name + " is kind of quirky.\n";
        break;
    case 4:
        x[1] = MC.name + " is doing a little bit of trolling.\n";
        break;
    case 5:
        x[1] = enemies[roll() % sizeof(enemies)-1].name + " seems feisty tonight.\n";
        break;
    case 6:
        x[1] = enemies[roll() % sizeof(enemies)-1].name + " eyes " + MC.name + " with a mix of curiosity and hostility.\n";
        break;
    case 7:
        x[1] = MC.name + " and " + enemies[roll() % sizeof(enemies)-1].name + " exchange a few sarcastic remarks before the battle.\n";
        break;
    case 8:
        x[1] = "As " + MC.name + " approaches, " + enemies[roll() % sizeof(enemies)-1].name + " snickers and says, 'You're in for a surprise.'\n";
        break;
    case 9:
        x[1] = "The tension is palpable as " + MC.name + " and " + enemies[roll() % sizeof(enemies)-1].name + " share a moment of awkward silence.\n";
        break;
    case 10:
        x[1] = "In a strange turn of events, " + enemies[roll() % sizeof(enemies)-1].name + " starts memeing, leaving " + MC.name + " utterly confused.\n";
        break;
    case 11:
        x[1] = MC.name + " retorts with a well-timed meme, causing " + enemies[roll() % sizeof(enemies)-1].name + " to reconsider their life choices.\n";
        break;
    case 12:
        x[1] = "The battlefield echoes with the sound of laughter as " + MC.name + " and " + enemies[roll() % sizeof(enemies)-1].name + " bond over shared meme references.\n";
        break;
    case 13:
        x[1] = "Suddenly, " + MC.name + " and " + enemies[roll() % sizeof(enemies)-1].name + " break into synchronized dance moves, turning the battlefield into a surreal spectacle.\n";
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
    print(x,1,true);
    int i = 1;

    do{
        entity E;
        cout << isEntityEmpty(eL) << to_string(MC.currentHealth) << endl;
        cout << " -=+=-\nTURN " + to_string(i) +"\n -=+=-\n";
        E = reFQueue(fqueue,eL);
        int dice = roll();
        float attackMultiplier;
        if(E.isPlayer){
            cout << "What's your choice?" << endl;
            cout << "1.Attack\t2.Skill\t3.Item\t4.Run\n";
            cout << "Select your choice (1-4): ";
            do{
               cin >> choice;
                if(choice == "1"){
                    cout << "Enemies: "<< endl;
                    entityAddress adrEntity = next(first(eL));
                    int j = 1;
                    while(adrE != NULL){
                        cout << i << "." << info(adrEntity).Enemy.name << " (" << info(adrEntity).no
                    }
                    for(int i = 1; i < sizeof(enemies)-1;i++){

                    }
                    cout << "Select your target:";
                }else if(choice == "2"){

                }else if(choice == "2"){

                }else if(choice == "2"){

                }else{
                    cout << "Wrong selection! Select your choice (1-4): "
                }
            }while(stoi(choice) < 0 || stoi(choice) > 4);
        }else{
            int rollskill = roll();
            //cout << E.Enemy.name + " is rolling..." << endl;
            bool hit = false;
            if(dice == 1){
                cout<< "It's a critical!";
                getch()
                cout<< " Miss..." < endl;
                attackMultiplier = 0;
            }else if(dice <= 5){
                for(int i = 0; i < dice; i++){
                    int coin = flipcoin;
                    if(coin == 1){
                        hit = true;
                    }
                }
            }
            if(dice > 5 || hit){
                if(dice > 15){
                    cout<< "It's a critical!";
                    getch()
                    cout<< " Hit!" < endl;
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
        }
        i++;

    }while(!isEntityEmpty(eL) && MC.currentHealth > 0);
    if(MC.currentHealth <= 0){
        position[0] = 1000;
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

void initiateTop(){

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
    }
}
