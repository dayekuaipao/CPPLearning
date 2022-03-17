#include"mat.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline DATA_TYPE getElement(const Mat* mat,size_t row,size_t col)
{
    return mat->data[row*mat->cols+col];
}

inline DATA_TYPE* getElementPointer(Mat* mat,size_t row,size_t col)
{
    return &(mat->data[row*mat->cols+col]);
}

inline const DATA_TYPE* getConstElementPointer(const Mat* mat,size_t row,size_t col)
{
    return &(mat->data[row*mat->cols+col]);
}

Mat createMat(size_t rows,size_t cols)
{
    Mat mat;
	mat.rows = rows;
	mat.cols = cols;
	mat.data = (DATA_TYPE*)calloc(rows*cols,sizeof(DATA_TYPE));
    assert(mat.data!=NULL);
    return mat;
}

void deleteMat(Mat* mat)
{
	
    mat->cols = 0;
    mat->rows = 0;
    free(mat->data);
    mat->data=NULL;
}

void copyMat(const Mat* a,Mat* b)
{
	b->cols = a->cols;
	b->rows = a->rows;
	b->data = (DATA_TYPE*)realloc(b->data,a->cols*a->rows*sizeof(DATA_TYPE));
    assert(b->data!=NULL);
	memcpy(b->data, a->data, a->cols*a->rows*sizeof(DATA_TYPE));
}

Mat readFromFile(const char* path)
{
    FILE *fp = fopen(path,"r");
    assert(fp!=NULL);
    char line[MAX_LENGTH]; 

    size_t rows = 0;
    size_t cols = 0; 
    DATA_TYPE* data = (DATA_TYPE*)malloc(MAX_SIZE*sizeof(DATA_TYPE));
    while(fgets(line,MAX_LENGTH,fp)!=NULL)
    {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';
        char *token = strtok(line,",");
        size_t tmpCols = 0;
        while(token!=NULL)
        {
            data[rows*cols+tmpCols]= (DATA_TYPE)atof(token);
            tmpCols++;
            token = strtok(NULL,",");
        }
        if(rows==0)
        {
            cols = tmpCols;
        }
        assert(tmpCols==cols);
        rows++; 
    }
    Mat mat = createMat(rows, cols);
    assert(mat.data!=NULL);
    memcpy(mat.data, data, rows*cols*sizeof(DATA_TYPE));
    free(data);
    fclose(fp);
    return mat;
}

void saveToFile(const char* path,const Mat* mat)
{
    FILE *fp = fopen(path,"w");
    assert(fp!=NULL);
    for(size_t i=0;i<mat->rows;i++)
    {
        for(size_t j=0;j<mat->cols;j++) 
        {
            fprintf(fp,"%f,",getElement(mat, i, j));
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}

void printMat(const Mat* mat)
{
    for(size_t i=0;i<mat->rows;i++)
    {
        for(size_t j=0;j<mat->cols;j++)
        {
            printf("%f,",getElement(mat, i, j));
        }
        printf("\n");
    }
    printf("rows: %zu, cols: %zu\n",mat->rows,mat->cols);
}

Mat multiply(const Mat* a,const Mat* b)
{
    assert(a!=NULL&&b!=NULL);
    assert(a->data!=NULL&&b->data!=NULL);
    assert(a->cols==b->rows);
    Mat c = createMat(a->rows, b->cols);
    for(size_t i=0;i<c.rows;i++)
    {
        for(size_t j=0;j<c.cols;j++)
        {
            for(size_t k=0;k<a->cols;k++)
                (*getElementPointer(&c, i, j)) += getElement(a, i, k)*getElement(b, k, j);
        }
    }
    return c;
}