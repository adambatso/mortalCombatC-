#pragma once

#include <vector>
#include <map>
#include <string>
#include <SFML\Graphics.hpp>

/*
Character Singleton Class.
This global static class holds all the available textures
for each character in the game.
The textures include all the movements for the character.

class holds vector that each cell in it represent a character and all
of his textures.each cell holds map of textures.
*/
class characterSingleton
{
public:

	//enum for all the moves that character holds
	enum Movement{
		characterBox=0, duckbeinghit, duckblock, duckhighpunch, ducking, duckkick, ducklowpunch, highkick,
		highpunch, jumpbeinghit, jumpkick, jumppunch, jumpside, lowkick, lowpunch,
		stand, standbeinghit, standblock, victory, walking, walkingRight, walkingLeft, jumpsideRight, jumpsideLeft,
		jumpkickleft, jumpkickright, jumppunchleft, jumppunchright, duckbeinghitLeft, duckbeinghitRight, standbeinghitLeft, standbeinghitRight
		, jumpbeinghitLeft, jumpbeinghitRight, Defeat,specialAttack
	};

	//enum for the moves of special object
	enum characterSpecialAttack {
		objectMove=0, objectcollide
	};

	//characters names
	enum character { subZero = 0, sonya, liuKang, kitana };

	typedef std::map<Movement, std::vector<sf::Texture>> CharacterMap;
	typedef std::map<characterSpecialAttack, std::vector<sf::Texture>> specialMap;

	//d-tor default
	~characterSingleton();

	//returns the only instance of the sigleton
	static characterSingleton &instance();

	//returns the character's box
	sf::Texture& getBox(character chatType);

	//returns the vector of textures of movement by received argument
	std::vector<sf::Texture>& getMovement(character chatType, Movement move);

	//returns the vector of textures of special move by received argument
	std::vector<sf::Texture>& getSpecialMove(character chatType, characterSpecialAttack move);

	//returns number of total character in the game
	size_t numOfCharacters() const;

	void insertImages(std::string originLocation,std::string move, Movement movekey, size_t numOfImages, CharacterMap &map);


private:


	//default c-tor loads all textures 
	characterSingleton();

	//sets not to compile those functions
	characterSingleton(const characterSingleton&) = delete;
	characterSingleton& operator=(const characterSingleton&) = delete;

	//vector that each cell is map of textures - for moves
	std::vector<CharacterMap> _characters;

	//vector that each cell is map of textures - for special moves
	std::vector<specialMap> _specialMove;

};

typedef characterSingleton::character charName;





template <class T,class S>
void insertImages2(std::string originLocation, std::string move, T movekey, size_t numOfImages, S &map)
{
	std::vector <sf::Texture> textures;

	for (size_t index = 1; index <= numOfImages; index++)
	{
		sf::Texture temp;
		temp.loadFromFile(originLocation + "/" + move + "/" + std::to_string(index) + ".png");
		textures.push_back(temp);

	}

	map[movekey] = textures;
}
