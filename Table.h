#ifndef TABLE_H
#define	TABLE_H

#include <iostream>
#include <cstdlib>   // Needed for the exit function
using namespace std;

#include "AbsTabl.h"

template <class T>
class Table : public AbsTabl<T> {
    public:
        // Overloaded constructor belongs to this class.
        Table(unsigned int rowSize, unsigned int colSize) {
            this->szRow = rowSize;
            this->szCol = colSize;

            // Create your array of pointers.
            // These are your rows.
            this->columns = new RowAray<T> *[rowSize];

            // Create the row arrays.
            // These are your columns.
            for (int i = 0; i < colSize; ++i) {
                this->columns[i] = new RowAray<T>(colSize);
            }
        }

        // Copy Constructor that belongs to this class.
        Table(const Table<T> &rhs) {
            this->szRow = rhs.szRow;
            this->szCol = rhs.szCol;

            // Create your array of pointers.
            this->columns = new RowAray<T> * [(int)rhs.szRow];

            // Create the row arrays.
            for (int i = 0; i < rhs.szCol; ++i) {
                this->columns[i] = new RowAray<T>(rhs.szCol);
            }

            // Copy the values from array A to array B
            for (int i = 0; i < rhs.szRow; ++i) {
                for (int j = 0; j < rhs.szCol; ++j) {
                    T value = rhs.getData(i, j); // Get value from array A
                    this->columns[i]->setData(j, value); // Set the value into array B
                }
            }
        }

        // Comes from the base class.
        // Do a little cleanup here.
        virtual ~Table() {
            for (int i = 0; i < this->szRow; ++i) {
                delete this->columns[i];
            }

            delete [] this->columns;
        }
        
        // Required to implement this.
        T getSzRow() const {
            return this->szRow;
        }
        
        // Required to implement this.
        T getSzCol() const {
            return this->szCol;
        }

        // Implement this.
        T getData(int row, int col) const {
            return this->columns[row]->getData(col);
        }

        // Implement this. Belongs to this class.
        void setData(int row, int col, int value) {
            return this->columns[row]->setData(col, value);
        }

        // Overloaded + operator
        // RHS = right hand side.
        // LHS = left hand side.
        Table<T> operator+(const Table<T> &rhs) {
            Table<T> lhs(*this); // Copy constructor

            for (int i = 0; i < lhs.getSzRow(); ++i) {
                for (int j = 0; j < lhs.getSzCol(); ++j) {
                    int result = lhs.getData(i, j) + rhs.getData(i, j);

                    lhs.setData(i, j, result);
                }
            }

            return lhs;
        }

        void subError() {
           cout << "ERROR: Subscript out of range.\n";
           exit(EXIT_FAILURE);
        }
};

#endif
