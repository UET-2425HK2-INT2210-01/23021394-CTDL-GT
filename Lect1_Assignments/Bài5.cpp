#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    vector<float> number(5);
    for ( int i = 0; i < 5; i++) {
        cin >> number[i];
    }
    float max = *max_element (number.begin(),number.end());
    float min = *min_element (number.begin(),number.end());
    float sum = max + min;
    cout << sum;
    return 0;
}
 