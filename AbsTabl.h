#ifndef ABSTABL_H
#define ABSTABL_H

#include "RowAray.h"

template <class T>
class AbsTabl {
    protected:
        T szRow;
        T szCol;
        RowAray<T> **columns;
    public:
        /** The = 0 is not related to const.
        It's used in conjunction with virtual to indicate that the function
        is pure virtual. That means it must be overridden by a sub-class.
        Classes containing pure virtual functions are sometimes
        described as abstract because they cannot be directly instantiated */
        virtual T getSzRow() const = 0;
        virtual T getSzCol() const = 0;
        virtual T getData(int,int) const = 0;
};

#endif
