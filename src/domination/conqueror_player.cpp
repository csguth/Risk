#include "conqueror_player.h"

namespace risk{
namespace domination{


conqueror_player::conqueror_player(const std::string name) :
	risk::player::player(name)
{

}
conqueror_player::~conqueror_player()
{

}

void conqueror_player::conquest(std::shared_ptr<conquerable_territory> territory)
{
	territories_.insert(std::make_pair(territory->name(), territory));
}

void conqueror_player::release(std::shared_ptr<conquerable_territory> territory)
{
	territories_.erase(territories_.at(territory->name())->name());
}

}
}