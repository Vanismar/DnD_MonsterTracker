#pragma once
#include <QWidget>
#include "MonsterType.h"

class QLabel;
class QVBoxLayout;

class MonsterStatBlock : public QWidget {
    Q_OBJECT

public:
    explicit MonsterStatBlock(const MonsterType& type, QWidget *parent = nullptr);
};
