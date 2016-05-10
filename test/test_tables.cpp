#include <gtest.h>
#include "hash.h"
#include "sort.h"
//#include <polinom.h>

TEST(hash_table, can_create_table)
{
	ASSERT_NO_THROW(hashtable table);
}

TEST(hash_table, can_add)
{
	hashtable table;
	ASSERT_NO_THROW(table.insert("a", 1));
}

TEST(hash_table, can_search)
{
	hashtable table;
	table.insert("d", 4);
	table.insert("a", 1);
	table.insert("b", 2);
	EXPECT_EQ(table.search("b")->getkey(), "b");
}

TEST(hash_table, can_delete)
{
	hashtable table;
	table.insert("d", 4);
	table.insert("a", 1);
	table.insert("b", 2);
	ASSERT_NO_THROW(table.del("b"));
}

TEST(sort_table, can_create_table)
{
	ASSERT_NO_THROW(sorttable table);
}

TEST(sort_table, can_add)
{
	sorttable table;
	ASSERT_NO_THROW(table.insert("a", 1));
}

TEST(sort_table, can_search)
{
	sorttable table;
	table.insert("d", 4);
	table.insert("a", 1);
	table.insert("b", 2);
	EXPECT_EQ(table.table[table.search("b")].k,"b");
}

TEST(sort_table, can_delete)
{
	sorttable table;
	table.insert("d", 4);
	table.insert("a", 1);
	table.insert("b", 2);
	ASSERT_NO_THROW(table.del("b"));
}