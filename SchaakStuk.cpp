//  Student: Thomas Ghysels
//  Rolnummer: s0210741
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "SchaakStuk.h"
#include "game.h"

vector<pair<int, int>> SchaakStuk::geldige_zetten(Game &g) {
    return {};
}


//Possible moves for Pawn
vector<pair<int, int>> Pion::geldige_zetten(Game &g) {
    vector<pair<int, int>> possibilities;
    auto place = g.currplace(this);
    auto color = this->getKleur();

    if (color == zwart){
        if (g.getPiece(place.first+1,place.second) == nullptr && place.first+1 < 8){
            possibilities.emplace_back(place.first+1,place.second);
        }

        //Als de pion op de 1ste rij staat kan het2 zettern doen als er geen stuk staat of er tussen geen stuk staat
        //een pion kan niet springen over een andere stuk
        if (place.first == 1 and g.getPiece(place.first+2,place.second) == nullptr && g.getPiece(place.first+1,place.second) == nullptr) {
            possibilities.emplace_back(place.first + 2, place.second);
        }


        //Als er schuin rechts onder een stuk staat
        if (g.getPiece(place.first+1 ,place.second+1) != nullptr){
            if (g.getPiece(place.first+1,place.second+1)->getKleur() == wit) {
                possibilities.emplace_back(place.first + 1, place.second + 1);
            }
        }
        //als schuin links onder geen stuk staat
        if (g.getPiece(place.first+1,place.second-1) != nullptr){
            if (g.getPiece(place.first+1,place.second-1)->getKleur() == wit) {
                possibilities.emplace_back(place.first + 1, place.second - 1);
            }
        }
    }

    else if (color == wit){
        if (g.getPiece(place.first-1,place.second) == nullptr && place.first-1>=0) {
            possibilities.emplace_back(place.first - 1, place.second);
        }
        //zelfde als Zwart maar dan voor een witte pion
        if (place.first == 6 and g.getPiece(place.first-2,place.second) == nullptr and g.getPiece(place.first-1,place.second) == nullptr) {
            possibilities.emplace_back(place.first - 2, place.second);
        }

        if (g.getPiece(place.first-1,place.second+1) != nullptr){
            if (g.getPiece(place.first-1,place.second+1)->getKleur() == zwart) {
                possibilities.emplace_back(place.first - 1, place.second + 1);
            }
        }
        if (g.getPiece(place.first-1,place.second-1) != nullptr){
            if (g.getPiece(place.first-1,place.second-1)->getKleur() == zwart) {
                possibilities.emplace_back(place.first - 1, place.second - 1);
            }
        }
    }
    return possibilities;
}

//Possible moves for rook
vector<pair<int, int>> Toren::geldige_zetten(Game &g) {
    vector<pair<int,int>> possibilities;
    auto place = g.currplace(this); // plaats van de toren

    //beweging naar boven
    for (int i = place.first-1; i >= 0 ; --i) {
            //check of er geen stuk bovenstaat
            if (g.getPiece(i, place.second) == nullptr) {
                possibilities.emplace_back(i, place.second);
            }
            //als er wel een stuk staat
            if (g.getPiece(i, place.second) != nullptr) {
                //check de kleur
                if (g.getPiece(i, place.second)->getKleur() != this->getKleur()) {
                    possibilities.emplace_back(i, place.second);
                }
                if (g.getPiece(i, place.second)->getKleur() == this->getKleur()) {
                    break;
                }
            }
    }

    //beweging naar beneden
    for (int i = place.first + 1; i < 8; ++i) {
        //check of er geen stuk onderstaat
        if (g.getPiece(i,place.second) == nullptr){
            possibilities.emplace_back(i,place.second);
        }
        //als er wel een stuk staat
        if (g.getPiece(i,place.second) != nullptr){
            //check de kleur
            if (g.getPiece(i,place.second)->getKleur() != this->getKleur()){
                possibilities.emplace_back(i,place.second);
            }
            if (g.getPiece(i,place.second)->getKleur() == this->getKleur()){
                break;
            }
        }
    }

    //beweging naar links
    for (int i = place.second -1 ; i >= 0 ; --i) {
        //check of er geen stuk links staat
        if (g.getPiece(place.first,i) == nullptr){
            possibilities.emplace_back(place.first,i);
        }
        //als er wel een stuk staat
        if (g.getPiece(place.first,i) != nullptr){
            //check de kleur
            if (g.getPiece(place.first,i)->getKleur() != this->getKleur()){
                possibilities.emplace_back(place.first,i);
            }
            if (g.getPiece(place.first,i)->getKleur() == this->getKleur()){
                break;
            }
        }
    }

    //beweging naar rechts
    for (int i = place.second+1; i < 8; ++i) {
        //check of er geen stuk staat
        if (g.getPiece(place.first,i) == nullptr){
            possibilities.emplace_back(place.first,i);
        }
        //als er wel een stuk staat
        if (g.getPiece(place.first,i) != nullptr){
            //check de kleur
            if (g.getPiece(place.first,i)->getKleur() != this->getKleur()){
                possibilities.emplace_back(place.first,i);
            }
            if (g.getPiece(place.first,i)->getKleur() == this->getKleur()){
                break;
            }
        }
    }

    return possibilities;
}

