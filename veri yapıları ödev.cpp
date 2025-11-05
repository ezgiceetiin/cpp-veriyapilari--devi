#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Icecek {
private:
    string isim;
    double fiyat;
    int stok;

public:
    Icecek(string _isim, double _fiyat, int _stok) : isim(_isim), fiyat(_fiyat), stok(_stok) {}

    string getIsim() const {
        return isim;
    }

    double getFiyat() const {
        return fiyat;
    }

    int getStok() const {
        return stok;
    }

    bool satinAl(int adet) {
        if (stok >= adet) {
            stok -= adet;
            return true;
        }
        return false;
    }

    void stokYenile(int adet) {
        stok += adet;
    }
};

int main() {
    setlocale(LC_ALL, "Turkish");
    float kasa = 500; // Başlangıçta kasada 500 TL

    Icecek icecekler[10] = {
        Icecek("su", 10.25, 10),
        Icecek("soda", 15.50, 10),
        Icecek("süt", 20.75, 10),
        Icecek("kola", 25.25, 10),
        Icecek("sprite", 30.50, 10),
        Icecek("filtre", 35.75, 10),
        Icecek("frappe", 40.25, 10),
        Icecek("latte", 45.50, 10),
        Icecek("mocha", 50.75, 10),
        Icecek("cortado", 55.25, 10)
    };

    while (true) {
        // İçecek listesini göster
        cout << "İçecek Listesi ve Fiyatlar:" << endl << endl;
        cout << "ID\tİSİM\t\t\tFİYAT" << endl << endl;
        for (int i = 0; i < 10; ++i) {
            cout << (i + 1) << "\t" << icecekler[i].getIsim() << "\t\t\t" << icecekler[i].getFiyat() << endl << endl;
        }

        // İçecek seçimi
        int secim;
        cout << "Merhaba, lütfen içeceğinizi ID ile seçiniz: ";
        cin >> secim;

        if (secim < 1 || secim > 10) {
            cout << "Hatalı giriş! Lütfen geçerli bir ID giriniz." << endl;
            continue;
        }

        // Adet miktarı girişi
        int adet;
        cout << "Adet miktarı giriniz (1-10 arası): ";
        cin >> adet;

        if (adet < 1 || adet > 10) {
            cout << "Hatalı giriş! Lütfen 1 ile 10 arasında bir adet miktarı giriniz." << endl;
            continue;
        }

        // İçecek satın alma işlemi
        if (icecekler[secim - 1].satinAl(adet)) {
            double toplamFiyat = adet * icecekler[secim - 1].getFiyat();
            cout << "Ödeme tamamlandı. Toplam fiyat: " << fixed << setprecision(2) << toplamFiyat << " TL" << endl;

            // Kullanıcıdan ödeme alma ve para üstünü hesaplama
            double odeme;
            cout << "Ödeme miktarını giriniz: ";
            cin >> odeme;

            if (odeme < toplamFiyat) {
                cout << "Girilen miktar yetersiz!" << endl;
                icecekler[secim - 1].stokYenile(adet); // Stoku geri al
            } else {
                double paraUstu = odeme - toplamFiyat;
                kasa += toplamFiyat; // Kasa güncelle
                cout << "Para üstü: " << fixed << setprecision(2) << paraUstu << " TL" << endl;
                cout << "Kasanın güncel durumu: " << fixed << setprecision(2) << kasa << " TL" << endl; // Kasa güncel durumu
            }
        } else {
            cout << "Üzgünüz, yeterli stok bulunmamaktadır." << endl;
        }

        cout << "Yeni işlem için 1'e, çıkış için 0'a basınız: ";
        int devam;
        cin >> devam;

        if (devam == 0) {
            break;
        } else if (devam != 1) {
            cout << "Geçersiz seçim. Çıkış yapılıyor." << endl;
            break;
        }
    }

    return 0;
}
