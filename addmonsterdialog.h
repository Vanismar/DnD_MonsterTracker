#pragma once

#include <QDialog>
#include <QComboBox>
#include <QSpinBox>

class AddMonsterDialog : public QDialog {
    Q_OBJECT

public:
    AddMonsterDialog(QWidget *parent = nullptr);
    QString getSelectedType() const;
    int getMonsterCount() const;

private:
    QComboBox *monsterTypeCombo;
    QSpinBox *monsterCountSpin;
};
