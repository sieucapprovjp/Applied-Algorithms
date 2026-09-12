#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a[1000];
  for (int i =0;i < n;i++) {
    cin >> a[i];
  }
  int max_val = a[0];
  for(int i =0;i<n; i++) {
    if (a[i] > max_val) max_val = a[i]; }
  cout << max_val << "\n";
  return 0;
}
