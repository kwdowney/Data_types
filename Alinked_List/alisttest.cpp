#include "alistint.h"
#include "gtest/gtest.h"

class AListTest : public testing::Test {
protected:

	AListTest() {

	}

	virtual ~AListTest() {
		
	}

/* Populate a list with values
 */
	virtual void SetUp() {
		list1.insert(0,0);
		list1.insert(1,1);
		list1.insert(2,2);
		list1.insert(3,3);
		list1.insert(4,4);
	}

	virtual void TearDown() {

	}

	AListInt list1;
	AListInt list2;
};

TEST_F(AListTest, GetNominal) {
	for(int i = 0; i<list1.size(); i++) {
		EXPECT_EQ(list1.get(i), i);
	}
	EXPECT_EQ(list1.size(), 5);
}

TEST_F(AListTest, GetOffNominal) {
	list1.get(10);
	EXPECT_EQ(list1.size(), 5);
}

TEST_F(AListTest, InsertNominal) {
	list1.insert(0,10);
	for(int i = 1; i<list1.size(); i++) {
		EXPECT_EQ(list1.get(i), i+1);
	}
	list1.insert(2,4);
	EXPECT_EQ(list1.get(0), 10);
	EXPECT_EQ(list1.size(), 7);
}

TEST_F(AListTest, InsertOffNominal) {
	list1.insert(10, 10);
	for(int i = 0; i<list1.size(); i++) {
		EXPECT_EQ(list1.get(i), i);
	}
	EXPECT_EQ(list1.size(), 5);
}

TEST_F(AListTest, RemoveNominal) {
	list1.remove(4);
	for(int i = 0; i<list1.size(); i++) {
		EXPECT_EQ(list1.get(i), i);
	}
	EXPECT_EQ(list1.size(), 4);
}

TEST_F(AListTest, RemoveOffNominal) {
	list1.remove(10);
	for(int i = 0; i<list1.size(); i++) {
		EXPECT_EQ(list1.get(i), i);
	}
	EXPECT_EQ(list1.size(), 5);
}

TEST_F(AListTest, SetNominal) {
	list1.set(0, 10);
	for(int i = 1; i<list1.size(); i++) {
		EXPECT_EQ(list1.get(i), i);
	}
	EXPECT_EQ(list1.get(0), 10);
	EXPECT_EQ(list1.size(), 5);
}

TEST_F(AListTest, SetOffominal) {
	list1.set(10, 10);
	for(int i = 0; i<list1.size(); i++) {
		EXPECT_EQ(list1.get(i), i);
	}
	EXPECT_EQ(list1.size(), 5);
}