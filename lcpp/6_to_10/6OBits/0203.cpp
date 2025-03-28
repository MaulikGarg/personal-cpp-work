#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits)
{
    std::bitset<4> copy{bits};
    bits <<= 1;
    bits[0] = copy[3];
    return bits;   
}

/*or
std::bitset<4> rotl(std::bitset<4> bits)
{
    return (bits<<1) | (bits>>3);
}    
*/

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}
