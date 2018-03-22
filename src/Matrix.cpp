#include "Matrix.h"
#include<sstream>

using namespace math;

Matrix::Matrix(const unsigned int x,const unsigned int y){
    kolom=x;
    baris=y;
    isi=new Pecahan[x*y];
}

Matrix::~Matrix(){
    delete isi;
}

Matrix::Matrix(){
    kolom=0;
    baris=0;
    isi=nullptr;
}

void Matrix::setBaris(const unsigned int x){
    baris=x;
    delete isi;
    isi=new Pecahan[baris*kolom];
}

void Matrix::setKolom(const unsigned int x){
    kolom=x;
    delete isi;
    isi=new Pecahan[baris*kolom];
}

unsigned int Matrix::getBaris(){
    return baris;
}

unsigned int Matrix::getKolom(){
    return kolom;
}

Pecahan Matrix::getData(const unsigned int x,const unsigned int y){
    return isi[x][y];
}

void Matrix::setData(const int v,const unsigned int x,const unsigned int y){
    isi[x][y]=v;
}

void Matrix::setData(const Pecahan p,const unsigned int x,const unsigned int y){
    isi[x][y]=p;
}

std::string Matrix::to_string(){
    std::ostringstream o;
    for(int x=0;x<baris;x++){
        for(int y=0;y<kolom;y++)o<<isi[x][y].to_string()<<" ";
        o<<endl;
    }return o.str();
}

bool Matrix::isPersegi(){
    return baris==kolom;
}

bool Matrix::isBaris(){
    return baris==1;
}

bool Matrix::isKolom(){
    return kolom==1;
}

bool Matrix::isTegak(){
    return baris>kolom;
}

bool Matrix::isDatar(){
    return baris<kolom;
}

bool Matrix::isNol(){
    bool b=true;
    for(int x=0;x<baris;x++)for(int y=0;y<kolom;y++)if(isi[x][y]!=0){
        b=false;
        break;
    }return b;
}

bool Matrix::isDiagonal(){
    bool b=isPersegi();
    if(b){
        for(int x=0;x<baris;x++)for(int y=0;y<kolom;y++)if(x==y){
            if(isi[x][y]==0){
                b=false;
                break;
            }
        }else{
            if(isi[x][y]!=0){
                b=false;
                break;
            }
        }
    }return b;
}

bool Matrix::isSkalar(){
    bool b=isDiagonal();
    Pecahan p;
    if(b)for(int x=0;x<baris;x++)for(int y=0;y<kolom;y++)if(x==y){
        if(p!=0){
            if(p!=isi[x][y]){
                b=false;
                break;
            }
        }else p=isi[x][y];
    }return b;
}

bool Matrix::isSimetri(){
    bool b=isPersegi();
    Pecahan p;
    if(b)for(int x=0;x<baris;x++)for(int y=0;y<kolom;y++)if(x!=y){
        if(p!=0){
            if(p!=isi[x][y]){
                b=false;
                break;
            }
        }else p=isi[x][y];
    }return b;
}
