#include <iostream>
#include <fstream>

using namespace std;

//function to check if a certain integer exists in the array
bool check(int arr[], int size, int num){
  for(int i = 0; i < size; i++){
    if(arr[i] == num){
      return true;
    }
  }
  return false;
}

//function to modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user
void modify(int arr[], int index, int &num, int &old){
  old = arr[index];
  arr[index] = num;
}

//function that adds a new integer to the end of the array
void add(int arr[], int &size, int num){
  arr[size++] = num;
}

//function which intakes an index of an array and remove the integer corresponding to that index
void remove(int arr[], int &size, int index){
  for(int i = index; i < size; i++){
    arr[i] = arr[i+1];
  }
  size--;
}

int main(){
  // File name
  string fileName = "data.txt";
  int arr[1000];
  int size = 0;

  ifstream inputFile;
  inputFile.open(fileName.c_str());
  if (!inputFile)
  {
    cout << "Unable to open file" << endl;
    exit(1);
  }
  int num;
  while (inputFile >> num)
  {
    arr[size++] = num;
  }
  inputFile.close();

  //check if a certain integer exists in the array if the number is present return the index where the number is present
  cout<<"Enter a number to check if it exists in the array: ";
  cin >> num;
  if(check(arr, size, num)){
    cout<<"The number exists in the array"<<endl;
  }else{
    cout<<"The number does not exist in the array"<<endl;
  }

  //A function to modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user
  int index, newNum, oldNum;
  cout<<"Enter the index of the number you want to modify: ";
  cin >> index;
  cout<<"Enter the new number: ";
  cin >> newNum;
  modify(arr, index, newNum, oldNum);
  cout<<"The old number was "<<oldNum<<" and the new number is "<<newNum<<endl;

  //A function that adds a new integer to the end of the array
  cout<<"Enter a number to add to the array: ";
  cin >> num;
  add(arr, size, num);
  cout<<"The new array is: ";
  for(int i = 0; i < size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  //A function which intakes an index of an array and remove the integer corresponding to that index
  cout<<"Enter the index of the number you want to remove: ";
  cin >> index;
  remove(arr, size, index);
  cout<<"The new array is: ";
  for(int i = 0; i < size; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
