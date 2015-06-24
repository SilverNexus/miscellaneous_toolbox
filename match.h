/*
 * match.h
 *
 * Contains declarations of functions that perform image comparison.
 *
 * Author: Daniel Hawkins
 */

// TODO: Ensure this is the right include.
#include <opencv.h>

/**
 * Compares the matrices a and b for equality.
 *
 * @param a One matrix to compare
 * @param b A second matrix to compare
 *
 * @retval true The matrices are identical.
 * @retval false The matrices are not identical.
 */
bool does_match(const Mat &a, const Mat &b);

