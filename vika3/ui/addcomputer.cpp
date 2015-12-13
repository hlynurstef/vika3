#include "addcomputer.h"
#include "ui_addcomputer.h"
#include <QMessageBox>

addComputer::addComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputer)
{
    ui->setupUi(this);
}

addComputer::~addComputer()
{
    delete ui;
}

void addComputer::on_button_add_computer_clicked()
{
    // Empty error messages
    ui->label_name_error->setText("");
    ui->label_type_error->setText("");
    ui->label_build_error->setText("");
    ui->label_description_error->setText("");

    // Fill variables with values in input lines
    string name = ui->input_name->text().toStdString();
    string type = ui->input_type->text().toStdString();
    string wasItBuilt = ui->input_was_it_built->text().toStdString();
    string buildYear= ui->input_build_year->text().toStdString();
    string description = ui->input_description->text().toStdString();

    if(buildYear.empty()){
        buildYear= "0";
    }

    bool error = errorCheck(name, type, wasItBuilt, buildYear, description);
    if(error == true){
        return;
    }

    int bYear = atoi(buildYear.c_str());

    Computer comp(name, bYear, type, wasItBuilt, description);


    this->done(1);
}
bool addComputer::errorCheck(string name, string type, string wasItBuilt, string buildYear, string description){
    bool error = false;

    if(name.empty()){
        ui->label_name_error->setText("<span style ='color: #ff0000'>Input name</span>");
        error = true;
    }
    if(type != "mechanical" || type != "Mechanical" || type != "electronic" || type != "Electronic" || type != "transistor" || type != "Transistor"){
        //QMessageBox::warning();
        //Test this out when I have figured out all errors
        ui->label_type_error->setText("<span style ='color: #ff0000'>Wrong input</span>");
        error = true;
    }
    if(type.empty()){
        ui->label_type_error->setText("<span style ='color: #ff0000'>Input type</span>");
        error = true;
    }
    if(wasItBuilt.empty()){
        ui->label_build_error->setText("<span style ='color: #ff0000'>Input y/n</span>");
        error = true;
    }
    if(description.empty()){
        ui->label_description_error->setText("<span style ='color: #ff0000'>Input description</span>");
    }

    if(error == true){
        return true;
    }
    return false;
}
