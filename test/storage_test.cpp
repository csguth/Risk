#include <catch/catch.hpp>
#include "../src/utils/storage.h"
template<typename T>
using storage = typename risk::utils::storage<T>;

TEST_CASE( "empty storage" ) {
    storage<int> store;
    REQUIRE(store.empty());
    REQUIRE(store.size() == 0);
}

TEST_CASE( "storage::insert" ) {
    storage<int> store;
    store.insert(1);
    REQUIRE(store.size() == 1);
}

TEST_CASE( "storage::get" ) {
    storage<int> store;
    auto id = store.insert(1);
    auto element_it = store.get(id);
}

#include <limits>

TEST_CASE( "storage::remove" ) {
    storage<int> store;
    std::size_t id = store.insert(1);
    REQUIRE(store.remove(id));
    REQUIRE(store.empty());
    REQUIRE(store.size() == 0);
}

TEST_CASE( "storage get removed id" ) {
    storage<int> store;
    std::size_t id = store.insert(1);
    store.remove(id);
    REQUIRE(store.get(id) == store.end());
}

TEST_CASE( "storage try to remove removed id" ) {
    storage<int> store;
    std::size_t id = store.insert(1);
    store.remove(id);
    REQUIRE(!store.remove(id));
}

TEST_CASE( "storage try to remove non-inserted id" ) {
    storage<int> store;
    REQUIRE(!store.remove(std::numeric_limits<storage<int>::id_t>::max()));
}

TEST_CASE( "limited-size container" ) {
    risk::utils::limited_storage<int> store(3);
    REQUIRE(!store.full());
    auto u1 = store.insert(1);
    REQUIRE(store.get(u1) != store.end());
    REQUIRE(!store.full());
    auto u2 = store.insert(2);
    REQUIRE(store.get(u2) != store.end());
    REQUIRE(!store.full());
    auto u3 = store.insert(3);
    REQUIRE(store.get(u3) != store.end());
    REQUIRE(store.full());
    auto nullel = store.insert(4);
    REQUIRE(store.get(nullel) == store.end());
    REQUIRE(store.max_size() == 3);
    REQUIRE(store.full());

}

