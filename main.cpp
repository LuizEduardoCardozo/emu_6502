#include <stdint.h>
#include <stdlib.h>


#define EXIT_SUCCESS 0

using Byte = unsigned char;
using Word = unsigned short;

struct Mem 
{
    static constexpr uint32_t MEM_SIZE = 1024 * 64;
    Byte Data[MEM_SIZE];

    void Init()
    {   
        /* Cleans all the memory */
        for(size_t i=0; i<MEM_SIZE; i++) {
            Data[i] = 0x00;
        }

    }

    Byte operator[] (uint32_t address) const
    {
        if (address < MEM_SIZE)
            return Data[address];
  
        return 0x0;
    }

};

struct CPU
{
    
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

    void Reset(Mem& memory)                                                
    {                                                           
        PC = 0xFFFC;                                            
        SP = 0x0100;                                            
        D = 0;                                                  
        C = Z = I = D = B = V = N = 0x0;                        
        A = X = Y = 0x0;

        memory.Init();
    }   
    
    Byte FetchByte(uint32_t cycles, Mem& memory)
    {
        Byte data = memory[PC];
        PC++;
        cycles--;
        return data;
    }
    
    void Execute(uint32_t cycles, Mem& memory)
    {
        while(cycles > 0)
        {
            Byte ins = FetchByte(cycles, memory);
            
        }
    }


};

int main()
{   
    Mem mem;
    CPU cpu;
    cpu.Reset(mem);
    cpu.Execute(2, mem);

    return EXIT_SUCCESS;
}

