#include "Matrix.h"
#include "MyVector.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);
  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> m(5);
  TMatrix<int> m1(m);
  EXPECT_EQ(1, m == m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> m(5);
  TMatrix<int> m1(m);
  EXPECT_NE(&m, &m1);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> m(5);
  ASSERT_NO_THROW(m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> m(5);
  m[1][1] = 4;
  EXPECT_EQ(4, m[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> m(5);
  ASSERT_ANY_THROW(m[2][-2] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> m(5);
  ASSERT_ANY_THROW(m[2][1000000000000] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> m(5);
  ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> m(5), m2(5);
  m[0][0] = 1;
  m2[1][1] = 2;
  m = m2;
  TMatrix<int> m3(5);
  m3[1][1] = 2;
  EXPECT_EQ(1, m3 == m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> m(5), m2(7);
  m = m2;
  EXPECT_EQ(7, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> m(5), m2(7);
  m[0][0] = 1;
  m2[1][1] = 2;
  m = m2;
  TMatrix<int> m3(7);
  m3[1][1] = 2;
  EXPECT_EQ(1, m3 == m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> m(5), m2(5);
  EXPECT_EQ(1, m == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> m(5);
  EXPECT_EQ(1, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> m(5), m2(8);
  EXPECT_EQ(0, m == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> m(2), m2(2);
  TMatrix<int> m1(2);
  m[0][0] = 2;
  m2[0][0] = 3;
  m1 = m + m2;
  TMatrix<int> m4(2);
  m4[0][0] = 5;
  EXPECT_EQ(1, m4 == m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> m(3), m2(6);
  ASSERT_ANY_THROW(m + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> m(2), m2(2);
  TMatrix<int> m1(2);
  m[0][0] = 13;
  m2[0][0] = 3;
  m1 = (m - m2);
  TMatrix<int> m4(2);
  m4[0][0] = 10;
  EXPECT_EQ(1, m4 == m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> m(1), m2(2);
  ASSERT_ANY_THROW(m - m2);
}
TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);
  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> v(10), v2(v);
  EXPECT_EQ(1, v == v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(10), v2(v);
  EXPECT_NE(&v, &v2);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(5);
  EXPECT_EQ(5, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(5, 2);
  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(5);
  v[0] = 7;
  EXPECT_EQ(7, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  TVector<int> v(5);
  ASSERT_ANY_THROW(v[-1] = 1;);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v(5);
  ASSERT_ANY_THROW(v[7] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(5);
  ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v(5), v2(5);
  v = v2;
  EXPECT_EQ(1, v == v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
  TVector<int> v(5), v2(10);
  v = v2;
  EXPECT_EQ(10, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v(5), v2(10);
  for (int i = 0; i < 5; i++)
	v[i] = 1;
  for (int i = 0; i < 10; i++)
	v2[i] = 2;
  v = v2;
  EXPECT_EQ(1, v == v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> v(5), v2(5);
  for (int i = 0; i < 5; i++)
	v[i] = 1;
  for (int i = 0; i < 5; i++)
	v2[i] = 1;
  EXPECT_EQ(1, v2 == v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> v(5);
  for (int i = 0; i < 5; i++)
	v[i] = 1;
  EXPECT_EQ(1, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> v(4), v2(5);
  EXPECT_NE(1, v == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> v2(5);
  for (int i = 0; i < 5; i++)
	v2[i] = 4;
  v2 = v2 + 3;
  TVector<int> v(5);
  for (int i = 0; i < 5; i++)
	v[i] = 7;
  EXPECT_EQ(1, v == v2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> v2(5);
  for (int i = 0; i < 5; i++)
	v2[i] = 3;
  v2 = v2 - 2;
  TVector<int> v(5);
  for (int i = 0; i < 5; i++)
	v[i] = 1;
  EXPECT_EQ(1, v == v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  TVector<int> v2(5);
  for (int i = 0; i < 5; i++)
	v2[i] = 3;
  v2 = v2 * 2;
  TVector<int> v(5);
  for (int i = 0; i < 5; i++)
	v[i] = 6;
  EXPECT_EQ(1, v == v2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  TVector<int> v(2), v2(2);
  v[0] = 1; v[1] = 2;
  v2[0] = 2; v2[1] = 3;
  TVector<int> res_ex(2);
  res_ex[0] = 3; res_ex[1] = 5;
  TVector<int> res(2);
  res = v2 + v;
  EXPECT_EQ(1, res_ex == res);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  TVector<int> v(4), v2(5);
  ASSERT_ANY_THROW(v2 + v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  TVector<int> v(2), v2(2);
  v[0] = 1; v[1] = 2;
  v2[0] = 2; v2[1] = 3;
  TVector<int> res_ex(2);
  res_ex[0] = 1; res_ex[1] = 1;
  TVector<int> res(2);
  res = v2 - v;
  EXPECT_EQ(1, res_ex == res);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  TVector<int> v(4), v2(5);
  ASSERT_ANY_THROW(v2 - v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> v(2), v2(2);
  for (int i = 0; i < 2; i++)
  {
	v[i] = 2; v2[i] = 3;
  }
  int res_ex = v * v2;
  int res = 12;
  EXPECT_EQ(res, res_ex);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> v(4), v2(5);
  ASSERT_ANY_THROW(v2 * v);
}