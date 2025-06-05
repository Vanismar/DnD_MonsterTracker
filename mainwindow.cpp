#include "MainWindow.h"
#include "AddMonsterDialog.h"
#include "MonsterFactory.h"
#include "MonsterWidget.h"

#include <QToolBar>
#include <QAction>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    QToolBar *toolbar = addToolBar("Tools");
    QAction *addMonsterAction = new QAction("Add Monsters", this);
    connect(addMonsterAction, &QAction::triggered, this, &MainWindow::openAddMonsterDialog);
    toolbar->addAction(addMonsterAction);

    centralWidget = new QWidget(this);
    monsterLayout = new QVBoxLayout();
    centralWidget->setLayout(monsterLayout);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(centralWidget);

    setCentralWidget(scrollArea);
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
        monsterLayout->addWidget(widget);
    }
}
