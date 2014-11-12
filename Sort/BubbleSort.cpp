void BubbleSort(int a[], int len){
	for(int i = 0; i < len - 1; i--){
		for(int j = len - 1; j > i && a[j-1] > a[j]; j--){
			swap(a, j-1, j);
		}
	}
}