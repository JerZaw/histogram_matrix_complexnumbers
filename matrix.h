#ifndef MATRIX_H
#define MATRIX_H

#include<vector>
#include<iostream>
#include<functional>

template<typename T>
class Matrix
{
private:
    std::vector<std::vector<T>> vec;
public:
    Matrix(int wiersze = 0, int kolumny = 0){
        for(int i=0;i<wiersze;i++){
            std::vector<T> vecpom;
            for(int j=0;j<kolumny;j++){
                vecpom.emplace_back(0);
            }
            this->vec.emplace_back(vecpom);
        }
    }

    Matrix(std::vector<std::vector<T>> const &arg_vec){
        this->vec = arg_vec;
    }

    friend std::ostream &operator<<(std::ostream &out, const Matrix<T> &m){
        for(auto &row : m.vec){
            for(auto &el : row){
                out<<el<<' ';
            }
            out<<std::endl;
        }
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Matrix<T> &m){
        std::cout<<"podaj ilosc wierszy, potem ilosc kolumn macierzy\n";
        int wier,kol;
        T pom;
        in>>wier>>kol;
        in.clear();
        for(int i=0;i<wier;i++){
            std::vector<T> vecpom;
            for(int j=0;j<kol;j++){
                std::cout<<"podaj element: ["<<i<<", "<<j<<"]\n";
                in>>pom;
                vecpom.emplace_back(pom);
                in.clear();
            }
            m.vec.emplace_back(vecpom);
        }

    }

    static Matrix eye(int wiersze, int kolumny){
       Matrix<int> m(wiersze,kolumny);
       for(int i=0;i<wiersze;i++){
            for(int j=0;j<kolumny;j++){
                if(i==j)m.vec[i][j]=1;
                else m.vec[i][j]=0;
            }
        }
        return m;
    }

    static Matrix fill(int wiersze, int kolumny, std::function<T()> funkcja){
        Matrix<T> m(wiersze,kolumny);
        for(int i=0;i<wiersze;i++){
             for(int j=0;j<kolumny;j++){
                 m.vec[i][j] = funkcja();
             }
         }
         return m;
    }

    Matrix operator+(const T &skalar){
        Matrix m(this->vec);
        for(int i=0;i<this->vec.size();i++){
            for(int j=0;j<this->vec[i].size();j++){
                m.vec[i][j]+=skalar;
            }
        }
        return m;
    }

    Matrix operator*(const T &skalar){
        Matrix m(this->vec);
        for(int i=0;i<this->vec.size();i++){
            for(int j=0;j<this->vec[i].size();j++){
                m.vec[i][j]*=skalar;
            }
        }
        return m;
    }

    friend Matrix operator*(const T &skalar, const Matrix<T> &macierz){
        Matrix m(macierz.vec);
        for(int i=0;i<macierz.vec.size();i++){
            for(int j=0;j<macierz.vec[i].size();j++){
                m.vec[i][j]*=skalar;
            }
        }
        return m;
    }

    Matrix operator*(const Matrix<T> &macierz){
        if(this->vec[0].size()!=macierz.vec.size()){
            std::cout<<"nie da sie pomnozyc tych macierzy\n";
        }
        else{

        T pom;
        std::vector<std::vector<T>> pomvec;
        std::vector<T> smolpomvec;

        for(int i=0;i<this->vec.size();i++){
            smolpomvec.clear();
            for(int j=0;j<macierz.vec[i].size();j++){
                pom=0;
                for(int it=0;it<macierz.vec.size();it++){
                    pom+=this->vec[i][it]*macierz.vec[it][j];
                }
                smolpomvec.emplace_back(pom);
            }
            pomvec.emplace_back(smolpomvec);
        }
        Matrix m(pomvec);
        return m;
        }
    }


};

#endif // MATRIX_H
