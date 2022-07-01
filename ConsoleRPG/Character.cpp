
#include "Character.h"

Character::Character()
{

  xPos = 0.0;
  yPos = 0.0;
  name = "";
  level = 1;
  experience = 0;
  expToNext = 0;
  health = 0;
  healthMax = 0;
  mana = 0;
  manaMax = 0;
  stamina = 0;
  staminaMax = 0;
  damageMin = 0;
  damageMax = 0;
  defense = 0;

  strength = 0;
  vitality = 0;
  dexterity = 0;
  intelligence = 0;
  
  statPoints = 0;
  skillPoints = 0;

}

Character::~Character()
{

}

//Functions
void Character::initialize(string name)
{
  this->xPos = 0.0;
  this->yPos = 0.0;
  this->name = name;
  this->level = level;
  this->experience = 0;
  //insert an algorithm here for progressive difficulty
  this->expToNext = (50/3)*(pow(level, 3) - 6*pow(level, 2) + (17 * level) - 12);;
  this->health = 10;
  this->healthMax = 10;
  this->mana = 10;
  this->manaMax = 10;
  this->stamina = 10;
  this->staminaMax = 10;
  this->damageMin = 2;
  this->damageMax = 4;
  this->defense = 1;

  this->strength = 5;
  this->vitality = 5;
  this->dexterity = 5;
  this->intelligence = 5;

  this->statPoints = 0;
  this->skillPoints = 0;
}

void Character::printCharacterStats() const
{
  system("clear");
  std::cout << " = Character Sheet = \n" << std::endl;
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Level: " << this->level << std::endl;
  std::cout << "Experience: " << this->experience << std::endl;
  std::cout << "Exp to next level: " << this->expToNext << std::endl;
  std::cout << std::endl;
  std::cout << "Strength: " << this->strength << std::endl;
  std::cout << "Vitality: " << this->vitality  << std::endl;
  std::cout << "Dexterity: " << this->dexterity << std::endl;
  std::cout << "Intelligence: " << this->intelligence << std::endl;
  std::cout << std::endl;
  std::cout << "HP: " << this->health << "/" << this->healthMax << std::endl;
  std::cout << "Stamina: " << this->stamina << "/" << this->staminaMax << std::endl;
  std::cout << "Damage: " << this->damageMin << "-" << this->damageMax << std::endl;
  std::cout << "Defense: " << this->defense << std::endl;
  std::cout << std::endl;
}

void Character::levelUp()
{
  while (experience >= expToNext)
  {
    experience -= expToNext;
    level++;
    this->experience = 0;
    this->expToNext = (50/3)*(pow(level, 3) - 6*pow(level, 2) + (17 * level) - 12);

    this->statPoints++;
    this->skillPoints++;
  }
}