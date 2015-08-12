#include "player.h"

namespace risk{
namespace player{

	const player player::null("null player");

	player::player(const std::string name) :
		name_(name)
	{

	}

	player::~player()
	{
		
	}
}
}
