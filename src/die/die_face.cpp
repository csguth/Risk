/*
 * die_face.cpp
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#include "die_face.h"

namespace risk {
namespace die {

die_face::die_face(die_face_value value) :
        value_(value) {

}

die_face::~die_face() {
}

bool die_face::operator >(const die_face& o) const {
    return value_ > o.value_;
}

bool die_face::operator ==(const die_face& o) const {
    return value_ == o.value_;
}

bool die_face::operator <(const die_face& o) const {
    return value_ < o.value_;
}

bool die::die_face::operator >=(const die_face& o) const {
    return value_ >= o.value_;
}

bool die::die_face::operator <=(const die_face& o) const {
    return value_ <= o.value_;
}

bool die_face::operator !=(const die_face& o) const {
    return value_ != o.value_;
}

bool die_face::wins(const die_face& o) const {
    return (*this) > o;
}

} /* namespace die */
} /* namespace risk */
