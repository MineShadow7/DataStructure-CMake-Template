// Copyright 2022 Marina Usova

#include <gtest.h>
#include "../lib_matrix/matrix.h"

TEST(TDynamicMatrix, can_create_matrix_with_positive_length) {
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix) {
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length) {
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix) {
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(10);
    EXPECT_EQ(matrix1, matrix2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(matrix1);
    EXPECT_NE(&matrix1, &matrix2);
}

TEST(TDynamicMatrix, can_get_size) {
    TDynamicMatrix<int> matrix(10);
    EXPECT_EQ(matrix.size(), 10);
}

TEST(TDynamicMatrix, can_set_and_get_element) {
    TDynamicMatrix<int> matrix(1);
    ASSERT_NO_THROW(std::cin >> matrix);
    ASSERT_NO_THROW(std::cout << matrix[0] << std::endl);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index) {
    TDynamicMatrix<int> matrix(1);
    ASSERT_ANY_THROW(matrix[-1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index) {
    TDynamicMatrix<int> m(1);
    ASSERT_ANY_THROW(m[10]);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself) {
    TDynamicMatrix<int> matrix(10);
    ASSERT_NO_THROW(matrix = matrix);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size) {
    TDynamicMatrix<int> matrix1(5);
    TDynamicMatrix<int> matrix2(5);
    ASSERT_NO_THROW(matrix1 = matrix2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(20);
    matrix1 = matrix2;
    EXPECT_EQ(matrix1.size(), 20);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(20);
    ASSERT_NO_THROW(matrix1 = matrix2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(10);
    ASSERT_NO_THROW(matrix1 == matrix2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true) {
    TDynamicMatrix<int> matrix(10);
    ASSERT_NO_THROW(matrix == matrix);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(20);
    EXPECT_TRUE(matrix1 != matrix2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(10);
    ASSERT_NO_THROW(matrix1 + matrix2);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(5);
    ASSERT_ANY_THROW(matrix1 + matrix2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(10);
    ASSERT_NO_THROW(matrix1 + matrix2);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size) {
    TDynamicMatrix<int> matrix1(10);
    TDynamicMatrix<int> matrix2(5);
    ASSERT_ANY_THROW(matrix1 + matrix2);
}
