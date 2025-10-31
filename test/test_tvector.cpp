#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(5);
	for (int i = 0; i < v.size(); i++) {
		v[i] = 5;
	}
	TDynamicVector<int> vtry(v);
	EXPECT_TRUE(v == vtry);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> some_vector(5);
	for (int j = 0; j < 5; j++) {
		some_vector[j] = 5;
	}

	TDynamicVector<int> another_vector(some_vector);

	for (int j = 0; j < 5; j++) {
		ASSERT_NE(&some_vector[j], &another_vector[j]);
	}
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(3);
	ASSERT_ANY_THROW(v[-1]=5);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(3);
	ASSERT_ANY_THROW(v[MAX_VECTOR_SIZE +1] = 5);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(5);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(5);
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(5);
	v1 = v2;
	EXPECT_EQ(v1.size(), 5);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(5);
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(5), v2(5);
	for (size_t i = 0; i < 3; ++i) { v1[i] = 5; v2[i] = 5; }
	EXPECT_TRUE(v1 == v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v1(5);
	EXPECT_TRUE(v1 == v1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(5);
	EXPECT_TRUE(v1 != v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(2);
	ASSERT_NO_THROW(v + 2);
	v = v + 2;
	for (size_t i = 0; i < v.size(); i++) {
		ASSERT_EQ(v[i], 2);
	}
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(2);
	ASSERT_NO_THROW(v - 2);
	v = v - 2;
	for (size_t i = 0; i < v.size(); i++) {
		ASSERT_EQ(v[i], -2);
	}
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v(2);
	for (size_t i = 0; i < v.size(); i++) {
		v[i]= 1;
	}
	ASSERT_NO_THROW(v * 2);
	v = v * 2;
	for (size_t i = 0; i < v.size(); i++) {
		ASSERT_EQ(v[i], 2);
	}
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(3);
	for (size_t i = 0; i < v1.size(); i++) {
		v1[i] = 1;
		v2[i] = 2;
	}
	ASSERT_NO_THROW(v1 + v2);
	v1 = v1 + v2;
	for (size_t i = 0; i < v1.size(); i++) {
		ASSERT_EQ(v1[i],3);
	}

}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(3);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(3);
	for (size_t i = 0; i < v1.size(); i++) {
		v1[i] = 1;
		v2[i] = 2;
	}
	ASSERT_NO_THROW(v1 - v2);
	v1 = v1 - v2;
	for (size_t i = 0; i < v1.size(); i++) {
		ASSERT_EQ(v1[i], -1);
	}

}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(3);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(3);
	for (size_t i = 0; i < v1.size(); i++) {
		v1[i] = 2;
		v2[i] = 3;
	}
	ASSERT_NO_THROW(v1 * v2);
	int res = v1 * v2;
	EXPECT_EQ(res, 18);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(3);
	ASSERT_ANY_THROW(v1 * v2);
}

