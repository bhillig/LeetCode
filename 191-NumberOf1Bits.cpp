// 191 - Number of 1 Bits (LeetCode Exercise)

// Time Complexity: O(n) where n is the number of bits
// Space Complexity: O(1)

int hammingWeight(uint32_t n) 
{
    int numberOf1Bits = 0;
    for( int i=0; i <= 31; i++)
    {
        if ((n & (1 << i))) numberOf1Bits++;
    }
    return numberOf1Bits;
}