//Possible moves for horse
vector<pair<int, int>> Paard::geldige_zetten(Game& g) {
    vector<pair<int,int>> possibilities;
    auto place = g.currplace(this);

    ///2up1right
    if (place.first-2 >= 0 && place.second+1 < 8) {
        //check of er iets staat
        if (g.getPiece(place.first - 2, place.second + 1) == nullptr) {
            possibilities.emplace_back(place.first - 2, place.second + 1);
        }
        //als er een stuk staat di een verschillende kleur heeft
        if (g.getPiece(place.first - 2, place.second + 1) != nullptr &&
            g.getPiece(place.first - 2, place.second + 1)->getKleur() != this->getKleur()) {
            possibilities.emplace_back(place.first - 2, place.second + 1);
        }
    }

    ///1up2right
    if (place.first-1 >= 0 && place.second+2 < 8) {
        //check of er iets staat
        if (g.getPiece(place.first - 1, place.second + 2) == nullptr) {
            possibilities.emplace_back(place.first - 1, place.second + 2);
        }
        //als er iets staaten de kleur is verschillend
        if (g.getPiece(place.first - 1, place.second + 2) != nullptr &&
            g.getPiece(place.first - 1, place.second + 2)->getKleur() != this->getKleur()) {
            possibilities.emplace_back(place.first - 1, place.second + 2);
        }
    }

    ///1down2right
    if (place.first+1 < 8 && place.second+2 < 8) {
        //check of er iets staat
        if (g.getPiece(place.first + 1, place.second + 2) == nullptr) {
            possibilities.emplace_back(place.first + 1, place.second + 2);
        }
        //als er iets staat en de kleur is verschillend
        if (g.getPiece(place.first + 1, place.second + 2) != nullptr &&
            g.getPiece(place.first + 1, place.second + 2)->getKleur() != this->getKleur()) {
            possibilities.emplace_back(place.first + 1, place.second + 2);
        }
    }

    ///2down1right
    if (place.first+2 < 8 && place.second+1 < 8) {
        //check of er iets staat
        if (g.getPiece(place.first + 2, place.second + 1) == nullptr) {
            possibilities.emplace_back(place.first + 2, place.second + 1);
        }
        //als er iets staat en de kleur is verschillend
        if (g.getPiece(place.first + 2, place.second + 1) != nullptr &&
            g.getPiece(place.first + 2, place.second + 1)->getKleur() != this->getKleur()) {
            possibilities.emplace_back(place.first + 2, place.second + 1);
        }
    }

    ///2down1left
    if (place.first+2 < 8 && place.second-1 >= 0) {
        //check of er iets staat
        if (g.getPiece(place.first + 2, place.second - 1) == nullptr) {
            possibilities.emplace_back(place.first + 2, place.second - 1);
        }
        //als er iets staatn en de kleur is verschillend
        if (g.getPiece(place.first + 2, place.second - 1) != nullptr &&
            g.getPiece(place.first + 2, place.second - 1)->getKleur() != this->getKleur()) {
            possibilities.emplace_back(place.first + 2, place.second - 1);
        }
    }

    ///1down2left
    if (place.first+1 < 8 && place.second-2 >= 0) {
        //check of er iets staat
        if (g.getPiece(place.first + 1, place.second - 2) == nullptr) {
            possibilities.emplace_back(place.first + 1, place.second - 2);
        }
        //als er iets staat en de kleur isverschillend
        if (g.getPiece(place.first + 1, place.second - 2) != nullptr &&
            g.getPiece(place.first + 1, place.second - 2)->getKleur() != this->getKleur()) {
            possibilities.emplace_back(place.first + 1, place.second - 2);
        }
    }

    ///1up2left
    if (place.first-1 >= 0 && place.second-2 >= 0) {
        //check if null
        if (g.getPiece(place.first - 1, place.second - 2) == nullptr) {
            possibilities.emplace_back(place.first - 1, place.second - 2);
        }
        //als er iets staat en de kleur is verschillend
        if (g.getPiece(place.first - 1, place.second - 2) != nullptr &&
            g.getPiece(place.first - 1, place.second - 2)->getKleur() != this->getKleur()) {
            possibilities.emplace_back(place.first - 1, place.second - 2);
        }
    }

    ///2up1left
    if (place.first-2 >= 0 && place.second-1 >= 0) {
        //check if null
        if (g.getPiece(place.first - 2, place.second - 1) == nullptr) {
            possibilities.emplace_back(place.first - 2, place.second - 1);
        }
        //als er iets staatn en de kleur is verschillend
        if (g.getPiece(place.first - 2, place.second - 1) != nullptr &&
            g.getPiece(place.first - 2, place.second - 1)->getKleur() != this->getKleur()) {
            possibilities.emplace_back(place.first - 2, place.second - 1);
        }
    }
    return possibilities;
}

