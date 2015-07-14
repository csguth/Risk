#ifndef MAP_TERRITORY_H
#define MAP_TERRITORY_H

#include <string>
#include <map>
#include <memory>

namespace risk {
namespace map {

class territory {
	std::string name_;
	std::map<std::string, std::shared_ptr<territory> > neighborhood_;
public:
	territory(const std::string name);
	virtual ~territory();

	inline const std::string name() const { return name_; }
	inline const int num_neighbors() const { return neighborhood_.size(); }
	
	std::shared_ptr<territory> find_neighbor(const std::string name) const;
	void add_neighbor(std::shared_ptr<territory> neighbor);
};

}
}

#endif /* MAP_TERRITORY_H */