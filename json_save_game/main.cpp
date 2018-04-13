#include <QCoreApplication>
#include <QTextStream>

#include "game.h"
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QStringList args = QCoreApplication::arguments();
    bool newGame = true;
    if (args.length() > 1)
        newGame = (args[1].toLower() != QStringLiteral("load"));
    bool json = true;
    if (args.length() > 2)
        json = (args[2].toLower() != QStringLiteral("binary"));

    Game game;
    if (newGame)
        game.newGame();
    else if (!game.loadGame(json ? Game::Json : Game::Binary))
            return 1;
    // Game is played; changes are made...
    QTextStream(stdout) << "Game ended in the following state:\n";
    game.print();
    if (!game.saveGame(json ? Game::Json : Game::Binary))
        return 1;

    return 0;
}