void Merge(int a[], int low, int mid, int high){
	int * tmp = new int[high - low + 1];
	int i = low, j = mid + 1, k = 0;
	while(i <= mid && j <= high){
		if(a[i] < a[j]) 
			tmp[k++] = a[i++];
		else 
			tmp[k++] = a[j++];
	}
	
	while(i <= mid) tmp[k++] = a[i++];
	while(j <= high) tmp[k++] = a[j++];
	
	memcpy(a, tmp, sizeof(int) * (high - low + 1));
	delete []tmp;
}

void MergeSort(int a[], int low, int high){
	if(low < high){
		int mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, mid, high);
	}
}