#ifndef MAP_SOUTH_AMERICA_H
#define MAP_SOUTH_AMERICA_H

#include "continent.h"

namespace risk {
namespace map {

class south_america : public continent {
	static const std::unique_ptr<continent> instance_;
	south_america();
public:
	virtual ~south_america();
	static const std::unique_ptr<continent> & instance() { return south_america::instance_; }

};

}
}

#endif /* MAP_SOUTH_AMERICA_H */