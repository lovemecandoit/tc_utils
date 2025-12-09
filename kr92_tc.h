#include <stdbool.h>
#include <stdint.h>

typedef enum {
	TC1 = 1,    /* Normal order of events
		-> Safety Connection 정상 수립 확인 ( ) */

	TC2,    /* Normal order of events (Use of default parameters)
		-> TE에서 default value로 AU1 Sa_Conn.req을 보냈을 때 Safety Connection 정상 수립 확인 */
	
	TC3,    /* Error case - Time out of Timer Testab after AU3 SaPDU
		-> AU3 이후 IUT가 AR을 수신하지 않아 타임아웃이 발생한 상황 */

	TC4,    /* Error case - Time out of Timer Testab after AU1 SaPDU
		-> IUT가 AU1을 송신 후 기대중인 AU2를 시간내 미수신 */

	TC5,    /* Error case - Reception of an AU2 SaPDU with an unexpected responding ETCS-ID
		-> IUT가 수신받은 AU2의 ETCS-ID 값이 다름 */

	TC6,    /* Error case - Reception of an AU2 SaPDU with MAC error
		-> IUT가 AU2 수신 시 포함된 MAC 검증 실패*/
    
    TC7,    /* Error case - Reception of an AR SaPDU with MAC error
        -> IUT가 AR수신 시 포함된 MAC 검증 실패*/  

    TC8,    /* Error case - Reception of an AU2 SaPDU with wrong direction flag
        -> IUT가 AU2수신 시 포함된 direction flag wrong */  

    TC9,    /* Error case - Reception of an AR SaPDU with wrong direction flag
        -> IUT가 AR수신 시 포함된 direction flag wrong */  

    TC10,   /* Error case - Reception of an AU2 SaPDU with wrong ETY field 
        -> IUT가 AU2수신 시 포함된 ETY wrong */  
    TC11,   /* Error case - Reception of an AU2 SaPDU with not supported safety feature
        -> IUT가 AU2 수신 시 Safety Feature wrong */  

    TC12,   /* Error case - Sequence error after AU1 SaPDU  
        -> IUT가 AU2 수신을 기대했지만 다른 MTI를 수신받는 경우 */  

    TC13,   /* Error case - Transport Connection Confirmation without AU2 SaPDU
        -> IUT가 수신받은 T-CONN.conf 안에 AU2가 누락된 상황 */  

    TC14,   /* Error case - Sequence error after AU3 SaPDU
        -> IUT가 AR 수신을 기대했지만 다른 메시지타입인 경우 (MTI) */

    TC15,   /* Error case - Reception of an AU2 SaPDU with wrong length
        -> IUT가 AU2 수신 시 Message length 검증 오류 */  

    TC16,   /* Error case - Reception of an AR SaPDU with wrong length
        -> IUT가 AR 수신 시 Message length 검증 오류 */  

    TC17,   /* Error case - Revocation of a connect request during peer entity authentication 
        -> IUT가 SaPDU 절차를 수행중일 때 완료되지 않은 상태에서 Sas user가 연결을 종료하려고 하는 경우 */  

    TC18,   /* Error case - No transport connection available
        -> AU1에서 에러를 발생시켜서 CFM에서 종료 이벤트를 내리도록 구성하는 거 */  

    TC19,   /* Normal order of events */ 

    TC20,   /* Error case - Missing authentication key
        -> IUT가 정상적인 AU1을 수신했지만 AU2를 만들기 위한 인증키가 존재하지 않는 경우 */  

    TC21,   /* Error case - Reception of an AU3 SaPDU with MAC error
        -> IUT가 AU3수신 시 포함된 MAC 검증 실패 */  

    TC22,   /* Error case - Reception of an AU1 SaPDU with wrong direction flag
        -> IUT가 AU1수신 시 포함된 direction flag wrong */  

    TC23,   /* Error case - Reception of an AU3 SaPDU with wrong direction flag 
        -> IUT가 AU3수신 시 포함된 direction flag wrong */  

    TC24,   /* Error case - Reception of an AU1 SaPDU with wrong field ETY  
        -> IUT가 AU1수신 시 포함된 ETY wrong */  

    TC25,   /* Error case - Reception of an AU1 SaPDU with not supported safety feature
        -> IUT가 Test Environment로부터 수신한 AU1 SaPDU의 Safety Feature 필드(SaF)가 IUT가 지원하지 않는 값으로 설정된 경우 */  

    TC26,   /* 정리한 문서에 없음 */  

    TC27,   /* Error case - Reception of an AU1 SaPDU with not supported safety feature
        -> IUT가 Test Environment로부터 수신한 AU1 SaPDU의 Safety Feature 필드(SaF)가 IUT가 지원하지 않는 값으로 설정된 경우 */  

    TC28,   /* 정리한 문서에 없음 */ 
    
    TC29,   /* Error case - Sequence error during peer entity authentification (reception of first message)
        -> IUT가 AU1을 기대하는데 다른 SaPDU가 수신됐을 경우(MTI필드값이 0001이 아님 ) */  
    
    TC30,   /* Error case - Error during peer entity authentification (first message missing) 
        -> TODO : 좀 더 확인 필요한 케이스 */  
    
    TC31,   /* Error case - Sequence error during peer entity authentification (reception of third message) 
        -> IUT 가 받은 AU3의 MTI(메시지 타입 값이) AU3(0011)이 아닌 경우 */  
    
    TC32,   /* Error case - Reception of an AU1 SaPDU with wrong length 
        -> IUT가 받은 AU1 메시지의 길이가 표준과 다른 경우. */  
    
    TC33,   /* Error case - Reception of an AU3 SaPDU with wrong length
        -> IUT가 받은 AU3 메시지의 길이가 표준과 다른 경우. */  
    
    TC34,   /* Error case - Incoming connect indication is not confirmed by SaS user 
        -> IUT가 AU3를 수신한 이후 SaS User에게서 종료가 내려올 경우. */  
    
    TC35,   /* Normal order of events 
        -> 일반 데이터와 고우선순위(high priority) 데이터의 송수신을 시험한다.*/  
    TC36,   /* Error case - Reception of messages with a wrong MTI  
        -> IUT가 받은 DT 메시지의 타입값(MTI)가 잘못된 타입인 경우 */  
    
    TC37,   /* Error case - Reception of DT SaPDU, which is too short  
        -> IUT가 받은 DT메시지가 유저 바디가 없이 (Header 1byte + empty body 0byte + MAC 8bytes  = 9) 9바이트인 경우 */  
    
    TC38,   /* Error case - Reception of DT SaPDU, which is too long
        -> IUT가 받은 DT 메시지의 바디가 허용하는 최대 길이(1023)를 뛰어넘는 경우 */  

    TC39,   /* Error case - Reception of DT SaPDU with wrong direction flag
        -> TE가 요청하는 상태로 시작한 상태로 받은 DT 메시지의 direction flag 값이 0이 아닌 경우 */

    TC40,   /* Error case - Reception of DT SaPDU with wrong direction flag 
        -> IUT가 요청하는 상태로 시작한 상태로 받은 DT 메시지의 direction flag 값이 1이 아닌 경우.*/  

    TC41,   /* Error case - Reception of DT SaPDU with wrong MAC  
        -> IUT가 수신한 DT메시지의 MAC값이 변조된 경우 */  

    TC42,   /* Normal order of events  
        -> DATA 상태에서 Sas User로부터 내려오는 정상 연결 해제 */ 

    TC43,   /* Normal order of events
        -> DATA 상태에서 TE쪽 Sas User로부터 내려오는 정상 연결 해제 */

    TC44,   /* Error case - No transport service available
        -> IUT가 수신한 T-Disc.ind의 body가 포함되지 않는 경우 */  

    TC45,   /* Error case - Reception of an DI SaPDU with wrong direction flag 
        -> IUT가 T-disc..ind 를 수신받을 때 direction flag 값이 잘못 설정된 경우 (양방항 다 봐야 함) */  

    TC46,   /* Error case - Reception of an DI SaPDU with changed first octet  
        -> DI헤더의 최상의 비트 3개는 000으로 고정되어야 하는데 수신한 데이터 헤더의 최상위 세 비트가 000이 아닐경우 */  

    NONE
} kr92_test_case;

