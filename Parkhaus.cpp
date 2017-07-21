#include"Parkhaus.h"


Parkhaus::Parkhaus(string s, vector<Stellplatz> v) : adresse(s), v(v) {
    if (s == "") throw runtime_error("error adresse");
}


vector<Stellplatz> Parkhaus::finde(Ptyp typ) const {

    vector<Stellplatz> vv;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].passt(typ) && v[i].ist_frei()) {
            vv.push_back(v[i]);
        }
    }
    return vv;

}

bool Parkhaus::einfahren(Ptyp typ) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].ist_frei() && v[i].passt(typ)) {
            v[i].einparken(typ);
            return true;
        }

    }
    return false;

}

void Parkhaus::ausfahren(size_t no) {
    if (v.size() < no) throw runtime_error("error 80");
//    if(v[no].ist_frei()) throw runtime_error ("error 80");
    v[no].ausparken();

}


ostream &operator<<(ostream &o, const Parkhaus &s) {
    return s.print(o);
}