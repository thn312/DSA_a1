/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"
#include "dbLib.h"
#include <cstring>
/* TODO: You can implement methods, functions that support your data structures here.
 * */
using namespace std;

void Initialization() {
    // If you use global variables, please initialize them explicitly in this function.
}

void Finalization() {
    // Release your data before exiting
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &N) {
    // TODO: Implement this function for processing a request
    // NOTE: You can add other functions to support this main process.
    //       pData is a pointer to a data structure that manages the dataset
    //       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
    //       N is the size of output, must be a non-negative number

	TDataset* p = static_cast <TDataset*>(pData);

	if (strcmp("CL",pRequest)==0) {
		cout << pRequest << ":";
		cout << ' ' << p->CL() << endl;
	}

///////////////////////////////////////////////////////////////////////////////

	else if (pRequest[0] == 'C' && pRequest[1] == 'L' && pRequest[2] == ' ') {
	int i = 3;
	string req = "";
	while (pRequest[i] != '\0') {
		req += pRequest[i];
		i++;
	}
	cout << pRequest << ":" << ' '; 
	p->CLC(req);
	
	}

////////////////////////////////////////////////////////////////////////////////
	else if (pRequest[0] == 'L' && pRequest[1] == 'S' && pRequest[2] == 'C' && pRequest[3] == ' ') {
		int i = 4;
		string req = "";
		while (pRequest[i] != '\0') {
			req += pRequest[i];
			i++;
		}
		cout << pRequest << ":";
		p->LSC(req);
	}

///////////////////////////////////////////////////////////////////////////////////
	else if (pRequest[0] == 'L' && pRequest[1] == 'L' && pRequest[2] == 'C' && pRequest[3] == ' ') {
		int i = 4;
		string req = "";
		while (pRequest[i] != '\0') {
			req += pRequest[i];
			i++;
		}
		cout << pRequest << ":";
		p->LLC(req);
	}

//////////////////////////////////////////////////////////////////////////////////////////
	else if (pRequest[0] == 'L'&&pRequest[1] == 'S'&&pRequest[2] == 'L' && pRequest[3] == ' '){
		int i = 4, number = 0;
		string req = "";
		while (pRequest[i] != '\0') {
			req += pRequest[i];
			i++;
		}

		int k = 0;
		int len = req.length();
		while (k < len) {
		 number += int( (req[k] - 48)*pow(10,len - k-1));
			k++;
		}

		cout << pRequest << ":";
	
		p->LSL(number);
	}

///////////////////////////////////////////////////////////////////////////////////

	else if (pRequest[0] == 'F' && pRequest[1] == 'C' && pRequest[2] == ' ') {
		int i = 3;
		string req = "";
		while (pRequest[i] != '\0') {
			req += pRequest[i];
			i++;
		}
		cout << pRequest << ":" <<' ' <<p->FC(req) <<endl;
	}


//////////////////////////////////////////////////////////////////////////////////

	else if (pRequest[0] == 'F' && pRequest[1] == 'S' && pRequest[2] == ' ') {
		int i = 3;
		string req = "";
		while (pRequest[i] != '\0') {
			req += pRequest[i];
			i++;
		}
		cout << pRequest << ":" << ' ' << p->FS(req) << endl;
	}

//////////////////////////////////////////////////////////////////////////////////

	else if (pRequest[0] == 'S' && pRequest[1] == 'L' && pRequest[2] == 'P' && pRequest[3] == ' ') {
		int i = 4;
		string req1 = "";
		string req2 = "";
		while (pRequest[i] != ' ') {
			req1 += pRequest[i];
			i++;
		}
		i++;
		while (pRequest[i] != '\0') {
			req2 += pRequest[i];
			i++;
		}

		int k = 0,id1=0,id2=0;
		int len = req1.length();
		while (k < len) {
			id1 += int((req1[k] - 48)*pow(10, len - k - 1));
			k++;
		}
		k = 0;
		int len2 = req2.length();
		while (k < len2) {
			id2 += int((req2[k] - 48)*pow(10, len2 - k - 1));
			k++;
		}
		cout << pRequest << ":" << ' ' << p-> SLP(id1,id2) << endl;
	}

//////////////////////////////////////////////////////////////////////////////////

	else if (pRequest[0] == 'R' && pRequest[1] == 'S' && pRequest[2] == ' ') {
	int i = 3;
	string req = "";
	while (pRequest[i] != '\0') {
		req += pRequest[i];
		i++;
	}
	int k = 0, id1 = 0;
	int len = req.length();
	while (k < len) {
		id1 += int((req[k] - 48)*pow(10, len - k - 1));
		k++;
	}

	cout << pRequest << ":" << ' ' << p->RS(id1) << endl;
	}

//////////////////////////////////////////////////////////////////////////////////

	else if (pRequest[0] == 'R' && pRequest[1] == 'S' && pRequest[2] == 'L' && pRequest[3] == ' ') {
	int i = 4;
	string req1 = "";
	string req2 = "";
	while (pRequest[i] != ' ') {
		req1 += pRequest[i];
		i++;
	}
	i++;
	while (pRequest[i] != '\0') {
		req2 += pRequest[i];
		i++;
	}

	int k = 0, id1 = 0, id2 = 0;
	int len = req1.length();
	while (k < len) {
		id1 += int((req1[k] - 48)*pow(10, len - k - 1));
		k++;
	}
	k = 0;
	int len2 = req2.length();
	while (k < len2) {
		id2 += int((req2[k] - 48)*pow(10, len2 - k - 1));
		k++;
	}
	cout << pRequest << ":" << ' ' << p->RSL(id1, id2) << endl;
	}

//////////////////////////////////////////////////////////////////////////////////

	else if (pRequest[0] == 'I' && pRequest[1] == 'S' && pRequest[2] == 'L' && pRequest[3] == ' ') {
	
	int staid = 0, lineid = 0, idx = 0;
	string text = "";
	stringstream s;
	s << pRequest;
	getline(s, text, ' ');
	s >> staid;
	s >> lineid;
	s >> idx;
	cout << pRequest << ":" << ' '  << p->ISL(staid,lineid,idx) << endl;
	}

//////////////////////////////////////////////////////////////////////////////////
	else if (pRequest[0] == 'U' && pRequest[1] == 'S' && pRequest[2] ==' ') {
	int i = 3;
	string req1 = "";
	string req2 = "";
	while (pRequest[i] != ' ') {
		req1 += pRequest[i];
		i++;
	}
	i++;
	while (pRequest[i] != '\0'){
		req2 += pRequest[i];
		i++;
	}
	int k = 0, id=0;
	int len = req1.length();
	while (k < len) {
		id += int((req1[k] - 48)*pow(10, len - k - 1));
		k++;
	}
	cout << pRequest << ":" << ' ' << p->US(id, req2) << endl;
	}
	
//////////////////////////////////////////////////////////////////////////////////
	else if (pRequest[0] == 'I' && pRequest[1] == 'S' && pRequest[2] == ' ') {
	int i = 3;
	string req = "";
	while (pRequest[i] != '\0'){
		req += pRequest[i];
		i++;
	}
	cout << pRequest << ":" << ' ' << p->IS(req) << endl;
	}
	//////////////////////////////////////////////////////////////////////////////////
	else {
		cout << pRequest << ":" << " error\n";
	}
	
}

