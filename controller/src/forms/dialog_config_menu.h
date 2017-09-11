#ifndef DIALOG_CONFIG_MENU_H
#define DIALOG_CONFIG_MENU_H

#include <QDialog>

namespace Ui {
class dialog_config_menu;
}

class dialog_config_menu : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_config_menu(QWidget *parent = 0);
    ~dialog_config_menu();

private:
    Ui::dialog_config_menu *ui;

private slots:
	void on_pushButton_ok_clicked();
	void on_pushButton_cancel_clicked();
};

#endif // DIALOG_CONFIG_MENU_H
