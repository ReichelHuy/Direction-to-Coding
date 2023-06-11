#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL)); // Thiết lập seed cho hàm random

    for (int i = 1; i <= 10; i++) {
        char filename[50];
        sprintf(filename, "CSDL%d.txt", i);

        FILE *outfile = fopen(filename, "w");

        if (!outfile) {
            cerr << "Không thể tạo file " << filename << endl;
            exit(1);
        }

        for (int j = 0; j < 1000000; j++) {
            fprintf(outfile, "%d\n", rand() % 1000000);
        }

        fclose(outfile);
    }

    return 0;
}