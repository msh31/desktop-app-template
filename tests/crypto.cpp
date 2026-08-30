#include <gtest/gtest.h>
#include <utils/utils.hpp>

namespace fs = std::filesystem;

TEST( crypto, hash_file ) {
    fs::path test_file = fs::temp_directory_path( ) / "atomic.test";

    bool res = utils::atomic_write( test_file, "mr bombastic" );
    ASSERT_TRUE( res );

    auto hash = utils::hash_file( test_file );
    ASSERT_EQ( hash, "c3dd52caef0a5a7527ffaa46158132e6b6cc982bcdaee8e7af1de34273bdd336" );
}