#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class karakter {
private:
    int kimlikid;
public:
    float para;
    float aclik;
    float susuzluk;
    bool uyku;
    float guc;
    int x, y;

    void getpara(float para) { this->para = para; };
    void getaclik(float aclik) { this->aclik = aclik; };
    void getsusuzluk(float susuzluk) { this->susuzluk = susuzluk; };
    void getguc(float guc) { this->guc = guc; };

    float setpara() { return para; };
    float setaclik() { return aclik; };
    float setsusuzluk() { return susuzluk; };
    float setguc() { return guc; };

        void aclikdurumu();
        void susuzlukdurumu();
        void yemekYedir();
        void suIc();
        void hareket(int x, int y);
        void hareket(float distance);
        void durumGoster();  // Yeni eklenen durumGoster metodu
    };

void karakter::aclikdurumu() {
    while (true) {
        aclik = aclik - 5;
        if (aclik <= 20) {
            cout << "Karakter yemek yedi. Açlık sorunu giderildi.";
            aclik = 100;
        }
        this_thread::sleep_for(chrono::seconds(10));
    }
}

void karakter::susuzlukdurumu() {
    while (true) {
        susuzluk = susuzluk - 5;
        if (susuzluk <= 20) {
            cout << "Karakter su içti. Susuzluk sorunu giderildi.";
            susuzluk = 100;
        }
        this_thread::sleep_for(chrono::seconds(10));
    }
}

void karakter::yemekYedir() {
    cout << "Karakter yemek yedi. Açlık sorunu giderildi." << endl;
    aclik = 100;
}

void karakter::suIc() {
    cout << "Karakter su içti. Susuzluk sorunu giderildi." << endl;
    susuzluk = 100;
}

void guckarsilastirma(float guc1, float guc2) {
    if (guc1 == guc2) {
        cout << "Karakterlerin güçleri birbirine eşittir." << endl;
    }
    else if (guc1 > guc2) {
        cout << "Karakter1 daha güçlüdür." << endl;
    }
    else if (guc1 < guc2) {
        cout << "Karakter2 daha güçlüdür." << endl;
    }
}

void karakter::hareket(int x, int y) {
    int yon;
    cout << "Hangi yöne hareket etsin? 0-SOL 1-SAG 2-YUKARI 3-ASAGI";
    cin >> yon;
    switch (yon) {
        case 0:
            cout << "Sola hareket etti" << endl;
            x = x - 1;
            break;
        case 1:
            cout << "Sağa hareket etti" << endl;
            x = x + 1;
            break;
        case 2:
            cout << "Yukarı hareket etti" << endl;
            y = y + 1;
            break;
        case 3:
            cout << "Aşağı hareket etti" << endl;
            y = y - 1;
            break;
        default:
            cout << "Geçersiz seçim" << endl;
    }
    cout << "Mevcut konumu:" << x << "," << y << endl;
}

void karakter::hareket(float distance) {
    cout << "Karakter belirtilen mesafeye hareket etti." << endl;
}

void karakter::durumGoster() {
    cout << "Karakter Durumu:" << endl;
    cout << "Para: " << para << endl;
    cout << "Açlık: " << aclik << endl;
    cout << "Susuzluk: " << susuzluk << endl;
    cout << "Güç: " << guc << endl;
}

void paraaktarma(float &para1, float &para2) {
    int karakternumarasi;
    float miktar;
    cout << "Hangi karakter para göndersin?" << endl;
    cin >> karakternumarasi;
    cout << "Ne kadar para yollasin?";
    cin >> miktar;

    switch (karakternumarasi) {
        case 1:
            if (para1 <= 0 || para1 < miktar) {
                cout << "Yetersiz Bakiye" << endl;;
                break;
            }
            para1 = para1 - miktar;
            para2 = para2 + miktar;
            cout << "Karakter1 " << miktar << " TL Karakter2'ye aktardi." << endl;
            cout << "Karakter1 mevcut para:" << para1 << endl;
            cout << "Karakter2 mevcut para:" << para2 << endl;
            break;

        case 2:
            if (para2 <= 0 || para2 < miktar) {
                cout << "Yetersiz Bakiye" << endl;
                break;
            }
            para2 = para2 - miktar;
            para1 = para1 + miktar;
            cout << "Karakter2 " << miktar << " TL Karakter1'ye aktardi." << endl;
            cout << "Karakter1 mevcut para:" << para1 << endl;
            cout << "Karakter2 mevcut para:" << para2 << endl;
            break;

        default:
            cout << "Geçersiz karakter numarasi" << endl;
            break;
    }
}

int main() {

    karakter karakter1, karakter2, karakter3;
    karakter1.getaclik(63); karakter2.getaclik(98); karakter3.getaclik(75);
    karakter1.getsusuzluk(100); karakter2.getsusuzluk(100); karakter3.getsusuzluk(90);
    karakter1.getguc(500); karakter2.getguc(888); karakter3.getguc(750);
    karakter1.getpara(963); karakter2.getpara(358); karakter3.getpara(500);

    int islem;
    int karakteradi;

    cout << "Islem Menusu" << endl;
    cout << "1-Karakterlerin güçlerini karsilastirma" << endl;
    cout << "2-Karakteri hareket ettir" << endl;
    cout << "3-Para Aktarma" << endl;
    cout << "4-Karakter Durumu Göster" << endl;
    cout << "5-Oyunu bitir." << endl;
    cout << "6-Yemek yedir." << endl;
    cout << "7-Su icir." << endl;

    bool devam = true;
    while (devam == true) {
        cout << "Islem seciniz:";
        cin >> islem;
        switch (islem) {
            case 1:
                guckarsilastirma(karakter1.setguc(), karakter2.setguc());
                break;
            case 2:
                cout << "Hangi karakter hareket etsin?";
                cin >> karakteradi;
                if (karakteradi == 1) {
                    karakter1.hareket(0, 0);
                }
                else if (karakteradi == 2) {
                    karakter2.hareket(5, 3);
                }
                else if (karakteradi == 3) {
                    karakter3.hareket(2, 7);
                }
                else {
                    cout << "Gecersiz karakter numarasi girdiniz!!" << endl;
                }
                break;
            case 3:
                paraaktarma(karakter1.para, karakter2.para);
                break;
            case 4:
                karakter1.durumGoster();
                karakter2.durumGoster();
                karakter3.durumGoster();
                break;
            case 5:
                devam = false;
                break;
                
                // Inside the main function...

                case 6:
                    cout << "Hangi karaktere yemek yedirmek istiyorsunuz? (1, 2 veya 3): ";
                    cin >> karakteradi;
                    if (karakteradi == 1) {
                        karakter1.yemekYedir();
                    } else if (karakteradi == 2) {
                        karakter2.yemekYedir();
                    } else if (karakteradi == 3) {
                        karakter3.yemekYedir();
                    } else {
                        cout << "Geçersiz karakter numarası girdiniz!!" << endl;
                    }
                    break;
                
                
            case 7:
                cout << "Hangi karaktere su içirmek istiyorsunuz? (1, 2 veya 3): ";
                cin >> karakteradi;
                if (karakteradi == 1) {
                    karakter1.suIc();
                } else if (karakteradi == 2) {
                    karakter2.suIc();
                } else if (karakteradi == 3) {
                    karakter3.suIc();
                } else {
                    cout << "Geçersiz karakter numarası girdiniz!!" << endl;
                }
                break;

            
            default:
                cout << "Gecersiz islem" << endl;
                break;
        }
    }
    cout << "OYUN BİTTİ :)" << endl;

    return 0;
}


