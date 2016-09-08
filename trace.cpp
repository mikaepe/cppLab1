// A very errornous program!
// C Marcus Holm
//  Adapted by Michael Hanke


#include <cstdlib>
#include <cmath>
#include <iostream>

double** initialization(int);
double* fill_vectors(double*, int);
void print_matrix(double** , int);
double trace (double** , int); // <- double* trace(...

using namespace std; //ADDED LINE

// The main program.
int main()
{
  int i, n; // <- i, j, n
  double **matrix;
  double sum ; //REMOVED pointer

  cout << endl << "Enter the Dimension for a square matrix: " << flush;
  cin >> n;
  matrix = initialization(n);
  for(i = 0 ; i < n ; i++) // <- i=1; i < n....
      matrix[i] =  fill_vectors(matrix[i] , n);
  sum = trace(matrix , n);
  print_matrix(matrix , n);
  cout << endl << "Sum of the diagonal elements are: " << sum << endl; //add endl at end
  return 0;
}


// The initialization routine is supposed to allocate memory for
// a n-by-n matrix and return a pointer to the allocated matrix.
double** initialization(int n)

{
  int i;
  double** matrix ;
  matrix = (double **) calloc(n , sizeof(double **)); // ADDED (double **) 'a cast'
  for(i=0 ; i< n ; ++i)
    matrix[i] = (double *) calloc(n , sizeof(double *)); // ADDED (double *) 'a cast'
  return (matrix);
}

// The fill_vector routine is supposed to fill a given vector with
// random numbers ranging from -10 to 10.
double* fill_vectors(double* vec , int n)
{
  int i ;
  for(i = 0 ; i < n ; i++)
    vec[i] = rand() % 21 - 10 ; //  <- 21, % 10: [0,9]. % 10 + 1: [1,10]
  return vec;
}

// The print_matrix routine is supposed to print out the elements of
// a given matrix in a nice format using printf.
void print_matrix(double** matrix , int n)

{
  int i,j;
  for (i= 0 ; i< n ; i++)
    {
    for(j = 0 ; j < n ; j++)
	cout << matrix[i][j] << ", ";
    cout << endl;
    }
}

// The trace routine is supposed to return the sum of the diagonal
// elements if a given matrix.
double trace (double** matrix , int n) // <- double*
{
  int i ;
  double sum = 0.0;
  for(i=0 ; i < n ; i++) //<- i = 1, i<=n; i++
    sum+=matrix[i][i];
  return sum; // <- &sum
}
