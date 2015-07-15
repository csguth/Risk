#ifndef MAP_TERRITORY_H
#define MAP_TERRITORY_H

#include <string>
#include <map>
#include <memory>

#include "continent.h"

namespace risk {
namespace map {

class continent;
class territory : public std::enable_shared_from_this<territory> {
	std::string name_;
	std::shared_ptr<continent> continent_;
	std::map<std::string, std::shared_ptr<territory> > neighborhood_;
public:
	territory(const std::string name);
	virtual ~territory();

	inline const std::string name() const { return name_; }
	inline const int num_neighbors() const { return neighborhood_.size(); }
	inline const std::shared_ptr<continent> get_continent() const { return continent_; }

	void set_continent(std::shared_ptr<continent> c);

	std::shared_ptr<territory> find_neighbor(const std::string name) const;
	void add_neighbor(std::shared_ptr<territory> neighbor);
};

}
}

#endif /* MAP_TERRITORY_H */