#ifndef MAP_CONTINENT_H
#define MAP_CONTINENT_H

#include <string>
#include <algorithm>

#include "map.h"
#include "territory.h"

#include <memory>

namespace risk {
namespace map {

class map;
class territory;
class continent : public std::enable_shared_from_this<continent> {
	std::string name_;
	std::shared_ptr<map> map_;
	std::map<std::string, std::shared_ptr<territory> > territories_;
	int bonus_;
public:
	continent(const std::string name, int bonus);
	virtual ~continent();

	inline const std::string name() const { return name_; }
	inline const int num_territories() const { return territories_.size(); }
	inline const std::shared_ptr<map> get_map() const { return map_; }
	inline const std::map<std::string, std::shared_ptr<territory> > territories() const { return territories_; }
	inline const int bonus() const { return bonus_; }

	std::shared_ptr<territory> find_territory(const std::string name) const;
	void set_map(std::shared_ptr<map> m);
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