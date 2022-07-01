#pragma once

#include "Inventory.h"
using namespace std;

class Character
{
public:
  Character();
  virtual ~Character();

  //Functions
  void initialize(const string name);
  void printCharacterStats() const;
  
  void levelUp();

  //Accessors

  inline const double& getX() const { return this->xPos; }
  inline const double& getY() const { return this->yPos; }
  inline const string& getName() const { return this->name; }
  inline const int& getLevel() const { return this->level; }
  inline const int& getExperience() const { return this->experience; }
  inline const int& getExpToNext() const { return this->expToNext; }
  inline const int& getHealth() const { return this->health; }
  inline const int& getHealthMax() const { return this->healthMax; }
  inline const int& getMana() const { return this->mana; }
  inline const int& getManaMax() const { return this->manaMax; }
  inline const int& getStamina() const { return this->stamina; }
  inline const int& getStaminaMax() const { return this->staminaMax; }
  inline const int& getDamageMin() const { return this->damageMin; }
  inline const int& getDamageMax() const { return this->damageMax; }
  inline const int& getDefense() const { return this->defense; }
  //Modifiers

private:
  double xPos;
  double yPos;

  string name;
  int level;
  int experience;
  int expToNext;
  int health;
  int healthMax;
  int mana;
  int manaMax;
  int stamina;
  int staminaMax;
  int damageMin;
  int damageMax;
  int defense;

  int strength;
  int vitality;
  int dexterity;
  int intelligence;

  int statPoints;
  int skillPoints;

};