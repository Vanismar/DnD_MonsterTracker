#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QMap>
#include <QGridLayout>
#include <QSet>
#include <monsterwidget.h>
#include "MonsterStatBlock.h"
#include "FlowLayout.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void openAddMonsterDialog();
    void addMonsters(const QString& type, int count);

private:
    QWidget *centralWidget;
    QVBoxLayout *monsterLayout;
    QMap<QString, int> monsterCounters;
    QMap<QString, MonsterStatBlock*> statBlocks;
    QSet<MonsterWidget*> monsterWidgets;
    QSet<QString> usedMonsterTypes;
    int monsterCount = 0;
    FlowLayout *monsterFlowLayout = nullptr;

private slots:
    void removeMonster(MonsterWidget *widget);
    void openStatBlock();
    void openConditions();

};
