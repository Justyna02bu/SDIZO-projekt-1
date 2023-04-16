#include <iostream>
#include <vector>
#include <fstream>

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

class Kopiec {
    std::vector<int> kopiec;

public:
    Kopiec() {}

    void popraw(int);

    int usun_ze_szczytu();

    void wypisz_kopiec();

    void dodaj(int value);

    void czy_istnieje(int wartosc);

    void wypisz_kopiec2();

    int rozmiar_kopca = 0;

    void zapisz();
};

