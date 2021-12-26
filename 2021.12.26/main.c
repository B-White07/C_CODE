#include <stdio.h>

int main() {
    /*
     * 程序的环境和预处理
     * 1程序的翻译环境     2程序的执行环境    3详解：C语言程序的编译+链接     4预定义符号介绍    5预处理指令#define
     * 6宏和函数的对比     7预处理操作符#和##介绍       8命令行定义       9预处理指令#include      10预处理指令#undef
     * 11条件编译
     */
//    一、程序的翻译环境和执行环境
//    在ANSI C的任何一种实现中，存在两个不同的环境
//    第一种是翻译环境，在这个环境中源代码被转换为可执行的机器指令；   第二种是执行环境，它用于实际执行代码
//    test.c --> test.exec的过程依赖的是翻译环境（当前为CLion），运行test.exec所依赖的是运行环境，产生运行结果
//    翻译环境工作流程：工程中的每个.c源文件单独经过编译器处理，变成.o（lunix下的目标文件）文件，
//    然后链接器会将所有的目标文件和链接库(.lib静态库)链接在一起生成可执行程序（exec）
//    因此，翻译环境可分为两部分：编译（依靠编译器）和链接（依靠链接器）
//    其中编译分为三个步骤：
//     1。预编译（预处理），通过gcc test.c -E > test.i将预处理的后的文件重定向到test.i中，便于查看
//          /Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include/stdio.h 查看stdio.h中的内容
//          说明了在预处理阶段完成了:
//              1.头文件的包含，其实就是将头文件拷贝到相应位置
//              2.#define定义的符号和宏的替换，因此后期程序在编译，汇编的时候也是看不到的，后来程序运行也是看不到的，就不便于调试
//              3.注释删除，因此程序中无论有多少注释，都不会给程序带来负担
//          上述这些其实都是文本操作，也就是说，预处理阶段实际上是完成了一些文本操作
//     2。编译，通过gcc test.i(test.c也可以) -S对文件进行编译，生成test.s文件，把C语言代码转化为汇编代码
//          编译阶段完成了：
//              1。语法分析
//              2。词法分析
//              3。语义分析
//              4。符号汇总:将.c中的全局符号汇总
//     3。汇编，通过gcc test.s -c对编译生成的.s文件处理，生成test.o文件（即目标文件），-c意思是汇编之后停止，不要进行下一步
//          test.o是elf格式的，可以使用objdump查看这个文件
//          汇编阶段完成了：
//              1.生成符号表：
//              2。把汇编代码转换成了机器指令（二进制指令）















    return 0;
}
