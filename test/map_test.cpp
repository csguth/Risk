#include <catch/catch.hpp>
#include "../src/map/map.h"
#include "../src/map/continent.h"
#include "../src/map/territory.h"
#include <exception>

using risk::map::map;
using risk::map::continent;
using risk::map::territory;

TEST_CASE( "map name", "[map]" )
{
	map earth{"earth"};
	REQUIRE( earth.name() == "earth" );
}

TEST_CASE( "created map with 0 continents", "[map]" )
{
	map earth{"earth"};
	REQUIRE( earth.num_continents() == 0 );
}

TEST_CASE( "created continent without map", "[map][continent]" )
{
	continent america{"South America", 1};
	REQUIRE( !america.get_map() );
}

TEST_CASE( "continent name", "[map][continent]" )
{
	continent america{"South America", 1};
	risk::map::continent_has_name comparator("South America");
	REQUIRE( america.name() == "South America" );
	REQUIRE( comparator(america) );
} 

TEST_CASE( "created continent with 0 territories", "[map][continent]" )
{
	continent america{"South America", 1};
	REQUIRE( america.num_territories() == 0 );
} 

TEST_CASE( "add continent to map", "[map][continent]" )
{
	std::shared_ptr<map> earth{new map{"earth"}};
	std::shared_ptr<continent> america{new continent{"South America", 1}};
	
	REQUIRE_NOTHROW( earth->add_continent(america) );
	REQUIRE( america->get_map() == earth );
	REQUIRE( earth->num_continents() == 1 );
}

TEST_CASE( "continent bonus size", "[map][continent]" )
{
	std::shared_ptr<continent> america{new continent{"South America", 1}};
	REQUIRE( america->bonus() == 1 );

	std::shared_ptr<continent> america_do_norte{new continent{"North America", 2}};
	REQUIRE( america_do_norte->bonus() == 2 );
}

TEST_CASE( "find continent by name", "[map][continent]" )
{
	std::shared_ptr<map> earth{new map{"earth"}};
	std::shared_ptr<continent> america{new continent{"South America", 1}};
	
	earth->add_continent(america);
	REQUIRE_NOTHROW( earth->find_continent("South America") );
	REQUIRE( earth->find_continent("South America")->name() == "South America" );
} 

TEST_CASE( "doesn't find continent by name", "[map][continent]" )
{
	std::shared_ptr<map> earth{new map{"earth"}};
	std::shared_ptr<continent> america{new continent{"South America", 1}};
	
	earth->add_continent(america);
	REQUIRE_THROWS_AS( earth->find_continent("Africa"), std::out_of_range );
} 

TEST_CASE( "territory name", "[map][territory]" )
{
	territory brazil{"Lígia"};
	REQUIRE( brazil.name() == "Lígia" );
	REQUIRE_FALSE( brazil.name() == "Brazil" );
}

TEST_CASE( "territory has empty neighborhood", "[map][territory]" )
{

	territory brazil{"Brazil"};
	REQUIRE( brazil.num_neighbors() == 0 );

}

TEST_CASE( "add argentina as neighbor of brazil", "[map][territory]" )
{

	std::shared_ptr<territory> brazil(new territory{"Brazil"});
	std::shared_ptr<territory> argentina(new territory{"Argentina"});

	brazil->add_neighbor(argentina);

	REQUIRE( brazil->num_neighbors() == 1 );
	REQUIRE( argentina->num_neighbors() == 1 );
	REQUIRE_NOTHROW( brazil->find_neighbor("Argentina") );
	REQUIRE_NOTHROW( argentina->find_neighbor("Brazil") );

}


TEST_CASE( "find neighbor", "[map][territory]" )
{

	std::shared_ptr<territory> brazil(new territory{"Brazil"});
	std::shared_ptr<territory> argentina(new territory{"Argentina"});
	brazil->add_neighbor(argentina);
	
	REQUIRE_NOTHROW( brazil->find_neighbor("Argentina") );
	REQUIRE( brazil->find_neighbor("Argentina")->name() == "Argentina" );
	REQUIRE_THROWS_AS( brazil->find_neighbor("Australia"), std::out_of_range);

}

