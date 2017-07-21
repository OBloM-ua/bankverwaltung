#ifndef STELLPLATZ_H
#define STELLPLATZ_H

#include<iostream>
#include<stdexcept>

using namespace std;

enum class Ptyp {
    pkw, bus, krad
};

class Stellplatz {
    Ptyp ptyp;
    bool frei;
public:

    Stellplatz(Ptyp t = Ptyp::pkw);

    bool ist_frei() const { return frei; }

    bool passt(Ptyp typ) const {
        if (typ == ptyp) return true;
        else return false;
    }

    bool einparken(Ptyp typ) {

        if (passt(typ) && ist_frei()) {
            frei = false;
            return true;

        } else return false;

    }

    void ausparken() {
        if (frei == true) throw runtime_error("error 2");
        else frei = true;
    }




    ostream &print(ostream &o) const {
        o << "[";
        if (ptyp == Ptyp::pkw) o << "PKW";
        if (ptyp == Ptyp::bus) o << "BUS";
        if (ptyp == Ptyp::krad) o << "2RAD";

        if (frei == false) o << " belegt";

        return o << "]";
    }

};

ostream& operator<< (ostream& o, const Stellplatz& s);


#endif
