#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            while (!st.empty() && st.back() > 0 && a < 0) {
                
                if (st.back() < -a) {
                    st.pop_back();
                    continue;
                }

                if (st.back() == -a) {
                    st.pop_back();
                }

                a = 0;
                break;
            }

            if (a != 0) {
                st.push_back(a);
            }
        }

        return st;
    }
};

int main() {
    Solution obj;
    vector<int> asteroids = {5, 10, -5};

    vector<int> ans = obj.asteroidCollision(asteroids);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}