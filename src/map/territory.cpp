/*
 * territory.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "territory.h"
#include <limits>

namespace risk {
namespace map {

const territory territory::null("null territory");
territory::id territory::null_id() {
    return std::numeric_limits<id>::max();
}

territory::territory(std::string name) :
        m_name(name) {
}

territory::~territory() {
}

} /* namespace map */
} /* namespace risk */

