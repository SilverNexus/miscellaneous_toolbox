/*
 * image_match_table.h
 *
 * Defines a class for storing a list of
 * matches associated with a single image
 *
 * Author: Daniel Hawkins
 */

#ifndef MATCHTABLE_H
#define MATCHTABLE_H

// TODO: Make sure this is the right include
#include <opencv.h>

#include <string>

using namespace std;

struct table_element{
	Mat *img;
	string path_to_img;
	table_element *next;
}

class match_table {
	private:
		Mat *img_to_match_on;
		string path_to_image;
		table_element *head;
	public:
		/**
		 * Constructor to initialize an empty match list for image img
		 * head is initialized to zero, or an empty list.
		 *
		 * @param img The image to associate the list with
		 * @param path The file location of the image
		 */
		match_table(Mat *img, string path);

		/**
		 * Constructor to initialize a given match list for image img
		 * Makes a deep copy of the list at hand, so the original may
		 * be dealt with accordingly.
		 *
		 * The assumption is made that you will use the above constructor
		 * if there is no list, but this one will still work with lst = 0.
		 *
		 * @param img The image to associate the list with
		 * @param lst The list of matches to assign to the image
		 * @param path The file location of the 
		 */
		match_table(Mat *img, table_element *lst, string path);

		/**
		 * Destructor to clean up dynamically allocated image and
		 * match list information.
		 */
		~match_table();

		/**
		 * Method to add an element to the list of matches
		 * Performs a deep copy of the image passed so the initial
		 * image may be dealt with as otherwise needed.
		 *
		 * @param img_match The image to add to the list of matches
		 * @param path The path to the image at img_match on disk.
		 */
		void add_match(Mat *img_match, string path);

		/**
		 * Method to remove an element to the list of matches
		 * Returns the removed image data for further operation
		 *
		 * @param filename the file path of the image to remove
		 *
		 * @return Pointer to the image removed from the list, or
		 * 0 if the requested image was not found.
		 */
		Mat *remove_match(string filename);
};
