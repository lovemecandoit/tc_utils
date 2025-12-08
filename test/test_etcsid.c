#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t value = 0x010203;
    printf("입력 값: 0x%06X\n", value);
    printf("바이트별 분해:\n");
    printf("  바이트 0 (LSB): 0x%02X\n", (value >> 0) & 0xFF);
    printf("  바이트 1:      0x%02X\n", (value >> 8) & 0xFF);
    printf("  바이트 2 (MSB): 0x%02X\n", (value >> 16) & 0xFF);
    printf("\n현재 함수 동작 (리틀 엔디안):\n");
    printf("  target[2] = 0x%02X\n", (value >> 0) & 0xFF);
    printf("  target[3] = 0x%02X\n", (value >> 8) & 0xFF);
    printf("  target[4] = 0x%02X\n", (value >> 16) & 0xFF);
    printf("\n예상 출력: 03 02 01\n");
    printf("실제 출력: 00 03 02\n");
    return 0;
}
