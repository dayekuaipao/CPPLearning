#include <stdio.h>
#include <time.h>
#include "mat.h"
int main(int argc, char const *argv[])
{   
    Mat aa;
    Mat bb;
    aa = createMat(4000,5000);
    printMat(&aa);
    bb = createMat(5000,3000);
    printMat(&bb);
    for(int i=0;i<5000;i++)
    {
        for(int j=0;j<4000;j++)
            aa.data[j*5000+i] = j*5+i;
        for(int j=0;j<3000;j++)
            bb.data[i*3000+j] = i*3+j;
    }
    saveToFile("./a.txt", &aa);
    saveToFile("./b.txt", &bb);
    Mat a;
    Mat b;
    a = readFromFile("./a.txt");
    printMat(&a);
    b = readFromFile("./b.txt");
    printMat(&b);
    clock_t t1 = clock();
	Mat c;
	c = multiply(&a,&b);
    clock_t t2 = clock();
    printMat(&c);
    printf("time = %lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);
    saveToFile("./c.txt",&c);
    deleteMat(&c);
	return 0;
}