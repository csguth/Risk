#ifndef MAP_CONTINENT_H
#define MAP_CONTINENT_H

#include <string>
#include <algorithm>

#include "territory.h"

namespace risk {
namespace map {

class continent {
	std::string name_;
	std::map<std::string, std::shared_ptr<territory> > territories_;
public:
	continent(const std::string name);
	virtual ~continent();

	inline const std::string name() const { return name_; }
	inline const int num_territories() const { return territories_.size(); }

	std::shared_ptr<territory> find_territory(const std::string name) const;

	void add_territory(std::shared_ptr<territory> territory);
};

class continent_has_name
{ 
	const std::string name_;
public:
	continent_has_name(const std::string name);
	bool operator()(const continent & c) const;
};

}
}


#endif /* MAP_CONTINENT_H */