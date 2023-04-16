
#include <iostream>
#include <fstream>

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

using namespace std;

class elementy_listy {

public:
    elementy_listy* nastepny;
    elementy_listy* poprzedni;
    int wartosc;

    elementy_listy(int, elementy_listy*, elementy_listy*);
};



class Lista {

public:

    int rozmiar;

    Lista();

    ~Lista();

    elementy_listy* pierwszy_element;
    elementy_listy* ostatni_element;
    elementy_listy* aktualny_element;

    void dodaj_na_poczatek(int wartosc);

    void dodaj_na_koniec(int wartosc);

    void dodaj_na_pozycje(int wartosc, int pozycja);

    void wypisz_liste();

    void usun_pierwszy();

    void usun_ostatni();

    void usun_na_pozycji(int);

    void znajdz_element(int wartosc);

    void zapisz();
};




