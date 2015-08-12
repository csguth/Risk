/*
 * land_attack_die_fight.cpp
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#include "land_attack_die_fight.h"

namespace risk {
namespace die {

land_attack_die_fight::land_attack_die_fight(land_attack_die_face attack,
        land_defense_die_face defense) :
        attack_(attack), defense_(defense) {
    result_ = land_attack_die_fight_result::ATTACK;
    if (defense_.wins(attack_))
        result_ = land_attack_die_fight_result::DEFENSE;
}
land_attack_die_fight::~land_attack_die_fight() {
}

} /* namespace die */
} /* namespace risk */

