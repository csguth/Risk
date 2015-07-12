/*
 * land_attack_die_fight.cpp
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#include "land_attack_die_fight.h"

namespace risk {
namespace die {

land_attack_die_fight::land_attack_die_fight(
		land_attack_attack_die& attacker,
		land_attack_defense_die& defenser) :
	attack_(attacker.roll()),
	defense_(defenser.roll())
{
	std::cout << "attack " << attack_.value() << std::endl;
	std::cout << "defense " << defense_.value() << std::endl;
	result_ = land_attack_die_fight_result::ATTACK;
	if(defense_.wins(attack_))
		result_ = land_attack_die_fight_result::DEFENSE;
}

land_attack_die_fight::~land_attack_die_fight() {
}

} /* namespace die */
} /* namespace risk */
