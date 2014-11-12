int Partition(int a[], int low, int high){
	int pivot = a[low];
	while(low < high){
		while(low < high && a[high] > pivot) high--;
		if(low < high) a[low] = a[high];
		while(low < high && a[low] < pivot) low++;
		if(low < high) a[high] = a[low]; 
	}
	a[low] = pivot;
	return low;
}

void QuickSort(int a[], int low, int high){
	if(low < high){
		int mid = Partition(a, low, high);
		QuickSort(a, low, mid-1);
		QuickSort(a, mid+1, high);
	}
}