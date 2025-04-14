//
// Created by toonc on 12/17/2021.
//

#include "message.h"
#include <QMessageBox>
#include <QString>

void message(const QString &s) {
    QMessageBox box1;
    box1.setText(s);
    //box1.setStyleSheet("background-color: rgb(255, 130, 249);color: rgb(166, 2, 2);");
    box1.exec();
}
