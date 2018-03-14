#ifndef TABLE_H
#define	TABLE_H

#include "AbsTabl.h"

class Table : public AbsTabl {
    public:
        // Overloaded constructor belongs to this class.
        Table(unsigned int rowSize, unsigned int colSize) {
            szRow = rowSize;
            szCol = colSize;

            // Create your array of pointers.
            // These are your rows.
            columns = new RowAray * [rowSize];

            // Create the row arrays.
            // These are your columns.
            for (int i = 0; i < colSize; ++i) {
                columns[i] = new RowAray(colSize);
            }
        }

        // Copy Constructor that belongs to this class.
        Table(const Table &rhs) {
            szRow = rhs.szRow;
            szCol = rhs.szCol;

            // Create your array of pointers.
            columns = new RowAray * [rhs.szRow];

            // Create the row arrays.
            for (int i = 0; i < rhs.szCol; ++i) {
                columns[i] = new RowAray(rhs.szCol);
            }

            // Copy the values from array A to array B
            for (int i = 0; i < rhs.szRow; ++i) {
                for (int j = 0; j < rhs.szCol; ++j) {
                    int value = rhs.getData(i, j); // Get value from array A
                    columns[i]->setData(j, value); // Set the value into array B
                }
            }
        }

        // Comes from the base class.
        // Do a little cleanup here.
        virtual ~Table() {
            for (int i = 0; i < szRow; ++i) {
                delete columns[i];
            }

            delete [] columns;
        }
        
        // Required to implement this.
        int getSzRow() const {
            return szRow;
        }
        
        // Required to implement this.
        int getSzCol() const {
            return szCol;
        }

        // Implement this.
        int getData(int row, int col) const {
            return columns[row]->getData(col);
        }

        // Implement this. Belongs to this class.
        void setData(int row, int col, int value) {
            return columns[row]->setData(col, value);
        }
};

#endif
