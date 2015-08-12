/*
 * territory.cpp
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#include "territory.h"

namespace risk {
namespace map {

const territory territory::null("null territory");

territory::territory(std::string name) :
        m_name(name) {
}

territory::~territory() {
}

} /* namespace map */
} /* namespace risk */
