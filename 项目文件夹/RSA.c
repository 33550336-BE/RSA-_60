#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 扩展欧几里得算法
long int Exgcd_60(long int a_60, long int b_60, long int *x_60, long int *y_60) {
    if (b_60 == 0) {
        *x_60 = 1;
        *y_60 = 0;
        return a_60;
    }
    long int r_60 = Exgcd_60(b_60, a_60 % b_60, x_60, y_60);
    long int temp_60 = *x_60;
    *x_60 = *y_60;
    *y_60 = temp_60 - (a_60 / b_60) * (*y_60);
    return r_60;
}

// 求模逆元
long int mod_reverse_60(long int a_60, long int n_60) {
    long int x_60, y_60;
    long int r_60 = Exgcd_60(a_60, n_60, &x_60, &y_60);
    if (r_60 == 1) {
        return (x_60 % n_60 + n_60) % n_60; // 保证返回正数
    } else {
        return -1;
    }
}

// 将整数转换为二进制数组
void intToBinary_60(long int num_60, int bin_60[], int *len_60) {
    int i_60 = 0;
    long int temp_60 = num_60;
    
    while (temp_60 > 0) {
        bin_60[i_60] = temp_60 % 2;
        temp_60 = temp_60 / 2;
        i_60++;
    }
    *len_60 = i_60;
}

// 平方乘算法 (左到右)
long int LRFun_60(long int a_60, long int m_60, long int n_60) {
    int key_60[100];
    int klen_60;
    
    // 将指数m转换为二进制
    intToBinary_60(m_60, key_60, &klen_60);
    
    printf("指数 %ld 的二进制表示: ", m_60);
    for (int i_60 = klen_60 - 1; i_60 >= 0; i_60--) {
        printf("%d", key_60[i_60]);
    }
    printf("\n");
    
    long int s_60 = 1;
    printf("初始值: s = 1\n");
    
    for (int i_60 = klen_60 - 1; i_60 >= 0; i_60--) {
        printf("i=%d: ", klen_60 - 1 - i_60);
        s_60 = (s_60 * s_60) % n_60;
        printf("平方后 s = %ld", s_60);
        
        if (key_60[i_60] == 1) {
            s_60 = (s_60 * a_60) % n_60;
            printf(" → 乘a后 s = %ld", s_60);
        }
        printf("\n");
    }
    printf("最终结果: %ld^%ld mod %ld = %ld\n", a_60, m_60, n_60, s_60);
    return s_60;
}

// 模重复平方法 (右到左)
long int RLFun_60(long int a_60, long int m_60, long int n_60) {
    int key_60[100];
    int klen_60;
    
    // 将指数m转换为二进制
    intToBinary_60(m_60, key_60, &klen_60);
    
    printf("指数 %ld 的二进制表示: ", m_60);
    for (int i_60 = klen_60 - 1; i_60 >= 0; i_60--) {
        printf("%d", key_60[i_60]);
    }
    printf("\n");
    
    long int s_60 = 1;
    long int base_60 = a_60 % n_60;
    
    printf("初始值: s = 1, base = %ld\n", base_60);
    
    for (int i_60 = 0; i_60 < klen_60; i_60++) {
        printf("i=%d: ", i_60);
        
        if (key_60[i_60] == 1) {
            s_60 = (s_60 * base_60) % n_60;
            printf("s = (s * base) mod n = %ld", s_60);
        } else {
            printf("s保持不变 = %ld", s_60);
        }
        
        base_60 = (base_60 * base_60) % n_60;
        printf(", base = base^2 mod n = %ld\n", base_60);
    }
    printf("最终结果: %ld^%ld mod %ld = %ld\n", a_60, m_60, n_60, s_60);
    return s_60;
}

// 字符串转换为数字
long int stringToNumber_60(const char* str_60) {
    long int result_60 = 0;
    for (int i_60 = 0; str_60[i_60] != '\0'; i_60++) {
        result_60 = result_60 * 256 + (unsigned char)str_60[i_60];
    }
    return result_60;
}

// 数字转换为字符串
void numberToString_60(long int num_60, char* str_60) {
    int i_60 = 0;
    long int temp_60 = num_60;
    
    while (temp_60 > 0) {
        str_60[i_60] = temp_60 % 256;
        temp_60 = temp_60 / 256;
        i_60++;
    }
    str_60[i_60] = '\0';
    
    // 反转字符串
    for (int j_60 = 0; j_60 < i_60 / 2; j_60++) {
        char temp_char_60 = str_60[j_60];
        str_60[j_60] = str_60[i_60 - 1 - j_60];
        str_60[i_60 - 1 - j_60] = temp_char_60;
    }
}

// RSA加密解密测试
void testRSA_60(long int e_60, long int p_60, long int q_60, long int m_60, const char* testName_60) {
    printf("\n%s\n", testName_60);
    
    // 计算n和欧拉函数值
    long int n_60 = p_60 * q_60;
    long int phi_60 = (p_60 - 1) * (q_60 - 1);
    
    printf("参数设置:\n");
    printf("公钥 e = %ld\n", e_60);
    printf("素数 p = %ld\n", p_60);
    printf("素数 q = %ld\n", q_60);
    printf("明文 m = %ld\n", m_60);
    printf("计算 n = p * q = %ld\n", n_60);
    printf("欧拉函数 φ(n) = (p-1)*(q-1) = %ld\n", phi_60);
    
    // 计算私钥d
    long int d_60 = mod_reverse_60(e_60, phi_60);
    if (d_60 == -1) {
        printf("错误: e 和 φ(n) 不互质，无法计算私钥！\n");
        return;
    }
    printf("私钥 d = %ld\n", d_60);
    
    // 验证 ed ≡ 1 mod φ(n)
    printf("验证: e * d mod φ(n) = %ld * %ld mod %ld = %ld\n", 
           e_60, d_60, phi_60, (e_60 * d_60) % phi_60);
    
    // 使用平方乘算法加密
    long int c_60 = LRFun_60(m_60, e_60, n_60);
    printf("密文 c = %ld\n", c_60);
    
    // 使用模重复平方法解密
    long int decrypted_60 = RLFun_60(c_60, d_60, n_60);
    printf("解密结果 = %ld\n", decrypted_60);
    
    // 验证结果
    if (m_60 == decrypted_60) {
        printf("✓ 加解密成功！明文和解密结果一致。\n");
    } else {
        printf("✗ 加解密失败！明文和解密结果不一致。\n");
    }
}

int main() {
    
    // 测试1: 固定数据
    testRSA_60(7, 13, 17, 22, "测试1: 固定数据 (e=7, p=13, q=17, m=22)");
    
    // 测试2: 学号后四位1060
    long int student_id_60 = 1060; // 学号后四位
    testRSA_60(65537, 61, 53, student_id_60, "测试2: 学号后四位1060作为明文");
    
    // 测试3: 字符串"RSA"
    const char* message_60 = "RSA";
    long int m_str_60 = stringToNumber_60(message_60);
    testRSA_60(17, 23, 19, m_str_60, "测试3: 字符串'RSA'作为明文");
    
    // 显示字符串转换结果
    printf("\n字符串转换详情:\n");
    printf("字符串 '%s' → 数字: %ld\n", message_60, m_str_60);
    
    char recovered_str_60[10];
    numberToString_60(m_str_60, recovered_str_60);
    printf("数字 %ld → 字符串: '%s'\n", m_str_60, recovered_str_60);
    
    return 0;
}