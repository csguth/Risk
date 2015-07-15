#include "round_bonus.h"

namespace risk {
namespace bonus {

round_bonus::round_bonus(std::shared_ptr<risk::domination::conqueror_player> player):
	player_(player),
	size_(std::max(3, player->num_territories()/2))
{
}

round_bonus::~round_bonus()
{

}

bool round_bonus::apply(std::shared_ptr<risk::domination::conquerable_territory> territory)
{
	if(size_ == 0)
		return false;
	
	player_->territory(territory->name());
	
	territory->add_army(1);
	size_--;

	return true;
}

}
}