#include <QApplication>
#include "main_window.h"

#include "log.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    main_window w;
    w.show();

    return a.exec();
}
