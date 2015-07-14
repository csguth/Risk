#include <catch/catch.hpp>
#include "../src/map/map.h"
#include "../src/map/earth.h"
#include "../src/map/continent.h"
#include "../src/map/south_america.h"
#include "../src/map/territory.h"
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

TEST_CASE( "territory name", "[map][territory]" )
{
	risk::map::territory brazil{"Lígia"};
	REQUIRE( brazil.name() == "Lígia" );
	REQUIRE_FALSE( brazil.name() == "Brazil" );
}

TEST_CASE( "territory has empty neighborhood", "[map][territory]" )
{

	risk::map::territory brazil{"Brazil"};
	REQUIRE( brazil.num_neighbors() == 0 );

}

TEST_CASE( "add argentina as neighbor of brazil", "[map][territory]" )
{

	std::shared_ptr<risk::map::territory> brazil(new risk::map::territory{"Brazil"});
	std::shared_ptr<risk::map::territory> argentina(new risk::map::territory{"Argentina"});
	brazil->add_neighbor(argentina);
	argentina->add_neighbor(brazil);

	REQUIRE( brazil->num_neighbors() == 1 );
	REQUIRE( argentina->num_neighbors() == 1 );

}


TEST_CASE( "find neighbor", "[map][territory]" )
{

	std::shared_ptr<risk::map::territory> brazil(new risk::map::territory{"Brazil"});
	std::shared_ptr<risk::map::territory> argentina(new risk::map::territory{"Argentina"});
	brazil->add_neighbor(argentina);
	argentina->add_neighbor(brazil);
	
	REQUIRE_NOTHROW( brazil->find_neighbor("Argentina") );
	REQUIRE( brazil->find_neighbor("Argentina")->name() == "Argentina" );
	REQUIRE_THROWS_AS( brazil->find_neighbor("Australia"), std::out_of_range);

}

TEST_CASE( "add territory to continent", "[map][continent][territory]" )
{

	std::shared_ptr<risk::map::continent> south_america{new risk::map::continent{"South America"}};
	std::shared_ptr<risk::map::territory> brazil{new risk::map::territory{"Brazil"}};

	south_america->add_territory(brazil);

	REQUIRE( south_america->num_territories() == 1 );

}


TEST_CASE( "find a territory in a continent", "[map][continent][territory]" )
{

	std::shared_ptr<risk::map::continent> south_america{new risk::map::continent{"South America"}};
	std::shared_ptr<risk::map::territory> brazil{new risk::map::territory{"Brazil"}};
	south_america->add_territory(brazil);

	REQUIRE_NOTHROW( south_america->find_territory("Brazil") );
}

TEST_CASE( "don't find a territory in a continent", "[map][continent][territory]" )
{

	std::shared_ptr<risk::map::continent> south_america{new risk::map::continent{"South America"}};
	REQUIRE_THROWS_AS( south_america->find_territory("Brazil"), std::out_of_range );
}

TEST_CASE( "south america", "[map][continent][territory]" )
{
	const std::unique_ptr<risk::map::continent> & south_america = risk::map::south_america::instance();
	REQUIRE( south_america->num_territories() == 4 );
	REQUIRE_NOTHROW( south_america->find_territory("Brazil") );
	REQUIRE_NOTHROW( south_america->find_territory("Colombia/Venezuela") );
	REQUIRE_NOTHROW( south_america->find_territory("Peru/Bolívia/Chile") );
	REQUIRE_NOTHROW( south_america->find_territory("Argentina/Uruguai") );
	REQUIRE_THROWS_AS( south_america->find_territory("Cuba"), std::out_of_range );
	REQUIRE_NOTHROW( south_america->find_territory("Brazil")->find_neighbor("Colombia/Venezuela") );
	REQUIRE_THROWS_AS(  south_america->find_territory("Brazil")->find_neighbor("Cuba"), std::out_of_range );
}
