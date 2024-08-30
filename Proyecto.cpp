#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1000), "Our SFML Project!");
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Images/MainSkin.png");
    sf::Sprite player(playerTexture);
    player.setScale(sf::Vector2f(2, 2));

    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("Images/EnemySkin.png");
    sf::Sprite enemy(enemyTexture);
    enemy.setScale(sf::Vector2f(2, 2));
    enemy.setPosition(sf::Vector2f(960, 540));

    enemy.setOrigin(sf::Vector2f(8, 8));

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::Vector2f vRequestedPlayerMovement(0.0f, 0.0f);
        // Gather the player's input here
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            vRequestedPlayerMovement += sf::Vector2f(0.0f,-1.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            vRequestedPlayerMovement += sf::Vector2f(-1.0f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            vRequestedPlayerMovement += sf::Vector2f(0.0f, 1.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            vRequestedPlayerMovement += sf::Vector2f(1.0f, 0.0f);
        }
        player.move(vRequestedPlayerMovement);

        window.clear();
        window.draw(player);
        window.draw(enemy);
        window.display();
    }

    return 0;
}