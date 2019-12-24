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
int TDataset::CL() {
	int count = 0;
	L1Item<TLine>*p = this->line.getHead();
	while (p) {
		p = p->pNext;
		count++;
	}
	return count;
}

int TDataset::CLC(string city) { // CL <city_name> -> output integer
	int count = 0, id = 0;
	bool flag = false;
	L1Item<TCity>* p = this->city.getHead();
	while (p) {
		if (p->data.name == city) {
			flag = true;
			id = p->data.id;
			break;
		}
		p = p->pNext;
	}
	
	if (flag) {
		L1Item<TLine>* _p = this->line.getHead();
		while (_p) {
			if (_p->data.city_id == id) {
				count++;
			}
			_p = _p->pNext;
		}
		return count;
	}
	return -1;
	
}

void TDataset::LSC(string city) { // LSC <city_name> -> integer array
	int id = 0;
	bool flag = false;

	L1Item<TCity>* p = this->city.getHead();
	while (p) {
		if (p->data.name == city) {
			id = p->data.id;
			flag = true;
			break;
		}
		p = p->pNext;
	}

	if (flag) {
		L1Item<TStation>* _p = this->station.getHead();
		while (_p) {
			if (_p->data.city_id == id) {
				 cout << ' ' << _p->data.id;
			}
			_p = _p->pNext;
		}
		
		cout << endl;
	}
	else cout  << endl;
}

void TDataset::LLC(string city) { // LLC <city_name> -> integer array
	int id = 0;
	bool flag = false;
	L1Item<TCity>* p = this->city.getHead();

	while (p) {
		if (p->data.name == city) {
			id = p->data.id;
			flag = true;
			break;
		}
		p = p->pNext;
	}

	if (flag) {

		L1Item<TLine>* _p = this->line.getHead();
		while (_p) {
			if (_p->data.city_id == id) {
				cout << ' ' << _p->data.id;
			}
			_p = _p->pNext;
		}
		cout << endl;
	}
	else cout << endl;
}

void TDataset::LSL(int line_id) { // LSL <line_id> -> integer array

		L1Item<TStation_Line> *p = this->sta_line.getHead();
		while (p) {
			if (p->data.line_id == line_id) {
				cout << ' ' << p->data.sta_id;
			}
			p = p->pNext;
		}
		cout << endl;
}

int TDataset::FC(string city) { // FC <city_name> -> integer
	bool flag = false;
	L1Item<TCity>* p = this->city.getHead();
	while (p) {
		if (p->data.name == city) {
			flag = true;
			break;
		}
		p = p->pNext;
	}
	if (!flag) return -1;
	return p->data.id;
}

int TDataset::FS(string station) { // FS <station_name> -> integer
	bool flag = false;
	L1Item<TStation>* p = this->station.getHead();
	while (p) {
		if (p->data.name == station) {
			flag = true;
			break;
		}
		p = p->pNext;
	}
	if (!flag) return -1;
	return p->data.id;
}

int TDataset::SLP(int station_id, int track_id) { // SLP <station_id> <track_id> -> integer
	int idx = 0, idxs = 0;
	string pos, linestr;
	bool flag = false;

	L1Item<TStation> *p = this->station.getHead();
	while (p) {
		if (p->data.id == station_id) {
			flag = true;
			break;
		}
		p = p->pNext;
	}

	if (!flag) return -1;
	
	pos = p->data.position;
	L1Item<TTrack> *_p = this->track.getHead();
	flag = false;
	while (_p) {
		if (_p->data.id == track_id) {
			flag = true;
			break;
		}
		_p = _p->pNext;
	}
	if (!flag) return -1;

	linestr = _p->data.linestring;

	idx = linestr.find(pos);

	if (idx == -1) return -1;

	for (int i = 0; i < idx; i++) {
		if (linestr[i] == ',') idxs++;
	}

	return idxs;

}

int TDataset::IS(string decrip) { // IS <csv_description>
	L1Item<TStation>* p = this->station.getHead();
	int maxid = p->data.id;
	while (p) {
		if (p->data.id > maxid) {
			maxid = p->data.id;
		}
		p = p->pNext;
	}

	string name = "";
	string pos = "";
	string text = "";
	stringstream s;
	s << decrip;

	getline(s, name, ',');
	getline(s, text, '(');
	getline(s, pos, ')');
	getline(s, text, ',');

	TStation temp;
	temp.id = maxid + 1;
	temp.name = name;
	temp.position = pos;



	this->station.push_back(temp);
	return temp.id;
}

