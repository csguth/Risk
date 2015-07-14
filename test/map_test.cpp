#include <catch/catch.hpp>
#include "../src/map/map.h"
#include "../src/map/earth.h"
#include "../src/map/continent.h"
#include <exception>

TEST_CASE( "map name", "[map]" )
{
	risk::map::map map{"earth"};
	REQUIRE( map.name() == "earth" );
}

TEST_CASE( "created map with 0 continents", "[map]" )
{
	risk::map::map map{"earth"};
	REQUIRE( map.num_continents() == 0 );
}

TEST_CASE( "continent name", "[map][continent]" )
{
	risk::map::continent america{"South America"};
	risk::map::continent_has_name comparator("South America");
	REQUIRE( america.name() == "South America" );
	REQUIRE( comparator(america) );
} 

TEST_CASE( "created continent with 0 territories", "[map][continent]" )
{
	risk::map::continent america{"South America"};
	REQUIRE( america.num_territories() == 0 );
} 

TEST_CASE( "add continent to map", "[map][continent]" )
{
	risk::map::map map{"earth"};
	risk::map::continent america{"South America"};
	map.add_continent(america);
	REQUIRE( map.num_continents() == 1 );
}

TEST_CASE( "find continent by name", "[map][continent]" )
{
	risk::map::map map{"earth"};
	risk::map::continent america{"South America"};
	map.add_continent(america);
	REQUIRE_NOTHROW( map.find_continent("South America") );
	REQUIRE( map.find_continent("South America").name() == "South America" );
} 

TEST_CASE( "doesn't find continent by name", "[map][continent]" )
{
	risk::map::map map{"earth"};
	risk::map::continent america{"South America"};
	map.add_continent(america);
	REQUIRE_THROWS_AS( map.find_continent("Africa"), std::out_of_range );
} 

TEST_CASE( "earth with 6 continents", "[map][continent]" )
{
	const std::unique_ptr<risk::map::map> & earth = risk::map::earth::instance();

	REQUIRE( earth->num_continents() == 6 );
	REQUIRE_NOTHROW( earth->find_continent("North America") );
	REQUIRE_NOTHROW( earth->find_continent("South America") );
	REQUIRE_NOTHROW( earth->find_continent("Europe") );
	REQUIRE_NOTHROW( earth->find_continent("Africa") );
	REQUIRE_NOTHROW( earth->find_continent("Oceania") );
	REQUIRE_THROWS_AS( earth->find_continent("Antarctica"), std::out_of_range );

}