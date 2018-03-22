#include"Pecahan.h"
#include<sstream>
#include<list>

using namespace math;

Pecahan::Pecahan(){
    angka=0;
    pembilang=0;
    penyebut=1;
}

Pecahan::Pecahan(const int a){
    angka=a;
    pembilang=0;
    penyebut=1;
}

Pecahan::Pecahan(const int a,const int b){
    angka=0;
    pembilang=a;
    penyebut=b;
}

Pecahan::Pecahan(const int a,const int b,const unsigned int c){
    angka=a;
    pembilang=b;
    penyebut=c;
}

void Pecahan::operator=(const int a){
    angka=a;
    pembilang=0;
    penyebut=1;
}

void Pecahan::operator=(const Pecahan p){
    angka=p.angka;
    pembilang=p.pembilang;
    penyebut=p.penyebut;
}

std::string Pecahan::to_string(){
    std::ostringstream o;
    if(!isBulat())o<<"("<<angka<<")"<<pembilang<<"/"<<penyebut;
    else o<<angka;
    return o.str();
}

bool Pecahan::isBulat(){
    return pembilang==0;
}

void Pecahan::setAngka(const int a){
    angka=a;
}

void Pecahan::setPembilang(const int a){
    pembilang=a;
}

void Pecahan::setPenyebut(const unsigned int a){
    penyebut=a;
}

int Pecahan::getAngka(){
    return angka;
}

int Pecahan::getPembilang(){
    return pembilang;
}

unsigned int Pecahan::getPenyebut(){
    return penyebut;
}

Pecahan sederhana(Pecahan p){
    Pecahan c;
    c.setPembilang(p.getPembilang()+(p.getAngka()*p.getPenyebut()));
    c.setPenyebut(p.getPenyebut());
    return c;
}

bool isPrima(int a){
    bool b=true;
    for(int x=2;x<a/2;x++)if(a%x==0){
        b=false;
        break;
    }return b;
}

std::list<int>genPrima(int batas){
    std::list<int>l;
    for(int x=2;x<=batas;x++)if(isPrima(x))l.push_front(x);
    return l;
}

Pecahan bongkar(Pecahan p){
    Pecahan c;
    c.setAngka(p.getPembilang()/p.getPenyebut());
    c.setPembilang(p.getPembilang()%p.getPenyebut());
    c.setPenyebut(p.getPenyebut());
    std::list<int>l=genPrima(c.getPembilang());
    for(int x:l)while(c.getPembilang()%x==0&&c.getPenyebut()%x==0){
        c.setPembilang(c.getPembilang()/x);
        c.setPenyebut(c.getPenyebut()/x);
    }return c;
}

Pecahan tambah(Pecahan x,Pecahan y){
    Pecahan a=sederhana(x),b=sederhana(y),c;
    c.setPembilang((a.getPembilang()*b.getPenyebut())+(a.getPenyebut()*b.getPembilang()));
    c.setPenyebut(a.getPenyebut()*b.getPenyebut());
    return bongkar(c);
}

Pecahan Pecahan::operator+(const int x){
    Pecahan p(x);
    return tambah(*this,p);
}

Pecahan Pecahan::operator+(const Pecahan p){
    return tambah(*this,p);
}

Pecahan kurang(Pecahan x,Pecahan y){
    Pecahan a=sederhana(x),b=sederhana(y),c;
    c.setPembilang((a.getPembilang()*b.getPenyebut())-(b.getPembilang()*a.getPenyebut()));
    c.setPenyebut(a.getPenyebut()*b.getPenyebut());
    return bongkar(c);
}

Pecahan Pecahan::operator-(const int x){
    Pecahan p(x);
    return kurang(*this,p);
}

Pecahan Pecahan::operator-(const Pecahan p){
    return kurang(*this,p);
}

Pecahan kali(Pecahan x,Pecahan y){
    Pecahan a=sederhana(x),b=sederhana(y),c;
    c.setPembilang(a.getPembilang()*b.getPembilang());
    c.setPenyebut(a.getPenyebut()*b.getPenyebut());
    return bongkar(c);
}

Pecahan Pecahan::operator*(const int x){
    Pecahan p(x);
    return kali(*this,p);
}

Pecahan Pecahan::operator*(const Pecahan p){
    return kali(*this,p);
}

Pecahan bagi(Pecahan x,Pecahan y){
    Pecahan a=sederhana(x),b=sederhana(y),c;
    c.setPembilang(a.getPembilang()*b.getPenyebut());
    c.setPenyebut(a.getPenyebut()*b.getPembilang());
    return bongkar(c);
}

Pecahan Pecahan::operator/(const int x){
    Pecahan p(x);
    return bagi(*this,p);
}

Pecahan Pecahan::operator/(const Pecahan p){
    return bagi(*this,p);
}

bool isSama(Pecahan x,Pecahan y){
    return x.getAngka()==y.getAngka()&&x.getPembilang()==y.getPembilang()&&x.getPenyebut()==y.getPenyebut();
}

bool isKurang(Pecahan x,Pecahan y){
    Pecahan a=sederhana(x),b=sederhana(y);
    a.setPembilang(a.getPembilang()*b.getPenyebut());
    b.setPembilang(b.getPembilang()*a.getPenyebut());
    return a.getPembilang()<b.getPembilang();
}

bool isLebih(Pecahan x,Pecahan y){
    Pecahan a=sederhana(x),b=sederhana(y);
    a.setPembilang(a.getPembilang()*b.getPenyebut());
    b.setPembilang(b.getPembilang()*a.getPenyebut());
    return a.getPembilang()>b.getPembilang();
}

bool Pecahan::operator==(const int x){
    Pecahan p(x);
    return isSama(*this,p);
}

bool Pecahan::operator==(const Pecahan p){
    return isSama(*this,p);
}

bool Pecahan::operator!=(const int x){
    Pecahan p(x);
    return!isSama(*this,p);
}

bool Pecahan::operator!=(const Pecahan p){
    return!isSama(*this,p);
}

bool Pecahan::operator>(const int x){
    Pecahan p(x);
    return isLebih(*this,p);
}

bool Pecahan::operator>(const Pecahan p){
    return isLebih(*this,p);
}

bool Pecahan::operator<(const int x){
    Pecahan p(x);
    return isKurang(*this,p);
}

bool Pecahan::operator<(const Pecahan p){
    return isKurang(*this,p);
}

bool Pecahan::operator<=(const int x){
    Pecahan p(x);
    return!isLebih(*this,p);
}

bool Pecahan::operator<=(const Pecahan p){
    return!isLebih(*this,p);
}

bool Pecahan::operator>=(const int x){
    Pecahan p(x);
    return!isKurang(*this,p);
}

bool Pecahan::operator>=(const Pecahan p){
    return!isKurang(*this,p);
}
