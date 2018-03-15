#ifndef ABSROW_H
#define ABSROW_H

template <class T>
class AbsRow {
    protected:
        T size;
        T *rowData;
    public:
        virtual T getSize() const = 0;
        virtual T getData(int) const = 0;
};

#endif
