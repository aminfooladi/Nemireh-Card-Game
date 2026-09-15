#include "main.h"
#include "Game.h"


int main()
{
    srand(time(0));

    Game* game = new Game;
    while (true)
    {
        if (game->getStatus() == "loginPage")
        {
            game->loadPlayersAccount();
            Player temp = game->getMinPlayer();
            game->loginPage(temp);
        }
        if (game->getStatus() == "inMainMenu")
        {
            game->mainMenu();
        }
        if (game->getStatus() == "stopMenu")
        {
            game->stopMenu();
        }
        if (game->getStatus() == "playGame")
        {
                game->playGame();
        }
        if (game->getStatus() == "endGame")
        {
            game->savePlayersAccount();
            game->endGame();
            return 0;
        }
    }
}