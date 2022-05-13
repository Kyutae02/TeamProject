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

void randomMenu(Menu *m, int count)
{
    int randnum, check;
    randnum = rand() % count;
    printf("메뉴를 추천 받으시겠습니까(예: 1, 아니오: 0)? ");
    scanf("%d", &check);
    if (check == 1)
    {
        printf("추천 메뉴 : ");
        readMenu(m[randnum]);
    }
    else if (check == 0)
    {
        printf("=> 취소됨!\n");
    }
}

