#include<stdio.h>
#include<unistd.h>
#include<getopt.h>
int main(int argc, char *argv[])
{
    int opt;
    /*单个字符表示选项没有参数                  输入格式：-A即可，不加参数
     *单字符加冒号表示选项有且必须加参数        输入格式：-B xiaocang或-Bxiaobo(二选一)
     *单字符加两个冒号表示选项可以有也可以无    输入格式：-Cxiaobo(必须挨着)
     */
    char *string = "AB:C::";
    while ((opt = getopt(argc, argv, string))!= -1)
    {  
        /* 下面是常用的两个获取选项及其值得变量optarg无需定义，全局变量
         * opt          '-' 后面的字符，也就是参数字符
         * optarg       指向当前选项参数(如果有)的指针。
         */
        printf("opt = %c\t\t", opt);
        printf("optarg = %s\t\t\n", optarg);
    }
    
    return 0;
}