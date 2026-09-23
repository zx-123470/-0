#pragma once

#include <QDialog>
#include "ui_adddialog.h"

class AddDialog : public QDialog
{
	Q_OBJECT

public:
	AddDialog(QWidget *parent = nullptr);
	~AddDialog();
	Ui::AddDialogClass ui;

private:
	
};

