#include <iostream>
#include <chrono>

//Imię i nazwisko: Justyna Bułach 262902
//Grupa projektowa: K03-37p – wtorek 15: 15 P
//Prowadzący: mgr inż. Antoni Sterna

using namespace std;
using namespace std::chrono;

class Czaso {
public:
    steady_clock::time_point start;
    steady_clock::time_point stop;

    void Start();

    void Stop();

    void Zmierzony_czas() const;

    long czas_do_pliku() const;
};


