//Cameron Calderon, Nisa Phelps, Serena Rampersad
//We start from the bottom and we build up to matricies that fit the values n,r,c.
//We pass the different matricies through base cases
//Then, we sum up the instances that dont have the base case and sum up their dependencies
// Finally, it returns the total number of vaild states that the chomp game has given n,r,c.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

int IterativeChomp(int n, int r, int c);

using namespace std;

int main()
{
    string line;
    ifstream myfile("input.txt");
    ofstream myfile2("output.txt");
    if (myfile.is_open() && myfile2.is_open())
    {
        string p;
        getline(myfile, p);
        cout << p << endl;
        while (getline(myfile, line))
        {
            istringstream ss(line);

            int n, r, c;

            ss >> n >> r >> c;
            cout << n << " " << r << " " << c << " " << endl;

            int var;
            var = IterativeChomp(n, r, c);
            cout << "Copying to output.txt: " << var << endl;
            myfile2 << var << endl;
        }
        myfile.close();
        myfile2.close();
    }
    else
        cout << "Unable to open file";

    return 1;
}

int IterativeChomp(int n, int r, int c)
{
    int C[100][100][100] = {{{0}}};
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= r; j++)
            for (int k = 0; k <= c; k++)
                if (j == 0 || k == 0)
                    C[i][j][k] = 0;
                else if (i == 1)
                {
                    C[i][j][k] = 1;
                }
                else if (i == (j * k))
                {
                    C[i][j][k] = 1;
                }
                else if (i > (j * k))
                    C[i][j][k] = 0;
                else
                {
                    int rows = j - 1;
                    int columns;
                    while (rows >= 0) // Going through all the rows
                    {
                        columns = 0;
                        while (columns != k) //not at max number of columns
                        {
                            C[i][j][k] += C[i - columns][rows][columns];
                            columns += 1;
                        }
                        rows -= 1;
                    }
                }
    return C[n][r][c];
}
