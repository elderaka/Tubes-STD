#include "menu.h"
void print(string text[100], int i, bool interactable){
    string x = text[i];
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
    x[6] = "Pedagang tua: TAPI, jika kau sudah memilih, kau tidak akan bisa lagi berpisah dengan barangnya dan akan ada efek samping di setiap barang tersebut ini. Silahkan pilih salah satu dengan hati-hati: \n"; // show barang2 apa aja
    print(x,6,true);
    showObject(OL);
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

void mainMenu(){
    cout << "===== Menu Utama =====" << endl;
    cout << "1. Petualangan\n";
    cout << "2. Toko\n";
    cout << "3. Pub\n";
    cout << "4. Latihan\n";
    cout << "5. Cek Karakter\n";
    cout << "6. Keluar\n";
    cout << "======================" << endl;
    cout << "Tip: " << "\n";
    cout << "Masukkan pilihan Anda (1-6): ";
    cin >> choice;
    while(choice < 0 || choice > 6){
        cout << "Pilihan tidak valid. Masukkan pilihan Anda (1-6): ";
        cin >> choice;
    }
    if(choice == 6){
        popMenu(Menu);
    }else{
        switch(choice){
        case 1:
            pushMenu(Menu,1);
            break;
        case 2:
            pushMenu(Menu,2);
            break;
        case 3:
            pushMenu(Menu,3);
            break;
        case 4:
            pushMenu(Menu,4);
            break;
        case 5:
            pushMenu(Menu,5);
            break;
        }
    }
}

void adventure(){
    cout << "Coming soon";
    getch();
    popMenu(Menu);
}
void shop(){
    cout << "Coming soon";
    getch();
    popMenu(Menu);
}
void pub(){
    cout << "Coming soon";
    getch();
    popMenu(Menu);
}
void training(){
    cout << "Coming soon";
    getch();
    popMenu(Menu);
}
void check(){
    cout << "Coming soon";
    getch();
    popMenu(Menu);
}

void initiateTop(){
    system("cls");
    switch(Menu.info[Menu.top]){
    case 0:
        mainMenu();
        break;
    case 1:
        adventure();
        break;
    case 2:
        shop();
        break;
    case 3:
        pub();
        break;
    case 4:
        training();
        break;
    case 5:
        check();
        break;
    }
}
