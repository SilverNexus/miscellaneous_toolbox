/*
 * Defines the file walk functions to be used to parade through the folder.
 * It is currently O(n^2) at best.
 *
 * Author: Daniel Hawkins
 */

#ifndef FOLDER_WALK_H
#define FOLDER_WALK_H

#include "image_match_table.h"
#include <list>

/*
 * Traverses the specified folder for images that match. Recurses if told to do so.
 *
 * @param path
 * The path to the folder of images being traversed.
 *
 * @param matches
 * The match table we are using.
 *
 * @param recurse
 * Boolean to indicate whether we traverse folders or not.
 */
void traverse_folder(char *path, list<match_table> &matches, bool recurse);

#endif
