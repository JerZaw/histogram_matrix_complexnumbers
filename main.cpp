#include <iostream>
#include <histogram.h>
#include <vector>
#include <zespolona.h>
#include <iomanip>
#include <wektor_overloading.h>
#include <ctime>
#include <cstdlib>
#include <matrix.h>
#include <random>

using typ_template = float;

void print(std::vector<std::pair<typ_template, int>> dodruku){
    for(auto &el : dodruku){
        std::cout<<el.first<<" w ilosci: "<<el.second<<std::endl;
    }
}

int main()
{
    //ZADANIE 4
//    Matrix<typ_template> m1;
//    Matrix<typ_template> m2(4,3);
//    Matrix<typ_template> m3({{1,2,3,4,5},{3,4,5,6,7},{9,8,7,6,5}});
//    Matrix<typ_template> m4({{1,2},{2,3},{3,4},{4,5},{5,6}});
//    std::cout<<m3<<std::endl<<m4<<"\nWYNIK:\n";
//    std::cout<<m4*m3;
//    Matrix<int> meye = Matrix<int>::eye(3,3);
    //std::cin>>m1;
    //std::cout<<meye<<std::endl;

//    static std::default_random_engine e{};
//    std::uniform_int_distribution<int> distribution{0, 100};
//    Matrix<int>  Y = Matrix<int>::fill(3, 3, [&distribution](){ return distribution(e); });
//    std::cout<<Y;
//    std::cout<<"\nTEST\n";
//    std::cout<<Y+1;
//    std::cout<<"\nTEST\n";
//    std::cout<<2*Y;
//    std::cout<<"\nTEST\n";
//    std::cout<<2*Y;


    //ZADANIE 3
//    srand(time(0));
//    std::vector<typ_template> v1,v2;
//    for(int i=0;i<3;i++){
//        v1.emplace_back(-5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(5+10))));
//        v2.emplace_back(-5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(5+10))));
//    }

//    std::cout<<v1<<v2<<std::endl;
//    std::cout<<v1+v2<<std::endl;
//    std::cout<<v1-v2<<std::endl;
//    std::cout<<v1*v2<<std::endl;

    //ZADANIE 2
//    Zespolona<typ_template> z1;
//    z1.setRE(2.2);
//    z1.setIM(3.01);
//    std::cout<<z1<<std::endl;
//    Zespolona<typ_template> z2(1,5.3,3);
//    std::cout<<z2<<std::endl<<std::endl;

//    std::cout<<z1+z2<<std::endl;

//    std::cout<<z1-z2<<std::endl;

//    std::cout<<z1*z2<<std::endl;

//    std::cout<<z1/z2<<std::endl;

//    ZADANIE 1
//    std::vector<typ_template> vec;
//    vec.emplace_back(1);
//    vec.emplace_back(2);
//    vec.emplace_back(5);
//    vec.emplace_back(8);
//    vec.emplace_back(10);
//    Histogram hist(vec);
//    hist<<5;
//    hist.emplace(10);
//    //std::cin>>hist;
//    hist.from_csv("example.csv",',',2);

//    using BinsVector = std::vector<std::pair<typ_template, int>>;
//    BinsVector items_vect = static_cast<BinsVector>(hist);
//    print(items_vect);


//    Histogram hist = Histogram<int>::generate(-10,10,50);
      //Histogram hist = Histogram<int>::generate(100, [](){ return -10 + rand() % 21; });
      //std::cout<<hist;
//    std::cout<<hist.max().first<<' '<<hist.max().second<<std::endl;
//    std::cout<<hist.unique_bins()<<std::endl;
//    std::cout<<hist.unique_items()<<std::endl;
//    std::cout<<std::endl<<hist[11]<<std::endl;
//    std::cout<<hist.range().first<<' '<<hist.range().second<<std::endl;
//    Histogram<int> hist_int = Histogram<int>::generate(-10,10,50);
//    std::cout<<hist_int;
}
