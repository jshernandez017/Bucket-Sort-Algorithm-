#include <iostream> 
#include <vector>
#include <algorithm> 
using namespace std; 
  
void insertion_Sort(vector<float>& arr, int size) 
{
	int j; 
	float tmp;

	for(int i = 1; i < size; i++){
		j = i;
		tmp = arr[i];
		while (j > 0 && tmp < arr[j - 1])
		{
           arr[j] = arr[j - 1];
           j--;
		}
		arr[j] = tmp;
	}
}
void bucket_Sort(float arr[], int size){  
	vector<float> buckets[size];  
	for (int i = 0; i < size; i++){ 
		int mod = size * arr[i]; 
		buckets[mod].push_back(arr[i]); 
	}
	for(int i = 0; i < size; i++){
		insertion_Sort(buckets[i], buckets[i].size());
	}
	int index = 0; 
	for(int i = 0; i < size; i++){
		for(int j = 0; j < buckets[i].size(); j++){			
			arr[index++] = buckets[i][j];
		}
	}
} 
int main(){
	int size;
	cin >> size;
	float arr[size];
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}
	bucket_Sort(arr, size);
	for(int j = 0; j < size; j++){
		cout << arr[j] << "\n";
	}
	return 0;
}