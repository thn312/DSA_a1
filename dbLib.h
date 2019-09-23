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
	TCity() {
		id = 0;
		name = "";
	}
	TCity(string name) {
		id = 0;
		this->name = name;
	}
	bool operator== (TCity a) {
		return this->name == a.name;
	}
	bool operator!= (TCity a) {
	return this->name != a.name;
	}
};

struct TLine {
	// The structure to store line information
	int id, city_id;
	string name;

	TLine() {
		id = 0;
		name = "";
		city_id = 0;
	}
};

struct TTrack {
	// The structure to store track information
	int id;
	string linestring;
	TTrack() {
		id = 0;
		linestring = "";
	}
};

struct TStation {
	int id;
	string name;
	int city_id;
	string position;
	TStation() {
		id = 0;
		name = "";
		city_id = 0;
		position = "";
	}
	TStation(string name) {
		id = 0;
		this->name = name;
		city_id = 0;
		position = "";
	}
	bool operator==(TStation name) {
		return this->name == name.name;
	}
	bool operator!=(TStation name) {
		return this->name != name.name;
	}
};

struct TStation_Line {
	int sta_id; //station id of file csv
	int line_id;
	
	TStation_Line() {
		sta_id = 0;
		line_id = 0;
		
	}
	TStation_Line(int id) {
		this->line_id = id;
	
	}
	bool operator==(TStation_Line id) {
		return this->sta_id == id.sta_id;
	}
	bool operator!=(TStation_Line id) {
		return this->sta_id != id.sta_id;
	}
};

struct TTrack_Line {
	int id; // section id

	TTrack_Line() {
		id = 0;
	}
	TTrack_Line(int id) {
		this->id = id;
	}
	bool operator==(TTrack_Line id) {
		return this->id == id.id;
	}
	bool operator!=(TTrack_Line id) {
		return this->id != id.id;
	}
};


class TDataset {
	// This class can be a container that help you manage your tables
private:
	L1List<TCity> city;
	L1List<TLine> line;
	L1List<TTrack> track;
	L1List<TStation> station;
	L1List<TStation_Line> sta_line;
	L1List<TTrack_Line> tra_line;
	
public:
	TDataset() {
		city = L1List<TCity>();
		line = L1List<TLine>();
		station = L1List<TStation>();
		track = L1List<TTrack>();
		sta_line = L1List<TStation_Line>();
		tra_line = L1List<TTrack_Line>();
		
	}
	L1List<TCity>& getCity() {
		return this->city;
	}
	L1List<TLine>& getLine() {
		return this->line;
	}
	L1List<TTrack>& getTrack() {
		return this->track;
	}
	L1List<TStation>& getStation() {
		return this->station;
	}
	L1List<TStation_Line>& getsta_line() {
		return this->sta_line;
	}
	L1List<TTrack_Line>& gettra_line() {
		return this->tra_line;
	}

	//////////////////////////////////////////////////////////////////////////////////////

	int  CL() {
		int count = 0;
		L1Item<TLine>*p=this->line.getHead();
		p = p->pNext;
		while (p && p->data.id != NULL) {
			p = p->pNext;
			count++;
		}
		return count;
	}

	///////////////////////////////////////////////////////////////////////////////////////

	void  CLC(string city) { // CL <city_name> -> output integer
		int count = 0;
		L1Item<TCity>* p = this->city.getHead();
		while (p && p->data.name != city) {
			p = p->pNext;
		}
		if (p == NULL) {
			cout << "-1" << endl;
			return;
		}
		
		L1Item<TLine>* _p = this->line.getHead();
		while (_p) {
			if (_p->data.city_id == p->data.id) {
				count++;
			}
			_p = _p->pNext;
		}
		
		cout << count << endl;
	}

	////////////////////////////////////////////////////////////////////////////////////

	void LSC(string city) { // LSC <city_name> -> integer array
		int count = 0;
		int id = 0;

		L1Item<TCity>* p = this->city.getHead();
		while (p && p->data.name != city) {
			p = p->pNext;
		}

		if (p != NULL) {
			id = p->data.id;
			L1Item<TStation>* _p = this->station.getHead();
			while (_p) {
				if (_p->data.city_id == id) {
					count++;
					if (count != 0) cout << ' ' << _p->data.id;
				}
				_p = _p->pNext;
			}
			if (count == 0) cout << " ";
			cout << endl;
		}
		else cout << " -1" << endl;
		
	}
	////////////////////////////////////////////////////////////////////////////////

	void LLC(string city) { // LLC <city_name> -> integer array
		int count = 0;
		int id = 0;
		L1Item<TCity>* p = this->city.getHead();

		while (p && p->data.name != city) {
			p = p->pNext;
		}

		if (p != NULL) {
			id = p->data.id;

			L1Item<TLine>* _p = this->line.getHead();
			while (_p) {
				if (_p->data.city_id == id) {
					count++;
					if (count != 0) cout << ' ' << _p->data.id;
				}
				_p = _p->pNext;
			}
			if (count == 0) cout << " ";
			cout << endl;
		}
		else cout << " -1" <<endl;
	}
	///////////////////////////////////////////////////////////////////////////

	void LSL(int line_id) { // LSL <line_id> -> integer array

		int count = 0;
		L1Item<TLine> *pline = this->line.getHead();
		while (pline && pline->data.id != line_id) {
			pline = pline->pNext;
		}
		if (pline != NULL) {
			L1Item<TStation_Line> *p = this->sta_line.getHead();
			while (p) {
				if (p->data.line_id == line_id) {
					count++;
					if (count != 0) cout << ' ' << p->data.sta_id;
				}
				p = p->pNext;
			}
			if (count == 0) cout << " ";
			cout << endl;
		}
		else cout << " error" << endl;
	}

