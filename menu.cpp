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
void mainmenu(){
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
    cout << "\nMasukkan nama kamu:";
    cin >> Player.name;
    system("cls");
    x[3] = "Ah, " + Player.name + ", sebuah nama yang membawa beban takdir. \n\nSaat Anda menjelajahi kota, Anda menemukan seorang pedagang tua misterius di sudut terpencil pasar. Dia merasakan percikan petualangan Anda. \n";
    print(x,3,false);
    x[4] = "Pedagang tua: Wahai petualang, saya merasa ada suatu potensial tinggi dalam diri anda, keberuntungan saja saya lagi kelebihan stok suatu barang yang anda mungkin tertarik, \n\n kemudian pedagang tua tersebut mengeluarkan 3 barang yang tidak familiar dimana-mana. \n ";
    print(x,4,false);
    x[5] = "Pedagang tua: Hehe, anak muda. Dari setiap barang ini memiliki kekuatan yang akan bisa membuatmu SANGAT kuabt dibanding siapapun dan bisa dibilang kekuatan yang KEKAL, TAPI, jika kau sudah memilih, kau tidak akan bisa lagi berpisah dengan barangnya dan akan ada efek samping di setiap barang tersebut ini. Silahkan pilih salah satu dengan hati-hati: \n"; // show barang2 apa aja
    print(x,5,true);
    showObject(OL);
    cout << "Pilih salah satu:" << endl; // kan ad 3 pilihan nnt pilihan 4 kl bs mending kg ush pilih, jg show barang dh nnt yang ada apa aja
    cin >> Object.name;
    while(findObject(OL,Object.name) == NULL){
        cout << "Barang tidak tersedia, Pilih salah satu" << endl;
        cin >> Object.name;
    }
    x[6] = "Pedagang tua: Kamu memilih " + Object.name + "? Apakah Kamu Yakin?\n"; //nnt tambah bool dgn bs pilihan Y/N
    // Y/N
    x[7] = "Pedagang tua: Muahahaha, sekarang nasib kau sudah tercatat dalam gulungan takdir"; //Jika kg pilih samsek, makany replyny "Kau adalah petualang yang konyol dan bodoh menolak kekuatan kekal, PERGILAH SEKARANG"

    system("cls");
    print(x,5,false);
    x[6] = "Sekarang, pilih class kamu:"; //kg ush krn skill awalan emg 1
    print(x,6,true);
    showSkillByLevel(ST,2);
    cout << "Pilih salah satu" << endl; //  same kek atas
    cin >> Skill.name;
    while(findskill(ST,Skill.name) == NULL){
        cout << "Skill tidak tersedia, Pilih salah satu" << endl;
        cin >> Skill.name;
    }
}
