#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int prefix[n];
    prefix[0] = arr[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    cout << "Prefix sum array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << prefix[i] << " ";
    }

    int q;
    cout << "\nEnter the number of queries:" << endl;
    cin >> q;

    int rangeSum[q];

    for(int i = 0; i < q; i++) {
        cout << "Enter the range " << (i + 1) << " (l r):" << endl;
        int l, r;
        cin >> l >> r;

        if(l == 0) {
            rangeSum[i] = prefix[r];
        } else {
            rangeSum[i] = prefix[r] - prefix[l - 1];
        }
    }

    cout << "Range sum results:" << endl;
    for(int i = 0; i < q; i++) {
        cout << rangeSum[i] << endl;
    }

    return 0;
}