int TDataset::RS(int station_id) { // RS <station_id>
	int idx = 0;
	bool flag = false;
	L1Item<TStation> * p = this->station.getHead();
	L1Item<TStation_Line> * p1 = this->sta_line.getHead();

	while (p) {
		if (p->data.id == station_id) {
			if (this->station.remove(idx) == 0) {
				flag = true;
				break;
			}
			
		}
		p = p->pNext;
		idx++;
	}
	idx = 0;
	bool flag1 = false;
	while (p1) {
		if (p1->data.sta_id == station_id) {
			if (this->sta_line.remove(idx) == 0) {
				flag1 = true;
				break;
			}
		}
		p1 = p1->pNext;
		idx++;
	}

	if (flag && flag1) return 0;

	return -1;

}

int TDataset::US(int id, string decrip) { // US <station_id> <csv_description>
	bool flag = false;
	L1Item<TStation> *p = this->station.getHead();
	while (p) {
		if (p->data.id == id) {
			flag = true;
			break;
		}
		p = p->pNext;
	}

	if (!flag) return -1;
	string name = "";
	string pos = "";
	string text = "";
	stringstream s;
	s << decrip;

	getline(s, name, ',');
	getline(s, text, '(');
	getline(s, pos, ')');
	getline(s, text, ',');

	p->data.name = name;
	p->data.position = pos;

	return 0;
}

void LoadData(void* &pData) {
	TDataset* p = new TDataset();
	ifstream infile;
	string text;


	///////////////////////////////////////////////////////////////
	 //Read file cities.csv
	infile.open("cities.csv");

	getline(infile, text, '\n');

	TCity city;
	while (infile.good()) {
		infile >> city.id;
		getline(infile, text, ',');
		getline(infile, city.name, ',');
		getline(infile, text, '\n');
		p->getCity().push_back(city);
	}

	p->getCity().removeLast();
	infile.close();

	// Read station_lines.csv

	infile.open("station_lines.csv");
	TStation_Line stat_line;

	getline(infile, text, '\n');

	while (infile.good()) {
		getline(infile, text, ',');
		infile >> stat_line.sta_id;
		getline(infile, text, ',');
		infile >> stat_line.line_id;
		getline(infile, text, '\n');

		p->getsta_line().push_back(stat_line);
	}
	p->getsta_line().removeLast();
	infile.close();

	////////////////////////////////////////////////////////////////////////
	//Read file lines.csv

	infile.open("lines.csv");
	TLine line;

	getline(infile, text, '\n');
	while (infile.good()) {
		
		infile >> line.id; // get id
		getline(infile, text,',');
		infile >> line.city_id;
		getline(infile, text, ',');
		getline(infile, line.name, ',');
		getline(infile, text, '\n');
	
		p->getLine().push_back(line);

	}
	p->getLine().removeLast();
	infile.close();


	//////////////////////////////////////////////////////////////////////////
	//// Read file statons.csv
	infile.open("stations.csv");
	TStation station;

	getline(infile, text, '\n');
	
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

		getline(infile, text, '\n');
		p->getStation().push_back(station);
	}
	p->getStation().removeLast();
	infile.close();
	

	////////////////////////////////////////////////////////////////////////////
	//// Read tracks.csv

	infile.open("tracks.csv");
	TTrack track;
	getline(infile, text, '\n');
	while (infile.good()) {
		infile >> track.id;
		getline(infile, text, '(');
		getline(infile, track.linestring, ')');
		getline(infile, text, '\n');
		p->getTrack().push_back(track);
	}
	p->getTrack().removeLast();
	infile.close();
	/*cout << p->getTrack().getSize();*/


	///////////////////////////////////////////////////////////////
	// Read track_lines.csv

	infile.open("track_lines.csv");
	TTrack_Line trac_line;
	int sect_id; //section id of file csv
	int track_id;

	getline(infile, text, '\n');
	while (infile.good()) {
		getline(infile, text, ',');
		infile >> sect_id;
		getline(infile, text, ',');
		infile >> track_id;
		getline(infile, text, '\n');
		p->gettra_line().push_back(trac_line);
	}
	p->gettra_line().removeLast();
	infile.close();

	////////////////////////////////////////////////////////////////////


	
	pData = p;
}




void ReleaseData(void* &pData) {
	pData = NULL;
}