//Possible moves for bishop
vector<pair<int, int>> Loper::geldige_zetten(Game &g) {
    vector<pair<int, int>> possibilities;
    auto place = g.currplace(this);

    //schuin naar rechts onder
    for (int i = 1; i < 8; ++i) {
        //domein
        if (place.first+i < 8 && place.second+i < 8) {
            //check of er schuin recht een pion staat
            if (g.getPiece(place.first+i,place.second+i) == nullptr){
                possibilities.emplace_back(place.first+i,place.second+i);
            }
            //als er iet staat
            if (g.getPiece(place.first+i,place.second+i) != nullptr){
                //check de kleur
                if (g.getPiece(place.first+i,place.second+i)->getKleur() != this->getKleur()){
                    possibilities.emplace_back(place.first+i,place.second+i);
                }
                if (g.getPiece(place.first+i,place.second+i)->getKleur() == this->getKleur()){
                    break;
                }
            }
        }
    }

    //schuin rechts naar boven
    for (int i = 1; i < 8; ++i) {
        //domein
        if (place.first-i >= 0 && place.second+i < 8){
            //check of er schuin rechts een stuk staat
            if (g.getPiece(place.first-i,place.second+i) == nullptr){
                possibilities.emplace_back(place.first-i,place.second+i);
            }
            //als er iet staat
            if (g.getPiece(place.first-i,place.second+i) != nullptr){
                //check de kleur;
                if (g.getPiece(place.first-i,place.second+i)->getKleur() != this->getKleur()){
                    possibilities.emplace_back(place.first-i,place.second+i);
                }
                if (g.getPiece(place.first-i,place.second+i)->getKleur() == this->getKleur()){
                    break;
                }
            }
        }
    }

    //schuin links naar beneden
    for (int i = 1; i < 8; ++i) {
        //domein
        if (place.first+i < 8 && place.second-i >= 0){
            //cehck of er iets staat
            if (g.getPiece(place.first+i,place.second-i) == nullptr){
                possibilities.emplace_back(place.first+i,place.second-i);
            }
            //als er iets staat
            if (g.getPiece(place.first+i,place.second-i) != nullptr){
                //check de kleur
                if (g.getPiece(place.first+i,place.second-i)->getKleur() != this->getKleur()){
                    possibilities.emplace_back(place.first+i,place.second-i);
                }
                if (g.getPiece(place.first+i,place.second-i)->getKleur() == this->getKleur()){
                    break;
                }
            }
        }
    }

    //links naar boven
    for (int i = 1; i < 8; ++i) {
        //domein
        if (place.first-i >=0 && place.second-i >=0){
            //check of er iets staat
            if (g.getPiece(place.first-i,place.second-i) == nullptr){
                possibilities.emplace_back(place.first-i,place.second-i);
            }
            //als er iets staat
            if (g.getPiece(place.first-i,place.second-i) != nullptr){
                //check kleur
                if (g.getPiece(place.first-i,place.second-i)->getKleur() != this->getKleur()){
                    possibilities.emplace_back(place.first-i,place.second-i);
                }
                if (g.getPiece(place.first-i,place.second-i)->getKleur() == this->getKleur()){
                    break;
                }
            }
        }
    }

    return possibilities;
}

