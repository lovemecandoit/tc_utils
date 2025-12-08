CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -g -O2
LDFLAGS = 

# 소스 파일
SRCS = kr92_tc.c
OBJS = $(SRCS:.c=.o)
SAMPLE = kr92_tc_sample.c
SAMPLE_TARGET = kr92_tc_sample

# 기본 타겟
all: $(OBJS) $(SAMPLE_TARGET)

# 오브젝트 파일 컴파일
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 샘플 프로그램 빌드
$(SAMPLE_TARGET): $(OBJS) $(SAMPLE)
	$(CC) $(CFLAGS) $(OBJS) $(SAMPLE) -o $(SAMPLE_TARGET) $(LDFLAGS)

# 정리
clean:
	rm -f $(OBJS) $(SAMPLE_TARGET)

# 재빌드
rebuild: clean all

.PHONY: all clean rebuild

