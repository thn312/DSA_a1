/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
struct TCity {
    // The structure to store city information
	int id;
	string name;
	string coords;
	int start_year;
	string url_name;
	string country;
	string country_state;

};

struct TLine {
    // The structure to store line information
	int id;
	int city_id;
	string name;
	string url_name;
	string color;
	int system_id;
	int transport_mode_id;

};

struct TTrack {
    // The structure to store track information
	int id;
	string geometry;
	int buildstart;
	int opening;
	int closure;
	int length;
	int city_id;

};

class TDataset {
    // This class can be a container that help you manage your tables

};

// Please add more or modify as needed

void LoadData(void* &);
void ReleaseData(void* &);

#endif //DSA191_A1_DBLIB_H
