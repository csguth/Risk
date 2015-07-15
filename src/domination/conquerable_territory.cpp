#include "conquerable_territory.h"

namespace risk {
namespace domination {

conquerable_territory::conquerable_territory(const std::string name):
	risk::map::territory(name),
	army_size_(0)
{

}
conquerable_territory::~conquerable_territory()
{

}

void conquerable_territory::player(std::shared_ptr<conqueror_player> player)
{
	player_ = player;
	army_size_ = 0;
	if(player_)
		army_size_ = 1;
}

void conquerable_territory::add_army(int qnt)
{
	army_size_ += qnt;
	army_size_ = std::max((player_?1:0), army_size_);
}

}
}
