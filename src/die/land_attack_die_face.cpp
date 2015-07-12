/*
 * land_attack_die_face.cpp
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#include "land_attack_die_face.h"

namespace risk {
namespace die {

land_attack_die_face::land_attack_die_face(die_face_value value) :
	die_face(value)
{

}

land_attack_die_face::~land_attack_die_face() {
}

bool land_attack_die_face::wins(const land_defense_die_face& other) const {
	return (*this) > other;
}

} /* namespace die */
} /* namespace risk */

