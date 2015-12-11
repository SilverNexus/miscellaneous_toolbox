/**
 * image_match_table.cpp
 *
 * Implements the class methods for storing a list of
 * matches associated with a single image.
 *
 * Author: Daniel Hawkins
 */

#include "image_match_table.h"

using namespace std;
using namespace cv;

/* Constructors */
match_table::match_table(Mat *img, string path){
	path_to_image = path;
	*img_to_match_on = img->clone();
	head = 0;
}

match_table::match_table(Mat *img, table_element *lst, string path){
	path_to_image = path;
	// Deep copy of the list
	table_element *tmp = lst;
	while (tmp){
		add_match(tmp->img, tmp->path_to_img);
		tmp = tmp->next;
	}
	*img_to_match_on = img->clone();
}

match_table::~match_table(){
	// Clean up matches for the image
	table_element *tmp = head;
	table_element *tmp2 = tmp;
	while (tmp){
		tmp2 = tmp->next;
		tmp->img->release();
		delete tmp;
		tmp = tmp2;
	}
	img_to_match_on->release();
}

void match_table::add_match(Mat *img_match, string path){
	table_element *new_el = new table_element();
	*(new_el->img) = img_match->clone();
	new_el->path_to_img = path;
	new_el->next = head;
	head = new_el;
}

Mat *match_table::remove_match(string filename){
	table_element *tmp = head, *prev = head;
	while (tmp){
		if (tmp->path_to_img == filename){
			// If the first element of the list, we adjust head
			if (tmp == prev){
				head = head->next;
			}
			// Otherwise we reroute the list to bypass
			else{
				prev->next = tmp->next;
			}
			Mat *res = tmp->img;
			// Prevent memory leaks
			delete tmp;
			return res;
		}			
	}
	return 0;
}
