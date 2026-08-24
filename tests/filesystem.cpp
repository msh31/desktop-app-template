#include <gtest/gtest.h>
#include <utils/utils.hpp>

namespace fs = std::filesystem;

TEST(filesystem, atomic_write) {
	fs::path test_file = fs::temp_directory_path() / "atomic.test";

	bool res = utils::atomic_write( test_file, "mr bombastic" );
	ASSERT_TRUE(res);

	std::ifstream in( test_file );
    ASSERT_TRUE( in.is_open( ) );

    std::stringstream ss;
    ss << in.rdbuf( );
    std::string contents = ss.str( );

	ASSERT_EQ( contents, "mr bombastic" );
}