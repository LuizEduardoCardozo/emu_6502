#include <gtest/gtest.h>
#include "../6502emu.h"

class Emu6502Test : public testing::Test
{
public:
    Mem mem;
    CPU cpu;

    virtual void SetUp()
    {
        cpu.Reset(mem);

    }

    virtual void TearDown()
    {

    }
};

TEST_F(Emu6502Test, LDAIMCanLoadAValueIntoARegister)
{
    mem[0xFFFC] = CPU::INS_LDA_IM;
    mem[0xFFFD] = 0x84;

    cpu.Execute(2, mem);

    EXPECT_EQ(cpu.A, 0x84);
}

