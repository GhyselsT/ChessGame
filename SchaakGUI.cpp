//
// Created by toonc on 12/17/2021.
//

#include "SchaakGUI.h"
#include "guicode/message.h"
#include "guicode/fileIO.h"

// Constructor
SchaakGUI::SchaakGUI():ChessWindow(nullptr) {
    g.setStartBord();
    update();
}


// Deze functie wordt opgeroepen telkens er op het schaakbord
// geklikt wordt. x,y geeft de positie aan waar er geklikt
// werd; r is de 0-based rij, k de 0-based kolom
void SchaakGUI::clicked(int r, int k) {
    auto c = g.currplace(g.getCurrpiece());

    if (g.getCurrpiece() == nullptr){
        //als er niets staat op de plaats r,k return
        if (g.getPiece(r,k) == nullptr)
            return;
        //als er iets staat
        else if (g.getPiece(r,k)->getKleur() == g.getCurrpersoon()) {
            g.setCurrpiece(g.getPiece(r, k));
            //selecteer het stuk dat er staat
            setTileSelect(r,k, true);
            //als je op eenstuk klikt geef alle mogelijke zetten visueel weer
            for(auto temp : g.getCurrpiece()->geldige_zetten(g)){
                setTileFocus(temp.first,temp.second, true);
            }
        }
    }
    //als er nog eens geklikt word op het zelfde stuk
    //stuk word nietmeer geselecteerd en de mogelijke zetten ook niet meer
    else if (g.getCurrpiece() == g.getPiece(r,k)){
        g.setCurrpiece(nullptr);
        setTileSelect(r,k, false);
        removeAllMarking();
        return;
    }
    //klik op een ander vak op de move te doen
    else if (g.getCurrpiece() != nullptr){
        //als move true is
        if (g.move(g.getCurrpiece(),r,k)) {
            update();
            //verander de persoon van kleur
            if (g.getCurrpersoon() == zwart) {
                g.setCurrpersoon(wit);
            }
            else if (g.getCurrpersoon() == wit) {
                g.setCurrpersoon(zwart);
            }
            //verwijder alle aanduidingen van de stukken.
            setTileSelect(c.first,c.second,false);
            removeAllMarking();
            g.setCurrpiece(nullptr);
            return;
        }
        else{
            //als move false geeft
            //return een message.
            message("Deze zet is ongeldig.");
        }
    }
}

void SchaakGUI::newGame(){
}


void SchaakGUI::save() {
    QFile file;
    if (openFileToWrite(file)) {
        QDataStream out(&file);
        out << QString("Rb") << QString("Hb") << QString("Bb") << QString("Qb") << QString("Kb") << QString("Bb") << QString("Hb") << QString("Rb");
        for  (int i=0;i<8;i++) {
            out << QString("Pb");
        }
        for  (int r=3;r<7;r++) {
            for (int k=0;k<8;k++) {
                out << QString(".");
            }
        }
        for  (int i=0;i<8;i++) {
            out << QString("Pw");
        }
        out << QString("Rw") << QString("Hw") << QString("Bw") << QString("Qw") << QString("Kw") << QString("Bw") << QString("Hw") << QString("Rw");
    }
}

void SchaakGUI::open() {
    QFile file;
    if (openFileToRead(file)) {
        try {
            QDataStream in(&file);
            QString debugstring;
            for (int r=0;r<8;r++) {
                for (int k=0;k<8;k++) {
                    QString piece;
                    in >> piece;
                    debugstring += "\t" + piece;
                    if (in.status()!=QDataStream::Ok) {
                        throw QString("Invalid File Format");
                    }
                }
                debugstring += "\n";
            }
            message(debugstring);
        } catch (QString& Q) {
            message(Q);
        }
    }
    update();
}


void SchaakGUI::undo() {
    message("Je hebt undo gekozen");
}

void SchaakGUI::redo() {}


void SchaakGUI::visualizationChange() {
    QString visstring = QString(displayMoves()?"T":"F")+(displayKills()?"T":"F")+(displayThreats()?"T":"F");
    message(QString("Visualization changed : ")+visstring);
}


// Update de inhoud van de grafische weergave van het schaakbord (scene)
// en maak het consistent met de game state in variabele g.
void SchaakGUI::update() {
    clearBoard();
    for (int r = 0; r < 8; r++) {
        for (int k = 0; k < 8; k++) {
            if (g.getPiece(r,k) != nullptr){
                setItem(r,k,g.getPiece(r,k));
            }
        }
    }
}

