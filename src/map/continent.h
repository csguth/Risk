#ifndef MAP_CONTINENT_H
#define MAP_CONTINENT_H

#include <string>
#include <algorithm>

namespace risk {
namespace map {

class continent {
	std::string name_;
public:
	continent(const std::string name);
	virtual ~continent();

	inline const std::string name() const { return name_; }
	inline const int num_territories() const { return 0; }
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