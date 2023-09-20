#include <iostream>
#include <bitset>
template<size_t N>
std::bitset<N> operator+(const std::bitset<N>& a, const std::bitset<N>& b) {
    std::bitset<N> result;
    bool carry = false;

    for (int i = 0; i < N; i++) {
        bool bitA = a[i];
        bool bitB = b[i];
        bool sum = bitA ^ bitB ^ carry;
        carry = (bitA && bitB) || (carry && (bitA ^ bitB));

        result[i] = sum;
    }

    return result;
}

template<size_t N>
std::bitset<N> operator-(const std::bitset<N>& a, const std::bitset<N>& b) {
    std::bitset<N> result;
    bool borrow = false;

    for (int i = 0; i < N; i++) {
        bool diff;
        if (borrow) {
            diff = !(a[i] ^ b[i]);
            borrow = !a[i] || (a[i] && b[i]);
        }
        else {
            diff = a[i] ^ b[i];
            borrow = !a[i] && b[i];
        }
        result[i] = diff;
    }

    return result;
}
template<class N>
void Shift(N &A, N& Q, bool &Q1, int t) {
    Q1 = Q[0];
    bool temp = A[0];
    A >>= 1;
    A[t - 1] = A[t-2];
    Q >>= 1;
    Q[t - 1] = temp;
}

int main() {
    int x = 5;
    int y = -3;

    const int N = 4;
    std::bitset<N> A = 0;
    bool Q1 = 0;
    std::bitset<N> M = x;
    std::bitset<N> Q = y;
    std::cout << A <<"  " <<Q<<"  "<< Q1 <<"  " << M << std::endl;
    for (int count = N; count != 0; count--) {
        if (Q[0] == 0 && Q1 == 1) {
            A = A + M; 
            std::cout << A << "  " << Q << "  " << Q1 << "  " << M << std::endl;
        }
        else if (Q[0] == 1 && Q1 == 0) {
            A = A - M;  
            std::cout << A << "  " << Q << "  " << Q1 << "  " << M << std::endl;
        }

        Shift<std::bitset<N>>(A, Q, Q1, N);
        std::cout << A << "  " << Q << "  " << Q1 << "  " << M << std::endl;
    }
    std::cout << "Resultado A: " << A << std::endl;
    std::cout << "Resultado Q: " << Q << std::endl;

    return 0;
}