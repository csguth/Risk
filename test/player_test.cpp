#include <catch/catch.hpp>
#include "../src/player/player.h"

TEST_CASE( "player name" )
{
	risk::player::player p{"csguth"};
	REQUIRE( p.name() == "csguth" );
}