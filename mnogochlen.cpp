#include "artonom.h"
using namespace std;

int main()
    {
    Ppolinom Header = NULL;
    Ppolinom p = NULL;

    int size_arr = 0;
    std::cin >> size_arr;

    Header = new polinom;
    p = Header;

    int tmp_a = 0;
    int tmp_p = 0;
    for (int i = 0; i < size_arr; i++)
        {
        std::cin >> tmp_a;
        std::cin >> tmp_p;

        p -> a = tmp_a;
        p -> p = tmp_p;

        if (i != (size_arr - 1))
            {
            p -> link = new polinom;
            p = p -> link;
            }
        }

    p -> link = NULL;



    Ppolinom Header2 = NULL;
    Header2 = new polinom;
    p = Header2;

    std::cin >> size_arr;

    tmp_a = 0;
    tmp_p = 0;
    for (int i = 0; i < size_arr; i++)
        {
        std::cin >> tmp_a;
        std::cin >> tmp_p;

        p -> a = tmp_a;
        p -> p = tmp_p;

        if (i != (size_arr - 1))
            {
            p -> link = new polinom;
            p = p -> link;
            }
        }

    p -> link = NULL;


    //out (dif (Header), 'x');
    //std::cout << '\n';
    out (sum (Header, Header2), 'x');
    }


