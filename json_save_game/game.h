#ifndef GAME_H
#define GAME_H

#include <QJsonObject>
#include <QVector>

#include "character.h"
#include "level.h"

class Game
{
public:
    enum SaveFormat {
        Json, Binary
    };

    Character player() const;
    QVector<Level> levels() const;

    void newGame();
    bool loadGame(SaveFormat saveFormat);
    bool saveGame(SaveFormat saveFormat) const;

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    void print(int indentation = 0) const;
private:
    Character mPlayer;
    QVector<Level> mLevels;
};

#endif // GAME_H