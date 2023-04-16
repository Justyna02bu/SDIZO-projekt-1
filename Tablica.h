#include <fstream>

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

class Tablica {


public:
    //Zmienne
    int *wskaznik;

    int rozmiar;

    //Metody
    Tablica();

    ~Tablica();

    void dodaj_na_poczatek(int);

    void dodaj_na_koniec(int wartosc);

    void dodaj_na_pozycje(int wartosc, int pozycja);

    void usun_ostatni();

    void usun_pierwszy();

    void usun_na_pozycji(int pozycja);

    void wypisz_tablice();

    bool znajdz_element(int wartosc);

    void zapisz();
};