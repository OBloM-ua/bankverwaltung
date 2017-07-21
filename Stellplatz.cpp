#include"Stellplatz.h"

Stellplatz::Stellplatz(Ptyp t){
    ptyp = t;
    frei = true;
}

//ostream& Stellplatz::print(ostream &o) const {
//    o << "[";
//    if (ptyp == Ptyp::pkw) o << "PKW";
//    if (ptyp == Ptyp::bus) o << "BUS";
//    if (ptyp == Ptyp::krad) o << "2RAD";
//
//    if (frei == false) o << " belegt";
//
//    return o << "]";
//}

ostream& operator<< (ostream& o, const Stellplatz& s) {
    return s.print(o);
}