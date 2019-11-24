/*EE242 2nd PROJECT GAUSSIAN ELIMINATION WITH COMPLETE PIVOTING
Name of the Student: Hýdýr Yüzügüzel
Student #:2008401159
e-mail: hidiryuzuguzel@boun.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//swap function swaps two number
void swap(float *i, float *j){
     float temp;
     temp=*i;
     *i=*j;
     *j=temp;
}
//swapOrder function swaps two integers
void swapOrder(int *i, int *j){
     int temp;
     temp=*i;
     *i=*j;
     *j=temp;
}
int main(int argc, char *argv[])
{
  FILE *infile1,*infile2;
  int row=0,column=0,n,i=0,j=0,k=0,l=0,tempi=0,tempj=0,t=0,N_add=0,N_mult=0;
  float element,pivot,multip,multip2,c;
  float *arr1,*arr2,*x;
  int *order;
  char ch;
  
  	infile1=fopen(argv[1],"r");
  	infile2=fopen(argv[2],"r");
         //The loop determines the number of items in the given matrix
         while( fscanf(infile1,"%f",&c)!=EOF){
            column++;
         }
          
    fclose(infile1);
    fclose(infile2);
    column=sqrt(column);
    row=column;
    n=row*column;
    
    arr1=(float*)malloc(n*sizeof(float));
    x=(float*)malloc(n*sizeof(float));
    arr2=(float*)malloc(row*sizeof(float));
    order=(int*)malloc(row*sizeof(int));
    // The loop equates the element with index
    for(i=0;i<row;i++){
        order[i]=i;      
    }
    infile1=fopen(argv[1],"r");
    infile2=fopen(argv[2],"r");
    i=0;
        //The loop reads the elements of the given matrix into the array arr1
         while(fscanf(infile1,"%f",&element)!=EOF){
              arr1[i]=element;
              i++;
         }

         i=0;
         //The loop reads the elements of the vector into the array arr2
         while(fscanf(infile2,"%f",&element)!=EOF){
              arr2[i]=element;
              ++i;
         }
        // The three for loop makes the given matrix Uppertriangular
         for(k=0;k<row-1;k++){
              element=arr1[column*k+k];
              tempi=k;
              tempj=k;
              for(i=k;i<column;i++){
                   for(j=k;j<row;j++){
                        if(abs(arr1[column*i+j])>abs(element)){
                             element=arr1[column*i+j];
                             tempi=i;
                             tempj=j;
                             
                        }
                       
                   }
                   
              }
             
              //The loop makes row exchange
              for(l=0;l<column;l++){
                   swap(&(arr1[column*tempi+l]),&(arr1[column*k+l]));
              }
              swap(&(arr2[tempi]),&(arr2[k]));
              //The loop makes column exchange
              for(l=0;l<row;l++){
                   swap(&(arr1[column*l+tempj]),&(arr1[column*l+k]));
              }
              swapOrder(&(order[tempj]),&(order[k]));
              pivot=arr1[column*k+k];
              for(t=k+1;t<row;t++){
                   multip=arr1[column*t+k]/arr1[column*k+k];
                   N_mult++;
                   for(j=k;j<column;j++){
                        arr1[column*t+j]=arr1[column*t+j]-multip*arr1[column*k+j];
                        N_add++;
                        N_mult++;
                   } 
                   arr2[t]-=multip*arr2[k];            
                   N_add++;
                   N_mult++;
              }
         
         } 
     
       //The loop makes back substitution
       for(j=row-1;j>=0;j--){
              //The if controls the singularity condition
              if(arr1[j*row+j]==0){
                 printf("The matrix is singular!");
                 system("PAUSE");
                 return -1;
              }
              x[(order[j])]=arr2[j]/arr1[j*row+j]; 
              N_mult++;
              for(i=0;i<j;i++){
                 arr2[i]-=arr1[i*row+j]*x[(order[j])];     
                 N_add++;
                 N_mult++;
              } 
              
         }

        //The loop prints the solution
        for(i=0;i<row;i++){
            printf("x[%d]= %f\n",i,x[i]);    
        }
         printf("The number of multiplication:%d The number of addition:%d ",N_mult,N_add);

    fclose(infile1);
    fclose(infile2);
                                
	
  system("PAUSE");	
  return 0;
}
