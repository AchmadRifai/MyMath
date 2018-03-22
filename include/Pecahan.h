#ifndef PECAHAN_H
#define PECAHAN_H
#include<string>
namespace math{
    class Pecahan{
    private:
        int angka,pembilang;
        unsigned int penyebut;
    public:
        Pecahan();
        Pecahan(const int);
        Pecahan(const int,const int);
        Pecahan(const int,const int,const unsigned int);
        void operator=(const int);
        void operator=(const Pecahan);
        std::string to_string();
        bool isBulat();
        void setAngka(const int);
        void setPembilang(const int);
        void setPenyebut(const unsigned int);
        int getAngka();
        int getPembilang();
        unsigned int getPenyebut();
        Pecahan operator+(const int);
        Pecahan operator+(const Pecahan);
        Pecahan operator-(const int);
        Pecahan operator-(const Pecahan);
        Pecahan operator*(const int);
        Pecahan operator*(const Pecahan);
        Pecahan operator/(const int);
        Pecahan operator/(const Pecahan);
        bool operator==(const int);
        bool operator==(const Pecahan);
        bool operator!=(const int);
        bool operator!=(const Pecahan);
        bool operator>(const int);
        bool operator>(const Pecahan);
        bool operator<(const int);
        bool operator<(const Pecahan);
        bool operator>=(const int);
        bool operator>=(const Pecahan);
        bool operator<=(const int);
        bool operator<=(const Pecahan);
    };
}
#endif // PECAHAN_H
