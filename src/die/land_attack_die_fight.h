/*
 * land_attack_die_fight.h
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_LAND_ATTACK_DIE_FIGHT_H_
#define DIE_LAND_ATTACK_DIE_FIGHT_H_

#include "die.h"
#include "land_attack_attack_die.h"
#include "land_attack_defense_die.h"

#include <iostream>

namespace risk {
namespace die {

enum class land_attack_die_fight_result {
	ATTACK, DEFENSE, DEFAULT
};

class land_attack_die_fight {
	land_attack_die_face attack_;
	land_defense_die_face defense_;
	land_attack_die_fight_result result_;

public:
	land_attack_die_fight(land_attack_die_face attack, land_defense_die_face defense);
	virtual ~land_attack_die_fight();

	inline const land_attack_die_face & attack() const { return attack_; }
	inline const land_defense_die_face & defense() const { return defense_; }
	inline const land_attack_die_fight_result result() const { return result_; }
};

} /* namespace die */
} /* namespace risk */

#endif /* DIE_LAND_ATTACK_DIE_FIGHT_H_ */
