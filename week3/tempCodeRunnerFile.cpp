int pivot = a[r];
    int i= l-1;
    for(int j=l;j<=r-1 ; j++)
    {
        if(a[j]<pivot)
        {
            i++;
           swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return (i+1);