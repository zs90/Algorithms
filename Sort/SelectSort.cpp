void SelectSort(int a[], int len){
	for(int i = 0; i < len-1; i++){
		int min = i;
		for(int j = i+1; j < len; j++){
			if(a[min] > a[j]){
				min = j;
			}
		}
		swap(a, min, i);
	}
}