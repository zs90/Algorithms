void InsertSort(int a[], int len){
	for(int i = 1; i < len; i++){
		for(int j = i; j >=1 && a[j-1] > a[i]; j--){
				a[j] = a[j-1]; 
		}
		a[j] = a[i];
	}
}