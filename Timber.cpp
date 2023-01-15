//Start with necessary libraries
#include <SFML/Graphics.hpp>

//Make things easier on ourself
using namespace sf;

//This is where it begins!
int main() {

	//Make a video mode object
	VideoMode vm(1920, 1080);

	//Now make the game window!
	RenderWindow window(vm, "Timber!!", Style::Fullscreen);

	//Create a texture to hold the background
	Texture textureBackground;

	//Load a graphic onto the background
	textureBackground.loadFromFile("graphics/background.png");

	//Create a sprite
	Sprite spriteBackground;

	//Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	//Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	//Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	//Prepare the bee!
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);

	//Is the bee moving?
	bool beeActive = false;

	//What is the airspeed of a bee??
	float beeSpeed = 0.0f;

	//Making three clouds from one texture!
	Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");

	//3 new sprites with the same texture!
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	//Position the clouds on the left at different heights
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);

	//Are the clouds currently onscreen?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	//How fast are the clouds?
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	//Variables to control time itself
	Clock clock;

	while (window.isOpen())
	{
		//****************
		//Handle player input
		//****************
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}


		//****************
		//Update the scene
		//****************
		
		//Measure time
		Time dt = clock.restart();

		
		//****************
		//Draw the scene
		//****************
		
		//Clear last frame
		window.clear();

		//Draw game scene here
		window.draw(spriteBackground);

		//Draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		//Draw the tree
		window.draw(spriteTree);

		//Draw the bee!!
		window.draw(spriteBee);

		//Show everything we drew
		window.display();
	}


	return 0;
}