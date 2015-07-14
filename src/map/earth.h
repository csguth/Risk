#ifndef MAP_EARTH_H
#define MAP_EARTH_H

#include "map.h"
#include <memory>

namespace risk {
namespace map {

class earth : public map {
	static const std::unique_ptr<map> instance_;
	earth();
public:	
	virtual ~earth();
	static const std::unique_ptr<map> & instance() { return earth::instance_; }

};	

}
}



#endif /* MAP_EARTH_H */
