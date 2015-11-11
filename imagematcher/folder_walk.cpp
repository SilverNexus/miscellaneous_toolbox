/**
 * Implements the folder walk operation to find matching images.
 *
 * Author: Daniel Hawkins
 */

#include "folder_walk.h"
#include <string>
#include <cstdio>

// Get configuration defines
#include "config.h"

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif

using namespace std;

void folder_walk(const char *path, list<match_table> &matches, bool recurse){
	DIR *dir = opendir(path);
	if (!dir){
		// Output an error message.
		return;
	}
	struct dirent *dir_contents;
	while (dir_contents = readdir(dir)){
		switch (dir_contents->d_type){
			case DT_REG:
				// This is a regular file.
				
				// TODO: Implement. This is dummy output.
				printf("%s/%s\n", path, dir_contents->d_name);
				break;
			case DT_DIR:
				// This is a directory
				if (recurse){
					string new_path = path;
					new_path.append("/").append(dir_contents->d_name);
					// Recurse is true because recurse is true if we get here, anyway.
					folder_walk(new_path.c_str(), matches, true);
				}
				break;
		}
	}
	
	// Clean up at the end.
	closedir(dir);
}
