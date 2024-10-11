import java.io.*;
import java.util.*;
public class speedTestSorting
{
    // void main(int terms)
    void main()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of terms");
        int terms=sc.nextInt();
        int arr1[]=new int[terms];
        int arr2[]=new int[terms];
        int arr3[]=new int[terms];
        int arr4[]=new int[terms];
        int arr5[]=new int[terms];
        int i,t;
        for(i=0;i<terms;i++)
        {
            t=(int)(0+Math.random()*10000);
            arr1[i]=arr2[i]=arr3[i]=arr4[i]=arr5[i]=t;
        }
        //for(i=0;i<arr1.length;i++)
        //System.out.print(arr1[i]+"\t");
        System.out.println();
        quicksort_1(arr5,0,terms-1);
        mergesort_1(arr4,0,terms-1);
        insertionsort(arr3);
        selectionsort(arr2);
        bubblesort(arr1);
    }
    void bubblesort(int a[])
    {
        double a1=System.currentTimeMillis();
        int i,j,temp;
        for(i=0;i<a.length-1;i++)
        {
            for(j=0;j<a.length-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        double a2=System.currentTimeMillis();
        //for(i=0;i<a.length;i++)
        //System.out.print(a[i]+"\t");
        System.out.println();
        System.out.println("bubble sort time = "+(a2-a1)+" ms");
    }
    void selectionsort(int a[])
    {
        double a1=System.currentTimeMillis();
        int i,j,temp,pos;
        for(i=0;i<a.length-1;i++)
        {
            temp=a[i];
            pos=i;
            for(j=i+1;j<a.length;j++)
            {
                if(a[j]<temp)
                {
                    temp=a[j];
                    pos=j;
                }
            }
            a[pos]=a[i];
            a[i]=temp;        
        }
        double a2=System.currentTimeMillis();
        //for(i=0;i<a.length;i++)
        //System.out.print(a[i]+"\t");
        System.out.println();
        System.out.println("selection sort time = "+(a2-a1)+" ms");
    }
    void insertionsort(int a[])
    {
        double a1=System.currentTimeMillis();
        int i,j,temp;
        for(i=1;i<a.length;i++)
        {
            temp=a[i];
            for(j=i-1;j>=0 && a[j]>temp;j--)
            {
                a[j+1]=a[j];
            }
            a[j+1]=temp;
        }
        double a2=System.currentTimeMillis();
        //for(i=0;i<a.length;i++)
        //System.out.print(a[i]+"\t");
        System.out.println();
        System.out.println("insertion sort time = "+(a2-a1)+" ms");
    }
    void merge(int[] arr, int lb, int mid, int ub)
    {
        int s= ub-lb+1;
        int[] b = new int[s];
        int i,j,k=0;
        for(i=lb,j=mid+1;i<=mid && j<=ub;)
        {
            if(arr[i]<=arr[j])
            {
                b[k]=arr[i];
                k++;
                i++;
            }
            else
            {
                b[k]=arr[j];
                j++;
                k++;
            }
        }
        if(i>mid)
        {
            while(j<=ub)
            {
                b[k]=arr[j];
                j++;
                k++;
            }
        }
        else
        {
            while(i<=mid)
            {
                b[k]=arr[i];
                i++;
                k++;
            }
        }
        for(i=lb,k=0;i<=ub;i++,k++)
        {
            arr[i]=b[k];
        }
    }
    void mergesort(int[] arr, int lb, int ub)
    {
        int mid;
        if(lb<ub)
        {
            mid=lb+((ub-lb)/2);
            mergesort(arr,lb,mid);
            mergesort(arr,mid+1,ub);
            merge(arr,lb,mid,ub);
        }
    }
    void mergesort_1(int[] arr,int lb, int ub)
    {
        int i;
        double a1=System.currentTimeMillis();
        mergesort(arr,lb,ub);
        double a2=System.currentTimeMillis();
        // for(i=0;i<arr.length;i++)
        // System.out.print(arr[i]+"\t");
        System.out.println();
        System.out.println("merge sort time = "+(a2-a1)+" ms");
    }
    int partition(int arr[],int first,int last)
    {
        int pivot=arr[last];
        int i= first-1;
        int j=first;
        int temp;
        for(;j<last;j++)
        {
            if(arr[j]<pivot)
            {
                i++;
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        temp=arr[last];
        arr[last]=arr[i+1];
        arr[i+1]=temp;
        return i+1;
    }
    void quicksort(int arr[],int first,int last)
    {
        if(first>=last)
        return;
        int pi=partition(arr,first,last);
        quicksort(arr,first,pi-1);
        quicksort(arr,pi+1,last);
    }
    void quicksort_1(int arr[],int first,int last)
    {
        int i;
        double a1=System.currentTimeMillis();
        quicksort(arr,first,last);
        double a2=System.currentTimeMillis();
        //for(i=0;i<arr.length;i++)
        //System.out.print(arr[i]+"\t");
        System.out.println();
        System.out.println("quick sort time = "+(a2-a1)+" ms");
    }
} 