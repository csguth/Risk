#ifndef DOMINATION_CONQUEROR_PLAYER_H
#define DOMINATION_CONQUEROR_PLAYER_H

#include "../player/player.h"
#include "conquerable_territory.h"
#include <map>

namespace risk{
namespace domination{

class conquerable_territory;
class conqueror_player : public risk::player::player {
	std::map<std::string, std::shared_ptr<conquerable_territory> > territories_;
public:
	conqueror_player(const std::string name);
	virtual ~conqueror_player();
	inline const int num_territories() const { return territories_.size(); }
	inline const std::shared_ptr<conquerable_territory> territory(const std::string name) const { return territories_.at(name); }

	void conquest(std::shared_ptr<conquerable_territory> territory);
	void release(std::shared_ptr<conquerable_territory> territory);
};

}
}

#endif /* DOMINATION_CONQUEROR_PLAYER_H */