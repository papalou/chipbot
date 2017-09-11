#include "dialog_config_menu.h"
#include "ui_dialog_config_menu.h"

dialog_config_menu::dialog_config_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_config_menu)
{
    ui->setupUi(this);
}

dialog_config_menu::~dialog_config_menu()
{
    delete ui;
}


void dialog_config_menu::on_pushButton_ok_clicked(){
	//Save config and close menu config
	this->close();
}

void dialog_config_menu::on_pushButton_cancel_clicked(){
	//Don't save config and close menu config
	this->close();
}
