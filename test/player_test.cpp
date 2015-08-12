#include <catch/catch.hpp>
#include "../src/player/player.h"
#include "../src/player/lobby.h"

TEST_CASE( "player name" )
{
	risk::player::player p{"csguth"};
	REQUIRE( p.name() == "csguth" );
}

TEST_CASE( "registering player in lobby" )
{
	risk::player::lobby l;
	REQUIRE( l.size() == static_cast<std::size_t>(0) );
	auto csguth_id = l.register_player("csguth");
	REQUIRE( l.size() == static_cast<std::size_t>(1) );
	auto other_id = l.register_player("other");
	REQUIRE( l.size() == static_cast<std::size_t>(2) );
	REQUIRE( other_id != csguth_id );
}

TEST_CASE( "removing player" )
{
	risk::player::lobby l;
	auto csguth_id = l.register_player("csguth");
	auto other_id = l.register_player("other");
	REQUIRE( l.remove_player(csguth_id) );
	REQUIRE( l.size() == 1 );
	REQUIRE( l.remove_player(other_id) );
	REQUIRE( l.size() == 0 );
	REQUIRE( !l.remove_player(other_id) );
	REQUIRE( l.size() == 0 );
}

