#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;
// Setup Players Default Animated Sprite


int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	AnimatedSprite animated_sprite(texture);
	animated_sprite.addFrame(sf::IntRect(3, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(88, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 3, 84, 84));

	// Setup the Player
	Player player(animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{		
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) //Idling
				{
					input.setCurrent(0);

				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) //Climbing
				{
					input.setCurrent(1);
					
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) //Jumping
				{
					input.setCurrent(2);
				}
				//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) //Swording
				//{
				//	input.setCurrent(4);
				//}
				//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) //Shoveling
				//{
				//	input.setCurrent(5);
				//}
				//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) //Hammering
				//{
				//	input.setCurrent(6);
				//}
				//break;
			default:
				break;
			}
		}

		// Handle input to Player
		player.handleInput(input);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};