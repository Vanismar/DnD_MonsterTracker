#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QMap>
#include <QGridLayout>
#include <QSet>
#include <monsterwidget.h>

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
    QGridLayout *monsterGridLayout;
    QSet<MonsterWidget*> monsterWidgets;
    int monsterCount = 0;
    int columnsPerRow = 5;

private slots:
    void removeMonster(MonsterWidget *widget);

};
