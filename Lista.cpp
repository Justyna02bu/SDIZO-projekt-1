#include <iostream>
#include "Lista.h"

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

using namespace std;

Lista::Lista() {
    Lista::pierwszy_element = nullptr;
    Lista::aktualny_element = nullptr;
    Lista::ostatni_element = nullptr;
    Lista::rozmiar = 0;
}

Lista::~Lista() {
    for (int i = 0; i < Lista::rozmiar; i++) {

        //Przepisanie kolejnych elementów listy jako aktualne
        aktualny_element = pierwszy_element->nastepny;

        //Usuwamanie pierwszwego elementu_listy
        delete pierwszy_element;

        pierwszy_element = aktualny_element;
    }
}

void Lista::dodaj_na_poczatek(int wartosc) {

    //Sprawdzanie, czy pierwszy element istnieje
    if (pierwszy_element == nullptr) {
        //Tworzenie nowego elementu i ustawianie go jako początkowy i końcowy
        pierwszy_element = new elementy_listy(wartosc, nullptr, nullptr);
        ostatni_element = pierwszy_element;

    }
    else {
        //Ustawianie elementu który był pierwszy na aktualny
        aktualny_element = pierwszy_element;


        //Ustawianie jego wartości oraz elementy_listy kolejny na elementy_listy aktualny (były pierwszy)
        //Zastępowanie pierwszego elementu nowym
        pierwszy_element = new elementy_listy(wartosc, aktualny_element, nullptr);
        aktualny_element->poprzedni = pierwszy_element;

    }


    rozmiar = rozmiar + 1;

}

void Lista::dodaj_na_koniec(int wartosc) {
    //Sprawdzanie, czy istnieje element początkowy
    if (pierwszy_element == nullptr) {
        //Tworzenie nowego elementu i ustawianie go jako element początkowy i końcowy
        ostatni_element = new elementy_listy(wartosc, nullptr, nullptr);
        pierwszy_element = ostatni_element;

    }
    else {
        //Ustawianie ostatniego elementu jako aktualny
        aktualny_element = ostatni_element;

        //Zastąpienie ostatniego elementy_listy nowym
        //Ustawienie jego wartości oraz elementy_listy poprzedni na elementy_listy aktualny (były ostatni)
        ostatni_element = new elementy_listy(wartosc, nullptr, aktualny_element);
        aktualny_element->nastepny = ostatni_element;
    }
    //Zwiększanie rozmiar_fun listy
    rozmiar++;
}

void Lista::dodaj_na_pozycje(int wartosc, int pozycja) {

    //Sprawdzanie czy pozycja jest w li�cie
    if (pozycja < 0 || pozycja >= rozmiar) {
        cout << "W liście nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }

    //Sprawdzanie czy pozycja jest pierwsza
    if (pozycja == 0) {
        Lista::dodaj_na_poczatek(wartosc);
        return;
    }

    //Sprawdzanie czy pozycja jest ostatnia
    if (pozycja == rozmiar - 1) {
        dodaj_na_koniec(wartosc);
        return;
    }

    //Sprawdzanie w której połowie listy znajduje się wybrany elementy_listy
    if (pozycja < rozmiar / 2) { //liczone od indeksu zerowego

        //Przypisanie za aktualny elementy_listy pierwszy
        aktualny_element = pierwszy_element;

        //Przesunięcie wszyskich elementów o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) {
            aktualny_element = aktualny_element->nastepny;
        }

    }
    else {

        //Przypisanie ostatniego jako aktualny
        aktualny_element = ostatni_element;

        //Przesunięcie wszystkich elementów o jedną pozycję do tyłu
        for (int i = 0; i < Lista::rozmiar - pozycja - 1; ++i) {
            aktualny_element = aktualny_element->poprzedni;
        }

    }

    //Stworzenie nowego elementy_listy listy z podanymi parametrami
    elementy_listy* nowy_element = new elementy_listy(wartosc, aktualny_element,
        aktualny_element->nastepny);

    //przypisanie nowego elementy_listy w odpowiednim miejscu tablicy
    aktualny_element->nastepny->poprzedni = nowy_element;
    aktualny_element->nastepny = nowy_element;
    rozmiar = rozmiar + 1;
}

