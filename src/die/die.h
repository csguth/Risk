/*
 * die.h
 *
 *  Created on: 11 de jul de 2015
 *      Author: csguth
 */

#ifndef DIE_DIE_H_
#define DIE_DIE_H_

#include "die_face.h"

namespace risk {
namespace die {

template<typename T>
class die {
protected:
public:
    virtual ~die() {
    }
    virtual const T roll() = 0;
};

} /* namespace die */
} /* namespace risk */

#endif /* DIE_DIE_H_ */
