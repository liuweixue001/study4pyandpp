# gdb简单使用
**使用g++ -g -o 编译 (使用 -g 选项告诉编译器生成调试信息)**

#### 1.打开文件
gdb /path/to/executable

#### 2.设置断点
break 42 //在第 42 行设置断点
info breakpoints 查看断点
disable 42 禁用断点
#### 3.运行程序
run

#### 4.逐步运行
step

#### 5.查看变量值
print i

#### 6.继续运行
continue

#### 7.退出
quit
