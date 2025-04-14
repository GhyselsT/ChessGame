//  Student: Thomas Ghysels
//  Rolnummer: s0210741
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#ifndef SCHAKEN_GAME_H
#define SCHAKEN_GAME_H

#include "SchaakStuk.h"
#include "iostream"
using namespace std;

class Game {
// variabelen om de status van het spel/bord te bewaren
    SchaakStuk* currpiece = nullptr;//welk stuk er geselecteerd is
    zw currpersoon = wit;//welke kleur/persoon er bezig is


public:
    Game();
    ~Game();


    pair<int,int> currplace(SchaakStuk* piece); //die zorgt er voor dat ik de plaats van de pion returnt

    bool move(SchaakStuk* s,int r, int k); // Verplaats stuk s naar rij r en kolom k

    SchaakStuk* findKing(zw kleur); //om de Koning te vinden van een gegeven kleur


    bool schaak(zw kleur);
    bool schaakmat(zw kleur);
    bool pat(zw kleur);
    void setStartBord();

    SchaakStuk* getPiece(int r, int k);
    void setPiece(int r, int k, SchaakStuk* s);

    SchaakStuk *getCurrpiece() const;

    void setCurrpiece(SchaakStuk *currpiece);

    zw getCurrpersoon() const;

    void setCurrpersoon(zw currpersoon);

private:
    // Hier zet jij jouw datastructuur neer om het bord te bewaren ...
    // 2d array
    array<array<SchaakStuk*, 8>, 8> bord;
};


#endif //SCHAKEN_GAME_H
