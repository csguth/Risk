/*
 * dice_fight.cpp
 *
 *  Created on: 12 de jul de 2015
 *      Author: csguth
 */

#include "land_attack_dice_fight.h"

namespace risk {
namespace die {

land_attack_dice_fight::land_attack_dice_fight(land_attack_attack_die & attack_die, int attack_size,
		land_attack_defense_die & defense_die, int defense_size): attacks_(0), defenses_(0)
{
	// roll attack dice
	std::vector<land_attack_die_face> attacks;
	for(int i = 0; i < attack_size; i++)
		attacks.emplace_back(attack_die.roll());

	// roll defense dice
	std::vector<land_defense_die_face> defenses;
	for(int i = 0; i < defense_size; i++)
		defenses.emplace_back(defense_die.roll());

	// compare dice
	for(std::size_t i = 0; i < std::min(attacks.size(), defenses.size()); i++)
	{
		fights_.push_back(land_attack_die_fight(attacks.at(i), defenses.at(i)));
		switch(fights_.back().result())
		{
		case land_attack_die_fight_result::ATTACK:
			attacks_++;
			break;
		case land_attack_die_fight_result::DEFENSE:
			defenses_++;
			break;
		case land_attack_die_fight_result::DEFAULT:
		default:
			break;
		}
	}
}

land_attack_dice_fight::~land_attack_dice_fight() {
}

} /* namespace die */
} /* namespace risk */
