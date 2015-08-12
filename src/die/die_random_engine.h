/*
 * die_random_engine.h
 *
 *  Created on: 12 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_DIE_RANDOM_ENGINE_H_
#define DIE_DIE_RANDOM_ENGINE_H_

#include <random>

namespace risk {
namespace die {

class die_random_engine {
public:
    static std::random_device RANDOM_DEVICE;
    static std::default_random_engine RANDOM_ENGINE;
};

} /* namespace die */
} /* namespace risk */

#endif /* DIE_DIE_RANDOM_ENGINE_H_ */
