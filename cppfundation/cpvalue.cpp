#include<iostream>
#include<string>

void reference(std::string& str)
{
    std::cout << "左值" << std::endl;
}

void reference(std::string&& str)
{
    std::cout << "右值" << std::endl;
}


// 这里加深一下左右值的概念
/* 左值的英文简写为“lvalue”，右值的英文简写为“rvalue”。很多人认为它们分别是"left value"、"right value" 的缩写，
其实不然。lvalue 是“loactor value”的缩写，可意为存储在内存中、有明确存储地址（可寻址）的数据，而 rvalue 译为 
"read value"，指的是那些可以提供数据值的数据（不一定可以寻址，例如存储于寄存器中的数据）。 */
int main()
{
    std::string lv1 = "string";
    std::string &&rv1 = std::move(lv1);        //  std::string rv1 = std::move(lv1); 如果不加引用使用，就是移动操作，若加上&&原来的右值不会改变
    // rv1 = "";
    std::cout << rv1 << std::endl;
    rv1 += "dwadw";
    reference(lv1);
    std::cout << lv1 << std::endl;

    const std::string& lv2 = lv1 + lv1;
    std::cout << lv2 << std::endl;

    std::string&& rv2 = lv1 + lv2;
    rv2 += "Test";
    std::cout << rv2 << std::endl;
    reference(rv2);

    return 0;
}