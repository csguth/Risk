#include <catch/catch.hpp>
#include "../src/map/territory.h"
#include "../src/player/player.h"

TEST_CASE( "territory begins with null player", "[territory][player]" )
{
	risk::map::territory brazil{"Brazil"};
	REQUIRE( !brazil.player() );
}

TEST_CASE( "player assignment", "[territory][player]" )
{
	risk::map::territory brazil{"Brazil"};
	std::shared_ptr<risk::player::player> csguth{new risk::player::player{"csguth"}};
	brazil.player(csguth);
	REQUIRE( brazil.player() == csguth );
}

TEST_CASE( "territory domination", "[territory][player]" )
{
	risk::map::territory brazil{"Brazil"};
	std::shared_ptr<risk::player::player> csguth{new risk::player::player{"csguth"}};
	std::shared_ptr<risk::player::player> johndoe{new risk::player::player{"johndoe"}};

	brazil.player(csguth);
	brazil.player(johndoe);
	REQUIRE( brazil.player() == johndoe );
	REQUIRE_FALSE( csguth.has_territory(brazil) );
}