#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


class User{
    int age_;
    QString name_;
public:
    static std::vector<User> users_;
    User(int age, QString name){
        this->age_=age;
        this->name_=name;
    }
    QString getName(){
        return name_;
    }
    int getAge(){
        return age_;
    }
    static size_t getCount(){
        return  users_.size();
    }
    static void addUser(User user){
        users_.push_back(user);
    }
    static void removeUserAt(int index){
        users_.erase(users_.begin() + index);
    }
    static void removeUserByName(QString name){
        users_.erase(std::remove_if(users_.begin(), users_.end(),[&](User found){return found.getName() == name;}), users_.end());
    }
    static std::vector<QString> getAllNames(){
        std::vector<QString> list;
        std::for_each(users_.begin(),users_.end(),[&](User found){list.push_back(found.getName());});
        return  list;
    }
};

std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User clicked on submit button";


    User::addUser(User(22,"Timofey"));
    User::addUser(User(33,"Aufar"));
    User::addUser(User(44,"Valery"));
    User::addUser(User(55,"Kirill"));
    User::addUser(User(66,"Artem"));
    User::addUser(User(77,"Camila"));

    qDebug() << "Current students' count: " << User::getCount();
    qDebug() << "All students: ";
    qDebug() << User::getAllNames();
    qDebug() << "Removing user at 4 index";

    User::removeUserAt(4);

    qDebug() << "Current Students' Count: " << User::getCount();
    qDebug() << "All students: ";
    qDebug() << User::getAllNames();
    qDebug() << "Removing user named Aufar ";

    User::removeUserByName("Aufar");

    qDebug() << "Current Students' Count: " << User::getCount();
    qDebug() << "All students: ";
    qDebug() << User::getAllNames();
}
