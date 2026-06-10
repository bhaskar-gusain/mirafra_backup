#include </home/mirafra/Desktop/temp/header.h>

int max_repeating_simple(int arr[], int n) 
{
	int max_count = 0, result = arr[0];
	for (int i = 0; i < n; i++) 
	{
		int count = 0;
		for (int j = 0; j < n; j++)
			if (arr[j] == arr[i]) count++;
		if (count > max_count) 
		{
			max_count = count;
			result = arr[i];
		}
	}
	printf("Element: %d, Count: %d\n", result, max_count);
	return result;
}


int main()
{

	int arr[] = {30,0,45,30,3,30,11,30,21,0,1};
	
	//printf("%d ",max_repeating_simple(arr,11));

	int ans =arr[0], max=0;

	for(int i= 0; i < (sizeof(arr)/sizeof(arr[0])) ;i++ )
	{
		int count = 1;	

		for(int j=i+1 ; j < (sizeof(arr)/sizeof(arr[0])) ; j++)
		{
			if(arr[i] == arr[j]) {
				count++;
				
			}

		}
		if(count > max){
			max = count;
			ans = arr[i];
		}



		printf("%d ",arr[i]);

	}

	printf("\n\n%d",ans);
	


	return 0;
}
