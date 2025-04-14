//
//  !!! Dit bestand moet je in principe NIET wijzigen !!!
//

#include <QApplication>
#include "SchaakGUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //custom color
    //bg 195, 131, 255
    //font color geen idee hoe
    //geprobeert aan tepassen in message.
    //rgb(232,247,238);
    a.setStyleSheet("QMessageBox{background: rgb(255, 130, 249);  border: none;font-family: Arial; font-style: normal;  font-size: 12pt; color: #e8f7ee; }");

    SchaakGUI w;
    w.show();

    return a.exec();
}
