#include "alistint.h"

using namespace std;

 /**
  * Default constructor - default to a list of capacity = 5
  */
AListInt::AListInt() {
	_data = new int[5];
	_size = 0;
}

 /**
  * Another constructor - default to a list to the indicated capacity
  */
AListInt::AListInt(int cap) {
	_data = new int[cap];
	_cap = cap;
	_size = 0;
}

/**
  * Copy constructor 
  */
AListInt::AListInt(const AListInt& other ) {
	_size = other._size;
	_cap = other._cap;
	for(int i = 0; i<(int)_size; i++) {
		_data[i] = other._data[i];
	}
}

 /**
  * Assignment operator
  */
AListInt &AListInt::operator=(const AListInt& other) {
	
	_data = new int[other._size];
	_size = other._size;
	for(int i = 0; i<(int)_size; i++) {
		_data[i] = other._data[i];
	}
	return *this;
}

 /**
  * Destructor
  */
AListInt::~AListInt() {

}

/**
 * Standard List interface
 */


/**
 * Returns true if the list is empty, false otherwise
 */
bool AListInt::empty() const
{
  return _size == 0;
}

/**
 * Returns the current number of items in the list 
 */
int AListInt::size() const
{
  return _size;
}

/**
 * Inserts val so it appears at index, pos
 */
void AListInt::insert(int loc, const int& val)
{	
	int oldsize = _size;

	if(_size==_cap) {
		resize();
	}

	if(loc<(int)_size) {
		for(int i = oldsize; i>loc; loc--) {
			_data[i+1] = _data[i];
		}
	}

	if(loc == oldsize) {
		_data[loc] = val;
	}

	_size++;
}


/**
 * Removes the value at index, pos
 */
void AListInt::remove(int loc)
{
	if(loc<(int)_size && loc>=0) {
		for(int i = loc; i<(int)_size; loc++) {
			_data[i] = _data[i+1];
		}
	}
	_size--;
}

/**
 * Overwrites the old value at index, pos, with val
 */
void AListInt::set(int loc, const int& val)
{
	if(loc<(int)_size && loc>=0) {
  		_data[loc] = val;
	}
}

/**
 * Returns the value at index, pos
 */
int& AListInt::get(int loc)
{
	if(loc<(int)_size && loc>=0) {
		return _data[loc];
	}
	else
		return;
}

/**
 * Returns the value at index, pos
 */
int const & AListInt::get(int loc) const
{
	if(loc<(int)_size && loc>=0) {
		return _data[loc];
	}
	else
		return;
}

void AListInt::resize() {
	_cap = _cap*2;

	int* resized = new int[_cap];

	for(int i = 0; i<(int)_size; i++) {
		resized[i] = _data[i];
	}

	delete[] _data;

	_data = resized;
}

/**
 * Produce a new list by concatenating this list and the input list
 *   If this list = [1, 2, 3] and other = [4, 5, 6] then return 
 *   a new list with contents [1, 2, 3, 4, 5, 6].  The capacity
 *   of the new list should be equal to its size (i.e. the new list
 *   would be full upon being returned)
 */
AListInt AListInt::operator+(const AListInt& other) const {
	int sum[other._size+_size];

	int place = 0;
	for(int i = _size; i<(int)(other._size+_size); i++) {
		sum[i] = other._data[place];
		place++;
	}
	return *sum;
}

/**
 * Operator[] to access the element at the given position
 */
int const & AListInt::operator[](int position) const {
	if(position<=(int)_size && position>=0) {
		return _data[position];
	}
	else
		return 0;
}

/**
 * Non-const version
 */
 int& AListInt::operator[](int position) {
	if(position<=(int)_size && position>=0) {
		return _data[position];
	}
	else
		return 0;
 }