# RSA-_60
期末RSA
RSA加密算法实现_60
https://img.shields.io/badge/License-Apache%25202.0-blue.svg
https://img.shields.io/badge/language-C-orange.svg

一个用C语言实现的RSA加密算法项目，包含完整的加密、解密功能以及多种模幂运算算法。
 项目简介
本项目实现了RSA公钥加密算法的核心功能，包括：
 密钥生成（公钥和私钥计算）
使用平方乘算法进行加密
使用模重复平方法进行解密
扩展欧几里得算法计算模逆元
支持整数和字符串的加解密
 功能特性
 完整的RSA实现 - 支持完整的加密解密流程
 两种模幂算法 - 平方乘算法（左到右）和模重复平方法（右到左）
大数支持 - 处理大整数运算
 字符串加解密 - 支持将字符串转换为数字进行加密
 多组测试用例 - 包含固定数据、学号、字符串等多种测试
 详细日志 - 显示运算过程的每一步
 技术栈
编程语言: C语言

核心算法:

RSA加密算法

扩展欧几里得算法

平方乘算法

模重复平方法

开发工具: GCC编译器、Git

项目结构
text
RSA_Project_60/
├── src/
│   └── rsa_algorithm.c    # 主要的RSA算法实现
├── docs/
│   ├── algorithm_explanation.md    # 算法原理说明
│   └── implementation_details.md   # 实现细节文档
├── tests/
│   └── test_cases.c       # 测试用例
├── README.md              # 项目说明文档
├── LICENSE               # Apache 2.0许可证
└── .gitignore           # Git忽略文件
快速开始
环境要求
GCC编译器

支持C99标准的C语言环境

编译和运行
bash
# 克隆项目
git clone https://github.com/yourusername/RSA_Project_60.git
cd RSA_Project_60

# 编译代码
gcc -o rsa_demo rsa_algorithm.c

# 运行程序
./rsa_demo
使用示例
程序运行后会自动执行三组测试：

测试1: 固定参数测试 (e=7, p=13, q=17, m=22)

测试2: 学号后四位1060作为明文

测试3: 字符串"RSA"加解密测试

算法详解
RSA加密流程
密钥生成:

选择两个大素数 p 和 q

计算 n = p × q

计算 φ(n) = (p-1) × (q-1)

选择公钥 e，满足 1 < e < φ(n) 且 gcd(e, φ(n)) = 1

计算私钥 d = e⁻¹ mod φ(n)

加密过程: c = mᵉ mod n

解密过程: m = cᵈ mod n

核心函数
Exgcd_60(): 扩展欧几里得算法

mod_reverse_60(): 计算模逆元

LRFun_60(): 平方乘算法（左到右）
RLFun_60(): 模重复平方法（右到左）
stringToNumber_60(): 字符串转数字
numberToString_60(): 数字转字符串
测试结果
程序运行示例输出：
text
测试1: 固定数据 (e=7, p=13, q=17, m=22)
参数设置:
公钥 e = 7
素数 p = 13
素数 q = 17
明文 m = 22
计算 n = p * q = 221
欧拉函数 φ(n) = (p-1)*(q-1) = 192
私钥 d = 55
验证: e * d mod φ(n) = 7 * 55 mod 192 = 1
 加解密成功！明文和解密结果一致。
 贡献指南
我们欢迎任何形式的贡献！请参考以下步骤：

Fork 本项目

创建特性分支 (git checkout -b feature/AmazingFeature)

提交更改 (git commit -m 'Add some AmazingFeature')

推送到分支 (git push origin feature/AmazingFeature)

创建 Pull Request

开发规范
代码遵循C语言标准规范

变量命名清晰，添加必要的注释

提交信息采用约定式提交格式

确保所有测试用例通过

 许可证
本项目采用 Apache License 2.0 许可证 - 查看 LICENSE 文件了解详情。

text
Copyright 2024 RSA_Project_60

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
