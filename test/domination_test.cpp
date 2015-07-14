#include <catch/catch.hpp>
#include "../src/map/territory.h"
#include "../src/player/player.h"
#include "../src/domination/conqueror_player.h"
#include "../src/domination/conquerable_territory.h"

TEST_CASE( "conqueror player name" ,"[domination][map][player]")
{
	risk::domination::conqueror_player csguth{"csguth"};
	REQUIRE( csguth.name() == "csguth" );
}


TEST_CASE( "conqueror player starts without territories" ,"[domination][map][player]")
{
	risk::domination::conqueror_player csguth{"csguth"};
	REQUIRE( csguth.num_territories() == 0 );
}

TEST_CASE( "conquerable territory starts without player" ,"[domination][map][player]")
{
	risk::domination::conquerable_territory brazil{"Brazil"};
	REQUIRE_FALSE( brazil.player() );
}

TEST_CASE( "player conquest a empty territory" ,"[domination][map][player]")
{
	std::shared_ptr<risk::domination::conquerable_territory> brazil{new risk::domination::conquerable_territory{"Brazil"}};
	std::shared_ptr<risk::domination::conqueror_player> csguth{new risk::domination::conqueror_player{"csguth"}};
	
	csguth->conquest(brazil);
	brazil->player(csguth);

	REQUIRE( csguth->num_territories() == 1);
	REQUIRE( brazil->player() );
	REQUIRE_NOTHROW( csguth->territory("Brazil") );
}

TEST_CASE( "player release a territory" ,"[domination][map][player]")
{
	std::shared_ptr<risk::domination::conquerable_territory> brazil{new risk::domination::conquerable_territory{"Brazil"}};
	std::shared_ptr<risk::domination::conqueror_player> csguth{new risk::domination::conqueror_player{"csguth"}};
	
	csguth->conquest(brazil);
	brazil->player(csguth);
	REQUIRE_NOTHROW( csguth->release(brazil) );
	REQUIRE( csguth->num_territories() == 0 );
	REQUIRE_NOTHROW( brazil->release() );
	REQUIRE_THROWS_AS( csguth->release(brazil), std::out_of_range );
	REQUIRE_THROWS_AS( csguth->territory("Brazil"), std::out_of_range );
}



TEST_CASE( "player conquest a conquered territory" ,"[domination][map][player]")
{
	std::shared_ptr<risk::domination::conquerable_territory> brazil{new risk::domination::conquerable_territory{"Brazil"}};
	std::shared_ptr<risk::domination::conqueror_player> csguth{new risk::domination::conqueror_player{"csguth"}};
	std::shared_ptr<risk::domination::conqueror_player> johndoe{new risk::domination::conqueror_player{"johndoe"}};

	csguth->conquest(brazil);
	brazil->player(csguth);
	csguth->release(brazil);
	brazil->release();

	johndoe->conquest(brazil);
	brazil->player(johndoe);


	REQUIRE( csguth->num_territories() == 0);
	REQUIRE( johndoe->num_territories() == 1);
	REQUIRE( brazil->player() );
	REQUIRE_THROWS_AS( csguth->territory("Brazil"), std::out_of_range );
	REQUIRE_NOTHROW( johndoe->territory("Brazil") );
	REQUIRE(  johndoe->territory("Brazil")->player()->name() == "johndoe" );
}