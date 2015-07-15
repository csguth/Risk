#ifndef MAP_MAP_H
#define MAP_MAP_H

#include <string>
#include <map>
#include "continent.h"
#include <memory>

namespace risk {
namespace map {

class continent;
class map : public std::enable_shared_from_this<map> {
	std::string name_;
	std::map<std::string, std::shared_ptr<continent> > continents_;
public:
	map(const std::string name);
	virtual ~map();

	inline const std::string name() const { return name_; }
	inline const int num_continents() const { return continents_.size(); }
	void add_continent(std::shared_ptr<continent> continent);
	std::shared_ptr<continent> find_continent(const std::string name) const;
};

}
}


#endif /* MAP_MAP_H */