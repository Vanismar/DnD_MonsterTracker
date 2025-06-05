#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QMap>

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

};