//Possible moves king
vector<pair<int, int>> Koning::geldige_zetten(Game &g) {
    vector<pair<int, int>> possibilities;
    auto place = g.currplace(this);

    ///1up
    if (place.first-1>= 0){
        //check of er iets staat
        if (g.getPiece(place.first-1,place.second) == nullptr){
            possibilities.emplace_back(place.first-1,place.second);
        }
        //Als er iets staat check de kleur verschille,d
        if (g.getPiece(place.first-1,place.second) != nullptr && g.getPiece(place.first-1,place.second)->getKleur() != this->getKleur()){
            possibilities.emplace_back(place.first-1,place.second);
        }
        if (place.first-1>=0 && place.second+1 < 8) {
            if (g.getPiece(place.first - 1, place.second + 1) != nullptr) {
                if (g.getPiece(place.first - 1, place.second + 1)->getKleur() == zwart) {
                    possibilities.emplace_back(place.first - 1, place.second + 1);
                }
            }
        }
        if (place.first-1 >= 0 && place.second-1 >= 0) {
            if (g.getPiece(place.first - 1, place.second - 1) != nullptr) {
                if (g.getPiece(place.first - 1, place.second - 1)->getKleur() == zwart) {
                    possibilities.emplace_back(place.first - 1, place.second - 1);
                }
            }
        }
    }

    ///1up1right
    if (place.first-1 >= 0 && place.second+1 < 8){
        //check of er iets staat
        if (g.getPiece(place.first-1,place.second+1) == nullptr){
            possibilities.emplace_back(place.first-1,place.second+1);
        }
        //als er iets staat check de kleur
        if (g.getPiece(place.first-1,place.second) != nullptr && g.getPiece(place.first-1,place.second)->getKleur() != this->getKleur()){
            possibilities.emplace_back(place.first-1,place.second+1);
        }
    }

    ///1right
    if (place.second+1 < 8){
        //check of er iets staat
        if (g.getPiece(place.first,place.second+1) == nullptr){
            possibilities.emplace_back(place.first,place.second+1);
        }
        //als er iets staat check kleur
        if (g.getPiece(place.first,place.second+1) != nullptr && g.getPiece(place.first,place.second+1)->getKleur() != this->getKleur()){
            possibilities.emplace_back(place.first,place.second+1);
        }
    }

    ///1down1right
    if (place.first+1 < 8 && place.second+1 < 8){
        if (g.getPiece(place.first+1,place.second+1) == nullptr){
            possibilities.emplace_back(place.first+1,place.second+1);
        }
        if (g.getPiece(place.first+1,place.second+1) != nullptr && g.getPiece(place.first+1,place.second+1)->getKleur() != this->getKleur()){
            possibilities.emplace_back(place.first+1,place.second+1);
        }
    }

    ///1down
    if (place.first+1 < 8){
        if (g.getPiece(place.first+1,place.second) == nullptr){
            possibilities.emplace_back(place.first+1,place.second);
        }
        if (g.getPiece(place.first+1,place.second) != nullptr && g.getPiece(place.first+1,place.second)->getKleur() != this->getKleur()){
            possibilities.emplace_back(place.first+1,place.second);
        }
        if (place.first+1 < 8 && place.second+1 < 8) {
            //Als er schuin rechts onder een stuk staat
            if (g.getPiece(place.first + 1, place.second + 1) != nullptr) {
                if (g.getPiece(place.first + 1, place.second + 1)->getKleur() == wit) {
                    possibilities.emplace_back(place.first + 1, place.second + 1);
                }
            }
        }
        if (place.first+1 < 8 && place.second-1 >= 0) {
            //als schuin links onder geen stuk staat
            if (g.getPiece(place.first + 1, place.second - 1) != nullptr) {
                if (g.getPiece(place.first + 1, place.second - 1)->getKleur() == wit) {
                    possibilities.emplace_back(place.first + 1, place.second - 1);
                }
            }
        }
    }

    ///1down1left
    if (place.first+1 < 8 && place.second-1 >= 0){
        if (g.getPiece(place.first+1,place.second-1) == nullptr){
            possibilities.emplace_back(place.first+1,place.second-1);
        }
        if (g.getPiece(place.first+1,place.second-1) != nullptr && g.getPiece(place.first+1,place.second-1)->getKleur() != this->getKleur()){
            possibilities.emplace_back(place.first+1,place.second-1);
        }
    }

    ///1left
    if (place.second-1 >= 0) {
        if (g.getPiece(place.first, place.second-1) == nullptr) {
            possibilities.emplace_back(place.first, place.second-1);
        }
        if (g.getPiece(place.first, place.second-1) != nullptr && g.getPiece(place.first, place.second-1)->getKleur() != this->getKleur()){
            possibilities.emplace_back(place.first, place.second-1);

        }
    }

    ///1up1left
    if (place.first-1 >= 0 && place.second-1 >= 0){
        if (g.getPiece(place.first-1,place.second-1) == nullptr){
            possibilities.emplace_back(place.first-1,place.second-1);
        }
        if (g.getPiece(place.first-1,place.second-1) != nullptr && g.getPiece(place.first-1,place.second-1)->getKleur() != this->getKleur()){
            possibilities.emplace_back(place.first-1,place.second-1);
        }
    }

    return possibilities;
}

