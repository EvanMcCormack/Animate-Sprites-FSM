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

	std::cout << "Press: 0) for Idling \n       1) for Climbing \n       2) for Jumping \n       3) for Walking \n       4) for Swording \n       5) for Shoveling \n       6) for Hammering " << std::endl;


	AnimatedSprite animated_sprite(texture);
	animated_sprite.addFrame(sf::IntRect(3, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(88, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 3, 84, 84));

	AnimatedSprite animated_climb(texture);
	animated_climb.addFrame(sf::IntRect(3, 88, 84, 84));
	animated_climb.addFrame(sf::IntRect(3, 173, 84, 84));
	animated_climb.addFrame(sf::IntRect(3, 258, 84, 84));
	animated_climb.addFrame(sf::IntRect(3, 343, 84, 84));
	animated_climb.addFrame(sf::IntRect(3, 428, 84, 84));

	AnimatedSprite animated_jump(texture);
	animated_jump.addFrame(sf::IntRect(88, 88, 84, 84));
	animated_jump.addFrame(sf::IntRect(88, 173, 84, 84));
	animated_jump.addFrame(sf::IntRect(88, 258, 84, 84));
	animated_jump.addFrame(sf::IntRect(88, 343, 84, 84));
	animated_jump.addFrame(sf::IntRect(88, 428, 84, 84));

	AnimatedSprite animated_walk(texture);
	animated_walk.addFrame(sf::IntRect(173, 88, 84, 84));
	animated_walk.addFrame(sf::IntRect(173, 173, 84, 84));
	animated_walk.addFrame(sf::IntRect(173, 258, 84, 84));
	animated_walk .addFrame(sf::IntRect(173, 343, 84, 84));
	animated_walk.addFrame(sf::IntRect(173, 428, 84, 84));

	AnimatedSprite animated_sword(texture);
	animated_sword.addFrame(sf::IntRect(258, 88, 84, 84));
	animated_sword.addFrame(sf::IntRect(258, 173, 84, 84));
	animated_sword.addFrame(sf::IntRect(258, 258, 84, 84));
	animated_sword.addFrame(sf::IntRect(258, 343, 84, 84));
	animated_sword.addFrame(sf::IntRect(258, 428, 84, 84));

	AnimatedSprite animated_shoveling(texture);
	animated_shoveling.addFrame(sf::IntRect(343, 88, 84, 84));
	animated_shoveling.addFrame(sf::IntRect(343, 173, 84, 84));
	animated_shoveling.addFrame(sf::IntRect(343, 258, 84, 84));
	animated_shoveling.addFrame(sf::IntRect(343, 343, 84, 84));
	animated_shoveling.addFrame(sf::IntRect(343, 428, 84, 84));

	AnimatedSprite animated_hammering(texture);
	animated_hammering.addFrame(sf::IntRect(428, 88, 84, 84));
	animated_hammering.addFrame(sf::IntRect(428, 173, 84, 84));
	animated_hammering.addFrame(sf::IntRect(428, 258, 84, 84));
	animated_hammering.addFrame(sf::IntRect(428, 343, 84, 84));
	animated_hammering.addFrame(sf::IntRect(428, 428, 84, 84));

	// Setup the Player
	Player player(animated_sprite);
	player.setNewTexture(animated_sprite);
	player.setNewTexture(animated_climb);
	player.setNewTexture(animated_jump);
	player.setNewTexture(animated_walk);
	player.setNewTexture(animated_sword);
	player.setNewTexture(animated_shoveling);
	player.setNewTexture(animated_hammering);
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
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) //Walking
				{
					input.setCurrent(3);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) //Sword
				{
					input.setCurrent(4);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) //Shoveling
				{
					input.setCurrent(5);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
				{
					input.setCurrent(6);
				}
				break;
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