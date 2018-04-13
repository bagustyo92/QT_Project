#ifndef LEVEL_H
#define LEVEL_H

#include <QJsonObject>
#include <QVector>

#include "character.h"

class Level
{
public:
    Level() = default;
    Level(const QString &name);

    QString name() const;

    QVector<Character> npcs() const;
    void setNpcs(const QVector<Character> &npcs);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    void print(int indentation = 0) const;
private:
    QString mName;
    QVector<Character> mNpcs;
};

#endif // LEVEL_H