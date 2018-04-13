#include "game.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QRandomGenerator>
#include <QTextStream>

Character Game::player() const
{
    return mPlayer;
}

QVector<Level> Game::levels() const
{
    return mLevels;
}

void Game::newGame()
{
    mPlayer = Character();
    mPlayer.setName(QStringLiteral("Hero"));
    mPlayer.setClassType(Character::Archer);
    mPlayer.setLevel(QRandomGenerator::global()->bounded(15, 21));

    mLevels.clear();
    mLevels.reserve(2);

    Level village(QStringLiteral("Village"));
    QVector<Character> villageNpcs;
    villageNpcs.reserve(2);
    villageNpcs.append(Character(QStringLiteral("Barry the Blacksmith"),
                                 QRandomGenerator::global()->bounded(8, 11),
                                 Character::Warrior));
    villageNpcs.append(Character(QStringLiteral("Terry the Trader"),
                                 QRandomGenerator::global()->bounded(6, 8),
                                 Character::Warrior));
    village.setNpcs(villageNpcs);
    mLevels.append(village);

    Level dungeon(QStringLiteral("Dungeon"));
    QVector<Character> dungeonNpcs;
    dungeonNpcs.reserve(3);
    dungeonNpcs.append(Character(QStringLiteral("Eric the Evil"),
                                 QRandomGenerator::global()->bounded(18, 26),
                                 Character::Mage));
    dungeonNpcs.append(Character(QStringLiteral("Eric's Left Minion"),
                                 QRandomGenerator::global()->bounded(5, 7),
                                 Character::Warrior));
    dungeonNpcs.append(Character(QStringLiteral("Eric's Right Minion"),
                                 QRandomGenerator::global()->bounded(4, 9),
                                 Character::Warrior));
    dungeon.setNpcs(dungeonNpcs);
    mLevels.append(dungeon);
}

bool Game::loadGame(Game::SaveFormat saveFormat)
{
    QFile loadFile(saveFormat == Json
        ? QStringLiteral("save.json")
        : QStringLiteral("save.dat"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(saveFormat == Json
        ? QJsonDocument::fromJson(saveData)
        : QJsonDocument::fromBinaryData(saveData));

    read(loadDoc.object());

    QTextStream(stdout) << "Loaded save for "
                        << loadDoc["player"]["name"].toString()
                        << " using "
                        << (saveFormat != Json ? "binary " : "") << "JSON...\n";
    return true;
}

bool Game::saveGame(Game::SaveFormat saveFormat) const
{
    QFile saveFile(saveFormat == Json
        ? QStringLiteral("save.json")
        : QStringLiteral("save.dat"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject gameObject;
    write(gameObject);
    QJsonDocument saveDoc(gameObject);
    saveFile.write(saveFormat == Json
        ? saveDoc.toJson()
        : saveDoc.toBinaryData());

    return true;
}

void Game::read(const QJsonObject &json)
{
    if (json.contains("player") && json["player"].isObject())
        mPlayer.read(json["player"].toObject());

    if (json.contains("levels") && json["levels"].isArray()) {
        QJsonArray levelArray = json["levels"].toArray();
        mLevels.clear();
        mLevels.reserve(levelArray.size());
        for (int levelIndex = 0; levelIndex < levelArray.size(); ++levelIndex) {
            QJsonObject levelObject = levelArray[levelIndex].toObject();
            Level level;
            level.read(levelObject);
            mLevels.append(level);
        }
    }
}

void Game::write(QJsonObject &json) const
{
    QJsonObject playerObject;
    mPlayer.write(playerObject);
    json["player"] = playerObject;

    QJsonArray levelArray;
    foreach (const Level level, mLevels) {
        QJsonObject levelObject;
        level.write(levelObject);
        levelArray.append(levelObject);
    }
    json["levels"] = levelArray;
}

void Game::print(int indentation) const
{
    const QString indent(indentation * 2, ' ');
    QTextStream(stdout) << indent << "Player\n";
    mPlayer.print(indentation + 1);

    QTextStream(stdout) << indent << "Levels\n";
    for (Level level : mLevels)
        level.print(indentation + 1);
}