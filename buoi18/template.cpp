#include<iostream>
using namespace std;

// int MAX(int IA, int IB)
// {
//     return ((IA > IB) ? IA : IB);
// }

// float MAX(float IA, float IB)
// {
//     return ((IA > IB) ? IA : IB);
// }

// double MAX(double IA, double IB)
// {
//     return ((IA > IB) ? IA : IB);
// }

// float MAX(int IA, float IB)
// {
//     return ((IA > IB) ? IA : IB);
// }

// float MAX(float IA, int IB)
// {
//     return ((IA > IB) ? IA : IB);
// }

template<typename Khoa, typename Khoa1>
    Khoa MAX(Khoa IA, Khoa1 IB)
{
    return ((IA > IB) ? IA : IB);
}

int main()
{
    int INT1 = 7;
    float FN1 = 8.5;
    
    // float IMax = MAX(FN1, INT1); // Kết quả 8.5
  float IMax = MAX(INT1,  FN1); // Kết quả 8
    cout << "Max = " << IMax << endl;
    system("pause");
    return 0;
}
