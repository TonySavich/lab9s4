#include <iostream>
#include <fstream>

int const N = 5;
int main()
{
    int mas[N][N];


    std::ifstream in("in.txt");
    if (in.is_open())
    {
        while (!in.eof()) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {

                    in >> mas[i][j];
                }
            }


        }


    }
    in.close();
    
    int dano;

    std::cin >> dano;
    dano = dano - 1;


    int path[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            path[i][j] = INT_MAX;
        }
    }
    path[0][dano] = 0;

    int counter = 1;
    int dopmas[N] , t;
    t = 0;

    while (counter < N) {

        for (int i = 0; i < N; i++) {
            path[counter][i] = path[counter - 1][i];
            if (path[counter][i] < INT_MAX) {
                dopmas[t] = i;
                t++;
            }
        }

        


        for (int j = 0; j < t; j++) {
            for (int i = 0; i < N; i++) {          
                    if (mas[dopmas[j]][i] != 0) {
                        if (path[counter][i] > mas[dopmas[j]][i] + path[counter][dopmas[j]]) {
                            path[counter][i] = mas[dopmas[j]][i] + path[dopmas[j]][dopmas[j]];

                        }                  
                }

            }
        }


        counter++;


        t = 0;




    }
    std::cout << std::endl;
    for (int i = 0; i < N; i++) {
        if (i == dano) {
            path[counter - 1][i] = 0;
        }
        if (path[counter - 1][i] == INT_MAX) {
            std::cout << i + 1 << " " << "No" << std::endl;
        }
        else {
            std::cout << i + 1 << " " << path[counter - 1][i] << std::endl;
        }
    }

}
