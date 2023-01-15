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

		//Setup bee movement
		if (!beeActive)
		{
			//How fast should he BEE
			srand((int)time(0));
			beeSpeed = (rand() % 200) + 150;

			//How high is the bee?
			srand((int)time(0) * 10);
			float height = (rand() % 500) + 500;
			spriteBee.setPosition(2000, height);
			beeActive = true;
		}
		else
		{
			//Let's move the bee!
			spriteBee.setPosition(
				spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), 
				spriteBee.getPosition().y);

			//When the bee reaches the other side
			if (spriteBee.getPosition().x < -100)
			{
				//Set it up for another bee!
				beeActive = false;
			}
		}

		//Now let's move the clouds!
		//Cloud 1
		if (!cloud1Active)
		{
			//How fast is the cloud
			srand((int)time(0) * 10);
			cloud1Speed = (rand() % 200);

			//How high is the cloud
			srand((int)time(0) * 10);
			float height = (rand() % 150);
			spriteCloud1.setPosition(-200, height);
			cloud1Active = true;
		}
		else
		{
			spriteCloud1.setPosition(
				spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()),
				spriteCloud1.getPosition().y);

			//When the cloud reaches the far right side, offscreen
			if (spriteCloud1.getPosition().x > 1920)
			{
				//Reset the cloud to be re-run!
				cloud1Active = false;
			}
		}

		if (!cloud2Active)
		{
			//How fast is the cloud
			srand((int)time(0) * 20);
			cloud2Speed = (rand() % 200);

			//How high is the cloud
			srand((int)time(0) * 20);
			float height = (rand() % 300) - 150;
			spriteCloud2.setPosition(2200, height);
			cloud2Active = true;
		}
		else
		{
			spriteCloud2.setPosition(
				spriteCloud2.getPosition().x - (cloud2Speed * dt.asSeconds()),
				spriteCloud2.getPosition().y);

			//When the cloud reaches the far right side, offscreen
			if (spriteCloud2.getPosition().x < -100)
			{
				//Reset the cloud to be re-run!
				cloud2Active = false;
			}
		}

		if (!cloud3Active)
		{
			//How fast is the cloud
			srand((int)time(0) * 25);
			cloud3Speed = (rand() % 200);

			//How high is the cloud
			srand((int)time(0) * 30);
			float height = (rand() % 450) - 150;
			spriteCloud3.setPosition(-200, height);
			cloud3Active = true;
		}
		else
		{
			spriteCloud3.setPosition(
				spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()),
				spriteCloud3.getPosition().y);

			//When the cloud reaches the far right side, offscreen
			if (spriteCloud3.getPosition().x > 1920)
			{
				//Reset the cloud to be re-run!
				cloud3Active = false;
			}
		}
		
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