#include "MainWindow.h"
#include "AddMonsterDialog.h"
#include "MonsterFactory.h"
#include <QToolBar>
#include <QAction>
#include <QScrollArea>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    QToolBar *toolbar = addToolBar("Tools");
    QAction *addMonsterAction = toolbar->addAction("Add Monster");
    connect(addMonsterAction, &QAction::triggered, this, &MainWindow::openAddMonsterDialog);
    QAction *viewStatBlockAction = toolbar->addAction("View Stat Block");
    connect(viewStatBlockAction, &QAction::triggered, this, &MainWindow::openStatBlock);

    centralWidget = new QWidget(this);
    monsterGridLayout = new QGridLayout();
    centralWidget->setLayout(monsterGridLayout);

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
        connect(widget, &MonsterWidget::monsterDied, this, &MainWindow::removeMonster);

        int row = monsterCount / columnsPerRow;
        int col = monsterCount % columnsPerRow;
        monsterGridLayout->addWidget(widget, row, col);
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

        // Optional: remove from map when closed
        connect(statBlock, &QWidget::destroyed, this, [this, typeName]() {
            statBlocks.remove(typeName);
        });
    }
}

void MainWindow::removeMonster(MonsterWidget *widget) {
    monsterGridLayout->removeWidget(widget);
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
