/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};


template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _size(0) {}

	void    clean() {
		_pHead = NULL;
		_size = 0;
		
	}
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }
	size_t setSize() {
		return _size++;
	}

	//T&      at(int i) {   // give the reference to the element i-th in the list
	//	if (i < 0 || i > _size - 1) return -1;
	//	else {
	//		L1Item<T>* p = _pHead;
	//		for (int j = 0; j < i; j++) {
	//			p = p->pNext;
	//		}
	//		return p->data;
	//	}
	//}
	//T&      operator[](int i) {		// give the reference to the element i-th in the list
	//	return at(i);
	//}
	L1Item<T>* getHead() { return this->_pHead; }
	
	int     remove(int i) {// remove an element at position i in the list. Return 0 if success, -1 otherwise.
		if (_pHead==NULL) return -1;
		if (i == 0) {
			L1Item<T>* p = _pHead;
			_pHead = p-> pNext;
			delete p;
			return 0;
		}

			L1Item<T>* p = _pHead;
			for (int j = 0;p!=NULL && j < i-1; j++) {
				p = p->pNext;
			}
			if (p == NULL || p->pNext == NULL) return-1;

			L1Item<T> * _pidx = p->pNext->pNext;
			delete p->pNext;
			p->pNext = _pidx;

		_size--;
		return 0;
	}

    int     push_back(T& a);// insert to the end of the list
    int     insertHead(T& a);// insert to the beginning of the list

	//int     removeHead();// remove the beginning element of the list
 //   int     removeLast();// remove the last element of the list

	//void    reverse() {
	//	L1Item<T> *_pCurrent = _pHead;
	//	L1Item<T> *_prev = NULL, *_pnext = NULL;
	//	while (_pCurrent != NULL) {
	//		_pnext = _pCurrent->pNext;
	//		_pCurrent->pNext = _prev;
	//		_prev = _pCurrent;
	//		_pCurrent = _pnext;
	//	}
	//	_pHead = _prev;
	//}

 //   void    traverse(void (*op)(T&)) {
 //       // TODO: Your code goes here
	//	L1Item<T> *p = _pHead;
	//	while (p != NULL) {
	//		op(p->data);
	//		p = p->pNext;
	//	}
 //   }
 //   void    traverse(void (*op)(T&, void*), void* pParam) {
 //       // TODO: Your code goes here
	//	L1Item<T> * p = _pHead;
	//	while (p) {
	//		op(p->data, pParam);
	//		p = p->pNext;
	//	}
 //   }
};

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T &a) {
	// TODO: Your code goes here

	if (_pHead == NULL) {
		_pHead = new L1Item<T>(a);
	}
	else {
		L1Item<T> *p = _pHead;
		while (p->pNext) {
			p = p->pNext;
		}
		p->pNext = new L1Item<T>(a);
	}
	_size++;
	return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
    // TODO: Your code goes here
	L1Item<T> *p = new L1Item<T>(a);
	p->pNext = _pHead;
	_pHead = p;
	_size++;
    return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
//template <class T>
//int L1List<T>::removeHead() {
//    // TODO: Your code goes here
//
//}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise


#endif //DSA191_A1_DSALIB_H
