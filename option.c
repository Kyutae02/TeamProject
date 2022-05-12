#include "basic.h"
#include "option.h"

void searchMenu(Menu *m, int count)
{
    int scnt = 0;
    char searchDest[40];

    printf("검색어를 입력하세요 : ");
    scanf("%s", searchDest);

    printf("\n======== 메뉴판 ========\n");
    for (int i = 0; i < count; i++)
    {
        if (m[i].price == -1)
            continue;
        if (strstr(m[i].food, searchDest))
        {
            printf("%2d ", i + 1);
            readMenu(m[i]);
            scnt++;
        }
    }

    if (scnt == 0)
    {
        printf("=> 검색된 결과 없음\n");
    }
}

