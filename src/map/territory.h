/*
 * territory.h
 *
 *  Created on: 11 de ago de 2015
 *      Author: csguth
 */

#ifndef MAP_TERRITORY_H_
#define MAP_TERRITORY_H_

#include <string>

namespace risk {
namespace map {

class territory {
    std::string m_name;
public:
    using id = std::size_t;
    static const territory null;
    static id null_id();

    territory(std::string name);
    virtual ~territory();
    const std::string & name() const {
        return m_name;
    }
};

} /* namespace map */
} /* namespace risk */

#endif /* MAP_TERRITORY_H_ */
