#define _AMD64_
typedef char _Bool;
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
 
 
static void gamesx(int xSIZEc, int xRANGEc, bool islotto, int ball)
{ 
	int GGGc[20] = { 0 };
	int hc = 0;
	int jc = 0;
	int a,e,x,y,z,zy;
    for (a = 0; a < xSIZEc; a++)
	{
	for (e = 0; e < xSIZEc; e++)
	{
		for (x = 0; x < xSIZEc; x++)
		{
			for (y = 0; y < xSIZEc; y++)
			{
				for (z = 0; z < xSIZEc; z++)
				{
					if (hc == (GGGc[z]))
					{
						while (true)
						{
							jc = rand() % xRANGEc + 1;
							if (jc != GGGc[z])
							{
								hc = jc;
								break;
							}
						}
					}
 
				}
 
			}
		}
	}
		GGGc[a] = hc;
	}
	for (zy = 0; zy < xSIZEc; zy++)
	{
		printf("%d = ", GGGc[zy]);
	}
	if (islotto == false)
	{
		printf("%d+ = ", rand() % ball + 1);
	}
}
 
static void numbersx(int xrange)
{
	int jhe = 0;
	int jhe1 = 0;
	int x;
	for (x = 0; x < xrange; x++)
	{
		jhe1 = rand() % 10;
		printf("%d = ", jhe1);
		jhe = jhe + jhe1;
	}
	printf("%d+ = ", jhe);
}
 
int main()
{
        time_t rawtime;
        struct tm * timeinfo;
        int i,ia;
        FILE *fp;
        FILE *fp1;
        FILE *fp2;
        float temp_milli;
        float temp_milli1;
        float temp_milli2;
        // thermal_zones: 0-7
        fp2 = fopen("/sys/class/thermal/thermal_zone1/temp", "r");
        fp1 = fopen("/sys/class/thermal/thermal_zone2/temp", "r");
        fp = fopen("/sys/class/thermal/thermal_zone7/temp", "r");
        if (fp2 == NULL) {perror("Error opening temperature file"); return 1;}
        if (fp1 == NULL) {perror("Error opening temperature file"); return 1;}
        if (fp == NULL) {perror("Error opening temperature file"); return 1;}
        // Read the millicelsius value
        if (fscanf(fp2, "%f", &temp_milli2) != 1) {fprintf(stderr, "Error reading temperature data\n"); fclose(fp2); return 1;}
        if (fscanf(fp1, "%f", &temp_milli1) != 1) {fprintf(stderr, "Error reading temperature data\n"); fclose(fp1); return 1;}
        if (fscanf(fp, "%f", &temp_milli) != 1) {fprintf(stderr, "Error reading temperature data\n"); fclose(fp); return 1;}
        fclose(fp2);
        fclose(fp1);
        fclose(fp);
	//get time
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	// welcome text
	printf("##############################################################################\n\n");
	printf("    New York Lottery v7.0 by alCoPaUL [NaCl][GIMO][ZnI][b8]  June 11, 2026    \n\n");
	printf("##############################################################################\n\n");
	// day as seed
	srand(((timeinfo->tm_year + 1900 / timeinfo->tm_mday) / timeinfo->tm_mon + 1) * ((temp_milli2 * 0.2) / 1000) * ((temp_milli1 * 62) / temp_milli));
	for (i = 1; i < 7; i++)
	{
		switch (i)
		{
		case 1:
			gamesx(5, 70, false, 25);
			printf("MegaMillions\n\n");
			break;
		case 2:
			gamesx(5, 69, false, 26);
			printf("PowerBall\n\n");
			break;
		case 3:
			gamesx(7, 59, true, 0);
			printf("NY Lotto 1\n");
			gamesx(7, 59, true, 0);
			printf("NY Lotto 2\n\n");
			break;
		case 4:
			gamesx(5, 60, false, 4);
			printf("Cash4Life\n\n");
			break;
		case 5:
			gamesx(5, 39, true, 0);
			printf("Take 5\n\n");
			break;
		case 6:
			gamesx(10, 80, true, 0);
			printf("Pick 10\n\n");
			break;
		}
 
	}
	for (ia = 1; ia < 5; ia++)
	{
		switch (ia)
		{
		case 1:
			numbersx(3);
			printf("[Midday] || ");
			break;
		case 2:
			numbersx(3);
			printf("[Evening] = Numbers\n\n");
			break;
		case 3:
			numbersx(4);
			printf("[Midday] || ");
			break;
		case 4:
			numbersx(4);
			printf("[Evening] = Win 4\n\n");
			break;
		}
 
	}
	gamesx(10, 80, true, 0);
	printf("QuickDraw\n\n");
	printf("##############################################################################\n\n");
	getchar();
	return 0;
}
// New York Lottery v7.0 by alcopaul[GIMO][As][aBrA][NPA] (twitter: @longint32)
//LRT
//Tatiana nikoLaevna RomanovDark

