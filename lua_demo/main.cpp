#include <QCoreApplication>
#include <QDebug>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

static int getnum(int num){
    num++;
    return num;
}

static int lua_getnum(lua_State *lu){
      /* 从栈顶中取一个值 */
    int num = (int) lua_tonumber(lu,1);
    /* 调用getNumber函数，将返回值入栈 */
    lua_pushnumber(lu,getnum(num));
    return 1;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    lua_State *lu = luaL_newstate();
//    luaL_openlibs(lu);
//    lua_close(lu);

    lua_State *lu = luaL_newstate();
    luaL_openlibs(lu);

    //注意文件的目录，默认是exe所在的执行目录
    int err = luaL_dofile(lu,"hello.lua");
    if(err!=0)
        qDebug()<<"open file error";

    //重置栈顶索引，就是要清空栈，这样后面很清楚栈里面的情况了
    lua_settop(lu,0);

    //C把myname放到栈中，lua就会从全局表去找，找到了之后，又放回栈中
    //所以，lua_getglobal干了很多活的
    int getdata = lua_getglobal(lu,"myname");
    qDebug()<<"getdata from lua_getglobal: "<<getdata;

    //从栈中取字符串，很明显，这是从栈顶取出就好了，因为这里只用了栈顶元素
    //先判断是不是字符串，返回0表示成功
    int isstr = lua_isstring(lu,1);
    if(isstr!=0)
        qDebug()<<"not a string";
    const char* str = lua_tostring(lu,1);
    qDebug()<<"myname is "<<str;


    qDebug()<<"*******************获取table的值*************************";
    //使用lua_gettable(lu，name)函数读取栈中table的name的值
    lua_settop(lu,0);
    //先将table压入栈，index=1
    lua_getglobal(lu,"helloTable");

    //将我们要查的table中的关键字压入栈，index=2
    lua_pushstring(lu,"name");
    //通过如下函数获取name对应的值，这是index2的值已经被替换掉了
    //注意，函数的对象是table，所以index是1
    lua_gettable(lu,1);

    const char* str1 = lua_tostring(lu,2);
    qDebug()<<"name is "<<str1;


    qDebug()<<"*******************C++调用lua加法函数*************************";
    lua_settop(lu,0);
    //加载函数名称，字符串，压入栈顶
    lua_getglobal(lu,"add");
    //按顺序压入参数
    lua_pushnumber(lu,1);
    lua_pushnumber(lu,2);
    //调用一个函数，第一个参数是参数的个数，第二参数是返回值的个数。第一个返回值首先压栈
    lua_call(lu,2,1);
    //最新压栈的就是函数的结果
    int result = lua_tonumber(lu,-1);
    qDebug()<<"1 + 2 = "<<result;

    qDebug()<<"*******************lua调用C++函数*************************";
    //lua不能直接调用C++函数，因为两者是通过栈来交互数据的，所以得自定义一个中间函数
    lua_settop(lu,0);
    lua_pushnumber(lu,1);
    lua_getnum(lu);
    int add1 = lua_tonumber(lu,-1);
    qDebug()<<"1 ++ = "<<add1;

    lua_close(lu);

    return a.exec();
}
