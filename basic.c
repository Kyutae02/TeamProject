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
 else{
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

