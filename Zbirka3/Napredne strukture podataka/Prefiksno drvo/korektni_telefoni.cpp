#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> numbers(n);
  for (int i = 0; i < n; i++)
    cin >> numbers[i];
  sort(begin(numbers), end(numbers));
  bool OK = true;
  for (size_t i = 1; i < numbers.size(); i++)
    if (numbers[i-1].size() <= numbers[i].size() &&
        equal(begin(numbers[i-1]), end(numbers[i-1]), begin(numbers[i]))) {
      OK = false;
      break;
    }
  if (OK)
    cout << "da" << endl;
  else
    cout << "ne" << endl;

  return 0;
}