//Possible moves queen
vector<pair<int, int>> Koningin::geldige_zetten(Game &g) {
    vector<pair<int, int>> possibilities;
    auto place = g.currplace(this);

    //beweging naar boven
    for (int i = place.first-1; i >= 0 ; --i) {
        //check of er geen stuk bovenstaat
        if (g.getPiece(i,place.second) == nullptr){
            possibilities.emplace_back(i,place.second);
        }
        //als er wel een stuk staat
        if (g.getPiece(i,place.second) != nullptr){
            //check de kleur
            if (g.getPiece(i,place.second)->getKleur() != this->getKleur()){
                possibilities.emplace_back(i,place.second);
            }
            if (g.getPiece(i,place.second)->getKleur() == this->getKleur()){
                break;
            }
        }
    }

    //beweging naar beneden
    for (int i = place.first + 1; i < 8; ++i) {
        //check of er geen stuk onderstaat
        if (g.getPiece(i,place.second) == nullptr){
            possibilities.emplace_back(i,place.second);
        }
        //als er wel een stuk staat
        if (g.getPiece(i,place.second) != nullptr){
            //check de kleur
            if (g.getPiece(i,place.second)->getKleur() != this->getKleur()){
                possibilities.emplace_back(i,place.second);
            }
            if (g.getPiece(i,place.second)->getKleur() == this->getKleur()){
                break;
            }
        }
    }

    //beweging naar links
    for (int i = place.second - 1 ; i >= 0 ; --i) {
        //check of er geen stuk links staat
        if (g.getPiece(place.first,i) == nullptr){
            possibilities.emplace_back(place.first,i);
        }
        //als er wel een stuk staat
        if (g.getPiece(place.first,i) != nullptr){
            //check de kleur
            if (g.getPiece(place.first,i)->getKleur() != this->getKleur()){
                possibilities.emplace_back(place.first,i);
            }
            if (g.getPiece(place.first,i)->getKleur() == this->getKleur()){
                break;
            }
        }
    }

    //beweging naar rechts
    for (int i = place.second+1; i < 8; ++i) {
        //check of er geen stuk staat
        if (g.getPiece(place.first,i) == nullptr){
            possibilities.emplace_back(place.first,i);
        }
        //als er wel een stuk staat
        if (g.getPiece(place.first,i) != nullptr){
            //check de kleur
            if (g.getPiece(place.first,i)->getKleur() != this->getKleur()){
                possibilities.emplace_back(place.first,i);
            }
            if (g.getPiece(place.first,i)->getKleur() == this->getKleur()){
                break;
            }
        }
    }
    //schuin naar rechts onder
    for (int i = 1; i < 8; ++i) {
        //domein
        if (place.first+i < 8 && place.second+i < 8) {
            //check of er schuin recht een pion staat
            if (g.getPiece(place.first+i,place.second+i) == nullptr){
                possibilities.emplace_back(place.first+i,place.second+i);
            }
            //als er iet staat
            if (g.getPiece(place.first+i,place.second+i) != nullptr){
                //check de kleur
                if (g.getPiece(place.first+i,place.second+i)->getKleur() != this->getKleur()){
                    possibilities.emplace_back(place.first+i,place.second+i);
                }
                if (g.getPiece(place.first+i,place.second+i)->getKleur() == this->getKleur()){
                    break;
                }
            }
        }
    }

    //schuin rechts naar boven
    for (int i = 1; i < 8; ++i) {
        //domein
        if (place.first-i >= 0 && place.second+i < 8){
            //check of er schuin rechts een stuk staat
            if (g.getPiece(place.first-i,place.second+i) == nullptr){
                possibilities.emplace_back(place.first-i,place.second+i);
            }
            //als er iet staat
            if (g.getPiece(place.first-i,place.second+i) != nullptr){
                //check de kleur;
                if (g.getPiece(place.first-i,place.second+i)->getKleur() != this->getKleur()){
                    possibilities.emplace_back(place.first-i,place.second+i);
                }
                if (g.getPiece(place.first-i,place.second+i)->getKleur() == this->getKleur()){
                    break;
                }
            }
        }
    }

    //schuin links naar beneden
    for (int i = 1; i < 8; ++i) {
        //domein
        if (place.first+i < 8 && place.second-i >= 0){
            //cehck of er iets staat
            if (g.getPiece(place.first+i,place.second-i) == nullptr){
                possibilities.emplace_back(place.first+i,place.second-i);
            }
            //als er iets staat
            if (g.getPiece(place.first+i,place.second-i) != nullptr){
                //check de kleur
                if (g.getPiece(place.first+i,place.second-i)->getKleur() != this->getKleur()){
                    possibilities.emplace_back(place.first+i,place.second-i);
                }
                if (g.getPiece(place.first+i,place.second-i)->getKleur() == this->getKleur()){
                    break;
                }
            }
        }
    }

    //links naar boven
    for (int i = 1; i < 8; ++i) {
        //domein
        if (place.first-i >=0 && place.second-i >=0){
            //check of er iets staat
            if (g.getPiece(place.first-i,place.second-i) == nullptr){
                possibilities.emplace_back(place.first-i,place.second-i);
            }
            //als er iets staat
            if (g.getPiece(place.first-i,place.second-i) != nullptr){
                //check kleur
                if (g.getPiece(place.first-i,place.second-i)->getKleur() != this->getKleur()){
                    possibilities.emplace_back(place.first-i,place.second-i);
                }
                if (g.getPiece(place.first-i,place.second-i)->getKleur() == this->getKleur()){
                    break;
                }
            }
        }
    }

    return possibilities;
}
