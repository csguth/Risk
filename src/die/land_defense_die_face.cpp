/*
 * land_defense_die_face.cpp
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#include "land_defense_die_face.h"

namespace risk {
namespace die {

land_defense_die_face::land_defense_die_face(die_face_value value) :
        die_face(value) {
}

land_defense_die_face::~land_defense_die_face() {
}

bool land_defense_die_face::wins(const land_attack_die_face& o) const {
    return (*this) >= o;
}

} /* namespace die */
} /* namespace risk */
