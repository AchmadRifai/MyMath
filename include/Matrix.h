#ifndef MATRIX_H
#define MATRIX_H
#include"Pecahan.h"
namespace math{
class Matrix
{
    public:
        Matrix(const unsigned int,const unsigned int);
        Matrix();
        ~Matrix();
        std::string to_string();
        void setBaris(const unsigned int);
        unsigned int getBaris();
        void setKolom(const unsigned int);
        unsigned int getKolom();
        bool isPersegi();
        bool isBaris();
        bool isKolom();
        bool isTegak();
        bool isDatar();
        bool isNol();
        bool isDiagonal();
        bool isSkalar();
        bool isSimetri();
        bool isMiring();
        bool isSatuan();
        bool isSegiAtas();
        bool isSegiBawah();
        bool isSebangun(const Matrix);
        Matrix transpose();
        void setData(const int,const unsigned int,const unsigned int);
        void setData(const Pecahan,const unsigned int,const unsigned int);
        Pecahan getData(const unsigned int,const unsigned int);
    protected:
    private:
        Pecahan*isi;
        unsigned int baris,kolom;
};
}
#endif // MATRIX_H
