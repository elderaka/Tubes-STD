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
        cout <<"Ketik mana saja untuk lanjut"<< endl;
        getch();
        system("cls");
    }

}
void mainmenu(){
    cout << " __| |____________________________________________| |__\n"
"(__   ____________________________________________   __)\n"
"   | |           Welcome To  Bensin Impek         | |\n"
"   | |                                            | |\n"
"   | |                                            | |\n"
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
    x[0] = "Selamat datang, pemberani, di dunia mistis Eldoria! Sebuah tanah yang penuh dengan sihir, dipenuhi makhluk mitos, dan dihiasi dengan harta karun yang tak terhitung jumlahnya. Angin takdir membawamu ke kota kecil Everhaven, di mana sebuah ramalan kuno meramalkan penemuan Pusaka yang Hilang—artefak kuat yang menyimpan kunci untuk mengembalikan keseimbangan dunia.\n";
    print(x,0,false);
    x[1] = "Saat kamu memasuki kota yang ramai, jalan-jalan berkerikil dan bangunan-bangunan berkerangka kayu bergema dengan kisah-kisah pahlawan dan bisikan kegelapan yang akan datang. Penduduk kota berkumpul di pasar yang hidup, dengan penuh antusias menantikan kedatangan yang terpilih—para pahlawan yang ditakdirkan untuk memulai pencarian berbahaya ini, menemukan Pusaka yang Hilang, dan menyelamatkan Eldoria.\n";
    print(x,1,false);
    x[2] = "Sekarang, pahlawan yang berani, saatnya bagi Anda untuk masuk ke dalam karakter Anda. Apa nama Anda, yang akan dinyanyikan dalam balada sepanjang negeri? Ucapkan dengan lantang, dan biarkan namamu terukir dalam sejarah Eldoria.\n";
    print(x,2,true);
    cout << "\nMasukkan nama kamu:";
    cin >> Player.name;
    system("cls");
    x[3] = "Ah, " + Player.name + ", sebuah nama yang membawa beban takdir. \n\nSaat Anda menjelajahi kota, Anda menemukan seorang pedagang tua misterius di sudut terpencil pasar. Dia merasakan percikan petualangan dalam diri Anda dan menawarkan Anda pilihan dari tiga item awal untuk membantu Anda dalam perjalanan Anda.\n";
    print(x,3,false);
    x[4] = "Pedagang: Hehe, anak muda. Aku memiliki barang. Silahkan pilih salah satu\n";
    print(x,4,true);
    showObject(OL);
    cout << "Pilih salah satu" << endl;
    cin >> Object.name;
    while(findObject(OL,Object.name) == NULL){
        cout << "Barang tidak tersedia, Pilih salah satu" << endl;
        cin >> Object.name;
    }
    x[5] = "Pedagang: Kamu memilih " + Object.name + "? Pilihan yang bagus\n";
    system("cls");
    print(x,5,false);
    x[6] = "Sekarang, pilih class kamu:";
    print(x,6,true);
    showSkillByLevel(ST,2);
    cout << "Pilih salah satu" << endl;
    cin >> Skill.name;
    while(findskill(ST,Skill.name) == NULL){
        cout << "Skill tidak tersedia, Pilih salah satu" << endl;
        cin >> Skill.name;
    }
}
