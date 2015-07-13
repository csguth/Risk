/*
 * dice_fight.h
 *
 *  Created on: 12 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_LAND_ATTACK_DICE_FIGHT_H_
#define DIE_LAND_ATTACK_DICE_FIGHT_H_

#include "land_attack_attack_die.h"
#include "land_attack_defense_die.h"
#include "land_attack_die_fight.h"

namespace risk {
namespace die {

class land_attack_dice_fight {
	std::vector<land_attack_die_fight> fights_;
	int attacks_;
	int defenses_;
public:
	land_attack_dice_fight(land_attack_attack_die & attack_die, int attack_size, land_attack_defense_die & defense, int defense_size);
	virtual ~land_attack_dice_fight();
	inline const int attacks() const { return attacks_; }
	inline const int defenses() const { return defenses_; }
};

} /* namespace die */
} /* namespace risk */

#endif /* DIE_LAND_ATTACK_DICE_FIGHT_H_ */
