#include <iostream>
#include "main_window.h"
#include "ui_main_window.h"
#include "dialog_config_menu.h"

main_window::main_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_window)
{
    ui->setupUi(this);
}

main_window::~main_window()
{
    delete ui;
}

void main_window::on_pushButton_menu_clicked(){
	//Open configuration menu
	//dialog_config_menu config_menu;
	//config_menu.setModal(true); //focus on dialog and doesn't have access to main_window
	//config_menu.exec();
	hide(); // hide the main window
	config_menu = new dialog_config_menu(this);
	config_menu->show();
}
