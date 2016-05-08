#include "characterSingleton.h"


characterSingleton::characterSingleton()
{
	CharacterMap map;

	//loading subzero textures
	insertImages("character/subzero", "characterBox", characterBox, 1, map);
	insertImages("character/subzero", "duckbeinghit", duckbeinghit, 3, map);
	insertImages("character/subzero", "duckblock", duckblock, 3, map);
	insertImages("character/subzero", "duckhighpunch", duckhighpunch, 5, map);
	insertImages("character/subzero", "ducking", ducking, 3, map);
	insertImages("character/subzero", "duckkick", duckkick, 3, map);
	insertImages("character/subzero", "ducklowpunch", ducklowpunch, 3, map);
	insertImages("character/subzero", "highkick", highkick, 6, map);
	insertImages("character/subzero", "highpunch", highpunch, 6, map);
	insertImages("character/subzero", "jumpbeinghit", jumpbeinghit, 13, map);
	insertImages("character/subzero", "jumpkick", jumpkick, 3, map);
	insertImages("character/subzero", "jumppunch", jumppunch, 3, map);
	insertImages("character/subzero", "jumpside", jumpside, 8, map);
	insertImages("character/subzero", "lowkick", lowkick, 6, map);
	insertImages("character/subzero", "jumppunch", jumppunch, 3, map);
	insertImages("character/subzero", "lowpunch", lowpunch, 4, map);
	insertImages("character/subzero", "stand", stand, 9, map);
	insertImages("character/subzero", "standbeinghit", standbeinghit, 3, map);
	insertImages("character/subzero", "standblock", standblock, 3, map);
	insertImages("character/subzero", "victory", victory, 5, map);
	insertImages("character/subzero", "walking", walking, 9, map);
	insertImages("character/subzero", "defeat", Defeat, 6, map);
	insertImages("character/subzero", "specialattack", specialAttack, 3, map);
	_characters.push_back(map);
	
	map.erase(map.begin(), map.end());

	//loading sonya textures
	insertImages("character/sonya", "characterBox", characterBox, 1, map);
	insertImages("character/sonya", "duckbeinghit", duckbeinghit, 3, map);
	insertImages("character/sonya", "duckblock", duckblock, 3, map);
	insertImages("character/sonya", "duckhighpunch", duckhighpunch, 5, map);
	insertImages("character/sonya", "ducking", ducking, 3, map);
	insertImages("character/sonya", "duckkick", duckkick, 3, map);
	insertImages("character/sonya", "ducklowpunch", ducklowpunch, 3, map);
	insertImages("character/sonya", "highkick", highkick, 8, map);
	insertImages("character/sonya", "highpunch", highpunch, 6, map);
	insertImages("character/sonya", "jumpbeinghit", jumpbeinghit, 12, map);
	insertImages("character/sonya", "jumpkick", jumpkick, 3, map);
	insertImages("character/sonya", "jumppunch", jumppunch, 3, map);
	insertImages("character/sonya", "jumpside", jumpside, 8, map);
	insertImages("character/sonya", "lowkick", lowkick, 6, map);
	insertImages("character/sonya", "jumppunch", jumppunch, 3, map);
	insertImages("character/sonya", "lowpunch", lowpunch, 5, map);
	insertImages("character/sonya", "stand", stand, 8, map);
	insertImages("character/sonya", "standbeinghit", standbeinghit, 3, map);
	insertImages("character/sonya", "standblock", standblock, 3, map);
	insertImages("character/sonya", "victory", victory, 8, map);
	insertImages("character/sonya", "walking", walking, 9, map);
	insertImages("character/sonya", "defeat", Defeat, 7, map);
	insertImages("character/sonya", "specialattack", specialAttack, 6, map);
	_characters.push_back(map);
	
	map.erase(map.begin(), map.end());

	//loading Liu-Kang textures
	insertImages("character/Liu-Kang", "characterBox", characterBox, 1, map);
	insertImages("character/Liu-Kang", "duckbeinghit", duckbeinghit, 3, map);
	insertImages("character/Liu-Kang", "duckblock", duckblock, 3, map);
	insertImages("character/Liu-Kang", "duckhighpunch", duckhighpunch, 5, map);
	insertImages("character/Liu-Kang", "ducking", ducking, 3, map);
	insertImages("character/Liu-Kang", "duckkick", duckkick, 3, map);
	insertImages("character/Liu-Kang", "ducklowpunch", ducklowpunch, 3, map);
	insertImages("character/Liu-Kang", "highkick", highkick, 8, map);
	insertImages("character/Liu-Kang", "highpunch", highpunch, 5, map);
	insertImages("character/Liu-Kang", "jumpbeinghit", jumpbeinghit, 13, map);
	insertImages("character/Liu-Kang", "jumpkick", jumpkick, 3, map);
	insertImages("character/Liu-Kang", "jumppunch", jumppunch, 3, map);
	insertImages("character/Liu-Kang", "jumpside", jumpside, 8, map);
	insertImages("character/Liu-Kang", "lowkick", lowkick, 6, map);
	insertImages("character/Liu-Kang", "jumppunch", jumppunch, 3, map);
	insertImages("character/Liu-Kang", "lowpunch", lowpunch, 4, map);
	insertImages("character/Liu-Kang", "stand", stand, 16, map);
	insertImages("character/Liu-Kang", "standbeinghit", standbeinghit, 3, map);
	insertImages("character/Liu-Kang", "standblock", standblock, 3, map);
	insertImages("character/Liu-Kang", "victory", victory, 15, map);
	insertImages("character/Liu-Kang", "walking", walking, 8, map);
	insertImages("character/Liu-Kang", "defeat", Defeat, 8, map);
	insertImages("character/Liu-Kang", "specialattack", specialAttack, 5, map);

	_characters.push_back(map);

	map.erase(map.begin(), map.end());

	//loading Kitana textures
	insertImages("character/Kitana", "characterBox", characterBox, 1, map);
	insertImages("character/Kitana", "duckbeinghit", duckbeinghit, 3, map);
	insertImages("character/Kitana", "duckblock", duckblock, 3, map);
	insertImages("character/Kitana", "duckhighpunch", duckhighpunch, 5, map);
	insertImages("character/Kitana", "ducking", ducking, 3, map);
	insertImages("character/Kitana", "duckkick", duckkick, 3, map);
	insertImages("character/Kitana", "ducklowpunch", ducklowpunch, 3, map);
	insertImages("character/Kitana", "highkick", highkick, 8, map);
	insertImages("character/Kitana", "highpunch", highpunch, 5, map);
	insertImages("character/Kitana", "jumpbeinghit", jumpbeinghit, 12, map);
	insertImages("character/Kitana", "jumpkick", jumpkick, 3, map);
	insertImages("character/Kitana", "jumppunch", jumppunch, 3, map);
	insertImages("character/Kitana", "jumpside", jumpside, 8, map);
	insertImages("character/Kitana", "lowkick", lowkick, 6, map);
	insertImages("character/Kitana", "jumppunch", jumppunch, 3, map);
	insertImages("character/Kitana", "lowpunch", lowpunch, 4, map);
	insertImages("character/Kitana", "stand", stand, 8, map);
	insertImages("character/Kitana", "standbeinghit", standbeinghit, 3, map);
	insertImages("character/Kitana", "standblock", standblock, 3, map);
	insertImages("character/Kitana", "victory", victory, 6, map);
	insertImages("character/Kitana", "walking", walking, 9, map);
	insertImages("character/Kitana", "defeat", Defeat, 6, map);
	insertImages("character/Kitana", "specialattack", specialAttack, 5, map);


	_characters.push_back(map);

	//special move loading
	specialMap specialmap;

	
	insertImages2("character/subzero", "specialobject", objectMove, 7, specialmap);
	insertImages2("character/subzero", "specialobjectcollision", objectcollide, 9, specialmap);

	_specialMove.push_back(specialmap);


	specialmap.erase(specialmap.begin(), specialmap.end());
	insertImages2("character/sonya", "specialobject", objectMove, 4, specialmap);
	insertImages2("character/sonya", "specialobjectcollision", objectcollide, 4, specialmap);

	_specialMove.push_back(specialmap);


	specialmap.erase(specialmap.begin(), specialmap.end());
	insertImages2("character/Liu-Kang", "specialobject", objectMove, 4, specialmap);
	insertImages2("character/Liu-Kang", "specialobjectcollision", objectcollide, 3, specialmap);

	_specialMove.push_back(specialmap);


	specialmap.erase(specialmap.begin(), specialmap.end());
	insertImages2("character/Kitana", "specialobject", objectMove, 5, specialmap);
	insertImages2("character/Kitana", "specialobjectcollision", objectcollide, 8, specialmap);

	_specialMove.push_back(specialmap);


}

