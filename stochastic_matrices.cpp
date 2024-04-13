// Miguel Marines
// Stochastic Matrices

// Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

// Namespace
using namespace std;

// Menu function
void print_menu()
{
    cout<<"\n\n\nMenu:";
    cout<<"\n1) Create matrix";
    cout<<"\n2) Check if the matrix is stochastic.";
    cout<<"\n3) Calculate the probability from going to one state to another in n steps.";
    cout<<"\n4) Calculate the long-term state (steady) of the matrix.";
    cout<<"\n5) Identify if the matrix is regular or not.";
    cout<<"\n6) Create automatically a 3 X 3 random stochastic matrix.";
    cout<<"\n7) Print matrix";
    cout<<"\n8) Exit program";
    cout<<"\nSelect option: ";
}

// Round Function
float round(double number)
{
    float new_number = (int)(number * 1000000 + .5);
    return (float)new_number / 1000000;
}

// Main
int main()
{
    // Variable to control de size of the matrix.
    int N;
    
    // Creation of the matrix.
    float matrix[10][10];

    // Variables that serve as flags.
    int menu_option;
    int flag_new_matrix = 0;
    
    cout<<"Menu:";
    cout<<"\n1) Create matrix";
    cout<<"\n6) Create automatically a 3 X 3 random stochastic matrix.";
    cout<<"\nSelect option: ";
    cin>>menu_option;
    
    if(menu_option != 1 && menu_option != 6)
    {
        cout<<"\nFirst you need to create a matrix.\n";
        menu_option = 1;
    }
    
    // Loop to keep the program running and display the menu.
    while(menu_option != 8)
    {
        // Option to create own squared matrix.
        if(menu_option == 1)
        {
            // Define the size of the matrix.
            cout<<"\nEnter the size of the matrix: ";
            cin>>N;
    
            // Enter the values of the matrix.
            for(int i = 0; i < N; i++)
            {
                cout<<"\n";
                for(int j = 0; j < N; j++)
                {
                    cout<<"Element ["<<i+1<<"]"<<"["<<j+1<<"]: ";
                    cin>>matrix[i][j];
                }
            }
            
            // Check if the matrix is stochastic.
            menu_option = 2;
        }
        // Option to check if a matrix is stochastic.
        if(menu_option == 2)
        {
            // Variables that serve as flags and counters.
            float sum_row = 0;
            int flag_negative_numbers = 0;
            
            // Loop to check if the matrix has negative numbers and the adittion of the rows.
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    sum_row = sum_row + matrix[i][j];
                    
                    if(matrix[i][j] < 0)
                    {
                        flag_negative_numbers = flag_negative_numbers + 1;
                    }
                }
            }
            
            // Prints the result if the matrix is not stochastic.
            if( ( ((sum_row / N) < 0.99) || ((sum_row / N) > 1 )) || (flag_negative_numbers != 0))
            {
                cout<<"\n\nThe matrix is NOT STOCHASTIC.";
                cout<<"\n\nMatrix: \n";   
                for (int i = 0 ; i < N ; i++ )
                {
                    for (int j = 0 ; j < N ; j++ )
                    {
                        cout<<matrix[i][j]<<" ";
                    }
                    cout<<"\n";
                }
                cout<<"\nThe matrix is not squared or the entries of the matrix are negative or the sum of the entries of each row is not 1.\n";
                //cout<<"\nAddition of the row: "<<(sum_row/N);
                //cout<<"\nNumber of negative elements: "<<flag_negative_numbers;
                flag_new_matrix = 1;
                menu_option = 1;
            }
            // Prints the result if the matrix is stochastic.
            else
            {
                cout<<"\n\nThe matrix is STOCHASTIC.";
                cout<<"\n\nMatrix: \n";   
                for (int i = 0 ; i < N ; i++ )
                {
                    for (int j = 0 ; j < N ; j++ )
                    {
                        cout<<matrix[i][j]<<" ";
                    }
                    cout<<"\n";
                }
                cout<<"\nThe matrix is squared.";
                cout<<"\nAll the entries of the matrix are nonnegative.";
                cout<<"\nThe sum of the entries of each row is 1.";
                flag_new_matrix = 0;
            }
        }
        // Option to calculate the probability from going to one state to another in n steps.
        if(menu_option == 3)
        {
            // Variable for the states and power.
            int initial_state;
            int final_state;
            int power;
            
            // Getting the values for the variables of the states and power.
            cout<<"\nEnter the number of the initial state: ";
            cin>>initial_state;
            cout<<"\nEnter the number of the destination state: ";
            cin>>final_state;
            cout<<"\nEnter the number of steps: ";
            cin>>power;
            
            // Auxiliary matrices.
            float product[N][N];
            float b[N][N];
            float c[N][N];
   
            // Fill of auxiliary matrices to not modify the original one.
            for(int i = 0; i < N; ++i)
            {
                for(int j = 0; j < N; ++j)
                {
                    b[i][j] = matrix[i][j];
                }
            }
    
            for(int i = 0; i < N; ++i)
            {
                for(int j = 0; j < N; ++j)
                {
                    c[i][j] = matrix[i][j];
                }
            }
   
            // Verify that the states and the power are valid.
            if(initial_state > N || initial_state < 1)
            {
                cout<<"\nNot valid initial state.";
            }
            else if(final_state > N || final_state < 1)
            {
                cout<<"\nNot valid final state.";
            }
            else if(power == 0 || power < 0)
            {
                cout<<"\nCannot find the probability of 0 or less than 0.";
            }
            
            // Computation in case that the power is 1.
            else if(power == 1)
            {
                for(int i = 0; i < N; ++i)
                {
                    for(int j = 0; j < N; ++j)
                    {
                        product[i][j] = c[i][j];
                    }
                }
        
                // Prints the result.
                cout<<"\nMatrix:"<<endl;
                for(int i = 0; i < N; ++i)
                {
                    for(int j = 0; j < N; ++j)
                    {
                        cout<<product[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                cout<<endl;
                cout<<"\nThe probability in decimals of going from state "<<initial_state<< " to "<<final_state<<" is: "<<product[initial_state - 1][final_state - 1];
                cout<<"\nThe probability in porcentage of going from state "<<initial_state<< " to "<<final_state<<" is: %"<<(product[initial_state - 1][final_state - 1] * 100);
            }
            // Computation in case that the power is greater  than 1.
            else
            {
                for(int i = 0; i < N; ++i)
                {
                    for(int j = 0; j < N; ++j)
                    {
                        product[i][j] = 0;
                    }
                }
    
                // Iteration the number of times according to the power.
                for(int x = 0; x < power - 1; x++)
                {
                    for(int i = 0; i < N; ++i)
                    {
                        for(int j = 0; j < N; ++j)
                        {
                            product[i][j] = 0;
                        }
                    }
    
                    for(int i = 0; i < N; ++i)
                    {
                        for(int j = 0; j < N; ++j)
                        {
                            for(int k = 0; k < N; ++k)
                            {
                                product[i][j] += b[i][k]*c[k][j];
                            }
                        }
                    }
        
                    for(int i = 0; i < N; ++i)
                    {
                        for(int j = 0; j < N; ++j)
                        {
                            c[i][j] = product[i][j];
                        }
                    }
                    
                    // Prints the result of the power.
                    cout<<"\n\nPower "<<(x + 2)<<" of the Matrix:"<<endl;
                    for(int i = 0; i < N; ++i)
                    {
                        for(int j = 0; j < N; ++j)
                        {
                            cout<<product[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    cout<<endl;
                    cout<<endl;
                }
                
                // Prints the result.
                cout<<"Matrix:"<<endl;
                for(int i = 0; i < N; ++i)
                {
                    for(int j = 0; j < N; ++j)
                    {
                        cout<<product[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                cout<<endl;
                cout<<"\nThe probability in decimals of going from state "<<initial_state<< " to "<<final_state<<" is: "<<product[initial_state - 1][final_state - 1];
                cout<<"\nThe probability in porcentage of going from state "<<initial_state<< " to "<<final_state<<" is: %"<<(product[initial_state - 1][final_state - 1] * 100);
            }
   
            flag_new_matrix = 0;            

        }
        // Option to calculate the long-term state (steady) of the matrix. 
        if(menu_option == 4)
        {
            // Variable to control the loops.
            int power = 100;
            int i, j, k;
            
            // Creation of auxilary matrices.
            float product[N][N];
            float b[N][N];
            float c[N][N];
   
            // Fill of the auxilary matrices.
            for(i = 0; i < N; ++i)
            {
                for(j = 0; j < N; ++j)
                {
                    b[i][j] = matrix[i][j];
                }
            }
    
            for(i = 0; i < N; ++i)
            {
                for(j = 0; j < N; ++j)
                {
                    c[i][j] = matrix[i][j];
                }
            }
   
            for(i = 0; i < N; ++i)
            {
                for(j = 0; j < N; ++j)
                {
                    product[i][j] = 0;
                }
            }
    
            // Computation of the long-term of the martrix.
            for(int x = 0; x < power -1; x++)
            {
                for(i = 0; i < N; ++i)
                {
                    for(j = 0; j < N; ++j)
                    {
                        product[i][j] = 0;
                    }
                }
    
                for(i = 0; i < N; ++i)
                {
                    for(j = 0; j < N; ++j)
                    {
                        for(k = 0; k < N; ++k)
                        {
                            product[i][j] += b[i][k]*c[k][j];
                        }
                    }
                }
        
                for(i = 0; i < N; ++i)
                {
                    for(j = 0; j < N; ++j)
                    {
                        c[i][j] = product[i][j];
                    }
                }
            }
            
            int flag_unsteady = 0;
            // Check if the matrix is steady.
            for(i = 0; i < N; ++i)
            {
                for(j = 0; j < N - 1; ++j)
                {
                    float tmp1 = round(product[j][i]);
                    float tmp2 = round(product[j + 1][i]);
                    if (tmp1 != tmp2)
                    {
                        flag_unsteady = flag_unsteady + 1;
                    }
                }
                cout<<endl;
            }
            
            // Print the results.
            if(flag_unsteady == 0)
            {
                // Prints the steady matrix.
                cout<<"Steady State of the Matrix: "<<endl;
                for(i = 0; i < N; ++i)
                {
                    for(j = 0; j < N; ++j)
                    {
                        cout<<product[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<"\nThe matrix has a STEADY STATE, because the columns have the same values in the the different rows. (Steady vector)";
            }
            else
            {
                // Prints the long term matrix.
                cout<<"Long-Term State of the Matrix: "<<endl;
                for(i = 0; i < N; ++i)
                {
                    for(j = 0; j < N; ++j)
                    {
                        cout<<product[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<"\nThe matrix does NOT HAVE A STEADY STATE, because the columns have different values in the the different rows. (No steady vector)";
            }

            flag_new_matrix = 0;
        }
        // Option to identify if the matrix is regular.
        if(menu_option == 5)
        {
            // Raise the matrix to the 100 power.
            int power = 100;
            
            // Auxiliary matrices.
            float product[N][N];
            float b[N][N];
            float c[N][N];
            
            int i, j, k;
   
            // Fill auxilary matrices.
            for(i = 0; i < N; ++i)
            {
                for(j = 0; j < N; ++j)
                {
                    b[i][j] = matrix[i][j];
                }
            }
    
            for(i = 0; i < N; ++i)
            {
                for(j = 0; j < N; ++j)
                {
                    c[i][j] = matrix[i][j];
                }
            }
            
            for(i = 0; i < N; ++i)
            {
                for(j = 0; j < N; ++j)
                {
                    product[i][j] = 0;
                }
            }
    
            // Iteration the number of times according to the power.
            for(int x = 0; x < power - 1; x++)
            {
                for(i=0; i<N; ++i)
                {
                    for(j=0; j<N; ++j)
                    {
                        product[i][j] = 0;
                    }
                }
    
                for(i=0; i<N; ++i)
                {
                    for(j=0; j<N; ++j)
                    {
                        for(k=0; k<N; ++k)
                        {
                            product[i][j] += b[i][k]*c[k][j];
                        }
                    }
                }
        
                for(i = 0; i < N; ++i)
                {
                    for(j = 0; j < N; ++j)
                    {
                        c[i][j] = product[i][j];
                    }
                }
            }
    
            // Checks if the matrix is regular.
            int irregular_flag = 0;
            for(i=0; i<N; ++i)
            {
                for(j=0; j<N; ++j)
                {
                    if(product[i][j] <= 0)
                    {
                        irregular_flag = irregular_flag + 1;
                    }
                }
            }
            
            // Prints the result if the matrix is regular.
            if( irregular_flag == 0)
            {
                cout<<"\n\nThe matrix is REGULAR."<<endl;
                cout<<"\n100th Power of the Matrix: "<<endl;
                for(i=0; i<N; ++i)
                {
                    for(j = 0; j < N; ++j)
                    {
                        cout<<product[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<"\nSome power of the matrix contains all positive entries, (no cero or no negative numbers)."<<endl;
            }
            // Prints the result if the matrix is not regular.
            else
            {
                cout<<"\n\nThe matrix is NOT REGULAR."<<endl;
                cout<<"\n100th Power of the Matrix: "<<endl;
                for(i = 0; i < N; ++i)
                {
                    for(j = 0; j < N; ++j)
                    {
                        cout<<product[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<"\nSome power of the matrix does not contain all positive entries, (no cero or no negative numbers)."<<endl;
            }
            
            flag_new_matrix = 0;
        }
        // Option to create random matrices 3x3.
        if(menu_option == 6)
        {
            // Size of the matrix.
            N = 3;
            
            // Limit for the generation of the random numbers.
            float limit = 0.8;
        
            // Variable for the generated random numbers.
            float a1;
            float a2;
            float a3;
        
            float b1;
            float b2;
            float b3;
    
            float c1;
            float c2;
            float c3;
    
            // Generation random numbers.
            srand((unsigned int)time(NULL));
            a1 = (float(rand())/float((RAND_MAX)) * limit);
            b1 = (float(rand())/float((RAND_MAX)) * limit);
            c1 = (float(rand())/float((RAND_MAX)) * limit);
    
            // Fill of the matrix.
            matrix[0][0] = a1;
    
            a2 = (1 - a1) / 3;
            matrix[0][1] = a2;
   
            a3 = ((1 - a1) / 3) + ((1 - a1) / 3);
            matrix[0][2] = a3;
   
            b2 = (1 - b1) / 3;
            matrix[1][0] = b2;
   
   
            matrix[1][1] = b1;
   
            b3 = ((1 - b1) / 3) + ((1 - b1) / 3);
            matrix[1][2] = b3;
   
            c3 = ((1 - c1) / 3) + ((1 - c1) / 3);
            matrix[2][0] = c3;
   
            c2 = (1 - c1) / 3;
            matrix[2][1] = c2;
   
            matrix[2][2] = c1;

            // Prints the generated matrix.
            cout<<"\nMatrix: \n";   
            for (int i = 0 ; i < 3 ; i++ )
            {
                for (int j = 0 ; j < 3 ; j++ )
                {
                    cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
            
            flag_new_matrix = 0;
        }
        // Option to print the matrix.
        if(menu_option == 7)
        {
            // Prints the matrix.
            cout<<"\n\nMatrix: \n";   
            for (int i = 0 ; i < N ; i++ )
            {
                for (int j = 0 ; j < N ; j++ )
                {
                    cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
            flag_new_matrix = 0;
        }
        // Option to exit the program.
        if(menu_option == 8)
        {
            cout<<"\nProgram terminated properly.";
            return 0;
        }
        // Prints that the entered option of the menu is not valid.
        if((menu_option > 8) || (menu_option < 1))
        {
            cout<<"\nPlease enter a valid option.";
            flag_new_matrix = 0;
        }
        // Prints the menu.
        if(flag_new_matrix == 0)
        {
            print_menu();
            cin>>menu_option;
        }
    }

    // Ends the program.
    return 0;
}