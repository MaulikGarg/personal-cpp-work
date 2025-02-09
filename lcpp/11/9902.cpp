#include <iostream>

//#define CP2020

#ifndef CP2020

template <typename T>
T add(T x, T y){
    return x+y;
}

template <typename T, typename U>
T mult(T x, U y){
    return x*y;
}

template <typename T, typename U>
auto sub(T x, U y){
    return x-y;
}

#endif

#ifdef CP2020
auto add(auto x, auto y){
    return x+y;
}
auto mult(auto x, auto y){
    return x*y;
}
auto sub(auto x, auto y){
    return x-y;
}
#endif

int main()
{
	// std::cout << add(2, 3) << '\n';
	// std::cout << add(1.2, 3.4) << '\n';

    // std::cout << mult(2, 3) << '\n';
	// std::cout << mult(1.2, 3) << '\n';

    std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}
