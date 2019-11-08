#include <stdio.h>

/* 定义一个函数指针
 * 确定入参与返回值类型 
 */
typedef int (* MyCallbak)(int PanJinLian, int XiMengQin);

/* 实现一个与上面定义的函数指针入参与返回值类型相同的函数
 */
int ThisMyFunc(int PanJinLian, int XiMengQin)
{
    printf("PanJinLian is %d\n", PanJinLian);
    printf("XiMengQin is %d\n", XiMengQin);
    printf("do something...\n");
    return 0;
}

int main(int argc, char *argv[])
{
    int P_adrenaline = 99;
    int X_adrenaline = 101;
    
    /* 定义一个函数指针变量 */
    MyCallbak CallbakPointer;
    
    /* 将函数地址赋予定义的指针 也叫挂钩子
     */
    CallbakPointer = ThisMyFunc;
    
    /* 调用函数，执行回调 */
    int ret = CallbakPointer(P_adrenaline, X_adrenaline);
    printf("ret is %d\n", ret);
    return 0;
}
