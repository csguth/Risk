/*
 * die_random_engine.cpp
 *
 *  Created on: 12 de jul de 2015
 *      Author: csguth
 */

#include "die_random_engine.h"

namespace risk {
namespace die {

std::random_device die_random_engine::RANDOM_DEVICE;
std::default_random_engine die_random_engine::RANDOM_ENGINE(RANDOM_DEVICE());

} /* namespace die */
} /* namespace risk */
