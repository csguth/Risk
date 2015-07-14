#ifndef MAP_MAP_H
#define MAP_MAP_H

#include <string>
#include <map>
#include "continent.h"

namespace risk {
namespace map {

class map {
	std::string name_;
	std::map<std::string, continent> continents_;
public:
	map(const std::string name);
	virtual ~map();

	inline const std::string name() const { return name_; }
	inline const int num_continents() const { return continents_.size(); }
	void add_continent(const continent c);
	const continent & find_continent(const std::string name) const;
};

}
}


#endif /* MAP_MAP_H */