#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include<vector>
#include<map>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>


template <typename T>
class Histogram
{
private:
    std::map<T,int> bins_;
public:
    Histogram(const std::vector<T> &vec = std::vector<T>()){
        for(auto &n: vec){
            this->emplace(n);
        }
    }

    void emplace(const T &t){
        this->bins_[t]++;
    }

    void emplace(const std::vector<T> &vec){
        for(auto &n: vec){
            this->emplace(n);
        }
    }

    Histogram &operator<<(const T &data){
        this->emplace(data);
    }

    friend std::ostream &operator<<(std::ostream &out, const Histogram<T> &hist){
        for(auto &el: hist.bins_){
            out<<el.first<<' '<<el.second<<std::endl;
        }
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Histogram<T> &hist){
        std::cout<<"Podaj liczbe wynikow, ktore chcesz wprowadzic\n";
        int n;
        T pierwszy;
        in>>n;
        in.clear();
        for(int i=0;i<n;i++){
            std::cout<<"Wprowadz "<<i+1<<" wynik\n";
            in>>pierwszy;
            hist.emplace(pierwszy);
            in.clear();
        }
    }

    void from_csv(std::string sciezka, char separator, int nr_kolumny){
        std::ifstream o;
        o.open(sciezka);
        if(!o.is_open()){
            std::cout<<"Zla sciezka pliku\n";
        }
        else{
            std::string data;
            T mydata;
            while(!o.eof()){
                for(int i=0;i<nr_kolumny;i++){
                    std::getline(o,data,separator);
                }
                o>>mydata;
                this->emplace(mydata);
                std::getline(o,data);
            }
        }
    }

    void clear(){
        std::map<T,int> pom;
        this->bins_=pom;
    }

    operator std::vector<std::pair<T, int>>(){
        std::vector<std::pair<T, int>> vec;
        for(auto &el : this->bins_){
            vec.emplace_back(el);
        }
        return vec;
    }

    int operator[](T value) const{
        try{
        return this->bins_.at(value);
        }
        catch(std::out_of_range e){
            std::cout<<"Exception: "<<e.what()<<std::endl;
            return -1;
        }
    }

    std::pair<T,T> range() const{
        std::pair<T,T> p(this->bins_.begin()->first,this->bins_.rbegin()->first);
        return p;
    }

    std::pair<T, int> max() const{
        std::pair<T, int> curr_max = *this->bins_.begin();
        for(auto &el : this->bins_){
            if(curr_max.second<el.second){
                curr_max = el;
            }
        }
        return curr_max;
    }

    std::vector<T> unique_bins(){
        std::vector<T> vec;
        for(auto &el: this->bins_){
            if(el.second!=0)vec.emplace_back(el.first);
        }
        return vec;
    }

    std::vector<std::pair<T, int>> unique_items(){
        std::vector<std::pair<T, int>> vec;
        for(auto &el: this->bins_){
            if(el.second!=0)vec.emplace_back(el);
        }
        return vec;
    }

    static Histogram generate(int min, int max, int count){
        srand(time(0));
        Histogram hist;
        int zakres = max-min+1;
        for(int i=0;i<count;i++){
            hist.emplace(rand()%zakres+min);
        }
        return hist;
    }

    static Histogram generate(int count, T(*funkcja_ptr)()){
        Histogram hist;
        for(int i=0;i<count;i++){
            hist.emplace(funkcja_ptr());
        }
        return hist;
    }

};

#endif // HISTOGRAM_H
