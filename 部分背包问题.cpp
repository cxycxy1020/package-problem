#include <stdio.h>
#include <algorithm>
using namespace std;
 
 
//物品结构体，包含两个属性，w表示重量，v表示价值
struct Good{
    int id;
    double w;
    double v;
};
 
//排序比较函数，以物品的价值/重量比值降序排序
bool cmp(Good a, Good b){
    if (a.v/a.w > b.v/b.w) {
        return true;
    }
    return false;
}
 
//结构体数组,所有物品信息
struct Good goods[] = {{1,4,3},{2,3,9},{3,10,8},{4,12,16},{5,5,20}};
 
 
//背包总重量
double totalW = 20;
 
int main()
{
    //以物品的价值/重量比值降序排序
    sort(goods,goods+6,cmp);
    double leftW = totalW;
    int totalV = 0;
    
    //遍历排好序的物品数组
    for (int i=0; i<6; i++) {
        //如果当前背包所能承受的重量大于i物品的总量
        //那么把i物品全部放进去
        if (leftW >= goods[i].w) {
            leftW -= goods[i].w;
            totalV += goods[i].v;
            printf("choose good[id = %d], %.1f weight,make %.1f value\n",goods[i].id,goods[i].w,goods[i].v);
            
        //如果不能，那么取当前背包所能承受重量的相应数量物品
        //当然价值也得按照比例来
        }else {
            totalV += leftW/goods[i].w * goods[i].v;
            leftW = 0;
            printf("choose good[id = %d], %.1f weight,make %.1f value\n",goods[i].id,leftW,leftW/goods[i].w * goods[i].v);
            break;
        }
    }
    
    printf("max total value:%d\n",totalV);
    return 0;
}