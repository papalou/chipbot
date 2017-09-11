#include "dialog_config_menu.h"
#include "ui_dialog_config_menu.h"

dialog_config_menu::dialog_config_menu(QWidget *parent) : QDialog(parent), ui(new Ui::dialog_config_menu)
{
	setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
}

dialog_config_menu::~dialog_config_menu()
{
    delete ui;
}


void dialog_config_menu::on_pushButton_ok_clicked(){
	//Save config TODO
	
	//Show parent widget -> main_window
	parentWidget()->show();

	//Close this dial window
	this->close();
}

void dialog_config_menu::on_pushButton_cancel_clicked(){
	//Don't save config

	//Show parent widget -> main_window
	parentWidget()->show();

	//Close this dial window
	this->close();
}

void dialog_config_menu::on_dialog_config_menu_finished(int result){
	//Close button X press
	//Show parent widget -> main_window
	parentWidget()->show();

	//Close this dial window
	this->close();
}
