#ifndef ROWARAY_H
#define	ROWARAY_H

#include "AbsRow.h"

class RowAray : public AbsRow {
    public:
        RowAray(unsigned int numCols) {
            size = numCols;
            rowData = new int[numCols];

            // Add random values to the row array.
            for (int i = 0; i < numCols; ++i) {
                rowData[i] = rand() % 90 + 10;
            }
        }

        virtual ~RowAray() {
            delete [] rowData;
        }

        int getSize() const {
            return size;
        }

        int getData(int i) const {
            if ( i >= 0 && i < size) {
                return rowData[i];
            } else {
                return 0;
            }
        }

        void setData(int col, int value) {
            rowData[col] = value;
        }
};

#endif