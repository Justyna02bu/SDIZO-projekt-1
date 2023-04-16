#include <vector>
#include <iostream>
#include <fstream>
#include "Drzewo.h"

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

using namespace std;

    Drzewo::Drzewo() {
        pusty = new Wenzel;
        pusty->kolor = 0;
        pusty->wartosc = 0;
        pusty->lewy = nullptr;
        pusty->prawy = nullptr;
        korzen = pusty;
    }

    // przeszukiwanie drzewa i wypisywanie w kolejności preorder
    void Drzewo::przeszukaj(int k) {
        cout << endl << "wypisuję w kolejności pre order zawartość drzewa od wskazanego elementu" << endl;
        wypisz_kolejnosc_algorytm(przeszukiwanie_algorytm(this->korzen, k));
    }
    //wypisanie kolejności algorytmu
    void Drzewo::wypisz_kolejnosc_algorytm(WenzelP wenzel) {
        if (wenzel != pusty) {
            cout << wenzel->wartosc << ", ";
            wypisz_kolejnosc_algorytm(wenzel->lewy);
            wypisz_kolejnosc_algorytm(wenzel->prawy);
        }
    }

    WenzelP Drzewo::przeszukiwanie_algorytm(WenzelP korzen, int klucz) {
        if (korzen == pusty || klucz == korzen->wartosc) {
            return korzen;
        }

        if (klucz <= korzen->wartosc) {
            return przeszukiwanie_algorytm(korzen->lewy, klucz);
        }
        return przeszukiwanie_algorytm(korzen->prawy, klucz);
    }

    //algorytm usuwania i jego poprawka
    void Drzewo::usun(int wartosc) {
        WenzelP wenzel = this->korzen;
        WenzelP z = pusty;
        WenzelP x, y;
        while (wenzel != pusty) {
            if (wenzel->wartosc == wartosc) {
                z = wenzel;
            }

            if (wenzel->wartosc <= wartosc) {
                wenzel = wenzel->prawy;
            } else {
                wenzel = wenzel->lewy;
            }
        }

        if (z == pusty) {
            cout << "Nie znaleziono klucza w drzewie" << endl;
            return;
        }

        y = z;
        int y_oryginalny_kolor = y->kolor;
        if (z->lewy == pusty) {
            x = z->prawy;
            przeniesienie(z, z->prawy);
        } else if (z->prawy == pusty) {
            x = z->lewy;

            przeniesienie(z, z->lewy);
        } else {
            y = minimum(z->prawy);
            y_oryginalny_kolor = y->kolor;
            x = y->prawy;
            if (y->rodzic == z) {
                x->rodzic = y;
            } else {
                przeniesienie(y, y->prawy);
                y->prawy = z->prawy;
                y->prawy->rodzic = y;
            }

            przeniesienie(z, y);
            y->lewy = z->lewy;
            y->lewy->rodzic = y;
            y->kolor = z->kolor;
        }
        delete z;
        if (y_oryginalny_kolor == 0) {
            poprawa_usuwania(x);
        }
    }
//popraawki to kodty które są odzielone od głównego algorytmu dla przejrzystości
//zawierają one wypadki w których trzeba baprawiać kod
void Drzewo::poprawa_usuwania(WenzelP x) {
    WenzelP s;
    while (x != korzen && x->kolor == 0) {
        if (x == x->rodzic->lewy) {
            s = x->rodzic->prawy;
            if (s->kolor == 1) {
                s->kolor = 0;
                x->rodzic->kolor = 1;
                rotacja_lewo(x->rodzic);
                s = x->rodzic->prawy;
            }

            if (s->lewy->kolor == 0 && s->prawy->kolor == 0) {
                s->kolor = 1;
                x = x->rodzic;
            } else {
                if (s->prawy->kolor == 0) {
                    s->lewy->kolor = 0;
                    s->kolor = 1;
                    rotacja_prawo(s);
                    s = x->rodzic->prawy;
                }

                s->kolor = x->rodzic->kolor;
                x->rodzic->kolor = 0;
                s->prawy->kolor = 0;
                rotacja_lewo(x->rodzic);
                x = korzen;
            }
        } else {
            s = x->rodzic->lewy;
            if (s->kolor == 1) {
                s->kolor = 0;
                x->rodzic->kolor = 1;
                rotacja_prawo(x->rodzic);
                s = x->rodzic->lewy;
            }

            if (s->prawy->kolor == 0) {
                s->kolor = 1;
                x = x->rodzic;
            } else {
                if (s->lewy->kolor == 0) {
                    s->prawy->kolor = 0;
                    s->kolor = 1;
                    rotacja_lewo(s);
                    s = x->rodzic->lewy;
                }

                s->kolor = x->rodzic->kolor;
                x->rodzic->kolor = 0;
                s->lewy->kolor = 0;
                rotacja_prawo(x->rodzic);
                x = korzen;
            }
        }
    }
    x->kolor = 0;
}

void Drzewo::przeniesienie(WenzelP u, WenzelP v) {
    if (u->rodzic == nullptr) {
        korzen = v;
    } else if (u == u->rodzic->lewy) {
        u->rodzic->lewy = v;
    } else {
        u->rodzic->prawy = v;
    }
    v->rodzic = u->rodzic;
}

// minimum zostało dodane do oddzielnej funkcji aby ułatwić szuaknie następnika
WenzelP Drzewo::minimum(WenzelP wenzel) {
    while (wenzel->lewy != pusty) {
        wenzel = wenzel->lewy;
    }
    return wenzel;
}


