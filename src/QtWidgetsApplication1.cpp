#include "QtWidgetsApplication1.h"
#include "adddialog.h"
#include <QListWidgetItem>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::on_addButton_clicked() {
    AddDialog dialog(this);
    if (dialog.exec()) {
        QString name = dialog.ui.nameEdit->text();
        QString email = dialog.ui.emailEdit->text();
        
        if (!name.isEmpty() && !email.isEmpty()) {
            QListWidgetItem* item = new QListWidgetItem(name, ui.addressList);
            item->setData(Qt::UserRole, email);
            ui.addressList->setCurrentItem(item);
        }
    }
}

void QtWidgetsApplication1::on_addressList_currentItemChanged() {
    QListWidgetItem* curItem = ui.addressList->currentItem();
    if (curItem) {
        ui.nameLabel->setText("Name:" + curItem->text());
        ui.emailLabel->setText("Emali:" + curItem->data(Qt::UserRole).toString());
    }
    else {
        ui.nameLabel->setText("<没有项目被选中>");
        ui.emailLabel->clear();
    }

}

void QtWidgetsApplication1::on_deleteButton_clicked() {
    QListWidgetItem* curItem = ui.addressList->currentItem();
    if (curItem) {
        int row = ui.addressList->row(curItem);
        ui.addressList->takeItem(row);
        delete curItem;
        if (ui.addressList->count() > 0)
            ui.addressList->setCurrentRow(0);
        else
            on_addressList_currentItemChanged();
    }
}

