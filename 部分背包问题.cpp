#include <stdio.h>
#include <algorithm>
using namespace std;
 
 
//��Ʒ�ṹ�壬�����������ԣ�w��ʾ������v��ʾ��ֵ
struct Good{
    int id;
    double w;
    double v;
};
 
//����ȽϺ���������Ʒ�ļ�ֵ/������ֵ��������
bool cmp(Good a, Good b){
    if (a.v/a.w > b.v/b.w) {
        return true;
    }
    return false;
}
 
//�ṹ������,������Ʒ��Ϣ
struct Good goods[] = {{1,4,3},{2,3,9},{3,10,8},{4,12,16},{5,5,20}};
 
 
//����������
double totalW = 20;
 
int main()
{
    //����Ʒ�ļ�ֵ/������ֵ��������
    sort(goods,goods+6,cmp);
    double leftW = totalW;
    int totalV = 0;
    
    //�����ź������Ʒ����
    for (int i=0; i<6; i++) {
        //�����ǰ�������ܳ��ܵ���������i��Ʒ������
        //��ô��i��Ʒȫ���Ž�ȥ
        if (leftW >= goods[i].w) {
            leftW -= goods[i].w;
            totalV += goods[i].v;
            printf("choose good[id = %d], %.1f weight,make %.1f value\n",goods[i].id,goods[i].w,goods[i].v);
            
        //������ܣ���ôȡ��ǰ�������ܳ�����������Ӧ������Ʒ
        //��Ȼ��ֵҲ�ð��ձ�����
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