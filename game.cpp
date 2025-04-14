//  Student: Thomas Ghysels
//  Rolnummer: s0210741
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "game.h"

Game::Game() {}

Game::~Game() {}

// Zet het bord klaar; voeg de stukken op de jusite plaats toe
void Game::setStartBord() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; ++j) {
            bord[i][j] = nullptr;
        }
    }

    currpiece = nullptr;

    //BlackPawns
    SchaakStuk* PionZ1 = new Pion(zwart);
    SchaakStuk* PionZ2 = new Pion(zwart);
    SchaakStuk* PionZ3 = new Pion(zwart);
    SchaakStuk* PionZ4 = new Pion(zwart);
    SchaakStuk* PionZ5 = new Pion(zwart);
    SchaakStuk* PionZ6 = new Pion(zwart);
    SchaakStuk* PionZ7 = new Pion(zwart);
    SchaakStuk* PionZ8 = new Pion(zwart);

    //BlackPieces
    SchaakStuk* TorenZ1 = new Toren(zwart);
    SchaakStuk* PaardZ1 = new Paard(zwart);
    SchaakStuk* LoperZ1 = new Loper(zwart);
    SchaakStuk* DameZ = new Koningin(zwart);
    SchaakStuk* KoningZ = new Koning(zwart);
    SchaakStuk* LoperZ2 = new Loper(zwart);
    SchaakStuk* PaardZ2 = new Paard(zwart);
    SchaakStuk* TorenZ2 = new Toren(zwart);

    //set BlackPawns
    setPiece(1,0,PionZ1);
    setPiece(1,1,PionZ2);
    setPiece(1,2,PionZ3);
    setPiece(1,3,PionZ4);
    setPiece(1,4,PionZ5);
    setPiece(1,5,PionZ6);
    setPiece(1,6,PionZ7);
    setPiece(1,7,PionZ8);

    //set BlackPieces
    setPiece(0,0,TorenZ1);
    setPiece(0,1,PaardZ1);
    setPiece(0,2,LoperZ1);
    setPiece(0,3,DameZ);
    setPiece(0,4,KoningZ);
    setPiece(0,5,LoperZ2);
    setPiece(0,6,PaardZ2);
    setPiece(0,7,TorenZ2);

    //WhitePawns
    SchaakStuk* PionW1 = new Pion(wit);
    SchaakStuk* PionW2 = new Pion(wit);
    SchaakStuk* PionW3 = new Pion(wit);
    SchaakStuk* PionW4 = new Pion(wit);
    SchaakStuk* PionW5 = new Pion(wit);
    SchaakStuk* PionW6 = new Pion(wit);
    SchaakStuk* PionW7 = new Pion(wit);
    SchaakStuk* PionW8 = new Pion(wit);

    //WhitePieces
    SchaakStuk* TorenW1 = new Toren(wit);
    SchaakStuk* PaardW1 = new Paard(wit);
    SchaakStuk* LoperW1 = new Loper(wit);
    SchaakStuk* DameW = new Koningin(wit);
    SchaakStuk* KoningW = new Koning(wit);
    SchaakStuk* LoperW2 = new Loper(wit);
    SchaakStuk* PaardW2 = new Paard(wit);
    SchaakStuk* TorenW2 = new Toren(wit);

    //set WhitePawns
    setPiece(6,0,PionW1);
    setPiece(6,1,PionW2);
    setPiece(6,2,PionW3);
    setPiece(6,3,PionW4);
    setPiece(6,4,PionW5);
    setPiece(6,5,PionW6);
    setPiece(6,6,PionW7);
    setPiece(6,7,PionW8);

    //set WhitePieces
    setPiece(7,0,TorenW1);
    setPiece(7,1,PaardW1);
    setPiece(7,2,LoperW1);
    setPiece(7,3,DameW);
    setPiece(7,4,KoningW);
    setPiece(7,5,LoperW2);
    setPiece(7,6,PaardW2);
    setPiece(7,7,TorenW2);


}


pair<int,int> Game::currplace(SchaakStuk *piece) {//geprobeert me tuple maar onmogelijk, daarna met vector maar pair is simpeler
    //om de positie van een stuk te krijgen als een pair
    pair<int,int> place;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (getPiece(i,j) == piece){
              place.first = i;
              place.second = j;
            }
        }
    }
    return place;
}


// Verplaats stuk s naar positie (r,k)
// Als deze move niet mogelijk is, wordt false teruggegeven
// en verandert er niets aan het schaakbord.
// Anders wordt de move uitgevoerd en wordt true teruggegeven
bool Game::move(SchaakStuk* s, int r, int k){
    // gebruik find om een paar te vinden in geldige zetten.
    // als het er in zit return true anders false
    auto prevl = this->currplace(s);
    auto vector = s->geldige_zetten(*this);
    auto search = make_pair(r, k);


    auto res = find(vector.begin(),vector.end(),search);
    if (res != vector.end()){
        setPiece(r, k, s);
        setPiece(prevl.first,prevl.second, nullptr);
        return true;
    }
    return false;

}

SchaakStuk *Game::findKing(zw kleur) { // om de koning te vinden van een gegeven kleur.
    //SchaakStuk* foundKing;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            auto piece = getPiece(i,j);
            if (piece != nullptr && piece->getKleur() == kleur && piece->getType() == "koning"){
                return piece;
            }
        }
    }
}

// Geeft true als kleur schaak staat
bool Game::schaak(zw kleur) {
    auto king = findKing(kleur);
    SchaakStuk* temp;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(getPiece(i,j)->getKleur() != kleur){
                temp = getPiece(i,j);
            }
        }
    }

    for(auto pairs : temp->geldige_zetten(*this)){
        if (pairs == currplace(king)){
            return true;
        }
    }
    return false;
}

// Geeft true als kleur schaakmat staat
bool Game::schaakmat(zw kleur) {
    return false;
}

// Geeft true als kleur pat staat
// (pat = geen geldige zet mogelijk, maar kleur staat niet schaak;
// dit resulteert in een gelijkspel)
bool Game::pat(zw kleur) {
    return false;
}

// Geeft een pointer naar het schaakstuk dat op rij r, kolom k staat
// Als er geen schaakstuk staat op deze positie, geef nullptr terug
SchaakStuk* Game::getPiece(int r, int k) {
    // Hier komt jouw code om op te halen welk stuk op rij r, kolom k staat
    if (bord[r][k] == nullptr){
        return nullptr;
    }
    return bord[r][k];
}

// Zet het schaakstuk waar s naar verwijst neer op rij r, kolom k.
// Als er al een schaakstuk staat, wordt het overschreven.
// Bewaar in jouw datastructuur de *pointer* naar het schaakstuk,
// niet het schaakstuk zelf.
void Game::setPiece(int r, int k, SchaakStuk* s)
{
    // Hier komt jouw code om een stuk neer te zetten op het bord
    bord[r][k] = s;
}
//getter van de currpiece
SchaakStuk *Game::getCurrpiece() const {
    return currpiece;
}

//setter van de currpiece
void Game::setCurrpiece(SchaakStuk *currpiece) {
    Game::currpiece = currpiece;
}

//getter van currpersoon
zw Game::getCurrpersoon() const {
    return currpersoon;
}

//setter currpersoon
void Game::setCurrpersoon(zw currpersoon) {
    Game::currpersoon = currpersoon;
}