//d-tor default	
characterSingleton::~characterSingleton()
{
}

//returns the only instance of the sigleton
characterSingleton &characterSingleton::instance()
{
	static characterSingleton instance;

	return instance;
}


void characterSingleton::insertImages(std::string originLocation,std::string move, Movement movekey, size_t numOfImages, CharacterMap &map)
{
	std::vector <sf::Texture> textures;

	for (size_t index = 1; index <= numOfImages; index++)
	{
		sf::Texture temp;
		temp.loadFromFile(originLocation + "/" + move + "/" + std::to_string(index) +".png");
		textures.push_back(temp);

	}

	map[movekey] = textures;

}


//returns the character's box
sf::Texture& characterSingleton::getBox(character chatType)
{
	
	return _characters[int(chatType)][characterBox][0];
}

//returns the vector of textures of movement by received argument
std::vector<sf::Texture>& characterSingleton::getMovement(character chatType, Movement move)
{
	return _characters[int(chatType)][move];
}

//returns the vector of textures of special move by received argument
std::vector<sf::Texture>& characterSingleton::getSpecialMove(character chatType, characterSpecialAttack move)
{
	return _specialMove[int(chatType)][move];
}

//returns number of total character in the game
size_t characterSingleton::numOfCharacters() const
{
	return _characters.size();
}
