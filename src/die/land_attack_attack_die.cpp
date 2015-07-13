/*
 * land_attack_attack_die.cpp
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#include "land_attack_attack_die.h"

namespace risk {
namespace die {

land_attack_attack_die::land_attack_attack_die() :
	simple_die<land_attack_die_face>({1, 2, 3, 4, 5, 6})
{
}

land_attack_attack_die::~land_attack_attack_die() {
}

} /* namespace die */
} /* namespace risk */
