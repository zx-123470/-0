#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

private slots:
    void on_addButton_clicked();
    void on_addressList_currentItemChanged();
    void on_deleteButton_clicked();

private:
    Ui::QtWidgetsApplication1Class ui;
};

