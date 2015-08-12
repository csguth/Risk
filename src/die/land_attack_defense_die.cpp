/*
 * land_attack_defense_die.cpp
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#include "land_attack_defense_die.h"

namespace risk {
namespace die {

land_attack_defense_die::land_attack_defense_die() :
        simple_die<land_defense_die_face>( { 1, 2, 3, 4, 5, 6 }) {

}

land_attack_defense_die::~land_attack_defense_die() {
}

} /* namespace die */
} /* namespace risk */
