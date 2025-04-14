//  Student: Thomas Ghysels
//  Rolnummer: s0210741
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#ifndef SCHAKEN_SCHAAKSTUK_H
#define SCHAKEN_SCHAAKSTUK_H
#include <guicode/chessboard.h>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;


class Game;

enum zw{zwart,wit};


class SchaakStuk {
public:
    SchaakStuk(zw kleur): kleur(kleur) {}

    virtual Piece piece() const=0;      // Verander deze functie niet!
                                        // Deze functie wordt gebruikt door
                                        // setItem(x,y,SchaakStuk*) van
                                        // SchaakGUI

    zw getKleur() const { return kleur; }

    virtual vector<pair<int,int>> geldige_zetten(Game& g);

    virtual const string &getType() const {return type;}


private:
    zw kleur;
    const string type;
};

class Pion:public SchaakStuk {
public:
    Pion(zw kleur):SchaakStuk(kleur) {}
    virtual Piece piece() const override {
        return Piece(Piece::Pawn,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(Game& g);

    const string &getType() const {return type;}

private:
    const string type = "pion";
};

class Toren:public SchaakStuk {
public:
    Toren(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::Rook,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(Game& g);

    const string &getType() const {return type;}

private:
    const string type = "toren";
};

class Paard:public SchaakStuk {
public:
    Paard(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::Knight,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(Game& g);

    const string &getType() const {return type;}

private:
    const string type = "paard";
};

class Loper:public SchaakStuk {
public:
    Loper(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::Bishop,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(Game& g);

    const string &getType() const{return type;};

private:
    const string type = "loper";
};

class Koning:public SchaakStuk {
public:


    Koning(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::King,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(Game& g);

    const string &getType() const{return type;};

private:
    const string type = "koning";
};

class Koningin:public SchaakStuk {
public:
    Koningin(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::Queen,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(Game& g);

    const string &getType() const {return type;}

private:
    const string type = "koningin";

};

#endif //SCHAKEN_SCHAAKSTUK_H
