#include "AddMonsterDialog.h"
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QLabel>

AddMonsterDialog::AddMonsterDialog(QWidget *parent)
    : QDialog(parent) {

    QVBoxLayout *layout = new QVBoxLayout(this);

    monsterTypeCombo = new QComboBox();
    monsterTypeCombo->addItems({"Goblin", "Orc"});

    monsterCountSpin = new QSpinBox();
    monsterCountSpin->setRange(1, 20);

    layout->addWidget(new QLabel("Select Monster Type:"));
    layout->addWidget(monsterTypeCombo);
    layout->addWidget(new QLabel("Number of Monsters:"));
    layout->addWidget(monsterCountSpin);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    layout->addWidget(buttonBox);
}

QString AddMonsterDialog::getSelectedType() const {
    return monsterTypeCombo->currentText();
}

int AddMonsterDialog::getMonsterCount() const {
    return monsterCountSpin->value();
}
