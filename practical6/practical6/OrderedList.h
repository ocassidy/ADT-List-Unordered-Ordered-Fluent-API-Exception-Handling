/*
* OrderedList.h
*
* Generic Ordered List based on a List implementation
*
* @author  Aiden McCaughey
* @email   a.mccaughey@ulster.ac.uk
* @version 1.2
*
*/

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include "ArrayList.h"

template <class T>
class OrderedList : public ArrayList<T>
{
public:
	explicit OrderedList(int size=100) : ArrayList<T>(size) {};
	OrderedList(const ArrayList<T> & data);

	void add(const T & e);
	int find(const T& e) const; 
	T first() const;
	T last() const;

	// override invalid operations
	void add(int pos, const T & e);
	void set(int pos, const T & e);

};

// PostCondition: Ordered list constructed from elements in ArrayList
template <class T>
OrderedList<T>::OrderedList(const ArrayList<T> & al) : ArrayList<T>(al.size()) 
{
	// calling orderedlist add function ensures elements are added in order
	for (int i = 0; i < al.size(); i++) {
		ArrayList<T>::add(al.get(i));
	}
}

// PreCondition: isEmpty() == false
template <class T>
T OrderedList<T>::first() const
{
	return ArrayList<T>::get(0);
}

// PreCondition: isEmpty() == false
template <class T>
T OrderedList<T>::last() const
{
	return ArrayList<T>::get(ArrayList<T>::size()-1); 
}

// PreCondition:: none
// PostCondition: element added to Collection
template <class T>
void OrderedList<T>::add(const T & e)
{        
	// locate correct position to insert
	int pos;
	for(pos=0; pos < ArrayList<T>::size() && e > ArrayList<T>::get(pos); pos++);

	// add element at ordered position
	// important to call superclass ArrayList add function
	ArrayList<T>::add(pos,e);   
}

// PreCondition:: elements in list are ordered
// PostCondition: return postion of element in List or -1 if not found
template <class T>
int OrderedList<T>::find(const T & e) const {
   int left = 0;				// set left boundary
   int right = ArrayList<T>::size()-1;		// set right boundary	
   while (left <= right) {		// continue search?
      int pivot = (left + right) / 2;
      if (e == ArrayList<T>::get(pivot)) {	
         return pivot;			// found
      } else if (e > ArrayList<T>::get(pivot)) { 
         left = pivot + 1;		// search to right
      } else {
         right = pivot - 1;		// search to left
      }
   }
   return -1;
}

// PreCondition: method call is invalid as OrderedList does not include set function
// PostCondition: calling this method will throw an exception 
template <class T>
void OrderedList<T>::set(int pos, const T & e)
{        
	// std::exception does not have a constructor that takes a string
	throw std::runtime_error("invalid operation on an Ordered List");
}

// PreCondition: method call is invalid as OrderedList does not include add at position function
// PostCondition: calling this method will throw an exception 
template <class T>
void OrderedList<T>::add(int pos, const T & e)
{
	throw std::runtime_error("invalid operation on an Ordered List");
}

#endif /* ORDEREDLIST_H */
