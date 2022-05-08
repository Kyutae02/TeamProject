#include "basic.h"

void readMenu(Menu *m){
    printf("%-8s %5d원 %4s\n",m->food,p->price,p->booth);
}

int loadData(Menu *m)
{
 int count = 0;
 FILE *fp;

 fp = fopen("Product.txt","rt");
 if(fp==NULL) printf("=>파일 없음\n");
 else
{
 for(;count<100;count++)
 {
 fscanf(fp,"%[^\n]s.",m[count].food);
 if(feof(fp)) break;
 fscanf(fp,"%d",&m[count].price);
 fscanf(fp,"%[^\n]s",m[count].booth);
 }
 fclose(fp);
 printf("=>로딩 성공!");
 printf("%d",count);
}
 return count;
}

int createMenu(Menu *m)
{
 printf("메뉴 이름은? ");
 getchar();
 fgets(m->food, sizeof(m->food), stdin);
 int len = strlen(m->food);
 m->food[--len] = '\0';
 printf("가격은? ");
 scanf("%d", &m->price);
 printf("판매 부스는? ");
 scanf("%s", m->booth);

 return 1;
}

void listMenu(Menu *m, int count)
{
 for(int i = 0; i < count; i++)
 {
  if(m[i].price == -1) continue;
  printf("========== %d ==========\n", i+1);
  readMenu(p[i]);
  printf("========================\n");
 }
}

int selectDataNum(Menu *m, int count)
{
 int selec;
 listMenu(m, count);
 printf("번호는(취소 : 0)? ");
 scanf("%d", &selec);

 return selec;
}

int updateMenu(Menu *m)
{
 printf("새로운 메뉴 이름은? ");
 getchar();
 fgets(m->food, sizeof(m->food), stdin);
 int len = strlen(m->food);
 m->food[--len] = '\0';
 printf("새로운 메뉴의 가격은? ");
 scanf("%d", &m->price);
 printf("새로운 메뉴의 판매 부스는? ");
 scanf("%s", m->booth);

 return 1;
}

