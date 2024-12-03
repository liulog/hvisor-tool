#include <stdio.h>

int main() {
    unsigned long long time_value;

    // 使用内联汇编读取 time 寄存器的值
    __asm__ volatile(
        "csrr %0, time"      // 将 time 寄存器的值读取到 time_value 变量中
        : "=r" (time_value)  // 输出操作数，%0 表示 time_value
        :                    // 输入操作数
        : "memory"           // 告诉编译器，内联汇编操作可能改变内存状态
    );

    // 打印读取到的时间戳计数器的值
    printf("%llu\n", time_value);

    return 0;
}