/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */


void LoadData(void* &pData) {
	TDataset* p = new TDataset();
	ifstream infile;
	string text;

	 //Read file cities.csv
	
	infile.open("cities.csv");
	getline(infile, text);
	TCity city;
	while (infile.good()) {
		
		infile >> city.id;
		getline(infile, text, ',');
		getline(infile, city.name, ',');
		getline(infile, text);
		p->getCity().push_back(city);
	}
	infile.close();
	
	////////////////////////////////////////////////////////////////////////
	//Read file lines.csv

	infile.open("lines.csv");
	getline(infile, text);
	TLine line;
	while (infile.good()) {
		
		infile >> line.id; // get id
		getline(infile, text,',');
		infile >> line.city_id;
		getline(infile, text, ',');
		getline(infile, line.name, ',');
		getline(infile, text);

		p->getLine().push_back(line);

	}
	infile.close();


	//////////////////////////////////////////////////////////////////////////
	//// Read file statons.csv
	infile.open("stations.csv");
	getline(infile, text);
	TStation station;
	while (infile.good()) {
		
		infile >> station.id;
		getline(infile, text, ',');
		getline(infile, station.name, ',');
		getline(infile, text, '(');
		getline(infile, station.position, ')');
		
		//pass buildstart opening...
		getline(infile, text, ',');
		getline(infile, text, ',');
		getline(infile, text, ',');
		getline(infile, text, ',');
		////

		infile >> station.city_id;
		getline(infile, text);
	
		p->getStation().push_back(station);
	}
	infile.close();
	

	////////////////////////////////////////////////////////////////////////////
	//// Read tracks.csv

	infile.open("tracks.csv");
	TTrack track;
	getline(infile, text);
	while (infile.good()) {
		infile >> track.id;
		getline(infile, text, '(');
		getline(infile, track.linestring, ')');
		getline(infile, text);
		p->getTrack().push_back(track);
	}
	infile.close();
	/*cout << p->getTrack().getSize();*/

	///////////////////////////////////////////////////////////////
	// Read station_lines.csv

	infile.open("station_lines.csv");
	TStation_Line stat_line;
	
	
	getline(infile, text);
	while (infile.good()) {
		getline(infile, text, ',');
		infile >> stat_line.sta_id;
		getline(infile, text, ',');
		infile >> stat_line.line_id;
		getline(infile, text);
		p->getsta_line().push_back(stat_line);
	}
	infile.close();
	///////////////////////////////////////////////////////////////
	// Read track_lines.csv

	infile.open("track_lines.csv");
	TTrack_Line trac_line;
	int sect_id; //section id of file csv
	int track_id;

	getline(infile, text);
	while (infile.good()) {
		getline(infile, text, ',');
		infile >> sect_id;
		getline(infile, text, ',');
		infile >> track_id;
		getline(infile, text);
		p->gettra_line().push_back(trac_line);
	}
	infile.close();

	////////////////////////////////////////////////////////////////////


	
	pData = p;
}




void ReleaseData(void* &pData) {
	pData = NULL;
}
