#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



#undef assert   //消除已经定义的

#ifdef NDEBUG //如果是该定义了该宏，则取消断言
    #define assert(expre)   ((void)0)     //使其功能失效
#else
    void _Assert_(const char* expre);
    #define  _str(x)   _xstr(x)                               //以下两行是为了将十进制__LINE__转换为字符串形式,由于__line__和__file__本身就包装了一层宏，所以需要两次转换
    #define  _xstr(x)    #x
    #define  assert(expre)   ((expre) ? (void)0 :     \
                _Assert_("My_assert\""#expre"         \
                \"failed,file:"_str(__FILE__)               \
                ", line:"_str(__LINE__)"\n" ))     
#endif


//这里系统调用来流输出
void _Assert_(const char * expre){
    fputs(expre,stderr);
    abort();
}