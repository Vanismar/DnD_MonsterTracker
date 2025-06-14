#include "MainWindow.h"
#include "AddMonsterDialog.h"
#include "MonsterFactory.h"
#include "conditions.h"
#include <QToolBar>
#include <QAction>
#include <QScrollArea>
#include <QInputDialog>
#include <QMessageBox>
#include <QLabel>
#include <QSpacerItem>
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    QToolBar *toolbar = addToolBar("Tools");
    toolbar->setFixedHeight(36);

    QAction *addMonsterAction = toolbar->addAction("Add Monster");
    connect(addMonsterAction, &QAction::triggered, this, &MainWindow::openAddMonsterDialog);

    QAction *viewStatBlockAction = toolbar->addAction("View Stat Block");
    connect(viewStatBlockAction, &QAction::triggered, this, &MainWindow::openStatBlock);

    QAction *viewConditions = toolbar->addAction("View Conditions");
    connect(viewConditions, &QAction::triggered, this, &MainWindow::openConditions);

    QWidget *spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolbar->addWidget(spacer);

    turnCounterLabel = new QLabel("Turn: 1");
    turnCounterLabel->setMinimumWidth(50);
    toolbar->addWidget(turnCounterLabel);

    QToolButton *subTurnButton = new QToolButton();
    subTurnButton->setText("-");
    toolbar->addWidget(subTurnButton);

    QToolButton *addTurnButton = new QToolButton();
    addTurnButton->setText("+");
    toolbar->addWidget(addTurnButton);

    QToolButton *resetTurnButton = new QToolButton();
    resetTurnButton->setText("Reset");
    toolbar->addWidget(resetTurnButton);

    connect(subTurnButton, &QToolButton::clicked, this, &MainWindow::decreaseTurn);
    connect(addTurnButton, &QToolButton::clicked, this, &MainWindow::incrementTurn);
    connect(resetTurnButton, &QToolButton::clicked, this, &MainWindow::resetTurn);

    monsterFlowLayout = new FlowLayout(5, 10, 10);
    auto *container = new QWidget;
    container->setLayout(monsterFlowLayout);

    auto *scroll = new QScrollArea;
    scroll->setWidget(container);
    scroll->setWidgetResizable(true);
    setCentralWidget(scroll);

    setMinimumSize(820, 450);
}

void MainWindow::openAddMonsterDialog() {
    AddMonsterDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        addMonsters(dialog.getSelectedType(), dialog.getMonsterCount());
    }
}

void MainWindow::addMonsters(const QString& type, int count) {
    auto monsterType = createMonsterType(type);
    if (!monsterType) return;

    int& currentCount = monsterCounters[type];

    for (int i = 0; i < count; ++i) {
        ++currentCount;

        MonsterInstance instance(monsterType);
        instance.name = QString("%1 #%2").arg(monsterType->name()).arg(currentCount);

        auto *widget = new MonsterWidget(instance, this);
        connect(widget, &MonsterWidget::monsterDied, this, &MainWindow::removeMonster);

        monsterFlowLayout->addWidget(widget);
        monsterWidgets.insert(widget);

        ++monsterCount;
    }

    QString typeName = monsterType->name();
    usedMonsterTypes.insert(typeName);
    if (!statBlocks.contains(typeName)) {
        auto *statBlock = new MonsterStatBlock(*monsterType, this);
        statBlock->setAttribute(Qt::WA_DeleteOnClose);
        statBlock->show();
        statBlocks[typeName] = statBlock;

        connect(statBlock, &QWidget::destroyed, this, [this, typeName]() {
            statBlocks.remove(typeName);
        });
    }
}

void MainWindow::removeMonster(MonsterWidget *widget) {
    monsterWidgets.remove(widget);
    widget->deleteLater();
}

void MainWindow::openStatBlock() {
    if (usedMonsterTypes.isEmpty()) {
        QMessageBox::information(this, "No Monsters Added", "No monster types have been added yet.");
        return;
    }

    QStringList availableTypes = usedMonsterTypes.values();
    bool ok;
    QString selected = QInputDialog::getItem(this, "View Stat Block",
                                             "Select Monster Type:", availableTypes,
                                             0, false, &ok);
    if (!ok || selected.isEmpty())
        return;

    if (!statBlocks.contains(selected)) {
        auto monsterType = createMonsterType(selected);
        if (!monsterType) return;

        auto *statBlock = new MonsterStatBlock(*monsterType);
        statBlock->setAttribute(Qt::WA_DeleteOnClose);
        statBlock->setWindowFlags(Qt::Window);
        statBlock->show();

        statBlocks[selected] = statBlock;

        connect(statBlock, &QWidget::destroyed, this, [this, selected]() {
            statBlocks.remove(selected);
        });
    } else {
        statBlocks[selected]->raise();
        statBlocks[selected]->activateWindow();
    }
}

void MainWindow::openConditions() {
    auto *window = new ConditionsWindow(this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowFlags(Qt::Window);
    window->show();
}

void MainWindow::decreaseTurn(){
    --turn;
    turnCounterLabel->setText(QString("Turn: %1").arg(turn));
}

void MainWindow::incrementTurn() {
    ++turn;
    turnCounterLabel->setText(QString("Turn: %1").arg(turn));
}

void MainWindow::resetTurn() {
    turn = 1;
    turnCounterLabel->setText("Turn: 1");
}
