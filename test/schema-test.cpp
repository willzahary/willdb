#include <gtest/gtest.h>
#include "../src/schema.h"

class SchemaTest : public testing::Test {
protected:
	Schema s1;
	Schema s2;
	Schema s3;

	SchemaTest() {
		s1 = Schema();

		s2 = Schema();
		s2.add_column("age", Value::INT32);

		s3 = Schema();
		s3.add_column("phone-number", Value::INT64);
		s3.add_column("age", Value::INT32);
	}
};

TEST_F(SchemaTest, SchemaSizes) {
	EXPECT_EQ(s1.get_column_count(), 0);
	EXPECT_EQ(s2.get_column_count(), 1);
	EXPECT_EQ(s3.get_column_count(), 2);
}

TEST_F(SchemaTest, SchemaIDs) {
	EXPECT_EQ(s2.get_column_id("age"), 0);

	EXPECT_EQ(s3.get_column_id("age"), 1);
	EXPECT_EQ(s3.get_column_id("phone-number"), 0);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}