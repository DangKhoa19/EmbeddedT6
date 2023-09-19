
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector

void myfunction (int i) {  // function:
  std::cout << ' ' << i;
}

struct myclass {           // function object type:
  void operator() (int i) {std::cout << ' ' << i;}
} myobject;

int main () {
  std::vector<int> myvector;
  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);

  std::cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myfunction);
  std::cout << '\n';

  // or:
  std::cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myobject);
  std::cout << '\n';

  return 0;
}


#include<iostream>
using namespace std;

//  [capture clause] (parameters) -> return - type
//  {
//     definition of method
//  }

int main()
{
    int a= 10;
    int f= 20;
    int k= 30;

    auto func = [=](int a, int b) -> int
    // dấu = trong [=] là capture clause sao chép (truyền tham trị) các biến bên ngoài vào hàm
    //(int a, int b) -> int hàm này nhận 2 tham số input kiểu int a và b, trả về kiểu int
    {
        return a +b+ f +k;
        //phần thân của hàm lambda
    };
    cout<<func(18, 2)<<endl;
    return 0;
}


#include <iostream>
int main() 
{

    int x = 5;
    int y = 10;

    auto lambda = [](int a, int b) ->int{
        return a+b; // Lambda không sử dụng x và y từ  bên ngoài
    };

    std::cout << lambda(3,4) << std::endl;

    return 0;
}

#include <iostream>

int main() {
    int x = 5;

    auto lambda = [x](int a, int b) -> int {
        return x * 2+a+b; // Lambda sử dụng x được sao chép từ phạm vi bên ngoài
    };

    std::cout << lambda(23,22) << std::endl;

    return 0;
}


#include <iostream>
using namespace std;
int main() {
    int x = 5;
    int y = 10;
    int c =11;

    auto lambda = [&, x]() {
        return x + y +c; 
        // Lambda dùng x được sao chép và y thông qua tham chiếu
    };

    cout << lambda() << endl;

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int x = 5;
    [](const float value)
    {
        cout << "Value = " << value << endl;
    }(6.7); // Thiếu dấu chấm phẩy ở đây để kết thúc biểu thức lambda
}

#include <iostream>
using namespace std;

int main() {
  [](const float value) {
    cout << "Value = " << value << endl;
}(6.7);

    return 0;
}

#include<iostream>
using namespace std;
int main()
{
int x = 5;
int y = 10;

auto lambda = [=, &y]() {
    y=20;
    return x + y; // Lambda sử dụng x được sao chép và y thông qua tham chiếu
};

cout << lambda() << endl;
cout << y << endl;

return 0; 
}
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = 10;

    auto lambda = [](float value) {
        cout << "Value = " << value << endl;
        return 42; // Lambda không sử dụng x và y từ bên ngoài
    }(4.11);

    cout << lambda << endl;

    return 0;
}



#include <iostream>

using namespace std;

int main() {

    int x = 5;
    int y = 10;
    auto lambda = [x, y](int a, int b) {
        return x * y+a+b; 
        // Lambda chỉ sử dụng x và y được sao chép từ phạm vi bên ngoài
    };
   cout << lambda(1,2) << endl;
   
    return 0;
}



#include <iostream>

using namespace std;

int main() {
    int z = 4;
    int x = 5;
    int y = 10;

    auto lambda = [&, x]() {
        return x + y+z; 
        // Lambda dùng x được sao chép và y thông qua tham chiếu
    };

    cout << lambda() << endl;

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int x = 5;
    [](float value) {
        cout << "Value = " << value << endl;
    }

    (6.7);

    return 0;
}


#include <iostream>

using namespace std;

int main() {

    int z = 4;
    int x = 5;
    int y = 10;

     [&, x](int value) {
             cout<< "value"<< value<<endl; 
        // Lambda dùng x được sao chép và y thông qua tham chiếu
    }(x);
    return 0;
}
