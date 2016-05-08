#pragma once

#include <vector>
#include <SFML\Graphics.hpp>

class ImageSingelton
{
public:

	enum Arena
	{
		desert = 0, city, dungeon, portal
	};

	~ImageSingelton(){};

	static ImageSingelton &instance();

	sf::Texture &getArenaTexture(int pos);
	size_t getNumOfArenas() const;

	sf::Texture& getBackground();
	sf::Texture& getFightTexture();

private:
	ImageSingelton(); 
	
	ImageSingelton(const ImageSingelton&) = delete;
	ImageSingelton& operator=(const ImageSingelton&) = delete;

	std::vector<sf::Texture> _arenaTextures;

	sf::Texture _background;
	sf::Texture _fight;
	std::vector <sf::Texture> _arena;

};





