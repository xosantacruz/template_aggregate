#ifndef ROWARAY_H
#define	ROWARAY_H

#include "AbsRow.h"

template <class T>
class RowAray : public AbsRow<T> {
    public:
        RowAray(unsigned int numCols) {
            this->size = numCols;
            this->rowData = new T [numCols];

            // Add random values to the row array.
            for (int i = 0; i < numCols; ++i) {
                this->rowData[i] = rand() % 90 + 10;
            }
        }

        virtual ~RowAray() {
            delete [] this->rowData;
        }

        T getSize() const {
            return this->size;
        }

        T getData(int i) const {
            if (i >= 0 && i < this->size) {
                return this->rowData[i];
            } else {
                return 0;
            }
        }

        void setData(int col, T value) {
            this->rowData[col] = value;
        }
};

#endif