typedef enum
{
    ETY, MTI, DF
} kr92_header_field;

typedef enum
{
    AU1 = 1,
    AU2 = 2,
    AU3 = 3,
    AR = 9,
    DT = 5,
    DI = 8,
} kr92_mti_type;

typedef enum
{
    BIT_MASK_ETY = 31, // 0001 1111, 1F
    BIT_MASK_MTI = 225, // 1110 0001, E1
    BIT_MASK_DF = 254 // 1111 1110, FE,
} kr92_header_bit_mask;

typedef enum
{
    ETY_ERROR = 224 /* 3bit */
} kr92_ety_value;

typedef enum
{
    MTI_AU1 = (1 << 1), 
    MTI_AU2 = (2 << 1), 
    MTI_AU3 = (3 << 1), 
    MTI_AR  = (9 << 1), 
    MTI_DT  = (5 << 1), 
    MTI_DI  = (8 << 1) /* 4 bit */
} kr92_mti_value;


typedef enum /* 양쪽 다 포함 */
{
    au1_sa_start = 2, au1_sa_end = 4, 
    au2_sa_start = 2, au2_sa_end = 4,
} kr92_sa_offset;


/* 설정된 테스트 케이스 */
extern kr92_test_case cur_test_case;

/* 표준 타입 사용 */
typedef uint8_t buf;
typedef uint32_t uint;


/* SIZE 정의 */
#define MAC_SIZE 8

/* OFFSET 정의 */
#define HEADER_OFFSET 0

void init(uint value);
kr92_test_case get_tc();
uint getMacOffset(uint buffer_len);

/* TC 유틸리티 선언 */
void setHeader(buf* target, kr92_header_field h_type, buf value);
void setMac(buf* target, uint bufLen, unsigned long value);
void setBufferLen(buf* target);
void setEtcsId(buf* target, kr92_mti_type b_type, uint value);
void setSaF(buf* target, kr92_mti_type b_type, buf b);

/* 개별 TC 별 추가 */
// ###########################################################
