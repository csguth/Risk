#ifndef DOMINATION_CONQUERABLE_TERRITORY_H
#define DOMINATION_CONQUERABLE_TERRITORY_H

#include "../map/territory.h"
#include "conqueror_player.h"

#include <memory>

namespace risk {
namespace domination {

class conqueror_player;
class conquerable_territory :
	public risk::map::territory
{
	friend class conqueror_player;
	std::shared_ptr<conqueror_player> player_;
	int army_size_;

	void player(std::shared_ptr<conqueror_player> player);
public:
	conquerable_territory(const std::string name);
	virtual ~conquerable_territory();
	inline std::shared_ptr<conqueror_player> player() { return player_; }
	inline int army_size() const { return army_size_; }

	void add_army(int qnt);

};

}
}

#endif /* DOMINATION_CONQUERABLE_TERRITORY_H */