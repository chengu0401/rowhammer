#include "include/memory.h"
#include "include/util.h"
#include "include/types.h"
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

static physaddr_t base_phys = 0L;

DRAMAddr phys_2_dram(physaddr_t p_addr){
    DRAMAddr addr1;
    int* bit = generate_bits(p_addr);
    addr1.bank = 0;
    for (int i = 0; i < 6; i++){
        addr1.bank |= *(bit + i);
    }
    return addr1;
}
int* generate_bits(physaddr_t p_addr){
    int* arr1;
    * arr1 = generate_bit0(p_addr);
    *(arr1+1) = generate_bit1(p_addr);
    *(arr1+2) = generate_bit2(p_addr);
    *(arr1+3) = generate_bit3(p_addr);
    *(arr1+4) = generate_bit4(p_addr);
    *(arr1+5) = generate_bit5(p_addr);
    *(arr1+6) = generate_bit6(p_addr);
    return arr1;
}

int generate_bit0(physaddr_t p_addr){
    int ans = getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getBit(10,p_addr),getBit(12,p_addr)),getBit(16,p_addr)),getBit(20,p_addr)),getBit(23,p_addr)),getBit(26,p_addr)),getBit(29,p_addr)),getBit(30,p_addr));
    return ans;
}

int generate_bit1(physaddr_t p_addr){
    int ans = getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getBit(11,p_addr),getBit(12,p_addr)),getBit(13,p_addr)),getBit(15,p_addr)),getBit(17,p_addr)),getBit(20,p_addr)),getBit(21,p_addr)),getBit(23,p_addr)),getBit(25,p_addr)),getBit(26,p_addr)),getBit(30,p_addr));
    return (ans<<1);
}

int generate_bit2(physaddr_t p_addr){
    int ans = getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getBit(12,p_addr),getBit(13,p_addr)),getBit(18,p_addr)),getBit(19,p_addr)),getBit(22,p_addr)),getBit(25,p_addr)),getBit(26,p_addr)),getBit(27,p_addr)),getBit(30,p_addr)),getBit(31,p_addr));
    return (ans<<2);
}

int generate_bit3(physaddr_t p_addr){
    int ans = getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getBit(13,p_addr),getBit(15,p_addr)),getBit(20,p_addr)),getBit(24,p_addr)),getBit(26,p_addr)),getBit(29,p_addr)),getBit(29,p_addr)), getBit(32,p_addr));
    return (ans<<3);
}

int generate_bit4(physaddr_t p_addr){
    int ans = getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getBit(15,p_addr),getBit(16,p_addr)),getBit(21,p_addr)),getBit(22,p_addr)),getBit(23,p_addr)),getBit(25,p_addr)),getBit(26,p_addr)),getBit(28,p_addr)),getBit(29,p_addr));
    return (ans<<4);
}

int generate_bit5(physaddr_t p_addr){
    int ans = getXOR(getXOR(getXOR(getXOR(getBit(16,p_addr),getBit(19,p_addr)),getBit(23,p_addr)),getBit(27,p_addr)),getBit(30,p_addr));
    return (ans<<5);
}

int generate_bit6(physaddr_t p_addr){
    int ans = getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getXOR(getBit(17,p_addr),getBit(20,p_addr)),getBit(22,p_addr)),getBit(23,p_addr)),getBit(24,p_addr)),getBit(27,p_addr)),getBit(28,p_addr)),getBit(29,p_addr)),getBit(31,p_addr));
    return (ans<<6);
}

int getBit (int num, physaddr_t p_addr){
    switch(num){
        case 1:
            return (p_addr & (1ll << 1));
        case 2:
            return (p_addr & (1ll << 2));
        case 3:
            return (p_addr & (1ll << 3));
        case 4:
            return (p_addr & (1ll << 4));
        case 5:
            return (p_addr & (1ll << 5));
        case 6:
            return (p_addr & (1ll << 6));
        case 7:
            return (p_addr & (1ll << 7));
        case 8:
            return (p_addr & (1ll << 8));
        case 9:
            return (p_addr & (1ll << 9));
        case 10:
            return (p_addr & (1ll << 10));
        case 11:
            return (p_addr & (1ll << 11));
        case 12:
            return (p_addr & (1ll << 12));
        case 13:
            return (p_addr & (1ll << 13));
        case 14:
            return (p_addr & (1ll << 14));
        case 15:
            return (p_addr & (1ll << 15));
        case 16:
            return (p_addr & (1ll << 16));
        case 17:
            return (p_addr & (1ll << 17));
        case 18:
            return (p_addr & (1ll << 18));
        case 19:
            return (p_addr & (1ll << 19));
        case 20:
            return (p_addr & (1ll << 20));
        case 21:
            return (p_addr & (1ll << 21));
        case 22:
            return (p_addr & (1ll << 22));
        case 23:
            return (p_addr & (1ll << 23));
        case 24:
            return (p_addr & (1ll << 24));
        case 25:
            return (p_addr & (1ll << 25));
        case 26:
            return (p_addr & (1ll << 26));
        case 27:
            return (p_addr & (1ll << 27));
        case 28:
            return (p_addr & (1ll << 28));
        case 29:
            return (p_addr & (1ll << 29));
        case 30:
            return (p_addr & (1ll << 30));
        case 31:
            return (p_addr & (1ll << 31));
        default:
            return (p_addr & (1ll));
    }
}

int getXOR(int x, int y) {
  return (x | y) & (~x | ~y);
}


