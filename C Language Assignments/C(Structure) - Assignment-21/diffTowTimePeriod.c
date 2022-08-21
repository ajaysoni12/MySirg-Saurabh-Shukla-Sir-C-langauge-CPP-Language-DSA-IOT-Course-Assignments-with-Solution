#include <stdio.h>
struct timePeriod
{
    int hrs, min, sec;
};
void inputPeriod(struct timePeriod *time)
{
    printf("\nEnter hourse: ");
    scanf("%d", &time->hrs);
    printf("\nEnter minute: ");
    scanf("%d", &time->min);
    printf("\nEnter second: ");
    scanf("%d", &time->sec);
}
void diffTimePeriod(struct timePeriod time1, struct timePeriod time2)
{
    int totalSec1 = time1.hrs * 60 * 60 + time1.min * 60 + time1.sec;
    int totalSec2 = time2.hrs * 60 * 60 + time2.min * 60 + time2.sec;
    int time = totalSec1 - totalSec2;
    int hrs, min, sec;
    sec = time % 60;
    time /= 60;
    min = time % 60;
    time /= 60;
    hrs = time;
    printf("\nRemaming time\nhrs - %d, min - %d, sec - %d", hrs, min, sec);
}
int main()
{
    struct timePeriod time1, time2;
    inputPeriod(&time1);
    inputPeriod(&time2);
    diffTimePeriod(time1, time2);
    return 0;
}