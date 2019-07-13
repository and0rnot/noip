#include <iostream>
#include <sys/resource.h>

using namespace std;

int f(int n) {
    if (n == 1)
        return 1;
    return f(n-1)+1;
}

int main() {
    struct rlimit rl;
    int result;

    getrlimit(RLIMIT_STACK, &rl);
    cout << "cur: " << rl.rlim_cur << ", max: " << rl.rlim_max << endl;
    rl.rlim_cur = 1024; // 1k
    result = setrlimit(RLIMIT_STACK, &rl);
    if (result != 0) {
        cout << "err: setrlimit return " << result << endl;
        return -1;
    }
    getrlimit(RLIMIT_STACK, &rl);
    cout << "cur: " << rl.rlim_cur << ", max: " << rl.rlim_max << endl;

    for (int i = 1; i <= 10000; i++) {
        cout << i << " " << f(i) << endl;
    }
    
    return 0;
}