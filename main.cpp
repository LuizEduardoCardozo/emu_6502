#define EXIT_SUCCESS 0

struct CPU
{
    using Byte = unsigned char;
    using Word = unsigned short;
    
    Word PC;    // program counter
    Word SP;    // stack pointer;

    Byte A;     // acumulator
    Byte X, Y;  // registers

    /* Processor status */
    Byte C : 1; // carry bit
    Byte Z : 1; // zero flag
    Byte I : 1; // Interrupt disable
    Byte D : 1; // Decimal mode
    Byte B : 1; // Break mode
    Byte V : 1; // oVerflow
    Byte N : 1; // Negative

};

int main()
{
    CPU cpu;
    return EXIT_SUCCESS;
}

