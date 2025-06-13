#include "AddMonsterDialog.h"
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QLabel>

AddMonsterDialog::AddMonsterDialog(QWidget *parent)
    : QDialog(parent) {

    QVBoxLayout *layout = new QVBoxLayout(this);

    monsterTypeCombo = new QComboBox();
    QStringList monsterTypes = {
        "Bugbear", "Bugbear Chief", "Doppelganger", "Goblin", "Goblin Boss", "Orc", "Spectator", "Twig Blight", "Grick", "Grick Alpha", "Hobgoblin",
        "Hobgoblin Captain", "Hobgoblin Warlord", "Mimic", "Nothic", "Black Pudding", "Gelatinous Cube", "Gray Ooze", "Ochre Jelly", "Orc War Chief",
        "Orc Eye of Gruumsh", "Orog", "Owlbear", "Skeleton", "Minotaur Skeleton", "Warhorse Skeleton", "Ancient Black Dragon", "Adult Black Dragon",
        "Young Black Dragon", "Black Dragon Wyrmling", "Ancient Blue Dragon", "Adult Blue Dragon", "Young Blue Dragon", "Blue Dragon Wyrmling",
        "Ancient Green Dragon", "Adult Green Dragon", "Young Green Dragon", "Green Dragon Wyrmling", "Ancient Red Dragon", "Adult Red Dragon",
        "Young Red Dragon", "Red Dragon Wyrmling", "Ancient White Dragon", "Adult White Dragon", "Young White Dragon", "White Dragon Wyrmling",
        "Ancient Brass Dragon", "Adult Brass Dragon", "Young Brass Dragon", "Brass Dragon Wyrmling", "Ancient Bronze Dragon", "Adult Bronze Dragon",
        "Young Bronze Dragon", "Bronze Dragon Wyrmling", "Ancient Copper Dragon", "Adult Copper Dragon", "Young Copper Dragon", "Copper Dragon Wyrmling",
        "Ancient Gold Dragon", "Adult Gold Dragon", "Young Gold Dragon", "Gold Dragon Wyrmling", "Ancient Silver Dragon", "Adult Silver Dragon",
        "Young Silver Dragon", "Silver Dragon Wyrmling", "Vampire Spawn", "Vampire Fledgling", "Vampire Knight", "Vampire baron", "Vampire Viscount", "Vampire Count",
        "Vampire Duke"
    };

    std::sort(monsterTypes.begin(), monsterTypes.end(), [](const QString &a, const QString &b) {
        return a.toLower() < b.toLower();  // Case-insensitive
    });

    monsterTypeCombo->addItems(monsterTypes);

    monsterCountSpin = new QSpinBox();
    monsterCountSpin->setRange(1, 50);

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
