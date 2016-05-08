#pragma once

#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <vector>
#include <map>
#include <memory>
#include "characterSingleton.h"

const int WINDOWX = 800;			//width of window
const int WINDOWY = 600;			//height of window
const int VIEWFOCUESOFFSET = 300;	//how much width to decrease in window

/*
General Singleton Class.
This global static class holds all the available audios
for appropriate moves in the game.

class holds map that each node in it represent a sound of
a move.
In addition the class also loads the font of the game and the
life bar textures.
*/
class GeneralSingleton
{
public:

	//key enum for sound map
	enum sound
	{
		highKick = 0, highPunch, lowKick, lowPunch, danforden, kitanaName, liuKangName,
		sonyaName, subzeroName, characterselect,
		fight, roundone, roundtwo, roundthree, endmach, specialMove
	};

	typedef std::map<sound, sf::Music> soundMap;

	//d-tor default
	~GeneralSingleton();

	//returns the only instance of the sigleton
	static GeneralSingleton &instance();

	//returns the game font
	sf::Font &getFont();

	//returns the life bar texture
	sf::Texture &getLifeBar();

	//plays the wanted sound by received argument
	void playSound(const sound soundType);

	//plays the wanted sound (the character name in sound) by received argument
	void playCharacterName(const characterSingleton::character name);


private:

	//default c-tor loads font and all sounds   
	GeneralSingleton();

	//sets not to compile those functions
	GeneralSingleton(const GeneralSingleton&) = delete;
	GeneralSingleton& operator=(const GeneralSingleton&) = delete;

	//game font
	sf::Font _gameFont;

	//life bar for each character
	sf::Texture _lifeBar;

	//map of the game sounds 
	soundMap _soundMap;


	void loadSoundFile();
};

