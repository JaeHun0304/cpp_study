#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int>& arr){
  for(auto i: arr){
    cout << i << " ";
  }
  cout << endl;
}

vector<int>& doMergeSort(vector<int> &arr){

  if(arr.size() > 1){
    int high = arr.size();
    int mid = high / 2;

    auto it = arr.begin();
    // based on vector ( InputIterator first, InputIterator last, const Allocator& = Allocator() );
    vector<int> left(it, it + mid);
    vector<int> right(it + mid, it + high);
    // Recursively call left and right until its size becomes 1
    left = doMergeSort(left);
    right = doMergeSort(right);
    int i = 0, j = 0, k = 0;
    // merge left and right subproblem
    while(i < left.size() && j < right.size()){
      if(left[i] < right[j]){
        arr[k] = left[i];
        i++;
        k++;
      }
      else if(left[i] > right[j]){
        arr[k] = right[j];
        j++;
        k++;
      }
      // if left and right subproblem numbers are same, use the left one and increment
      // left subproblem index to prevent infinite while loop
      else{
        arr[k] = left[i];
        i++;
        k++;
      }
    }
    // fill arr with remaining left[i]
    while(i < left.size()){
      arr[k] = left[i];
      i++;
      k++;
    }

    //fill arr with remaining right[j]
    while(j < right.size()){
      arr[k] = right[j];
      j++;
      k++;
    }
  }
  
  return arr;
}


int binarySearch(vector<int> &arr, int key, int low, int high){
  // reference mid index element for binary search
  int mid = (high - low) / 2 + low;

  if(low < high){
    if(key < arr[mid])
      mid = binarySearch(arr, key, low, mid);
    else if(key > arr[mid])
      mid = binarySearch(arr, key, mid + 1, high);
    else if(key == arr[mid])
      return mid;
  }

  if(key == arr[mid])
    return mid;
  
  return -1;
}

vector<int> binaryAllMatch(vector<int> &arr, int mid, int key){
  
  vector<int> all_match;
  all_match.push_back(mid);

  auto it = arr.begin() + mid;
  auto it_prev = it - 1;
  auto it_next = it + 1;

  // search adjacent arr elements using the prev and next iterators
  // Note. (it - it.begin()) can return the current index of the given iterator
  // Think like it's a distance from here to begin()
  while(*(it_next) == arr[mid] || *(it_prev) == arr[mid]){
    if(*(it_next) == *(it)){
      all_match.push_back(it_next - arr.begin());
      it_next++;
    }
    if(*(it_prev) == *(it)){
      all_match.push_back(it_prev - arr.begin());
      it_prev--;
    }
  }

  sort(all_match.begin(), all_match.end());
  
  //return all the matching indexes
  return all_match;
}

int main(){
  vector<int> my_arr{1, 1, 4, 4, 4, 4, 8, 9};
  doMergeSort(my_arr);
  // will be {1, 1, 2, 3, 5, 6, 7, 8}
  printArray(my_arr);
  //cout << binarySearch(my_arr, 4, 0, (my_arr.size() - 1)) << endl;
  vector<int> result = binaryAllMatch(my_arr, binarySearch(my_arr, 4, 0, (my_arr.size() - 1)), 4);
  printArray(result);
}