void Lista::usun_pierwszy() {

    //przypisanie drugiego elementy_listy jako aktualny
    aktualny_element = pierwszy_element->nastepny;
    delete pierwszy_element;

    //Sprawdzenie, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustawienie aktualnego elementy_listy jako pierwszy
    //Jeżeli nie, wyzerowanie elementów listy
    if (rozmiar > 1) {
        aktualny_element->poprzedni = nullptr;
        pierwszy_element = aktualny_element;
    }
    else {
        aktualny_element = nullptr;
        pierwszy_element = nullptr;
        ostatni_element = nullptr;
    }

    rozmiar--;
}

void Lista::usun_ostatni() {

    //Przypisanie przedostaniego elementu jako aktualny
    aktualny_element = ostatni_element->poprzedni;

    //Usuwanie ostatniego elementu listy
    delete ostatni_element;

    //Sprawdzanie czy lista nie jest pusta
    if (rozmiar > 1) {
        aktualny_element->nastepny = nullptr;
        ostatni_element = aktualny_element;
    }
    else {
        aktualny_element = nullptr;
        pierwszy_element = nullptr;
        ostatni_element = nullptr;
    }


    rozmiar--;

}


void Lista::usun_na_pozycji(int pozycja) {
    if (pozycja < 0 || pozycja >= rozmiar) {
        cout << "Niepoprawna pozycja" << endl;
        return;
    }

    if (pozycja == 0) {
        usun_pierwszy();
        return;
    }
    if (pozycja == rozmiar - 1) {
        usun_ostatni();
        return;
    }

    int i = 0;
    elementy_listy* poprzedniElement = nullptr;
    aktualny_element = pierwszy_element;

    while (i < pozycja) {
        poprzedniElement = aktualny_element;
        aktualny_element = aktualny_element->nastepny;
        i++;
    }

    poprzedniElement->nastepny = aktualny_element->nastepny;
    delete aktualny_element;
    aktualny_element = nullptr;
    rozmiar--;
}

void Lista::znajdz_element(int wartosc) {


    if (rozmiar == 0) {
        return;
    }


    aktualny_element = pierwszy_element;

    //szukanie wartosci w liście
    for (int i = 0; i < rozmiar; i++) {
        if (aktualny_element->wartosc == wartosc) {
            cout << "wartosc jest na pozycji: " << i << endl;
            return;
        }

        aktualny_element = aktualny_element->nastepny;
    }
    cout << "Nie ma takiej wartości w tablicy" << endl;
}

void Lista::wypisz_liste() {
    if (rozmiar == 0) {
        cout << "Lista jest pusta" << endl;
        return;
    }


    aktualny_element = pierwszy_element;

    for (int i = 0; i < rozmiar; i++) {

        cout << "[" << i << "] " << aktualny_element->wartosc << endl;

        //Przypisywanie kolejnego elementu jako aktualny
        aktualny_element = aktualny_element->nastepny;

    }
}

void Lista::zapisz() {
    string daneWyjsciowe;
    ofstream plikWyjsciowy;
    daneWyjsciowe = "lista.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWyjsciowy << rozmiar << endl;
    aktualny_element = pierwszy_element;
    for (int i = 0; i < rozmiar; i++) {
        plikWyjsciowy << aktualny_element->wartosc << endl;
        if (aktualny_element == ostatni_element) i = rozmiar + 10;
        else aktualny_element = aktualny_element->nastepny;
    }
    plikWyjsciowy.clear();
    plikWyjsciowy.close();
}

elementy_listy::elementy_listy(int wartosc, elementy_listy* nastepny, elementy_listy* poprzedni) {

    elementy_listy::wartosc = wartosc;
    elementy_listy::nastepny = nastepny;
    elementy_listy::poprzedni = poprzedni;

}
