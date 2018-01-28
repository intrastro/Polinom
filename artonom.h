#include <iostream>
#include <stdlib.h>
#include <cmath>
#define artamonov std::cout<<"artamonov"<<'\n';
using namespace std;

struct polinom
    {
    int a, p;
    polinom* link;
    };
typedef polinom *Ppolinom;

bool eqv (Ppolinom polinom1, Ppolinom polinom2);
double res (Ppolinom polinom1, int x);
void out (Ppolinom polinom1, char v);
Ppolinom dif ( Ppolinom polinom1);
Ppolinom sum (Ppolinom polinom1, Ppolinom polinom2);

bool eqv (Ppolinom polinom1, Ppolinom polinom2)
    {
    Ppolinom pol_q = polinom1, pol_r = polinom2;

    while (pol_q && pol_r)
        {
        if ((pol_q -> a == pol_r -> a) && (pol_q -> p == pol_r -> p ))
            {
            if (pol_q -> link == NULL && pol_r -> link == NULL)
                {
                return true;
                }
            else if (pol_q -> link == NULL && pol_r -> link != NULL)
                {
                return false;
                }
            else if (pol_q -> link != NULL && pol_r -> link == NULL)
                {
                return false;
                }
            else
                {
                pol_q = pol_q -> link;
                pol_r = pol_r -> link;
                }
            }
        else
            {
            return false;
            }
        }

    return true;
    }


double res (Ppolinom polinom1, int x)
    {
    Ppolinom pol_q = polinom1;
    double sum = 0;

    while (pol_q)
        {
        sum += (pol_q -> a) * (pow (x, (pol_q -> p)));
        }

    return sum;
    }

void out (Ppolinom polinom1, char v)
    {
    Ppolinom pol_q = polinom1;

    while (pol_q)
        {
        std::cout << pol_q -> a  << v <<"^"<< pol_q -> p << "\n";
        pol_q = pol_q-> link;
        }
    }

Ppolinom dif (Ppolinom polinom1)
    {
    Ppolinom H = polinom1;
    Ppolinom H_d = NULL;
    H_d = new polinom;

    Ppolinom H_p = H_d;
    H_p -> link = NULL;

    while (polinom1)
        {
        if (polinom1 -> p > 0)
            {
            H_p -> a = (polinom1 -> a) * (polinom1 -> p);
            H_p -> p = (polinom1 -> p) - 1;

            //std::cout << (polinom1 -> a) << " " << (H_p -> a) << '\n';
            }

        if (polinom1 -> link != NULL)
            {
            polinom1 = polinom1 -> link;

            H_p -> link = new polinom;
            H_p = H_p -> link;
            H_p -> link = NULL;
            }
        else
            {
            H_p -> link = NULL;

            break;
            }
        }


    return H_d;
    }


Ppolinom sum(Ppolinom polinom1, Ppolinom polinom2)
    {
    if (polinom1 == NULL) {std::cout << "impasibl"; return NULL;}

    if (polinom2 == NULL) {std::cout << "impasibl"; return NULL;}


    Ppolinom polinom3 = NULL;
    polinom3 = new polinom;
    polinom3 -> link = NULL;

    Ppolinom pol_p = polinom1;
    Ppolinom pol_q = polinom2;
    Ppolinom pol_r = polinom3;

    while (pol_p)
        {
        pol_r -> a = pol_p -> a;
        pol_r -> p = pol_p -> p;
        pol_r -> link = NULL;

        if (pol_p -> link != NULL)
            {
            pol_p = pol_p -> link;

            pol_r -> link = new polinom;
            pol_r = pol_r -> link;
            pol_r -> link = NULL;
            }
        else
            {
            break;
            }
        }
    pol_r = polinom3; //возвращение к истокам

    int tmp_p = 0;

    Ppolinom tmp_link = NULL;


    while (pol_q)
        {
        tmp_p = pol_q -> p;

        while (pol_r)
            {
            if (pol_r -> link != NULL && (pol_r -> link -> p > pol_q -> p))
                {
                pol_r = pol_r -> link;
                }
            else
                {
                break;
                }
            }
        if (pol_r -> link == NULL)
            {
            //std::cout << "AAAAUCH  ";

            pol_r -> link = new polinom;

            pol_r -> p = tmp_p;

            pol_r -> a = pol_q -> a;

            pol_r -> link = NULL;
            }
        else if (pol_r -> link -> p == tmp_p)
            {
            //std::cout << "OOOOOU" << '\n';

            pol_r -> link -> a += pol_q -> a;

            //std::cout << ( r -> link -> a) << "  " <<  (q -> a) << '\n';

            if (pol_r -> link -> a == 0)
                {
                tmp_link = pol_r -> link -> link;

                delete pol_r -> link;

                pol_r -> link = tmp_link;
                }
            }
        else if (pol_r == polinom3)
            {
            tmp_link = polinom3;
            polinom3 = new polinom;
            pol_r = polinom3;

            pol_r -> link = tmp_link;

            pol_r -> p = tmp_p;
            pol_r -> a = pol_q -> a;

            }
        else if (pol_r -> link -> p < tmp_p)
            {
            //std::cout << "EEEEH";

            tmp_link = pol_r -> link;

            pol_r -> link = new polinom;
            pol_r -> link -> link = tmp_link;

            pol_r -> link -> p = tmp_p;
            pol_r -> link -> a = pol_q -> a;
            }


        pol_r = polinom3;
        pol_q = pol_q -> link;
        }

    return polinom3;
    }
