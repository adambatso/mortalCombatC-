#include "ImageSingelton.h"

ImageSingelton::ImageSingelton()

{ 
	_background.loadFromFile("plus/menubackground.jpg"); 
	_fight.loadFromFile("image/fight.png");

	sf::Texture tempText;
	tempText.loadFromFile("arena/desert.png");
	_arenaTextures.push_back(tempText);
	tempText.loadFromFile("arena/city.png");
	_arenaTextures.push_back(tempText);
	tempText.loadFromFile("arena/dungeon.png");
	_arenaTextures.push_back(tempText);
	tempText.loadFromFile("arena/portal.png");
	_arenaTextures.push_back(tempText);


}


ImageSingelton &ImageSingelton::instance()
{

	static ImageSingelton instance;

	return instance;

}



sf::Texture& ImageSingelton::getBackground()
{
	return _background;
}

sf::Texture &ImageSingelton::getArenaTexture(int pos)
{
	return _arenaTextures[pos];
}

size_t ImageSingelton::getNumOfArenas() const
{
	return _arenaTextures.size();
}

sf::Texture& ImageSingelton::getFightTexture()
{
	return _fight;
}
