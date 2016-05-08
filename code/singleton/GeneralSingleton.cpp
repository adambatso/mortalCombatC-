#include "GeneralSingleton.h"


GeneralSingleton::GeneralSingleton()
{

	_gameFont.loadFromFile("plus/mkx.ttf");
	_lifeBar.loadFromFile("plus/lifebar.png");



	loadSoundFile();
}


GeneralSingleton::~GeneralSingleton()
{
}

GeneralSingleton &GeneralSingleton::instance()
{
	static GeneralSingleton instance;

	return instance;
}

sf::Font &GeneralSingleton::getFont()
{
	
	return _gameFont;
}

sf::Texture &GeneralSingleton::getLifeBar()
{
	return _lifeBar;
}



void GeneralSingleton::loadSoundFile()
{
	
	_soundMap[highKick].openFromFile("sound/hitsounds/highKick.ogg");
	_soundMap[lowKick].openFromFile("sound/hitsounds/lowKick.ogg");
	_soundMap[lowPunch].openFromFile("sound/hitsounds/lowPunch.ogg");
	_soundMap[highPunch].openFromFile("sound/hitsounds/highKick.ogg");
	
	_soundMap[danforden].openFromFile("sound/danforden/danforden.ogg");

	_soundMap[kitanaName].openFromFile("sound/names/kitana.ogg");
	_soundMap[liuKangName].openFromFile("sound/names/liuKang.ogg");
	_soundMap[sonyaName].openFromFile("sound/names/sonya.ogg");
	_soundMap[subzeroName].openFromFile("sound/names/subzero.ogg");

	_soundMap[characterselect].openFromFile("sound/other/characterselect.ogg");
	_soundMap[fight].openFromFile("sound/other/fight.ogg");
	_soundMap[roundone].openFromFile("sound/other/roundone.ogg");
	_soundMap[roundthree].openFromFile("sound/other/roundthree.ogg");
	_soundMap[roundtwo].openFromFile("sound/other/roundtwo.ogg");
	_soundMap[endmach].openFromFile("sound/other/startmach.ogg");
	_soundMap[specialMove].openFromFile("sound/other/specialMove.ogg");

}

void GeneralSingleton::playSound(const sound soundType) 
{
	_soundMap[soundType].play();
}

void GeneralSingleton::playCharacterName(const characterSingleton::character name)
{
	switch (name)
	{
	case characterSingleton::subZero :
		_soundMap[subzeroName].play();
		break;
	case characterSingleton::sonya:
		_soundMap[sonyaName].play();
		break;
	case characterSingleton::liuKang:
		_soundMap[liuKangName].play();
		break;
	case characterSingleton::kitana:
		_soundMap[kitanaName].play();
		break;
	default:
		break;
	}
}