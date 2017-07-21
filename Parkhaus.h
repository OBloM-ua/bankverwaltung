#ifndef PARKHAUS_H
#define PARKHAUS_H

#include"Stellplatz.h"

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;


class Parkhaus {
    string adresse;
    vector<Stellplatz> v;
public:
    Parkhaus(string, vector<Stellplatz>);

    vector<Stellplatz> finde(Ptyp typ) const;
    bool einfahren(Ptyp typ);
    void ausfahren(size_t no);

    ostream &print(ostream &o) const{
        o << "[" << adresse << "{";

        for (int i = 0; i < v.size(); ++i) {
            o << v[i];
            if (i != v.size()-1) o << ", ";
        }

        return o << "}]";
    }


};

ostream &operator<<(ostream &o, const Parkhaus &s);

#endif
