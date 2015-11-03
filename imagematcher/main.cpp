/*
 * main.cpp
 *
 * Contains the entry point for the duplicate image finder.
 *
 * Author: Daniel Hawkins
 */

#include "folder_walk.h"

int main(int argc, char **argv){
	// Parse the argument for folder to check.
	if (argc != 2)
		return 1;
	// Okay, initialize the match table
	// Each element is for one file, so we need a list of these.
	list<match_table> matches;
	// Images are at argv[1].
	traverse_folder(argv[1], &matches, false);

	// TODO: Implement any and everything else
	return 0;
}