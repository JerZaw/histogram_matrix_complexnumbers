#ifndef ZESPOLONA_H
#define ZESPOLONA_H

#include<iostream>
#include<iomanip>

template <typename T>
class Zespolona
{
private:
    T re,im;
    int precyzja;
public:

    Zespolona(const T &arg_re = T(0), const T &arg_im = T(0), const int &arg_precyzja = 0){
        this->re = arg_re;
        this->im = arg_im;
        this->precyzja = arg_precyzja;
    }

    friend std::ostream &operator<<(std::ostream &out, Zespolona z){
        if(z.precyzja==0){
            out<<z.re;
            if(z.im>0)out<<'+';
            out<<z.im<<'i';
        }
        else{
            out<<std::fixed<<std::setprecision(z.precyzja)<<z.re;
            if(z.im>0)out<<'+';
            out<<std::setprecision(z.precyzja)<<z.im<<'i';
        }
        return out;
    }

    const Zespolona operator+(const Zespolona &z){
        int pom_precyzja = std::max(this->precyzja,z.precyzja);
        Zespolona wynik(this->re+z.re,this->im+z.im,pom_precyzja);
        return wynik;
    }

    const Zespolona operator-(const Zespolona &z){
        int pom_precyzja = std::max(this->precyzja,z.precyzja);
        Zespolona wynik(this->re-z.re,this->im-z.im,pom_precyzja);
        return wynik;
    }

    const Zespolona operator*(const Zespolona &z){
        int pom_precyzja = std::max(this->precyzja,z.precyzja);
        Zespolona wynik(this->re*z.re-this->im*z.im,this->im*z.re+this->re*z.im,pom_precyzja);
        return wynik;
    }

    const Zespolona operator/(const Zespolona &z){
        int pom_precyzja = std::max(this->precyzja,z.precyzja);
        if((z.re*z.re + z.im*z.im)==0){
            std::cout<<"nie mozna wykonac dzielenia\n";
            Zespolona wynik;
            return wynik;
        }
        else {
            Zespolona wynik((this->re*z.re+this->im*z.im)/(z.re*z.re + z.im*z.im),(this->im*z.re-this->re*z.im)/(z.re*z.re + z.im*z.im),pom_precyzja);
            return wynik;
        }
    }




    T getRE() const{
        return this->re;
    }
    T getIM() const{
        return this->im;
    }
    int getPRE() const{
        return this->precyzja;
    }
    void setRE(T x){
        this->re = x;
    }
    void setIM(T x){
        this->im = x;
    }
    void setPRE(int x){
        this->precyzja = x;
    }
};

#endif // ZESPOLONA_H
