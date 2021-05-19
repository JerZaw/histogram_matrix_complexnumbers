#ifndef WEKTOR_OVERLOADING_H
#define WEKTOR_OVERLOADING_H

#include<vector>
#include<iostream>
template <typename T>
std::vector<T> operator+(std::vector<T> &v1,std::vector<T> &v2){
    std::vector<T> wynik;
    int n=std::min(v1.size(),v2.size());
    for(int i=0;i<n;i++){
        wynik.emplace_back(v1[i]+v2[i]);
    }
    return wynik;
}

template <typename T>
std::vector<T> operator-(std::vector<T> &v1,std::vector<T> &v2){
    std::vector<T> wynik;
    int n=std::min(v1.size(),v2.size());
    for(int i=0;i<n;i++){
        wynik.emplace_back(v1[i]-v2[i]);
    }
    return wynik;
}

template <typename T>
T operator*(std::vector<T> &v1,std::vector<T> &v2){
    T wynik;
    int n=std::min(v1.size(),v2.size());
    for(int i=0;i<n;i++){
        wynik = wynik + (v1[i]*v2[i]);

    }
    return wynik;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, std::vector<T> vec){
       for(auto &el : vec){
           out<<el<<' ';
       }
       out<<std::endl;
       return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, std::vector<std::pair<T,int>> vec){
       for(auto &el : vec){
           out<<el.first<<' '<<el.second<<std::endl;
       }
       out<<std::endl;
       return out;
}


#endif // WEKTOR_OVERLOADING_H
