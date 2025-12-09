#include <stdio.h>
#include <string.h>
#include "kr92_tc.h"

/*
 * kr92_tc 사용 예제
 *
 * - AU1 메시지를 구성한다는 가정으로 헤더/ETCS-ID/SaF/MAC을 채움
 * - setHeader 내부 구현의 캐스팅은 실제 환경에 맞게 보완이 필요할 수 있음
 */
int main(void) {
    /* 헤더 1바이트 + ETCS-ID 3바이트 + SaF 1바이트 + MAC 8바이트 = 13바이트 */
    int body_len = 4;
    const uint buf_len = 1 + 3 + 1 + body_len + MAC_SIZE;
    buf msg[buf_len];
    memset(msg, 0, sizeof(msg));

    /* 실행할 테스트 케이스 설정 */
    init(TC3);
    printf("현재 TC: %d\n", get_tc());

    /* 헤더 필드 설정 */
    setHeader(msg, ETY, ETY_ERROR); /* ETY 필드 예시 */
    setHeader(msg, MTI, MTI_AU1);   /* MTI=AU1 */
    setHeader(msg, DF, 1);           /* 방향 플래그 예시 */

    /* 바디 - ETCS-ID 설정 (AU1 기준) */
    setEtcsId(msg, AU1, 0x010203);

    /* 바디 - Safety Feature(SaF) 설정 */
    setSaF(msg, AU1, 0xAA); /* 예시 값 */

    /* MAC 영역 채우기 */
    setMac(msg, buf_len, 0xFF); /* 예: 0x11 값으로 8바이트 채움 */

    /* 결과 출력 */
    printf("생성된 메시지(hex):");
    for (uint i = 0; i < buf_len; ++i) {
        printf(" %02X", msg[i]);
    }
    printf("\n");

    return 0;
}

