#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <iomanip>
using namespace std;

void display(int *array,int size)
{
    for (int i=0;i<size; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}
void insertion_sort(int size,int *array)
{
    int x,i,j;
    for(i=0;i<size;i++) {
        x=array[i];
        j=i;
        while(j>0 && array[j-1]>x){
            array[j]=array[j-1];
            j--;
        }
        array[j]=x;
    }

}
void bubble_sort(int size,int *array){
    int i,j;
    for(i=0;i<size-1;i++)
        for(j=0;j<size-i-1;j++)
        if(array[j]>array[j+1])
        swap(array[j],array[j+1]);
}
void bubble_sort_opti(int *array, int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (array[j] > array[j+1])
        {
           swap(array[j], array[j+1]);
           swapped = true;
        }
     }


     if (swapped == false)
        break;
   }
}
void selection_sort(int size,int *array)
{
    int i,j,mini;
    for(i=0;i<size-1;i++)
    {
        mini=i;
        for(j=i+1;j<size;j++)
            if(array[j]<array[mini])
            mini=j;
        swap(array[mini],array[i]);
    }
}
void merge(int *array,int l,int m,int r)
{
    int i,j,k,nl,nr;
    nl=m-l+1;
    nr=r-m;
    int larr[nl],rarr[nr];
    for(i=0;i<nl;i++)
        larr[i]=array[l+i];
    for(j=0;j<nr;j++)
        rarr[j]=array[m+1+j];
    i=0; j=0; k=1;
    while(i<nl && j<nr)
    {
        if(larr[i] <= rarr[j])
        {
            array[k]=larr[i];
            i++;
        }
        else{array[k]=rarr[j];
        j++;
        }
        k++;
    }
    while(i<nl)
    {
        array[k]=larr[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        array[k]=rarr[j];
        j++;
        k++;
    }
}
void merge_sort(int *array,int l,int r)
{
    int m;
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(array,l,m);
        merge_sort(array,m+1,r);
        merge(array,l,m,r);
    }
}


int partition(int *array,int low,int high)
{
    int pivot=array[high];
    int i=(low-1);
    for(int j=low;j<=high-1;j++)
    {
        if(array[j]<pivot)
        {
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[high]);
    return(i+1);
}
void quick_sort(int array[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(array,low,high);
        quick_sort(array,low,pi-1);
        quick_sort(array,pi+1,high);
    }
}
int main()
{
  srand(time(NULL));
  int l,buf;
  cout<<"The lenght of the array is: ";
  cin>>l;
  int rand_arr[l],asc_arr[l],desc_arr[l];
  cout<<"Unsorted array: ";
  for(int i=0;i<l;i++){
    rand_arr[i]=rand()%10000;

    cout<<rand_arr[i]<<" ";

  }
    cout<<endl;
    cout<<"Ascending array: ";
   for(int j=0;j<l;j++)
   {
       asc_arr[j]=j;
       cout<<asc_arr[j]<<" ";


   }
   cout<<endl;
   cout<<"Descending array: ";
   for(int k=0;k<l;k++)
   {
       desc_arr[k]=l-k-1;
       cout<<desc_arr[k]<<" ";
   }
   cin>>buf;
   switch(buf){
  case 0: {clock_t start0=clock();
   insertion_sort(l,rand_arr);
   clock_t end0=clock();
   cout<<"Running time for insertion sort random array: "<<fixed<<double(end0-start0)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
  }
  case 1:{ clock_t start1=clock();
   insertion_sort(l,desc_arr);
   clock_t end1=clock();
   cout<<"Running time for insertion sort descending array: "<<fixed<<double(end1-start1)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
  }
   case 2:{clock_t start2=clock();
   insertion_sort(l,asc_arr);
   clock_t end2=clock();
   cout<<"Running time for insertion sort ascending array: "<<fixed<<double(end2-start2)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }v
   case 3:{ clock_t start3=clock();
   bubble_sort(l,rand_arr);
   clock_t end3=clock();
   cout<<"Running time for bubble sort random array: "<<fixed<<double(end3-start3)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 4:{clock_t start4=clock();
   bubble_sort(l,asc_arr);
   clock_t end4=clock();
   cout<<"Running time for bubble sort ascending array: "<<fixed<<double(end4-start4)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 5:{clock_t start5=clock();
   bubble_sort(l,desc_arr);
   clock_t end5=clock();
   cout<<"Running time for bubble sort descending array: "<<fixed<<double(end5-start5)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 6:{clock_t start6=clock();
   selection_sort(l,rand_arr);
   clock_t end6=clock();
   cout<<"Running time for selection sort random array: "<<fixed<<double(end6-start6)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 7:{clock_t start7=clock();
   selection_sort(l,asc_arr);
   clock_t end7=clock();
   cout<<"Running time for selection sort ascending array: "<<fixed<<double(end7-start7)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 8:{clock_t start8=clock();
   selection_sort(l,desc_arr);
   clock_t end8=clock();
   cout<<"Running time for selection sort descending array: "<<fixed<<double(end8-start8)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 9:{clock_t start9=clock();
   merge_sort(rand_arr,0,l-1);
   clock_t end9=clock();
   cout<<"Running time for merge sort random array: "<<fixed<<double(end9-start9)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 10:{clock_t start10=clock();
   merge_sort(asc_arr,0,l-1);
   clock_t end10=clock();
   cout<<"Running time for merge sort ascending array: "<<fixed<<double(end10-start10)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 11:{clock_t start11=clock();
   merge_sort(desc_arr,0,l-1);
   clock_t end11=clock();
   cout<<"Running time for merge sort descending array: "<<fixed<<double(end11-start11)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   
   case 15:{clock_t start15=clock();
   quick_sort(rand_arr,0,l-1);
   clock_t end15=clock();
   cout<<"Running time for quick sort random array: "<<fixed<<double(end15-start15)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 16:{clock_t start16=clock();
   quick_sort(asc_arr,0,l-1);
   clock_t end16=clock();
   cout<<"Running time for quick sort ascending array: "<<fixed<<double(end16-start16)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 17:{clock_t start17=clock();
   quick_sort(desc_arr,0,l-1);
   clock_t end17=clock();
   cout<<"Running time for quick sort descending array: "<<fixed<<double(end17-start17)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 18:{clock_t start18=clock();
   bubble_sort_opti(rand_arr,l);
   clock_t end18=clock();
   cout<<"Running time for quick sort random array: "<<fixed<<double(end18-start18)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 19:{clock_t start19=clock();
   bubble_sort_opti(asc_arr,l);
   clock_t end19=clock();
   cout<<"Running time for quick sort ascending array: "<<fixed<<double(end19-start19)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }
   case 20:{clock_t start20=clock();
   bubble_sort_opti(desc_arr,l);
   clock_t end20=clock();
   cout<<"Running time for quick sort descending array: "<<fixed<<double(end20-start20)/double(CLOCKS_PER_SEC)<<setprecision(12)<<endl;
   break;
   }

}
