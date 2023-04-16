#include <iostream>
#include <vector>
#include <fstream>

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

struct Wenzel {
    int wartosc;
    Wenzel *rodzic;
    Wenzel *lewy;
    Wenzel *prawy;
    int kolor;
};

    typedef Wenzel *WenzelP;

class Drzewo {

private:
    WenzelP korzen;
    WenzelP pusty;
    //w poprzednich strukturach tego nie robiła ale tutaj aby lepiej się
    //połapać w kodzie dodałam wszytkie funkcje do nagłówka

    void wypisz_kolejnosc_algorytm(WenzelP wenzel);

    WenzelP przeszukiwanie_algorytm(WenzelP korzen, int klucz);

    void poprawa_usuwania(WenzelP x);

    void przeniesienie(WenzelP u, WenzelP v);

    void poprawka_wstawiania(WenzelP k);

    void wypisz_algorytm(WenzelP wenzel, std::string separator, bool strona);

    void rotacja_lewo(WenzelP x);

    void rotacja_prawo(WenzelP x);

    WenzelP minimum(WenzelP wenzel);

    void wypisz_do_pliku(WenzelP wenzel, std::string daneWyjsciowe);

public:

    Drzewo();

    void dodaj(int klucz);

    void usun(int wartosc);

    void wypisz();

    void przeszukaj(int k);

    void zapisz();

    int rozmiar_fun(WenzelP wenzel);
};