	////////////////////////////////////////////////////////////////////////////////

	int  FC(string city) { // FC <city_name> -> integer

		L1Item<TCity>* p = this->city.getHead();
		while (p && p->data.name != city) {
			p = p->pNext;
		}

		if (p == NULL) return -1;

		return p->data.id;

	}

	///////////////////////////////////////////////////////////////////////////////////

	int  FS(string station) { // FS <station_name> -> integer
		L1Item<TStation>* p = this->station.getHead();
		while (p && p->data.name != station) {
			p = p->pNext;
		}
		if (p == NULL) return -1;

		return p->data.id;
	}

	////////////////////////////////////////////////////////////////////////

	int  SLP(int station_id, int track_id) { // SLP <station_id> <track_id> -> integer
		int idx = 0, idxs = 0;
		string pos, linestr;

		L1Item<TStation> *p = this->station.getHead();
		while (p && p->data.id != station_id) {
			p = p->pNext;
		}
		if (p == NULL) return -1;
		pos = p->data.position;

		L1Item<TTrack> *_p = this->track.getHead();
		while (_p && _p->data.id != track_id) {
			_p = _p->pNext;
		}
		if (_p == NULL)return -1;
		linestr = _p->data.linestring;

		idx = linestr.find(pos);

		if (idx == -1) return -1;

		for (int i = 0; i < idx; i++) {
			if (linestr[i] == ',') idxs++;
		}

		return idxs;

	}

/////////////////////////////////////////////////////////////////////////////////

	int  IS(string decrip) { // IS <csv_description>
		L1Item<TStation>*p = this->station.getHead();
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


		this->station.insertHead(temp);

		return temp.id;
	}
////////////////////////////////////////////////////////////////////////////

	int  RS(int station_id) { // RS <station_id>
		int idx = 0;
		L1Item<TStation> * p = this->station.getHead();
		L1Item<TStation_Line> * p1 = this->sta_line.getHead();
		while (p && p->data.id != station_id) {
			p = p->pNext;
			idx++;
		}

		if (p == NULL) return -1;
		else {
			this->station.remove(idx);
			idx = 0;
			while (p1 && p1->data.sta_id != station_id) {
				p1 = p1->pNext;
				idx++;
			}
			this->sta_line.remove(idx);
		
		}
		return 0;

	}

/////////////////////////////////////////////////////////////////////////////////////

	int  US(int id, string decrip) { // US <station_id> <csv_description>
		L1Item<TStation> *p = this->station.getHead();
		while (p && p->data.id != id) {
			p = p->pNext;
		}

		if (p == NULL) return -1;
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
	

		/*cout << p->data.name << endl;*/
		//cout << p->data.position << endl;
		return 0;
	}

////////////////////////////////////////////////////////////////////////////////////
	int  ISL(int station_id, int line_id, int p_i) { // ISL <station_id> <line_id>
		int idx = p_i;
		

		L1Item<TLine> *pcheck = this->line.getHead();
		while (pcheck && pcheck->data.id != line_id) {
			pcheck = pcheck->pNext;
		}
		
		if(pcheck!= NULL) {
		
			L1Item<TStation_Line> *p1 = this->sta_line.getHead();
			
			while (p1 && p1->data.sta_id != station_id) {
				p1 = p1->pNext;
			}
			
			if (p1 != NULL) return -1;

			L1Item<TStation_Line> *pSize = this->sta_line.getHead();
			int count_Size = 0;
			while (pSize) {
				if (pSize->data.line_id == line_id)
				{
					count_Size++;
				}
				pSize = pSize->pNext;
			}
	


			if(p1 == NULL) {

				if (idx <0 || idx >count_Size) return -1;
				
				else {

					TStation_Line T1;
					T1.line_id = line_id;
					T1.sta_id = station_id;

					if (idx == 0) {
					/*	cout << "--- INSERT HEAD ! ---" << endl;*/
						this->sta_line.insertHead(T1);
						return 0;
					}

					else if (idx == count_Size) {
						this->sta_line.push_back(T1);
						return 0;
					}
					
					else {
						
						L1Item<TStation_Line> * pnew = new L1Item<TStation_Line>(T1);
						L1Item<TStation_Line> *pct = this->sta_line.getHead();
						L1Item<TStation_Line> *current = new L1Item<TStation_Line>;
						int temp = 0, count =0;
						while (pct) {
							if (pct->data.line_id == line_id) {
								temp++;
							}
							count++;

							if (temp == idx) break;
							
							pct = pct->pNext;
						}
						
						current = pct->pNext;
						pct->pNext = pnew;
						pnew->pNext = current;

						return 0;

					}
				}
			}
		}
		return -1;
	}
///////////////////////////////////////////////////////////////////////////////////////

	int  RSL(int station_id, int line_id) { // RSL <station_id> <line_id>
		
		L1Item<TLine>*p = this->line.getHead();
		while (p && p->data.id != line_id) {
			p = p->pNext;
		}
		if (p != NULL) {
			int i = 0;
			L1Item<TStation_Line> *p1 = this->sta_line.getHead();
			while (p1 && p1->data.sta_id != station_id) {
				i++;
				p1 = p1->pNext;
			}
			if (p1 != NULL) {
				this->sta_line.remove(i);
				return 0;
			}
			return -1;
		}
		return -1;
	}
};



// Please add more or modify as needed
void LoadData(void* &);
void ReleaseData(void* &);

#endif //DSA191_A1_DBLIB_H
