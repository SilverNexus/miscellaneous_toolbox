/*
 * match.cpp
 *
 * Implements the code to match images based on content.
 *
 * Author: Daniel Hawkins
 */

bool does_match(const Mat &a, const Mat &b){
	// TODO: Do I need to set the size of the Matrix, or does OpenCV handle it for me?
	Mat out;
	int res;
	compare(a, b, out, res);
	return res == CMP_EQ;
}
