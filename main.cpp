#include"Parkhaus.h"


using namespace std;
int main()
{
    Stellplatz s1;
    Stellplatz s2{Ptyp::bus};
    if (s1.einparken(Ptyp::bus) || !s1.ist_frei()) cout << "Error 1\n";
    if (!s1.einparken(Ptyp::pkw) || s1.ist_frei()) cout << "Error 2\n";
    if (s1.einparken(Ptyp::pkw)) cout << "Error 3\n";

    try {
        s1.ausparken();
        s2.ausparken();
        cout << "Error 3\n";
    }
    catch (runtime_error& e)
    {
        cout << "Ausparken fehlgeschlagen!\n";
    }
    if (!s1.einparken(Ptyp::pkw) || s1.ist_frei()) cout << "Error 4\n";
    Parkhaus p{"Rathausplatz 1", {{Ptyp::bus},{Ptyp::bus},{Ptyp::krad},{Ptyp::pkw},{Ptyp::krad},{},s1,s2,{},{}}};
    try
    {
        Parkhaus p{"",{}};
        cout << "Hier nicht\n";
    }
    catch (runtime_error& e)
    {
        cout << "Exception OK\n";
    }
    cout << p << '\n';
    cout << p << '\n';

    //Dekommentieren fuer Zusatzbeispiel finde

    vector<Stellplatz> v{p.finde(Ptyp::pkw)};
    for (const auto& s : v)
        cout << s << " ";
    cout << '\n';


    //Dekommentieren fuer Zusatzbeispiel ein-/ausfahren

    p.einfahren(Ptyp::pkw);
    p.einfahren(Ptyp::krad);
    p.einfahren(Ptyp::bus);
    p.einfahren(Ptyp::krad);
    if (p.einfahren(Ptyp::krad)) cout << "Error 5\n";
    cout<<p<<'\n';
    try
    {
        p.ausfahren(0);
        p.ausfahren(1);
        cout << "Error 6\n";
    }
    catch (runtime_error& e)
    {
        cout << "Kann nicht von leerem Platz ausfahren!\n";
    }
    try
    {
        p.einfahren(Ptyp::pkw);
        p.ausfahren(3);
        p.ausfahren(100);
        cout << "Error 7\n";
    }
    catch (runtime_error& e)
    {
        cout << "Ungueltige Platznummer!\n";
    }
    cout << p << '\n';

    return 0;
}
