#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t value = 0x010203;
    uint32_t au1_sa_start = 2;
    uint32_t au1_sa_end = 4;
    uint32_t bit_mask = 0xFF;
    
    printf("입력 값: 0x%06X\n\n", value);
    printf("현재 함수 로직:\n");
    for (uint32_t i = au1_sa_start; i <= au1_sa_end; ++i) {
        uint32_t shift = (i - au1_sa_start) * 8;
        uint8_t byte = (value >> shift) & bit_mask;
        printf("  target[%u] = (0x%06X >> %u) & 0xFF = 0x%02X\n", i, value, shift, byte);
    }
    
    printf("\n결과: ");
    for (uint32_t i = au1_sa_start; i <= au1_sa_end; ++i) {
        uint32_t shift = (i - au1_sa_start) * 8;
        uint8_t byte = (value >> shift) & bit_mask;
        printf("%02X ", byte);
    }
    printf("\n\n실제 출력: 00 03 02\n");
    printf("예상 출력: 03 02 01\n");
    
    printf("\n빅 엔디안 방식 (MSB 먼저):\n");
    for (uint32_t i = au1_sa_start; i <= au1_sa_end; ++i) {
        uint32_t shift = (au1_sa_end - i) * 8;
        uint8_t byte = (value >> shift) & bit_mask;
        printf("  target[%u] = (0x%06X >> %u) & 0xFF = 0x%02X\n", i, value, shift, byte);
    }
    
    return 0;
}
