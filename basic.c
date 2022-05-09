#include "basic.h"

int selectButton()
{
    int button;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &button);
    return button;
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

void readMenu(Menu m){
    printf("%-8s %5d원 %4s\n",m.food,m.price,m.booth);
}
void listMenu(Menu *m, int count)
{
 for(int i = 0; i < count; i++)
 {
  if(m[i].price == -1) continue;
  printf("========== %d ==========\n", i+1);
  readMenu(m[i]);
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

int deleteMenu(Menu *m)
{
    m->price=-1;
    printf("==> 삭제됨!\n");
    return 0;
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

void saveData(Menu *m, int count);