// algorytm wstawiania i jego poprawka
void Drzewo::dodaj(int klucz) {
    WenzelP wenzel = new Wenzel;
    wenzel->rodzic = nullptr;
    wenzel->wartosc = klucz;
    wenzel->lewy = pusty;
    wenzel->prawy = pusty;
    wenzel->kolor = 1;

    WenzelP y = nullptr;
    WenzelP x = this->korzen;

    while (x != pusty) {
        y = x;
        if (wenzel->wartosc < x->wartosc) {
            x = x->lewy;
        } else {
            x = x->prawy;
        }
    }

    wenzel->rodzic = y;
    if (y == nullptr) {
        korzen = wenzel;
    } else if (wenzel->wartosc < y->wartosc) {
        y->lewy = wenzel;
    } else {
        y->prawy = wenzel;
    }

    if (wenzel->rodzic == nullptr) {
        wenzel->kolor = 0;
        return;
    }

    if (wenzel->rodzic->rodzic == nullptr) {
        return;
    }

    poprawka_wstawiania(wenzel);
}
//tak jak przy odejmowania poprawka odnawia właściwości kopca
    void Drzewo::poprawka_wstawiania(WenzelP k) {
        WenzelP u;
        while (k->rodzic->kolor == 1) {
            if (k->rodzic == k->rodzic->rodzic->prawy) {
                u = k->rodzic->rodzic->lewy;
                if (u->kolor == 1) {
                    u->kolor = 0;
                    k->rodzic->kolor = 0;
                    k->rodzic->rodzic->kolor = 1;
                    k = k->rodzic->rodzic;
                } else {
                    if (k == k->rodzic->lewy) {
                        k = k->rodzic;
                        rotacja_prawo(k);
                    }
                    k->rodzic->kolor = 0;
                    k->rodzic->rodzic->kolor = 1;
                    rotacja_lewo(k->rodzic->rodzic);
                }
            } else {
                u = k->rodzic->rodzic->prawy;

                if (u->kolor == 1) {
                    u->kolor = 0;
                    k->rodzic->kolor = 0;
                    k->rodzic->rodzic->kolor = 1;
                    k = k->rodzic->rodzic;
                } else {
                    if (k == k->rodzic->prawy) {
                        k = k->rodzic;
                        rotacja_lewo(k);
                    }
                    k->rodzic->kolor = 0;
                    k->rodzic->rodzic->kolor = 1;
                    rotacja_prawo(k->rodzic->rodzic);
                }
            }
            if (k == korzen) {
                break;
            }
        }
        korzen->kolor = 0;
    }
    // wypisywanie
    void Drzewo::wypisz() {
        cout << "Wypisuje koppiec. Węzły połączone kreską znajdują się na tym samym poziomie." << endl;
        cout << "Czerwwony -> ○" << endl;
        cout << "Czarny -> ●" << endl;
        if (korzen) {
            wypisz_algorytm(this->korzen, "", true);
        }
    }

    void Drzewo::wypisz_algorytm(WenzelP wenzel, string separator, bool strona) {
        if (wenzel != pusty) {
            cout << " ";
            if (strona) {
                cout << separator << "P:";
                separator += "   ";
            } else {
                cout << separator << "L:";
                separator += "|  ";
            }

            string kolor_za = wenzel->kolor ? "○" : "●";
            cout << wenzel->wartosc << "[" << kolor_za << "]" << endl;
            wypisz_algorytm(wenzel->lewy, separator, false);
            wypisz_algorytm(wenzel->prawy, separator, true);
        }
    }


    //rotacje
    void Drzewo::rotacja_lewo(WenzelP x) {
        WenzelP y = x->prawy;
        x->prawy = y->lewy;
        if (y->lewy != pusty) {
            y->lewy->rodzic = x;
        }
        y->rodzic = x->rodzic;
        if (x->rodzic == nullptr) {
            this->korzen = y;
        } else if (x == x->rodzic->lewy) {
            x->rodzic->lewy = y;
        } else {
            x->rodzic->prawy = y;
        }
        y->lewy = x;
        x->rodzic = y;
    }

    void Drzewo::rotacja_prawo(WenzelP x) {
        WenzelP y = x->lewy;
        x->lewy = y->prawy;
        if (y->prawy != pusty) {
            y->prawy->rodzic = x;
        }
        y->rodzic = x->rodzic;
        if (x->rodzic == nullptr) {
            this->korzen = y;
        } else if (x == x->rodzic->prawy) {
            x->rodzic->prawy = y;
        } else {
            x->rodzic->lewy = y;
        }
        y->prawy = x;
        x->rodzic = y;
    }

void Drzewo::zapisz() {
    string daneWyjsciowe;
    ofstream plikWyjsciowy;
    daneWyjsciowe = "drzewo.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWyjsciowy << rozmiar_fun(this->korzen) << endl;
    wypisz_do_pliku(this->korzen, daneWyjsciowe);
    plikWyjsciowy.close();
}

void Drzewo::wypisz_do_pliku(WenzelP wenzel, string daneWyjsciowe) {
    if (wenzel != pusty) {
        ofstream plikWyjsciowy(daneWyjsciowe, ios::app);
        plikWyjsciowy << wenzel->wartosc << endl;
        wypisz_do_pliku(wenzel->lewy, daneWyjsciowe);
        wypisz_do_pliku(wenzel->prawy, daneWyjsciowe);
    }
}

int Drzewo::rozmiar_fun(WenzelP wenzel) {
    if (wenzel != pusty) {
        int rozmiar = 1;
        rozmiar = rozmiar + rozmiar_fun(wenzel->lewy);
        rozmiar = rozmiar + rozmiar_fun(wenzel->prawy);
        return rozmiar;
    }
    else
        return 0;
}
