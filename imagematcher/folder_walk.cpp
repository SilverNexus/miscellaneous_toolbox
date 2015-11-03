/**
 * Implements the folder walk operation to find matching images.
 *
 * Author: Daniel Hawkins
 */

#include "folder_walk.h"

// Get configuration defines
#include "config.h"

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif

void folder_walk(char *path, list<match_table> &matches, bool recurse){
	// TODO: Implement
}