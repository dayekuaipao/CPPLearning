#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
struct Matf
{
    float* data;
    int rows;
    int cols;
};

struct Matd
{
    double* data;
    int rows;
    int cols;
};

bool multiplyf(const Matf& a,const Matf& b,Matf &c)
{
    if(a.cols!=b.rows)
        return false;
    c.data = (float*)calloc(a.rows*b.cols,sizeof(float));
    c.rows = a.rows;
    c.cols = b.cols;
    for(int i=0;i<c.rows;i++)
    {
        for(int j=0;j<c.cols;j++)
        {
            for(int k=0;k<a.cols;k++)
                c.data[i*c.rows+j] += a.data[i*a.rows+k]*b.data[k*b.cols+j];
        }
    }
    return true;
}

bool multiplyd(const Matd& a,const Matd& b,Matd &c)
{
    if(a.cols!=b.rows)
        return false;
    c.data = (double*)calloc(a.rows*b.cols,sizeof(double));
    c.rows = a.rows;
    c.cols = b.cols;
    for(int i=0;i<c.rows;i++)
    {
        for(int j=0;j<c.cols;j++)
        {
            for(int k=0;k<a.cols;k++)
                c.data[i*c.rows+j] += a.data[i*a.rows+k]*b.data[k*b.cols+j];
        }
    }
    return true;
}

bool readFromFiled(const char* path,Matd& mat)
{
    FILE *fp = fopen(path,"r");
    if(fp==NULL)
    {
        return false;
    }
    char line[1000]; 

    int rows = 0;
    int cols = 0; 
    double data[10000];

    while(fgets(line,1000,fp)!=NULL)
    {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';
        char *token = strtok(line,",");
        int tmpRows = 0;
        while(token!=NULL)
        {
            data[rows*cols+tmpRows]= atof(token);
            tmpRows++;
            token = strtok(NULL,",");
        }
        if(rows==0)
        {
            rows = tmpRows;
        }
        else if(tmpRows!=rows)
        {
            return false;
        }
        cols++;
    }
    mat.data = (double*)malloc(rows*cols*sizeof(double));
    for(int i=0;i<rows*cols;i++)
    {
        mat.data[i] = data[i];
    }
    mat.rows = rows;
    mat.cols = cols;
    fclose(fp);
    return true;
}

bool readFromFilef(const char* path,Matf& mat)
{
    FILE *fp = fopen(path,"r");
    if(fp==NULL)
    {
        return false;
    }
    char line[1000]; 

    int rows = 0;
    int cols = 0; 
    float data[10000];

    while(fgets(line,1000,fp)!=NULL)
    {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';
        char *token = strtok(line,",");
        int tmpRows = 0;
        while(token!=NULL)
        {
            data[rows*cols+tmpRows]= (float)atof(token);
            tmpRows++;
            token = strtok(NULL,",");
        }
        if(rows==0)
        {
            rows = tmpRows;
        }
        else if(tmpRows!=rows)
        {
            return false;
        }
        cols++;
    }
    mat.data = (float*)malloc(rows*cols*sizeof(float));
    for(int i=0;i<rows*cols;i++)
    {
        mat.data[i] = data[i];
    }
    mat.rows = rows;
    mat.cols = cols;
    fclose(fp);
    return true;
}

bool saveToFilef(const char* path,Matf mat)
{
    FILE *fp = fopen(path,"w");
    if(fp==NULL)
    {
        return false;
    }
    for(int i=0;i<mat.rows;i++)
    {
        for(int j=0;j<mat.cols;j++)
        {
            fprintf(fp,"%f ",mat.data[i*mat.cols+j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    return true;
}

bool saveToFiled(const char* path,Matd mat)
{
    FILE *fp = fopen(path,"w");
    if(fp==NULL)
    {
        return false;
    }
    for(int i=0;i<mat.rows;i++)
    {
        for(int j=0;j<mat.cols;j++)
        {
            fprintf(fp,"%f ",mat.data[i*mat.cols+j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    return true;
}

void printMatd(const Matd& mat)
{
    printf("rows: %d, cols: %d\n",mat.rows,mat.cols);
    for(int i=0;i<mat.rows;i++)
    {
        for(int j=0;j<mat.cols;j++)
        {
            printf("%f ",mat.data[i*mat.cols+j]);
        }
        printf("\n");
    }
}

void printMatf(const Matf& mat)
{
    printf("rows: %d, cols: %d\n",mat.rows,mat.cols);
    for(int i=0;i<mat.rows;i++)
    {
        for(int j=0;j<mat.cols;j++)
        {
            printf("%f ",mat.data[i*mat.cols+j]);
        }
        printf("\n");
    }
}

int main()
{
    Matf af,bf,cf;
    readFromFilef("./a.txt",af);
    readFromFilef("./b.txt",bf);
    multiplyf(af,bf,cf);
    printMatf(af);
    printMatf(bf);
    printMatf(cf);
    saveToFilef("./cf.txt",cf);

    Matd ad,bd,cd;
    readFromFiled("./a.txt",ad);
    readFromFiled("./b.txt",bd);
    multiplyd(ad,bd,cd);
    printMatd(ad);
    printMatd(bd);
    printMatd(cd);
    saveToFiled("./cd.txt",cd);
}