TEST_CASE( "add territory to continent", "[map][continent][territory]" )
{

	std::shared_ptr<continent> south_america{new continent{"South America", 1}};
	std::shared_ptr<territory> brazil{new territory{"Brazil"}};

	south_america->add_territory(brazil);

	REQUIRE( south_america->num_territories() == 1 );
	REQUIRE_NOTHROW( south_america->find_territory("Brazil") );
	REQUIRE( brazil->get_continent() == south_america );
}


TEST_CASE( "find a territory in a continent", "[map][continent][territory]" )
{

	std::shared_ptr<continent> south_america{new continent{"South America", 1}};
	std::shared_ptr<territory> brazil{new territory{"Brazil"}};
	south_america->add_territory(brazil);

	REQUIRE_NOTHROW( south_america->find_territory("Brazil") );
}

TEST_CASE( "don't find a territory in a continent", "[map][continent][territory]" )
{
	std::shared_ptr<continent> south_america{new continent{"South America", 1}};
	REQUIRE_THROWS_AS( south_america->find_territory("Brazil"), std::out_of_range );
}

TEST_CASE( "world map test", "[map]")
{
	std::shared_ptr<continent> america_do_sul{new continent{"América do Sul", 1}};

	std::shared_ptr<territory> brasil{new territory{"Brasil"}};
	std::shared_ptr<territory> peru{new territory{"Peru/Bolívia/Chile"}};
	std::shared_ptr<territory> colombia{new territory{"Colômbia/Venezuela"}};
	std::shared_ptr<territory> argentina{new territory{"Argentina/Uruguai"}};

	brasil->add_neighbor(colombia);
	brasil->add_neighbor(peru);
	brasil->add_neighbor(argentina);
	//brasil->add_neighbor(argelia);

	peru->add_neighbor(colombia);
	peru->add_neighbor(argentina);

	america_do_sul->add_territory(brasil);
	america_do_sul->add_territory(peru);
	america_do_sul->add_territory(colombia);
	america_do_sul->add_territory(argentina);

	std::shared_ptr<continent> america_do_norte{new continent{"América do Norte", 1}};

	std::shared_ptr<territory> mexico{new territory{"México"}};
	std::shared_ptr<territory> nova_york{new territory{"Nova York"}};
	std::shared_ptr<territory> california{new territory{"Califórnia"}};
	std::shared_ptr<territory> vancouver{new territory{"Vancouver"}};
	std::shared_ptr<territory> ottawa{new territory{"Ottawa"}};
	std::shared_ptr<territory> labrador{new territory{"Labrador"}};
	std::shared_ptr<territory> alaska{new territory{"Alaska"}};
	std::shared_ptr<territory> mackenzie{new territory{"Mackenzie"}};
	std::shared_ptr<territory> groenlandia{new territory{"Groenlandia"}};

	mexico->add_neighbor(colombia);
	mexico->add_neighbor(california);
	mexico->add_neighbor(nova_york);

	nova_york->add_neighbor(california);
	nova_york->add_neighbor(ottawa);
	nova_york->add_neighbor(labrador);

	california->add_neighbor(vancouver);
	california->add_neighbor(ottawa);

	vancouver->add_neighbor(alaska);
	vancouver->add_neighbor(mackenzie);
	vancouver->add_neighbor(ottawa);

	ottawa->add_neighbor(mackenzie);
	ottawa->add_neighbor(labrador);

	labrador->add_neighbor(groenlandia);

	//alaska->add_neighbor(vladivostok);

	mackenzie->add_neighbor(groenlandia);

	//groenlandia->add_neighbor(islandia);

	america_do_norte->add_territory(mexico);
	america_do_norte->add_territory(nova_york);
	america_do_norte->add_territory(california);
	america_do_norte->add_territory(vancouver);
	america_do_norte->add_territory(ottawa);
	america_do_norte->add_territory(labrador);
	america_do_norte->add_territory(alaska);
	america_do_norte->add_territory(mackenzie);
	america_do_norte->add_territory(groenlandia);



	std::shared_ptr<continent> europa{new continent{"Europa", 1}};

	std::shared_ptr<territory> islandia{new territory{"Islândia"}};
	std::shared_ptr<territory> inglaterra{new territory{"Inglaterra"}};
	std::shared_ptr<territory> suecia{new territory{"Suécia"}};
	std::shared_ptr<territory> portugal{new territory{"Portugal/Espanha/França"}};
	std::shared_ptr<territory> alemanha{new territory{"Alemanha"}};
	std::shared_ptr<territory> polonia{new territory{"Polônia/Iugoslávia"}};
	std::shared_ptr<territory> moscou{new territory{"Moscou"}};

	islandia->add_neighbor(groenlandia);
	islandia->add_neighbor(inglaterra);
	islandia->add_neighbor(suecia);

	inglaterra->add_neighbor(portugal);
	inglaterra->add_neighbor(suecia);
	inglaterra->add_neighbor(alemanha);

	suecia->add_neighbor(moscou);

	portugal->add_neighbor(alemanha);
	portugal->add_neighbor(polonia);
	//portugal->add_neighbor(argelia);

	alemanha->add_neighbor(polonia);

	polonia->add_neighbor(moscou);

	// moscou->add_neighbor(omsk);
	// moscou->add_neighbor(aral);
	// moscou->add_neighbor(oriente_medio);

	europa->add_territory(islandia);
	europa->add_territory(inglaterra);
	europa->add_territory(suecia);
	europa->add_territory(portugal);
	europa->add_territory(alemanha);
	europa->add_territory(polonia);
	europa->add_territory(moscou);

	std::shared_ptr<continent> asia{new continent{"Ásia", 1}};

	std::shared_ptr<territory> omsk{new territory{"Omsk"}};
	std::shared_ptr<territory> aral{new territory{"Aral"}};
	std::shared_ptr<territory> oriente_medio{new territory{"Oriente Médio"}};
	std::shared_ptr<territory> dudinka{new territory{"Dudinka"}};
	std::shared_ptr<territory> siberia{new territory{"Sibéria"}};
	std::shared_ptr<territory> vladivostok{new territory{"vladivostok"}};
	std::shared_ptr<territory> tchita{new territory{"Tchita"}};
	std::shared_ptr<territory> mongolia{new territory{"Mongólia"}};
	std::shared_ptr<territory> china{new territory{"China"}};
	std::shared_ptr<territory> japao{new territory{"Japão"}};
	std::shared_ptr<territory> india{new territory{"Índia"}};
	std::shared_ptr<territory> vietna{new territory{"Vietnã"}};

	omsk->add_neighbor(moscou);
	omsk->add_neighbor(dudinka);
	omsk->add_neighbor(aral);
	omsk->add_neighbor(mongolia);
	omsk->add_neighbor(china);

	aral->add_neighbor(moscou);
	aral->add_neighbor(china);
	aral->add_neighbor(india);
	aral->add_neighbor(oriente_medio);

	oriente_medio->add_neighbor(polonia);
	oriente_medio->add_neighbor(moscou);
	oriente_medio->add_neighbor(india);
	//oriente_medio->add_neighbor(egito);

	dudinka->add_neighbor(siberia);
	dudinka->add_neighbor(tchita);
	dudinka->add_neighbor(mongolia);

	siberia->add_neighbor(tchita);
	siberia->add_neighbor(vladivostok);

	vladivostok->add_neighbor(alaska);
	vladivostok->add_neighbor(tchita);
	vladivostok->add_neighbor(japao);
	vladivostok->add_neighbor(china);

	tchita->add_neighbor(mongolia);
	tchita->add_neighbor(china);

	mongolia->add_neighbor(china);

	china->add_neighbor(japao);
	china->add_neighbor(india);
	china->add_neighbor(vietna);
	
	india->add_neighbor(vietna);
	//india->add_neighbor(sumatra);

	// vietna->add_neighbor(borneo);

	asia->add_territory(omsk);
	asia->add_territory(aral);
	asia->add_territory(oriente_medio);
	asia->add_territory(dudinka);
	asia->add_territory(siberia);
	asia->add_territory(vladivostok);
	asia->add_territory(tchita);
	asia->add_territory(mongolia);
	asia->add_territory(china);
	asia->add_territory(japao);
	asia->add_territory(india);
	asia->add_territory(vietna);

	std::shared_ptr<continent> oceania{new continent{"Oceania", 1}};

	std::shared_ptr<territory> sumatra{new territory{"Sumatra"}};
	std::shared_ptr<territory> borneo{new territory{"Borneo"}};
	std::shared_ptr<territory> nova_guine{new territory{"Nova Guiné"}};
	std::shared_ptr<territory> australia{new territory{"Austrália"}};

	sumatra->add_neighbor(india);
	sumatra->add_neighbor(australia);

	borneo->add_neighbor(vietna);
	borneo->add_neighbor(nova_guine);
	borneo->add_neighbor(australia);

	nova_guine->add_neighbor(australia);

	oceania->add_territory(sumatra);
	oceania->add_territory(borneo);
	oceania->add_territory(nova_guine);
	oceania->add_territory(australia);

	std::shared_ptr<continent> africa{new continent{"África", 1}};

	std::shared_ptr<territory> argelia{new territory{"Argélia/Nigéria"}};
	std::shared_ptr<territory> egito{new territory{"Egito"}};
	std::shared_ptr<territory> sudao{new territory{"Sudão"}};
	std::shared_ptr<territory> congo{new territory{"Congo"}};
	std::shared_ptr<territory> africa_do_sul{new territory{"África do Sul"}};
	std::shared_ptr<territory> madagascar{new territory{"Madagascar"}};

	argelia->add_neighbor(brasil);
	argelia->add_neighbor(egito);
	argelia->add_neighbor(portugal);
	argelia->add_neighbor(sudao);
	argelia->add_neighbor(congo);

	egito->add_neighbor(portugal);
	egito->add_neighbor(polonia);
	egito->add_neighbor(oriente_medio);
	egito->add_neighbor(sudao);

	sudao->add_neighbor(congo);
	sudao->add_neighbor(madagascar);
	sudao->add_neighbor(africa_do_sul);

	congo->add_neighbor(africa_do_sul);

	africa_do_sul->add_neighbor(madagascar);

	africa->add_territory(argelia);
	africa->add_territory(egito);
	africa->add_territory(sudao);
	africa->add_territory(congo);
	africa->add_territory(africa_do_sul);
	africa->add_territory(madagascar);


	std::shared_ptr<map> terra{new map{"Terra"}};

	terra->add_continent(america_do_norte);
	terra->add_continent(america_do_sul);
	terra->add_continent(europa);
	terra->add_continent(asia);
	terra->add_continent(oceania);
	terra->add_continent(africa);

	REQUIRE( terra->num_continents() == 6 );

	REQUIRE( america_do_norte->num_territories() == 9 );
	REQUIRE( america_do_sul->num_territories() == 4 );
	REQUIRE( europa->num_territories() == 7 );
	REQUIRE( asia->num_territories() == 12 );
	REQUIRE( oceania->num_territories() == 4 );
	REQUIRE( africa->num_territories() == 6 );

	REQUIRE_NOTHROW( vladivostok->find_neighbor(alaska->name()) );
	REQUIRE_NOTHROW( brasil->find_neighbor(argelia->name()) );
	REQUIRE_NOTHROW( japao->find_neighbor(vladivostok->name()) );
	REQUIRE_NOTHROW( japao->find_neighbor(china->name()) );
	REQUIRE_NOTHROW( groenlandia->find_neighbor(islandia->name()) );
	REQUIRE_NOTHROW( sumatra->find_neighbor(india->name()) );
	REQUIRE_NOTHROW( borneo->find_neighbor(vietna->name()) );
	REQUIRE_NOTHROW( portugal->find_neighbor(argelia->name()) );
	REQUIRE_NOTHROW( portugal->find_neighbor(egito->name()) );
	REQUIRE_NOTHROW( polonia->find_neighbor(egito->name()) );
	REQUIRE_THROWS_AS( brasil->find_neighbor(mexico->name()), std::out_of_range );




}
