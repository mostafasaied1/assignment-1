

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);
//======================================================================
//this function take two matrix and make sure rows and columns in two matrix are equal each other
//then return new matrix with combined process
matrix operator+  (matrix mat1, matrix mat2)
{
    matrix res;
    res.col=0;
    res.row=0;
    //res.data[res.row][res.col]=0;
    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
        cout<<"Not Same Size"<<endl;
        return res;
    }
    else
    {
        res.col=mat1.col;
        res.row=mat2.row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                res.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
            }
        }
        return res;
    }
}
//_______________________________________________________________________
//this function take two matrix and make sure rows and columns in two matrix are equal each other
//then return new matrix with  subtraction process
matrix operator-  (matrix mat1, matrix mat2)
{
    matrix res;
    res.col=0;
    res.row=0;
    //res.data[res.row][res.col]=0;
    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
        cout<<"Not Same Size"<<endl;
        return res;
    }
    else
    {

        res.col=mat1.col;
        res.row=mat2.row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                res.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
            }
        }
        return res;
    }
}
//________________________________________________________________________
//this function take two matrix and make sure columns in matrix1 is equal to rows in matrix2
//then return new matrix with  multiplication process
matrix operator*  (matrix mat1, matrix mat2)
{
    matrix res;
    res.col=0;
    res.row=0;
    //res.data[res.row][res.col]=0;
    if(mat1.col!=mat2.row)
    {
        cout<<"Dimensions Do Not Match"<<endl;
        return res;
    }
    else
    {
        res.col=mat2.col;
        res.row=mat1.row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                int temp=0;
                for(int x=0; x<mat1.col; x++)
                {
                    temp+=mat1.data[i][x]*mat2.data[x][j];
                }
                res.data[i][j]=temp;
            }

        }
        return res;
    }

}
//_________________________________________________________________________
//this function take only on matrix and scalar this add scalar to each element in matrix
// and return it
matrix operator+  (matrix mat1, int scalar)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]+=scalar;
        }
    }
    return mat1;
}
//_________________________________________________________________________
//this function take only on matrix and scalar this subtract scalar from each element in matrix
// and return it
matrix operator-  (matrix mat1, int scalar)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]-=scalar;
        }
    }
    return mat1;
}
//_________________________________________________________________________
//this function take only on matrix and scalar this multiply scalar to each element in matrix
// and return it
matrix operator*  (matrix mat1, int scalar)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]*=scalar;

        }
    }
    return mat1;
}
//=========================================================================
//this function take two matrix and make sure rows and columns in two matrix are equal each other
//then return new matrix with combined process
matrix operator+= (matrix& mat1, matrix mat2)
{
    matrix res;
    res.col=0;
    res.row=0;
    //res.data[res.row][res.col]=0;
    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
        cout<<"Not Same Size"<<endl;
        return res;
    }
    else
    {
        res.col=mat1.col;
        res.row=mat2.row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                res.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
            }
        }
        mat1=res;
        return mat1;
    }
}
//------------------------------------------------------------
//this function take two matrix and make sure rows and columns in two matrix are equal each other
//then return new matrix with  subtraction process
matrix operator-= (matrix& mat1, matrix mat2)
{
    matrix res;
    res.col=0;
    res.row=0;
    //res.data[res.row][res.col]=0;
    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
        cout<<"Not Same Size"<<endl;
        return res;
    }
    else
    {

        res.col=mat1.col;
        res.row=mat2.row;
        res.data=new int*[res.row];
        for(int i=0; i<res.row; i++)
        {
            res.data[i]=new int[res.col];
            for(int j=0; j<res.col; j++)
            {
                res.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
            }
        }
        mat1=res;
        return mat1;
    }
}
//--------------------------------------------------------------------------------
//this function take only on matrix and scalar this add scalar to each element in matrix
// and return it
matrix operator+= (matrix& mat, int scalar)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            mat.data[i][j]+=scalar;
        }
    }
    return mat;
}
//---------------------------------------------------------------------------------
//this function take only on matrix and scalar this subtract scalar from each element in matrix
// and return it
matrix operator-= (matrix& mat, int scalar)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            mat.data[i][j]-=scalar;
        }
    }
    return mat;
}
//--------------------------------------------------------------------------------
//this function take only one matrix and add 1 to each element of this matrix
void   operator++ (matrix& mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            ++mat.data[i][j];
        }
    }
}
//--------------------------------------------------------------------------------
//this function take only one matrix and subtract 1 from each element of this matrix
void   operator-- (matrix& mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            --mat.data[i][j];
        }
    }
}
//---------------------------------------------------------------------------------
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input
istream& operator>> (istream& in, matrix& mat)
{
    in>>mat.row>>mat.col;
    mat.data = new int* [mat.row];
    for(int i=0; i<mat.row; i++)
    {
        mat.data[i] = new int [mat.col];
        for(int j=0; j<mat.col; j++)
        {
            in>>mat.data[i][j];
        }
    }
    return in;
}
//=================================================================================
ostream& operator<< (ostream& out, matrix mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            out<<mat.data[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
//----------------------------------------------------------------------------------
//this function take two matrix and return true if two matrix identical and false if not
bool   operator== (matrix mat1, matrix mat2)
{
    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
        return false;
    }
    else
    {
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                if(mat1.data[i][j]!=mat2.data[i][j])
                {
                    return false;
                }
                else if((i==mat1.row-1)&&(j==mat1.col-1))
                {
                    return true;
                }
            }
        }
    }
}
//----------------------------------------------------------------------------------
//this function take two matrix and return True if not same
bool   operator!= (matrix mat1, matrix mat2)
{
    if((mat1.col!=mat2.col)||(mat1.row!=mat2.row))
    {
       // cout<<"*";
        return true;
    }
    else
    {

        for(int i=0; i<mat1.row; i++)
        {

            for(int j=0; j<mat1.col; j++)
            {

                if(mat1.data[i][j]!=mat2.data[i][j])
                {

                    cout<<mat1.data[i][j]<<" "<<mat2.data[i][j];
                    return true;
                }
                else if((i==mat1.row-1)&&(j==mat1.col-1))
                {

                    return false;
                }

            }
        }
    }
}
//----------------------------------------------------------------------------------
// this function take one matrix and return True if square matrix
bool   isSquare   (matrix mat)
{
    if(mat.col==mat.row)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//-----------------------------------------------------------------------------------
// this function take one matrix and  Return new matrix with the transpose
matrix transpose(matrix mat)
{
    matrix res;
    res.row=mat.col;
    res.col=mat.row;
    res.data = new int* [res.row];
    for(int i=0; i<res.row; i++)
    {
        res.data[i] = new int[res.col];
    }
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {

            res.data[j][i]=mat.data[i][j];

        }
    }
    return res;
}
//-----------------------------------------------------------------------------------
// this function take one matrix and return True if square and symmetric
bool   isSymetric (matrix mat)
{
    if(!isSquare(mat))
    {
        return false;
    }
    else
    {
        matrix temp=transpose(mat);
        if((temp==mat))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}
//-----------------------------------------------------------------------------------
//  this function take one matrix and returnTrue if square and identity
bool   isIdentity (matrix mat)
{
    if(!isSquare(mat))
    {
        return false;
    }
    else
    {
        for(int i=0; i<mat.row; i++)
        {
            for(int j=0; j<mat.col; j++)
            {
                if((i==j)&&(mat.data[i][j]!=1))
                {
                    return false;
                }
                else if((i!=j)&&(mat.data[i][j]!=0))
                {
                    return false;
                }
                else if((i==mat.row-1)&&(j==mat.col-1))
                {
                    return true;
                }
            }
        }
    }
}

//====================================================================================
int main()
{

    int data1 [] = {1,0,0,0,1,0,0,0,1};
    int data2 [] = {13,233,3,4,5,6,7,8,7,8,9,5};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [] = {4,1,1,-2};
    matrix mat1, mat2, mat3, mat4;
    createMatrix (3, 3, data1, mat1);
    createMatrix (3, 4, data2, mat2);
    createMatrix (4, 4, data3, mat3);
    createMatrix (2, 2, data4, mat4);

    cout <<transpose(mat2);

   /* if (isSquare(mat2)){
        cout<< "true";
    }else{
    cout<< "not true";
    }*/









    /* The next code will not work until you write the functions
      cout << mat1 << endl;
      cout << mat2 << endl;
      cout << mat3 << endl;

      cout << (mat1 + mat3) << endl << endl;
      cout << (mat3 + mat3) << endl << endl;

      ++mat1;
      cout << mat1 << endl;

      mat1+= mat3 += mat3;
      cout << mat1 << endl;
      cout << mat2 << endl;
      cout << mat3 << endl;
      // Add more examples of using matrix
      // .......
    */
    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}




